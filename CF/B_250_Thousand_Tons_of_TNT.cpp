#include <bits/stdc++.h>
#include <iostream>

using namespace std;
 

 
int main() {
	int tt; cin >> tt;

    while(tt--){
        int n,m;
        cin >> n;
        vector<int> a(n);

        for(int i = 0; i < n; i++) cin >> a[i];

        long long ans = 0;
        for(int i = 0; i < n; i++){
            vector<long long> b;
            if(n%(i+1)==0){
                long long cur = 0;
                for(int j = 0; j < n; j++){
                
                    cur+=a[j];
                    if((j+1)%(i+1)==0){
                        b.push_back(cur);
                        cur=0;
                    }
                }
                sort(b.begin(),b.end());
                ans = max(ans,b[b.size()-1]-b[0]);
            }
        }
        cout << ans << "\n";

    }
}