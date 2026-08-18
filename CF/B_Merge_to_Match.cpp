#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, m; cin >> n >> m;

        vector<int> a(n+1);
        vector<int> b(m+1);

        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= m; i++) cin >> b[i];

        if(n < 2 * m){
            cout << "NO\n";
            continue;
        }

        vector<pair<int,int>> c = {{0,0}};

        for(int i = 1; i <= n; i++) c.push_back({a[i], 0});
        for(int i = 1; i <= m; i++) c.push_back({b[i], 1});

        sort(c.begin(), c.end());

        int c1 = 0;
        bool flag = 1;

        for(int i = 1; i <= n + m; i++){
            if(c[i].second){
                if(!c1){
                    flag = 0;
                    break;
                }
                c1--;
            }
            else c1++;
        }

        c1 = 0;

        for(int i = n + m; i >= 1; i--){
            if(c[i].second){
                if(!c1){
                    flag = 0;
                    break;
                }

                c1--;
            }
            else c1++;
        }

        

        cout << (flag ? "YES\n" : "NO\n");
    }
}


/*

*/