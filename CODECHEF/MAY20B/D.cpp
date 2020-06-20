#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

void lol(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("../Downloads/in.txt", "r", stdin);
	// freopen("../Downloads/output.txt", "w", stdout);
	freopen("output.txt", "w", stdout);
	#endif	
}

int swapThree(vector<int> &v, vector<int> &atIndex, int f, int s, int t, vector<vector<int> > &ans){
	
	vector<int> smallAns;
	smallAns.push_back(f);smallAns.push_back(s);smallAns.push_back(t);
	ans.push_back(smallAns);

	int temp = v[t];
	v[t] = v[s];
	v[s] = v[f];
	v[f] = temp;

	atIndex[v[f]] = f;
	atIndex[v[s]] = s;
	atIndex[v[t]] = t;

	int count = 0;
	count += v[f] == f;
	count += v[s] == s;
	count += v[t] == t;

	// printf("SWAPPING INDEXES : %d,%d,%d\nArray after Swapping : ",f,s,t);
	// for(int i=1; i<v.size(); i++) cout << v[i] << " ";
	// cout << endl;

	return count; 
}

void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> v(n+1);
	vector<int> atIndex(n+1);
	for(int i=1; i<=n; i++) {
		cin >> v[i];
		atIndex[v[i]] = i;
	}
	priority_queue<int> q;
	vector<bool> sent_back(n+1, false);

	int count = 0;
	int bad = 0; 
	vector<vector<int> > ans;

	for(int i=1; i<=n; i++){
		if(atIndex[i] != i) q.push(i), ++bad;
	}

	while(!q.empty()){
		if(bad == 0) break;
		int idx = q.top();
		q.pop();
		if(atIndex[idx] == idx) continue;
		int atFirstIndex = v[idx];
		int whereIsFirstVal = atIndex[idx]; 

		if(atFirstIndex != whereIsFirstVal){
			int best = swapThree(v,atIndex,idx, atFirstIndex, whereIsFirstVal,ans);
			bad -= best;
		}
		else{
			if(!sent_back[idx]){
				// printf("Sending %d at the back of the queue\n", idx);
				sent_back[idx] = true;
				q.push(idx);
			}
			else {
				bool use = false;
				int nextIdx = -1;
				while(!q.empty()){
					int tempIdx = q.top();
					q.pop();
					if(atIndex[tempIdx] == tempIdx || atFirstIndex == tempIdx) continue;
					else {
						use = true;
						nextIdx = tempIdx;
						break;
					}
				}
				if(use){
					int best = swapThree(v,atIndex,idx,nextIdx,whereIsFirstVal,ans);
					bad -= best;
					q.push(nextIdx);
				}
				else{
					cout << "-1\n";
					return;
				}
			}
		}
	}


	if(ans.size() > k) {
		cout << "-1\n";
		return;
	}

	cout << ans.size() << endl;
	for(int i=1; i<v.size(); i++) cout << v[i] << " ";
	cout << endl;
	// for(auto x: ans){
	// 	for(auto y: x) cout << y << " ";
	// 	cout << endl;
	// }

}

int main(){
	FAST(); 
	lol();
	int t; cin >> t; while(t--) solve();
	return 0;
}