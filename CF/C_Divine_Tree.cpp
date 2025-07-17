#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

#define int long long

/*

greedy

lets say we root at the largest such that rt + n - 1 <= m

2 * (n-1) vs n + n-1

that can be compensated by adding an extra
*/


int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n,m; cin >> n >> m;


        int rt = -1;
        int cnt = 0;
        stack<int> st;
        for(int i = n; i >= 1; i--){
            if(i + n -1 <= m){
                rt = i;
                break;
            }
            st.push(i);
            cnt++;
        }

        if(rt == -1){
            cout << "-1\n";
            continue;
        }


        n--;
        int prev = rt;

        vector<pair<int,int>> ans;


        for(int i = rt; i >= 1; i--){

            //place 0
            if(i + i - 1 + cnt > m){
                cnt++;
                st.push(i);
                continue;
            }
            
            //place between 1 and hwoever many
            int k = 1;
            for(int j = 1; j <= cnt; j++){
                if(i * (j+1) + (cnt - j) + i-1> m) break;
                k = j+1;
            }

            if(i != rt) ans.push_back({prev, i});
            prev = i;
            

            m -= i * k;
            cnt -= k-1;

            for(int j = 0; j < k-1; j++){
                ans.push_back({i, st.top()});
                st.pop();
            }

            
        }

        if(cnt != 0 || m != 0){
            cout << "-1\n";
            continue;
        }

        cout << rt << "\n";

        for(auto [x,y] : ans) cout << x << " " << y << "\n";


    }
}