#include<bits/stdc++.h>

#define int long long
#define X first
#define Y second

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

const long long MAX = 2e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;


int n;
int snt[MAX];
int cnt[MAX];

signed main(){
	
	cin>>n;
	
	
	for(int i = 2;i * i< MAX;i++){
		if(!snt[i]){
			for(int j = i * i;j < MAX;j += i)snt[j] = i;
		}
	}
	
	for(int i = 1;i < MAX;i++)if(!snt[i])snt[i] = i;
	
	while(n != 1){
		cnt[snt[n]]++;
		n /= snt[n];
	}
	
	int sum = 1;
	int up = 0;
	
	vector<int> rt;
	for(int i = 1;i < MAX;i++){
		if(cnt[i] != 0){
			
			sum *= i;
			//up = max(up,cnt[i]);
			rt.push_back(cnt[i]);
			//cout<<i<<" "<<cnt[i]<<"\n";
		}
	}
	
	cout<<sum<<" ";
	
	sort(rt.begin(),rt.end(),[&](const int &a,const int &b){
		return a > b;
	});
	
	int yu = 0;
	bool ok = 0;
	for(auto v : rt){
		
		int id = 0;
		for(int i = 1;i < 32;i++){
			
			if(v <= (1 << i) && v > (1 << (i - 1))){
				id = i;
				break;
			}
			
		}
		
		//cout<<v<<" "<<(1 << id)<<" "<<id<<"\n";
		if(v != (1 << id))id++,ok = 1;
		
		yu = max(yu,id);
		
		break;
	}
	
	if(ok)return cout<<yu,0;
	for(int i = 1;i < rt.size();i++)if(rt[i] != rt[0]){
		yu++;
		break;
	}
	
	cout<<yu;
	

	
}