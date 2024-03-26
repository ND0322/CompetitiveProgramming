#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        string ans;

        vector<int> cnt(27);

        int cur = 0;

        for(int i = 0; i < n; i++){
            int x; cin >> x;

            if(!x){
                ans += (char)(cur+'a');
                cnt[cur]++;
                cur++;
                continue;
            }
            else{
                for(int j = 0; j < 26; j++){
                    if(cnt[j] == x){
                        ans += (char)(j+'a');
                        cnt[j]++;
                        break;
                    }
                }
            }
        }

        cout << ans << "\n";
    }
}