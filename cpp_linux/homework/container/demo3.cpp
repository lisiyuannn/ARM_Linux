#include <iostream>
#include <map>
#include <string>

int main() {

    std::map<int, std::string> digitToWordMap = {
        {0, "zero"},
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {5, "five"},
        {6, "six"},
        {7, "seven"},
        {8, "eight"},
        {9, "nine"}
    };

    int inputDigit;
    std::cout << "请输入一个 0 到 9 之间的阿拉伯数字: ";
    std::cin >> inputDigit;

	//输入检查
    if (inputDigit >= 0 && inputDigit <= 9) {
        std::cout << "对应的英文数字是: " << digitToWordMap[inputDigit] << std::endl;
    } else {
        std::cout << "输入的数字不在 0 到 9 的范围内，请重新输入。" << std::endl;
    }

    return 0;
}
