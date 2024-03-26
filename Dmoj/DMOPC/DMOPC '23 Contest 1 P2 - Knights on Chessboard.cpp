#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool grid[2005][2005];

int main(){
    int n; cin >> n;

    int cnt = 0;
   
    for(int i = 2; i < n; i+=5){
        for(int j = 0; j < n; j++){
            grid[i][j] = 1;
            cnt++;
        }
    }

    if(n == 11){
        for(int i = 2; i < n-2; i++) grid[n-2][i] = 1;
    }

    else if((n-11)%5 == 0){
        for(int i = 0; i < n-1; i += 3){
            grid[n-2][i] = 1;
            cnt++;
        }
        for(int i = 2; i < n-2; i+=3){
            grid[n-2][i] = 1;
            cnt++;
        }
        
       
        for(int i = 0; i < n; i++){
            if(i == 0 || i == 1){
                if(!grid[n-2][i+2]){
                    grid[n-2][i+2] = 1;
                    cnt++;
                }

                continue;
            }
            if(i == n-1 || i == n-2){
                if(!grid[n-2][i-2]){
                    grid[n-2][i-2] = 1;
                    cnt++;
                }
                continue;
            }

            if(!grid[n-2][i-2] && !grid[n-2][i+2]){
                grid[n-2][i-2] = 1;
                cnt++;
            }


           

            
        }


    }
    

    if((n-12) % 5 == 0){
        for(int i = 0; i < n; i++) grid[n-1][i] = 1;
    }

    
   
    if(cnt > ((n*n) + 3 * n)/(5)){
        cout << "-1\n";
        return 0;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cout << grid[i][j] << " ";
        cout << "\n";
    }

    

}