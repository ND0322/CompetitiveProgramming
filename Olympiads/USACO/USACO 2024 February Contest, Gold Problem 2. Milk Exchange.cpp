#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long



const int MAXN = 5e5+5;

int n, a[MAXN], ans[MAXN];

vector<int> st;

int32_t main(){
    cin >> n;

    long long sum = 0;

    pair<int,int> mn = {1e9, 1e9};
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mn = min(mn, {a[i], i});
        sum += a[i];
    }

    rotate(a+1, a+mn.second, a+n+1);
    reverse(a+1, a+n+1);

 
    


    for(int i = n; i>=1; i--){
        while(st.size() && a[st.back()] >= a[i]) st.pop_back();            
        st.push_back(i);
        for(int j = 1; j < st.size(); j++){
            ans[st[j-1] - i] -= (a[st[j-1]] - a[st[j]]);
        }
    }


   
    for(int i = 1; i <= n; i++){
        sum -= ans[i];
        cout << sum << "\n";
    }


}