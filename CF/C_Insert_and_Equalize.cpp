#include <bits/stdc++.h>
#include <iostream>

using namespace std;

long long gcd(long long a, long long b){
    return !b ? a : gcd(b, a%b);
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<long long> a(n);

        long long cur = 0;
        long long sum = 0;

        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
        }

        for(int i = 0; i < n-1; i++) cur = gcd(cur,abs(a[i+1]-a[i]));
        
        cur = max(cur, 1LL);

        sort(a.begin(), a.end());

        long long ans =  a[n-1];

        int j = n-1;

        while(1){
            while(j >= 0 && a[j] > ans) j--;
            if(j < 0 || a[j] != ans) break;
            ans -= cur;
        }

        
        cout << ((a[n-1]) * (n+1) - (sum + ans))/cur << "\n";


        




        


    }
}