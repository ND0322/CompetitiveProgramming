#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//alternate swaps

char s[105], t[105];

int main(){
    int tt; cin >> tt;

    while(tt--){
        string a,b; cin >> a >> b;

        int n = a.size();

        for(int i = 0; i < n; i++) s[i] = a[i];
        for(int i = 0; i < n; i++) t[i] = b[i];

        bool ts = 1;
        
        for(int i = 0; i < n; i++){
            if(s[i] == t[i]) continue;

            if(ts){
                if(s[i] < t[i]) swap(s[i], t[i]);
                ts = 0;
            }
            else if(s[i] > t[i]) swap(s[i], t[i]);
        }

        for(int i = 0; i < n; i++) cout << s[i];
        cout << "\n";
        for(int i = 0; i < n; i++) cout << t[i];
        cout << "\n";
    }

    

}