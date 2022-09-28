#include<bits/stdc++.h>

using namespace std;
const long long MAX = 2e3 + 5;
#define ii pair<int,int>
#define X first
#define Y second

int n;
int a[MAX];
double dp[MAX];
int par[MAX];

signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	if(ifstream("sapxep.inp")){
		freopen("sapxep.inp","r",stdin);
		freopen("sapxep.out","w",stdout);
	}
	
	cin>>n;
	
	for(int i = 1;i <= n;i++)cin>>a[i];
	memset(par,-1,sizeof par);
	int mx = 0;
	bool ok = 1;
	for(int i = 1;i <= n;i++){
		mx = max(mx,a[i]);
		if(a[i] != i)ok = 0;
		if(ok){
			dp[i] = 0;
			par[i] = i;
			continue;
		}
		 
		if(mx == i){
			
			dp[i] = sqrt(i);
			
			for(int j = 1;j * j <= i;j++){
				int root = max(1,i - (j + 1) * (j + 1) + 1);
				root = min(root,i - 1);
				if(par[root] == -1)continue;
				dp[i] = min(dp[i],j + dp[par[root]]);
				
			}
			
			if(a[i] == i)dp[i] = min(dp[i],dp[i - 1]);
			
			
			int id = i;
			
			while(par[id] == -1 && id >= 1){
				par[id] = i;
				id--;
			}
		}
		
	}
	
	cout<<dp[n];
	
	
}