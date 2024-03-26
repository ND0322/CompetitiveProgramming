#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int a[6005], n, has[MAXN];



int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        has[a[i]]++;
    }

    int ans = 0;

    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){

            if(a[i] == a[j]){
                if(has[a[i]] < 3) continue;
                ans = max(ans, a[i] * 3);

            }


           
            if(has[max(a[i],a[j]) + abs(a[i] - a[j])]) ans = max(ans, a[i] + a[j] + max(a[i],a[j]) +  abs(a[i] - a[j]));
            if(min(a[i],a[j]) - abs(a[i] - a[j]) >= 0 && has[min(a[i],a[j]) - abs(a[i] - a[j])]) ans = max(ans, a[i] + a[j] + min(a[i],a[j]) -  abs(a[i] - a[j]));
        }
    }

    cout << ans << "\n";
}