#include <bits/stdc++.h>
#include <iostream>



using namespace std;

const int MAXN = 1e5+5;

int n, m, a[MAXN], b[50];



long long sol = 1e18, psa[MAXN];

//add binary search in the greedy

bool can(long long x){
    int l = 1;
    int r = 1;

    for(int i = 1; i <= m; i++){
        r = l;    
        while(r <= n && x*b[i] >= psa[r] - psa[l-1]) r++;        
        l = r;

        if(x == 2) cout << l << " ";
    }

    if(x ==2) cout << "\n";
    return (r == n+1);
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
        long long lo = 0;
        long long hi = 1e14+5;
        long long ans = 1e14+5;

         cout << can(2) << "\n";

        while(lo <= hi){
            int mid = (lo+hi)>>1;

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