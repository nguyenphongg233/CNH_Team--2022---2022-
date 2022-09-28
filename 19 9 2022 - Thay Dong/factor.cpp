#include<bits/stdc++.h>

using namespace std;

#define int long long
const long long MAX = 1e3 + 5;
int f[MAX];
int snt[MAX];
int dp[MAX];
int gt[MAX];
map<int,int> ans;
signed main(){
	
	snt[1] = 1;
	
	for(int i = 2;i * i < MAX;i++){
		if(!snt[i]){
			snt[i] = i;
			for(int j = i * i;j < MAX;j += i)snt[j] = i;
		}
	}
	
	gt[0] = 1;
	for(int i = 1;i <= 20;i++){
		gt[i] = gt[i - 1] * i;
	}
	for(int i = 2;i < MAX;i++){
		//f[i] = f[i / snt[i]] + 1;
		map<int,int> t;
		int cnt = 0;
		int id = i;
		
		while(id > 1){
			
			
			t[snt[id]]++;
			cnt++;
			id /= snt[id];
			
			cout<<id<<"\n";
			
		}
		
		cout<<"\n";
		int rtr = gt[cnt];
		
		for(auto v : t)rtr /= gt[v.second];
		rtr *= cnt;
		
		if(!ans.count(rtr))ans[rtr] = i;
		else ans[rtr] = min(i,ans[rtr]);
		
	}
	

	
	/*int n;
	while(cin>>n){
		
		if(ans.count(n))cout<<ans[n]<<"\n";
		else cout<<-1<<"\n";
	}*/
	
}