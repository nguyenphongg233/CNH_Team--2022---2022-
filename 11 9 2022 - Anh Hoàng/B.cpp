#include<bits/stdc++.h>

using namespace std;
const long long MAX = 2000 + 5;
const long long INF = 1e9;
signed main(){
	
	int t;
	cin>>t;
	
	while(t--){
		int n;
		string s1,s2;
		cin>>n>>s1>>s2;
		
		s1 = " " + s1;
		s2 = " " + s2;
		vector<int> l(n + 5),r(n + 5);
		
		int res = INF;
		for(int i = 1;i <= n;i++)l[i] = l[i - 1] + (s1[i] != s2[i]);
		for(int i = n;i >= 1;i--)r[i] = r[i + 1] + (s1[i] != s2[i]);
		
		for(int i = 1;i <= n;i++){
			
			int it1 = i,it2 = i;
			int cnt = (s2[i] != s1[i]);
			res = min(res,l[i - 1] + r[i + 1] + cnt);
			while(it1 > 1 && it2 < n){
				
				it1--;
				it2++;
				
				cnt += (s1[it1] != s2[it2]);
				cnt += (s1[it2] != s2[it1]);
				res = min(res,l[it1 - 1] + r[it2 + 1] + cnt);
			}
			
			it1 = i,it2 = i + 1;
			cnt = (s1[it1] != s2[it2]) + (s1[it2] != s2[it1] ) ;
			res = min(res,l[it1 - 1] + r[it2 + 1] + cnt);
			while(it1 > 1 && it2 < n){
				
				it1--;
				it2++;
				
				cnt += (s1[it1] != s2[it2]);
				cnt += (s1[it2] != s2[it1]);
				res = min(res,l[it1 - 1] + r[it2 + 1] + cnt);
			}
			
			
		}
		
		cout<<min(r[1],res)<<'\n';
	}
	
}