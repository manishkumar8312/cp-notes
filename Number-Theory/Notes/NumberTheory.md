# Number Theory

## 1. Modular Arithmetic

Modular arithmetic is fundamental for handling large numbers efficiently.

### Key Properties

* Prevents overflow
* Operations are closed under modulo
* Division requires modular inverse

### Formulas

```
(a + b) % m = ((a % m) + (b % m)) % m
(a * b) % m = ((a % m) * (b % m)) % m
(a - b) % m = ((a % m - b % m) + m) % m
```

### Negative Modulo Handling

```cpp
long long mod(long long a, long long m) {
    return (a % m + m) % m;
}
```

### Modular Inverse (m is prime)

Using Fermat’s Little Theorem:

```
a^(m-2) % m
```

```cpp
long long modInv(long long a, long long m) {
    return binpow(a, m - 2, m);
}
```

### Modular Division

```
(a / b) % m = a × modInv(b) % m
```

Time Complexity: `O(1)` per operation

---

## 2. Prime Numbers, Divisors, Factorization

### Naive Prime Check

Time Complexity: `O(√n)`

```cpp
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}
```

### Optimized Factorization using SPF (Smallest Prime Factor)

Preprocessing: `O(n log log n)`
Factorization per query: `O(log n)`

```cpp
const int N = 1e6;
int spf[N + 1];

void sieveSPF() {
    for (int i = 1; i <= N; i++) spf[i] = i;
    for (int i = 2; i * i <= N; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= N; j += i)
                if (spf[j] == j) spf[j] = i;
        }
    }
}
```

### Number of Divisors

If

```
n = p1^a × p2^b × ...
```

Then

```
Total divisors = (a + 1)(b + 1)...
```

---

## 3. Bitwise Operations

Bitwise operations allow constant-time optimizations.

### Common Operations

* AND (`&`)
* OR (`|`)
* XOR (`^`)
* Left Shift (`<<`)
* Right Shift (`>>`)

### Important Tricks

```cpp
// Check odd
bool isOdd(int n) {
    return n & 1;
}

// Check power of two
bool isPowerOfTwo(int n) {
    return n && !(n & (n - 1));
}

// Remove lowest set bit
n = n & (n - 1);

// Count set bits
__builtin_popcount(n);
```

Time Complexity: `O(1)`

---

## 4. Euclidean Algorithm (GCD)

### Standard GCD

```cpp
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}
```

Time Complexity: `O(log min(a, b))`

### Extended Euclidean Algorithm

Used for modular inverse when modulus is not prime.

```cpp
long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    long long x1, y1;
    long long g = extGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}
```

---

## 5. Sieve of Eratosthenes

Efficient prime generation for multiple queries.

### Standard Sieve

Time Complexity: `O(n log log n)`
Space Complexity: `O(n)`

```cpp
vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    return isPrime;
}
```

### Optimization Options

* Use `bitset` to reduce memory
* Sieve only odd numbers
* Maintain prime prefix count array

---

## 6. Binary Modular Exponentiation

Used for large power calculations under modulo.

### Formula

```
a^b % m
```

### Implementation

```cpp
long long binpow(long long a, long long b, long long mod) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
```

Time Complexity: `O(log b)`

### Extensions

* Modular inverse
* Matrix exponentiation
* Linear recurrences

---

## 7. Combinatorics

### Factorials Precomputation

```cpp
const int MOD = 1e9 + 7;
vector<long long> fact, invFact;

void init(int n) {
    fact.resize(n + 1);
    invFact.resize(n + 1);

    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invFact[n] = binpow(fact[n], MOD - 2, MOD);
    for (int i = n; i > 0; i--)
        invFact[i - 1] = invFact[i] * i % MOD;
}
```

### Efficient nCr

```cpp
long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}
```

Time Complexity:

* Precomputation: `O(n)`
* Each query: `O(1)`

---

## 8. Must-Know Number Theory Theorems

* Fermat’s Little Theorem
* Wilson’s Theorem
* Euler’s Totient Function
* Chinese Remainder Theorem

---
