#include<bits/stdc++.h>

#define int long long
#define X first
#define Y second

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

const long long MAX = 1e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

int n;
int a[MAX];
stack<int> st;
int mp[MAX];
signed main(){
	
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	for(int i = 1;i <= n;i++)cin>>a[i];
	st.push(a[1]);
	mp[a[1]]++;
	int cnt = 0;
	for(int i = 2;i <= n;i++){
		
		
		if(st.size() && st.top() > a[i]){
			cnt++;
			//cout<<i<<" 1\n";
			mp[a[i]]++;
			st.push(a[i]);
			continue;
		}
		
		int cnt1 = 0;
		while(st.size() && a[i] > st.top())mp[st.top()]--,st.pop(),cnt1++;
		cnt1 += mp[a[i]];
		
		if(st.size() > mp[a[i]])cnt1++;
		
		cnt += cnt1;
		//cout<<i<<" "<<mp[a[i]]<<" ";
		//cout<<cnt1<<"\n";
		st.push(a[i]);
		
		mp[a[i]]++;
	}
	
	cout<<cnt;
	
	

	
}