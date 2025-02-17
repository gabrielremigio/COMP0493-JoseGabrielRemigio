unsigned long long int binaryExponentiation(unsigned long long int x, unsigned long long int n)
{
    if(n == 0)
        return 1;

    unsigned long long int half = binaryExponentiation(x, n / 2);

    if(n % 2 == 0)
        return half * half;
    else
        return x * half * half;
}