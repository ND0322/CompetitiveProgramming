#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int a,b,c; cin >> a >> b >> c;

        if(c & 1){
            if(b > a){
                cout << "Second\n";
            }
            else{
                cout << "First\n";
            }
        }
        else{
            if(a > b){
                cout << "First\n";

            }
            else{
                cout << "Second\n";
            }
        }
    }
}