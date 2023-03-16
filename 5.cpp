#include <iostream>
#include <iomanip>
#include <bitset>
#include <vector>
#include <cmath>

using namespace std;

const uint64_t MAX_NUM = 0xFFFFFFFFFFFFFFFFULL;
const uint64_t BIT_MASK = 0x3ULL; // 0b11

bool isPrime(uint64_t n)
{
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    if ((n & 1) == 0)
        return false;

    uint64_t sqrt_n = sqrt(n);
    for (uint64_t i = 3; i <= sqrt_n; i += 2) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main()
{
    vector<uint64_t> primes;

    for (uint64_t i = 3; i <= MAX_NUM; i += 2) {
        if (i & BIT_MASK == BIT_MASK && isPrime(i)) {
            primes.push_back(i);
        }
    }

    cout << "Found " << primes.size() << " primes with only two set bits." << endl;

    if (!primes.empty()) {
        sort(primes.begin(), primes.end());
        cout << "Min prime: " << primes.front() << " (hex: " << hex << primes.front() << ")" << endl;
        cout << "Max prime: " << primes.back() << " (hex: " << hex << primes.back() << ")" << endl;
    }

    return 0;
}
