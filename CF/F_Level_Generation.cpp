#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int q;

long long n;

/*
we can have a 2CC of size x
number of edges = 
#of non 2CC nodes = n-x 
+
#of 2CC edges = min(number of potential edges = nC2, number of non 2CC edges for the condition in the problem)

so

ans = n-x + min(n(n-1)/2, n-x)
*/

long long f(long long x){
    return n-x + min(x*(x-1)/2, n-x);
}

int main(){
    cin >> q;

    while(q--){
        cin >> n;

        if(n <= 5){
            cout << n-1 << "\n";
            continue;
        }

        

        int lo = 3;
        int hi = n;
        long long ans = 0;



        while(lo <= hi){
            int mid = (lo+hi)>>1;


            if(f(mid) > f(mid+1)){
                hi = mid-1;
                ans = f(mid);
            }
            else lo = mid+1;
        }

        cout << ans << "\n";


    }
}