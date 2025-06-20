#include <stdio.h>

void convertCurrency(float amount, int choice) {
    float convertedAmount;

    switch (choice) {
        case 1: // USD
            convertedAmount = amount / 83.0;
            printf("🇮🇳 INR %.2f = 💵 USD %.2f\n", amount, convertedAmount);
            break;
        case 2: // EUR
            convertedAmount = amount / 91.0;
            printf("🇮🇳 INR %.2f = 💶 EUR %.2f\n", amount, convertedAmount);
            break;
        case 3: // GBP
            convertedAmount = amount / 106.0;
            printf("🇮🇳 INR %.2f = 💷 GBP %.2f\n", amount, convertedAmount);
            break;
        case 4: // JPY
            convertedAmount = amount * 1.5;
            printf("🇮🇳 INR %.2f = 💴 JPY %.2f\n", amount, convertedAmount);
            break;
        default:
            printf("❌ Invalid choice! Please select between 1 and 4.\n");
    }
}

int main() {
    float inrAmount;
    int currencyChoice;

    printf("💱 INR Currency Converter\n");
    printf("Enter amount in INR: ₹");
    if (scanf("%f", &inrAmount) != 1 || inrAmount <= 0) {
        printf("❌ Please enter a valid positive amount.\n");
        return 1;
    }

    printf("\nConvert to:\n");
    printf("1. USD (United States Dollar)\n");
    printf("2. EUR (Euro)\n");
    printf("3. GBP (British Pound)\n");
    printf("4. JPY (Japanese Yen)\n");
    printf("Enter your choice (1-4): ");
    if (scanf("%d", &currencyChoice) != 1) {
        printf("❌ Invalid input for currency choice.\n");
        return 1;
    }

    convertCurrency(inrAmount, currencyChoice);

    return 0;
}
