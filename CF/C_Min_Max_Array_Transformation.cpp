#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
how many less and greater 
i-1 less and n-i greater 

min just binary search

for max we consider that the prefix of bj for some candidate j must have a sufficient number of elements less in a
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;
        

        vector<int> a(n+1);
        vector<int> b(n+1);

        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];

        for(int i = 1; i <= n; i++){
            int lo = 1;
            int hi = n;

            int ans = -1;

            while(lo <= hi){
                int mid = (lo+hi)>>1;

                if(b[mid] >= a[i]){
                    hi = mid-1;
                    ans = mid;
                }
                else lo =mid+1;
            }
            cout << b[ans] - a[i] << " ";
        }
        cout << "\n";

        //mark bad points and for each is the nearest bad point

        int p1 = 0;
        int p2 = 0;
        for(int i = 1; i <= n; i++){

        }
    }
}