#include <bits/stdc++.h>
#define nmax 1005
using namespace std;
struct EDGE {
	int u,v;
	int w;
};
int n,m;
EDGE g;
int s[nmax],size[nmax];
vector <EDGE> e;
void MakeSet(){
	for (int v=1; v<=n; ++v){
		s[v]=v;
		size[v]=1;
	}
}
int FindSet(int v){
	if (v==s[v]) return v;
	return s[v]=FindSet(s[v]);
}
bool Union(int x, int y){
	x=FindSet(x);
	y=FindSet(y);
	if (x==y) return false;   //Kiem tra hai dinh co trung nhan?
	if (size[x]<size[y]) swap(x,y);
	s[y]=x;
	size[x]+=size[y];
	return true;
}
void INPUT(){
	cin>>n>>m;
	for (int i=0; i<m; ++i){
		cin>>g.u>>g.v>>g.w;
		e.push_back(g);
	}	
}
bool cmp(EDGE x, EDGE y){
	return x.w<y.w;
}
void KRUSKAL(){
	sort(e.begin(),e.end(),cmp);
	vector<EDGE> MST;  //minimum spanning tree
	for (int i=0; i<m; ++i){
		if (Union(e[i].u,e[i].v)){
			MST.push_back(e[i]);
		}
	}
	cout<<"T = ";
	for (auto i:MST) cout<<"("<<i.u<<","<<i.v<<")"<<" ";
}
int main(){
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	INPUT();
	MakeSet();
	KRUSKAL();
	return 0;
}
/*
6 9
1 2 4
1 3 2
1 5 3
2 4 5
3 4 1
3 5 6
3 6 6
4 6 6
5 6 2
*/
