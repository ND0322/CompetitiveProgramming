#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1005;

int n,k;

string a[MAXN];

int main(){
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }



    int ans = 0;
    for(int i = 0; i < (1<<k); i++){
        int res = 1e9;

        for(int j = 0; j < n; j++){
            int cnt = 0;
            for(int l = 0; l < k; l++){
                cnt += ((bool)(i & (1<<l)) == (a[j][l] == 'T'));
                //if(i == 21 && j == 0) cout << (i & (1<<l)) << " " << a[j][l] << "\n";
            }
            res = min(res,cnt);
        }

        

        ans = max(ans,res);

    }

    cout << ans << "\n";
}