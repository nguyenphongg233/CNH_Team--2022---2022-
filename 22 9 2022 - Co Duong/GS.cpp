#include<bits/stdc++.h>

using namespace std;
const long long N = 1e5 + 5,MOD = 1e9 + 7;
#define int long long

int n;
string s[N];
bool cmp(string a,string b){
	if(a.size() != b.size())return a.size() > b.size();
	
	for(int i = 0;i < a.size();i++){
		if(a[i] > b[i])return 1;
		else if(b[i] > a[i])return 0;
	}
	return 1;
}
signed main(){
	
	
	if(ifstream("GS.INP")){
		freopen("GS.INP","r",stdin);
		freopen("GS.OUT","w",stdout);
	}
	cin>>n;
	
	for(int i = 1;i <= n;i++){
		cin>>s[i];
	}
	
	sort(s + 1,s + 1 + n,cmp);
	
	if(n == 1)cout<<s[1];
	else if(n == 2){
		
		string res1 = s[1] + s[2];
		string res2 = s[2] + s[1];
		
		if(cmp(res1,res2))cout<<res1;
		else cout<<res2; 
		
	}else{
		
		string res = "";
		
		for(int i = 1;i <= 3;i++){
			for(int j = 1;j <= 3;j++){
				for(int z = 1;z <= 3;z++){
					if(i != j && j != z && z != i){
						string res2 = s[i] + s[j] + s[z];
						if(cmp(res2,res))res = res2;
					}
				}
			}
		}
		
		cout<<res;
		
	}
}