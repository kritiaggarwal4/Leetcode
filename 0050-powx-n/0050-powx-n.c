double pow1(double x, long long n)
{
    if(n == 0)
        return 1.0;

    if(n % 2 == 1)
        return x * pow1(x * x, (n - 1) / 2);

    return pow1(x * x, n / 2);
}

double myPow(double x, int n)
{
    long long N = n;

    if(N < 0)
        return 1.0 / pow1(x, -N);

    return pow1(x, N);
}