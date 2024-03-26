#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 1e6+5;

int n, a[MAXN];



int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n;


    stack<pair<int,int>> st;
    st.push({1e9,1});
    

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        while(!st.empty() && st.top().first <= x) st.pop();
        cout << i-st.top().second << " ";
        st.push({x,i});
    }
}