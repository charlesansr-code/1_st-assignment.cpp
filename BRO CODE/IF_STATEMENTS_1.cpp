#include <iostream>
int main(){
    using namespace std;
int age;

cout << "Enter Your Age";
cin >> age;

if(age>= 18){
cout << "Welcome to the site";
}
else if(age < 0)
cout << "You havent been born yet";
else if(age < 18){
    cout << "You are not old to enter";
}
else if (age >= 100){
cout << "Hello super BOOMER";
}
else if (age >= 60){
cout << "Hello Boomer";
}


    return 0;
} 