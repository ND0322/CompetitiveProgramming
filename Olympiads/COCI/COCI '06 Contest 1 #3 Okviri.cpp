#include <bits/stdc++.h>
#include <iostream>

using namespace std;

char ans[10][105];

int main(){
    string s; cin >> s;

    memset(ans, '.', sizeof(ans));

    for(int i = 0; i < s.size(); i++){
        ans[2][4*i+2] = s[i];

        ans[0][4*i+2] = '#';
        ans[1][4*i+1] = '#';
        ans[1][4*i+3] = '#';
        ans[2][4*i] = '#';
        ans[2][4*i+4] = '#';
        ans[3][4*i+3] = '#';
        ans[3][4*i+1] = '#';
        ans[4][4*i+2] = '#';
    }

    for(int i = 2; i < s.size(); i+=3){
        ans[0][4*i+2] = '*';
        ans[1][4*i+1] = '*';
        ans[1][4*i+3] = '*';
        ans[2][4*i] = '*';
        ans[2][4*i+4] = '*';
        ans[3][4*i+3] = '*';
        ans[3][4*i+1] = '*';
        ans[4][4*i+2] = '*';
    }

    for(int j = 0; j < 5; j++){
        for(int i = 0; i <= s.size() * 4; i++) cout << ans[j][i];
        cout << "\n";
    }

    

    
}