#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 55;

int n, m, sick[MAXN];

bool drank[MAXN][MAXN];
vector<pair<int,int>> milk[MAXN];
int main(){
    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);
    cin >> n >> m;

    int d,s; cin >> d >> s;

    while(d--){
        int p,b,t; cin >> p >> b >> t;

        milk[p].push_back({b,t});

    }

    while(s--){
        int p,t; cin >> p >> t;

        sick[p] = t;
    }

    for(int i = 1; i <= n; i++){
        for(pair<int,int> p : milk[i]){
            if(p.second < sick[i]){
                drank[i][p.first] = 1;
                //cout << i << " " << p.first << "\n";
            }
        }
    }

    int ans = 0;

    for(int i = 1; i <= m; i++){
        bool flag = 1;
        for(int j = 1; j <= n; j++){

            if(!sick[j]) continue;
            //not the bad milk
            if(!drank[j][i]){
                flag = 0;
                break;
            }
        }

        if(!flag) continue;

        int cnt = 0;
        for(int j = 1; j <= n; j++){
            for(pair<int,int> p : milk[j]){
                if(p.first == i){
                    cnt++;
                    break;
                }
            }
        }

        ans = max(ans,cnt);
    }

    cout << ans << "\n";


}