#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

#define int long long


const int MAXN = 2e5+5;

int n, a[MAXN];

//1, 2, 4, 5 

int32_t main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    int ans = 0;

    set<int> active;

    active.insert(a[1]);
    int r = 1;

    while(1){
        if(active.empty()){
            cout << "-1\n";
            return 0;
        }

        int l = r+1;

        if(r + *active.begin() > n){
            ans++;
            break;
        }
        int tmp = *active.begin();
        r += *active.begin();

        active.erase(active.begin());
        ans++;
        for(int i = l; i <= r; i++){
            if(a[i] > tmp) active.insert(a[i]);
        }
    }
    cout << ans << "\n";

    
}