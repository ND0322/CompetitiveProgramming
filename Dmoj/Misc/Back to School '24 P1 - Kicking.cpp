#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 5e5+5;


int main(){
    int n, m, k; cin >> n >> m >> k;

    vector<vector<char>> ans(n+1, vector<char>(m+1));

    for(int i = 1; i <= n; i++){
        set<int> a, b;
        string s; cin >> s;
        s = '.' + s;
        for(int j = 1; j <= m; j++){

            if(s[j] == 'A') a.insert(j);
            if(s[j] == 'B') b.insert(j);
        }

        for(int j = 1; j <= m; j++){
            if(s[j] == '.'){
                ans[i][j] = '.';
                continue;
            }

            if(s[j] == 'A'){
                if(b.lower_bound(j) == b.end()){
                    ans[i][j] = 'Y';
                    continue;
                }

                if(*b.lower_bound(j) > j + k) ans[i][j] = 'Y';
                else ans[i][j] = 'N';
            }

            if(s[j] == 'B'){
                if(a.lower_bound(j) == a.begin()){
                    ans[i][j] = 'Y';
                    continue;
                }

                auto it = a.lower_bound(j);
                it--;

                if(*it < j - k) ans[i][j] = 'Y';
                else ans[i][j] = 'N';
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cout << ans[i][j];
        cout << "\n";
    }
}