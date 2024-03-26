#include <bits/stdc++.h>
#include <iostream>

using namespace std;



int n,m,k, dif[30005][1005];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    cin >> m >> n >> k;

    for(int i = 0; i < k; i++){
        int x,y,r,b; cin >> y >> x >> r >> b;


        //we can find y for each x covered by circle
        for(int j = max(1,x-r); j <= min(m,x+r); j++){
            double circ = pow(r*r - (j-x)*(j-x),.5);
            dif[j][max(1,(int)ceil(y - circ))] += b;
            dif[j][min(n, (int)floor(y + circ))+1] -= b;

            
        }

        
    }


    
    int ans = -1;
    int cnt = 0;
   

    for(int i = 1; i <= m; i++){
        int sum = 0;

        for(int j = 1; j <= n; j++){
            sum += dif[i][j];

            if(sum == ans) cnt++;

            if(sum > ans){
                ans = sum;
                cnt = 1;
            }
            
            
        }
    }

    cout << ans << "\n";
    cout << cnt << "\n";
    
    

   


}