// =====================================================
// SCIENTIFIC CALCULATOR - COMPLETE PROGRAM
// =====================================================
// This program has 1000+ lines with all major scientific
// functions, memory, history, and a clean interface
// =====================================================

#include <iostream>
#include <cmath>      // For sin, cos, tan, log, sqrt, pow, etc.
#include <iomanip>    // For formatting output
#include <vector>     // For storing history
#include <string>     // For string operations
#include <cstdlib>    // For system("pause") and system("cls")
#include <limits>     // For input validation

using namespace std;

// =====================================================
// GLOBAL VARIABLES
// =====================================================
const double PI = 3.14159265358979323846;
double memory = 0;                    // Memory storage
bool memorySet = false;               // Track if memory has a value
vector<string> history;               // Store calculation history
bool degreeMode = true;               // true = degrees, false = radians
const int MAX_HISTORY = 50;           // Maximum history entries

// =====================================================
// FUNCTION PROTOTYPES (declarations)
// =====================================================
void displayMenu();
void displayHeader();
void clearScreen();
void waitForEnter();
double getNumber(string prompt);
double getTwoNumbers(string prompt1, string prompt2, double &num1, double &num2);
double factorial(double n);
double combination(double n, double r);
double permutation(double n, double r);
double toRadians(double degrees);
double toDegrees(double radians);
void handleBasicOperation();
void handleTrigonometric();
void handleLogarithmic();
void handlePowerRoot();
void handleFactorial();
void handleCombinationPermutation();
void handleMemory();
void handleConstants();
void handleHistory();
void addToHistory(string operation, double input, double output);
void addToHistoryTwoInputs(string operation, double input1, double input2, double output);
void displayHistory();
void clearHistory();
bool validateInput();

// =====================================================
// MAIN FUNCTION
// =====================================================
int main() {
    int choice;
    
    // Display welcome message
    clearScreen();
    cout << "====================================================\n";
    cout << "      WELCOME TO ADVANCED SCIENTIFIC CALCULATOR     \n";
    cout << "====================================================\n";
    cout << "This calculator supports all major scientific functions\n";
    cout << "including trigonometry, logarithms, factorials, and more!\n";
    cout << "====================================================\n\n";
    
    waitForEnter();
    
    // Main program loop - continues until user exits
    do {
        clearScreen();
        displayHeader();
        displayMenu();
        
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        // Validate input - if user enters letters, clear and ask again
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input! Please enter a number.\n";
            waitForEnter();
            continue;
        }
        
        // Handle user's menu choice using switch statement
        switch(choice) {
            case 1:  // Basic Operations (add, subtract, multiply, divide)
                handleBasicOperation();
                break;
            case 2:  // Trigonometric Functions
                handleTrigonometric();
                break;
            case 3:  // Logarithmic Functions
                handleLogarithmic();
                break;
            case 4:  // Power and Root Functions
                handlePowerRoot();
                break;
            case 5:  // Factorial
                handleFactorial();
                break;
            case 6:  // Combinations and Permutations
                handleCombinationPermutation();
                break;
            case 7:  // Memory Functions
                handleMemory();
                break;
            case 8:  // Constants (PI, e)
                handleConstants();
                break;
            case 9:  // View History
                handleHistory();
                break;
            case 0:  // Exit Program
                cout << "\nThank you for using the Scientific Calculator!\n";
                cout << "Goodbye!\n\n";
                break;
            default: // Invalid choice
                cout << "\nInvalid choice! Please select 0-9.\n";
                waitForEnter();
        }
    } while(choice != 0);
    
    return 0;
}

// =====================================================
// DISPLAY FUNCTIONS
// =====================================================

// Displays the main menu options
void displayMenu() {
    cout << "╔════════════════════════════════════════════════════════╗\n";
    cout << "║                     MAIN MENU                          ║\n";
    cout << "╠════════════════════════════════════════════════════════╣\n";
    cout << "║  1. Basic Operations (+, -, ×, ÷)                     ║\n";
    cout << "║  2. Trigonometric Functions (sin, cos, tan)           ║\n";
    cout << "║  3. Logarithmic Functions (log, ln)                   ║\n";
    cout << "║  4. Power and Root Functions (x², x³, √, xⁿ)          ║\n";
    cout << "║  5. Factorial (!)                                     ║\n";
    cout << "║  6. Combinations (nCr) and Permutations (nPr)         ║\n";
    cout << "║  7. Memory Functions (M+, M-, MR, MC)                 ║\n";
    cout << "║  8. Constants (π, e)                                  ║\n";
    cout << "║  9. History                                           ║\n";
    cout << "║  0. Exit                                              ║\n";
    cout << "╚════════════════════════════════════════════════════════╝\n";
}

