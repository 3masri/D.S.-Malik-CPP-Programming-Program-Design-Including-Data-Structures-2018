// Description: This program calculates the total price of an item after applying state, city, and luxury item taxes.
// Resource : D.S. Malik - C++ Programming. Program Design including Data Structures-Cengage (2018)
// EXAMPLE 1-5 | PAGE 18


#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

// Function to calculate average test score for a student
double calculateStudentAverage(const std::vector<int>& testScores) {
    double sum = 0.0;
    for (int score : testScores) {
        sum += score;
    }
    return sum / testScores.size();
}

// Function to determine the grade based on average score
char determineGrade(double average) {
    if (average >= 90) {
        return 'A';
    } else if (average >= 80) {
        return 'B';
    } else if (average >= 70) {
        return 'C';
    } else if (average >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

int main() {
    int studentCount;
    int testCount;

    std::cout << "Enter the number of students: ";
    std::cin >> studentCount;
    std::cout << "Enter the number of tests per student: ";
    std::cin >> testCount;

    double totalClassAverageSum = 0.0;

    std::cout << "--- Student Grading System ---" << std::endl;

    for (int i = 0; i < studentCount; ++i) {
        std::string studentName;
        std::vector<int> testScores(testCount);
        double currentStudentTestSum = 0.0;

        std::cout << "\nEnter name for student " << (i + 1) << ": ";
        std::getline(std::cin >> std::ws, studentName); // std::ws to consume any leftover newline

        std::cout << "Enter " << testCount << " test scores for " << studentName << ":" << std::endl;
        for (int j = 0; j < testCount; ++j) {
            int score;
            // Basic input validation loop
            while (true) {
                std::cout << "  Test " << (j + 1) << " score: ";
                std::cin >> score;

                if (std::cin.fail() || score < 0 || score > 100) {
                    std::cout << "Invalid score. Please enter a number between 0 and 100." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } else {
                    testScores[j] = score;
                    currentStudentTestSum += score;
                    break;
                }
            }
        }

        double studentAverage = calculateStudentAverage(testScores); // Or use currentStudentTestSum / NUMBER_OF_TESTS;
        char studentGrade = determineGrade(studentAverage);

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "\n--- Results for " << studentName << " ---" << std::endl;
        std::cout << "Average Score: " << studentAverage << std::endl;
        std::cout << "Grade:         " << studentGrade << std::endl;

        totalClassAverageSum += studentAverage;
    }

    double classOverallAverage = totalClassAverageSum / studentCount;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n--- Class Overall Summary ---" << std::endl;
    std::cout << "Class Average Score: " << classOverallAverage << std::endl;

    return 0;
}
