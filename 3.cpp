#include <iostream>
#include <cmath>
#include <random>
#include <chrono>

using namespace std;

uint64_t genPrime(unsigned int n, bool isPrime(uint64_t))
{
    uint64_t min = 1ULL << (n-3);
    uint64_t max = (min << 2) + 2;
    uint64_t r;
    std::mt19937_64 gen(clock());
    std::uniform_int_distribution<uint64_t> rnd(min,max);
    do {
        r = rnd(gen);
    } while (!isPrime(r));
    return r;
}

bool TrialDivision(uint64_t n)
{
    if (n<2)
        return false;
    if (n<4)
        return true;
    if ((n & 1) == 0)
        return false;
    for (uint64_t i = 3; i <= (uint64_t) sqrt(n); i+=2)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    // генерация и вывод трех простых чисел с замером времени
    for (int i = 0; i < 3; i++) {
        auto start_time = chrono::steady_clock::now();
        uint64_t p = genPrime(64, TrialDivision);
        auto end_time = chrono::steady_clock::now();
        auto diff_time = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
        cout << "Prime number " << i+1 << ": " << p << ", generated in " << diff_time.count() << " ms" << endl;
    }
    return 0;
}
