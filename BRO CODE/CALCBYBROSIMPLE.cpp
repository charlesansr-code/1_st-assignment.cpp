#include <iostream>
int main(){
using namespace std;
char op;
double num1,num2;
double result;

cout << "********** CALCULATOR **********\n";

cout << "Enter Either (+,-,*,/) = ";
cin >> op;

cout << "Enter # 1: ";
cin >> num1;

cout << "Enter # 2:";
cin >> num2;

switch(op){
    case '+':
    result = num1 + num2;
    cout << "result: " << result << "\n";
 break;
    case '-':
    result = num1 - num2;
    cout << "result:  " << result << "\n";
break;
    case '*':
     result = num1 * num2;
    cout << "result: " << result << "\n";
    break;
    case '/':
     result = num1 / num2;
    cout << "result:" << result << "\n";
    break;
    default:
    cout << "INVALID OPERATOR";
}

cout << "********************************";


    return 0;
}