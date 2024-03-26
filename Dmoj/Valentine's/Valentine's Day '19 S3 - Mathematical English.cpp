#include <bits/stdc++.h>
#include <iostream>




using namespace std;

const int MAXN = 1e5+5;

int n, m;

long long sol = 1e14, psa[MAXN], a[MAXN], b[50];

//add binary search in the greedy

bool can(long long x){
    int l = 0;

    for(int i = 1; i <= m; i++){

        int lo = l;
        int hi = n;
        int ans = -1;

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(psa[n]/x < b[i]) return 1;


            
            
            if(psa[mid] - psa[l] <= x*b[i]){

                if(mid == n) return 1;
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }

        if(ans <= l) return 0;
        l = ans;

        
    }

    return l == n;
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        psa[i]+=a[i];
        psa[i] += psa[i-1];
    }

    for(int i = 1; i <= m; i++) cin >> b[i];


    sort(b+1,b+m+1);

   

    
    do { 
        long long lo = 1;
        long long hi = 1e14+5;
        long long ans = 1e14+5;

        while(lo <= hi){
            long long mid = (lo+hi)>>1;

            if(can(mid)){
                ans = mid;
                hi = mid-1;
            } 
            else lo = mid+1;
        }

        sol = min(sol, ans);
    }
    while (next_permutation(b+1, b + m+1)); 
    

    cout << sol << "\n";
    
    
    

    
   
    
    
}

