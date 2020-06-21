#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long

void solve(){
	int n;
	cin >> n;
	string a,b;
	cin >> a >> b; 
	int count[2] = {0};
	for(int i=0; i<n; i++){
		count[a[i] - '0']++;
	}
	for(int i=0; i<n; i++){
		count[b[i] - '0']--;
	}
	
	if(count[0] != 0 || count[1] != 0) {
		cout << "-1\n";
		return;
	}

	vector<bool> bad(n, false);
	for(int i=0; i<n; i++){
		if(a[i] != b[i]) bad[i] = true;
	}

	int ending[2] = {0};

	for(int i=0; i<n; i++) {
		if(bad[i]) {
			int num = a[i] - '0';
			if(ending[!num] > 0) --ending[!num];
			++ending[num];
		}
	}

	cout << ending[0] + ending[1] << endl;
}

int main(){
	IOS;
	int t = 1; 
	// cin >> t;
	while(t--) solve();
	return 0;
}