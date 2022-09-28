#include<bits/stdc++.h>

using namespace std;

#define int long long
const long long INF = 1e9;
const long long MOD = 1e9 + 7;
const long long MAX = 1000 + 5;
int n;
string s[10];
int ans = 0;
int h[10][MAX],p[MAX];
int h2[10][MAX];
const int base = 26;

int get(int l,int r,int i){
	
	return (h[i][r] - h[i][l - 1] * p[r - l + 1] + MOD * MOD) % MOD;
	
}

int get2(int l,int r,int i){
	return (h2[i][r] - h2[i][l - 1] * p[r - l + 1] + MOD * MOD) % MOD;
}
void duyet(int sr,int srt,int siz){
	
	//cout<<sr<<"\n";
	
	bool ok = 0;

	
	for(int i = 2;i <= n;i++){
		
		bool ok = 0;
		for(int j = siz - 1;j < s[i].size();j++){
			
			int r = j;
			int l = j - siz + 1;
			
			if(get(l,r,i) == sr || get(l,r,i) == srt){
				//cout<<sr<<" "<<srt<<"\n";
				//cout<<l<<" "<<r<<" "<<i<<"\n";
				ok = 1;
				break;
			}
			
		}
		
		if(!ok){
			//cout<<i<<" "<<sr<<" "<<siz<<"\n";
			
			return;
		}
		
	}
	
	//cout<<sr<<"\n";
	//int x = sr.size();
	//cout<<" "<<sr<<" "<<siz<<"\n";
	ans = max(ans,siz);
	
	
}
signed main(){
	
	cin>>n;
	
	for(int i = 1;i <= n;i++)cin>>s[i],s[i] = s[i] + s[i];
	
	sort(s + 1,s + 1 + n,[&](const string &a,const string &b){
		return a.size() < b.size();
	});
	
	
	for(int i = 1;i <= n;i++)cout<<s[i]<<"\n";
	int m = s[1].size();
	
	
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < s[i].size();j++){
			h[i][j] = (h[i][j - 1] * base + s[i][j] - 'a' + 1 ) % MOD; 
		}
		
		
		
		for(int j = s[i].size() - 1;j >= 0;j--){
			h2[i][j] = (h2[i][j + 1] * base + s[i][j] - 'a' + 1 ) % MOD; 
		}
	}
	
	p[0] = 1;
	for(int i = 1;i < MAX;i++)p[i] = (p[i - 1] * base ) % MOD;
	
	for(int l = 0;l < m;l++){
		
		
		
		//duyet(get(l,l,1),get(l,l,1),1);
		if(l > m / 2)break;
		for(int r = l + 1;r <= m;r++){
			
			if(r - l + 1 > m / 2)break;
			
			
			int ty = get(l,r,1);
			//cout<<l<<" "<<r<<" "<<"\n";
			int ty2 = get2(l,r,1);
			duyet(ty,ty2,r - l + 1);
			
			
		}
		
		
		
	}
	
	cout<<get(4,6,1)<<"\n";
	cout<<get2(4,6,1)<<"\n";
	cout<<get(1,3,2)<<"\n";
	cout<<get(0,2,3)<<"\n";
	
	cout<<ans;
	
	
	
	
}