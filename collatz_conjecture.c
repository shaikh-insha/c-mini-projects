#include <stdio.h>

// Function to perform Collatz transformation
int collatz_steps(int n) {
    int steps = 0;

    while (n != 1) {
        if (n % 2 == 0)
            n = n / 2;
        else
            n = 3 * n + 1;
        steps++;
    }

    return steps;
}

int main() {
    int n;

    printf("📥 Enter a positive integer: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("❌ Invalid input! Please enter a positive integer.\n");
        return 1;
    }

    int steps = collatz_steps(n);

    printf("✅ It took %d steps to reach 1 using the Collatz Conjecture.\n", steps);

    return 0;
}
