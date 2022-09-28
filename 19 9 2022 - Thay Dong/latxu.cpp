#include<bits/stdc++.h>

using namespace std;

#define int long long
const long long INF = 1e9;

int n;
int a[15];
int cnt = 0;


int calc(int mask){
	
	int b[15];
	for(int i = 0;i < n;i++)b[i] = a[i];
	
	//cout<<"\n";
	int cnt = 0;
	for(int i = 0;i < n;i++){
		if(mask >> i & 1){
			b[0] ^= (1 << i);
			if(i > 0)b[0] ^= (1 << (i - 1));
			if(i < n - 1)b[0] ^= (1 << (i + 1));
			b[1] ^= (1 << i);
			cnt++;
		}
	}
	
	//printt(b[0]);
	for(int i = 1;i < n;i++){
		
		int mask2 = b[i - 1];
		
		for(int j = 0;j < n;j++){
			
			if(mask2 >> j & 1){
				
				b[i] ^= (1 << j);
				if(j > 0)b[i] ^= (1 << (j - 1));
				if(j < n - 1)b[i] ^= (1 << (j + 1));
				b[i + 1] ^= (1 << j);
				b[i - 1] ^= (1 << j);
				cnt++;
				
			}
			
		}
		
		//printt(b[i]);
		
	}
	
	
	for(int i = 0;i < n;i++){
		//cout<<b[i]<<" ";
		//printt(b[i]);
		if(b[i] != 0)return -1;
	}
	
	return cnt;
	
	
}
signed main(){
	n = 4;
	
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			char z;
			cin>>z;
			
 			if(z == 'b')
			a[i] += (1 << j);
		}
		
	}
	
	
	int ans = INF;
	for(int i = 0;i < n;i++){
		for(int mask = 0;mask < (1 << n);mask++){
			int x = calc(mask);
			if(x != -1)ans = min(ans,x);
			
			
		}
	}
	

	
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			
			a[i] ^= (1 << j);

			
		}
	}
	
	
	
	
	for(int i = 0;i < n;i++){
		for(int mask = 0;mask < (1 << n);mask++){
			int x = calc(mask);
			if(x != -1)ans = min(ans,x);
			
			
		}
	}
	
	cout<<(ans == INF ? -1 : ans);
}