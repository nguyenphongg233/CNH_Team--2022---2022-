#include<bits/stdc++.h>

using namespace std;
const long long MAX = 1e5 + 5;
#define int long long

int n,a[MAX];


int res = 0;
signed main(){
	
	cin>>n;

	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	
	int ans = 0;
	
	for(int i = 60;i >= 0;i--){
		int x = 0;
		for(int j = 1;j <= n;j++){
			if((a[j] >> i & 1) && (!(ans >> i & 1)) && (a[j] <= ((1 << (i + 1)) - 1))){
				
				x = a[j];
				ans ^= a[j];
				break;
				
			}
		}
		
		//cout<<x<<"\n";
		
		if(x == 0)continue;
		for(int j = 1;j <= n;j++){
			if(a[j] >> i & 1)a[j] ^= x;
			cout<<a[j]<<" ";
		}
		cout<<"\n";
		cout<<ans<<"\n";
		
		if(ans == 0)continue;
		//cout<<x<<" "<<ans<<"\n";
	}
	
	cout<<ans;
}
