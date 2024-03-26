#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n,k,psa[MAXN];

string s;


int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> k;

        cin >> s;

        

        

        int ans = 0;
        int i = 0;

        while(i < n){

            if(s[i] == 'B'){
                ans++;
                i+=k;
                continue;
            }
            i++;
        }

        cout << ans << "\n";

        
    }
}