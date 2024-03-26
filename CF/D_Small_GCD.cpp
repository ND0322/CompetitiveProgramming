#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 1e5+5;

int phi[MAXN], cnt[MAXN];

vector<int> divisors[MAXN];

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}


int32_t main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    for(int i = 1; i < MAXN; i++){
        phi[i] = i;
        divisors[i].push_back(i);
    }

    for(int i = 1; i < MAXN; i++){
        for(int j = i<<1; j < MAXN; j+=i){
            phi[j] -= phi[i];
            divisors[j].push_back(i);
        }
    }
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);
        memset(cnt,0,sizeof(cnt));

        for(int i = 1; i <= n; i++)cin >> a[i];

        sort(a.begin(), a.end());
        long long ans = 0;
        //vector<int> phi = eulerTotient(n);
        //vector<int> pre = preCompute(n, phi);


        for(int i = 1; i <= n; i++){
            for(int d : divisors[a[i]]) ans += (n-i) * phi[d] * cnt[d]++;
           

        }


        cout << ans << "\n";

        
    }
}