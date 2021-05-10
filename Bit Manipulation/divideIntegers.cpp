class Solution {
public:
	int divide(int A, int B) {
		if (A == INT_MIN && B == -1) {
			return INT_MAX;
		}
		long dvd = labs(A), dvs = labs(B), ans = 0;
		bool sign = A > 0 ^ B > 0 ? 0 : 1;
		while (dvd >= dvs) {
			long temp = dvs, m = 1;
			while (temp << 1 <= dvd) {
				temp <<= 1;
				m <<= 1;
			}
			dvd -= temp;
			ans += m;
		}
		return (sign) ? ans : -ans;
	}
};

class Solution {
public:
	int divide(int a, int b) {
		if (b == 0)return INT_MAX ;
		if (a == 0)return 0 ;
		if (b == 1)return a ;
		if (a == INT_MIN && b == -1)return 2147483647 ;


		if (a == INT_MIN) {
			if (b & 1)
				return divide(a + 1, b);

			return divide(a >> 1, b >> 1);
		}


		if (b == INT_MIN)
			return 0;
		int sign = (a < 0) ^ (b < 0) == 0 ? 1 : -1 ;
		a = abs(a) ;
		b = abs(b) ;
		int ans = 0 ;
		while (a - b >= 0) {
			ans++ ;
			a = a - b ;
		}
		return ans * sign ;

	}
};