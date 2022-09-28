#include<bits/stdc++.h>

using namespace std;
const long long MAX = 4e5 + 5;

int a[MAX],s[MAX];
int n;
vector<int> rt;

void solve(int l,int r){
	
	vector<int> dp(n + 5);
	
	map<int,int> mp;
	dp[l - 1] = 0;
	mp[s[l - 1]] = l;
	
	for(int i = l;i <= r;i++){
		
		if(mp[s[i]]){
			dp[i] = max(dp[mp[s[i]]] + 1,dp[i - 1]);
		}else dp[i] = dp[i - 1];
		
		mp[s[i]] = i;
		
	}
	
	
	cout<<dp[r]<<"\n";
	
	
	
	for(int i = l;i <= r;i++)mp[s[i]] = 0;
	
	
	
}

int q;

void sub1(){
	
	while(q--){
		int l,r;
		cin>>l>>r;
		solve(l,r);
	}
	
}

signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		s[i] = s[i - 1] + a[i];
		
	}
	
	
	
	cin>>q;
	
	sub1();
	
}