#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
consider even and odd seperately

for odd

sum of all block distances to center must be equal 

even is not possible

for odd we have a few constuctions
we can reduce one odd to even by placing 3 in the middle
for two odds we can reduce to even by placing 3 on either side

2110221

4
2 + 3 + 7 = 12 / 3 = 4
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, k; cin >> n >> k;

        vector<int> cnt(k+1, 0);
        
        int one = 0;
        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            cnt[x]++;
        }

        bool flag = 0;
        for(int i = 1; i <= k; i++){
            if(cnt[i] == 1){
                if(one) flag |= 1;
                else one = i;
            }
        }

        if(flag){
            cout << "NO\n";
            continue;
        }
        

        set<int> odd;

        vector<int> ans(n+1);

        for(int i = 1; i <= k; i++){
            if(cnt[i]&1) odd.insert(i);   
        }

        if(odd.size() && !(n&1)){
            cout << "NO\n";
            continue;
        }

        if(one){
            ans[(n+1)/2] = one;
            cnt[one]--;
            odd.erase(one);
        }
        else if(odd.size()){   
            ans[(n+1)/2] = *odd.begin();
            cnt[*odd.begin()]--;
            odd.erase(odd.begin());
        }


        int r = 1;

        while(odd.size()){
            int a = *odd.begin();

            odd.erase(odd.begin());

            int b = *odd.begin();

            odd.erase(odd.begin());

            ans[(n+1)/2 - r] = a;
            ans[(n+1)/2 - r - 1] = a;
            ans[(n+1)/2 - r - 2] = b;

            ans[(n+1)/2 + r] = b;
            ans[(n+1)/2 + r + 1] = b;
            ans[(n+1)/2 + r + 2] = a;

            cnt[a]-=3;
            cnt[b]-=3;

            r += 3;
        }

        for(int i = 1; i <= k; i++){
            if(cnt[i]&1) continue;

            while(cnt[i]){
                ans[(n+1)/2 - r + !(n&1)] = i;
                ans[(n+1)/2 + r] = i;
                cnt[i] -= 2;
                r++;
            }
        }

        cout << "YES\n";
        for(int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << "\n";








    }
}