#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef  long long int lli;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inf (1000*1000*1000+5)

const int mod=1e9+9;
const int num=1e5+5;
lli dp[num+1];
lli ans[6][num+1]={0};

void init(){
	for(int i=0;i<num;i++)dp[i]=0;
}

int32_t main(){
	boost;
	int t=1;
	//cin>>t;
	init();
	while(t--){
		lli n,p,k;
		cin>>n>>k>>p;
		lli a[n];
		for(int i=0;i<n;i++)cin>>a[i];
		lli cnt=0;
		for(int i=1;i<n;i++){
			if(a[i]-a[i-1]<=k)dp[i]=cnt;
			else dp[i]=++cnt;
		}
		lli l,m;
		while(p--){
			cin>>l>>m;
			l--,m--;
			if(dp[l]!=dp[m])cout<<"No\n";
			else cout<<"Yes\n";
		}
	}
	return 0;
}
