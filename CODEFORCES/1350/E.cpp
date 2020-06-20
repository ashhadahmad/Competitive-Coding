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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<string> ip(n);
    vector<vector<ll> > store(n, vector<ll>(m, -1));
    vector<vector<bool> > vis(n, vector<bool>(m, false));
    queue<pair<ll,ll> > q;
    ll move_x[4] = {1,0,-1,0};
    ll move_y[4] = {0,1,0,-1};
    for(ll i=0; i<n; i++) cin >> ip[i];
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            for(ll k=0; k<4; k++){
                ll nexti = i + move_x[k];
                ll nextj = j + move_y[k];
                if(nexti >= 0 && nexti < n && nextj >= 0 && nextj < m){
                    if(ip[nexti][nextj] == ip[i][j]) {
                        store[i][j] = 0;
                        vis[i][j] = true;
                        q.push(make_pair(i, j));
                        break;
                    }
                }
            }
        }
    }

    
    while(!q.empty()){
        ll curx = q.front().first, cury = q.front().second;
        q.pop();
        for(ll i=0; i<4; i++){
            ll nextx = curx + move_x[i];
            ll nexty = cury + move_y[i];
            if(nextx >= 0 && nextx < n && nexty >= 0 && nexty < m){
                if(!vis[nextx][nexty]) {
                    vis[nextx][nexty] = true;
                    store[nextx][nexty] = store[curx][cury] + 1;
                    q.push(make_pair(nextx, nexty));
                }
            }
        }
    }
    while(k--){
        ll i,j,atDay;
        cin >> i >> j>> atDay;
        --i, --j;
		if (store[i][j] == -1 || atDay < store[i][j] || (atDay - store[i][j]) % 2 == 0) {
			cout << ip[i][j] << '\n';
		}
		else {
			cout << (char) (ip[i][j] ^ 1) << '\n';
		}
    }
}

int main(){
	FAST(); 
	lol();
	ll t; t = 1; while(t--) solve();
	return 0;
}