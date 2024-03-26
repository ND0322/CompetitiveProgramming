#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e4+5;

int n;

int query(int x, int y){
    cout << "0 " << x << " " << y << "\n";
    int x; cin >> x;
    return x;
}

void update(int x, int y){
    cout << "1 " << x << " " << y << "\n";
}

int main(){
    cin >> n;
    for(int i = 1;  i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(!query(i,j)){
                update(i,j);
                break;
            }

        }   
    }
}