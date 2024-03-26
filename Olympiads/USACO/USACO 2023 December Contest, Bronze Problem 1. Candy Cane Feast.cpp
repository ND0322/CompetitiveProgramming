#include <bits/stdc++.h>
#include <iostream>

using namespace std;



const int MAXN = 2e5+5;

long long n, m, a[MAXN], b[MAXN], ans[MAXN];

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    for(int i = 0; i < m; i++){
        long long big = a[0];
        a[0] += min(a[0], b[i]);


        for(int j = 1; j < n; j++){
            if(a[j] > big && b[i] > big){
                int tmp = a[j];
                a[j] += min(a[j],b[i])-big;
                big = tmp;
            }

            if(b[i] <= big) break;
        } 
    }

    for(int i = 0; i < n; i++) cout << a[i] << "\n";

    
}