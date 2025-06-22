// Description: This program calculates the total price of an item after applying state, city, and luxury item taxes.
// Resource : D.S. Malik - C++ Programming. Program Design including Data Structures-Cengage (2018)
// EXAMPLE 1-4 | PAGE 17

#include <iostream>
#include <iomanip> // Not strictly needed for this version, but good practice to include if setprecision or fixed are used
#include <random>  // For better random number generation
#include <limits>  // For std::numeric_limits

int main() {
    // Seed the random number generator
    // Use std::mt19937 and std::random_device for superior randomness
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 100); // Define distribution for numbers 0-100

    int randomNumber = distrib(gen); // Generate a truly random number

    int guess;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have chosen a number between 0 and 100." << std::endl;
    std::cout << "Can you guess what it is?" << std::endl;

    while (true) {
        std::cout << "\nEnter your guess: ";
        std::cin >> guess;
        attempts++;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a whole number." << std::endl;
            std::cin.clear(); // Clear the error flag
            // Discard invalid input from the buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue; // Ask for input again
        }

        if (guess < 0 || guess > 100) {
            std::cout << "Your guess is out of range. Please enter a number between 0 and 100." << std::endl;
            continue; // Ask for input again
        }

        if (guess < randomNumber) {
            std::cout << "Too low! " << std::endl;
        } else if (guess > randomNumber) {
            std::cout << "Too high! " << std::endl;
        } else {
            std::cout << "\nCongratulations! You guessed the number " << randomNumber;
            std::cout << " in " << attempts << " attempts!" << std::endl;
            break;
        }
    }

    return 0;
}
