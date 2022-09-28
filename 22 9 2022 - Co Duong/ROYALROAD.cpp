#include<bits/stdc++.h>

using namespace std;
const long long N = 15,MOD = 1e9 + 7;
#define int long long
int n,m;
int s,t;


struct Matrix{
	int a[10][10];
	int row,col;
	
	Matrix(int n,int m){
		row = n;
		col = m;
		memset(a,0,sizeof a);
	}
	Matrix operator* (const Matrix &b){
		Matrix c(row,b.col);
		
		for(int i = 0;i < row;i++){
			for(int j = 0;j < b.col;j++){
				for(int k = 0;k < b.row;k++){
					c.a[i][j] = (c.a[i][j] + b.a[k][j] * a[i][k]) % MOD;
				}
			}
		}
		return c;
	}
};

Matrix power(Matrix a,int b){
	if(b == 1)return a;
	Matrix s = power(a,b / 2);
	return((b & 1) ? s * s * a : s * s);
}
signed main(){
	
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	if(ifstream("ROYALROAD.inp")){
		freopen("ROYALROAD.inp","r",stdin);
		freopen("ROYALROAD.out","w",stdout);
	}
	cin>>n>>m;
	
	Matrix a(n,n);
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			cin>>a.a[i][j];
		}
	}
	
	a = power(a,m);
	
	cin>>s>>t;
	

	cout<<a.a[s - 1][t - 1];
	
	
	
}