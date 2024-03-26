#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int main(){
    deque<double> q;

    int c[3]; cin >> c[0] >> c[1] >> c[2];

    for(int i = 0; i < 3; i++){
        double x; cin >> x;

        while(c[i]--) q.push_back(x);
    }

    double ans = 0;
    int cnt = 0;

    while(q.size()){
        ans += q.front();
        q.pop_front();

        cnt++;

        if(cnt == 3 && q.size()){
            q.pop_back();
            cnt = 0;
        }
    }

    
    cout << setprecision(2) << fixed << ans << "\n";



    
}