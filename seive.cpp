#include<bits/stdc++.h>
using namespace std;
vector<int> seive(int n) {
/*Returns a vector<int> with all the prime numbers till n
 * - Time complexity: O(nlglg(n))
 * - n >= 2
 * - if n is less returns a empty vector
*/
	vector<bool> is_prime(n+1, 1);
	is_prime[0] = is_prime[1] = 0;
	for(int i = 2; i*i <= n; ++i) {
		if(is_prime[i]) {
			for(int j = i*i; j <= n; j+=i) is_prime[j] = 0;
		}
	}
	
	vector<int> primes;
	for(int i = 0; i < n+1; ++i) if(is_prime[i]) primes.push_back(i);
	return primes;
}

void solution(/*long long tc = 0*/) {
	int n;
	cin >> n;
	vector<int> primes = seive(n);
	for(int &i: primes) cout << i << ' ';
	cout << '\n';
}

int main() {

    long long tc = 1;
    cin >> tc;
    for (long long t = 0; t < tc; ++t) solution(/*t*/);


    return 0;
}
