#include <bits/stdc++.h>
#include <iostream>

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")

using namespace std;

//it always be good if no factor > i
//each number can only be good for so long 

const int MAXN = 1e6+5;

int n, a[MAXN], st[MAXN<<2];

//solving
//https://dmoj.ca/problem/bsfast

void build(int node, int l, int r){
    if(l == r){
        st[node] = a[l];
        return;
    }

    int mid = (l+r)>>1;
    build(node<<1, l,mid);
    build(node<<1|1, mid+1, r);
    st[node] = min(st[node<<1], st[node<<1|1]);
}

void update(int node, int l, int r, int i, int val){
    if(l == r){
        st[node] = val;
        return;
    }

    int mid = (l+r)>>1;
    if(i <= mid) update(node<<1, l, mid, i, val);
    else update(node<<1|1, mid+1,r,i,val);
    st[node] = min(st[node<<1], st[node<<1|1]);
}

int query(int node, int l, int r, int x, int y, int k){
    if(l == x && r == y && st[node] >= k) return -1;
    if(l == r) return l;

    int mid = (l+r)>>1;
    if(y <= mid) return query(node<<1, l, mid, x, y, k);
    else if(x > mid) return query(node<<1|1, mid+1, r, x, y, k);
    else{
        int res = query(node<<1, l , mid,x, mid, k);
        return (res != -1 ? res :  query(node<<1|1, mid+1 , r,mid+1, y, k));
    } 
}

int f(int n) {
  
    // Initialize the maximum prime factor variable
    int maxPrime = -1;

    // Check for factors of 2
    while (n % 2 == 0) {
        maxPrime = 2;
        n >>= 1;  
    }

    // Check for factors of 3
    while (n % 3 == 0) {
        maxPrime = 3;
        n = n / 3;
    }

    // Check for odd factors starting from 5 and 
  // incrementing by 6 (i and i+2)
    for (int i = 5; i * i <= n; i += 6) {
        while (n % i == 0) {
            maxPrime = i;
            n = n / i;
        }
        while (n % (i + 2) == 0) {
            maxPrime = i + 2;
            n = n / (i + 2);
        }
    }

   // If n is still greater than 4, it is a 
  // prime number
    if (n > 4)
        maxPrime = n;

    return maxPrime;
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n;

    //i <= min(l,r)

    for(int i = 1; i <= n; i++){
        cin >> a[i];

        a[i] = f(a[i]);
        
        a[i] = i-a[i]+1;
    }

    build(1,1,n);



    long long ans = 0;

    for(int i = 1; i <= n; i++){

        
        ans += (query(1,1,n,i,n,i) == -1 ? n+1 : query(1,1,n,i,n,i)) -i;
    }

    cout << ans << "\n";


}