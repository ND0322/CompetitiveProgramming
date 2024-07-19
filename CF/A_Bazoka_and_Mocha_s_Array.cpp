#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, a[MAXN];

int main(){
    int tt; cin >> tt;
    while(tt--){
        cin >> n;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            a[i+n] = a[i]; 
        }

        bool ans = 0;
        for(int i = 1; i <= n; i++){
            bool flag = 1;

            for(int j = i+1; j < i+n; j++){
                if(a[j] < a[j-1]){
                    flag = 0;
                    break;
                
                }
            }

            if(flag){
                cout << "Yes\n";
                ans = 1;
                break;
            }
        }

        if(!ans) cout << "No\n";
    }
    
}