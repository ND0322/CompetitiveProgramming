#include <bits/stdc++.h>
#include <iostream>
#include <stack>


#define int long long

using namespace std;

const int MAXN = 3e5+5;


int n, a[MAXN], b[MAXN];

/*
we can merge two of the same thing if everything in between gets deleted first
build it greedily over the prefix
when adding a new element it will either merge with the previous thing or not 
probably a monostack?
if it merges we sum the two then take max and for no merge we simply take the max of old max and bi
seg tree query max over the distance between the last occurence of this character
update the seg tee at position of left endpoint with new value
*/

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];

        stack<pair<int,int>> st;

        int ans = 0;

        for(int i = 1; i <= n; i++){
            int mx = 0;
            while(st.size()){
                if(st.top().first == b[i]){
                    //merge
                    //cout << i << " " << a[i] << " " << st.top().first << " " << st.top().second << " " << mx << "\n"; 
                    a[i] += st.top().second - mx;
                    st.pop();
                    continue;
                }

                if(st.top().second > a[i]) break;
                mx = max(st.top().second, mx);
                st.pop();
            }
            st.push({b[i], a[i]});
            ans = max(ans, a[i]);
            cout << ans << " ";
        }
        cout << "\n";


        
        

    }
}