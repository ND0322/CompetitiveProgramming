#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){

    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<bool> a(n+1);

        int cnt = 0;

        for(int i = 1;i <= n; i++){
            char c; cin >> c;

            a[i] = (c == '1');
            cnt += !a[i];
        }

        if(is_sorted(a.begin(), a.end())){
            cout << "Bob\n";
            continue;
        }

        vector<bool> b = a;


        sort(b.begin(), b.end());

        
        vector<int> ans;

        for(int i = 1; i <= n; i++){
            if(i <= cnt && a[i]) ans.push_back(i);
            if(i > cnt && !a[i]) ans.push_back(i);
        }

        cout << "Alice\n";
        cout << ans.size() << "\n";

        for(int i : ans) cout << i << " ";
        cout << "\n";





    }
}