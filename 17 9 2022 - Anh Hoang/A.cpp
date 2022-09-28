#include<bits/stdc++.h>

using namespace std;
#define int long long 
const long long MAX = 1e5 + 5;
#define ii pair<int,int>
#define X first
#define Y second 

string s;
int n;
string c;
int cnt = 0;
vector<int> adj[30];

bool ok2(string s,string c,int i,int j){
	
	// i : s 
	// j : c 
	
	for(;i < s.size();i++){
		if(j == c.size())return true;
		if(s[i] == c[j]){
			j++;
		}
		if(j == c.size())return true;
	}
	
	return false;
	
	
}
bool check(string s,string c){
	
	int id1 = 0;
	int id2 = 0;
	
	for(;id1 < s.size();id1++){
		
		//cout<<id1<<" "<<id2<<"\n";
		
		if(id1 == id2){
			//id2++;
			//continue;
		}
		if(id2 == c.size())break;
		//cout<<"?";
		
		//if(s[id1] == c[id2]){
			int tv = c[id2] - 'a' + 1;
			
			int ok = 0;
			//cout<<id1<<" "<<id2<<"\n";
			
			for(auto v : adj[tv]){
				if(v < id1)continue;
				if(ok2(s,c,v,id2))ok++;
		
				if(ok >= 2)break;
			}
			//cout<<"\n";
			
			if(ok >= 2)return true;
		//}
		
		if(s[id1] == c[id2]){
			id2++;
			//id1++;
			
		}
	}
	
	return false;
	
	
	
}
signed main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	

	
	cin>>s>>n;
	
	for(int i = 0;i < s.size();i++){
		adj[s[i] - 'a' + 1].push_back(i);
	}
	
	//if(n <= 100 && s.size() <= 100){
		for(int i = 1;i <= n;i++){
			
			cin>>c;
			
			if(c.size() > s.size())continue;
			if(check(s,c))cnt++;
			 
			
		}
		return cout<<cnt,0;
	//}
	
	
	
	
}