#include <iostream>

int readNumber()
{
    std::cout << "Enter a number: ";
    int number{};
    std::cin >> number;
    return number;
}

void writeAnswer(int value)
{
    std::cout << "The answer is: " << value << std::endl;
}
