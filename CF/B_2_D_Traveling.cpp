#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

ll A[200005],B[200005];
//im stupid * 2



int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,k,a,b; cin >> n >> k >> a >> b;

        //if no major cities straight up fly to b cause distance is constant

        //sort major cities by distance to b
        //sort them by distance to a

        //sum

        a--;
        b--;

        

        

        long long minA = LLONG_MAX/2,minB = LLONG_MAX/2;

        for(int i = 0; i < n; i++){
            cin >> A[i] >> B[i];

            
        }

        for(int i = 0; i < k; i++){
            minA = min(minA,abs(A[a] - A[i]) + abs(B[a] - B[i]));
            minB = min(minB,abs(A[b] - A[i]) + abs(B[b] - B[i]));
        }
        
        long long first = (abs(A[a] - A[b]) + abs(B[a] - B[b]));
        long long second = minA + minB;
        if(k <= 1) cout << first << "\n";
        else cout << min(first,second) << "\n";

        

        

        


    }
}