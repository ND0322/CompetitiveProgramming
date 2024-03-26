#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int long long

const int MAXN = 2e5+5;

int n, a[MAXN];


using namespace std;


struct node_ap
{
	int sum, lazy, lazy_ap;
	
	node_ap() {sum = 0; lazy = 0; lazy_ap = 0;}
	node_ap(int val)
	{
		sum = val;
		lazy = 0;
		lazy_ap = 0;
	}
} tr[MAXN<<2];

node_ap temp, broken;

node_ap merge(node_ap l, node_ap r)
{
	temp.sum = l.sum + r.sum;
	temp.lazy = 0;
	temp.lazy_ap = 0;
	return temp;
}



void update(int l, int r, int idx)
{
    if(tr[idx].lazy)
    {
        tr[idx].sum += (r - l + 1) * tr[idx].lazy;

        if(l != r)
        {
            tr[2 * idx + 1].lazy += tr[idx].lazy;
            tr[2 * idx + 2].lazy += tr[idx].lazy;
        }

        tr[idx].lazy = 0;
    }	

    if(tr[idx].lazy_ap)
    {
        int mid = (l + r) >> 1;
        tr[idx].sum += ((r - l + 1) * (r - l + 2) / 2) * tr[idx].lazy_ap;

        if(l != r)
        {
            tr[2 * idx + 1].lazy_ap += tr[idx].lazy_ap;
            tr[2 * idx + 2].lazy_ap += tr[idx].lazy_ap;
            tr[2 * idx + 2].lazy += tr[idx].lazy_ap * (mid - l + 1);
        }

        tr[idx].lazy_ap = 0;
    }
}

void init(int l, int r, int idx)
{
    if(l == r)
    {
        tr[idx] = node_ap(a[l]);
        return;
    }

    int mid = (l + r) >> 1;
    init(l, mid, 2 * idx + 1);
    init(mid + 1, r, 2 * idx + 2);

    tr[idx] = merge(tr[2 * idx + 1], tr[2 * idx + 2]);
}	
	
void update(int qL, int qR, int val, int prog, int l, int r, int idx)
{
    update(l, r, idx);

    if(qL > r || l > qR)
        return;

    if(qL <= l && r <= qR)
    {
        tr[idx].lazy += val + (l - qL) * prog;
        tr[idx].lazy_ap += prog;
        update(l, r, idx);
        return;
    }

    int mid = (l + r) >> 1;
    update(qL, qR, val, prog, l, mid, 2 * idx + 1);
    update(qL, qR, val, prog, mid + 1, r, 2 * idx + 2);

    tr[idx] = merge(tr[2 * idx + 1], tr[2 * idx + 2]);
}

node_ap query(int qL, int qR, int l, int r, int idx)
{
    update(l, r, idx);

    if(l > qR || r < qL)
        return broken;

    if(qL <= l && r <= qR)
        return tr[idx];

    int mid = (l + r) >> 1;
    return merge(query(qL, qR, l, mid, 2 * idx + 1), query(qL, qR, mid + 1, r, 2 * idx + 2));
} 






int32_t main(){
    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];

    long long ans = 0;

    init(0,n-1,0);
    
    

    for(int i = 0; i < n; i++){
        
        ans += abs(query(i,i, 0, n-1, 0).sum);

        int tmp = -query(i,i, 0, n-1, 0).sum;

        update(i, n-1, 0, tmp, 0, n-1, 0);
    }



    cout << ans << "\n";
}