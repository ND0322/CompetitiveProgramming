#include <bits/stdc++.h>
#include <iostream>

using namespace std;


//if some number appears twice in the first half there must be a number that appears twice in the second half

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n, k; cin >> n >> k;

        vector<int> freq(n+1);

        vector<int> a, b;

        for(int i = 0; i < n; i++){
            int x; cin >> x;

            freq[x]++;
        }

        for(int i = 0; i < n; i++){
            int x; cin >> x;
        }

        for(int i = 1; i <= n; i++){
            if(freq[i] == 2) a.push_back(i);
            if(!freq[i]) b.push_back(i);
        }

        vector<int> ans;
        vector<int> ansb;

        k <<= 1;

        while(k > 0 && a.size()){   
            ans.push_back(a.back());
            ans.push_back(a.back());

            a.pop_back();

            ansb.push_back(b.back());
            ansb.push_back(b.back());
            b.pop_back();

            k-=2;
        }


        for(int i = 1; i <= n && k > 0; i++){
            if(freq[i] == 1){
                ans.push_back(i);
                ansb.push_back(i);
                k--;
            }
        }

        for(int i : ans) cout << i << " ";
        cout << "\n";
        for(int i : ansb) cout << i << " ";
        cout << "\n";


    }
}