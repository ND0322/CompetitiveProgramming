#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n);

        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());

        int ans = 0;

        for(int i = 1; i < n-1; i++){
            for(int j = i+1; j < n-1; j++){
                vector<int> ord = {0, i, j, n-1};

                do{
                    ans = max(ans, abs(a[ord[0]] - a[ord[1]]) + abs(a[ord[1]] - a[ord[2]]) + abs(a[ord[2]] - a[ord[3]]) + abs(a[ord[3]] - a[ord[0]]));
                }
                while(next_permutation(ord.begin(), ord.end()));

            }
        }

        cout << ans << "\n";
    }
}