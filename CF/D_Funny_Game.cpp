#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 2005;

int n, a[MAXN];

bool vis[MAXN];

vector<int> mod[MAXN];

//process in reverse
//we start from more specific to more broad
//answer is probably always possible

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            vis[i] = 0;
        }
        vector<pair<int,int>> ans;

        for(int i = n-1; i >= 1; i--){
            for(int j = 0; j < i; j++) mod[j].clear();

            for(int j = 1; j <= n; j++){
                if(vis[j]) continue;
                mod[a[j] % i].push_back(j);
            }

            for(int j = 0; j < i; j++){
                if(mod[j].size() > 1){
                    ans.push_back({mod[j][0], mod[j][1]});
                    vis[mod[j][0]] = 1;
                    break;
                }
            }
        }

        cout << "YES\n";
        reverse(ans.begin(), ans.end());

        for(auto [x,y] : ans) cout << x << " " << y << "\n";


    }
}