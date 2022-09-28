#include<bits/stdc++.h>

using namespace std;
const long long MAX = 1e5 + 5;
#define int long long

int n,a[MAX],pref[MAX];
map<int,int> mp;
struct node{
	node *child[2];
	node (){
		for(int i = 0;i < 2;i++)child[i] = NULL;
	}
};

node *root = new node();

void add(int n){
	
	
	node *rt = root;
	for(int i = 64;i >= 0;i--){
		
		int bit = n >> i & 1;
		if(rt -> child[bit] == NULL){
			rt -> child[bit] = new node();
		}
		
		rt = rt->child[bit];
		
	}
	
}

int get(int n){
	
	node *rt = root;
	int res = 0;
	for(int i = 64;i >= 0;i--){
		int bit = 1 - (n >> i & 1);
		
		if(rt -> child[bit] == NULL){
			res ^= ((1 << (bit)) * (1 ^ bit));
			rt = rt -> child[1 - bit];
		}else{
			res ^= (1 << bit) * bit;
			rt = rt -> child[bit];
		}
		
	}
	
	return res;
}
signed main(){
	
	cin>>n;
	
	add(0);
	
	int res = 0;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		pref[i] = pref[i - 1] ^ a[i];
		cout<<pref[i]<<" ";
		cout<<get(pref[i])<<"\n";
		res = max(res,pref[i] ^ get(pref[i]));
		add(pref[i]);
		//mp[pref[i]]++;
	}
	
	cout<<res;
	
}