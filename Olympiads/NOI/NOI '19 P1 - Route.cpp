#include <bits/stdc++.h>
#include <iostream>
#include <deque>
#include <queue>


using namespace std;



//cht dp
//using dq for cht

typedef pair<int,int> pii;
typedef pair<pii,pii> edge;
typedef long double ld;



const int MAXN = 2e5+5;

int n,m,a,b,c;

deque<pii> cht[MAXN];
priority_queue<pii, vector<pii>, greater<pii>> pq[MAXN];
edge edges[MAXN];


//at edge i
//min over all j
//t = p[i] - q[j]
//tt = tot time
//At^2 + Bt + C + tt
//A (p[i] - q[j]) ^ 2 + B(p[i] - q[j]) + C + tt
//A (p[i] ^ 2 - 2*p[i] * q[j] + q[j]^2 ) + B(p[i] - q[j]) + c + tt
//Ap[i]^2 - A2*p[i] * q[j] + A * q[j]^2 + Bp[i] - Bq[j] + C + tt
//group things with j
//A * q[j] ^ 2 - 2A * q[j] * p[i] - B * q[j] + tt
//m = -2A * q[j] 
//b = A * q[j] ^ 2 - B * q[j] + tt
//not gonna explicitly store the lines to make sorting easier





ld intersect(pii l, pii ll){
    int i = l.first;
    int j = ll.first;

    int t1 = l.second;
    int t2 = ll.second;

    //both slopes would be 0
    if(!a) return (b*i + t1 >= b*j + t2) ? 0: MAXN;
   
    return ((ld)(a * i * i - b * i + t1) - (ld)(a * j * j - b * j + t2))/((ld)(-2 * a * j) - (ld)(-2 * a * i));

}

//station, line information
void insert(int s, pii x){
    while(cht[s].size() >= 2 && intersect(cht[s][cht[s].size() - 2], cht[s].back()) >= intersect(cht[s].back(), x)) cht[s].pop_back();
    
    cht[s].push_back(x);
    //cout << x.first << " " << x.second << "\n";
    
}

//station, time
long long query(int s, int t){
    //if(s == 2){
        //cout << cht[s][0].first << " " << cht[s][0].second << "\n";
        //cout << cht[s][1].first << " " << cht[s][1].second << "\n";
        //cout << intersect(cht[s][0], cht[s][1]) << "\n";
       
    //}
    
    while(cht[s].size() >= 2 && intersect(cht[s][0], cht[s][1]) <= t){
        //if(s == 2) cout << cht[s].front().first << " " << cht[s].front().second << "\n";
        cht[s].pop_front();
    }

    //cout << cht[s].front().first << " " << cht[s].front().second << "\n";

    int j = cht[s].front().first;

    //cout << j << " " << cht[s].front().second << "\n";

    
    return a * t * t - 2* a * j * t + a * j * j + b * t - b * j + c + cht[s].front().second;
}


int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> m >> a >> b >> c;

    for(int i = 0; i < m; i++) cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first.first >> edges[i].first.second;

    sort(edges, edges+m);

    cht[1].push_back({0,0});

    long long ans = 1e18;

    for(int i = 0; i < m; i++){
        int x = edges[i].second.first;
        int y = edges[i].second.second;
        long long p = edges[i].first.first;
        long long q = edges[i].first.second;

        while(!pq[x].empty() && pq[x].top().first <= p){
            pii l = pq[x].top();
            pq[x].pop();

            insert(x, l);
            //if(x == 2) cout << l.first << " " << l.second << "\n";
        }



        if(cht[x].empty()) continue;

        //if(x == 2)for(pii l : cht[x]) cout << l.first << " " << l.second << "\n";
        //ong long res = query(x, p);
        //cout << x << " " << res << "\n";

		
		    
		
		
		
        long long res = query(x,p);

        


        //edge brings to n consider answer
        if(y == n) ans = min(ans, res + q);
        //cout << q << " " << res << "\n";
        pq[y].push({q, res});

        

    }

    cout << ans << "\n";



}

