#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

/*
there is a greedy strategy to just stick the max in front the whole time 


2 1 0

6 vs 1 + 3 + 2 + 3 -> 9

lets say we have k consecutive items

0 + 1
1 + 2
2 + 3
...

(1 + 1 + (k-1) * 2) / 2

k^2 + 
(2k - 1)*k/2 + 2k+1 * (n-k)> n * mx 
*/

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);
        set<int> s;
        int mx = -1;
        map<int,int> freq;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            s.insert(a[i]);
            mx = max(mx, a[i]);
            freq[a[i]]++;
        }

        int k = -1;

        for(int i = 0; i < n; i++){
            if(s.find(i) == s.end()) break;
            freq[i]--;
            k++;
        }

        freq[mx]--;

        if(k == -1){
            cout << n * mx << "\n";
            continue;
        }

        vector<int> b(n+1);






        //0 1 2 3 4 5 ... k mx . . . . . .
        int res1 = k * (k+1) / 2 + (k+1) * (k+2) / 2 + (k+1) * (n-k-1) + mx * (n-k-1);
        int res2 = mx * n + 
        cout << res1 << "\n";

    



    }
}