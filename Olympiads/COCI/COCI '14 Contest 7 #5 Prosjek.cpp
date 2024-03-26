#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3e5+5;

int n, k;

double a[MAXN], b[MAXN], mx[MAXN];


/*
binary search + sliding window
subtracting x from all reduces all averages
*/

bool check(int x){
    for(int i = 1; i <= n; i++) b[i] = a[i] - x/1000.0;

    mx[1] = b[1];
    double cur = b[1]; 

    for(int i = 2; i <= n; i++){
        cur = max(b[i], cur + b[i]);
        mx[i] = cur;
    }

    double sum = 0;

    for(int i = 1; i <= k; i++) sum += b[i];
    double ans = sum;

    for(int i = k+1; i <= n; i++){
        sum += b[i] - b[i-k];
        ans = max(ans,sum);
        ans = max(ans, sum + mx[i-k]);
    }

    return ans >= 0;
}

int main(){
    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> a[i];

    int ans = -1;
    int lo = 1;
    int hi = 1e9;

    
    while(lo <= hi){
        int mid = (lo+hi)/2;

    
        if(check(mid)){
            lo = mid+1;
            ans = mid;
        }
        else hi = mid-1;
    }
    
    
    
    
    
    cout << setprecision(4) << fixed << ans/1000.0 << "\n";

}