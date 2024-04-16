#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n;

long long a[MAXN], k;

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> k;

        for(int i = 1; i <= n;i++) cin >> a[i];

        long long bk = k/2;
        long long fr = k-bk;
  

        int l = n+1;
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(fr < a[i]){
                l = i;
                a[i] -= fr;
                break;
            }
            cnt++;
            fr -= a[i];
        }

        for(int i = n; i >= l; i--){
            if(bk < a[i]) break;
            cnt++;
            bk -= a[i];
        }

        cout << cnt << "\n";

        


    }
}