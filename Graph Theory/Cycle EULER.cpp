#include <bits/stdc++.h>
#define nmax 1001
using namespace std;
set <int> adj[nmax+1];
stack <int> s;
vector <int> ce;
void INPUT(int &n, int &m){
	cin>>n>>m;
	for (int i=0; i<m; ++i){
		int u, v; cin>>u>>v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
}
int main(){
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	int n,m;
	INPUT(n,m);
	int u=3;
	s.push(u);
	while(!s.empty()){
		int x=s.top();
		if (adj[x].size()!=0){
			int y=*adj[x].begin();
			s.push(y);
			adj[x].erase(y);
			adj[y].erase(x);
		}
		else{
			ce.push_back(x);
			s.pop();
		}
	}
	reverse(begin(ce), end(ce));
	for (auto i:ce)
		cout<<i<<" ";
	return 0;
}
/*
8 22
1 6
1 5
2 5
2 6
3 6
3 5
4 6
4 5
4 7
4 8
5 4
5 3
5 2
5 1
6 4
6 3
6 2
6 1
7 4
7 8
8 4
8 7
*/
