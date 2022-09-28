#include<bits/stdc++.h>

using namespace std;
#define int long long 
const long long MAX = 2e6 + 5e5 + 5;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

int n,k,a[MAX];

int power(int a,int b){
	if(b == 1)return a % MOD;
	if(b == 0)return 1;
	
	int s = power(a,b / 2);
	
	s = (s * s) % MOD;
	
	if(b & 1)s = (s * a) % MOD;
	return s;
}


void add(int &a,int b){
	a += b;
	if(a > MOD)a -= MOD;
}
void sub1(){
	
	vector<int> dp(n + 5);
	dp[0] = 0;
	for(int i = 1;i <= n;i++){
		dp[i] = dp[i - 1] + a[i];
		int minx = a[i];
		for(int j = i - 1;j >= max((i - k + 1),1ll);j--){
			minx = max(minx,a[j]);
			dp[i] = min(dp[i],dp[j - 1] + minx);
			
		}
		
		
	}
	
	int sum = 0;
	for(int i = 1;i <= n;i++){
		add(sum,dp[i] % MOD * power(23,n - i));
	}
	
	cout<<sum % MOD<<"\n";
	
	
}

void sub(){
	
	set<int> res;
	vector<int> dp(n + 5);
	deque<int> h;
	
	dp[0] = 0;
	h.push_back(0);
	a[0] = INF;
	
	for(int i = 1;i <= n;i++){
		
		dp[i] = dp[i - 1] + a[i];
		while(!h.empty() && a[h.back()] <= a[i])h.pop_back();
		
		while(h.size() && i - h.front() + 1 > k)h.pop_front();
		//cout<<i<<"\n";
		for(auto v : h){
			
			//cout<<v<<" ";
			if(v == 0)
				dp[i] = min(dp[i],a[i]);
			else 
				dp[i] = min(dp[i],dp[v - 1] + max(a[v],a[i]));
			
		}
		
		if(h.empty()){
			
			dp[i] = min(dp[i - k] + a[i],dp[i]);
			
		}
		
		h.push_back(i);
		//cout<<"\n";
		
		
		//cout<<dp[i]<<" ";
		
	}
	
	
	
	int sum = 0;
	for(int i = 1;i <= n;i++){
		add(sum,dp[i] % MOD * power(23,n - i));
	}
	
	cout<<sum;
	
}
signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	cin>>n>>k;
	
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	
	
	sub1();
		//return 0;
	

	
}