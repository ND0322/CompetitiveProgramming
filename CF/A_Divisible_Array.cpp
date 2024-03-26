#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int roundUp(int numToRound, int multiple)
{
    if (multiple == 0)
        return numToRound;

    int remainder = numToRound % multiple;
    if (remainder == 0)
        return numToRound;

    return numToRound + multiple - remainder;
}

int main(){
    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        vector<int> ans;
        int tot = 0;
        for(int i = 1; i <= n; i++){
            ans.push_back(i);
            tot += i;
        }

        int target = roundUp(tot,n);

        target -= tot;

        for(int i = n; i >= 1; i--){
            
            ans[i-1] += i * (target / i);
            target %= i;
            
            
            
        }

        for(int i = 0; i < n; i++){
            cout << ans[i] << " ";
        }

        cout << endl;
    }
}