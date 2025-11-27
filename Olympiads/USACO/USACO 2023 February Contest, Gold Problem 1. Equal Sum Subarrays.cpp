#include <bits/stdc++.h>
#include <iostream>

using namespace std;


const int MAXN = 5e5+5;

int a[MAXN], n;

vector<pair<long long,pair<int,int>>> sms;

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++){
        int sm = 0;
        for(int j = i; j <= n; j++){
            sm += a[j];
            sms.push_back({sm, {i, j}});
        }
    }

    sort(sms.begin(), sms.end());

    for(int i = 1; i <= n; i++){
        vector<long long> no, yes;

        for(auto j : sms){
            if(i >= j.second.first && i <= j.second.second) yes.push_back(j.first);
            else no.push_back(j.first);
        }

        int r = 0;
        long long mn = 1e18;
        for(int j = 0; j < yes.size(); j++){
            while(r < no.size() && (j == yes.size()-1 || abs(yes[j] - no[r]) <= abs(yes[j+1] - no[r]))){
                mn = min(mn, abs(yes[j] - no[r]));
                r++;
            }
        }

        cout << mn << "\n";
        
    }

  
    
}