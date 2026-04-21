#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
casework

consider multiples kn greater than min(x,y)
Obviously only one possibility per k

<= min(x,y)

WLOG assume x <= y
We can safely send [0:x] so long as nk - y <= x
so we send [nk-y:x] for all nk <= x

bounds 
cap at 0 where k < y/n
max is when nk - y > x
nk > x + y

arithmetic sequence decreasing by n per step 
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, x, y; cin >> n >> x >> y;

        if(x > y) swap(x,y);

        long long ans = 0;

        int l = y / n;
        ans += l * x;

        l = ceil(y/(double)n);

        int r = (x+y)/n;

        cout << l << " " << r << "\n";
        cout << (2*x + 2*y - n * (l+r)) << "\n";
        

        ans += (2*x + 2*y - n * (l+r)) * (r-l+1) / 2;

        cout << ans << "\n";



    }
}