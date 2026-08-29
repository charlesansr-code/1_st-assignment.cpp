#include <iostream>
int main (){
using namespace std;
int month;
cout << "ENTER A MONTH FROM (1 TO 12)";
cin >> month;

switch(month){
    case 1:
    cout << "TODAY IS JANUARY";
    break;
    case 2:
    cout << "TODAY IS FEBUARY";
    break;
    case 3:
    cout << "TODAY IS MARCH";
    break;
    case 4:
    cout << "TODAY IS APRIL";
    break;
    case 5:
    cout << "TODAY IS MAY";
    break;
    case 6:
    cout << "TODAY JUNE";
    break;
    case 7:
    cout << "TODAY IS JULY";
    break;
    case 8:
    cout << "TODAY IS AUSGUST";
    break;
    case 9:
    cout << "TODAY IS SEPTEMBER";
    break;
    case 10:
    cout << "TODAY IS OCTOBER";
    break;
    case 11:
    cout << "TODAY IS NOVEMBER";
    break;
    case 12:
    cout << "TODAY IS DECEMBER";
    break;
default:
cout << "PLEASE ONLY ENTER NUMBER (1 TO 12)";
}
    return 0;
}