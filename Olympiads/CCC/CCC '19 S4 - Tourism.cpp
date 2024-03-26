#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;



int n, k, a[MAXN], pmax[MAXN], smax[MAXN];;

long long dp[MAXN], sdp[MAXN];



//n/k+1 groups
//min element is n%k for all states

//precalculate some stuff to optimize
int main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> a[i];
    

    for(int i = 1; i <= n+5; i++) dp[i] = -1e18;



    int l = 1;
    int r = k;

    while(l <= n){

        r = min(r,n);

        
        pmax[l] = a[l];
        for(int i = l+1; i <= r; i++) pmax[i] = max(pmax[i-1],a[i]);
        for(int i = l; i <= r; i++){
            int j = max(i-k+1, 1);
            dp[i] = max(pmax[i] + dp[j-1], sdp[j-1]);
        }

        //update suffix dp

        sdp[r] = dp[r]; 
        smax[r] = a[r];

        for(int i = r-1; i >=l; i--){
            sdp[i] = max(smax[i+1] + dp[i], sdp[i+1]);
            dp[i] =max(dp[i], dp[i+1]);
            smax[i] = max(smax[i+1], a[i]);
            
        }
        




        l+=k;
        r+=k;
    }

    cout << dp[n] << "\n";

    


}

