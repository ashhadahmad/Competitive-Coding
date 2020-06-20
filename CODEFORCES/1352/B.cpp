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
	int n,k;
	cin >> n >> k;
	if(n < k) {
		cout << "NO\n";
		return;
	}
	if(n&1){
		if(k&1){
			cout << "YES\n";
			for(int i=0; i<k-1; i++){
				cout << 1 << " ";
			}
			cout << n-k+1 << endl;
			return;
		}
		else{
			cout << "NO\n";
			return;
		}
	}
	else{
		if(k > n/2){
			if((n-k+1)&1) {
				cout << "YES\n";
				for(int i=0; i<k-1; i++){
					cout << 1 << " ";
				}
				cout << n-k+1 << endl;
				return;
			}
			else{
				cout << "NO\n";
				return;
			}
		}
		else{
			cout << "YES\n";
			for(int i=0; i<k-1; i++) cout << 2 << " ";
			cout << n - 2 * k + 2;
			cout << endl;
			return ;
		}
	}
}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--) solve();
	return 0;
}