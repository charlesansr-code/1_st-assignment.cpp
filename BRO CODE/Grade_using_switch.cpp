#include <iostream>
int main(){
using namespace std;
char grade;
cout << "What is your grade (ENTER A TO F)=  ";
cin >> grade;

switch(grade){
case 'A':
cout << "YOU DID GREAT";
break;
case 'B':
cout << "YOU DID GOOD";
break;
case 'C':
cout << "YOU DID DECENT";
break;
case 'D':
cout << "YOU DID BAD";
break;
case 'F':
cout << "UNDANG NAG SKWELA";
break;
default:
cout << "ENTER ONLY A TO F";
}

    return 0;
}