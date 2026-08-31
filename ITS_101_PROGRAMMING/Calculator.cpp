#include <iostream>
using namespace std;

int main() {
    // Variables to hold the two numbers, the operator, and the result
    double num1, num2, result;
    char op;

    // Get the first number from the user
    cout << "Enter first number: ";
    cin >> num1;

    // Get the operator from the user
    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    // Get the second number from the user
    cout << "Enter second number: ";
    cin >> num2;

    // Decide what to do based on which operator was entered
    switch (op) {
    case '+':
        result = num1 + num2;
        break;
        

    case '-':
        result = num1 - num2;
        break;

    case '*':
        result = num1 * num2;
        break;

    case '/':
        // Check for division by zero before dividing
        if (num2 != 0) {
            result = num1 / num2;
        } else {
            cout << "Error: Cannot divide by zero." << endl;
            return 1;
        }
        break;

    default:
        // Runs if the operator isn't +, -, *, or /
        cout << "Error: Invalid operator." << endl;
        return 1;
    }

    // Print the final result
    cout << num1 << " " << op << " " << num2 << " = " << result << endl;

    return 0;
}