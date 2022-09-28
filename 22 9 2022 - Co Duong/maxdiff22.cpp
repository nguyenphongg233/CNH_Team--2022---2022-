#include<bits/stdc++.h>

using namespace std;
const long long MAX = 20;
const long long INF = 1e18;
#define int long long 
int sum,st,dif;
int n,p,q;
int dp[MAX][1000];
int p10[MAX];


int dpx(int id,int s){
	
	if(id == n)return dp[id][s] = ((s == sum) ? 0 : -2);
	if(dp[id][s] != -1)return dp[id][s];
	
	int &res = dp[id][s] = -2;
	
	for(int d = (id == 0 ? max(1ll,dif) : dif);d <= min(9ll,dif + st);d++){
		if(dpx(id + 1,s + d) != -2){
			res = dpx(id + 1,s + d) + p10[n - id - 1] * d;
			break;
		}
	}
	
	return res;
	
	
}

int dpy(int id,int s){
	
	if(id == n)return dp[id][s] = ((s == sum) ? 0 : -2);
	if(dp[id][s] != -1)return dp[id][s];
	
	int &res = dp[id][s] = -2;
	
	for(int d = min(9ll,st + dif);d >= (id == 0 ? max(1ll,dif) : dif);d--){
		if(dpy(id + 1,s + d) != -2){
			res = dpy(id + 1,s + d) + d * p10[n - id - 1];
			break;
		}
	}
	return res;
}
void solve(){
	
	if(p > q)swap(p,q);
	
	int ans = 0;
	for(sum = 1;sum <= 9 * 20;sum++){
		int X = INF;
		int Y = -INF;
		
		st = p;
		
		for(dif = 0;dif <= 9;dif++){
			memset(dp,-1,sizeof dp);
			if(dpx(0,0) != -2){
				X = min(X,dpx(0,0));
			}
		}
		
		st = q;
		
		for(dif = 0;dif <= 9;dif++){
			memset(dp,-1,sizeof dp);
			if(dpy(0,0) != -2){
				Y = max(Y,dpy(0,0));
			}
		}
		
		if(X != INF && Y != -INF){
			ans = max(ans,abs(X - Y));
		}
		
		
	}
	
	swap(p,q);
	
	for(sum = 1;sum <= 9 * 20;sum++){
		int X = INF;
		int Y = -INF;
		
		st = p;
		
		for(dif = 0;dif <= 9;dif++){
			memset(dp,-1,sizeof dp);
			if(dpx(0,0) != -2){
				X = min(X,dpx(0,0));
			}
		}
		
		st = q;
		
		for(dif = 0;dif <= 9;dif++){
			memset(dp,-1,sizeof dp);
			if(dpy(0,0) != -2){
				Y = max(Y,dpy(0,0));
			}
		}
		
		if(X != INF && Y != -INF){
			ans = max(ans,abs(X - Y));
		}
		
		
	}
	
	cout<<ans<<"\n";
	
}

signed main(){
	
	int t;
	cin>>t;
	
	p10[0] = 1;
	for(int i = 1;i <= 18;i++){
		p10[i] = p10[i - 1] * 10;
	}
	
	while(t--){
		cin>>n>>p>>q;
		solve();
	}
	
}