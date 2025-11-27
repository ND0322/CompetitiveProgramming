#include <bits/stcd++.h>
#include <iostream>


using namespace std;


int door[5005], ans[5005], tmp[5005];
bool marked[5005];


void exploreCave(int n){
    int last = -1;
    while(1){

        int lo = 1;
        int hi = n;
        int pos = 0;

        while(lo <= hi){
            int mid = (lo+hi)>>1;


            for(int i = 1; i <= n; i++){
                if(ans[i]) tmp[i] = ans[i] == 1;
                else tmp[i] = 1;
            }

            int res = tryCombination(tmp);

            if(res == -1 || res > last){
                hi = mid-1;
                pos = mid;
            }
            else lo = mid+1;    
        }

        for(int i = 1; i <= pos; i++){
            if(!ans[i]) ans[i] = 1;
        }

        for(int i = 1; i <= n; i++){
            if(ans[i]) tmp[i] = ans[i] == 1;
            else tmp[i] = 1;
        }

        last = tryCombination(tmp);

        door[pos] = last;
        if(last == -1) break;
    }


    
}