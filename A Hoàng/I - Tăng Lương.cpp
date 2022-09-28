#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

const long long MAX = 3e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

int n;
int salary[MAX];
vi adj[MAX];
ii dp[MAX];
int cnt[MAX];

void dfs(int u,int p){
	
	dp[u] = {u,salary[u]};
	for(auto v : adj[u]){
		if(v == p)continue;
		
		dfs(v,u);
		
		if(dp[v].Y > dp[u].Y)dp[u] = dp[v];
		
		
	}
	
	
	cnt[dp[u].X] += dp[u].X != u;
	
}
signed main(){
	
	cin>>n;
	cin>>salary[0];
	
	for(int i = 1,x;i <= n;i++){
		cin>>salary[i]>>x;
		adj[x].push_back(i);
		adj[i].push_back(x);
	}
	
	
	dfs(0,-1);
	
	for(int i = 1;i <= n;i++)cout<<cnt[i]<<"\n";
	
	
	
}