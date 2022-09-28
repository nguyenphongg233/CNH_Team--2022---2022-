#include<bits/stdc++.h>

#define X first
#define Y second

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;


struct query{
	int x,y,z,id;
	
	bool operator< (const query &a){
		if(x != a.x)return x <= a.x;
		if(y != a.y)return y <= a.y;
		return z <= a.z;
	}
};

query q[MAX];
int n;
signed main(){
	
	cin>>n;
	for(int i = 1,x,y,z;i <= n;i++){
		cin>>x>>y>>z;
		q[i] = {x,y,z,i};
	}
	
	sort(q + 1,q + 1 + n);
	
	for(int i = 1;i <= n;i++){
		//cout<<q[i].x<<" "<<q[i].y<<" "<<q[i].z<<"\n";
		cout<<q[i].id<<" "<<q[i + 1].id<<"\n";
		i++;
	}
	
	

	
}