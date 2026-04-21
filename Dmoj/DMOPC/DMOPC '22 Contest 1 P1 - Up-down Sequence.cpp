#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);
        vector<bool> up(n+1);
        for(int i = 1; i <= n; i++) cin >> a[i];

        for(int i = 2; i < n; i++){
            if(a[i] && a[i-1] && a[i+1]){
                bool st = 1;
                if(a[i] > a[i-1] && a[i] < a[i+1]) st = 0;

                for(int j = i; j < n; j++){
                    up[j] = st;
                    st ^= 1;
                }

                st = 1;
                if(a[i] > a[i-1] && a[i] < a[i+1]) st = 0;

                for(int j = i; j >= 2; j--){
                    up[j] = st;
                    st ^= 1;
                }
            
                break;
            }
        }


        for(int i = 2; i < n; i++){
            if(a[i] && a[i-1] && a[i+1]){
                if(a[i] > a[i+1] && a[i] > a[i-1] && !up[i]){
                    flag = 0;
                    break;
                }

                if(a[i] < a[i+1] && a[i] < a[i+1] && up[i]){
                    flag = 0;
                    break;
                }

                continue;
            }
        }

        if(!flag){
            cout << "NO\n";
            continue;
        }

        /*
        casework

        one 0 ->
        two 0 ->
        three 0 -> 
        */
    }
}