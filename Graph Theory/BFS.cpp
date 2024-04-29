#include <bits/stdc++.h>
#define nmax 1001
using namespace std;
int n,m,r;
vector <int> Ke[nmax], T;
bool ChuaXet[nmax];
void INPUT(){
	cin>>n>>m;
	for (int i=0; i<m; ++i){
		int x,y; cin>>x>>y;
		Ke[x].push_back(y);
		Ke[y].push_back(x);
	}
}
void INIT(){
	memset(ChuaXet,false,sizeof(ChuaXet));
}
void BFS(int r){
	queue <int> q; q.push(r); ChuaXet[r]=true;
	while(!q.empty()){
		int v=q.front();
		T.push_back(v);
		q.pop();
		for (auto u:Ke[v]){
			if (!ChuaXet[u]){
				q.push(u);
				ChuaXet[u]=true;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	INPUT();
	INIT();
	BFS(1);
	cout<<"T = ";
	for (auto i:T) cout<<i<<" ";
	return 0;
}
/*
8 11
1 2
1 3
1 8
2 4
2 8
3 4
3 6
4 5
5 6
5 8
6 7
*/
