#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(auto &a:arr) cin>>a;

        int dp[n][2];
        dp[0][0]=arr[0];
        dp[0][1]=arr[0];

        int ans=INT_MIN;
        for(int i=1;i<n;i++){
            dp[i][0]=max(arr[i], arr[i]+dp[i-1][0]);
            dp[i][1]=max((arr[i]*arr[i]), max(((arr[i]*arr[i])+dp[i-1][0]),arr[i]+dp[i-1][1]));
            ans=max(ans,max(dp[i][0],dp[i][1]));
        }
        cout<<ans<<endl;
    }
}
