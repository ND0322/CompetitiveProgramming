#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

#define int long long 

//unwrap both arrays into the unmerged stuff
//basically split as much as we can which will be at max logm(ai) times
//if the resulting arrays dont match theres nothing we can do
//in the resuling stuff we can merge all subbarrays and check equality for time complexity

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        int n,m; cin >> n >> m;

        stack<pair<int,int>> st;

        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            long long cnt = 1;
            while(!(x%m)){
                cnt *= m;
                x /= m;
            }

            if(st.size()){
                if(st.top().first != x){
                    st.push({x,cnt});
                    continue;
                }
                st.top().second += cnt;
            }
            else st.push({x,cnt});

        }

        vector<pair<int,int>> a;

        while(st.size()){
            a.push_back(st.top());
            st.pop();
        }

        cin >> n;
        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            long long cnt = 1;
            while(!(x%m)){
                cnt *= m;
                x /= m;
            }

            if(st.size()){
                if(st.top().first != x){
                    st.push({x,cnt});
                    continue;
                }
                st.top().second += cnt;
            }
            else st.push({x,cnt});
        }

        vector<pair<int,int>> b;

        while(st.size()){
            b.push_back(st.top());
            st.pop();
        }

        if(a.size() != b.size()){
            cout << "NO\n";
            continue;
        }

        bool flag = 1;
        for(int i = 0; i < a.size(); i++) flag &= (a[i].first == b[i].first && a[i].second == b[i].second);
        cout << (flag ? "YES\n" : "NO\n");


    }
}