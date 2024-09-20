#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 3e5+5;

int n, a[MAXN], pref[20], pmx[20], suf[20], smx[20];

/*
3 5 1 2 6 8 7

consider precomputation of the prefix and suffix for every power of 2

suffix will look like
21 1
for indices 4 and 6 respectively 

calculating these takes log n * (n log n) time total or smth like that
consider what happens when we insert an element at position 4 for example

3 5 1 4 [2 6 8 7]

the right suffix will remain the same 
the prefix at 2 will remain the same 
no we have to combine the 4 with at most log n neighbors 

4-1 = 3
3^2 + 2^2 + 1^2 = 14 

what happens if the suffix isnt a perfect power of two?

3 4 5 1 2 6 8 7

this takes like log n time 
*/

int main(){
    cin >> n;

    set<int> vals;
    for(int i = 1; i <= n; i++) vals.insert(i);

    for(int i = 1; i < n; i++){
        cin >> a[i];
        vals.erase(a[i]);
        pmx[i] = max(pmx[i-1], a[i]);
    }


    int k = *vals.begin();

    
    for(int i = 1; i < log2(n); i++){
        vector<int> cur;

        for(int j = 1; j <= (1<<i); j++) cur.push_back(a[j]);

        int sm = 0;
        vector<int> tmp;
        while(cur.size() > 1){
            for(int j = 0; j < cur.size(); j += 2){
                sm += abs(cur[j] - cur[j+1]) * abs(cur[j] - cur[j+1]);
                tmp.push_back(max(cur[j], cur[j+1]));
            }

            cur.swap(tmp);
            tmp.clear();
        }

        pref[i] = sm;
        pmx[i] = cur[0];
    }

    
    for(int i = 1; i < log2(n); i++){
        vector<int> cur;

        for(int j = n-1; j >= n - (1<<i); j--) cur.push_back(a[j]);


        int sm = 0;
        vector<int> tmp;
        while(cur.size() > 1){
            for(int j = 0; j < cur.size(); j += 2){
                sm += abs(cur[j] - cur[j+1]) * abs(cur[j] - cur[j+1]);
                tmp.push_back(max(cur[j], cur[j+1]));
            }

            cur.swap(tmp);
            tmp.clear();
        }

        suf[i] = sm;
        smx[i] = cur[0];
    }

    

    for(int i = 1; i <= n; i++){
        int block = ceil(log2(i));

        if(i == 1 || i == 2){

        }

        vector<int> cur;

        bool flag = 0;

        cout <<i << " " << min(n - (1<<((int)log2(n) - block + 1)), n) << "\n";
        for(int j = max((1<<(block-1)), 0)+1; j <= min(n - (1<<((int)log2(n) - block + 1)), n); j++){
            if(j == i){
                flag = 1;
                cur.push_back(k);
            }
            else cur.push_back(a[j-flag]);
        }

        int sm = 0;
        vector<int> tmp;
        while(cur.size() > 1){
            for(int j = 0; j < cur.size(); j += 2){
                sm += abs(cur[j] - cur[j+1]) * abs(cur[j] - cur[j+1]);
                tmp.push_back(max(cur[j], cur[j+1]));
            }

            cur.swap(tmp);
            tmp.clear();
        }

        if(i <= n/2){
            sm += pref[block-1];
            sm += abs(pmx[block-1] - cur[0]) * abs(pmx[block-1] - cur[0]);
            int v = max(pmx[block-1], cur[0]);
            sm += abs(smx[(int)log2(n) - block + 1] - v) * abs(smx[(int)log2(n) - block + 1] - v);
            sm += suf[(int)log2(n) - block + 1];
        }
        else{
            sm += suf[(int)log2(n) - block + 1];
            sm += abs(smx[(int)log2(n) - block + 1] - cur[0]) * abs(smx[(int)log2(n) - block + 1] - cur[0]);
            cout << smx[(int)log2(n) - block + 1] << " " << cur[0] << "\n";
            int v = max(smx[(int)log2(n) - block + 1], cur[0]);
            sm += pref[block-1];
            sm += abs(pmx[block-1] - v) * abs(pmx[block-1] - v);
            cout << i << " " << sm  << " " << suf[((int)log2(n) - block + 1)] << " " <<pref[block-1] << "\n";

        }

        
    }
    

     
    


}