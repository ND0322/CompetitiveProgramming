#include <bits/stdc++.h>
#include <iostream>

using namespace std;

long double turtle[3], target[3];




int main(){
    cin >> turtle[0] >> turtle[1] >> turtle[2];
    cin >> target[0] >> target[1] >> target[2];


    //say turtle starts at 0 0 0
    turtle[0] = target[0] - turtle[0];
    turtle[1] = target[1] - turtle[1];
    turtle[2] = target[2] - turtle[2];

    long double ans = turtle[0] * turtle[0] +  turtle[1] * turtle[1] + turtle[2] * turtle[2];


    while(true){
        double d; char dir; cin >> d >> dir;

        
        double x = turtle[0] - d;

        if(x * turtle[0] < 0) ans = min(ans, turtle[1] * turtle[1] + turtle[2] * turtle[2]);
        else ans = min(ans, x * x + turtle[1] * turtle[1] + turtle[2] * turtle[2]);
       
        


  

        turtle[0] = x;

        long double temp = turtle[0];

        if(dir == 'E') break;
        if(dir == 'L'){
            turtle[0] = turtle[1];
            turtle[1] = -temp;
        }
        if(dir == 'R'){
            turtle[0] = -turtle[1];
            turtle[1] = temp;
        }

        if(dir == 'U'){
            turtle[0] = turtle[2];
            turtle[2] = -temp;
        }
        if(dir == 'D'){
            turtle[0] = -turtle[2];
            turtle[2] = temp;
        }


    }


   

    cout << setprecision(2) << fixed << sqrt(ans) << "\n";
}