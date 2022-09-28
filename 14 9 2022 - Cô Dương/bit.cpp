#include<bits/stdc++.h>

using namespace std;

#define int long long 
#define ii pair<int,int> 
#define X first
#define Y second 

const long long MAX = 1e6 + 5;

int n;
int snt[MAX];
int cnt[MAX];



signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	if(ifstream("bit.inp")){
		freopen("bit.inp","r",stdin);
		freopen("bit.out","w",stdout);
	}
	
	int n;
	cin>>n;
	
	if(n > MAX){
		int id = sqrt(n);
		cout<<id<<"\n";
		return 0;
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j += i){
			
			cnt[j] ^= 1;
			
		}
		
	}
	
	int sum = accumulate(cnt + 1,cnt + 1 + n,0);
	cout<<sum;
}