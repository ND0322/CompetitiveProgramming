#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        
        //answer is upper bounded by number of unique elements in a and b
        //which is bounded by x + y
        //prioritize larger numbers


        //place n largest rows
        //place m-1 largest columns
        //or if the m-2 largest column beats the sum of top rows the when can get rid of it

        int n,m, x,y; cin >> n >> m >> x >> y;

        set<int> a;
        set<int> b;

        set<int> uni;
        for(int i = 1; i <= x; i++){
            int z; cin >> z;
            a.insert(z);
        }
        for(int i = 1; i <= y; i++){
            int z; cin >> z;

            b.insert(z);

            if(a.find(z) != a.end()){
                a.erase(z);
                b.erase(z);

                uni.insert(z);
            }
        }


        int sz1 = a.size();
        int sz2 = b.size();
        int sz3 = uni.size();


        vector<int> psa1(sz1+2), psa2(sz2+2), psa3(sz3+2);

        for(int i = 1; i <= sz1; i++){
            psa1[i] = psa1[i-1] + *a.rbegin();
            a.erase(prev(a.end()));
        }

        for(int i = 1; i <= sz2; i++){
            psa2[i] = psa2[i-1] + *b.rbegin();
            b.erase(prev(b.end()));
        }

        for(int i = 1; i <= sz3; i++){
            psa3[i] = psa3[i-1] + *uni.rbegin();
            uni.erase(prev(uni.end()));
        }

        int c1 = min(n, x);
        int c2 = min(m-1, y);

        int ans = 0;

        for(int k = 0; k <= min(c1, sz1); k++){
            int r = min(c2, sz2);

            int l = 0;

            int s = r;

            
            int pos = min(sz3, max(0LL, c1 + c2 - k - l));

            ans = max(ans, psa1[k] + psa2[l] + psa3[pos]);

            pos = min(sz3, max(0LL, c1 + c2 - k - r));
            ans = max(ans, psa1[k] + psa2[r] + psa3[pos]);

            int cand = c1 + c2 - sz3 - k;

            if(0 <= cand && cand <= r){
                pos = min(sz3, max(0LL, c1 + c2 - k - cand));
                ans = max(ans, psa1[k] + psa2[cand] + psa3[pos]);
            }
            cand++;
            if(0 <= cand && cand <= r){
                pos = min(sz3, max(0LL, c1 + c2 - k - cand));
                ans = max(ans,psa1[k] + psa2[cand] + psa3[pos]);
            }
        }

        c1 = min(n-1, x);
        c2 = min(m, y);

        for(int k = 0; k <= min(c1, sz1); k++){
            int r = min(c2, sz2);

            int l = 0;

            int s = r;

            
            int pos = min(sz3, max(0LL, c1 + c2 - k - l));

            ans = max(ans, psa1[k] + psa2[l] + psa3[pos]);

            pos = min(sz3, max(0LL, c1 + c2 - k - r));
            ans = max(ans, psa1[k] + psa2[r] + psa3[pos]);

            int cand = c1 + c2 - sz3 - k;

            if(0 <= cand && cand <= r){
                pos = min(sz3, max(0LL, c1 + c2 - k - cand));
                ans = max(ans, psa1[k] + psa2[cand] + psa3[pos]);
            }
            cand++;
            if(0 <= cand && cand <= r){
                pos = min(sz3, max(0LL, c1 + c2 - k - cand));
                ans = max(ans,psa1[k] + psa2[cand] + psa3[pos]);
            }
        }


        cout << ans << "\n";








     
        
    }
}