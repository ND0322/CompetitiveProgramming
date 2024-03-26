#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;

const int MAXN = 2e5+5;


int a[MAXN], n;

int main(){

    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        //calculate optimal min

        for(int i = 0; i < n; i++) cin >> a[i];

        int check = a[0];

        for(int i = 1; i < n; i++) check &= a[i];
        if(check){
            cout << "1\n";
            continue;
        }
        

        //split into groups of 0

        int pref = a[0];
        int ans = 0;

        for(int i = 1; i < n; i++){
            if(!pref){
                ans++;
                pref = a[i];
                
            }
            pref &= a[i];
        
        }

        if(!pref)ans++;
        cout << ans << "\n";
    }
    
}