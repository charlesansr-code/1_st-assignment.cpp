#include <iostream>
int main(){
using namespace std;
cout << "HELLO THIS SIMPLE CODE IS FOR YOU TO GET YOUR AVERAGE SCORE IN THE TEST \n";

double score,total;
cout << "PLUG VALUE (THE SCORE YOU GOT) = ";
cin >> score;

cout << "PLUG SECOND VALUE (THE EXAM ITEMS) = ";
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
    cout << "YOU ARE ABOVE AVERAGE";
}
else if (calculate >= 75){
     cout << "YOU HAVE PASSED";
}
else if (calculate <= 70){
    cout << "YOU HAVE NOT PASSED";
}
else{
 cout << "YOU HAVE FAILED";
    }
return 0;
}