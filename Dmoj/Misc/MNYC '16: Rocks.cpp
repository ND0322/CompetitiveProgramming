#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

const int MAXN = 1e5+5;

int n, q, st[MAXN<<1];

map<string, int> pos;

pair<char, pair<string,string>> queries[MAXN];



void update(int i, int x){
    for(st[i+=n] = x; i > 1; i>>=1) st[i>>1] = st[i] + st[i^1];
}

int query(int l, int r){
    int ans = 0;
    for(l += n, r+=n; l < r; l >>=1, r>>=1){
        if(l&1) ans += st[l++];
        if(r&1) ans += st[--r];
    }
    return ans;
}

int hsh(string s){
    int ans = 0;
    for(int i = 0; i < s.size(); i++) ans += s[i] - 'a' + 1;
    return ans;
}

int main(){
    cin >> q;

    for(int i = 0; i < q; i++){
        cin >> queries[i].first;

        if(queries[i].first == 'N') continue;
        if(queries[i].first == 'A'){
            cin >> queries[i].second.first;
            n++;
            continue;
        }

        cin >> queries[i].second.first;
        cin >> queries[i].second.second;
    }


    int cnt = 0;

    for(int i = 0; i < q; i++){
        if(queries[i].first == 'N'){
            cout << cnt << "\n";
            continue;
        }

        if(queries[i].first == 'A'){
            if(pos.count(queries[i].second.first)){
                cout << "Can't add " << queries[i].second.first << "\n";
                continue;
            }
            pos[queries[i].second.first] = cnt;
            update(cnt, hsh(queries[i].second.first));
            cnt++;
            
        }

        if(queries[i].first == 'S'){
            swap(pos[queries[i].second.first], pos[queries[i].second.second]);
            update(pos[queries[i].second.first], hsh(queries[i].second.first));
            update(pos[queries[i].second.second], hsh(queries[i].second.second));
        }

        if(queries[i].first == 'M'){
            int p1 = pos[queries[i].second.first];
            int p2 = pos[queries[i].second.second];

            if(p1 > p2) swap(p1,p2);

            cout << query(p1,p2+1) << "\n";

            //cout << p1 << " " << p2 << " " <<  pos["a"] << " " << pos["b"] << " " << pos["c"] << "\n";
        }

        if(queries[i].first == 'R'){
            pos[queries[i].second.second] = pos[queries[i].second.first];
            update(pos[queries[i].second.second], hsh(queries[i].second.second));
            pos.erase(queries[i].second.first);
        }

        //cout <<"e " << query(0, 6) << "\n";


    }
}