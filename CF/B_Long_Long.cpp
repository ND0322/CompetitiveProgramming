#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;
        

        vector<int> arr(n);

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        vector<vector<int>> groups = vector<vector<int>>();

        int i = 0;

        while(i < n){

            if(arr[i] <= 0){
                vector<int> e = vector<int>();
                for(int j = i; j < n; j++){
                    if(arr[j] <= 0){
                        e.push_back(arr[j]);
                    }
                    else{
                        i = j+1;
                        break;
                    }
                }

                groups.push_back(e);
            }
            else{
                i++;
            }
            
            
        }

        int ans = 0;

        for(vector<int> i: groups){
            for(int j:i){
                if(j < 0){
                    ans++;
                    break;
                }
            }
        }

        cout << ans << "\n";


       
    }
}