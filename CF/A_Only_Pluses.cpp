#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int a,b,c; cin >> a >> b >> c;

        for(int i = 0; i < 5; i++){
            if(a <= b && a <= c) a++;
            else if(b <= a && b <= c) b++;
            else if(c <= a && c <= b) c++;
        }

        cout << a*b*c << "\n";
    }
}