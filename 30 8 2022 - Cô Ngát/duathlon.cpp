#include<bits/stdc++.h>

#define X first
#define Y second

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

const long long MAX = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

int n,a[MAX];
vector<int> adj[MAX];
int l[MAX],r[MAX];
int st[MAX << 2];

void buildtree(int id ,int l,int r){
	if(l == r){
		st[id] = a[l];
		return;
	}
	
	int m = l + r >> 1;
	buildtree(id << 1,l,m);
	buildtree(id << 1 | 1,m + 1,r);
	st[id] = max(st[id],st[id << 1 | 1]);
}

int get(int id,int l,int r,int u,int v){
	if(u > r || v  < l)return 0;
	if(u <= l && r <= v)return st[id];
	
	int m = l + r >> 1;
	return max(get(id << 1,l,m,u,v),get(id << 1 | 1,m + 1,r,u,v));
}

int gett(int u,int v){
	return get(1,1,n,u,v);
}
signed main(){
	
	cin>>n;
	
	vector<int> rt;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		rt.push_back(a[i]);
	}
	
	sort(rt.begin(),rt.end());
	rt.erase(unique(rt.begin(),rt.end()),rt.end());
	
	for(int i = 1;i <= n;i++){
		a[i] = lower_bound(rt.begin(),rt.end(),a[i]) - rt.begin() + 1;
		adj[a[i]].push_back(i);
		l[i] = max(l[i - 1],a[i]);
	}
	
	buildtree(1,1,n);
	for(int i = n;i >= 1;i--)r[i] = max(r[i + 1],a[i]);
	
	int cnt = 0;
	int ans = 0;
	bool swb = 1,ewb = 1;
	
	for(int i = rt.size();i >= 1;i--){
		
		
		for(auto v : adj[i]){
			
			if(v == 1){
				swb = 0;
				if(a[v] > a[v + 1])cnt++;
			}else if(v == n){
				ewb = 0;
				if(a[v] > a[v - 1])cnt++;
			}else{
				if(a[v] > a[v - 1] && a[v] > a[v + 1])cnt++;
				if(a[v] <= a[v - 1] && a[v] <= a[v + 1])cnt--;
			}
			
		}
		
		cout<<cnt + cnt - 2 + ewb + swb<<"\n";
		ans = max(ans,cnt + cnt - 2 + ewb + swb);
		
	}
	
	cout<<ans;
	

	
}