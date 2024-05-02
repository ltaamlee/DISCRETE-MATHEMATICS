#include <bits/stdc++.h>
#define nmax 1001
using namespace std;
int n,m,r,cnt;
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
void DFS(int v){	
	ChuaXet[v]=true; 
	T.push_back(v);
	for (auto u:Ke[v]){
		if (!ChuaXet[u]){
			DFS(u);
		}
	}
}
void CONNECT(){
	cnt=0;
	INIT();
	for (int i=1; i<=n; ++i){
		if (!ChuaXet[i]){
			++cnt;
			cout<<"Cac dinh thuoc thanh phan lien thong thu "<<cnt<<" : ";
			DFS(i);
			for (auto i:T) cout<<i<<" ";
			cout<<"\n";
			T.clear();
		}
		
	}
}
int main(){
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	INPUT();
//	cout<<"T = ";
//	for (auto i:T) cout<<i<<" ";
//	cout<<"\n";
	CONNECT();
  if (cnt==0) cout<<"Do thi khong lien thong!";
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

9 6
1 2
2 3
3 4
3 6
5 7
5 8
*/
