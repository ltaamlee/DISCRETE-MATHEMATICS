#include <bits/stdc++.h>
using namespace std;
int s[100];
void INIT(int n, int s[]){
	for (int i=1; i<=n; ++i)
		s[i]=i;
}
void SHOW(int n){
	for (int i=1; i<=n; ++i){
		cout<<s[i]<<" ";
	}
	cout<<"\n";
}
void SORT(int pos, int n, int s[]){
	for (int i=pos; i<n; ++i){
		for (int j=i+1; j<=n; ++j){
			if (s[i]>s[j])
				swap(s[i],s[j]);
		}
	}
}
int main(){
    long n; cin>>n;
    INIT(n,s);
    cout<<"Cac hoan vi "<<n<<" phan tu : \n";
    while(true){
    	SHOW(n);
		int j=n-1, k=n;
		while(s[j]>s[j+1] && j>0) j--;
		if (j==0) break;
		else{
			while(s[k]<s[j])
				k--;
			swap(s[j],s[k]);
			SORT(j+1,n,s);
		}
	}
	return 0;
}
