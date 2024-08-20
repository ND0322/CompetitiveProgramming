#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int a,b,c,d; cin >> a >> b >> c >> d;

        //case 1: one contains the other 
        //case 2: no intersection
        //case 3 intersection

        //length of intersection + number of connections 

        if(b < c || d < a){
            cout << "1\n";
            continue;
        }

        if(a == c && b == d){
            cout << b-a << "\n";
            continue;
        }

        //left aligned
        if(a == c){
            cout << min(b,d) - a + 1 << "\n";
            continue;
        }

        if(b == d){
            cout << b - max(a,c) + 1 << "\n";
            continue;
        }

        if(a < c && b > d){
            cout << d-c + 2 << "\n";
            continue;
        }

        if(c < a && d > b){
            cout << b-a + 2 << "\n";
            continue;
        }

        cout << min(b,d) - max(a,c) + 2 << "\n";
    }
}