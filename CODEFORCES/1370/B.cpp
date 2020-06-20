#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n;
	cin >> n;
	vector<int> a(n + n);
	for(int i=0; i < n + n; i++) cin >> a[i];
	vector<int> even, odd;
	for(int i=0; i< n + n; i++){
		if(a[i] & 1){
			odd.push_back(i+1);
		}
		else{
			even.push_back(i+1);
		}
	}

	vector<pair<int, int> > vp;

	for(int i=1; i<odd.size(); i+=2){
		vp.push_back(make_pair(odd[i-1], odd[i]));
	}
	for(int i=1; i<even.size(); i+=2){
		vp.push_back(make_pair(even[i-1], even[i]));
	}

	for(int i=0; i<n-1; i++){
		cout << vp[i].first << " " << vp[i].second << endl;
	}
}

int main(){
	IOS;
	int t = 1; 
	cin >> t;
	while(t--) solve();
	return 0;
}