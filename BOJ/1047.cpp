#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 45;

int n;

pair<pair<int,int>, int> a[MAXN];

//brute max x min x max y min y
//remove all stuff outside that and greedy the insides to make up the perimeter

int main(){
    cin >> n;

    for(int i = 1; i <= n ; i++) cin >> a[i].first.first >> a[i].first.second >> a[i].second;

    int ans = 1e9;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                for(int l = 1; l <= n; l++){
                    //i is max x
                    //j is min x
                    //k is max y
                    //l is min y

                    pair<int,int> mx = {a[i].first.first, a[j].first.first};
                    pair<int,int> my = {a[k].first.second, a[l].first.second};


                    
                    
                    if(mx.first != max({a[i].first.first, a[j].first.first, a[l].first.first, a[k].first.first}));
                    if(mx.second != min({a[i].first.first, a[j].first.first, a[l].first.first, a[k].first.first}));
                    if(my.first != max({a[i].first.second, a[j].first.second, a[l].first.second, a[k].first.second}));
                    if(my.second != min({a[i].first.second, a[j].first.second, a[l].first.second, a[k].first.second}));

                    //cout << mx.first << " " << mx.second << " " << my.first << " " << my.second << "\n";
                    int per = (mx.first - mx.second) * 2 + (my.first - my.second) * 2;

                    vector<int> nutsac;

                    int cnt = 0;
                    for(int p = 1; p <= n; p++){
                        if(a[p].first.first <= mx.first && a[p].first.first >= mx.second && a[p].first.second <= my.first && a[p].first.second >= my.second) nutsac.push_back(a[p].second);
                        else{
                            cnt++;
                            per -= a[p].second;  
                        }                      
                    }

                    if(per <= 0){
                        ans = min(ans, cnt);
                        //cout << mx.first << " " << mx.second << " " << my.first << " " << my.second << " " << cnt << "\n";
                        continue;
                    }

                    sort(nutsac.rbegin(), nutsac.rend());

                    for(int p = 0; p < nutsac.size(); p++){
                        per -= nutsac[p];

                        if(per <= 0){
                            ans = min(ans, cnt + p + 1);
                            break;
                        }
                    }






                }
            }
        }
    }

    cout << ans << "\n";
    
}