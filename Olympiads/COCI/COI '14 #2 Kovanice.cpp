#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3e5+5;

int n,v,e,ansF[MAXN],ansR[MAXN],comp[MAXN],cnt;

vector<int> adj1[MAXN],adj2[MAXN],adj3[MAXN],adj4[MAXN];



bitset<MAXN> visited;

void floodfill(int node){
    visited[node] = 1;
    comp[node] = cnt;
    

    for(int child:adj2[node]){
        if(!visited[child]) floodfill(child);
    }
}

//look for longest path from forward and reverse and check if they sum to n

/*
bool dfs(int node, int d){

    

    if(ans[node]) return true;
    if(d == n){
       
        ans[node] = d;
        return true;
    }

    bool flag = false;

    for(int child:adj3[node]){
       
        if(dfs(child,d+1)){
            
            ans[node] = d;
            flag = true;
        }
    }

    return flag;

    
}
*/


int dfs1(int node){
    if(ansF[node]) return ansF[node];

    for(int child:adj3[node]){
        ansF[node] = max(ansF[node],dfs1(child));
    }

    ansF[node]++;
    return ansF[node];
}

int dfs2(int node){
    if(ansR[node]) return ansR[node];

    for(int child:adj4[node]){
        ansR[node] = max(ansR[node],dfs2(child));
    }

    ansR[node]++;
    return ansR[node];
}



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n >> v >> e;

    

    

    for(int i = 0; i < e; i++){
        string edge; cin >> edge;
        //kinda wished i used python

        string first = "";
        string second = "";
        bool flag = true;
        int syb = -1;

        for(char j:edge){
            if(j == '='){
                syb = 0;
                flag = 0;
                continue;
            }
            else if(j == '<'){
                syb = 1;
                flag = 0;
                continue;
            } 

            if(flag) first += j;
            else second += j;
        }

        

        int fn = stoi(first);
        int sn = stoi(second);

        //cout << syb << " " << fn << " " << sn << "\n";
        

        
       

        if(syb)adj1[fn].push_back(sn);
        else{
            adj2[fn].push_back(sn);
            adj2[sn].push_back(fn);
        }

        
    }

    for(int i = 1; i <= v; i++){
        if(!visited[i]){
            floodfill(i);
            cnt++;
        }
    }

 

    


 
    
   

    for(int i = 1; i <= v; i++){
       
        for(int j : adj1[i]){
            if(comp[i] == comp[j]) continue;

            adj3[comp[i]].push_back(comp[j]);
            adj4[comp[j]].push_back(comp[i]);
            

            
        }
    }

    for(int i = 0; i < cnt; i++){
        if(!ansF[i]) dfs1(i);
        if(!ansR[i]) dfs2(i);
    }


   

   

   

    

    

    for(int i = 1; i <= v; i++){
        if(ansF[comp[i]] + ansR[comp[i]] == n+1){
            cout << "K" << ansR[comp[i]] << "\n";
        }
        else{
            cout << "?\n";
        }

        //cout << ans[comp[i]] << "\n";
    }







    



}