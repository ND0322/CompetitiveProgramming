#include <bits/stdc++.h>
#include <iostream>
#include <map>


using namespace std;

const int MAXN = 1e6+5;

typedef pair<int,int> pii;

int n;

vector<pii> a,b;
vector<pair<pii,bool>> c;

map<long long,long long> best;

int main(){
    cin >> n;

    long long ans = 1e18;
    int si = -1;
    int sj = -1;

    for(int i = 0; i < n; i++){
        int x; cin >> x;

        if(best.find(x) == best.end()) best[x] = i;
        else{
            if(2*abs(x) < ans){
                ans = 2*abs(x);
                si = best[x];
                sj = i;
            }
            else if(2*abs(x) == ans){
                if(best[x] < si){
                    si = best[x];
                    sj = i;
                }
                else if(best[x] == si) sj = min(sj, i);
            }
        }
    }

    for(auto i : best){
        if(i.first < 0){
            a.push_back({i.first, i.second});
            c.push_back({{-i.first, i.second}, 1});
        }
        else{
            b.push_back({i.first, i.second});
            c.push_back({{i.first, i.second}, 0});
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    

    for(int i = 0; i < (int)a.size()-1; i++){
        if( -a[i].first - a[i+1].first < ans){
            ans = -a[i].first - a[i+1].first;
            si = min(a[i].second, a[i+1].second);
            sj = max(a[i].second, a[i+1].second);
        }
        else if( -a[i].first - a[i+1].first == ans){
            if(min(a[i].second, a[i+1].second) < si){
                si = min(a[i].second, a[i+1].second);
                sj = max(a[i].second, a[i+1].second);
            }
            else if(si == min(a[i].second, a[i+1].second)) sj = min(sj, max(a[i].second, a[i+1].second));
        }
    }

    for(int i = 0; i < (int)b.size()-1; i++){
        if( b[i].first + b[i+1].first < ans){
            ans = b[i].first + b[i+1].first;
            si = min(b[i].second, b[i+1].second);
            sj = max(b[i].second, b[i+1].second);
        }
        else if( b[i].first + b[i+1].first == ans){
            if(min(b[i].second, b[i+1].second) < si){
                si = min(b[i].second, b[i+1].second);
                sj = max(b[i].second, b[i+1].second);
            }
            else if(si == min(b[i].second, b[i+1].second)) sj = min(sj, max(b[i].second, b[i+1].second));
        }
    }

    for(int i = 0; i < (int)c.size()-1; i++){
        if(c[i].second == c[i+1].second) continue;



        if( abs(c[i].first.first - c[i+1].first.first) < ans){
            ans = abs(c[i].first.first - c[i+1].first.first);
            si = min(c[i].first.second, c[i+1].first.second);
            sj = max(c[i].first.second, c[i+1].first.second);
        }
        else if(abs(c[i].first.first - c[i+1].first.first) == ans){
            if(min(c[i].first.second, c[i+1].first.second) < si){
                si = min(c[i].first.second, c[i+1].first.second);
                sj = max(c[i].first.second, c[i+1].first.second);
            }
            else if(si == min(c[i].first.second, c[i+1].first.second)) sj = min(sj, max(c[i].first.second, c[i+1].first.second));
        }


    }

    cout << ans << "\n";
    cout << si+1 << " " << sj+1 << "\n";

    

   
}