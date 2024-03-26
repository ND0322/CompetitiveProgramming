#include <bits/stdc++.h>
#include <iostream> 

using namespace std;
//n!
//n-r! * 2


int main(){
    int n; cin >> n;


    long long ans = 0;

    for(long long i = 1; i < n; i++){
        if(n-2*i < 0) break;
        
        ans = max(ans,i * (n-2*i) * (n-2*i-1)/2LL);
    }

    cout << ans << "\n";


}