#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 4e5+5;
int n, k, cur, cnt[MAXN];

//count number of each under mod x

int main(){
    cin >> n >> k;

    cur = 0;
    while(n--){
        int x; cin >> x;

        cnt[x % k]++;

        while(cnt[cur%k]){
            cnt[cur%k]--;
            cur++;
        }

        cout << cur << "\n";
    }
}