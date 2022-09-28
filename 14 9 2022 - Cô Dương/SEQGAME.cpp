#include<bits/stdc++.h>

using namespace std;

#define int long long 
#define ii pair<int,int> 
#define X first
#define Y second 

const long long MAX = 1e5 + 5;
const long long INF = 1e18;

int n,m;
int pref[MAX];
int f[MAX];
int st[MAX << 2];

void buildtree(int id,int l,int r){
	
	if(l == r){
		st[id] = pref[l];
		return;
	}
	
	int mid = l + r >> 1;
	
	buildtree(id << 1,l,mid);
	buildtree(id << 1 | 1,mid + 1,r);
	
	st[id] = max(st[id << 1],st[id << 1 | 1]);
	
}

int get(int id,int l,int r,int u,int v){
	
	if(u > r || v < l)return 0;
	if(u <= l && r <= v)return st[id];
	int mid = l + r >> 1;
	return max(get(id << 1,l,mid,u,v),get(id << 1 | 1,mid + 1,r,u,v));
}

struct query{
	int l,r,v;
}q[MAX];

signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	if(ifstream("SEQGAME.INP")){
		freopen("SEQGAME.INP","r",stdin);
		freopen("SEQGAME.OUT","w",stdout);
	}
	
	cin>>n>>m;
	
	for(int i = 1,l,r,v;i <= m;i++){
		cin>>l>>r>>v;
		f[l] += v;
		f[r + 1] -= v;
		q[i] = {l,r,v};
		
	}
	
	for(int i = 1;i <= n;i++){
		pref[i] = pref[i - 1]  + f[i];
	}
	
	buildtree(1,1,n);

	int ans = INF;
	for(int i = 1;i <= m;i++){
		
		int l = q[i].l;
		int r = q[i].r;
		int v = q[i].v;
		
		int q = get(1,1,n,l,r) - v;
		int w = get(1,1,n,1,l - 1);
		int ve = get(1,1,n,r + 1,n);
		
		ans = min(ans,max({q,w,ve}));
		
	}
	
	cout<<ans;
	
	
	
}