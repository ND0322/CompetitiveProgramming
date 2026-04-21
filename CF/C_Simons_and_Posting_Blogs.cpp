#include <bits/stdc++.h>
#include <iostream>

using namespace std;


/*
reverse the process 

sort all reverse array lexicograpgical
add value to ans if it is not in visited set 

*/

bool cmp(vector<int> a, vector<int> b){

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for(int i = 0; i < min(a.size(), b.size()); i++){
        if(a[i] < b[i]) return 1;
        else if(a[i] > b[i]) return 0;
    }

    return a.size() < b.size();
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<vector<int>> a(n+1);

        for(int i = 1; i <= n; i++){
            int l; cin >> l;

            for(int j = 0; j < l; j++){
                int x; cin >> x;
                a[i].push_back(x);
            }
        }


        sort(a.begin(), a.end(), cmp);


        set<int> used;

        vector<int> ans;

        //we should go one by one for each ai
        //the lowest index of each ai, that doesnt contraditc a previous ai
        

        for(auto i : a){
            for(int j = i.size()-1; j >= 0; j--){
                cout << i[j] << " ";
                if(used.find(i[j]) != used.end()) continue;

                ans.push_back(i[j]);
                used.insert(i[j]);

            }

            cout << "\n";
        }

        for(int i : ans) cout << i << " ";
        cout << "\n";
    }


}