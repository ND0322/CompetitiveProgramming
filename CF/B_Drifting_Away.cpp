#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
assume no ><
or *< and >* and ** 

each path will form some continous chain to the end points 
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        string t; cin >> t;

        int n = t.size();

        t = "." + t;

        bool flag = 1;

        for(int i = 1; i < n; i++){
            if(t[i] == '>' && t[i+1] == '<') flag = 0;
            if(t[i] == '>' && t[i+1] == '*') flag = 0;
            if(t[i] == '*' && t[i+1] == '<') flag = 0;
            if(t[i] == '*' && t[i+1] == '*') flag = 0;
        }

        if(!flag){
            cout << "-1\n";
            continue;
        }

        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(t[i] == '>') break;
            cnt++;
        }

        int cntb = 0;

        for(int i = n; i >= 1; i--){
            if(t[i] == '<') break;
            cntb++;
        }

        cout << max(cnt, cntb) << "\n";
    }
}