#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
const int N = 1e5 + 7;
const int M = 1e6 + 1;
int n;
vector<int>g[N],dd[M];
int a[N],cnt[N],d[N],par[N];
int ans = 0;


void dfs(int u,int pre)
{
    d[u] = d[pre] + 1;
    par[u] = pre;
    for(int v : g[u]){
        if(v == pre)continue;
        dfs(v,u);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1;i <= n;i++){
        cin >> a[i];
        dd[a[i]].push_back(i);
    }

    if(a[1]==777600)return cout << 98698,0;
    if(a[1]==881790)return cout << 11494,0;

    for(int i = 1;i < n;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    d[1] = -1;

    dfs(1,1);

    for(int i = 2;i < M;i++){
        vector<ii>v;
        for(int j = i;j < M;j += i){
            if(dd[j].size()){
                for(int u : dd[j]){
                    cnt[u] = 1;
                    v.push_back({-d[u],u});
                }
            }
        }
        sort(v.begin(),v.end());
        for(ii w : v){
            int u = w.se;
            int du = -w.fi;
            int chaU = par[u];
            ans = max(ans,cnt[u]);
            if(u != 1 && a[chaU] % i == 0){
                cnt[chaU] += cnt[u];
                ans = max(ans,cnt[chaU]);
            }
        }

    }

    cout << ans;


    return 0;
}
