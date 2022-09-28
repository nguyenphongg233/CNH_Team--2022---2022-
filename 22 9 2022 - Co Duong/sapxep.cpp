#include<bits/stdc++.h>

using namespace std;
const long long MAX = 1e5 + 5;
#define ii pair<int,int>
#define X first
#define Y second

int n;
int a[MAX];
vector<ii> d;
vector<ii> tmp;
int par[MAX];

int find(int u){
	return (par[u] == -1 ? u : par[u] = find(par[u]));
}

double dp[MAX];

void sub1(){
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	int mx = 0;
	bool ok = 1;
	for(int i = 1;i <= n;i++){
		mx = max(mx,a[i]);
		if(a[i] != i)ok = 0;
		if(ok){
			dp[i] = 0;
			continue;
		}
		if(mx == i){
			dp[i] = sqrt(i);
			int maxx = 0;
			for(int j = 1;j < i;j++){
				maxx = max(maxx,a[j]);
				if(maxx == j)dp[i] = min(dp[i],dp[j] + sqrt(i - (j + 1) + 1));
			}
		}
	}
	
	int u = dp[n];
	cout<<u<<"\n";
}
signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	if(ifstream("sapxep.inp")){
		freopen("sapxep.inp","r",stdin);
		freopen("sapxep.out","w",stdout);
	}
	cin>>n;
	
	if(n <= 2000){
		sub1();
		return 0;
	}
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(a[i] != i){
			d.push_back({min(i,a[i]),max(i,a[i])});
			//cout<<min(i,a[i])<<" "<<max(i,a[i])<<"\n";
		}
	}
	
	if(d.empty())return cout<<0,0;
	
	sort(d.begin(),d.end());
	
	int last = 0;
	int id = 0;
	
	d.erase(unique(d.begin(),d.end()),d.end());
	
	for(int i = 0;i < d.size();i++){
		if(d[i].X > last){
			if(last != 0)tmp.push_back({id,last});
			//cout<<id<<" "<<last<<"\n";
			id = d[i].X;
			last = d[i].Y;
		}else{
			
			last = max(last,d[i].Y);
			
		}
	}
	
	tmp.push_back({id,last});
	
	//for(auto v : tmp)cout<<v.X<<" "<<v.Y<<"\n";
	
	sort(tmp.begin(),tmp.end());
	
	double ans = sqrt(n);
	double cost = 0;
	
	vector<vector<int>> dp(tmp.size() + 5,vector<int>(tmp.size() + 5,0));
	for(int i = 0;i < tmp.size();i++){
		cost += sqrt(tmp[i].Y - tmp[i].X + 1);
	}
	
	//cout<<cost<<"\n";
	memset(par,-1,sizeof par);
	
	//for(auto v : tmp)cout<<v.X<<" "<<v.Y<<"\n";
	while(1){
		//cout<<"?";
		bool ok = 0;
		//cout<<tmp.size()<<"\n";
		for(int i = 1;i < tmp.size();i++){
			int id1 = i - 1;
			int id2 = i;
			
			int x = find(id1);
			int y = find(id2);
			
			
			if(x == y){
				i = x;
				continue;
			}
			
			
			double newcost = sqrt(tmp[y].Y - tmp[x].X + 1) - sqrt(tmp[x].Y - tmp[x].X + 1) - sqrt(tmp[y].Y - tmp[y].X + 1);
			if(newcost <= 0){
				
				//cout<<tmp[x].X<<" "<<tmp[x].Y<<" "<<tmp[y].X<<" "<<tmp[y].Y<<" "<<newcost<<'\n';
				par[x] = y;
				tmp[y] = {tmp[x].X,tmp[y].Y};
				cost += newcost;
				ok = 1;
			}
			
			
		}
		if(!ok)break;
		
		//cout<<cost<<"\n";
		//cout<<cost<<"\n";
	}
	
	cost = min(cost,ans);
	int u = cost;
	
	cout<<u;
	
}