#include<bits/stdc++.h>
using namespace std;
#define FASTIO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

void localIO(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
}

void solve(){
	int n, x; 
	cin >> n >> x;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	vector<int> pre_sum(n+1, 0);
	for(int i=1; i<=n; i++){
		pre_sum[i] = (pre_sum[i-1] + a[i-1]) % x;
	}	
	int lastIndex = -1;
	int ans = -1; 
	for(int i=1; i<=n; i++){
		if(pre_sum[i] != 0){
			ans = i;
			if(lastIndex == -1){
				lastIndex = i;
			}
		}
		else{
			if(lastIndex == -1){
				continue;
			}
			else{
				ans = max(ans, i - lastIndex);
			}
		}
	}

	cout << ans << "\n";

}

int main(){
	FASTIO(); 
	localIO();
	int t; 
	cin >> t;
	while(t--) 
		solve();
	return 0;
}