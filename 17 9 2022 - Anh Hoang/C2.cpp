#include<bits/stdc++.h>

using namespace std;
#define int long long 
const long long MAX = 1e5 + 5;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
#define ii pair<int,int>
#define X first
#define Y second 

int n,k,a[MAX];
int dp[MAX];
const long long base = 23;
signed main(){
	
	cin>>n>>k;
	for(int i = 1;i <= n;i++)cin>>a[i];
	
	deque<int> h;
	
	dp[1] = a[1];
	h.push_back(1);
	set<ii> st;
	st.insert({dp[1],1});
	for(int i = 2;i <= n;i++){
		
		while(!h.empty() && a[h.back()] < a[i]){
			//if(i == 8)cout<<h.back()<<"\n";
			st.erase({dp[h.back() - 1] + a[h.back()],h.back()});
			h.pop_back();
		}
		while(!h.empty() && i - h.front() + 1 > k){
			//if(i == 8)cout<<h.front()<<"\n";
			st.erase({dp[h.front() - 1] + a[h.front()],h.front()});
			h.pop_front();
		}
		dp[i] = INF;
		//if(i == 8)
		//cout<<h.size()<<" "<<st.size()<<"\n";
		if(st.size()){
			auto it = *st.begin();
			//cout<<it.X<<"\n";
			dp[i] = min(dp[i],it.X);
		}
	    else {
	    	
	    	dp[i] = min(dp[i],dp[max(0ll,i - k)] + a[i]);
	    	//if(i == 8)
	    	//cout<<max(0ll,i - k)<<" "<<dp[max(0ll,i - k)] + a[i]<<"\n";
	    }
	   // if(st.size())cout<<i<<" "<<*st.begin()<<"\n";
		h.push_back(i);
		st.insert({dp[i - 1] + a[i],i});
		
		//cout<<i<<" "<<max(0ll,i - k)<<" ";
		//cout<<"***\n";
		//for(auto v : st)cout<<v<<" ";
		//cout<<"\n";
		//cout<<dp[i]<<"\n";
		dp[i] %= MOD;
	}
	
	int poww = 1;
	int sum = 0;
	for(int i = n;i >= 1;i--){
		
		sum = (sum + poww * dp[i] % MOD) % MOD; 
		
		poww = (poww * base) % MOD;
	}
	
	cout<<sum % MOD;
	
}