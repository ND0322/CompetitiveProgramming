#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 1e5+5;

//for each square find the max power its hit with

//infinite is possible if we keep jumping between two power 0


int n,s, a[MAXN], last[MAXN], cnt[MAXN];

bool t[MAXN], used[MAXN];

int32_t main(){
    cin >> n >> s;

    for(int i = 1; i <= n; i++) cin >> t[i] >> a[i];

    int pos = s;
    int pow = 1;
    int dir = 1;
    int ans = 0;

    while(pos >= 1 && pos <= n){
        cnt[pos]++;

        if(cnt[pos] >= 100) break;
        if(t[pos]){
            if(!used[pos] && pow >= a[pos]){
                ans++;
                used[pos] = 1;
            }
        }
        else{
            pow += a[pos];
            dir = -dir;
        }

        pos += pow * dir;
    }

    cout << ans << "\n";

    


}