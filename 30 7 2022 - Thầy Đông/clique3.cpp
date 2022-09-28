#include<bits/stdc++.h>

#define X first
#define Y second

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

const long long MAX = 3e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

int n;
int a[MAX];
int l[MAX],r[MAX];
bool dd[MAX];
int ans = 0;

signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	
	
	
	for(int i = 1,x;i <= n;i++){
		cin>>x;
		dd[x] = 1;
	}
	
	for(int i = 1;i < MAX;i++){
		if(!dd[i])continue;
		
		for(int j = i * 2;j < MAX;j += i){
			if(!dd[j])continue;
			
			l[j]++;
			r[i]++;
			
		}
	}
	
	
	for(int i = 1;i < MAX;i++){
		
		if(!dd[i])continue;
		//cout<<i<<" "<<l[i]<<" "<<r[i]<<"\n";
		ans += l[i] * r[i];
		
	}
	
	
	cout<<ans;
	
	
	#ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
	
}