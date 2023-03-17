#include <iostream>
#include <cmath>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;


bool hasTwoSolo(unsigned long long n) {
    int count = 0;

    while (n)
    {
        if (n % 2 == 1) count++;
        n /= 2;
    }
    if (n % 2 == 1) count++;
    if (count == 2) return true;
    return false;
}

bool isPrime(unsigned long long n)
{
 if (n<2)
 return false;
 if (n<4)
 return true;
 if ((n & 1) == 0)
 return false;
 for (unsigned long long i = 3; i <= (unsigned long long) sqrt(n); i+=2)
 if (n % i == 0)
 return false;
 return true;
}

int main()
{
    vector<uint64_t> v;
    for (unsigned long long i = 1; i <= numeric_limits<unsigned long long>::max(); i+=2) {
        if (hasTwoSolo(i) && isPrime(i)) {
            cout << dec << i << " " << hex << i << endl;
        }
    }
 return 0;
}
