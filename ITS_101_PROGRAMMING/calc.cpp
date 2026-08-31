#include <iostream>
#include <cmath>

using namespace std;

void displayMenu() {
    cout << "Scientific Calculator Menu" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Square Root" << endl;
    cout << "6. Exit" << endl;
}

double performAddition(double a, double b) {
    return a + b;
}

double performSubtraction(double a, double b) {
    return a - b;
}

double performMultiplication(double a, double b) {
    return a * b;
}

double performDivision(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        cout << "Error: Division by zero!" << endl;
        return 0.0;
    }
}

double performSquareRoot(double a) {
    if (a >= 0) {
        return sqrt(a);
    } else {
        cout << "Error: Square root of a negative number is not defined!" << endl;
        return 0.0;
    }
}

int main() {
    double num1, num2;
    int choice;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter two numbers to add: ";
                cin >> num1 >> num2;
                cout << "Result: " << performAddition(num1, num2) << endl;
                break;
            case 2:
                cout << "Enter two numbers to subtract: ";
                cin >> num1 >> num2;
                cout << "Result: " << performSubtraction(num1, num2) << endl;
                break;
            case 3:
                cout << "Enter two numbers to multiply: ";
                cin >> num1 >> num2;
                cout << "Result: " << performMultiplication(num1, num2) << endl;
                break;
            case 4:
                cout << "Enter two numbers to divide: ";
                cin >> num1 >> num2;
                cout << "Result: " << performDivision(num1, num2) << endl;
                break;
            case 5:
                cout << "Enter a number for square root: ";
                cin >> num1;
                cout << "Result: " << performSquareRoot(num1) << endl;
                break;
            case 6:
                cout << "Exiting the calculator. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}