#include<bits/stdc++.h>

using namespace std;

int main(){
	int i,q,n,j,x,y;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>q;
	int b[q];
	memset(b,0,sizeof(b));
	for(i=0;i<q;i++){
		cin>>x>>y;
		for(j=x;j<=y;j++){
			b[i]+=a[j];
		}
	}
	for(i=0;i<q;i++){
		cout<<b[i]<<endl;
	}
}
