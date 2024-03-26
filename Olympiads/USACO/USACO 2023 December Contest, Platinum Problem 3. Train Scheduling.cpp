#include <bits/stdc++.h>    
#include <iostream>

using namespace std;

const int MAXN = 5005;



int n;
long long t, dp[MAXN];

//cost of first i such that the ith train leaves on time

pair<long long, bool> a[MAXN];
//a[MAXN], b[MAXN];

//todo list
//do the dishes
//walk the dog
//lines
//finish this problem
//wrap presents



int main(){
    cin >> n >> t;

    for(int i = 0; i < n; i++){
        char c; cin >> c;

        long long x; cin >> x;
        a[i] = {x,(c=='A')};
    }

    sort(a,a+n);

    for(int i = n-1; i >= 0; i--){
        long long lt[2];
        lt[a[i].second] = a[i].first;
        lt[!a[i].second] = -1e18;
        dp[i] = 1e18;
        long long cost = 0;

        for(int j = i+1; j <= n; j++){
            //if(i == 0) cout << j << " " << lt[0] << " " << lt[1] << " " << cost << "\n";
            if(lt[!a[j].second] + t <= a[j].first || j == n){
                //if(i == 0) cout << j << "\n";
                dp[i] = min(dp[i], cost + dp[j]);
                lt[a[j].second] = max(a[i].first + t, a[j].first);
            }
            else{
                lt[a[j].second] = max(lt[!a[j].second] + t, a[j].first);
                cost += lt[a[j].second] - a[j].first;
            }
            
            
        }
    }

    cout << dp[0] << "\n";



    



    /*
    int n = 0;
    int m = 0;

    for(int l = 0; l < N; l++){
        char t; cin >> t;

        long long x; cin >> x;

        if(t == 'A') a[n++] = x;
        else b[m++] = x;
    }

    sort(a,a+n);
    sort(b,b+m);
    */

    



    


    
}