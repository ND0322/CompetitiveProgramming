#include <bits/stdc++.h>
#include <iostream>

using namespace std;




//cht but im not making a custom struct and sort cmp
//let the coyote be at (l,0)
//then dist = -2xi * l + xi^2 + yi^2
//m = -2xi
//b = xi^2 + yi^2

typedef pair<pair<long double,long double>,long long> line;

const int MAXN = 1e6+5;

int n;

long double x[MAXN],y[MAXN];

vector<line> lines, sheep;

long double intersect(line l, line ll){
    long double b = (l.first.second - ll.first.second);
    long double m = (ll.first.first - l.first.first);

    return b/m;
}

void insert(line l){
    while(!lines.empty() && lines.back().first.first == l.first.first) lines.pop_back();
    while(lines.size() >= 2 && intersect(lines[lines.size() - 2], lines.back()) > intersect(lines.back(), l)) lines.pop_back();
    lines.push_back(l);
    
    
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    int n; cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];

        long long tempx = x[i] * 1000;
        long long tempy = y[i] * 1000;

        sheep.push_back({{-2 * tempx, tempx*tempx + tempy*tempy}, i});
    }

    sort(sheep.rbegin(), sheep.rend());

    for(line i : sheep) insert(i);

    for(int i = 0; i < lines.size(); i++){
       if(i != lines.size()-1 && intersect(lines[i],lines[i+1]) < 0) continue;

       cout << setprecision(2) << fixed << "The sheep at (" << x[lines[i].second] << ", " << y[lines[i].second] << ") might be eaten.\n";

       //out of bounds
       if(i != lines.size()-1 && intersect(lines[i], lines[i+1]) > 1000 * 1000) break;
    }

    
}