// Displays the header with current mode and memory status
void displayHeader() {
    cout << "══════════════════════════════════════════════════════════\n";
    cout << "  SCIENTIFIC CALCULATOR";
    cout << "    Mode: " << (degreeMode ? "DEG" : "RAD");
    if (memorySet) {
        cout << "    Memory: " << fixed << setprecision(4) << memory;
    } else {
        cout << "    Memory: Empty";
    }
    cout << "\n";
    cout << "══════════════════════════════════════════════════════════\n";
}

// Clears the screen (works on Windows)
void clearScreen() {
    system("cls");
}

// Waits for user to press Enter
void waitForEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// =====================================================
// INPUT VALIDATION FUNCTIONS
// =====================================================

// Gets a single number with validation
double getNumber(string prompt) {
    double number;
    while (true) {
        cout << prompt;
        cin >> number;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";
        } else {
            break;
        }
    }
    return number;
}

// Gets two numbers with validation
double getTwoNumbers(string prompt1, string prompt2, double &num1, double &num2) {
    num1 = getNumber(prompt1);
    num2 = getNumber(prompt2);
    return 0;
}

// =====================================================
// MATH HELPER FUNCTIONS
// =====================================================

// Converts degrees to radians
double toRadians(double degrees) {
    return degrees * PI / 180.0;
}

// Converts radians to degrees
double toDegrees(double radians) {
    return radians * 180.0 / PI;
}

