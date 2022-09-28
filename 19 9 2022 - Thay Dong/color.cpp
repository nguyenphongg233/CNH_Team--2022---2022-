#include<bits/stdc++.h>

using namespace std;

#define int long long

int dp[15][(1 << 15)];
int n,m;

int g(int mask,int q){
	return (mask >> q) & 1;
}
void printt(){
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < (1 << m);j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
}
signed main(){
	
	cin>>n>>m;
	
	if(n < m)swap(n,m);
	
	if(m == 1){
		cout<<(1 << n);
		return 0;
	}
	int ans = 0;
	
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < (1 << m);j++){
			if(i == 1)dp[i][j] = 1;
			else dp[i][j] = 0;
			
		}
	
	}
	
	for(int i = 2;i <= n;i++){
		for(int mask = 0;mask < (1 << m);mask++){
			
			for(int mask2 = 0;mask2 < (1 << m);mask2++){
				
				
				bool ok = 1;
				for(int z = 1;z < m;z++){
					
					if(g(mask,z) == g(mask,z - 1) && g(mask,z - 1) == g(mask2,z - 1) && g(mask2,z - 1) == g(mask2,z))ok = 0;
					
				}
				
				if(!ok){
					continue;
				}
				
				
				dp[i][mask] += dp[i - 1][mask2];
				
			}
			
			if(i == n)ans += dp[i][mask];
			
			//cout<<dp[i][mask]<<" ";
			
			
		}
		//cout<<"\n";
		
	
		
		
	}
	
	
	cout<<ans;
	
	
	
	
}