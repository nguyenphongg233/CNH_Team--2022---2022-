#include<bits/stdc++.h>

using namespace std;

const long long MAX = 1e6+ 5;
const long long N = 3e5 + 5;

#define int long long

int n,k,a[MAX],d[MAX];
vector<int> rt;

signed main(){
	
	cin>>n >> k;
	
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		rt.push_back(a[i]);
	}
	
	sort(rt.begin(),rt.end());
	rt.erase(unique(rt.begin(),rt.end()),rt.end());
	
	for(int i = 1;i <= n;i++){
		a[i] = lower_bound(rt.begin(),rt.end(),a[i]) - rt.begin() + 1;
	}
	
	int ans = 1,cnt = 0;
    int i = 1,j = 1;
    while(1){
        if(i > n || j > n)break;
        if(i > j)j++;
        if(d[a[j]] == 0){
            if(cnt > k){
                d[a[i]]--;
                if(d[a[i]] == 0)cnt--;
                i++;
                continue;
            }
            d[a[j]]++;
            cnt++;
            j++;
            continue;
        }
        ans = max(ans,d[a[j]]+1);
        d[a[j]]++;
        j++;
    }
 
    cout << ans;
	
	
	
}
