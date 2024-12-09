#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int query(string s){
    cout <<"1 " << s << "\n";
    cout.flush();
    int x; cin >> x;

    return x;
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >>n;

        int a = query("1");
        int b = query("11");
        int c = query("10");

        if(a == b + c) cout << "0 " << n << " 0\n";
        else cout << "0 " << n << " 1\n";

        cout.flush();

        int res; cin >> res;

        if(res == 1) continue;
        else break;
        
    }

    


}