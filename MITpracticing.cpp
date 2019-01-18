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

//#define S second
//#define F first
#define pb push_back
#define nl '\n'
#define NL cout << '\n';
#define EX exit(0)
#define all(s) s.begin(), s.end()
#define FOR(i, start, finish, k) for(int i = start; i <= finish; i += k)

const long long MXN = 1e5 + 1;
const long long MNN = 1e5 + 1;
const long long MOD = 1e9;
const long long INF = 1e18;
const long long OO = 1e9 + 500;

typedef long long llong;
typedef unsigned long long ullong;

using namespace std;

int bg, x;
llong A, B, last;

int ask(llong a, llong b){
	cout << '?' << ' ' << a << ' ' << b << endl;
	int x;
	cin >> x;
	fflush(stdout);
	return x;
}

void choose(llong i){
	if(last == 1){
		A ^= (1 << i);
	}else{
		B ^= (1 << i);
	}last = x;
}

void guess(llong a, llong b){
	cout << '!' << ' ' << a << ' ' << b << endl;
	exit(0);
}

int main(){
	x = ask(0, 0);
	last = x;
	for(llong i = 29; i >= 0; i--){
		x = ask(((1 << i) ^ A), B);
		if(x == -1){
			x = ask(A, ((1 << i) ^ B));
			if(x == 1){
				A ^= (1 << i);
				B ^= (1 << i);
			}else{
				choose(i);
			}
		}else if(x == 0){
			choose(i);
		}else{
			x = ask(A, ((1 << i) ^ B));
			if(x == 1){
				choose(i);
			}
		}
	}guess(A, B);
	return 0;
}
