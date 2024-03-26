#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int a[32], tmp[32];

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    int q; cin >> q;
   

    while(q--){
        int t; cin >> t;

        if(t==1){
            int x; cin >> x;

            a[x]++;
        }
        else{
            int x; cin >> x;
            
            for(int i = 0; i <= 30; i++) tmp[i] = a[i];

            bool flag = 1;
            for(int i = 0; i <= 30; i++){
                if((x & (1<<i)) && !tmp[i]){
                    cout << "NO\n";
                    flag = 0;
                    break;
                }

                if(x & (1<<i)) tmp[i+1] += (tmp[i]-1)/2;
                else tmp[i+1] += tmp[i]/2;
                
            }

            


            if(flag) cout << "YES\n";
        }

       
    }



}