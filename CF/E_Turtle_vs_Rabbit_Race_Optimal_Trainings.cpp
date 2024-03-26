#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
an = k - n + 1

y = (k - (n + 1)/2) * n
y = nk - 1/2 * n^2 + 1/2n

b = k + 1/2
a = 1/2

    
find the x of the vertex
binary search for greatest less than that

*/



const int MAXN = 1e5+5;

int n, psa[MAXN], a[MAXN];

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;


        for(int i = 1; i <= n; i++){
            cin >> a[i];
            psa[i] = psa[i-1] + a[i];
        }

        int q; cin >> q;

        while(q--){
            int l, k; cin >> l >> k;

            //im bald and cant do math for some reason
            int lo = l;
            int hi = n;
            int ans = l;

            while(lo <= hi){
                int mid = (lo+hi)>>1;

                if(psa[mid] - psa[l-1] <= k){
                    ans = mid;
                    lo = mid+1;
                }
                else hi = mid-1;
            }


            //cout << "\n";
            
            long long x = psa[ans] - psa[l-1];

            //cout << x << "\n";
            


            long double p1 =  x* k - .5 * x * x + .5 * x;

            x = psa[min(ans+1,n)] - psa[l-1];
            //cout << x << "\n";
            long double p2 = x* k - .5 * x * x + .5 * x;

            
            //cout << p1 << " " << p2 << " " << ans << "\n";

            if(p1 >= p2) cout << ans << " ";
            else cout << ans+1 << " ";
            
        }

        cout << "\n";


    }


}