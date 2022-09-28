#include<bits/stdc++.h>

using namespace std;
const long long MAX = 1e3 + 5;
const long long INF = 1e9;

#define ii pair<int,int> 
#define X first
#define Y second
int n,m;
int a[MAX][MAX];
vector<int> adj[MAX];
int color[MAX];
bool ok = 0;

int l = 0,r = 0;
void dfs(int u,int col){
	
	color[u] = col;
	int nextcol = 3 - col;
	if(col == 1)l++;
	else r++;
	for(auto v : adj[u]){
		if(color[v] == col){
			ok = 1;
			return;
		}else if(color[v] == nextcol)continue;
		
		dfs(v,3 - col);
	}
	
}
vector<int> p;
map<int,int> dp;
map<int,int> f;

signed main(){
	
	cin>>n>>m;
	
	for(int i = 1,u,v;i <= m;i++){
		cin>>u>>v;
		a[u][v] = 1;
		a[v][u] = 1;
	}
	
	int sum = 0;
	
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++){
			if(!a[i][j]){
				adj[i].push_back(j);
				adj[j].push_back(i);
				//cout<<i<<" "<<j<<"\n";
			}
		}
	}
	
	for(int i = 1;i <= n;i++){
		if(!color[i]){
			l = 0,r = 0;
			dfs(i,1);
			p.push_back(abs(l - r));
			sum += abs(l - r);
			//cout<<l<<" "<<r<<"\n";
		}
	}
	
	if(ok)return cout<<-1,0;
	
	dp[0] = true;

    for(int x : p)
        for(int i = sum; i >= x; i--)
            if(!dp[i])
                if(dp[i - x])
                    dp[i] = true;
    int ans = sum;

    for(int i = 0; i <= sum; i++)
        if(dp[i])ans = min(ans, abs(sum - 2 * i));

    cout << ans;
	//return 0;
	
	

	
	
	
}