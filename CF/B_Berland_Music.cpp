#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n);
        vector<int> ans(n);

        vector<pair<int,int>> l,r;

        for(int i = 0; i <n ; i++) cin >> a[i];
        string s; cin >> s;
        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '0') l.push_back({a[i], i});
            else{
                r.push_back({a[i], i});
                cnt++;
            }
        }


        //2 1

        sort(a.rbegin(), a.rend());
        sort(r.rbegin(), r.rend());

        for(int i = 0; i < cnt; i++){
            ans[r[i].second] = a[i];
        }

        sort(l.rbegin(), l.rend());

        for(int i = cnt; i < n; i++){
            ans[l[i-cnt].second] = a[i];
        }

        for(int i : ans) cout << i << " ";
        cout << "\n";

        
    }
}