#include <iostream>
int main (){
int month;
using namespace std;

cout << "ENTER A NUMBER FOR THE MONTH (1 to 12)     :";
cin >> month;

switch(month){
    case 1 :
    cout << "IT IS JANUARY";
}

switch(month){
    case 2 :
    cout << "IT IS FEBUARY";
}


switch(month){
    case 3 :
    cout << "IT IS MARCH";
}

switch(month){
    case 4 :
    cout << "IT IS APRIL";
}

switch(month){
    case 5 :
    cout << "IT IS MAY";
}

switch(month){
    case 6 :
    cout << "IT IS JUNE";
}

switch(month){
    case 7 :
    cout << "IT IS JULY";
}


switch(month){
    case 8 :
    cout << "IT IS AUGUST";
}


switch(month){
    case 9 :
    cout << "IT IS SEPTEMBER";
}

switch(month){
    case 10 :
    cout << "IT IS OCTOBER";
}

switch(month){
    case 11 :
    cout << "IT IS NOVEMBER";
}

switch(month){
    case 12 :
    cout << "IT IS DECEMBER";
}

if(month > 12){
    cout << "INVALID NUMBER";
}
else if(month<=0)
     cout << "INVALID NUMBER";
     

    return 0;
}