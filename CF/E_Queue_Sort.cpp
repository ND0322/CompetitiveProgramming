#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n);

        for(int i = 0; i < n; i++) cin >> a[i];

        int last = 0;

        for(int i = 0; i < n; i++) if(a[i] < a[last]) last = i;

        bool flag = true;

        for(int i = last+1; i < n; i++){
            if(a[i] < a[i-1]){
                flag = false;
                break;
            }
        }

        cout << (flag ? last : -1) << "\n";
    }
}