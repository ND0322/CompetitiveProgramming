#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int color[MAXN];

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        if(n <= 5){
            if(n == 1) cout << "1\n";
            if(n == 2) cout << "2\n";
            if(n == 3) cout << "2\n";
            if(n == 4) cout << "3\n";
            if(n == 5) cout << "3\n";
            cout << "1 ";
            for(int i = 3; i <= n+1; i++) cout << (int)ceil((i/2.0)) << " ";
            cout << "\n";
            continue;
        }

        cout << 4 << "\n";
        for(int i = 1; i <= n; i++) cout << i%4+1 << " ";
        cout << "\n";

    
        
        



        

    }
}