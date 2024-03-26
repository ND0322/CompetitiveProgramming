#include <bits/stdc++.h> 
#include <iostream>
#include <map>

using namespace std;

int n;

vector<char> ans;

struct Node{
    map<char, Node*> children;
    short cnt, depth;
    char bad;

    void dfs(){
        for(auto c: children){
            c.second->dfs();
            int nxt = c.second->depth + 1;
            if(nxt > depth){
                depth = nxt;
                bad = c.first;
            }

        }
    }

    void build(bool g){
        if(!g) bad = 0;

        while(cnt--) ans.push_back('P');

        for(auto c: children){
            if(c.first == bad) continue;
            ans.push_back(c.first);
            c.second->build(0);
            ans.push_back('-');
        }
        if(bad){
            ans.push_back(bad);
            children[bad]->build(1);
        }
    }

};





int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin>>n;
	Node *root = new Node();


	
	while(n--){
		string s; cin>>s;
		Node *cur = root;

		for(char c: s){
			if(!cur->children.count(c))
				cur->children[c] = new Node();
			cur = cur->children[c];
		}
		cur->cnt++;
	}
	root->dfs();
    root->build(1);
    cout << ans.size() << "\n";
    for(char c:ans) cout << c << "\n";
}