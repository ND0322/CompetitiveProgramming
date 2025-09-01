#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 1e6+5;
const int MOD = 1e6+3;
const int MINV = 500002;


#define int long long

int n, a[MAXN], b[MAXN];




/*
the question can be handled in three parts:
from 1 to l of peak
from l to r of peak
from r of peak to n

parts 1 and 3 we simply lift each one up to the pmax and smax respectively
part 2 we lift to the peak height

we can split each mountain into searching prefix and suffix

lets say we have a group of equal summed things

obviusly for a chunk we should first raise the left and right respectively
let l1 and r1 be the prefix and suffix max at l
let l2 and r2 be prefix and suffix max at r

it is clear that l1 == l2 and r2 == r2 the array a does not yet equal b

total cost will be 2 * pref + 2 * suf - max(pref, suf)

what is cost for group of length n to raise to min(pref, suf)

((2 * pref + 2 * suf - max(pref, suf)) + 2 * (n-2)) * (delta-1)

where delta = second smallest - smallest 

for n = 1 it is just

(delta - 1) * (pref + suf)


we can maybe exchange argument for sub 2 

notice that it is always optimal to raise the chunk with minimal value
what do we do if there are multiple chunks?
we should just collapse contiguous same value into one element with some math so now we just become a merge operation


lets say we have


5 2 2 2 2 6 7 4 2 2 2 2 6 

denote p1 and s1 as prefix and suffix of group 1
similarly p2 and 2 for group 2

we always need to pay p1 and s2

buy left first:

p1 + s1 + 1 + s2

buy right first

p2 + s2 + 1 + p1 

s2 + p1 + 1 + min(s1, p2)

notice that if we have a third middle segment, the s and p are always at least as bad as the two edges so we should never raise it

we can just look at the leftmost and rightmost occurence of x and disregard intervals (we only need the number of such x)
*/



int32_t main(){
    cin >> n;

    pair<int,int> peak = {-1,-1};

    int pmax = 0;

    set<int> s;

    long long ans = 0;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        peak = max(peak, {a[i], i});
        s.insert(a[i]);

        pmax = max(pmax, a[i]);

        b[i] = pmax;
    }

    int smax = 0;

    for(int i = n; i >= peak.second; i--){
        smax = max(smax, a[i]);
        b[i] = smax;
    }

    for(int i = 1; i <= n; i++) ans = (ans + (((b[i] + a[i]-1) % MOD) * ((b[i] - a[i]) % MOD) * MINV) % MOD) % MOD;
    

    //we can just shrink the search space later when stuff reachs b

    

    for(int i : s){
        int l = 1e9;
        int r = 0;
        for(int j = 1; j <= n; j++){
            if(a[j] == b[j]) continue;

            if(a[j] == i){
                l = min(l, j);
                r = max(r, j);
            }
        }

        if(r == 0) continue;

        cout << l << " " << r << " " << i << "\n";
        int s1 = 1e9;
        int s2 = 1e9;
        int p1 = 1e9;
        int p2 = 1e9;


        for(int j = l; j <= n; j++){
            if(a[j] > i) s1 = min(s1, a[j]);
        }

        for(int j = r; j <= n; j++){
            if(a[j] > i) s2 = min(s2, a[j]);
        }


        for(int j = 1; j <= r; j++){
            if(a[j] > i) p2 = min(p2, a[j]);
        }

        for(int j = 1; j <= l; j++){
            if(a[j] > i) p1 = min(p1, a[j]);
        }

        int cnt = 0;

        //can do with BIT or policy based or smart update segment tree or precomputing
        for(int j = l; j <= r; j++) cnt += (a[j] > i);

        if(l == r) ans = (ans + ((*next(s.find(i)) - i) * (p1 + s2) % MOD) % MOD) % MOD;
        
        else{
            int dif = (*next(s.find(i)) - i) % MOD;
            int ext = ((((((r-l-cnt-1) % MOD * ((*next(s.find(i)) + i - 1) % MOD)) % MOD) * dif) % MOD) + (((*next(s.find(i)) + i - 1) * dif) % MOD * MINV) % MOD) % MOD;

            ans = ((ans + (dif * ((p1 + s2 + min(s1, p2) + 1) % MOD + (2 * (r-l+1 - cnt - 2)) % MOD)) % MOD) % MOD + ext) % MOD;
        }
        
           

        for(int j = l; j <= r; j++) a[j] = max(a[j], *next(s.find(i)));

        
    }
    


    cout << ans << "\n";

}