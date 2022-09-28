#include<bits/stdc++.h>

using namespace std;
const long long MAX = 1e5;
#define int long long

int n,MOD;
int dp[(1 << 20)][25];

int calc(int mask,int last){
	
	if(mask == (1 << n) - 1)return dp[mask][last] = 1;
	
	if(dp[mask][last] != -1)return dp[mask][last];
	
	int &res = dp[mask][last] = 0;
	
	for(int i = 0;i < n;i++){
		if(mask >> i & 1)continue;
		if(last == i - 1)continue;
		
		res = (res + calc(mask ^ (1 << i),i)) % MOD;
		
	}
	
	return res % MOD;
	
	
}

signed main(){
	
	cin>>n>>MOD;
	
	memset(dp,-1,sizeof dp);
	
	int sum = 1;
	for(int i = 1;i <= n;i++)sum = (sum * i) % MOD;
	
	sum = (sum - calc(0,n + 1) + MOD * MOD) % MOD;
	cout<<sum;
}