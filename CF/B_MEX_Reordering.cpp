#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        vector<int> pref(n+1), suf(n+1);

        for(int i = 1; i <= n; i++) suf[a[i]]++;

        int pmex = 0;
        int smex = 0; 

        for(int i = 0; i <= n; i++){
            if(!suf[i]){
                smex = i;
                break;
            }
        }

        bool flag = 1;

        for(int i = 1; i < n; i++){
            pref[a[i]]++;
            suf[a[i]]--;

            while(pref[pmex]) pmex++;
            if(!suf[a[i]] && a[i] < smex) smex = a[i];

            if(pmex == smex) flag = 0;


        }

        cout << (flag ? "YES\n" : "NO\n");

        
    }
}