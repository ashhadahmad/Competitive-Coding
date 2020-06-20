#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

void lol(){
	#ifndef ONLINE_JUDGE
	freopen("/Users/mac/Documents/Codes/input.txt", "r", stdin);
	freopen("/Users/mac/Documents/Codes/output.txt", "w", stdout);
	#endif	
}

void solve(){
	string a,b;
	cin >> a >> b;
	int n = a.size(); 
	int left = 0, right = n-1;
	while(a[left] == b[left]) left++;
	while(a[right] == b[right]) right--;
	vector<int> gaps;
	bool isgap = false;
	int gapcount = 0, l = 0;
	for(int i = left; i <= right; i++){
		if(a[i] == b[i]){
			if(isgap) gapcount++;
			else isgap = true, gapcount++;
		}
		else{
			l++;
			if(isgap) {
				gaps.push_back(gapcount);
				isgap = false;
				gapcount = 0;
			}
		}
		// printf("%c,%c - isgap:%d, gapcount:%d\n", a[i], b[i], isgap, gapcount);

	}
	sort(gaps.begin(), gaps.end());
	int k = gaps.size() + 1;
	ll ans = k * l;
	// cout << ans << endl;
	for(int i=0; i<gaps.size(); i++){
		--k, l += gaps[i];
		// cout << k << " " << l << endl;
		ans = min(ans, (ll) k * l);
	}
	cout << ans << endl;
}

using namespace std;
int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--){
		solve();
	}
	return 0;
}