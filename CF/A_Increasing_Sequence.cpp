#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        int last = 0;
        for(int i = 0; i < n; i++){
            int x; cin >> x;

            if(last+1 == x){
                last ++;
            }

            last++;

            
        }

        cout << last << "\n";
    }
}