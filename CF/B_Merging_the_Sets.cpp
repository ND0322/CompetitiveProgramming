#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
try all sets as one solution

try taking away one set and seeing if it still works 
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n,m; cin >> n >> m;

        vector<int> freq(m+1);

        vector<vector<int>> sets(n+1);

        for(int i = 1;i <= n; i++){
            int l; cin >> l;

            sets[i] = vector<int> (l+1);

            for(int j = 1; j <= l; j++){
                cin >> sets[i][j];
                freq[sets[i][j]]++;
            }
        }

        bool flag = 1;

        for(int i = 1; i <= m; i++) flag &= (freq[i] >= 1);
        

        if(!flag){
            cout << "NO\n";
            continue;
        }

        int cnt = 0;

        for(int i = 1; i <= n; i++){
            //remove

            bool flag = 1;
            for(int j = 1; j < sets[i].size(); j++){
                freq[sets[i][j]]--;

                flag &= (freq[sets[i][j]] >= 1);
            }

            cnt += flag;

            for(int j = 1; j < sets[i].size(); j++) freq[sets[i][j]]++;               
        }

        cout << (cnt >= 2 ? "YES\n" : "NO\n");


    }
}