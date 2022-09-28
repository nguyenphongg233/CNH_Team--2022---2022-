#include<bits/stdc++.h>

using namespace std;

#define int long long 
#define ii pair<int,int> 
#define X first
#define Y second 
const long long INF = 1e18;
const long long MAX = 2e5 + 5;

int n,m,k;
int a[MAX];
int f[MAX],g[MAX];

signed main(){
	
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	if(ifstream("bb.inp")){
		freopen("bb.inp","r",stdin);
		freopen("bb.out","w",stdout);
	}
	
	cin>>n>>m>>k;
	
	for(int i = 1;i <= n;i++)cin>>a[i];

	f[0] = -INF;
	
	for(int i = 1;i <= n;i++)f[i] = a[i];
	
	
	for(int i = 2;i <= k;i++){
		
		g[0] = -INF;
        deque<int> q;

        for(int j = 1;j <= n;j++) {
            while (!q.empty() && f[q.back()] <= f[j-1]) q.pop_back();
            q.push_back(j-1);
            while (q.front() < j - m) q.pop_front();
            g[j] = f[q.front()] + a[j]*i;
        }
		
		for(int j = 1;j <= n;j++){
			f[j] = g[j];
			g[j] = 0;
		}
		
	}
	
	int ans = *max_element(f,f + n + 1);
	
	
	cout<<ans;
	
}