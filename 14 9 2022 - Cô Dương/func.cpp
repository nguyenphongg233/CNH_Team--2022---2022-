#include<bits/stdc++.h>

using namespace std;

#define int long long 
#define ii pair<int,int> 
#define X first
#define Y second 

const long long MAX = 1e5 + 5;

int n;


signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	if(ifstream("func.inp")){
		freopen("func.inp","r",stdin);
		freopen("func.out","w",stdout);
	}
	
	cin>>n;
	
	if(n & 1){
		
		cout<<(((n - 1) / 2) - n);
		
	}else cout<<n / 2;

}