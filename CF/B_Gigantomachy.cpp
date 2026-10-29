#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,m; cin >> n >> m;

        vector<int> a(n+2);
        vector<int> b(m+2);

        //gaps or sum shit
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= m; i++) cin >> b[i];

        int ans1 = 0;
        int ans2 = 0;
        for(int i = 1; i < n; i++) ans1 += a[i] - a[i+1]+1;
        for(int i = 1; i < m; i++) ans2 += b[i] - b[i+1]+1;

        ans1 += a[n];
        ans2 += b[m];

        if(ans1 < ans2) cout << "2\n";
        else cout << "1\n";


        
          
    }
}