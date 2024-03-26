#include <bits/stdc++.h>  
#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 2005;

int n,m;

long long a[MAXN], b[MAXN], psa[MAXN];

long long calc(long long x){
    return x * (x + 1)/2;
}

//min stack plus some math stuffs
int main(){

    cin >> n >> m;

    long long ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c; cin >> c;

            if(c == '.') psa[j]++;
            else psa[j] = 0;
            //psa of the column
        }

        fill(a,a+m+1, m);
        fill(b,b+m+1,-1);

        stack<int> st;

        for(int j = 0; j < m; j++){
            while(!st.empty() && psa[j] <= psa[st.top()]){
                a[st.top()] = j;
                st.pop();
            }
            st.push(j);
        }

        while(!st.empty())st.pop();

        for(int j = m-1; j >= 0; j--){
            while(!st.empty() && psa[j] < psa[st.top()]){
                b[st.top()] = j;
                st.pop();
            }
            st.push(j);
        }

        for(int j = 0; j < m; j++){
            long long fir = (calc(a[j]) - calc(j)) * (j-b[j]);
            long long sec = (calc(j) - calc(b[j])) * (a[j]-j);



            ans += (fir - sec) * (calc(psa[j]));
        }

        
    }

    cout << ans << "\n";
}