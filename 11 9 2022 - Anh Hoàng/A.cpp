#include<bits/stdc++.h>

using namespace std;
const long long MAX = 10000 + 5;

int n;
string s[MAX];
int cnt[11][11][11][11];
int res = 0;

int dp(string &a,string &b,int id,int rt[]){
	if(id == 4)return cnt[rt[0]][rt[1]][rt[2]][rt[3]];
	
	if(a[id] == b[id]){
		rt[id] = a[id] - '0';
		return dp(a,b,id + 1,rt);
	}
	
	rt[id] = 10;
	int res = 0;
	// khong trung a,b
	res += dp(a,b,id + 1,rt);
	rt[id] = a[id] - '0';
	// trung a
	res -= dp(a,b,id + 1,rt);
	rt[id] = b[id] - '0';
	// trung b
	res -= dp(a,b,id + 1,rt);
	
	return res;
}
signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	
	for(int i = 1;i <= n;i++)cin>>s[i];
	for(int i = 1;i <= n;i++){
		
		for(int mask = 0;mask < (1 << 4);mask++){
			int rt[4];
			for(int j = 0;j < 4;j++){
				if(mask >> j & 1)rt[j] = s[i][j] - '0';
				else rt[j] = 10;
			}
			cnt[rt[0]][rt[1]][rt[2]][rt[3]]++;
		}
		
		for(int j = i + 1; j <= n;j++){
			
			int rt[] = {10,10,10,10};
			res += dp(s[i],s[j],0,rt);
			
		}
		
	}
	
	cout<<res;
	
	
}