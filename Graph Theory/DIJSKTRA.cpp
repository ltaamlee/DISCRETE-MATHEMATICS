#include <bits/stdc++.h>
#define nmax 100
#define inf 9999
using namespace std;
int n,m,s,t;
int w[nmax][nmax], d[nmax], Truoc[nmax];
bool check[nmax];
vector <int> v;
void INPUT(){
	cin>>n;
	for(int i=1; i<=n; ++i){
		for (int j=1; j<=n; ++j){
			cin>>w[i][j];
		}
	}
}
void INIT(){
	memset(d,inf,sizeof(d));
	memset(check,false,sizeof(check));
}
int MIN_U(int n){
	int u=-1, ming=inf;
	for (int i=1; i<=n; ++i){
		if (!check[i] && d[i]<ming){
			ming=d[i];
			u=i;
		}
	}
	return u;
}
void PATH(int s, int f){
	cout<<"Duong di ngan nhat tu dinh "<<s<<" den dinh "<<f<<" : ";
	v.push_back(f);
	int p=f;
	while(p!=s){
		v.push_back(Truoc[p]);
		p=Truoc[p];
	}
	reverse(v.begin(),v.end());
	for (auto i:v) cout<<i<<" ";
	v.clear();
	cout<<"\n";
}
void DIJSKTRA(int s){
	INIT();
	for (int v=1; v<=n; ++v){
		d[v]=w[s][v];
		Truoc[v]=s;
	}
	d[s]=0;
	check[s]=true;
	int cnt=n;
	while (cnt!=0){
		int u=MIN_U(n);
		if (u==-1) break;
		check[u]=true;
		for (int v=1; v<=n; ++v){
			if (!check[v] && (d[v]>d[u]+w[u][v])){
				d[v]=d[u]+w[u][v];
				Truoc[v]=u;
			}
		}
		cnt--;
	}	
	for (int i=1; i<=n; ++i){
		if (d[i]>0 && d[i]<inf){
			PATH(s,i);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	INPUT();
//	for (int i=1; i<=n; ++i){
//		for (int j=1; j<=n; ++j){
//			cout<<w[i][j]<<"\t"; 
//		}
//		cout<<"\n";
//	}
	cin>>s;
	DIJSKTRA(s);
	return 0;
}
/*
5 9
1 2 1
1 5 7
2 3 1
2 4 4
2 5 8
3 4 2
3 5 4
4 3 1
5 4 4
5
9999 1 9999 9999 7
9999 9999 1 4 8
9999 9999 9999 2 4
9999 9999 1 9999 9999
9999 9999 9999 4 9999
*/
