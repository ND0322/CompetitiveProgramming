#include <bits/stdc++.h>
#include <iostream>

using namespace std;


/*
start with all 2s

1111111

2211111

3 

*/

int main(){
    int k; cin >> k;

    for(int n = 1; n <= 100; n++){
        vector<int> ans(n+1, 1);

        int diff = (n * (n+1)) / 2 - k;



        int i = 1;
        while(i <= n && diff > 0){

            int sz = 0;
            for(int j = 1; j <= n; j++){
                if(2 * diff >= j * (j+1)) sz = j;
            }

            if(i + sz > n) break;


            for(int j = i; j < i +sz; j++) ans[j] = 2; 
            diff -= (sz * (sz+1)) / 2;
            i += sz;
        }

        for(int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << "\n";
        

    }


    





}