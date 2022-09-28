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

int n,x,m;
map<int,int> mp;
vector<int> a;
signed main(){
	
	cin>>n>>x>>m;
	
	if(x == 0)return cout<<0,0;
	a.push_back(x);
	mp[x]++;
	int last = -1;\
	int cnt = 0;
	while(1){
		if(a.size() == n)break;
		int x_ = (a.back() * a.back()) % m;
		if(mp[x_]){
			last = x_;
			break;
		}
		else mp[x_]++;
		a.push_back(x_);
		
	}
	
	if(a.size() == n && last == -1){
		
		int sum = 0;
		for(auto x : a)sum += x;
		cout<<sum;
		return 0;
		
	}
	
	
	int base = -1;
	int sum = 0;
	int str = -1;
	for(int i = 0;i < a.size();i++){
		
		if(a[i] == last){
			
			base = a.size() - (i);
			
			str = i;
			break;
			
		}
		else{
			
			
			n--;
			sum += a[i];
		}
		
	}
	
	int op = 0;
	
	for(int i = str;i < a.size();i++)op += a[i];
	
	
	sum += op * (n / base);
	
	int du = n % base;
	
	
	for(int i = str;i < a.size();i++){
		if(du == 0)break;
		du--;
		sum += a[i];
		if(du == 0)break;
	}
	
	cout<<sum;
	
	
	
	#ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
	
}