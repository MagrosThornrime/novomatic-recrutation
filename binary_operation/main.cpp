#include <iostream>

#include <Calculate.hpp>
#include <string>
#include <sstream>


int main() {
    std::string result = calculate<Concatenate, Value>(1000, Value("a"), Concatenate());
    std::cout << result << std::endl;
}