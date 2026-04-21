#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;

int n, sz[5], cnt[3][3], tmp[3][3];
char a[MAXN<<1];

/*
we know what the length of the blocks are
either ABC or ACB

rotate the starting point of the block 
*/

int calc(){
    int res = 0;

    for(int i =0; i < 3; i++){
        for(int j =0; j < 3; j++) tmp[i][j] = cnt[i][j];
    }
    
    //B and As

    int swp = min(tmp[0][1], tmp[1][0]);
    tmp[0][1] -= swp;
    tmp[1][0] -= swp;

    res += swp;

    //still a B in the A section
    if(tmp[0][1]){
        //swap B with A in C section
        tmp[2][0] -= tmp[0][1];
        tmp[2][1] += tmp[0][1];
        res += tmp[0][1];
        tmp[0][1] = 0;
    }


    //if there are still A in B we will deal with them in this part

    swp = min(tmp[0][2], tmp[2][0]);


    tmp[0][2] -= swp;
    tmp[2][0] -= swp;

    res += swp;


    if(tmp[0][2]){
        //swap C with A in B section

        tmp[1][0] -= tmp[0][2];
        tmp[1][2] += tmp[0][2];
        res += tmp[0][2];
        tmp[0][2] = 0;
    }

    res += tmp[1][2];
    return res;

}
int main(){
    string s; cin >> s;

    n = s.size();

    


    for(int i = 1; i <= n; i++){
        a[i] = a[i+n] = s[i-1];
        sz[a[i] - 'A']++;
    }



    for(int i = 1; i<=sz[0]; i++) cnt[0][a[i] - 'A']++;
    for(int i = sz[0]+1; i<=sz[0] + sz[1]; i++) cnt[1][a[i] - 'A']++;
    for(int i = sz[1]+sz[0]+1; i<=sz[0] + sz[1] + sz[2]; i++) cnt[2][a[i] - 'A']++;

    int ans = calc();
        
    for(int i = 2; i <= n; i++){
        //remove contribution from left


        cnt[0][a[i-1] - 'A']--;
        cnt[1][a[i+sz[0] - 1] - 'A']--;
        cnt[2][a[i +sz[0] + sz[1] - 1] - 'A']--;

        cnt[0][a[i+sz[0]-1] - 'A']++;
        cnt[1][a[i + sz[0] + sz[1]-1] - 'A']++;
        cnt[2][a[i + sz[0] + sz[1] + sz[2]-1] - 'A']++;

        ans = min(ans, calc());
    }

    sz[0] = sz[1] = sz[2] = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) cnt[i][j] = 0;
    }

    for(int i = 1; i <= n; i++){
        if(s[i-1] == 'B') a[i] = a[i+n] = 'C';
        else if(s[i-1] == 'C') a[i] = a[i+n] = 'B';
        else a[i] = a[i+n] = 'A';

        sz[a[i] - 'A']++;
    }

    for(int i = 1; i<=sz[0]; i++) cnt[0][a[i] - 'A']++;
    for(int i = sz[0]+1; i<=sz[0] + sz[1]; i++) cnt[1][a[i] - 'A']++;
    for(int i = sz[1]+sz[0]+1; i<=sz[0] + sz[1] + sz[2]; i++) cnt[2][a[i] - 'A']++;

    ans = min(ans, calc());
        
    for(int i = 2; i <= n; i++){
        //remove contribution from left


        cnt[0][a[i-1] - 'A']--;
        cnt[1][a[i+sz[0] - 1] - 'A']--;
        cnt[2][a[i +sz[0] + sz[1] - 1] - 'A']--;

        cnt[0][a[i+sz[0]-1] - 'A']++;
        cnt[1][a[i + sz[0] + sz[1]-1] - 'A']++;
        cnt[2][a[i + sz[0] + sz[1] + sz[2]-1] - 'A']++;

        ans = min(ans, calc());
    }

    cout << ans << "\n";





    
}