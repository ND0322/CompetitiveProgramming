#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int a[5005];

vector<int> save;
int main(){
    int k; cin >> k;
    

    for(int i = 2; i <= 5000; i++) a[i] = a[i-1] + i-1;
    for(int i = 5000; i >= 2; i++){
    
        while(k >= a[i]){
            save.push_back(i);
            k-=a[i];  
        }
    }

    /*

    vector<pair<int,int>> edges;

    int cnt = 0;

    for(int i : save){
        for(int j = 1; j < i; j++) edges.push_back({cnt+j, cnt+j+1});
        edges.push_back({cnt+i, cnt+1});
        cnt+=i;
    }

    for(pair<int,int> p : edges) cout <<p.first << " " << p.second << "\n";


    */

    


}