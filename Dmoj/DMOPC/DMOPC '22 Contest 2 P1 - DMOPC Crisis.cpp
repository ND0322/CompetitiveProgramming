#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;

    int cnt = 0;

    string ans;
    int res = 0;

    for(int i = 0; i < n; i++){
        if(!cnt || cnt == 1) ans += '_';
        else{
            res++;
            ans += 'M';
        }

        cnt = (cnt+1)%4;
    }

    cout << res << "\n";
    cout << ans << "\n";

}