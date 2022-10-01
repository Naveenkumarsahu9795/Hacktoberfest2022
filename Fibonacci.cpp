/* It is a c++ program for printing Fibonacci series  */
#include <bits/stdc++.h>
using namespace std;

// This will  limit on the largest Fibonacci number to be used
#define N 30

/* Array for storing fibonacci numbers. fib[m] is going
to store (m+2) Fibonacci number*/
int fib[N];

// Stores values in fib and returns index of the largest
// fibonacci number smaller than n.
int largestFiboLessOrEqual(int n)
{
	fib[0] = 1; // Fib[0] will stores the 2nd Fibonacci No.
	fib[1] = 2; // Fib[1] will stores the 3rd Fibonacci No.

	// Keep Generating remaining numbers while previously
	// generated number is smaller
	int m;
	for (m=2; fib[m-1]<=n; m++)
		fib[m] = fib[m-1] + fib[m-2];

	// Return index of the largest fibonacci number
	// smaller than or equal to n. Note that the above
	// loop stopped when fib[m-1] became larger.
	return (m-2);
}

/* Returns pointer to the string which corresponds to
code for n */
char* fibonacciEncoding(int n)
{
	int index = largestFiboLessOrEqual(n);

	//allocate memory for variable code
	char *code = (char*)malloc(sizeof(char)*(index+3));

	// index of the largest Fibonacci f <= n
	int m = index;

	while (n)
	{
		// Mark usage of Fibonacci f
		code[m] = '1';

		// Subtract f from n
		n = n - fib[m];

		// Move to Fibonacci just smaller than f
		m = m - 1;

		// Mark all Fibonacci > n as not used 
		// progress backwards
		while (m>=0 && fib[m]>n)
		{
			code[m] = '0';
			m = m - 1;
		}
	}

	//additional '1' bit
	code[index+1] = '1';
	code[index+2] = '\0';

	//return pointer to code
	return code;
}

/* driver function */
int main()
{
	int n = 143;
	cout <<"Fibonacci code word for " <<n <<" is " << fibonacciEncoding(n);
	
	return 0;
}
// Naveen Kumar Sahu
