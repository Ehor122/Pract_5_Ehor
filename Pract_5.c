#include <stdio.h>

#define MOD 12345

// A function for calculating the number of sequences of length n
int count_sequences(int n) {
    // Arrays for storing the number of sequences
    int dp0[n + 1]; // sequences ending in 0
    int dp1[n + 1]; // sequences ending in 1
    int dp2[n + 1]; // sequences ending in 11

    // Initialization for basic cases
    dp0[1] = 1; // only one sequence “0”
    dp1[1] = 1; // only one sequence “1”
    dp2[1] = 0; // it is impossible to have a sequence ending in “11” with length 1

    for (int i = 2; i <= n; i++) {
        dp0[i] = (dp0[i-1] + dp1[i-1] + dp2[i-1]) % MOD;
        dp1[i] = dp0[i-1] % MOD;
        dp2[i] = dp1[i-1] % MOD;
    }

    return (dp0[n] + dp1[n] + dp2[n]) % MOD;
}

int main() {
    int n;
    printf("Enter the length of the sequences n: ");
    scanf("%d", &n);

    if (n <= 1 || n >= 10000) {
        printf("Invalid value of n. n must be in the range from 2 to 9999.");
        return 1;
    }

    int result = count_sequences(n);
    printf("Number of sequences searched: %d\n", result);

    return 0;
}
