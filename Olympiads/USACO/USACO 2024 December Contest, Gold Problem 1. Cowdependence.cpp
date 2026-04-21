#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n, a[MAXN], ans[MAXN];

set<int> pos[MAXN];


int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pos[a[i]].insert(i);
    }

    /*
    for each thing store positions and do it in n / x^n 
    n log n
    binary search for next one 
    */

    
    for(int i = 1; i <= n; i++){
        if(!pos[i].size()) continue;

        
        for(int x = 1; x <= pos[i].size(); x++){

                int j = -n;
                int cnt = 0;

                while(1){
                    if(pos[i].lower_bound(j+x+1) == pos[i].end()) break;
                    j = *pos[i].lower_bound(j + x+1);
                    cnt++;
                }

                ans[x] += cnt;
            }
        } 









            

            
  

    for(int i = 1; i <= n; i++) cout << ans[i] << "\n";

}