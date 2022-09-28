#include<bits/stdc++.h>

#define int long long
#define X first
#define Y second

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

int n,a[MAX],b[MAX],par[MAX];
bool dd[MAX];
int sum[MAX];

int find(int u){
	if(u == par[u])return u;
	return par[u] = find(par[u]);
}

set<int> s;
vector<int> ans;

signed main(){
	
	cin>>n;
	
	for(int i = 1;i <= n;i++)cin>>a[i],par[i] = i;
	for(int i = 1;i <= n;i++)cin>>b[i];
	
	
	for(int i = n;i >= 1;i--){
		
		
		
		int id = b[i];
		
		
		if(dd[id - 1] && dd[id + 1]){
			
			int x = find(id - 1);
			int y = find(id + 1);
			
			s.erase(sum[y]);
			s.erase(sum[x]);
			
			sum[y] += sum[x] + a[id];
			
			s.insert(sum[y]);
			par[id] = y;
			par[x] = y; 
			
		}else if(dd[id - 1]){
			
			int x = find(id - 1);
			s.erase(sum[x]);
			
			sum[x] += a[id];
			par[id] = x;
			
			s.insert(sum[x]);
			
			
		}else if(dd[id + 1]){
			
			int y = find(id + 1);
			s.erase(sum[y]);
			
			sum[y] += a[id];
			par[id] = y;
			
			s.insert(sum[y]);
			
			
		}else{
			
			s.insert(a[id]);
			sum[id] = a[id];
		}
		
		dd[id] = 1;
		
		
		ans.push_back(*s.rbegin());
	}
	
	
	reverse(ans.begin(),ans.end());
	
	for(auto v : ans)cout<<v<<"\n";
	
	#ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
	
}