// Calculates factorial of a number
double factorial(double n) {
    if (n < 0) {
        return -1;  // Error: factorial of negative number
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    double result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Calculates combinations (nCr)
double combination(double n, double r) {
    if (n < r || n < 0 || r < 0) {
        return -1;  // Error: invalid values
    }
    return factorial(n) / (factorial(r) * factorial(n - r));
}

// Calculates permutations (nPr)
double permutation(double n, double r) {
    if (n < r || n < 0 || r < 0) {
        return -1;  // Error: invalid values
    }
    return factorial(n) / factorial(n - r);
}

// =====================================================
// HISTORY FUNCTIONS
// =====================================================

// Adds calculation with one input to history
void addToHistory(string operation, double input, double output) {
    string entry = operation + "(" + to_string(input) + ") = " + to_string(output);
    if (history.size() >= MAX_HISTORY) {
        history.erase(history.begin());  // Remove oldest entry
    }
    history.push_back(entry);
}

// Adds calculation with two inputs to history
void addToHistoryTwoInputs(string operation, double input1, double input2, double output) {
    string entry = to_string(input1) + " " + operation + " " + to_string(input2) + " = " + to_string(output);
    if (history.size() >= MAX_HISTORY) {
        history.erase(history.begin());  // Remove oldest entry
    }
    history.push_back(entry);
}

// Displays all history entries
void displayHistory() {
    clearScreen();
    cout << "══════════════════════════════════════════════════════════\n";
    cout << "                     CALCULATION HISTORY                 \n";
    cout << "══════════════════════════════════════════════════════════\n";
    
    if (history.empty()) {
        cout << "\nNo calculations in history yet.\n";
    } else {
        cout << "\n";
        for (int i = 0; i < history.size(); i++) {
            cout << setw(3) << (i + 1) << ". " << history[i] << "\n";
        }
        cout << "\nTotal entries: " << history.size() << " / " << MAX_HISTORY << "\n";
    }
    cout << "\n══════════════════════════════════════════════════════════\n";
    waitForEnter();
}

// Clears all history
void clearHistory() {
    history.clear();
    cout << "\nHistory cleared!\n";
    waitForEnter();
}

// =====================================================
// HANDLER FUNCTIONS FOR EACH MENU OPTION
// =====================================================

// =====================================================
// HANDLER 1: Basic Operations
// =====================================================
void handleBasicOperation() {
    clearScreen();
    cout << "══════════════════════════════════════════════════════════\n";
    cout << "                  BASIC OPERATIONS                       \n";
    cout << "══════════════════════════════════════════════════════════\n\n";
    
    int operation;
    cout << "1. Addition (+)\n";
    cout << "2. Subtraction (-)\n";
    cout << "3. Multiplication (×)\n";
    cout << "4. Division (÷)\n";
    cout << "Enter operation (1-4): ";
    cin >> operation;
    
    if (cin.fail() || operation < 1 || operation > 4) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid operation!\n";
        waitForEnter();
        return;
    }
    
    double num1, num2, result;
    cout << "\n";
    num1 = getNumber("Enter first number: ");
    num2 = getNumber("Enter second number: ");
    
    string opSymbol;
    switch(operation) {
        case 1:
            result = num1 + num2;
            opSymbol = "+";
            break;
        case 2:
            result = num1 - num2;
            opSymbol = "-";
            break;
        case 3:
            result = num1 * num2;
            opSymbol = "×";
            break;
        case 4:
            if (num2 == 0) {
                cout << "\nERROR: Cannot divide by zero!\n";
                waitForEnter();
                return;
            }
            result = num1 / num2;
            opSymbol = "÷";
            break;
    }
    
    cout << fixed << setprecision(6);
    cout << "\n" << num1 << " " << opSymbol << " " << num2 << " = " << result << "\n";
    addToHistoryTwoInputs(opSymbol, num1, num2, result);
    waitForEnter();
}

// =====================================================
// HANDLER 2: Trigonometric Functions
// =====================================================
void handleTrigonometric() {
    clearScreen();
    cout << "══════════════════════════════════════════════════════════\n";
    cout << "                TRIGONOMETRIC FUNCTIONS                  \n";
    cout << "══════════════════════════════════════════════════════════\n";
    cout << "Current Mode: " << (degreeMode ? "DEGREES" : "RADIANS") << "\n\n";
    
    int operation;
    cout << "1. sin (sine)\n";
    cout << "2. cos (cosine)\n";
    cout << "3. tan (tangent)\n";
    cout << "4. asin (arcsine)\n";
    cout << "5. acos (arccosine)\n";
    cout << "6. atan (arctangent)\n";
    cout << "7. Toggle Degree/Radian Mode\n";
    cout << "Enter operation (1-7): ";
    cin >> operation;
    
    if (cin.fail() || operation < 1 || operation > 7) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid operation!\n";
        waitForEnter();
        return;
    }
    
    if (operation == 7) {
        degreeMode = !degreeMode;
        cout << "\nMode toggled to " << (degreeMode ? "DEGREES" : "RADIANS") << "!\n";
        waitForEnter();
        return;
    }
    
    double angle, result;
    angle = getNumber("Enter angle: ");
    
    double angleInRadians = degreeMode ? toRadians(angle) : angle;
    
    switch(operation) {
        case 1:
            result = sin(angleInRadians);
            addToHistory("sin", angle, result);
            break;
        case 2:
            result = cos(angleInRadians);
            addToHistory("cos", angle, result);
            break;
        case 3:
            if (cos(angleInRadians) == 0) {
                cout << "\nERROR: tan is undefined at this angle!\n";
                waitForEnter();
                return;
            }
            result = tan(angleInRadians);
            addToHistory("tan", angle, result);
            break;
        case 4:
            if (angle < -1 || angle > 1) {
                cout << "\nERROR: asin domain is [-1, 1]!\n";
                waitForEnter();
                return;
            }
            result = asin(angle);
            if (degreeMode) result = toDegrees(result);
            addToHistory("asin", angle, result);
            break;
        case 5:
            if (angle < -1 || angle > 1) {
                cout << "\nERROR: acos domain is [-1, 1]!\n";
                waitForEnter();
                return;
            }
            result = acos(angle);
            if (degreeMode) result = toDegrees(result);
            addToHistory("acos", angle, result);
            break;
        case 6:
            result = atan(angle);
            if (degreeMode) result = toDegrees(result);
            addToHistory("atan", angle, result);
            break;
    }
    
    cout << fixed << setprecision(6);
    string funcName[] = {"", "sin", "cos", "tan", "asin", "acos", "atan"};
    cout << "\n" << funcName[operation] << "(" << angle << ") = " << result << "\n";
    waitForEnter();
}

