#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//good[i] will be if the pair i and i+1 is good or bad

const int MAXN = 3e5+5;

int n,q, a[MAXN], id[MAXN], cnt;

bool bad[MAXN];

int main(){
    cin >> n >> q;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        id[a[i]] = i;
    }

    for(int i = 0; i < n; i++){
        bad[i] = (a[i] > a[(i+1)%n]);
        cnt+= bad[i];
    }

    //cout << cnt << "\n";

    while(q--){
        int x,y; cin >> x >> y;

        cnt -= bad[(id[x]+n-1)%n];
        cnt -= bad[id[x]];
        cnt -= bad[(id[y]+n-1)%n];
        cnt -= bad[id[y]];


        if(max(id[x], id[y]) == n-1 && min(id[x], id[y]) == 0) cnt += bad[n-1];
        if((min(id[x], id[y]) + 1) % n == max(id[x], id[y])) cnt += bad[min(id[x],id[y])];
        

        

        bad[(id[x]+n-1)%n] = 0;
        bad[id[x]] = 0;
        bad[(id[y]+n-1)%n] = 0;
        bad[id[y]] = 0;

        //cout << cnt << "\n";

        swap(a[id[x]], a[id[y]]);
        swap(id[x], id[y]);

        //for(int i = 0; i < n; i++) cout << a[i] << " ";
        //cout << "\n";

        


        bad[id[x]] = (a[id[x]] > a[(id[x]+1)%n]);
        bad[(id[x]+n-1)%n] = (a[(id[x]+n-1)%n] > a[id[x]]);
        bad[id[y]] = (a[id[y]] > a[(id[y]+1)%n]);
        bad[(id[y]+n-1)%n] = (a[(id[y]+n-1)%n] > a[id[y]]);

        //cout << id[x] << " " << id[y] << "\n";

        cnt += bad[id[x]];
        cnt += bad[(id[x]+n-1)%n];
        cnt += bad[id[y]];
        cnt += bad[(id[y]+n-1)%n];

        if(max(id[x], id[y]) == n-1 && min(id[x], id[y]) == 0) cnt -= bad[n-1];
        if((min(id[x], id[y]) + 1) % n == max(id[x], id[y])) cnt -= bad[min(id[x],id[y])];

        //for(int i = 0; i < n; i++) cout << bad[i] << " ";
        //cout << "\n";

        //cout << cnt << "\n";

        cout << (cnt == 1 ? "DA\n" : "NE\n");
    }




    
}