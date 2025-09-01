#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long

/*
choose 4 indices such that the maximum absolute value difference is minimum

max - min + middle two difference 

swap a and b such that a contains all the mins and b contains all the maxes 
*/

int32_t main(){
    int tt; cin >> tt;


    while(tt--){
        int n, k; cin >> n >> k;


        map<int, set<int>> mp;


        vector<int> a(n+1), b(n+1);


        set<pair<int,int>> check;


        long long ans = 0;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++){
            cin >> b[i];

            ans += abs(b[i] - a[i]);

            mp[max(a[i], b[i])].insert(min(a[i], b[i]));

            check.insert({max(a[i], b[i]), min(a[i], b[i])});
        }
        if((int)check.size() != n){
            cout << ans << "\n";
            continue;
        }
        int best = 1e18;
        for(int i = 1; i <= n; i++){
            auto l = mp.lower_bound(min(a[i], b[i]));
            if(l != mp.end() && l->first == max(a[i], b[i]) && (int)l->second.size() == 1){
                l = next(l);
            }
            if(l != mp.end()){
                auto fuck = l->second.lower_bound(max(a[i], b[i]));

                if(fuck != l->second.end() && *fuck == min(a[i], b[i])) fuck = next(fuck);

                if(fuck != l->second.end()){

                    vector<int> tmp = {l->first, min(a[i], b[i]), *fuck, max(a[i], b[i])};
                    sort(tmp.begin(), tmp.end());
                    best = min(best, tmp[3] - tmp[0] + tmp[2] - tmp[1]
                        - (max(a[i], b[i]) - min(a[i], b[i])) - (l->first - *fuck));
                }


                fuck = l->second.lower_bound(max(a[i], b[i]));

                if(fuck != l->second.begin()){
                    fuck = prev(fuck);

                    if(fuck != l->second.begin() && *fuck == min(a[i], b[i])) fuck = prev(fuck);


                    vector<int> tmp = {l->first, min(a[i], b[i]), *fuck, max(a[i], b[i])};
                    sort(tmp.begin(), tmp.end());


                    best = min(best, tmp[3] - tmp[0] + tmp[2] - tmp[1]
                        - (max(a[i], b[i]) - min(a[i], b[i])) - (l->first - *fuck));
                }
            }
            l = mp.lower_bound(min(a[i], b[i]));


            if(l != mp.begin()){


                l = prev(l);
                auto fuck = l->second.lower_bound(max(a[i], b[i]));


                if(fuck != l->second.end()){


                    vector<int> tmp = {l->first, min(a[i], b[i]), *fuck, max(a[i], b[i])};
                    sort(tmp.begin(), tmp.end());
                    best = min(best, tmp[3] - tmp[0] + tmp[2] - tmp[1]
                        - (max(a[i], b[i]) - min(a[i], b[i])) - (l->first - *fuck));
                }
                if(fuck != l->second.begin()){

                    
                    fuck = prev(fuck);
                    vector<int> tmp = {l->first, min(a[i], b[i]), *fuck, max(a[i], b[i])};
                    sort(tmp.begin(), tmp.end());
                    best = min(best, tmp[3] - tmp[0] + tmp[2] - tmp[1]
                        - (max(a[i], b[i]) - min(a[i], b[i])) - (l->first - *fuck));
                }
            }
        }
        cout << ans + best << "\n";
    }
}
