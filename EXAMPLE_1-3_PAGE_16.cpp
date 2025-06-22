// Description: This program calculates the total price of an item after applying state, city, and luxury item taxes.
// Resource : D.S. Malik - C++ Programming. Program Design including Data Structures-Cengage (2018)
// EXAMPLE 1-3 | PAGE 16

#include <iostream>
#include <iomanip>

int main() {
    int baseSalary;
    int yearsOfService;
    int totalSales;

    std::cout << "Enter base salary: $";
    std::cin >> baseSalary;

    std::cout << "Enter years of service: ";
    std::cin >> yearsOfService;

    std::cout << "Enter total sales: $";
    std::cin >> totalSales;

    int serviceBonus = (yearsOfService <= 5) ? (10 * yearsOfService) : (20 * yearsOfService);

    double salesBonus;
    if (totalSales < 5000) {
        salesBonus = 0.0;
    } else if (totalSales < 10000) {
        salesBonus = 0.03 * totalSales;
    } else {
        salesBonus = 0.06 * totalSales;
    }

    double payCheck = baseSalary + serviceBonus + salesBonus;

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "\n--- Paycheck Summary ---" << std::endl;
    std::cout << "Base Salary:    $" << std::setw(10) << baseSalary << std::endl;
    std::cout << "Service Bonus:  $" << std::setw(10) << serviceBonus << std::endl;
    std::cout << "Sales Bonus:    $" << std::setw(10) << salesBonus << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << "Total Paycheck: $" << std::setw(10) << payCheck << std::endl;
    std::cout << "------------------------" << std::endl;


    return 0;
}
