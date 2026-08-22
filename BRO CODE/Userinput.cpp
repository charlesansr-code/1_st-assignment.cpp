#include <iostream>
using namespace std;
int main(){

std::string name;
int age;

cout << "whats your name?:"<<'\n';
std::cin >> name;
std::cout << "Hello " << name<<'\n';

std::cout << "What is your age?: "<<'\n';
std::cin>> age;
std::cout << "So you are "<< age << "years old " << '\n';

    return 0;
}

//std::getline(std::cin, name);1
//cout<< (insertion operator)
// cin >> (extraction operator)F