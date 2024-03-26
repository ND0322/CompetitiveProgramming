#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int n, pos;

/*
strat:
query the whole thing to find second largest
after you can easily find which side the largest is on of the second
then bsearch for the smallest r such that query(pos, r) is equal to second
*/

//4 5 3 1 2

int query(int l, int r){
    cout << "? " << l << " " << r<< "\n";
    int x; cin >> x;
    return x;
}

void solver(){
    int lo = pos+1;
    int hi = n;
    int ans = 0;

    while(lo <= hi){
        int mid = (lo+hi)>>1;

        if(query(pos, mid) == pos){
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }

    cout << "! " << ans << "\n";
}

void solvel(){
    //rightmost index so that query is still = pos

    int lo = 1;
    int hi = pos-1;
    int ans = 0;

    while(lo <= hi){
        int mid = (lo+hi)>>1;

        if(query(mid, pos) == pos){
            ans = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }

    cout << "! " << ans << "\n";
}
int main(){
    cin >> n;
    pos = query(1,n);

    if(pos == 1){
        solver();
        return 0;
    }
    if(pos == n){
        solvel();
        return 0;
    }

    int l = query(1,pos);
    
    if(l == pos){
        solvel();
    }
    else{
        solver();
    }


}