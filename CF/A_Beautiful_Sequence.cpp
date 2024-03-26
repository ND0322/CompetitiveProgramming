#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    //approach: for each element, see if there are at least ai - 1 elements behind it. eg. if ai = 2, check if index is at least 1
    int t; cin >> t;

    while(t--){
        int n; cin >> n;



        bool ans = false;

        for(int i = 0; i < n; i++){
            int x; cin >> x;
            if(i >= x-1){
                ans = true;
            }
        }

        cout << (ans ? "YES":"NO") << "\n";
    }
}