void interval(int n, int &a, int &b)
{
 	long long int factorial, factorial_1, factorial_0;
    factorial = 1;
    factorial_1 = 1;
    factorial_0 = 1;
    for(int i = 2; i <= n; i++)
    {
     	factorial *= i;
        factorial_1 *= i;
        factorial_0 *= i;
    }
    factorial_1 *= n + 1;
    factorial_0 /= n;
    a = factorial_0 + 1;
    b = factorial_1 - 1;
}