#define ll long long int

const ll N = 1e5 + 1;
const ll mod = 1e9 + 7;
ll prod[N];

void precompute() {
	for (ll i = 1; i < N; i++) {
		prod[i] = i;
	}

	for (ll i = 2; i < N; i++) {
		for (ll j = 2 * i; j < N; j += i) {
			prod[j] = ((prod[j] % mod) * (i % mod)) % mod;
		}
	}

}

bool compare(pair<ll, ll> a, pair<ll, ll> b) {
	return a.first > b.first;
}
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
	precompute();
	ll n = A.size();
	stack<ll> s;
	s.push(0);
	ll freq[n];
	for (ll i = 1; i < n; i++) {
		while (!s.empty() && A[s.top()] <= A[i]) {
			ll idx = s.top();
			s.pop();
			ll left = idx + 1;
			ll right = i - idx;
			if (!s.empty()) {
				left = idx - s.top();
			}
			freq[idx] = left * right;
		}
		s.push(i);
	}

	while (!s.empty()) {
		ll idx = s.top();
		s.pop();
		ll left = idx + 1;
		ll right = n - idx;
		if (!s.empty()) {
			left = idx - s.top();
		}
		freq[idx] = left * right;
	}


	vector<pair<ll, ll>> store;
	for (ll i = 0; i < n; i++) {
		store.push_back({prod[A[i]], freq[i]});
	}

	sort(store.begin(), store.end(), compare);

	for (ll i = 1; i < n; i++) {
		store[i].second += store[i - 1].second;
	}

	vector<ll> ans;
	for (ll i = 0; i < B.size(); i++) {
		ll q = B[i];
		ll s = 0;
		ll e = n - 1;

		while (s <= e) {
			ll m = s + (e - s) / 2;

			if (q <= store[0].second) {
				ans.push_back(store[0].first);
				break;
			}

			if (q <= store[m].second && q > store[m - 1].second) {
				ans.push_back(store[m].first);
				break;
			}

			else if (q > store[m].second) {
				s = m + 1;
			}

			else
				e = m - 1;


		}
	}

	return ans;
}
