#include <bits/stdc++.h>
#include <iostream>

using namespace std;



const int MAXN = 2e5+5;
const int MAXX = 1e6+5;

int n, q, pcnt[MAXX], scnt[MAXX];

long long psa[MAXX], ssa[MAXX];

long long f(long long x, long long a, long long b){
   
    return (x * pcnt[x] - psa[x]) * a + (ssa[x] - scnt[x] * x)  * b; 
}

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        psa[x]+=x;
        ssa[x]+=x;
        pcnt[x]++;
        scnt[x]++;
    }

    for(int i = 1; i <= 1e6; i++){
        psa[i] += psa[i-1];
        pcnt[i] += pcnt[i-1];
    }
    for(int i = 1e6; i >= 0; i--){
        ssa[i] += ssa[i+1];
        scnt[i] += scnt[i+1];
    }

    cin >> q;

    while(q--){
        long long a,b; cin >> a >> b;
        int lo = 0;
        int hi = 1e6;

        while(lo < hi){
            int mid = (lo+hi)>>1;

            if(f(mid,a,b) < f(mid+1,a,b)) hi = mid;
            else lo = mid+1;
        }

        cout << f(lo, a,b) << "\n";
    }

}