#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, k, a[MAXN];

/*
focus on either even or odd
bsearch over answer
assume we focus on odd
if even index we skip to next
if odd we find the next element less than x
*/

bool can(int x){
    int i = 1;
    int cnt = 1;
    while(1){
        if(cnt&1){
            while(i <= n){
                if(a[i] <= x) break;
                i++;
            }

            if(i == n+1) return 0;
        }
        
        i++;
        cnt++;

        if(cnt == k+1) return 1;
        if(i > n) return 0;
    }

   
}

bool check(int x){
    int i = 1;
    int cnt = 1;
    while(cnt <= k){
        if(!(cnt&1)){
            while(i <= n){
                if(a[i] <= x) break;
                i++;
            }

            if(i == n+1) return 0;
            
        }
        
        i++;
        cnt++;

        if(cnt == k+1) return 1;
        if(i > n) return 0;
    }
}



int main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> a[i];

    
    
    int lo = 1;
    int hi = 1e9;

    int f = -1;
    while(lo <= hi){
        int mid = (lo+hi)>>1;
        if(can(mid)){
            f = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }

    lo = 1;
    hi = 1e9;

    int s = -1;
    while(lo <= hi){
        int mid = (lo+hi)>>1;
        if(check(mid)){
            s = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    
    cout << min(f,s) << "\n";

    
}