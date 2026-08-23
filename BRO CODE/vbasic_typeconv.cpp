#include <iostream>
int main(){
using namespace std;

cout << "HELLO THIS SIMPLE CODE IS FOR YOU TO GET YOUR AVERAGE SCORE IN THE TEST \n";

double score,total;
cout << "PLUG VALUE (the score you got) = ";
cin >> score;

cout << "PLUG SECOND VALUE (your total score) = ";
cin >> total;

double calculate = score/(double)total * 100;
cout << "You got = " << calculate << "% \n";

if(calculate == 100){
    cout << "CONGRATULATIONS AND KEEP IT UP ";
}
else if(calculate >= 90){
     cout << "WOW THATS A HIGH SCORE";
}
else if (calculate >= 80 ){
    cout << "YOU ARE ABOVE AVRAGE";
}
else if (calculate == 75){
     cout << "YOU HAVE PASSED";
}
else if (calculate < 70){
    cout << "YOU HAVE NOT PASSED";
}


return 0;
}