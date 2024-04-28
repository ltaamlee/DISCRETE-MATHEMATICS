#include <bits/stdc++.h>
#define nmax 100
#define mmax 100
using namespace std;
map <tuple<int,int>,int> mp;
void INPUT(int &n, int &m, int a[nmax][mmax]){
    cin>>n>>m;
	for (int i=1; i<=n; ++i){
		for (int j=1; j<=m; ++j){
			cin>>a[i][j];
		}
	}
}
void EDGE_P(int n, int k, int a[nmax][mmax]){
	for (int i=1; i<n; ++i){
		for (int j=i+1; j<=n; ++j){
			if (a[i][k]==a[j][k] && a[i][k]==1){
				mp[make_tuple(i,j)]++;
			}
		}
	}	
}
int main(){
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	int n,m,a[nmax][mmax]={0}, cnt=0;
	INPUT(n,m,a);
	cout<<"------------------------------------\n";
	cout<<" MA TRAN LIEN THUOC DO THI VO HUONG \n";
	cout<<"------------------------------------\n";
//a. Cac cap dinh co canh song song
	cout<<"Cap dinh co canh song song:\n";
	for (int j=1; j<=m; ++j) EDGE_P(n,j,a);
	for (auto i:mp){
		if (i.second==2){
			cnt++;
			cout<<"("<<get<0>(i.first)<<","<<get<1>(i.first)<<")\n";
		}
	}
	if (cnt==0) cout<<"Khong co!\n";
	cout<<"------------------\n";
//b. Bac cua cac dinh
	for (int i=1; i<=n; ++i){
		for (int j=1; j<=m; ++j){
			a[i][0]+=a[i][j];
		}
	}
	for (int i=1; i<=n; ++i)
		cout<<"Bac dinh "<<i<<" : "<<a[i][0]<<"\n";
	cout<<"------------------\n";
//c. Dinh treo
	cnt=0;
	cout<<"Dinh treo: ";
	for (int i=1; i<=n; ++i){
		if (a[i][0]==1) {
			cout<<i<<"\n";
			cnt++;
		}
	}
	if (cnt==0) cout<<"Khong co!\n";
	cout<<"------------------\n";
//d.Dinh co lap
	cnt=0;
	cout<<"Dinh co lap: ";
	for (int i=1; i<=n; ++i){
		if (a[i][0]==0) {
			cout<<i<<"\n";
			cnt++;
		}
	}
	if (cnt==0) cout<<"Khong co!\n";
	cout<<"------------------\n";
	return 0;
}
/*
4 4
1 0 0 0
1 1 1 0
0 1 1 1
0 0 0 0 
*/
