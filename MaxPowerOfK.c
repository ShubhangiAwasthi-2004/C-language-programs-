#include <stdio.h>
#include <math.h>

#define MAX_FACTORS 20

// Function to factorize k and store primes and their exponents
int factorize(int k, int primes[], int exps[]) {
    int count = 0;
    for (int i = 2; i * i <= k; i++) {
        if (k % i == 0) {
            primes[count] = i;
            exps[count] = 0;
            while (k % i == 0) {
                k /= i;
                exps[count]++;
            }
            count++;
        }
    }
    if (k > 1) {
        primes[count] = k;
        exps[count] = 1;
        count++;
    }
    return count;
}

// Legendre's formula to count power of p in n!
int countPowerInFactorial(int n, int p) {
    int count = 0;
    while (n > 0) {
        n /= p;
        count += n;
    }
    return count;
}

// Main function to compute max x such that k^x divides n!
int maxKPower(int n, int k) {
    int primes[MAX_FACTORS], exps[MAX_FACTORS];
    int numFactors = factorize(k, primes, exps);

    int result = 1e9;
    for (int i = 0; i < numFactors; i++) {
        int totalPower = countPowerInFactorial(n, primes[i]);
        int possibleX = totalPower / exps[i];
        if (possibleX < result)
            result = possibleX;
    }

    return result;
}

int main() {
    int n, k;
    printf("Enter n and k: ");
    scanf("%d %d", &n, &k);

    int ans = maxKPower(n, k);
    printf("Maximum x such that k^x divides n! is: %d\n", ans);

    return 0;
}
