#include <bits/stdc++.h>
#include <iostream>


using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        string grid[8];

        string ans = "";

        for(int i = 0; i < 8; i++){
            cin >> grid[i];
        }

        for(int i = 0;i < 8; i++){

            bool flag = true;
            for(int j = 0; j < 8; j++){

                


                if(grid[i][j] != '.'){
                    ans += grid[i][j];

                    for(int k = i+1; k < 8; j++){

                        cout << k << " " << j << " " << grid[k][j] << endl;
                        if(grid[k][j] == '.'){
                            break;
                        }
                        ans+= grid[k][j];
                    }

                    flag = false;
                    break;
                }
            }

            if(!flag) break;
        }

        cout << ans << "\n";
       
    }
}