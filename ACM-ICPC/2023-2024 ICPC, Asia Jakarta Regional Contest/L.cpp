#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int main(){
    int n, k; cin >> n >> k;

    //6 4
    //((()))
    //()(())

    if(k < n/2 || k == n){
        cout << "-1\n";
        return 0;
    }

    int expairs = (k-n/2);

    //cout << expairs << "\n";
    string ans = "";

    for(int i = 0; i < expairs/2; i++) ans += "()";
    for(int i = 0; i < (n-expairs*2)/2; i++) ans += "(";
    for(int i = 0; i < (n-expairs*2)/2; i++) ans += ")";
    for(int i = 0; i < expairs - expairs/2; i++) ans += "()";

    cout << ans << "\n";
}