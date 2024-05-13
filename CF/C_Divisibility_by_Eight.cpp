#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//dont know if the dumb way works
//subsequence of length 3
//this way is n^3 i think

int n;

string ans, num;

void dfs(int i, string s, int cnt){
    if(i > n) return;
    if(cnt && stoi(s) % 8 == 0) ans = s;
    if(cnt == 3) return;
    

    for(int j = i; j < n; j++) dfs(j+1, s + num[j], cnt+1);
}

int main(){
    cin >> num;

    n = num.size();

    dfs(0,"",0);

    if(ans.size()){
        cout << "YES\n";
        cout << ans << "\n";
    }
    else cout << "NO\n";
}