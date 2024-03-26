#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 45;

int n,m, cnt, rebuild[MAXN];

string A[MAXN], B[MAXN];



bool solve(string a, string b, int depth){
    if(depth > m) return false;

    if(a.size() && a == b){
        cnt = depth;
        return true;
    }

    for(int i = 0; i < n; i++){
        if(solve(a+A[i], b + B[i], depth+1)){
            rebuild[depth] = i+1;
            return true;
        }
    }

    return false;

    
}


int main(){

    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    
    cin >> m >> n;

    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < n; i++) cin >> B[i];

    if(!solve("", "", 0)){
        cout << "No solution.\n";
        return 0;
    }

    cout << cnt << "\n";

    for(int i = 0; i < cnt; i++){
        cout << rebuild[i] << "\n";
    }



}



