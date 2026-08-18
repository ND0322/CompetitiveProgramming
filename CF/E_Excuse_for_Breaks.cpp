#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n,m, d; cin >> n >> m >> d;

        vector<int> a(m+1);
        vector<int> b(m+1);

        vector<int> psa(m+1);

        for(int i = 1;i <= m; i++) cin >> a[i] >> b[i];

        //compare average value
        //for n cyclic its (n / m) * sm + psa[(n % m)]

        for(int i = 1; i <= m; i++) psa[i] = psa[i-1] + b[i];

        int v1 = psa[m] + n * d;
        
        bool flag = 0;

        for(int k = 1; k <= m; k++){
            int v2 = psa[k] + a[k] * d;


            if(v2 * n > v1 * a[k]) flag = 1;
        }

        cout << (flag ? "YES\n" : "NO\n");


        //14 + 9
        
    }
}