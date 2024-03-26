#include <bits/stdc++.h>
#include <iostream>


using namespace std;

const int MAXN = 2005;



int n,k, a[MAXN], b[MAXN];

bool used[MAXN];



int main(){
    cin >> n >> k;

    

    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        a[i] += k;
    }
    sort(a,a+n);
    sort(b,b+n);

    long long ans = 0;

    for(int i = 0; i < n; i++){
        pair<int,int> balls = {1e9,n};
        bool flag = 0;
        for(int j = 0; j < n; j++){
            if(a[j] > b[i]){
                used[j] = !flag;
                flag = 1;
                continue;
                
            }
            if(used[j]) continue;
            
            cout << i << " " << j << " " << ceil((b[i]-a[j])/(double)k) << "\n";
            balls = min(balls, {ceil((b[i]-a[j])/(double)k),j});
            ans += ceil((b[i]-a[j])/(double)k);
            a[j] += k * ceil((b[i]-a[j])/(double)k);
        }
        
        if(!flag) used[balls.second] = 1;
    }
   

    cout << ans << "\n";


}