#include<bits/stdc++.h>

using namespace std;
const long long MAX = 1e5 + 5;
//#define int long long 
int t;
int n,p,q;

void sub1(){
	
	int cs = 1;
	for(int i = 1;i <= n;i++)cs *= 10;	
	int ans = 0;
	for(int x = cs / 10;x < cs;x++){
		for(int y = cs / 10;y < cs;y++){
			string a = to_string(x);
			string b = to_string(y);
			int minx1 = 10,minx2 = 10,maxx1 = -1,maxx2 = -1;
			int sum1 = 0,sum2 = 0;
			for(int i = 0;i < a.size();i++){
				minx1 = min(minx1,(a[i] - '0'));
				minx2 = min(minx2,b[i] - '0');
				maxx1 = max(maxx1,a[i] - '0');
				maxx2 = max(maxx2,b[i] - '0');
				sum1 += a[i] - '0';
				sum2 += b[i] - '0';
			}
			
			if(abs(minx1 - maxx1) <= p && abs(minx2 - maxx2) <= q){
				if(sum1 == sum2){
					ans = max(ans,abs(x - y));
				}
			}
		}
	}
	
	cout<<ans<<"\n";
}



signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	if(ifstream("MAXDIFF.INP")){
		freopen("MAXDIFF.INP","r",stdin);
		freopen("MAXDIFF.OUT","w",stdout);
	}
	
	cin>>t;
	
	while(t--){
		cin>>n>>p>>q;
		sub1();
		
	}
	
}