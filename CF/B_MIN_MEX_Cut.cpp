#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//upperbound is 2 
//check if we can do it in 0 or 1 greedily
int main(){
    int tt; cin >> tt;

    while(tt--){
        string s; cin >> s;

        int i = 0; 

        int cnt = 0;
        while(i < s.size()){
            char init = s[i];

            while(i < s.size() && s[i] == init) i++;

            cnt += (init == '0'); 
        }

        cout << min(cnt, 2) << "\n";
    }
}