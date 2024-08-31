#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>

using namespace std;

const int MAXN = 1e5+5;

int n, q;

double h[MAXN];

struct Node{
    long double sm[5], lz[5];
} st[6005];

/*
complementary counting
find sum of area bounded by the lines and water and subtract from the water stuff
4 cases
Case 1: water is above the ground
ground area will min(h[i], h[i+1]) + (max(h[i], h[i+1]) - min(h[i], h[i+1]))/2
Case 2: water is underground
ground area is height of water 
Case 3: Water is between two points of the floor + h[i] < h[i+1]
denote water height as l
intersection is at x = (l - h[i])/(h[i+1] - h[i]) + i
area = l - (l-h[i]) * x
area = l - (l-h[i]) * ((l - h[i])/(h[i+1] - h[i]) + i)
*/

void pushdown(int node, int l, int r, int t){
    if(st[node].lz[t]){
        st[node<<1].lz[t] += st[node].lz[t];
        st[node<<1|1].lz[t] += st[node].lz[t];

        if(l != r){
            int mid = (l+r)>>1;
            st[node<<1].sm[t] += st[node].lz[t] * (mid - l + 1);
            st[node<<1|1].sm[t] += st[node].lz[t] * (r-mid);
        }

        st[node].lz[t] = 0;
    }
}

void update(int node, int l, int r, int x, int y, double v, int t){
    if(x > r || y < l) return;
    if(x <= l && y >= r){
        st[node].lz[t] += v;
        st[node].sm[t] += (r-l+1) * v;
        return;
    }
    int mid = (l+r)>>1;
    pushdown(node, l, r, t);
    update(node<<1,l, mid, x,y,v, t);
    update(node<<1|1, mid+1, r, x, y, v, t); 
    st[node].sm[t] = st[node<<1].sm[t] + st[node<<1|1].sm[t];
}

double query(int node, int l, int r, int x, int y, int t){
    if(x > r || y < l) return 0;
    if(x <= l && y >= r) return st[node].sm[t];
    pushdown(node, l, r, t);
    int mid = (l+r)>>1;
    return query(node<<1, l, mid, x, y, t) + query(node<<1|1, mid+1,r,x,y,t);
}

void point(int i, bool sn){
    if(i+1 >= n) return;
    double height = min(h[i], h[i+1]);

    //above
    update(1,0,1000, max(h[i], h[i+1]) + (height == max(h[i], h[i+1])), 1000, pow(-1, sn) * (height + (max(h[i], h[i+1]) - height) / 2.0), 0);
    //below
    update(1,0,1000, 0, height, pow(-1, sn), 1);

    

    double px = min(h[i], h[i+1]);    

    double m = max(h[i], h[i+1]) - height;

    //l - h[i] = m(x - i)
    //(l-h[i])/m + i = x
    //l - ((l-h[i])/m+i) * (l-h[i]))/2

    if(max(h[i], h[i+1]) > height+1){
        update(1,0, 1000, height+1, max(h[i], h[i+1])-1, pow(-1, sn) * (-1/(2*m)), 2);
        update(1,0, 1000, height+1, max(h[i], h[i+1])-1, pow(-1, sn) * (1 + px/m ), 3);
        update(1,0, 1000, height+1, max(h[i], h[i+1])-1, pow(-1, sn) * (-(px * px / (2 * m))), 4);
    }
    

}

int main(){
    cin >> n >> q;

    for(int i = 0; i < n; i++) cin >> h[i];

    for(int i = 0; i < n-1; i++) point(i, 0);


    while(q--){
        char c; cin >> c;

        if(c == 'Q'){
            double l; cin >> l;
            double ans = l * l * query(1, 0, 1000, l,l,2) + l * query(1, 0, 1000, l,l, 3) + query(1,0, 1000, l,l, 4);
            ans += l * query(1, 0, 1000, l,l, 1);
            ans += query(1,0, 1000, l,l, 0);
            cout << setprecision(3) << fixed << l * (n-1) - ans << "\n";
        }
        else{
            int i, x; cin >> i >> x;

            point(i, 1);
            if(i != 0) point(i-1, 1);
            h[i] = x;
            point(i, 0);
            if(i != 0) point(i-1, 0);


        }
    }
}