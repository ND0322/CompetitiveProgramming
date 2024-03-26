#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;
constexpr int MM = 1e5+5, X = 1e6;

struct line{
	ll m, b; int id;
	bool operator<(const line &o) const{
		if(m == o.m){
			if(b == o.b)
				abort();
				// return id > o.id;
			return b > o.b;
		}
		return m > o.m; //highest slope first
	}
};

int n;
ll x[MM], y[MM];
vector<line> points, q;

ld inter(line a, line b){
	assert(a.m != b.m);
	return ld(b.b-a.b)/ld(a.m-b.m);
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
		points.push_back({-2*x[i], x[i]*x[i] + y[i]*y[i], i});
	}

    
	sort(points.begin(), points.end());
    for(auto i:points){
        cout << i.m << " " << i.b << " " << i.id << "\n";
    }
	for(auto i: points){
		while(q.size() and q.back().m == i.m)
			q.pop_back();
    
        if(q.size() >= 2)cout << q[q.size() - 2].m << " " << q.end()[-2].b << " " << q.end()[-2].id << "\n"; //cout << inter(q.back(), i) << "\n";
		
		//
		while(q.size() >= 2 and inter(q.end()[-2], q.back()) > inter(q.back(), i))
			q.pop_back();
		q.push_back(i);
	}
	for(int i = 0; i < (int)q.size(); i++){
		if(i < (int)q.size()-1 and inter(q[i], q[i+1]) < 0)
			continue;
		printf("The sheep at (%lld, %lld) might be eaten.\n", x[q[i].id], y[q[i].id]);
		if(i < (int)q.size()-1 and inter(q[i], q[i+1]) > X)
			break;
	}
}