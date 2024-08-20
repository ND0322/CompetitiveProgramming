#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3005;

int n,m, s,f,l, r, col[MAXN], ans[MAXN][MAXN];


int main(){
    cin >> n >> m >> s >> f >> l >> r;

    if(r == 0){
        if(s != f){
            cout << "-1\n";
            return 0;
        }

        cout << "0\n";
        for(int i = 1;  i<= n; i++){
            for(int j = 1; j <= m; j++){
                cout << "0";
                if(j < m) cout << " ";
            }
            cout << "\n";
        }
        return 0;
    }

    int ind = 0 - (s != f);

    for(int i = 1; i <= m; i++){
        cin >> col[i];
        if(col[i] == f) ind = i;
    }

    if(ind == -1){
        cout << "-1\n";
        return 0;
    }

    if(ind * n + (m-ind) * (n-1) < l){
        cout << "-1\n";
        return 0;
    }


   
    cout << max(1,l) << "\n";
    int cnt = l-(bool)ind;
    for(int j = 1; j <= ind; j++){
        for(int i = 1; i <= n; i++){
            if(cnt <= 0) break;
            if(!(j == ind && i == s))cnt--;
            ans[i][j] = 1;
            if(j != ind) s = col[j];
        }
    }

    if(!ans[s][ind]) ans[s][ind] = 1;

    s = f;

    if(cnt > 0){
        for(int j = ind+1; j <= m; j++){
            for(int i = 1; i <= n; i++){
                if(i == s) continue;
                if(cnt <= 0) break;
                cnt--;
                ans[i][j] = 1;
            }
        }
    }

    for(int i = 1; i<= n; i++){
            for(int j = 1; j <= m; j++){
                cout << ans[i][j];
                if(j < m) cout << " ";
            }
            cout << "\n";
        }


}