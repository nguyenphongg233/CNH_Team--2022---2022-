#include<bits/stdc++.h>

using namespace std;

//#define int long long

int n;
string s[10];
int ans = 0;

bool duyet(string sr){
	
	//cout<<sr<<"\n";
	
	bool ok = 0;
	string ty = sr;
	reverse(ty.begin(),ty.end());
	for(int i = 2;i <= n;i++){
		
		if(s[i].find(sr) > s[i].size() && s[i].find(ty) > s[i].size())return 0;
			
		
		
	}
	
	//cout<<sr<<"\n";
	int x = sr.size();
	ans = max(ans,x);
	
	return 1;
}
signed main(){
	
	cin>>n;
	
	for(int i = 1;i <= n;i++)cin>>s[i],s[i] = s[i] + s[i];
	
	sort(s + 1,s + 1 + n,[&](const string &a,const string &b){
		return a.size() < b.size();
	});
	
	
	int m = s[1].size();
	s[1] = " " + s[1];
	
	
	for(int l = 1;l <= m;l++){
		
		
		string op = "";
		op = op + s[1][l];
		//cout<<op;
		duyet(op);
		
		int l_ = l + 1,r_ = m;
		
		while(l_ <= r_){
			
			int m_ = l_ + r_ >> 1;
			string t = "";
			
			for(int i = l;i <= m_;i++){
				t = t + s[1][i];
			}
			
			if(duyet(t))l_ = m_ + 1;
			else r_ = m_ - 1;
		}
		
		/*
		for(int r = l + 1;r <= m;r++){
			
			if(r - l + 1 > m / 2)break;
			
			string t = "";
			
			for(int i = l;i <= r;i++){
				t = t + s[1][i];
			}
			//cout<<l<<" "<<r<<" "<<t<<"\n";
			
			duyet(t);
			
			
		}
		
		*/
		
		
	}
	
	cout<<ans;
	
	
	
	
}
