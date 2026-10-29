#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n,m; cin >> n >> m;

    string s; cin >> s;
    s = "." + s;

    
    while(m--){
        int l,r; cin >> l >> r;
        char c1, c2; cin >> c1 >> c2;

        string t = "";

        for(int i = l; i <= r; i++){
            if(s[i] == c1) t += c2; 
            else t += s[i];
        }

        s = "." + t;
        
    }

    cout << s << "\n";
    
}