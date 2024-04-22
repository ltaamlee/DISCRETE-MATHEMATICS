#include <bits/stdc++.h>
using namespace std;
#define nmax 100
void INPUT(int &n, int a[][nmax]){
	cin>>n;
	for (int i=1; i<=n; ++i){
		for (int j=1; j<=n; ++j){
			cin>>a[i][j];
		}
	}
}
void PARALLEL(set<tuple<int,int>> &st){
	for (auto x: st){
		tuple<int,int> t=x;
		cout<<"("<<get<0>(x)<<","<<get<1>(x)<<")\n";
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, a[nmax][nmax], cnt=0;
	set <tuple<int,int>> st;
	INPUT(n,a);
	cout<<"-------------------\n";
	cout<<"  DO THI VO HUONG \n";
	cout<<"-------------------\n";
//a. Cac cap dinh co canh song song
	bool check[nmax][nmax]={0};
	cout<<"Cap dinh co canh song song:\n";
	for (int i=1; i<=n; ++i){
		for (int j=1; j<=n; ++j){
			if (a[i][j]==2 && check[i][j]==0){
				st.insert(make_tuple(i,j));
				check[j][i]=check[i][j]=1;
			}
		}
	}
	if (st.size()>0)
		PARALLEL(st);
	else cout<<"Khong co!\n";
	cout<<"------------------\n";
//b. Bac cua cac dinh
	for (int i=1; i<=n; ++i){
		for (int j=1; j<=n; ++j){
			a[i][0]+=a[i][j];
		}
	}
	for (int i=1; i<=n; ++i){
		cout<<"Bac dinh "<<i<<": "<<a[i][0]<<"\n";
	}
	cout<<"------------------\n";
//c. Dinh treo
	cout<<"Dinh treo: ";
	for (int i=1; i<=n; ++i){
		if (a[i][0]==1) {
			cout<<i<<" ";
			cnt++;
		}
	}
	if (cnt==0) cout<<"Khong co!\n";
	cout<<"------------------\n";
//d. Dinh co lap
	cout<<"Dinh co lap: ";
	cnt=0;
	for (int i=1; i<=n; ++i){
		if (a[i][0]==0){
			cout<<i<<" ";
			cnt++;
		}
	}
	if (cnt==0)
		cout<<"Khong co!\n";
	return 0;
}
/*
6
0 1 1 1 0 0
1 0 0 1 0 0
1 0 0 2 1 1
1 1 2 0 0 2
0 0 1 0 0 1
0 0 1 2 1 1
*/
