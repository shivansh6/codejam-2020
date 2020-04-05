#include<bits/stdc++.h>
#define ff first
#define ss second
#define pi pair<int,int>
#define JaldiKarDeYaara ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define all(sort_it) (sort_it).begin(),(sort_it).end()
#define pb push_back
using namespace std;

void solve_it(int tt){
	int var1,var2,n;
	int i;
	cin >> n;
	vector<pair<pi,int>> ans_vec;
	for(i = 0; i < n; i++){
		cin >> var1 >> var2;
		ans_vec.pb({{var1,var2},i});
	}

	sort(all(ans_vec));
	char cameron[1445];
	char jame[1445];
	string ans(n,' ');

	memset(cameron,'-',sizeof(cameron));
	memset(jame,'-',sizeof(jame));
	
	for(i = 0; i < n; i++){
		var1 = (ans_vec[i].ff).ff;
		var2 = (ans_vec[i].ff).ss;
		string came(cameron+var1,var2-var1);
		string jam(jame+var1,var2-var1);
		string req(var2-var1,'-');
		if(req.compare(came) == 0){
			ans[ans_vec[i].ss] = 'C';
			memset(cameron+var1,'+',sizeof(char)*(var2-var1));
		}
		else if(req.compare(jam) == 0){
			ans[ans_vec[i].ss] = 'J';
			memset(jame+var1,'+',sizeof(char)*(var2-var1));	
		}
		else{
			cout << "Case #" << tt << ": " << "IMPOSSIBLE" << endl;
			break;
		}
	}
	if(i == n){
		cout << "Case #" << tt << ": " << ans << endl;
	}
}

int main(){
	JaldiKarDeYaara;
	int testcases;
	cin >> testcases;
	for(int j = 1; j <= testcases; j++){
		solve_it(j);
	}
}