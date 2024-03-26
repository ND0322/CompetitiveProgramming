#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 4005;

int n, a[MAXN];

set<int> s;

//check for ap



int main(){
    cin >> n;

    bool cnt = 0;

    for(int i = 1;i <= n; i++){
        cin >> a[i];
        cnt ^= (a[i] & 1);
        s.insert(a[i]);
    }

    if(n == 2){
        if(cnt) cout << "1\n";
        else cout << "2\n";
        return 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if(s.find(max(a[i],a[j]) + max(a[i],a[j]) - min(a[i],a[j])) != s.end()){
                cout << "3\n";
                return 0;
            }
        }
    }

    cout << "2\n";
    


}
