#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 25;
const int MOD = 1e9+7;

int n, cnt[4];

pair<int,int> a[MAXN];



int main(){
    cin >> n;

    //bruteforce for subtask

    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    long long ans = 0;

    for(int i = 0; i < (1<<n); i++){
        cnt[1] = cnt[2] = cnt[3] = 0;

        for(int j = 0; j < n; j++){
            if(i & (1<<j)){
                cnt[a[j].first]++;
                cnt[a[j].second]++;
            }
        }

        

        ans = (ans + (cnt[1] > cnt[2] && cnt[1] > cnt[3])) % MOD;
    }

    cout << ans << "\n";


}