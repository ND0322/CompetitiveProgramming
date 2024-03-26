#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, x, a[MAXN];
int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> x;

        int ind = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];

            if(a[i] == x) ind = i;
        }

        int lo = 1;
        int hi = n+1;

        while(hi-lo > 1){
            int mid = (hi+lo)>>1;

            if(a[mid] <= x) lo = mid;
            else hi = mid;
        }

        cout << "1\n";
        cout << ind << " " << lo << "\n";
    }
}