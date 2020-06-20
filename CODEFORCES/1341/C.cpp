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
	int n; cin >> n;
	vector<pair<int, int> > v(n);
	for(int i=0; i<n; i++) {
		cin >> v[i].first;
		v[i].second = i;
	}
	vector<bool> vis(n+1, false);
	sort(v.begin(), v.end());

	int nextIdx = 0;
	bool useNextIdx = 0;
	bool ans = true;
	for(int i=0; i<n; i++){
		vis[v[i].second] = true;
		if(useNextIdx){
			if(v[i].second != nextIdx) {
				ans = false;
				break;
			}
			else{
				if(nextIdx == n-1) useNextIdx = false;
				else if(vis[nextIdx + 1]) useNextIdx = false;
				else{
					++nextIdx;
				}
			}
		}
		else{
			if(v[i].second == n-1) continue;
			else if(vis[v[i].second + 1]) continue;
			else useNextIdx = true, nextIdx = v[i].second + 1;
		}
	}

	cout << (ans ? "Yes\n" : "No\n");

}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--){
		solve();
	}
	return 0;
}