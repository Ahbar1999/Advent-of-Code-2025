#include <iostream>
// #include <sstream>
#include <fstream>
#include <vector>
#include <filesystem>

std::vector<std::string> get_input(const std::string& filepath) {
    std::ifstream input(filepath);
    std::vector<std::string> result;

    if (input.is_open()) {
        std::string line;
        while (getline(input, line)) {
            // std::cout << line << std::endl;
            result.push_back(line);
        }

        input.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
    }

    return result;
}
int day1(const std::vector<std::string>& input, const int start_pos =50, const int dial_max= 100, const int dial_min=0) {
    int ans = start_pos;
    int result =0;

    for (auto& line: input) {
        int clicks=  std::stoi(line.substr(1, -1));

        result += clicks / dial_max;
        clicks %= dial_max;
        if (line[0] == 'R') {
            // if its not already at zero but will go through 0 during remainder of clicks
            if (ans && ans + clicks >= 100) result++;

            ans = (ans + clicks) % dial_max;
        } else {
            if (ans && ans - clicks <= 0) result++;

            ans = (ans - clicks + dial_max) % dial_max;
        }
    }

    return result;
}

int main() {
    // auto cwd = std::filesystem::current_path();
    // std::cout << cwd << std::endl;
    auto input = get_input("../input/day1/input.txt");
    std::cout << day1(input) << std::endl;

    return 0;
}