#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
one chunk of all perfect squares

one chunk for each unique non perfect sqaure we find 

each subarray contributes to only one k

and split by sign 


we can non perfect square groups that can work with each other 

let prime factors be p1 p2 p3 p4


all p1 must have either odd or even parity 
*/


int main(){
    int n; cin >> n;

    vector<int> a(n+1);
    vector<int> b(n+1);

    for(int i = 1; i <= n; i++) cin >> a[i];


    vector<map<int,int>> cnt(n+1, map<int,int>());

    vector<int> fact;

    for(int i = 1; i <= n; i++){

        if(a[i] < 0){
            b[i] = 1;
            a[i] = -a[i];
        }
        for(int j = 2; j * j <= a[i]; j++){
            while(!(a[i] % j)){
                cnt[i][j]++;
                a[i] /= j;
                fact.push_back(j);
            }
        }

        if(a[i] > 1){
            cnt[i][a[i]]++;

            fact.push_back(a[i]);
        }
    }

    map<int,int> pos;

    fact.resize(distance(fact.begin(), unique(fact.begin(), fact.end())));

    sort(fact.begin(), fact.end());
    for(int i = 0; i < fact.size(); i++){
        pos[fact[i]] = i+1;
    }

    for(int i = 1; i <= n; i++){


        for(auto j : cnt[i]) b[i] += ((j.second & 1)<<pos[j.first]);

    }


    vector<int> ans(n+1);

    for(int i = 1; i <= n; i++){
        set<int> s;

        for(int j = i; j <= n; j++){
            s.insert(b[j]);
            ans[s.size()]++;
        }
    }

    for(int i =1 ; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";



    
}