#include<bits/stdc++.h>

using namespace std;

const long long MAX = 1e3 + 5;
#define ii pair<int,int>
#define X first
#define Y second 
int t;
int n;
ii a[MAX];

void calc(int k,int l,int r){
	
	//cout<<k<<" "<<l<<" "<<r<<"\n";
	if(l == r)return;
	if(k == 10)return;
	vector<ii> left,right;
	
	for(int i = l;i <= r;i++){
		
		if(a[i].X >> k & 1)right.push_back(a[i]);
		else left.push_back(a[i]);
		
	}
	
	for(int i = 0;i < left.size();i++)a[i + l] = left[i];
	for(int i = 0;i < right.size();i++)a[l + left.size() + i] = right[i];
	
	calc(k + 1,l,left.size() + l - 1);
	calc(k + 1,l + left.size(),r);
}
void solve(){
	
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i].X;
		a[i].Y = i;
	}
	
	//for(int i = 1;i <= n;i++)cout<<a[i].Y<<" ";
	//cout<<"\n";
	
	calc(0,1,n);
	
	for(int i = 1;i <= n;i++)cout<<a[i].Y<<" ";
	cout<<"\n";
	
	
}

signed main(){
	
	cin>>t;
	
	while(t--)solve();
	
	
}