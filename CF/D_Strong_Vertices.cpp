#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;

const int MAXN = 2e5+5;
const long long INF = 1e10;

int n;

ll a[MAXN],b[MAXN];

int main(){

    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        ll big = -INF;

        for(int i = 0; i < n; i++) big = max(big,a[i]-b[i]);

        vector<int> ans;

        for(int i = 0; i < n; i++){
            if(a[i]-b[i] == big) ans.push_back(i+1);
            
        }

        cout << ans.size() << "\n";

        for(int i :ans) cout << i << " ";

        cout << "\n";

        }
    
 

    


    


}