#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

//between the right and left of a local maximum
//take the longer one
//if it has odd length then a wins
//if it has even

int main(){
    int n; cin >> n;

    vector<int> a(n+3);

    for(int i = 1; i <= n; i++) cin >> a[i];

    pair<int,int> so = {1,1};
    set<pair<int,int>> best;

    int i = 1;

    while(i <= n){
        int l = i;
        while(i+1 <= n && a[i] <= a[i+1]) i++;

        if(i-l+1 == so.first){
            so.second++;
            best.insert({l,i});
        }
        else if(i-l+1 > so.first){
            so = {i-l+1, 1};
            best = {{l,i}};
        }
        i++;
    }

    vector<int> b(n+3);

    for(int i = 1; i <= n; i++) b[i] = a[n-i+1];

    i = 1;

    while(i <= n){
        int l = i;
        while(i+1 <= n && b[i] <= b[i+1]) i++;

        if(i-l+1 == so.first){
            so.second++;
            best.insert({n-i+1, n-l+1});
        }
        else if(i-l+1 > so.first){
            
            so = {i-l+1, 1};
            best = {{n-i+1,n-l+1}};
        }
        i++;
    }
    
    if(so.second > 2 || so.second == 1){
        cout << "0\n";
        return 0;
    }

   




    int l = 1e9;
    int cntl = 0;

    int r = 1;
    int cntr = 0;

    int ans = 0;

    


    for(int i = 1; i <= n; i++){

        if(i >= r){
            r = i;
            cntr = 0;

            while(a[r] > a[r+1] && r+1 <= n){
                r++;
                cntr++;
            }
        }
        if(a[i] > a[i-1] && a[i] > a[i+1]){
            if(cntl + 1 == so.first && cntr + 1 == so.first && so.first % 2) ans++;
        }
        
        if(a[i] > l){
            l = a[i];
            cntl++;
        }
        else{
            cntl = 1;
            l = a[i];
        }

        cntr--;
    }

    cout << ans << "\n";
}

