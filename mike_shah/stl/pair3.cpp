#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <functional>

using student_t = std::pair<int, std::string>;

int main() {
    std::vector<student_t> students;

    for (int i = 0; i < 10; i++) {
        students.emplace_back(i, "student" + std::to_string(i));
    }

    for (const auto& student : students) {
        std::cout << student.first << " " << student.second << "\n";
    }

    int val = 100L;

    auto newpair = std::make_pair(val, 10.0F);

    val = 150L;

    std::cout << newpair.first << std::endl;

    std::cout << std::get<float>(newpair) << std::endl;

    return 0;
}

