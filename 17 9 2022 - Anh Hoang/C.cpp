#include<bits/stdc++.h>

using namespace std;
#define int long long 
#define double long double
const long long MAX = 1e5 + 5;
#define ii pair<int,int>
#define X first
#define Y second 

int n;
int b;
double w;

struct query{
	double e,w;
	int c;
};


query a[MAX];
double res = 0;


void sub1(){
	
	
	
	for(int mask = 0;mask < (1 << n);mask++){
		
		int cost_ = 0;
		double ww = w;
		double en_ = 0;
		bool ok = 1;
		for(int i = 0;i < n;i++){
			if(mask >> i & 1){
				
				double et = a[i].e;
				double wt = a[i].w;
				int ct = a[i].c;
				
				cost_ += ct;
				en_ += et;
				ww += wt;
				
				if(cost_ > b){
					
					ok = 0;
					break;
				}
				
			}
		}
		
		double q = en_ / ww;
		if(ok)res = max(res,en_ / ww);
	}
	
	
	
	cout<<setprecision(4)<<fixed<<res<<"\n";
	
}


vector<vector<double>> dp;
void sub2(){
	
	dp.resize(n + 5,vector<double>(b + 5,0));
	
	// xet den thg thu i da tieu j dong dong voi e nhieu nhat 
	
	for(int i = a[0].c;i <= b;i++){
		dp[0][i] = a[0].e;
	}

	for(int i = 1;i < n;i++){
		
		double et = a[i].e;
		int ct = a[i].c;

		for(int mm = 0;mm <= b;mm++){
			if(mm >= ct)
				dp[i][mm] = max(dp[i - 1][mm],dp[i - 1][mm - ct] + et);
			else
				dp[i][mm] = dp[i - 1][mm];
		}
		
	}
	
	for(int i = 0;i < n;i++){
		for(int mm = 0;mm <= b;mm++){
			//cout<<dp[i][mm]<<" ";
			res = max(res,dp[i][mm] / w);
		}
		//cout<<"\n";
	}
	
	
	cout<<setprecision(4)<<fixed<<res;
	
	
	
	
}

int last = -1;

void sub3(){
	
	sort(a + 1,a + 1 + n,[&](const query &c,const query &b){
		return (c.e - c.w > b.e - b.w);
	});
	
	int er = b / last;
	double ww = w;
	double ew = 0;
	for(int i = 0;i < min(er,n);i++){
		ew += a[i].e;
		ww += a[i].w;
	}
	cout<<setprecision(4)<<fixed<<ew / ww;
	
	
}
signed main(){
	
	cin>>n>>b>>w;
	
	bool canuses2 = 1;
	bool can3 = 1;
	
	for(int i = 0,c;i < n;i++){
		double w,e;
		cin>>e>>w>>c;
		a[i] = {e,w,c};
		
		if(w != 0)canuses2 = 0;
		if(last == -1)last = c;
		else if(last != c)can3 = 0;
	}
	
	
	

	if(n <= 20){
		sub1();
		return 0;
	}
	if(canuses2){
		sub2();
		return 0;
	}
	if(can3){
		sub3();
		return 0;
	}
	
	
	
}