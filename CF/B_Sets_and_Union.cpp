#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;
        vector<int> arr;
        set<int> s[n], st;
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            int sz;
            cin >> sz;
            int temp2 = 0;
            for (int j = 0; j < sz; j++)
            {
                int x;
                cin >> x;
                temp |= x;
                temp2 |= x;
                s[i].insert(x);
                st.insert(x);
            }
            arr.push_back(temp2);
        }
        long long ans = 0;
        for (auto &x : st)
        {
            set<int> temp;
            for (int i = 0; i < n; i++)
            {
                if (s[i].find(x) == s[i].end())
                {
                    for (auto &x : s[i])
                    {
                        temp.insert(x);
                    }
                }
            }
            ans = max(ans, (long long)temp.size());
        }
        cout << ans << endl;
    }
}