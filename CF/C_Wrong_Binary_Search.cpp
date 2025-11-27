#include <bits/stdc++.h>
#include <iostream>

//p[i] must equal i
//all things on the left must be smaller and all things on the right must be bigger 

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        string s; cin >> s;

        s = '.' + s;


        vector<int> ans(n+1);

        set<int, greater<int>> se;

        int last = 0;

        for(int i = 1; i <= n; i++){
            if(s[i] == '1'){
                for(int j = last+1; j < i; j++){
                    ans[j] = *se.begin();
                    se.erase(se.begin());
                }
                ans[i] = i;
                last = i;
            }
            else se.insert(i);
        }

        for(int j = last+1; j <= n; j++){
            ans[j] = *se.begin();
            se.erase(se.begin());
        }


        set<int> l, r;

        l.insert(0);
        r.insert(n+1);

        for(int i = 1; i <= n; i++) r.insert(i);

        bool flag = 1;
        for(int i = 1; i <= n; i++){
            r.erase(ans[i]);
            if(s[i] == '1')flag &= (*l.rbegin() < ans[i] && *r.begin() > ans[i]);
            else flag &= !(*l.rbegin() < ans[i] && *r.begin() > ans[i]);

            l.insert(ans[i]);
            
            
        }

        if(!flag){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        for(int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << "\n";
            
    



    }
}