#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

bool isPrime(uint64_t n)
{
    if (n < 2)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (uint64_t i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

int main()
{
    vector<uint64_t> primes;
    for (uint64_t n = 0; n <= 0xFFFFFFFFFFFFFFFF; n++)
    {
        if ((n & (n - 1)) == 0 && isPrime(n))
            primes.push_back(n);
    }
    sort(primes.begin(), primes.end());
    cout << "Min prime: " << dec << primes.front() << " (hex: 0x" << hex << primes.front() << ")" << endl;
    cout << "Max prime: " << dec << primes.back() << " (hex: 0x" << hex << primes.back() << ")" << endl;
    return 0;
}
