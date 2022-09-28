#include<bits/stdc++.h>

using namespace std;
const long long MAX = 1e6 + 5;
#define int long long
int n,a[MAX],l[MAX],r[MAX];

signed main(){
	
	cin>>n;
	
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		l[i] = max(l[i - 1] + a[i],a[i]);
		
	}
	
	for(int i = n;i >= 1;i--)r[i] = min(r[i + 1] + a[i],a[i]);
	
	int res = 0;
	for(int i = 2;i <= n;i++){
		res = max(res,abs(r[i] - l[i - 1]));
		//cout<<l[i - 1]<<" "<<r[i]<<"\n";
	}
	
	
	memset(l,0,sizeof l);
	memset(r,0,sizeof r);
	
	for(int i = 1;i <= n;i++)
		l[i] = min(l[i - 1] + a[i],a[i]);
		
	
	for(int i = n;i >= 1;i--)r[i] = max(r[i + 1] + a[i],a[i]);
	
	
	for(int i = 2;i <= n;i++){
		res = max(res,abs(r[i] - l[i - 1]));
		//cout<<l[i - 1]<<" "<<r[i]<<"\n";
	}
	
	
	cout<<res;
}