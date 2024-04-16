#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5e5+5;

int n, a[MAXN], psa[MAXN];

int main(){
    cin >> n;

    long long sum = 0;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }

    if(sum%3){
        cout << "0\n";
        return 0;
    }

    long long pref = 0;

    for(int i = 1; i <= n; i++){
        pref += a[i];
        if(pref == sum/3) psa[i]++;
        psa[i] += psa[i-1];
    }


    

    pref = 0;
    long long ans = 0;
    for(int i = n; i >= 1; i--){
        pref += a[i];

        if(pref != (sum/3)) continue;
        ans += psa[i-2];
    }
    cout << ans << "\n";

   
}