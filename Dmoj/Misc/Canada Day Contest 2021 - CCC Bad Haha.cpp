#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        string n; cin >> n;

        n += '0';

        int k; cin >> k;

        stack<char> st;

        vector<char> popped;

        

        for(char c : n){

            while(st.size() && k && st.top() > c){
                popped.push_back(st.top());
                st.pop();
                
                k--;
            }

            st.push(c);
        }

        st.pop();

        string ans;

        sort(popped.rbegin(), popped.rend());

        for(char i:popped) ans += i;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }


        reverse(ans.begin(), ans.end());

        cout << ans << "\n";
    }
}