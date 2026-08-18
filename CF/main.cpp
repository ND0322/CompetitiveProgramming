#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TestsNumT; 
    cin >> TestsNumT;

    while(TestsNumT--){
        int n, m, x, y; 
        cin >> n >> m >> x >> y;

        set<int> a;
        set<int> b;

        for(int i = 1; i <= x; i++){
            int val; cin >> val;
            a.insert(val);
        }
        for(int i = 1; i <= y; i++){
            int val; cin >> val;
            b.insert(val);
        }

        vector<int> A_only, B_only, AB;

        for(int val : a){
            if(b.count(val)) AB.push_back(val);
            else A_only.push_back(val);
        }
        for(int val : b){
            if(!a.count(val)) B_only.push_back(val);
        }

        sort(A_only.rbegin(), A_only.rend());
        sort(B_only.rbegin(), B_only.rend());
        sort(AB.rbegin(), AB.rend());

        auto get_ans = [&](int c1, int c2) {
            c1 = min(c1, (int)a.size());
            c2 = min(c2, (int)b.size());

            int sz_a = A_only.size();
            int sz_b = B_only.size();
            int sz_ab = AB.size();

            vector<long long> pA(sz_a + 1, 0), pB(sz_b + 1, 0), pAB(sz_ab + 1, 0);

            for(int i = 0; i < sz_a; i++) pA[i + 1] = pA[i] + A_only[i];
            for(int i = 0; i < sz_b; i++) pB[i + 1] = pB[i] + B_only[i];
            for(int i = 0; i < sz_ab; i++) pAB[i + 1] = pAB[i] + AB[i];

            long long mx = 0;

            for(int k = 0; k <= min(c1, sz_a); k++){
                int max_l = min(c2, sz_b);

                int l1 = 0;
                int l2 = max_l;
                int l3 = c1 + c2 - k - sz_ab;

                vector<int> cand = {l1, l2};
                if(l3 >= 0 && l3 <= max_l) cand.push_back(l3);
                if(l3 + 1 >= 0 && l3 + 1 <= max_l) cand.push_back(l3 + 1);

                for(int l : cand){
                    int take_ab = min(sz_ab, max(0, c1 + c2 - k - l));
                    long long cur = pA[k] + pB[l] + pAB[take_ab];
                    mx = max(mx, cur);
                }
            }
            return mx;
        };

        long long ans1 = get_ans(n, m - 1);
        long long ans2 = get_ans(n - 1, m);

        cout << max(ans1, ans2) << "\n";
    }
}