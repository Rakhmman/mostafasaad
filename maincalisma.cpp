#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include<unordered_map>

#define ios ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
#define S second
#define F first
#define pb push_back
#define nl '\n'
#define NL cout << '\n';
#define EX exit(0)
#define all(s) s.begin(), s.end()
#define FF(i, n) for(int i = 1; i <= n; i++)

const long long MXN = 1e5 + 1;
const double eps = 1e-10;
const double pi = acos(-1.0);
const long long OO = 1e18 + 1;
const int MNN = 1e5 + 1;
const int MOD = 1e9 + 7;
const long long INF = 1e18;

typedef long long llong;

using namespace std;

llong n, q, cost[MXN], color[MXN], a, b, dp[MXN], t[MXN * 4], mx[2];
bool used[MXN];

void upd(llong cur){
	if(dp[cur] > dp[mx[0]]){
		mx[1] = mx[0];
		mx[0] = cur;
		return ;
	}if(dp[cur] > dp[mx[1]] && cur != mx[0]){
		mx[1] = cur;
		return ;
	}
}

int main(){
	ios;
	//freopen("input.txt", "r", stdin);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> cost[i];
	}for(int i = 1; i <= n; i++){
		cin >> color[i];
	}for(int i = 1; i <= q; i++){
		cin >> a >> b;
		llong ans = 0;
		for(int i = 1; i <= n; i++){
			dp[i] = -INF;
			used[i] = 0;
			mx[0] = 0;
			mx[1] = 0;
		}for(int i = 1; i <= n; i++){
			if(used[color[i]] == 1) dp[color[i]] = max(dp[color[i]] + cost[i] * a, dp[color[i]]);
			llong mxget = 0;
			if(mx[0] == color[i]){
				mxget = mx[1];
			}else{
				mxget = mx[0];
			}dp[color[i]] = max(dp[mxget] + cost[i] * b, dp[color[i]]);
			used[color[i]] = 1;
			upd(color[i]);
			ans = max(dp[color[i]], ans);
		}cout << ans << nl;
	}
	return 0;
}
