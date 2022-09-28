#include<bits/stdc++.h>

#define int long long
#define X first
#define Y second

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

int n;

signed main(){
	
	cin>>n;
	int ans = 0;
	bool ok = 0;
	for(int i = 60;i >= 1;i--){
		
		if(n >> i & 1){
			ok = 1;
			//cout<<ans<<"\n";
		}
		
		if(ok){
			
			ans += (1 << (i));
			//cout<<i<<" ";
			cout<<(1 << (i))<<'\n';
		}
	
	}
	
	cout<<ans + (n & 1)<<'\n';
	
}