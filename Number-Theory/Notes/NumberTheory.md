## Number Theory

<details>
<summary><strong>Modular Arithmetic</strong></summary>

Modular arithmetic deals with operations under a fixed modulus `m`.

**Key Points**

* Prevents integer overflow
* Frequently used in competitive programming and cryptography

**Formulas**

* `(a + b) % m = ((a % m) + (b % m)) % m`
* `(a * b) % m = ((a % m) * (b % m)) % m`

**Time Complexity**

* All basic operations: `O(1)`

**C++ Implementation**

```cpp
long long add(long long a, long long b, long long mod) {
    return (a % mod + b % mod) % mod;
}
```

</details>

---

<details>
<summary><strong>Primes, Divisors and Multiples</strong></summary>

This topic focuses on properties of prime numbers and factorization.

**Key Points**

* Prime number: divisible only by 1 and itself
* Divisors can be found in `O(√n)`
* Useful in factor-based optimizations

**Formula**
If `n = p₁^a × p₂^b × ...`
Number of divisors = `(a + 1)(b + 1)...`

**Time Complexity**

* Prime check: `O(√n)`

**C++ Implementation**

```cpp
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}
```

</details>

---

<details>
<summary><strong>Bitwise Operations</strong></summary>

Bitwise operations work directly on binary representations.

**Common Operations**

* AND (`&`)
* OR (`|`)
* XOR (`^`)
* Left Shift (`<<`)
* Right Shift (`>>`)

**Applications**

* Fast arithmetic
* Subset generation
* Optimization techniques

**Time Complexity**

* All bitwise operations: `O(1)`

**C++ Example**

```cpp
bool isOdd(int n) {
    return n & 1;
}
```

</details>

---

<details>
<summary><strong>Euclidean Algorithm (GCD)</strong></summary>

Efficient algorithm to compute the Greatest Common Divisor.

**Formula**

* `gcd(a, b) = gcd(b, a % b)`

**Applications**

* LCM calculation
* Fraction simplification
* Coprime checking

**Time Complexity**

* `O(log min(a, b))`

**C++ Implementation**

```cpp
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}
```

</details>

---

<details>
<summary><strong>Sieve of Eratosthenes</strong></summary>

Efficient algorithm to precompute prime numbers up to `N`.

**Key Points**

* Marks multiples of primes
* Used for multiple prime queries

**Time Complexity**

* `O(n log log n)`

**C++ Implementation**

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

</details>

---

<details>
<summary><strong>Binary Modular Exponentiation</strong></summary>

Used to compute large powers efficiently under modulo.

**Formula**

* `(a^b) % m` using repeated squaring

**Time Complexity**

* `O(log b)`

**C++ Implementation**

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

</details>

---

<details>
<summary><strong>Combinatorics</strong></summary>

Combinatorics focuses on counting and arrangements.

**Key Concepts**

* Factorial
* Permutations (`nPr`)
* Combinations (`nCr`)
* Pascal’s Identity

**Formula**

* `nCr = n! / (r! × (n−r)!)`

**Time Complexity**

* Precomputation: `O(n)`
* Each query: `O(1)`

**C++ Implementation**

```cpp
const int MOD = 1e9 + 7;
vector<long long> fact(1000001);

void computeFactorial() {
    fact[0] = 1;
    for (int i = 1; i <= 1000000; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
}
```

</details>

---

