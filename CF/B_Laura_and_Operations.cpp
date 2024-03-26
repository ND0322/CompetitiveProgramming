#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int vals[3];
int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> vals[0] >> vals[1] >> vals[2];

        if(vals[1] == vals[2]) cout << "1 ";
        else if(vals[1]%2 == vals[2]%2 && vals[0] >= max(vals[1],vals[2]) - (vals[1]+vals[2])/2) cout << "1 ";
        else cout << "0 ";

        if(vals[0] == vals[2]) cout << "1 ";
        else if(vals[0]%2 == vals[2]%2 && vals[1] >= max(vals[0],vals[2]) - (vals[0]+vals[2])/2) cout << "1 ";
        else cout << "0 ";
        

        if(vals[0] == vals[1]) cout << "1 ";
        else if(vals[0]%2 == vals[1]%2 && vals[2] >= max(vals[0],vals[1]) - (vals[0]+vals[1])/2) cout << "1 ";
        else cout << "0 ";

        cout << "\n";

        
    }
}