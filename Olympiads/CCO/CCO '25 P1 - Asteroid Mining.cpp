#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5e5+5;
int n;

long long k, a[MAXN], b[MAXN];

map<long long,priority_queue<long long>> ms;


int32_t main(){
    cin >> n >> k;

    long long mn = 1e12;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
        mn = min(mn, b[i]);
    }

    for(int i = 1; i <= n; i++) b[i] /= mn;
    k /= mn;

    for(int i = 1; i <= n; i++){
        if(b[i] > k) continue;
        ms[b[i]].push(a[i]);
    }

    vector<long long> weights = {};

    for(auto [x,y] : ms) weights.push_back(x);
    


    long long ans = 0;

    int last = weights.size()-1;
    for(int i = 0; i < weights.size()-1; i++){
        if(k == 0){
            last = i+1;
            break;
        }
        long long nxt = weights[i+1] / weights[i];

    
        while(k%nxt != 0 && ms[weights[i]].size()){
            ans += ms[weights[i]].top();
            ms[weights[i]].pop();
            k--;
        }

        while(ms[weights[i]].size() >= nxt){
            long long sm = 0;
            for(int j = 0; j < nxt; j++){
                sm += ms[weights[i]].top();
                ms[weights[i]].pop();
            }

            


            ms[weights[i+1]].push(sm);
        }

        long long sm = 0;
        while(ms[weights[i]].size()){
            sm += ms[weights[i]].top();
            ms[weights[i]].pop();
        }


        ms[weights[i+1]].push(sm);


        k /= nxt;
    }

    

    while(k-- && ms[weights[last]].size()){
        ans += ms[weights[last]].top();
       
        ms[weights[weights.size()-1]].pop();
    }

    

    cout << ans << "\n";



    

    


}