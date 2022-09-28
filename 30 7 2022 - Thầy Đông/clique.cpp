#include<bits/stdc++.h>

#define X first
#define Y second

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

const long long MAX = 600 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;






int g[MAX][MAX];
int n,m,k;
int cnt[MAX];
int stone[MAX];
bool ok = 0;
int ans = 0;

bool check(int b){
	
	for(int i = 1;i <= b;i++){
		for(int j = i + 1;j <= b;j++){
			
			if( !g[stone[i]][stone[j]])return false;
			
		}
	}
	
	return true;
}

void find(int i,int l,int s){
	
	
	if(ok)return;
	for(int j = i + 1;j <= n  - (s - l);j++){
		
		if(cnt[j] >= s - 1){
			
			stone[l] = j;
			
			if(check(l)){
				
				if(l < s)find(j,l + 1,s);
				else {
					ok = 1;
					for(int y = 1;y <= l;y++)cout<<stone[y]<<" ";
					cout<<"\n";
					return;
				}
			}
		}
		
		if(ok)return;
	}
	
	
}

void solve(){
	
	cin>>n>>m>>k;
	
	
	
	for(int i = 1,u,v;i <= m;i++){
		cin>>u>>v;
		g[u][v] = g[v][u] = 1;
		cnt[u]++;
		cnt[v]++;
	}
	
	
	find(0,1,k);
	
	if(!ok)cout<<-1<<"\n";
	
	
	ok = 0;
	ans = 0;
	
	for(int i = 1;i <= n;i++){
		cnt[i] = 0;
		stone[i] = 0;
		for(int j = 1;j <= n;j++){
			g[i][j] = 0;
			
		}
	}
}

signed main(){
	
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	int t;
	cin>>t;
	
	while(t--)solve();
	
	
	#ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
	
}