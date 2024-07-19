#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 5005;
const int MOD = 1e6+3;

int n, a[MAXN], dp[MAXN];

//check all lights first with bsearch
//first point where projected r is less than current r
//then stuff with heavy
//sweep from r to l

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    dp[n+1] = 1;
    for(int i = n; i >= 1; i--){

        set<int> op;
        set<int> done;
        set<int> no; 

        //start with heavy
        bool sn = 0;
        for(int j = i; j <= n; j++){
            if(no.find(a[j]) != no.end()) break;
            if(!sn){
                if(op.find(a[j]) != op.end()){
                    op.erase(a[j]);
                    done.insert(a[j]);
                }
                else if(done.find(a[j]) == done.end()) op.insert(a[j]);
                

            }
            else{
                if(done.find(a[j]) != done.end() || op.find(a[j]) != op.end()) break;
                no.insert(a[j]);
            }

            if(op.empty()) dp[i] = (dp[j+1] + dp[i]) % MOD;

            sn = !sn;
        }

        //cout << i << " " << dp[i] << "\n";     

        sn = 1;
        op.clear();
        done.clear();
        no.clear();

        for(int j = i; j <= n; j++){
            if(no.find(a[j]) != no.end()) break;
            if(!sn){
                if(op.find(a[j]) != op.end()){
                    op.erase(a[j]);
                    done.insert(a[j]);
                }
                else if(done.find(a[j]) == done.end()) op.insert(a[j]);

            }
            else{
                if(done.find(a[j]) != done.end() || op.find(a[j]) != op.end()) break;
                no.insert(a[j]);
                
            }

            if(op.empty()) dp[i] = (dp[j+1] + dp[i]) % MOD;

            sn = !sn;
        }

        //cout << i << " " << dp[i] << "\n";     
    }

    cout << dp[1] << "\n";
}