#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);
        vector<int> b(n);

        for(int i = 0; i < n; i++){
            int x; cin >> x;
            a[x] = i;
        }

        for(int i = 0; i < n; i++) cin >> b[i];

        bool flag = 1;

        for(int i = n-1; i >= 1; i--){
            //cout << a[b[i]] << " " << a[b[i-1]] << "\n";
            if(a[b[i]] < a[b[i-1]]){
                cout << i << "\n";
                flag = 0;
                break;
            }
        }

        if(flag) cout << "0\n";
    }
}