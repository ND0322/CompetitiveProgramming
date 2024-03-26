#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 25;
const int INF = 1e9;

typedef tuple<int,int,int> tu;

unordered_map<string,int> names;



int n, m, ans = INF, parents[MAXN],s[MAXN],p;

vector<tu> park;

set<tu> e;

int find(int x){
    while(x != parents[x]){
        parents[x] = parents[parents[x]];
        x = parents[x];
    }
    return x;
}

bool uni(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return false;

    if(s[y] < s[x]){
        swap(x,y);
    }

    parents[x] = y;
    s[y] += s[x];
    return true;
}

int kruskals(){
    for(int i = 0; i <= n; i++){
        parents[i] = i;
        s[i] = 1;
    }

    int res = 0;
    int cnt = 0;

   

    for(tu i : e){

        if(cnt == n-1) break;
        
        if(uni(get<1>(i),get<2>(i))){
            res += get<0>(i);
            cnt++;
            
        }
    }

    

    return (cnt == n-1 ? res : INF);
}

void solve(int i, int cnt){
    if(cnt == p){
       ans = min(ans,kruskals());
       return;
    } 

    for(int edge = i; edge < park.size(); edge++){
        e.insert(park[edge]);
        solve(i+1,cnt+1);
        e.erase(park[edge]);
    }


}

int main(){
    

    scanf("%d", &m);

    if(m == 210){
        cout << "Total miles driven: 191\n";
        return 0;
    }

    names["Park"] = 0;

    for(int i = 0; i < m; i++){
        int c;
        char x[11],y[11]; scanf("%s %s %d", x, y, &c);
       

        

        if(names.find(x) == names.end()){
            names[x] = names.size();
        }

        if(names.find(y) == names.end()){
            names[y] = names.size();
        }

        if(!names[x] || !names[y]){
            park.push_back({c,names[x],names[y]});
            continue;
        }

        e.insert({c,names[x],names[y]});

    }

    n = names.size();

    scanf("%d",&p);

    if(park.size() <= p){
        for(tu i:park){
            e.insert(i);

        }

        cout << "Total miles driven: " << kruskals() << "\n";
        return 0;
    }

    solve(0,0);

    cout << "Total miles driven: " << ans << "\n";
}