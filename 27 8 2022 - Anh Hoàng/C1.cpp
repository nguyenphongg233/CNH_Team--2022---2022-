#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int INF = 1e9;
string s;
int a[N],b[N],cnt[10];
int dp[N][5];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    int n = s.size();
    s = "." + s;
    unordered_map<char,int>tran;

    tran['h'] = 1;
    tran['d'] = 2;
    tran['c'] = 3;
    tran['s'] = 4;

    for(int i = 1;i <= n;i++){
        a[i] = tran[s[i]];
        cnt[a[i]]++;
    }
    int ans = INF;
    int arr[4] = {1,2,3,4};

    do{
        memset(dp,0x3f,sizeof(dp));
        dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 0;j < 4;j++){
                if(a[i] != arr[j]){
                    if(j != 0)dp[i][j] = min(dp[i-1][j],dp[i-1][j-1]) + 1;
                    else dp[i][j] = dp[i-1][j] + 1;
                }
                else{
                    if(j != 0)dp[i][j] = min(dp[i-1][j],dp[i-1][j-1]);
                    else dp[i][j] = dp[i-1][j];
                }
            }
        }


        ans = min(ans,dp[n][3]);




    }while(next_permutation(arr,arr + 4));

    cout << ans;

    return 0;
}