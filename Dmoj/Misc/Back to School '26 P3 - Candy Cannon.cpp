#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
consider that removing the minimum exposes the next one in the sequence 
*/

const int MAXN = 2005;

int n, m, a[MAXN][MAXN];
int main(){
    cin >> n >> m;

    vector<int> b = {0};

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];

            b.push_back(a[i][j]);
        }
    }

    sort(b.begin(), b.end());

    int sa = 0;
    int sb = 0;

    for(int i = 1; i < b.size(); i += 2) sa += b[i];
    for(int i = 2; i < b.size(); i += 2) sb += b[i];

    if(sa == sb){
        cout << "TIE\n";
        return 0;
    }

    if(sa > sb){
        cout << "RED\n";
        return 0;
    }

    cout << "BLUE\n";
    
}