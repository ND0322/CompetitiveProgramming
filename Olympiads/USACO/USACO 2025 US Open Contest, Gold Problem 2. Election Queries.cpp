#include <bits/stdc++.h>
#include <iostream>


using namespace std;

const int MAXN = 2e5+5;

int n, a[MAXN], freq[MAXN], q, mx[MAXN], mn[MAXN];

map<int,int> mp;

set<int> s[MAXN];

/*
x + y >= most frequent element

number of distinct frequencies is bounded o(sqrt n)
some set bookeeping shit + segtree 
*/

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> q;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        freq[a[i]]++;
    }

    for(int i = 1; i <= n; i++){
        if(!freq[i]) continue;
        mp[freq[i]]++;
        s[freq[i]].insert(i);
    }

    for(int i = 1; i <= n; i++){
        if(mp.find(i) == mp.end()) continue;
        mn[i] = *s[i].begin();
        mx[i] = *s[i].rbegin();
    }


    while(q--){
        int i,x; cin >> i >> x;

        if(freq[a[i]]){
            mp[freq[a[i]]]--;
            s[freq[a[i]]].erase(a[i]);
            if(!mp[freq[a[i]]]) mp.erase(freq[a[i]]);
            else{
                mn[freq[a[i]]] = *s[freq[a[i]]].begin();
                mx[freq[a[i]]] = *s[freq[a[i]]].rbegin();
            }
        }        
        freq[a[i]]--;
        if(freq[a[i]]){
            mp[freq[a[i]]]++;
            s[freq[a[i]]].insert(a[i]);
            mn[freq[a[i]]] = *s[freq[a[i]]].begin();
            mx[freq[a[i]]] = *s[freq[a[i]]].rbegin();
        }

        a[i] = x;

        if(freq[a[i]]){
            mp[freq[a[i]]]--;
            s[freq[a[i]]].erase(a[i]);
            if(!mp[freq[a[i]]]) mp.erase(freq[a[i]]);
            else{
                mn[freq[a[i]]] = *s[freq[a[i]]].begin();
                mx[freq[a[i]]] = *s[freq[a[i]]].rbegin();
            }
        }        
        freq[a[i]]++;
        if(freq[a[i]]){
            mp[freq[a[i]]]++;
            s[freq[a[i]]].insert(a[i]);
            mn[freq[a[i]]] = *s[freq[a[i]]].begin();
            mx[freq[a[i]]] = *s[freq[a[i]]].rbegin();
        }
        
        vector<int> tmx, tmn, label;
        vector<int> smn(mp.size()+2), smx(mp.size()+2);

        tmx = tmn = label = {0};

        for(auto j : mp){
            label.push_back(j.first);
            tmx.push_back(mx[j.first]);
            tmn.push_back(mn[j.first]);

        }

        int ans = 0;
        smn[mp.size()+1] = 1e9;
        for(int i = mp.size(); i >= 1; i--){
            smx[i] = max(smx[i+1], tmx[i]);
            smn[i] = min(smn[i+1], tmn[i]);
        }


        int j = mp.size();

        

        for(int l = 1; l <= mp.size(); l++){
            while(j > l && label[j-1] + label[l] >= label.back()) j--;

            int k = j;
            if(j < l) k = l;
            if(k == l && tmn[l] == tmx[l]) k+1;

            ans = max(ans, smx[k] - tmn[l]);
            ans = max(ans, tmx[l] - smn[k]);
        
            
        }
        
        cout << ans << "\n";



    }
}