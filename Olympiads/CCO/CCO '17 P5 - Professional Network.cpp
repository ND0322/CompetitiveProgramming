#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 2e5+5;

typedef pair<int,int> pii;

int n;
pii a[MAXN];


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }

    sort(a+1,a+n+1);
    priority_queue<int,vector<int>,greater<int>> pq;



    int ans = 0;
    int r = n;

    //much better than mine with two pointers 
    for(int i = n; i >= 0; i--){
        
        while(r >= 1 && a[r].first == i){
            pq.push(a[r].second);
            r--;
        }

        while(pq.size() > n-i){
            ans += pq.top();
            pq.pop();
        }


        
    }

    cout << ans << "\n";


}