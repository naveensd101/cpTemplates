#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long llp;
#define mod 1000000007

struct hash_pair {
	template<class T1, class T2>
	size_t operator()(const pair<T1, T2>&p) const {
		auto hash1 = hash<T1>{}(p.first);
		auto hash2 = hash<T2>{}(p.second);
		return hash1 ^ hash2;
	}
};

int main() {
	unordered_map<pair<int, int>, int, hash_pair> m;
	m[{1,2}]++;
	cout << m[{1,2}];
	return 0;
}
