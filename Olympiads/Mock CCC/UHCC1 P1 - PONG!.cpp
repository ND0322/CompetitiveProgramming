#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int a,b,c,d;

int main(){
    cin >> a >> b >> c >> d;

    int x = 0;
    int y = 0;

    while(1){
        if(y <= x){
            y += b;

            if(y >= d){
                cout << "2\n";
                return 0;
            }

            x += c;

            if(x >= d){
                cout << "1\n";
                return 0;
            }
            
        }
        
        if(x < y){
            x += a;

            if(x >= d){
                cout << "1\n";
                return 0;
            }
        }
    }
}