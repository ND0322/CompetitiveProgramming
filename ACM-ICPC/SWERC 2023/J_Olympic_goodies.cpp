#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n, p, in[MAXN];

int main(){
    cin >> n >> p;

    for(int i = 0; i < n-1; i++){
        int x,y; cin >> x >> y;

        in[x]++;
        in[y]++;
    }

    int cnt = 0;

    for(int i = 1; i <= n-1; i++) cnt += (in[i] == 1);

    if(!(p % cnt)){
        cout << (p/cnt) * 2 << "\n";
        return 0;
    }

    if(p % cnt == 1){
        cout << (p/cnt)*2+1 << "\n";
        return 0;
    }


    cout << (p/cnt)*2+2 << "\n";
}