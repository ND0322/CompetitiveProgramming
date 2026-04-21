#include <bits/stdc++.h>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long


const int MAXN = 1e6+5;
const int MOD = 1e9+7;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ost;

ost s;

int n, a[MAXN], k, cnt[MAXN], suf[MAXN], suf2[MAXN];

bool coach[MAXN];


int fastpow(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1) res = (res * a) % MOD;
        b >>=1;
        a = (a*a) % MOD; 
    }

    return res % MOD; 
}



/*
maybe dp
let dp be answer if i is the last taken coach

two cases
ai + d >= aj, where j is the next transition
ai + d < aj

case 2 we can just take the count at i
case 1 we have to subtract the intersection 

mistakes
did suffix array wrong way
bounds of l
pbounded is already powers of 2

*/


int32_t main(){
    cin >> n >> k;

    vector<int> b = {0};
    vector<int> bounded = {0};
    int last = 0;

    for(int i = 1; i <= n; i++){
        cin >> a[i] >> coach[i];
        
        if(!coach[i]){
            s.insert(a[i]);
            if(a[last] + k < a[i]) continue;
            bounded.back()++;

        }
        else{
        	last = i;
            b.push_back(a[i]);
            bounded.push_back(0);
        }
    }


    int m = b.size()-1;

    for(int i = 1; i <= m; i++){
        while(s.size() && s.order_of_key(b[i])){
        	s.erase(s.begin());
        }
        cnt[i] = s.order_of_key(b[i] + k+1);
    }
    
    b.push_back(2e9);

    vector<int> dp(m+2, 0);
    vector<int> pbounded(m+2, 0);
    

	pbounded[0] = 1;
    for(int i = 1; i <= m; i++) pbounded[i] = (pbounded[i-1] * fastpow(2, bounded[i])) % MOD;
    
    dp[m+1] = 1;
    suf[m+1] = 1;
    suf2[m+1] = 1;
    

    for(int i = m; i >= 1; i--){

        int lo = i+1;
        int hi = m+1;
        int l = -1;
        //bsearch for l

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(b[i] + k < b[mid]){
                hi = mid-1;
                l = mid;
            }
            else lo = mid+1;
        }

        dp[i] = suf[l] * fastpow(2, cnt[i]);

        int sm1 = (suf2[i+1] - suf2[l] + MOD) % MOD;
        dp[i] = (dp[i] + (sm1 * fastpow(pbounded[i-1], MOD-2)) % MOD) % MOD;
        suf[i] = (suf[i+1] + dp[i]) % MOD;
        suf2[i] = (suf2[i+1] + (dp[i] * pbounded[i-1]) % MOD) % MOD;
        

    }
    
    int ans = 0;
    for(int i = 1; i <= m; i++) ans = (ans + dp[i]) % MOD;
    cout << ans << "\n";
}