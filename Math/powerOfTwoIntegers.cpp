vector<int> generatePrimes(int n)
{
	vector<bool> primes(n + 1, 1);

	primes[0] = primes[1] = 0;
	for (int i = 2; i * i <= n; i++)
	{
		if (primes[i])
		{
			for (int j = i * i; j <= n; j += i)
				primes[j] = 0;
		}
	}
	vector<int> val;
	for (int x : primes)
	{
		if (x)
			val.push_back(x);
	}

	return val;
}


int Solution::isPower(int A) {
	int num = min(1e5 + 3, sqrt(A) + 1);
	vector<int> primes = generatePrimes(num);

	int cnt = 0;
	int prime = 0;
	for (int x : primes)
	{
		if (A % x == 0) {
			prime = x;
			cnt++;

			if (cnt > 1)
				return 0;
		}
	}

	if (prime != A)
		return 1;

	return 0;

}
