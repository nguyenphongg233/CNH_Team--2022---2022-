#include<bits/stdc++.h>

using namespace std;

#define int long long
const long long MAX = 1e5 + 5;
const long long INF = 1e18;

double dp[MAX];
int n,k,d;
double h[MAX];
int t[MAX];

signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	cin>>n>>k>>d;
	
	for(int i = 1;i <= n;i++)dp[i] = -INF;
	for(int i = 1;i <= n;i++)cin>>h[i];
	for(int i = 1;i < n;i++)cin>>t[i];
	
	//dp[1] = h[1];
	
	for(int i = 1;i <= n;i++){
		
		dp[i] += dp[i];
		for(int j = i + 1;j <= i + t[i];j++){
			dp[j] = max(dp[j],dp[i] + double(h[j]) - double(((j - i) / k) * d));
			
		}
		
	}
	
	cout<<setprecision(0)<<fixed<<ceil(dp[n]);
	
	//cout<<setpresion(0)<<fixed<<ceil(dp[n]);
}