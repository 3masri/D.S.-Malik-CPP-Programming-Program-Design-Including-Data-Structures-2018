// Description: This program calculates the total price of an item after applying state, city, and luxury item taxes.
// Resource : D.S. Malik - C++ Programming. Program Design including Data Structures-Cengage (2018)
// EXAMPLE 1-1 | PAGE 14

#include <iostream>

int main() {
    double length;
    double width;
    double perimeter;
    double area;

    std::cout << "Enter the length of the rectangle: ";
    std::cin >> length;
    
    if (length < 0) {
        std::cout << "Error: Length and width cannot be negative." << std::endl;
        return 1;
    }

    if (std::cin.fail()) {
        std::cout << "Error: Invalid input. Please enter numeric values." << std::endl;
        return 1;
    }

    std::cout << "Enter the width of the rectangle: ";
    std::cin >> width;

    if (width < 0) {
        std::cout << "Error: Length and width cannot be negative." << std::endl;
        return 1;
    }
    if (std::cin.fail()) {
        std::cout << "Error: Invalid input. Please enter numeric values." << std::endl;
        return 1;
    }

    perimeter = 2 * (length + width);

    area = length * width;

    std::cout << "\n--- Rectangle Calculations ---" << std::endl;
    std::cout << "Length: " << length << std::endl;
    std::cout << "Width: " << width << std::endl;
    std::cout << "Perimeter: " << perimeter << std::endl;
    std::cout << "Area: " << area << std::endl;

    return 0;
}
