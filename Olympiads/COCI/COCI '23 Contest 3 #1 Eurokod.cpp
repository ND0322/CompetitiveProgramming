#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 55;

int n;

pair<int,int> a[MAXN];

int main(){
    cin >> n;

    for(int i = n; i >= 1; i--){
        int x; cin >> x;

        a[i] = {i,x};
    }

    vector<pair<int,int>> balls;

    for(int i = 1; i <= n; i++){
        int x; cin >> x;

        balls.push_back({x,i});
    }

    sort(balls.begin(), balls.end());

    for(int i = n; i >= 1; i--){
        a[balls[i-1].second].second += i;
    }

    sort(a+1, a+n+1);





    
}