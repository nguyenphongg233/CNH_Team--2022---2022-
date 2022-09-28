#include<bits/stdc++.h>

using namespace std;
const long long MAX = 1e5;

#define int long long 
#define double long double

double f[MAX],in[MAX],out[MAX];
vector<int> adj[MAX];
int n;


void dfs(int u,int p){
	
	for(auto v : adj[u]){
		
		if(v == p)continue;
		dfs(v,u);
		if(adj[v].size() == 1)in[u] += f[v];
		else in[u] += (in[v] / (adj[v].size() - 1)) + (f[v] / adj[v].size());
		
	}
}

void dfs2(int u,int p){
	
	//double sum = in[u] + out[u];
	
	//cout<<u<<" "<<out[u]<<" "<<adj[u].size()<<" :\n";
	for(auto v : adj[u]){
		if(v == p)continue;
		
		double sum = 0;
		if(adj[v].size() == 1)sum += f[v];
		else sum += (in[v] / (adj[v].size() - 1)) + (f[v] / adj[v].size());
		
		if(adj[u].size() != 1){
			out[v] = (in[u] + out[u] - sum) / (adj[u].size() - 1) + f[u] / adj[u].size();
		}else out[v] = out[u] + f[u];
		
		//cout<<v<<" "<<sum<<"\n";
		
		dfs2(v,u);
		
	}
	
	
}
signed main(){
	
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i = 1,u,v;i < n;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	int k;
	cin>>k;
	
	for(int i = 1,u;i <= k;i++){
		double v;
		cin>>u>>v;
		f[u] += v;
	}
	
	dfs(1,0);
	dfs2(1,0);
	
	cout<<setprecision(4)<<fixed;
	for(int i = 1;i <= n;i++){
		cout<<out[i] + in[i] + f[i]<<"\n";
	}
	
	
}