#include<bits/stdc++.h>
using namespace std;
vector<long long> seive(long long n) {
/*Returns a vector<int> with all the prime numbers till n
 * - Time complexity: O(nlglg(n))
 * - n >= 2
 * - if n is less returns a empty vector
*/
	vector<bool> is_prime(n+1, 1);
	is_prime[0] = is_prime[1] = 0;
	for(long long i = 2; i*i <= n; ++i) {
		if(is_prime[i]) {
			for(long long j = i*i; j <= n; j+=i) is_prime[j] = 0;
		}
	}
	
	vector<long long> prime;
	for(long long i = 0; i < n+1; ++i) if(is_prime[i]) prime.push_back(i);
	return prime;
}
vector<long long> primes;
vector<long long> trial_division_with_primes(long long n) {
/*Returns a vector<long long> with all the prime factors of n
 * - Requires a primes vector<long long> that has prime number till sqrt(n)
 * - if n = 18
 * - [2 3 3]
 * - for n = 1, n = 0 it returns a empty vector
 * - for prime numbers it returns just that number
*/
	vector<long long> factorization;
	for(long long d: primes) {
		if(d*d > n) break;
		while(n%d == 0) {
			factorization.push_back(d);
			n /= d;
		}
	}
	if(n > 1) factorization.push_back(n);
	return factorization;
}

void solution(/*long long tc = 0*/) {
	int n;
	cin >> n;
    vector<long long> v = trial_division_with_primes((long long)n);
	for(long long x: v) cout << x << ' ';
	cout << '\n';
}

int main() {
	primes = seive(1e6);
    long long tc = 1;
    cin >> tc;
    for (long long t = 0; t < tc; ++t) solution(/*t*/);


    return 0;
}
