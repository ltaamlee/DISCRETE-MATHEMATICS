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
	set <tuple<int,int>> st1, st2;
	INPUT(n,a);
	cout<<"-------------------\n";
	cout<<"  DO THI VO HUONG \n";
	cout<<"-------------------\n";
//a. Cac cap dinh co canh song song cung huong
	cout<<"Cap dinh co canh song song cung huong:\n";
	for (int i=1; i<=n; ++i){
		for (int j=1; j<=n; ++j){
			if (a[i][j]==2){
				st1.insert(make_tuple(i,j));
			}
		}
	}
	if (st1.size()>0)
		PARALLEL(st1);
	else cout<<"Khong co!\n";
	cout<<"------------------\n";
//b. Cac cap dinh co canh song song nguoc huong
	bool check[nmax][nmax]={0};
	cout<<"Cap dinh co canh song song nguoc huong:\n";
	for (int i=1; i<=n; ++i){
		for (int j=1; j<=n; ++j){
			if (a[i][j]==1 && a[j][i]==1 && check[i][j]==false && check[i][j]==false){
				st2.insert(make_tuple(i,j));
				check[i][j]=check[j][i]=true;
			}
		}
	}
	if (st2.size()>0)
		PARALLEL(st2);
	else cout<<"Khong co!\n";
	cout<<"------------------\n";
//c. Ban bac trong, ban bac ngoai 
	for (int i=1; i<=n; ++i){
		for (int j=1; j<=n; ++j){
			a[i][0]+=a[i][j];
		}
	}
	for (int i=1; i<=n; ++i){
		for (int j=1; j<=n; ++j){
			a[0][j]+=a[i][j];
		}
	}
	for (int i=1; i<=n; ++i){
		cout<<"Ban bac trong cua dinh "<<i<<" : "<<a[0][i]<<"\n";
	}
	cout<<"------------------\n";
	for (int i=1; i<=n; ++i){
		cout<<"Ban bac ngoai cua dinh "<<i<<" : "<<a[i][0]<<"\n";
	}	
	return 0;
}
/*
6
0 1 1 1 0 0
0 0 0 1 0 0
0 0 0 1 1 1
0 0 1 0 0 1
0 0 0 0 0 1
0 0 0 2 0 0
*/
