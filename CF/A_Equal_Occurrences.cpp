#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 105;

int freq[MAXN];

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        memset(freq, 0 ,sizeof(freq));

        for(int i = 1; i <= n; i++){
            int x; cin >> x;

            freq[x]++;
        }


        sort(freq+1, freq+n+1);
        reverse(freq+1, freq+n+1);


        int ans = 0;

        for(int i = 1; i <= n; i++){
            ans = max(ans, i * freq[i]);
        }

        cout << ans << "\n";



    }
}