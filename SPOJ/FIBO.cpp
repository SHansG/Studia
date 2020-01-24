//Fibonacci

#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007;
long long int a, b, c, d;

class FiboNums {
public:
	long long a, b;
};

void fast_fib(long long int n, FiboNums &p)
{
	if (n == 0)
	{
		p.a = 0;
		p.b = 1;
		return;
	}
	fast_fib((n / 2), p);
	a = p.a;             /* F(n) */
	b = p.b;             /* F(n+1) */
	c = 2 * b - a;
	if (c < 0)
		c += MOD;
	c = (a * c) % MOD;      /* F(2n) */
	d = (a * a + b * b) % MOD;  /* F(2n + 1) */
	if (n % 2 == 0)
	{
		p.a = c;
		p.b = d;
	}
	else
	{
		p.a = d;
		p.b = c + d;
	}
}

int main()
{
	long long int n;        /* nth value to be found */
	FiboNums p;
	p.a = 0;
	p.b = 0;
	int tests;
	cin >> tests;

	for (int i = 0; i < tests; i++) {
		n = 0;
		cin >> n;
		fast_fib(n, p);
		cout << p.a << endl;
	}
	return 0;
}