// =====================================================
// HANDLER 3: Logarithmic Functions
// =====================================================
void handleLogarithmic() {
    clearScreen();
    cout << "══════════════════════════════════════════════════════════\n";
    cout << "                 LOGARITHMIC FUNCTIONS                   \n";
    cout << "══════════════════════════════════════════════════════════\n\n";
    
    int operation;
    cout << "1. log (base 10)\n";
    cout << "2. ln (natural log, base e)\n";
    cout << "3. log base 2\n";
    cout << "4. log base n (custom base)\n";
    cout << "Enter operation (1-4): ";
    cin >> operation;
    
    if (cin.fail() || operation < 1 || operation > 4) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid operation!\n";
        waitForEnter();
        return;
    }
    
    double number, base, result;
    number = getNumber("Enter number: ");
    
    if (number <= 0) {
        cout << "\nERROR: Logarithm of non-positive number is undefined!\n";
        waitForEnter();
        return;
    }
    
    switch(operation) {
        case 1:
            result = log10(number);
            addToHistory("log", number, result);
            cout << fixed << setprecision(6);
            cout << "\nlog10(" << number << ") = " << result << "\n";
            break;
        case 2:
            result = log(number);
            addToHistory("ln", number, result);
            cout << fixed << setprecision(6);
            cout << "\nln(" << number << ") = " << result << "\n";
            break;
        case 3:
            result = log2(number);
            addToHistory("log2", number, result);
            cout << fixed << setprecision(6);
            cout << "\nlog2(" << number << ") = " << result << "\n";
            break;
        case 4:
            base = getNumber("Enter base: ");
            if (base <= 0 || base == 1) {
                cout << "\nERROR: Base must be positive and not equal to 1!\n";
                waitForEnter();
                return;
            }
            result = log(number) / log(base);
            addToHistoryTwoInputs("log base", base, number, result);
            cout << fixed << setprecision(6);
            cout << "\nlog" << base << "(" << number << ") = " << result << "\n";
            break;
    }
    waitForEnter();
}

// =====================================================
// HANDLER 4: Power and Root Functions
// =====================================================
void handlePowerRoot() {
    clearScreen();
    cout << "══════════════════════════════════════════════════════════\n";
    cout << "                   POWER AND ROOT                        \n";
    cout << "══════════════════════════════════════════════════════════\n\n";
    
    int operation;
    cout << "1. Square (x²)\n";
    cout << "2. Cube (x³)\n";
    cout << "3. Square Root (√x)\n";
    cout << "4. Cube Root (∛x)\n";
    cout << "5. Power (xⁿ)\n";
    cout << "6. Root (ⁿ√x)\n";
    cout << "7. 10 to the power (10ˣ)\n";
    cout << "8. e to the power (eˣ)\n";
    cout << "Enter operation (1-8): ";
    cin >> operation;
    
    if (cin.fail() || operation < 1 || operation > 8) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid operation!\n";
        waitForEnter();
        return;
    }
    
    double number, power, result;
    
    switch(operation) {
        case 1:
            number = getNumber("Enter number: ");
            result = number * number;
            addToHistory("square", number, result);
            cout << fixed << setprecision(6);
            cout << "\n" << number << "² = " << result << "\n";
            break;
        case 2:
            number = getNumber("Enter number: ");
            result = number * number * number;
            addToHistory("cube", number, result);
            cout << fixed << setprecision(6);
            cout << "\n" << number << "³ = " << result << "\n";
            break;
        case 3:
            number = getNumber("Enter number: ");
            if (number < 0) {
                cout << "\nERROR: Square root of negative number is complex!\n";
                waitForEnter();
                return;
            }
            result = sqrt(number);
            addToHistory("sqrt", number, result);
            cout << fixed << setprecision(6);
            cout << "\n√" << number << " = " << result << "\n";
            break;
        case 4:
            number = getNumber("Enter number: ");
            if (number < 0) {
                result = -cbrt(-number);
            } else {
                result = cbrt(number);
            }
            addToHistory("cbrt", number, result);
            cout << fixed << setprecision(6);
            cout << "\n∛" << number << " = " << result << "\n";
            break;
        case 5:
            number = getNumber("Enter base: ");
            power = getNumber("Enter exponent: ");
            result = pow(number, power);
            addToHistoryTwoInputs("^", number, power, result);
            cout << fixed << setprecision(6);
            cout << "\n" << number << " ^ " << power << " = " << result << "\n";
            break;
        case 6:
            number = getNumber("Enter number: ");
            power = getNumber("Enter root (n): ");
            if (number < 0 && fmod(power, 2) == 0) {
                cout << "\nERROR: Even root of negative number is complex!\n";
                waitForEnter();
                return;
            }
            if (number < 0) {
                result = -pow(-number, 1.0/power);
            } else {
                result = pow(number, 1.0/power);
            }
            addToHistoryTwoInputs("root", number, power, result);
            cout << fixed << setprecision(6);
            cout << "\n" << power << "√" << number << " = " << result << "\n";
            break;
        case 7:
            number = getNumber("Enter exponent: ");
            result = pow(10, number);
            addToHistory("10^", number, result);
            cout << fixed << setprecision(6);
            cout << "\n10^" << number << " = " << result << "\n";
            break;
        case 8:
            number = getNumber("Enter exponent: ");
            result = exp(number);
            addToHistory("e^", number, result);
            cout << fixed << setprecision(6);
            cout << "\ne^" << number << " = " << result << "\n";
            break;
    }
    waitForEnter();
}

