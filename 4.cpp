#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;

uint32_t genPrime(unsigned int n, bool isPrime(uint32_t))
{
    uint32_t min = 1UL << (n-2);
    uint32_t max = (1UL << (n-1)) - 1;
    uint32_t r;
    std::mt19937 gen(clock());
    std::uniform_int_distribution<uint32_t> rnd(min,max);
    do {
        r = rnd(gen);
    } while (!isPrime(r));
    return r;
}

bool TrialDivision(uint32_t n)
{
    if (n<2)
        return false;
    if (n<4)
        return true;
    if ((n & 1) == 0)
        return false;
    for (uint32_t i = 3; i <= (uint32_t) sqrt(n); i+=2)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    vector<uint32_t> primes(1000);
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000; i++) {
        primes[i] = genPrime(32, TrialDivision);
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken to generate 1000 primes: " << duration.count() << " microseconds" << endl;

    sort(primes.begin(), primes.end());

    cout << "Minimum prime: " << primes.front() << endl;
    cout << "Maximum prime: " << primes.back() << endl;

    return 0;
}
