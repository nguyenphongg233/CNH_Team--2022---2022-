#include<bits/stdc++.h>

using namespace std;
#define int long long
const long long INF = 1e18;
const long long MAX = 1e5 + 5;
#define ii pair<int,int>
#define X first
#define Y second 

vector<ii> adj[MAX];
vector<int> td[MAX];
int cnt[MAX];

int n,m;
int step[MAX];

void sub(){
	
	for(int i = 1;i <= m;i++){
		

		for(int j = 0;j < cnt[i];j++){
			for(int z = j + 1;z < cnt[i];z++){
				
				int l = td[i][j];
				int r = td[i][z];
				
				int cost = (cnt[i] - (z - j + 1));
				
				adj[l].push_back({r,cost});
				adj[r].push_back({l,cost});
				
				
				//cout<<l<<" "<<r<<" "<<cost<<"\n";
			}
		}
		

	}
	
	priority_queue<ii,vector<ii>,greater<ii>> q;
	
	q.push({0,1});
	
	for(int i = 1;i <= n;i++)step[i] = INF;
	step[1] = 0;
	while(!q.empty()){
		
		int u = q.top().Y;
		int cost = q.top().X;
		
		q.pop();
		
		
		for(auto e : adj[u]){
			
			int v = e.X;
			int w = e.Y;
			
			if(step[v] > step[u] + w){
				step[v] = step[u] + w;
				q.push({step[v],v});
			}
			
		}
	}
	
	cout<<step[n];
	
}

signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	
	int str = 0;
	int ed = 0;
	for(int i = 1;i <= m;i++){
		cin>>cnt[i];
		//cout<<cnt[i]<<"\n";
		for(int j = 1,x;j <= cnt[i];j++){
			cin>>x;
			if(x == 1)str = j;
			else if(x == n)ed = j;
			
			td[i].push_back(x);
		}
	}

	sub();
	
	
	
	
	
	
	
}