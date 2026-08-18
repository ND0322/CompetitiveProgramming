#include <bits/stdc++.h>
#include <iostream>

using namespace std;


const int MOD = 998244353;



int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);
        vector<int> freq(n+1);
        
        
        int mx = 0;

        int l = -1;
        int r = -1;

        for(int i = 1; i < n; i++){
            cin >> a[i];
            freq[a[i]]++;
            mx = max(mx, a[i]);
        }

        for(int i = 1; i < n; i++){
            if(l == -1 && a[i] == mx) l = i;
            if(a[i] == mx) r = max(r, i); 
        }   
        if(mx != n-1){
            cout << "0\n";
            continue;
        }

        bool flag = 1;
        for(int i = 1; i < l; i++) flag &= (a[i] <= a[i+1]);
        for(int i = l; i <= r; i++) flag &= (a[i] == mx);
        for(int i = r+1; i < n; i++) flag &= (a[i+1] <= a[i]);


        set<int> s;
        for(int i = 1; i < l; i++) s.insert(a[i]);
        for(int i = r+1; i < n; i++){
            if(s.find(a[i]) != s.end()) flag = 0;
        }

        if(!flag){
            cout << "0\n";
            continue;
        }

        int cnt = 0;

        cnt += r-l;


        long long ans = 2;

        for(int i = n-2; i >= 1; i--){
            if(freq[i]) cnt += freq[i]-1;
            else{

                if(!cnt){
                    flag = 0;
                    break;
                }
                ans = (ans * cnt) % MOD;
                cnt--;
            }
        }

        if(!flag){
            cout << "0\n";
            continue;
        }

        cout << ans << "\n";
    
      


    }
}