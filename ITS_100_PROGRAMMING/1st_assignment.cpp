
#include <iostream>
using namespace std;
int main() {
char studentName[100];
int studentID;
double quiz1, quiz2, quiz3;
double lab1, lab2;
double midterm, finalExam;

// im going to see this on github

cout << "Enter Student Name: ";
cin.getline(studentName, 100);
cout << "Enter Student ID Number: ";
cin >> studentID;
cout << "Enter Quiz 1 Score: ";
cin >> quiz1;
cout << "Enter Quiz 2 Score: ";
cin >> quiz2;
cout << "Enter Quiz 3 Score: ";
cin >> quiz3;
cout << "Enter Laboratory Activity 1 Score: ";
cin >> lab1;
cout << "Enter Laboratory Activity 2 Score: ";
cin >> lab2;
cout << "Enter Midterm Examination Score: ";
cin >> midterm;
cout << "Enter Final Examination Score: ";
cin >> finalExam;


double quizAverage = (quiz1 + quiz2 + quiz3) / 3.0;
double labAverage = (lab1 + lab2) / 2.0;
double examAverage = (midterm + finalExam) / 2.0;
double finalGrade = (quizAverage * 0.15) + (labAverage * 0.35) + (examAverage * 0.50);


cout << "\nStudent Name: " << studentName << "\n";
cout << "Student ID: " << studentID << "\n";
cout << "Quiz 1: " << quiz1 << "\n";
cout << "Quiz 2: " << quiz2 << "\n";
cout << "Quiz 3: " << quiz3 << "\n";
cout << "Quiz Average: " << quizAverage << "\n";
cout << "Laboratory Activity 1: " << lab1 << "\n";
cout << "Laboratory Activity 2: " << lab2 << "\n";
cout << "Laboratory Average: " << labAverage << "\n";
cout << "Midterm Examination: " << midterm << "\n";
cout << "Final Examination: " << finalExam << "\n";
cout << "Examination Average: " << examAverage << "\n";
cout << "Final Grade: " << finalGrade << "\n";
return 0;
}
