#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 1005;

int n, m, dp[MAXN][5];

vector<char> alph = {'n', 'a', 'r', 'e', 'k'};

string a[MAXN];

int main(){
    int tt; cin >> tt;
    while(tt--){
        cin >> n >> m;

        for(int i = 1; i <= n; i++){
            a[i] = '.';

            string s; cin >> s;
            a[i] += s;
        }

        for(int i = 0; i < 5; i++) dp[n+1][i] = 0;
        for(int i = n; i >= 1; i--){
            for(int j = 0; j < 5; j++){
                dp[i][j] = dp[i+1][j];

                int cur = j;
                int res = 0;
                for(int k = 1; k <= m; k++){
                    if(a[i][k] == alph[cur]){
                        cur++;
                        if(cur == 5){
                            cur = 0;
                            res += 10;
                        }
                    }

                    if(find(alph.begin(), alph.end(), a[i][k]) != alph.end()) res--;

                }

                dp[i][j] = max(dp[i][j], res + dp[i+1][cur]);
            }
        }

        cout << dp[1][0] << "\n";


    }
}