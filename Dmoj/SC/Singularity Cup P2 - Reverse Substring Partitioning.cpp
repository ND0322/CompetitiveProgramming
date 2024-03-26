#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;

    string s; cin >> s;

    if(n == 1){
        cout << "1\n";
        return 0;
    }

    if(s[0] != s[n-1]){
        cout << n << "\n";
        return 0;
    }

    //2

    //aaccada

    //caadac
    //acada
    //cada

    int ans = 1;

    for(int i = 0; i < n-1; i++) if(s[i] == s[i+1]) ans++;

    
    if(ans == n){
        cout << "1\n";
    }
    else cout << n-ans << "\n";



   
    //accacda
    //cadcac
    //dacac
    

    

    

    
}