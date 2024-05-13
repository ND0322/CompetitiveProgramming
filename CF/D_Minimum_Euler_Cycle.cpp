#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//pattern is for 5 node is 1 2 1 3 1 4 1 5 + 4 node 
//4 node is 1 2 1 3 1 4 + 3 node

//full for 5 is 1 2 1 3 1 4 1 5 | 2 3 2 4 2 5 | 3 4 3 5 | 4 5 | 1
//                      8               6           4      2   

//each seg is (n-i)*2

#define int long long

const int MAXN = 2e5+5;

int n, l, r;

vector<int> ans;

void rec(int i, int cur){
    if(i == n) return;
    if(cur >= r) return;

    for(int j = i+1; j <= n; j++){
        ans.push_back(i);
        ans.push_back(j);
    }

    rec(i+1, cur + (n-i)*2);
}

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> l >> r;

        ans.clear();

        //find starting i
        int start = 0;
        long long cur = 0;
        for(int i = 1; i <= n; i++){
            cur += (n-i)*2;

            if(cur >= l){
                start = i;
                break;
            }
        }

        rec(start, cur - (n-start)*2);
        ans.push_back(1);
        for(int i = l - (cur - (n-start) * 2)-1; i < r-(cur - (n-start) * 2); i++) cout << ans[i] << " ";
        cout << "\n";

    }
}
