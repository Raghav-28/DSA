#include<iostream>
using namespace std;

const int MAX = 1e5+5;
long long fact[MAX];

// Efficient modular exponentiation
long long modPower(long long a, long long b, long long m) {
    long long result = 1;
    a %= m;
    while (b > 0) {
        if (b & 1)
            result = (result * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return result;
}

// Precompute factorials modulo m
void computeFactorials(int n, int m) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % m;
    }
}

long long modularnCr(int n, int r, int m) {
    if (r < 0 || r > n) return 0;
    computeFactorials(n, m);

    long long numerator = fact[n];
    long long denominator = (fact[r] * fact[n - r]) % m;
    long long inverse = modPower(denominator, m - 2, m); // Fermat's Little Theorem

    return (numerator * inverse) % m;
}

int main() {
    int n =5, r=2, m=7;
    cout << "The value of nCr mod m is: ";
    cout << modularnCr(n, r, m) << endl;

    return 0;
}
