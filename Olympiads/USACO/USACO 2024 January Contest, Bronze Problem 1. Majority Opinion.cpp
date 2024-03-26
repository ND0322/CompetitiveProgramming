#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n, last[MAXN], cnt[MAXN];

bool has[MAXN];

int main(){
    

    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        for(int i = 1; i <= n; i++){
            cnt[i] = 0;
            has[i] = 0;
            last[i] = 0;
        }

        for(int i = 1; i <= n; i++){
            int x; cin >> x;

            if(i - last[x] <= 2) cnt[x]++;
            else cnt[x] = 1;
                
            

            last[x] = i;

            has[x] |= cnt[x] >= 2;
            
        }

       

        vector<int> ans;

        for(int i = 1; i <= n; i++){
            if(has[i]){
                ans.push_back(i);
            }
        }
        
        if(!ans.size()){
            cout << "-1\n";
            continue;
        }

        for(int i = 0; i < ans.size()-1; i++) cout << ans[i] << " ";
        cout << ans[ans.size()-1] << "\n";

        
    }
    


}