// =====================================================
// HANDLER 5: Factorial
// =====================================================
void handleFactorial() {
    clearScreen();
    cout << "══════════════════════════════════════════════════════════\n";
    cout << "                      FACTORIAL                          \n";
    cout << "══════════════════════════════════════════════════════════\n\n";
    
    double number = getNumber("Enter a non-negative integer: ");
    
    if (number < 0) {
        cout << "\nERROR: Factorial of negative number is undefined!\n";
        waitForEnter();
        return;
    }
    
    if (number != floor(number)) {
        cout << "\nERROR: Factorial is only defined for integers!\n";
        waitForEnter();
        return;
    }
    
    double result = factorial(number);
    cout << fixed << setprecision(0);
    cout << "\n" << number << "! = " << result << "\n";
    addToHistory("factorial", number, result);
    waitForEnter();
}

// =====================================================
// HANDLER 6: Combinations and Permutations
// =====================================================
void handleCombinationPermutation() {
    clearScreen();
    cout << "══════════════════════════════════════════════════════════\n";
    cout << "             COMBINATIONS & PERMUTATIONS                 \n";
    cout << "══════════════════════════════════════════════════════════\n\n";
    
    int operation;
    cout << "1. Combinations (nCr)\n";
    cout << "2. Permutations (nPr)\n";
    cout << "Enter operation (1-2): ";
    cin >> operation;
    
    if (cin.fail() || operation < 1 || operation > 2) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid operation!\n";
        waitForEnter();
        return;
    }
    
    double n = getNumber("Enter n (total items): ");
    double r = getNumber("Enter r (items to choose): ");
    
    if (n < 0 || r < 0 || n < r) {
        cout << "\nERROR: Invalid values! n ≥ r ≥ 0 required.\n";
        waitForEnter();
        return;
    }
    
    if (n != floor(n) || r != floor(r)) {
        cout << "\nERROR: n and r must be integers!\n";
        waitForEnter();
        return;
    }
    
    double result;
    string opName;
    if (operation == 1) {
        result = combination(n, r);
        opName = "nCr";
    } else {
        result = permutation(n, r);
        opName = "nPr";
    }
    
    cout << fixed << setprecision(0);
    cout << "\n" << opName << "(" << n << ", " << r << ") = " << result << "\n";
    addToHistoryTwoInputs(opName, n, r, result);
    waitForEnter();
}

// =====================================================
// HANDLER 7: Memory Functions
// =====================================================
void handleMemory() {
    clearScreen();
    cout << "══════════════════════════════════════════════════════════\n";
    cout << "                     MEMORY FUNCTIONS                    \n";
    cout << "══════════════════════════════════════════════════════════\n";
    if (memorySet) {
        cout << "Current Memory: " << fixed << setprecision(6) << memory << "\n";
    } else {
        cout << "Current Memory: Empty\n";
    }
    cout << "\n";
    
    int operation;
    cout << "1. M+ (Add to memory)\n";
    cout << "2. M- (Subtract from memory)\n";
    cout << "3. MR (Recall memory)\n";
    cout << "4. MC (Clear memory)\n";
    cout << "5. MS (Store to memory)\n";
    cout << "Enter operation (1-5): ";
    cin >> operation;
    
    if (cin.fail() || operation < 1 || operation > 5) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid operation!\n";
        waitForEnter();
        return;
    }
    
    double number;
    switch(operation) {
        case 1:  // M+
            number = getNumber("Enter number to add: ");
            if (!memorySet) {
                memory = 0;
                memorySet = true;
            }
            memory += number;
            cout << fixed << setprecision(6);
            cout << "\nMemory updated: " << memory << "\n";
            break;
        case 2:  // M-
            number = getNumber("Enter number to subtract: ");
            if (!memorySet) {
                memory = 0;
                memorySet = true;
            }
            memory -= number;
            cout << fixed << setprecision(6);
            cout << "\nMemory updated: " << memory << "\n";
            break;
        case 3:  // MR
            if (!memorySet) {
                cout << "\nERROR: Memory is empty!\n";
            } else {
                cout << fixed << setprecision(6);
                cout << "\nMemory recall: " << memory << "\n";
            }
            break;
        case 4:  // MC
            memory = 0;
            memorySet = false;
            cout << "\nMemory cleared!\n";
            break;
        case 5:  // MS
            number = getNumber("Enter number to store: ");
            memory = number;
            memorySet = true;
            cout << fixed << setprecision(6);
            cout << "\nMemory stored: " << memory << "\n";
            break;
    }
    waitForEnter();
}

