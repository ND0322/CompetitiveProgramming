#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>

using namespace std;

const int MAXN = 2e5+5, MOD = 1e9+7;

int n,m;

long long t[MAXN*2];


unordered_map<int,int> cnt;


void build(){
    for(int i = n-1; i > 0; i--) t[i] = (t[i<<1] * t[i<<1|1]) % MOD;
}

long long query(int l,int r){
    long long ans = 1;
    for(l += n, r += n; l < r; l >>=1, r >>= 1){
        if(l&1) ans = (ans * t[l++]) % MOD;
        if(r&1) ans = (ans * t[--r]) % MOD; 
    }

    return ans;
}







int main(){

    int tt; cin >> tt;

    while(tt--){
        cin >> n >> m;


        fill(t,t+2*n+1,0);
        cnt.clear();



        

        vector<int> b;
        vector<int> freq;
        

        for(int i = 0; i < n; i++){
            int x; cin >> x;
            
            if(cnt.find(x) == cnt.end()){
                cnt[x] = 1;
                b.push_back(x);


            }
            else{
                cnt[x]++;
            }

        }

        sort(b.begin(),b.end());

        for(int i = 0; i < b.size(); i++){

            //cout << b[i] << "\n";
            t[i+n] = cnt[b[i]];

            //cout << t[i+n] << " ";
        }

        //6 7 8 9 10 11

        //cout << "\n";

        build();

       


        long long ans = 0;

        for(int i = 0; i + m-1 < b.size(); i++){
            if(b[i+m-1] - b[i] < m){

         

                
                
                ans = (ans + query(i,i+m)) % MOD;
            }
        }

        cout << ans << "\n";

        




    }
    


}