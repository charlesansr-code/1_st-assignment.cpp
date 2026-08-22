#include <iostream>
int main(){

int age;
std::cout<<"Enter your Age; ";
std::cin >> age;
if(age >= 100){
    std::cout <<  "HOW??";
}
else if(age >= 18){
std::cout << "Welcome to the WEB";
}

else if (age < 0){
    std::cout << "You are not born yet? ";
}
else if (age <= 17)
std::cout << "You are not allowed to enter the website";



return 0;
}