#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <set>

using namespace std;

const int MAXN = 2e5+5;

int q, n, id[MAXN], cnt = 2, dist[MAXN<<1], ans[MAXN<<1], cback[MAXN];

map<int,set<int>> cx, cy;

map<int,map<int,int>> ind, nw;

pair<int,int> inp[MAXN], nxt[MAXN];






//calc shortest path stuff
//order the points in circular order and map old values to new and vice versa
//for some update all new values between l and r will be updated
//for each old value lookup the sum of the new value
//bsearch for last sub

//keeping information about the line segments to help with impl

int main(){
    cin >> q >> n;

    for(int i = 1; i <= n; i++){
        cin >> inp[i].first >> inp[i].second;
        cx[inp[i].first].insert(inp[i].second);
        cy[inp[i].second].insert(inp[i].first);
        ind[inp[i].first][inp[i].second] = i;
    }

    //for(int i : cx[1]) cout << i << "\n";

    id[1] = 1;
    nw[inp[1].first][inp[1].second] = 1;

    set<pair<int,int>> vis;

    bool dir = 0;

    int cur = 1;
    bool flag = 0;

    bool check = 0;

    while(1){
        if(cur == 1){
            if(flag) break;
            flag = 1;
        } 

        int x = inp[cur].first;
        int y = inp[cur].second;
        
        if(!dir){
            //right
            auto it = cx[x].find(y);

            int l = 1e9;
            int r = 1e9;

            if(next(it) != cx[x].end()){
                it++;
                r = *it;
            }

            //left
            it = cx[x].find(y);

            if(it != cx[x].begin()){
                it--;
                l = *it;
            }

            vector<pair<pair<int,bool>,pair<int,int>>> opt;

            if(vis.find({x,r}) == vis.end()){
                opt.push_back({{abs(r-y),0}, {x,r}});
            }

            if(vis.find({x,l}) == vis.end()){
                opt.push_back({{abs(l-y),1 }, {x,l}});
            }

            if(opt.size()){
                sort(opt.begin(), opt.end());

                int xx = opt[0].second.first;
                int yy = opt[0].second.second;


                nw[xx][yy] = cnt;
                nxt[id[cur]] = {cnt, opt[0].first.first};
                cback[cnt] = ind[xx][yy];
                id[ind[xx][yy]] = cnt++;
                cur = ind[xx][yy];
                vis.insert({xx,yy});
            }


        }
        else{
            auto it = cy[y].find(x);

            int l = 1e9;
            int r = 1e9;

            if(next(it) != cy[y].end()){
                it++;
                r = *it;
            }

            

            //left
            it = cy[y].find(x);

            if(it != cy[y].begin()){
                it--;
                l = *it;
            }

            vector<pair<pair<int,bool>,pair<int,int>>> opt;

            if(vis.find({r,y}) == vis.end()){
                opt.push_back({{abs(r-x),1 }, {r,y}});
            }

            if(vis.find({l,y}) == vis.end()){
                opt.push_back({{abs(l-x),0 }, {l,y}});
            }

            if(opt.size()){
                sort(opt.begin(), opt.end());

                int xx = opt[0].second.first;
                int yy = opt[0].second.second;

                //cout << x << " " << y << " " << xx << " " << yy << "\n";


                nw[xx][yy] = cnt;
                nxt[id[cur]] = {cnt, opt[0].first.first};
                cback[cnt] = ind[xx][yy];
                id[ind[xx][yy]] = cnt++;
                cur = ind[xx][yy];
                vis.insert({xx,yy});
            }

            
        }

        dir ^= 1;
    }

    id[1] = 1;
    nw[inp[1].first][inp[1].second] = 1;

    for(int i = 2; i <= n; i++) dist[i] = dist[i-1] + nxt[i-1].second;
    for(int i = n+1; i <= 2*n; i++) dist[i] = dist[i-1] + nxt[(i-1)%n+1].second;
    
    while(q--){
        int a,b, aa,bb; cin >> a >> b >> aa >> bb;

        pair<pair<int,int>,pair<int,int>> in, out;
        
        //determine if a,b is on a vertical or horizontal segment

        if(nw[a][b]) in = {{nw[a][b], 0}, {nw[a][b], 0}};
        else{
            int l,r,u,d; 

            l = r = u = d = 1e9;
            int val[4] = {0,0,0,0};
            //right

            auto it = cx[a].lower_bound(b);

            if(it != cx[a].end()){
                r = nw[a][*it];
                val[0] = abs(*it - b);
            }

            it = cx[a].lower_bound(b);

            if(it != cx[a].begin()){
                it--;
                l = nw[a][*it];
                val[2] = abs(*it - b);
            }

            //down
            it = cy[b].lower_bound(a);

            if(it != cy[b].end()){
                d = nw[*it][b];
                val[1] = abs(*it - a);
            }

            it = cy[b].lower_bound(a);

            if(it != cy[b].begin()){
                it--;
                u = nw[*it][b];
                val[3] = abs(*it - a);
            }

            //cout << l << " " << r << " " << u << " " << d << "\n";

            if((u == n && d == 1) || (d == n && u == 1) || abs(u-d) == 1){
                in = {{u, val[3]}, {d, val[1]}};
            }
            else{
                in = {{r, val[0]}, {l, val[2]}};
            }

            
        }

        //cout << in.first.first << " " << in.second.first << " " << in.first.second << " " << in.second.second << "\n";

        if(nw[aa][bb]) out = {{nw[aa][bb], 0}, {nw[aa][bb], 0}};
        else{
            int l,r,u,d; 

            l = r = u = d = 1e9;
            int val[4] = {0,0,0,0};
            //right

            auto it = cx[aa].lower_bound(bb);

            if(it != cx[aa].end()){
                r = nw[aa][*it];
                val[0] = abs(*it - bb);
            }

            it = cx[aa].lower_bound(bb);

            if(it != cx[aa].begin()){
                it--;
                l = nw[aa][*it];
                val[2] = abs(*it - bb);
            }

            //down
            it = cy[bb].lower_bound(aa);

            if(it != cy[bb].end()){
                d = nw[*it][bb];
                val[1] = abs(*it - aa);
            }

            it = cy[bb].lower_bound(aa);

            if(it != cy[bb].begin()){
                it--;
                u = nw[*it][bb];
                val[3] = abs(*it -aa);
            }

            //cout << l << " " << r << " " << u << " " << d << "\n";

            if((u == n && d == 1) || (d == n && u == 1) || abs(u-d) == 1){
                out = {{u, val[3]}, {d, val[1]}};
            }
            else{
                out = {{r, val[0]}, {l, val[2]}};
            }
        }
        pair<int, pair<int,int>> best = {1e9, {-1,-1}};

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                for(int l = 0; l < 2; l++){
                    int x;
                    int vx;
                    if(!i){
                        x = in.first.first;
                        vx = in.first.second;
                    }
                    else{
                        x = in.second.first;
                        vx = in.second.second;
                    }

                    int y;
                    int vy;
                    if(!j){
                        y = out.first.first;
                        vy = out.first.second;
                    }
                    else{
                        y = out.second.first;
                        vy = out.second.second;
                    }

                    int exp;
                    if(l){
                        exp = dist[max(x,y)] - dist[min(x,y)];
                        best = min(best, {exp+vx+vy, {max(x,y), min(x,y)}});
                    }
                    else{
                        exp = dist[min(x,y)+n] - dist[max(x,y)];
                        best = min(best, {exp+vx+vy, {min(x,y)+n, max(x,y)}});
                    }
                }
            }

        }

        for(int i = best.second.second; i <= best.second.first; i++) ans[i]++;
    }

    for(int i = 1; i <= n; i++) cout << ans[cback[i]] + ans[cback[i]+n] << "\n";

}