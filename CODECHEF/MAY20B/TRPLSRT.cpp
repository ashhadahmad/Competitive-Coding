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

struct triplet{
	ll f,s,t;
	triplet(){
		f=s=t=0;
	}
	triplet(ll f1, ll s1, ll t1){
		f=f1, s=s1, t=t1;
	}
};

void solve(){
	ll n, k;
	cin >> n >> k;
	vector<ll> v(n+1);
	for(ll i=1; i<=n; i++) cin >> v[i];
	vector<bool> vis(n+1, false);
	vector<triplet> ans;
	vector<pair<ll, ll> > double_swaps;

	for(ll i=1; i<=n; i++){
		if(vis[i] || v[i] == i) continue;
		else{
			vector<ll> cur_cycle;
			ll cur_idx = i;
			while(!vis[cur_idx]){
				cur_cycle.push_back(cur_idx);
				vis[cur_idx] = true;
				cur_idx = v[cur_idx];
			}
			ll cur_size = (ll)cur_cycle.size();
			if(cur_size == 2) double_swaps.push_back(make_pair(cur_cycle[0], cur_cycle[1]));
			else{
				if(cur_size&1){
					for(ll i=1; i<cur_size; i+=2){
						triplet temp(cur_cycle[0], cur_cycle[i], cur_cycle[i+1]);
						ans.push_back(temp);
					}
				}
				else{
					for(ll i=1; i<cur_size-1; i+=2){
						triplet temp(cur_cycle[0], cur_cycle[i], cur_cycle[i+1]);
						ans.push_back(temp);
					}
					double_swaps.push_back(make_pair(cur_cycle[0], cur_cycle[cur_size-1]));
				}
			}
		}
	}

	ll double_size = (ll)double_swaps.size();
	if(double_size&1){
		cout << "-1\n";
		return;
	}

	for(ll i=0; i<double_size; i+=2){
		pair<ll,ll> p1 = double_swaps[i], p2 = double_swaps[i+1];
		triplet t1(p1.first, p1.second, p2.first);
		triplet t2(p1.first, p2.second, p2.first);
		ans.push_back(t1);ans.push_back(t2);
	}

	if(ans.size() > k) {
		cout << "-1\n";
		return;
	}

	for(auto x: ans){
		ll temp = v[x.t];
		v[x.t] = v[x.s];
		v[x.s] = v[x.f];
		v[x.f] = temp;
	}

	cout << ans.size() << endl;
	for(ll i=1; i<v.size(); i++) cout << v[i] << " ";
	cout << endl;

	// for(auto x: ans){
	// 	printf("%lld %lld %lld\n", x.f, x.s, x.t);
	// }

}

int main(){
	FAST(); 
	lol();
	ll t; cin >> t; while(t--) solve();
	return 0;
}