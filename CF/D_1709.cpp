#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> a(n+1);
        vector<int> b(n+1);

        int cnt = 0;

        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];

        vector<pair<int,int>> ans;        

   
        bool swapped;
    
        for (int i = 1; i <= n; i++) {
            swapped = false;
            for (int j = 1; j <= n - i; j++) {
                if (a[j] > a[j + 1]) {
                    swap(a[j], a[j + 1]);
                    swapped = true;
                    ans.push_back({1, j});
                }
            }
        
        
            if (!swapped)
                break;
        }

    
        for (int i = 1; i <= n; i++) {
            swapped = false;
            for (int j = 1; j <= n - i; j++) {
                if (b[j] > b[j + 1]) {
                    swap(b[j], b[j + 1]);
                    swapped = true;
                    ans.push_back({2, j});
                }
            }
        
        
            if (!swapped)
                break;
        }

    
    for(int i = 1; i <= n; i++){
        if(a[i] > b[i]){
            ans.push_back({3,i});
            swap(a[i], b[i]);
        }
    }

    cout << ans.size() << "\n";

    for(auto [x,y] : ans) cout << x << " " << y << "\n";

}
}