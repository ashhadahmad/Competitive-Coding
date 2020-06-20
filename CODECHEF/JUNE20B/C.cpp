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
	int n;
	cin >> n; 
	vector<int> a(n, 0);
	for(int i=0; i<n; i++) cin >> a[i];
	int count5 = 0, count10 = 0;
	for(int i=0; i<n; i++){
		if(a[i] == 5) ++count5;
		else if(a[i] == 10){
			if(count5 == 0){
				cout << "NO\n";
				return;
			}
			else{
				--count5;
				++count10;
			}
		}
		else{
			if(count10 > 0){
				--count10;
			}
			else if(count5 > 1){
				count5 -= 2;
			}
			else{
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
	return;
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