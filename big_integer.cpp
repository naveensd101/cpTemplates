bool lessthan(string &a, string &b) {
	// O(N), N = size of string
	// return true if a < b
	// string a and b should not have leading zeroes
	// format
	// ------
	// num = 123445
	// string = "544321"
	// string[0] = '5'
	if(a.size() < b.size()) return true;
	else if(a.size() > b.size()) return false;
	
	for(int i = (int)a.size(); i >= 0; --i) {
		if(a[i] == b[i]) continue;
		else return a[i] < b[i];
	}

	return false;
}
string add(string &a, string &b) {
	// O(N), N = size of string
	// num = 1234
	// string = "4321"
	string ans, t;
	if(lessthan(a, b)) {
		ans = b;
		t = a;
	}
	else {
		ans = a;
		t = b;
	}

	int carry = 0;
	for(int i = 0; i < (int)ans.size(); ++i) {
		int _a, _t;
		_a = ans[i] - '0';
		i < (int)t.size() ? _t = t[i] - '0' : _t = 0;
		_a += _t + carry;
		carry = _a / 10;
		_a = _a % 10;
		ans[i] = (char)(_a + '0');
	}
	if(carry) {
		ans += (char)(carry + '0');
	}
	return ans;
}
