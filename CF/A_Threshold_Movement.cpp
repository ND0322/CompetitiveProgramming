#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+3);

        set<int> s;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            s.insert(a[i]-1);
            s.insert(a[i]+1);
        }
        

        bool ans = 0;
        for(int i : s){
            vector<int> b(n+3);

            bool flag = 1;

            for(int j = 1; j <= n; j++){
                if(a[j] == i) {
                    flag = 0;

                    break;
                }

                if(a[j] < i) b[j-1] = a[j];
                else b[j+1] = a[j];
            }

            for(int j = 1; j <= n; j++) flag &= b[j] != 0;
            ans |= flag;
        
        }

        cout << (ans ? "YES\n" : "NO\n");


    }
}