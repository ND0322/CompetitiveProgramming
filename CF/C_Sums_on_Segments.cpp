#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

int kadanes(vector<int> a){
    int n = a.size();

    int pref = 1e9;
    int ans = 1e9;

    for(int i = 0; i < n; i++){
        if(pref > 0) pref = a[i];
        else pref += a[i];

        ans = min(ans, pref);
    }

    return ans;
}

int pmax(vector<int> a){
    int n = a.size();

    int ans = 0;

    int sm = 0;
    for(int i = 0; i < n; i++){
        sm += a[i];
        ans = max(ans, sm);
    }

    return ans;
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;
        

        int k = -1;

        vector<int> l;
        vector<int> r;
        bool flag = 0;

        for(int i = 0; i < n; i++){
            int x; cin >> x;

            if(x != 1 && x != -1){
                k = x;
                flag = 1;
                continue;
            }

            if(flag) r.push_back(x);
            else l.push_back(x);
        } 

        int lmn = kadanes(l);
        for(int i = 0; i < l.size(); i++) l[i] = -l[i];
        int lmx = -kadanes(l);
        int rmn = kadanes(r);
        for(int i = 0; i < r.size(); i++) r[i] = -r[i];
        int rmx = -kadanes(r);



 
        set<int> ans = {0};

        for(int i = lmn; i <= lmx; i++) ans.insert(i);
        for(int i = rmn; i <= rmx; i++) ans.insert(i);

        if(k != 1 and k != -1){

        

            rmn = -pmax(r);
            for(int i = 0; i < r.size(); i++) r[i] = -r[i];
            rmx = pmax(r);

            reverse(l.begin(), l.end());

            lmn = -pmax(l);
            for(int i = 0; i < l.size(); i++) l[i] = -l[i];
            lmx = pmax(l);

    



            for(int i = min(lmn,0) + min(rmn,0) + k; i <= max(0,rmx) + max(0,lmx) + k; i++) ans.insert(i);

            
        }

        cout << ans.size() << "\n";
        for(int i : ans) cout << i << " ";
        cout << "\n";

        
    }
}