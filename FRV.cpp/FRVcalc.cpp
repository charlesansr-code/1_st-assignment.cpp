#include <iostream>
int main(){
    using namespace std;
double num1,num2,run;
char op;

cout << "ENTER OPERATOR (+,-,*,/)";
cin >> op;

cout << "Enter num 1";
cin >> num1;

cout << "Enter num 2";
cin >> num2;

switch(op){
case '+':
run = num1 + num2;
cout << "ANS :" << run << "\n";
break;
case '-':
run = num1 - num2;
cout << "ANS :" << run << "\n";
break;
case '*':
run = num1*num2;
cout << "ANS :"<< run << "\n";
break;
case '/':
run = num1/num2;
cout << "ANS :"<< run << "\n";
break;
default:
cout << "INVALID OPERATOR";


}




    return 0;
}