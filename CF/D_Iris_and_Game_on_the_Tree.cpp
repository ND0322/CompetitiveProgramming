#include <bits/stdc++.h>
#include <iostream>

using namespace std;


/*
substrings bro not subsequence
consider two cases
Case 1: the root is set
in this case 
ans will be number of leaves with opposite color
assume root is color 1
intuition is that after some alternations of blocks of 1 and 0s if the the thing matches the rt then they will be equal
for all ? leaves we simply do ceil(cnt/2) for obvious reasons
Case 2:
root is not set 
we should not waste a turn coloring the root
we will take turns dilly dallying with the non leaf ? 
floor if we have to waste a turn painting root
ceil if not 
*/

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        vector<int> deg(n+1);
        vector<int> col(n+1);

        for(int i = 0; i < n-1; i++){
            int x,y; cin >> x >> y;
            deg[x]++;
            deg[y]++;
        }

        for(int i = 1; i <= n;i++){
            char c; cin >> c;
            if(c == '0') col[i] = 0;
            if(c == '1') col[i] = 1;
            if(c == '?') col[i] = 2;
        }

        int leaves[3] = {0,0};
        int waste = 0;
        for(int i = 2; i <= n; i++){
            if(deg[i] == 1) leaves[col[i]]++;
            else if(col[i] == 2) waste++;
        }

        if(col[1] == 0){
            cout << leaves[1] + ceil(leaves[2]/2.0) << "\n";
            continue;
        }

        if(col[1] == 1){
            cout << leaves[0] + ceil(leaves[2]/2.0) << "\n";
            continue;
        }

        int ans = leaves[2];
        //root color is not obvious
        if(leaves[0] == leaves[1] && (waste&1)) ans++;
        cout << max(leaves[0], leaves[1]) +  ans/2<< "\n";
    }
}