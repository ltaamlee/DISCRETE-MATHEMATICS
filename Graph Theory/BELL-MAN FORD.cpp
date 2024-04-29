#include <bits/stdc++.h>
#define nmax 100
#define inf 9999
using namespace std;
int n,m,s,t;
int w[nmax][nmax], d[nmax], Truoc[nmax];
vector <int> v;
bool check=false;
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
	for (int v=1; v<=n; ++v){
		d[v]=w[s][v];
		Truoc[v]=s;
	}
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
void BELL_MAN_FORD(int s){
	INIT();
	d[s]=0;
	for (int k=1; k<n; ++k){
		check=true;
		for (int v=1& v!=s; v<=n; ++v){
			for (int u=1; u<=n; ++u){
				if (d[v]>d[u]+w[u][v]){
					d[v]=d[u]+w[u][v];
					Truoc[v]=u;
					check=false;
				}
			}
		}	
		if (check) break;	
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
	cin>>s;
	BELL_MAN_FORD(s);
	return 0;
}
/*
5 9
1 2 1
1 5 3
2 3 3
2 4 3
2 5 8
3 4 1
3 5 -5
4 3 2
5 4 4
5
9999 1 9999 9999 3
9999 9999 3 3 8
9999 9999 9999 1 -5
9999 9999 2 9999 9999
9999 9999 9999 4 9999 
*/
