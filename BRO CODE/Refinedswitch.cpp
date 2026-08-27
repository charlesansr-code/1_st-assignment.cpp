#include <iostream>
using namespace std;

int main (){
    int month;
    
    cout << "ENTER A NUMBER FOR THE MONTH (1 to 12)     :";
    cin >> month;
    
    switch(month){
        case 1 :
        cout << "IT IS JANUARY";
        break;  // Added break
    }
    
    switch(month){
        case 2 :
        cout << "IT IS FEBRUARY";
        break;  // Added break
    }
    
    switch(month){
        case 3 :
        cout << "IT IS MARCH";
        break;  // Added break
    }
    
    switch(month){
        case 4 :
        cout << "IT IS APRIL";
        break;  // Added break
    }
    
    switch(month){
        case 5 :
        cout << "IT IS MAY";
        break;  // Added break
    }
    
    switch(month){
        case 6 :
        cout << "IT IS JUNE";
        break;  // Added break
    }
    
    switch(month){
        case 7 :
        cout << "IT IS JULY";
        break;  // Added break
    }
    
    switch(month){
        case 8 :
        cout << "IT IS AUGUST";
        break;  // Added break
    }
    
    switch(month){
        case 9 :
        cout << "IT IS SEPTEMBER";
        break;  // Added break
    }
    
    switch(month){
        case 10 :
        cout << "IT IS OCTOBER";
        break;  // Added break
    }
    
    switch(month){
        case 11 :
        cout << "IT IS NOVEMBER";
        break;  // Added break
    }
    
    switch(month){
        case 12 :
        cout << "IT IS DECEMBER";
        break;  // Added break
    }
    
    if(month > 12){
        cout << "INVALID NUMBER";
    }
    else if(month <= 0)
        cout << "INVALID NUMBER";
    
    return 0;
}