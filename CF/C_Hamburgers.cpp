#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int a[3], b[3], c[3];

long long k;

bool can(long long x){
    return max(x*c[0] - a[0],0LL)*b[0] + max(x*c[1] - a[1],0LL)*b[1] + max(x*c[2] - a[2],0LL)*b[2] <= k;
}

int main(){
    string s; cin >> s;

    for(char i : s){
        if(i == 'B') c[0]++;
        if(i == 'S') c[1]++;
        if(i == 'C') c[2]++;
    }

    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];

    cin >> k;


    long long lo = 0;
    long long hi = 1e14;

    long long ans = 0;
    while(lo <= hi){
        long long mid = (lo+hi)>>1;

        if(can(mid)){
            ans = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }

    cout << ans << "\n";



}