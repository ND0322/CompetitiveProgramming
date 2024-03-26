#include <bits/stdc++.h>
#include <iostream>
#include <stack>


using namespace std;

long long ind;
string s;



int main(){
    int tt; cin >> tt;

    while(tt--){

        //monotonic stack
        stack<char> st;
        
        
        cin >> s;
        
        cin >> ind;

        ind--;

        int cnt = s.size();

        s+='_';

        bool flag = ind >= cnt;

        for(char i : s){

            

            
            while(flag && st.size() > 0 && st.top() > i){
                
                ind-=cnt;
                cnt--;
                st.pop();
                
                if(ind < cnt) flag = false;
               

               
            }

            st.push(i);
           
        }

        vector<char> ans;

        while(st.size()){
            ans.push_back(st.top());
            //cout << st.top() << " ";
            st.pop();
            
        }

        reverse(ans.begin(),ans.end());

        //cout << "\n";

        

        //cout << cnt << "\n";


        

        cout << ans[ind];

    }
}

