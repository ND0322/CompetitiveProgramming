#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 1e6+5;

int n, a[MAXN];

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    stack<int> st;

    st.push(1e9);
    st.push(a[1]);
    a[n+1] = 1e9;
    long long ans = 0;

    for(int i = 2; i <= n+1; i++){
        while(st.size() && st.top() <= a[i]){
            int x = st.top();

            st.pop();
            ans += max(x, min(st.top))
        }  
    }

    
}