// =====================================================
// HANDLER 8: Constants
// =====================================================
void handleConstants() {
    clearScreen();
    cout << "══════════════════════════════════════════════════════════\n";
    cout << "                       CONSTANTS                         \n";
    cout << "══════════════════════════════════════════════════════════\n\n";
    
    int operation;
    cout << "1. π (PI)\n";
    cout << "2. e (Euler's number)\n";
    cout << "3. √2\n";
    cout << "4. √3\n";
    cout << "5. φ (Golden ratio)\n";
    cout << "6. Use constant in calculation\n";
    cout << "Enter operation (1-6): ";
    cin >> operation;
    
    if (cin.fail() || operation < 1 || operation > 6) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid operation!\n";
        waitForEnter();
        return;
    }
    
    double constantValue;
    string constantName;
    
    switch(operation) {
        case 1:
            constantValue = PI;
            constantName = "π";
            break;
        case 2:
            constantValue = M_E;
            constantName = "e";
            break;
        case 3:
            constantValue = sqrt(2);
            constantName = "√2";
            break;
        case 4:
            constantValue = sqrt(3);
            constantName = "√3";
            break;
        case 5:
            constantValue = (1 + sqrt(5)) / 2;
            constantName = "φ";
            break;
        case 6:
            cout << "Constants available:\n";
            cout << "1. π (PI) = " << PI << "\n";
            cout << "2. e = " << M_E << "\n";
            cout << "3. √2 = " << sqrt(2) << "\n";
            cout << "4. √3 = " << sqrt(3) << "\n";
            cout << "5. φ = " << (1 + sqrt(5)) / 2 << "\n";
            int choice;
            cout << "Select constant (1-5): ";
            cin >> choice;
            switch(choice) {
                case 1: constantValue = PI; constantName = "π"; break;
                case 2: constantValue = M_E; constantName = "e"; break;
                case 3: constantValue = sqrt(2); constantName = "√2"; break;
                case 4: constantValue = sqrt(3); constantName = "√3"; break;
                case 5: constantValue = (1 + sqrt(5)) / 2; constantName = "φ"; break;
                default:
                    cout << "Invalid choice!\n";
                    waitForEnter();
                    return;
            }
            double number = getNumber("Enter number to combine with constant: ");
            int op;
            cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n";
            cout << "Choose operation: ";
            cin >> op;
            double result;
            switch(op) {
                case 1: result = constantValue + number; break;
                case 2: result = constantValue - number; break;
                case 3: result = constantValue * number; break;
                case 4: 
                    if (number == 0) {
                        cout << "ERROR: Division by zero!\n";
                        waitForEnter();
                        return;
                    }
                    result = constantValue / number; 
                    break;
                default:
                    cout << "Invalid operation!\n";
                    waitForEnter();
                    return;
            }
            cout << fixed << setprecision(6);
            cout << "\n" << constantName << " and " << number << " = " << result << "\n";
            addToHistoryTwoInputs("with constant", constantValue, number, result);
            waitForEnter();
            return;
    }
    
    cout << fixed << setprecision(10);
    cout << "\n" << constantName << " = " << constantValue << "\n";
    addToHistory(constantName, 0, constantValue);
    waitForEnter();
}

// =====================================================
// HANDLER 9: History
// =====================================================
void handleHistory() {
    clearScreen();
    cout << "══════════════════════════════════════════════════════════\n";
    cout << "                       HISTORY                           \n";
    cout << "══════════════════════════════════════════════════════════\n\n";
    
    int operation;
    cout << "1. View History\n";
    cout << "2. Clear History\n";
    cout << "3. Back to Main Menu\n";
    cout << "Enter operation (1-3): ";
    cin >> operation;
    
    if (cin.fail() || operation < 1 || operation > 3) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid operation!\n";
        waitForEnter();
        return;
    }
    
    switch(operation) {
        case 1:
            displayHistory();
            break;
        case 2:
            clearHistory();
            break;
        case 3:
            // Just return to main menu
            break;
    }
}

// =====================================================
// END OF PROGRAM
// =====================================================