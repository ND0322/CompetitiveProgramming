#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 5e4+5;

int n, a[MAXN], b[MAXN];

bool have[MAXN<<1];

int main(){
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        have[a[i]] = 1;
    }

    int i =0;

    for(int j = 1; j <= 2*n; j++){
        if(!have[j]){
            b[i] = j;
            i++;
        }
    }

    sort(b, b+n);
    reverse(b,b+n);
    reverse(b, b+n/2);
    sort(a, a+n/2);

    
    int j = 0;
    int ans = 0;

    for(int i = 0; i < n>>1; i ++){
        while(b[j] < a[i]) j++;
        if(j < n>>1){
            ans++;
            j++;
        }
    }

    sort(a+n/2, a+n);
    reverse(a+n/2, a+n);



    j = n>>1;

    for(int i = n>>1; i < n; i++){
        while(b[j] > a[i]) j++;
        if(j < n){
            j++;
            ans++;
        }
    }

    cout << ans << "\n";


}