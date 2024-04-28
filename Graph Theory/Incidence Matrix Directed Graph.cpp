#include <bits/stdc++.h>
#define nmax 100
#define mmax 100
using namespace std;
map <tuple<int,int,int,int>,int> mp;
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
			if (a[i][k]==-a[j][k] && abs(a[i][k])==1){
				mp[make_tuple(i,j,a[i][k],a[j][k])]++;
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
//a. Cac cap dinh co canh song song cung huong
	cout<<"Cap dinh co canh song song cung huong:\n";
	cnt=0;
	for (int j=1; j<=m; ++j) EDGE_P(n,j,a);
	for (auto i:mp){
		if (i.second==2){
			cnt++;
			cout<<"("<<get<0>(i.first)<<","<<get<1>(i.first)<<")\n";	
		}
	}
	if (cnt==0) cout<<"Khong co!\n";
	cout<<"------------------\n";
//b. Cac cap dinh co canh song song nguoc huong
	cout<<"Cap dinh co canh song song nguoc huong:\n";
	set<tuple<int,int>> st;
	for (auto i:mp){
		if (i.second==1){
			st.insert(make_tuple(get<0>(i.first),get<1>(i.first)));
		}
	}
	if (st.size()==0) cout<<"Khong co!\n";
	else{
		for (auto x: st){
			tuple<int,int> t=x;
			cout<<"("<<get<0>(x)<<","<<get<1>(x)<<")\n";
		}
	}
	cout<<"------------------\n";
//c. Ban bac trong _ Ban bac ngoai
	for (int i=1; i<=n; ++i){
		for (int j=1; j<=m; ++j){
			if (a[i][j]==1)
				a[i][0]+=1;
		}
	}
	for (int i=1; i<=n; ++i){
		cout<<"Ban bac ngoai cua dinh "<<i<<" : "<<a[i][0]<<"\n";
	}
	cout<<"------------------\n";
	for (int i=1; i<=n; ++i){
		for (int j=1; j<=m; ++j){
			if (a[i][j]==-1){
				a[0][i]+=abs(a[i][j]);
			}
		}
	}
	for (int i=1; i<=n; ++i){
		cout<<"Ban bac trong cua dinh "<<i<<" : "<<a[0][i]<<"\n";
	}
	return 0;
}
/*
4 5
1 0 0 0 1
-1 -1 1 0 -1
0 1 -1 1 0
0 0 0 0 0 
*/
