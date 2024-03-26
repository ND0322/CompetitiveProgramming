#include <bits/stdc++.h>
#include <iostream>
#include <stack>


using namespace std;

const int MAXN = 3e5+5;

int n, a[MAXN];





int main(){
    cin >> n;

    
    for(int i = 1; i <= n; i++) cin >> a[i];

    long long ans = 0;
    stack<int> st;

    for(int i = n; i >= 1; i--){
        while(st.size() && a[st.top()] < a[i]) st.pop();
        if(st.size()) ans += st.top()-i+1;
        st.push(i);
    }

    while(st.size()) st.pop();

    reverse(a+1,a+n+1);

    for(int i = n; i >= 1; i--){
        while(st.size() && a[st.top()] < a[i]) st.pop();
        if(st.size()) ans += st.top()-i+1;
        st.push(i);
    }

    cout << ans << "\n";
    

    

}