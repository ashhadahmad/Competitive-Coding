#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

void lol(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif	
}

void solve(){
	int n;
	cin >> n;
	vector<int> a(n+1);
	for(int i=1; i<=n; i++) cin >> a[i];
	vector<int> ans(n+1, 1);
	ans[1] = 1;
	for(int i=1; i<=n/2; i++){
		// printf("At: %d : ",i);
		for(int j=i+i; j<=n; j+=i){
			// printf("%d ",j);
			if(a[j] > a[i]) ans[j] = max(ans[i] + 1, ans[j]);
		}
	}
	// for(int i=1; i<=n; i++) cout << i << " " << ans[i] << endl;
	int fans = 0;
	for(int i=1; i<=n; i++) fans = max(fans, ans[i]);
	cout << fans << endl;	
}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--) solve();
	return 0;
}