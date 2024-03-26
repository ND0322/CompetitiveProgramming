#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int t; cin >> t;

    while(t--){
        int n; cin >> n;


        string ans = "1";
        bool used = false;
        int first; cin >> first;
        int last = first;

        for(int i = 0; i < n-1; i++){
            //cout << last << endl;
            int x; cin >> x;
            if(!used){
                if(x >= last){
                    ans += "1";
                    last = x;
                }
                else{
                    if(x <= first){
                        ans += "1";
                        used = true;
                        last = x;
                    }
                    else{
                        ans += "0";
                    }
                }
            }
            else{
                

                if(x >= last && x <= first){
                    ans += "1";
                    last = x;
                }
                else{
                    ans += "0";
                }
            }
        }

        cout << ans << "\n";


    }
}