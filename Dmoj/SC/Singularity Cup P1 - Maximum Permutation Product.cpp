#include <bits/stdc++.h>
#include <iostream>

using namespace std;



int main(){
    int n; cin >> n;

    if(n == 1){
        cout << "1 1\n";
        return 0;
    }


    

    int ind = 0;
    int ind3 = 0;

    for(int i = 1; i <= n; i++){
        int x; cin >> x;

        if(x == 1) ind = i;
        if(x == 3) ind3 = i;
    }

    if(n == 3){
        if(ind == 2){
            cout << ind3 << " " << ind3 << "\n";
            return 0;
        }
    }


    if(ind == 1){
        cout << "2 " << n << "\n";
    }
    else if(ind == n){
        cout << "1 " << n-1 << "\n";
    }
    else{
        cout << "1 " << n << "\n";
    }
    
}