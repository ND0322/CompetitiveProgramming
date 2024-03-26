#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
   
    string s; cin >> s;

    int n = s.size();

    vector<int> a;

    a.push_back(-1);

    for(char c:s) a.push_back(c - 'a');

    vector<int> dp(n+2);


    for(int i = n; i >= 0; i--){
        for(int j = i+1; j <= n; j++){
            if(a[j] > a[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }



    cout << 26-dp[0] << "\n";


    
}