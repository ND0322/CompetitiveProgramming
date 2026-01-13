#include <bits/stdc++.h>
#include <iostream>


using namespace std;

/*
if all 1s -> a wins
if starts/ends with 1 -> a wins
0 1 1 0 0


*/

int main(){
    int tt; cin >> tt;
    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];

        if(a[1] == 1 || a[n] == 1) cout << "Alice\n";
        else cout << "Bob\n";
    
    }
}