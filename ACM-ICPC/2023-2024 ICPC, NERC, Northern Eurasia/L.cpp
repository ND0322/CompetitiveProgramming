#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;

    string s; cin >> s;

    int sufa = 0,sufb = 0;

    for(int i = 0; i < n ; i++){
        if(s[i] == 'L') sufa++;
        else sufb++;
    }

    int prefa, prefb;

    prefa = prefb = 0;

    for(int i = 0; i < n-1; i++){
        if(s[i] == 'L'){
            prefa++;
            sufa--;
        }
        else{
            prefb++;
            sufb--;
        }

        if(sufa != prefa && prefb != sufb){
            cout << i+1 << "\n";
            return 0;
        }
    }

    cout << "-1\n";
}