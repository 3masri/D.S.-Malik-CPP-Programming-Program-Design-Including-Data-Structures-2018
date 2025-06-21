// Description: This program calculates the total price of an item after applying state, city, and luxury item taxes.
// Resource : D.S. Malik - C++ Programming. Program Design including Data Structures-Cengage (2018)
// EXAMPLE 1-2 | PAGE 14

#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

// Constants for tax rates and thresholds
const double STATESALESTAX_RATE = 0.04;  // 4% state sales tax
const double CITYSALESTAX_RATE = 0.015; // 1.5% city sales tax
const double LUXURYITEMTAX_RATE = 0.1;  // 10% luxury item tax
const double LUXURY_THRESHOLD = 1000.0; // Items over $1000 are considered luxury

int main()
{
    double salePrice;

    // Set output formatting for currency
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Enter the sale price of the item: $";
    std::cin >> salePrice;

    // Input validation
    if (salePrice < 0) {
        std::cout << "Error: Sale price cannot be negative." << std::endl;
        return 1; // Indicate an error
    }
    if (std::cin.fail()) {
        std::cout << "Error: Invalid input. Please enter a numeric value." << std::endl;
        return 1; // Indicate an error
    }

    double stateTax = salePrice * STATESALESTAX_RATE;
    double cityTax = salePrice * CITYSALESTAX_RATE;

    double luxuryTax = 0.0;
    bool isLuxuryItem = false; // Initialize to false

    // Determine if it's a luxury item based on the threshold
    if (salePrice > LUXURY_THRESHOLD) {
        isLuxuryItem = true;
        luxuryTax = salePrice * LUXURYITEMTAX_RATE;
    }

    double totalTax = stateTax + cityTax + luxuryTax;
    double totalPrice = salePrice + totalTax;

    // Display the breakdown of costs
    std::cout << "\n--- Sales Tax Calculation ---" << std::endl;
    std::cout << "Original Sale Price: $" << salePrice << std::endl;
    std::cout << "State Sales Tax (4.00%):   $" << stateTax << std::endl;
    std::cout << "City Sales Tax (1.50%):    $" << cityTax << std::endl;

    if (isLuxuryItem) {
        std::cout << "Luxury Item Tax (10.00%):  $" << luxuryTax << " (Item over $" << LUXURY_THRESHOLD << ")" << std::endl;
    } else {
        std::cout << "Luxury Item Tax (N/A):     $0.00" << std::endl;
    }

    std::cout << "-----------------------------" << std::endl;
    std::cout << "Total Tax:                 $" << totalTax << std::endl;
    std::cout << "Total Price (incl. taxes): $" << totalPrice << std::endl;

    return 0; // Indicate successful execution
}
