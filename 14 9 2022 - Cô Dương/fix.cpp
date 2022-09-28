#include<bits/stdc++.h>

using namespace std;

#define int long long 
#define ii pair<int,int> 
#define X first
#define Y second 

const long long MAX = 2e5 + 5;

int n,m;

vector<int> adj[MAX];
int p[MAX];
bool d[MAX];
int par[MAX];
int coe[MAX];
bool ret[MAX];

int find(int u){
	return (u == par[u]) ? u : par[u] = find(par[u]);
}
signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	if(ifstream("FIX.INP")){
		freopen("FIX.INP","r",stdin);
		freopen("FIX.OUT","w",stdout);
	}
	
	cin>>n>>m;
	
	for(int i = 1,u,v;i <= m;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for(int i = 1;i <= n;i++){
		cin>>p[i];
		//cout<<p[i]<<"\n";
		par[i] = i;
		coe[i] = 1;
	}
	
	int ans = 0;
	
	
	for(int i = n;i >= 1;i--){
		
		d[p[i]] = 1;
		
		int newt = n - i;
	
		//cout<<ans<<" "<<newt<<"\n";
		
		/*if(ans == newt){
			ret[i] = 1;
			
		}else ret[i] = 0;*/
		for(auto v : adj[p[i]]){
			
			if(!d[v])continue;
			
			int x = find(v);
			
			if(x == p[i])continue;
			par[x] = p[i];
			coe[p[i]] += coe[x];
			coe[x] = 0;
			
			
		}
		
		ans = coe[p[i]];
		if(ans == newt + 1){
			ret[i] = 1;
			
		}else ret[i] = 0;
		//cout<<p[i]<<" ";

		
		
		//for(int j = 1;j <= n;j++)cout<<coe[j]<<" ";
		//cout<<"\n";
		
	}
	
	for(int i = 1;i <= n;i++)cout<<(ret[i] == 0 ? "NO" : "YES")<<"\n";
	
	
}