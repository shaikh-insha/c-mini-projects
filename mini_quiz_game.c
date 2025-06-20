#include <stdio.h>

int main() {
    int score = 0, answer;

    printf("🧠 Welcome to the Mini Quiz Game!\n");
    printf("---------------------------------\n");

    // Question 1
    printf("\n1️⃣ Question: What is the capital of France?\n");
    printf("1. Berlin\n2. Madrid\n3. Paris\n4. Rome\n");
    printf("Your answer (1-4): ");
    scanf("%d", &answer);
    if (answer == 3) {
        printf("✅ Correct!\n");
        score++;
    } else {
        printf("❌ Wrong! Correct answer: Paris\n");
    }

    // Question 2
    printf("\n2️⃣ Question: Which planet is known as the Red Planet?\n");
    printf("1. Earth\n2. Mars\n3. Jupiter\n4. Saturn\n");
    printf("Your answer (1-4): ");
    scanf("%d", &answer);
    if (answer == 2) {
        printf("✅ Correct!\n");
        score++;
    } else {
        printf("❌ Wrong! Correct answer: Mars\n");
    }

    // Question 3
    printf("\n3️⃣ Question: Who wrote 'To Kill a Mockingbird'?\n");
    printf("1. Harper Lee\n2. Jane Austen\n3. Mark Twain\n4. J.K. Rowling\n");
    printf("Your answer (1-4): ");
    scanf("%d", &answer);
    if (answer == 1) {
        printf("✅ Correct!\n");
        score++;
    } else {
        printf("❌ Wrong! Correct answer: Harper Lee\n");
    }

    printf("\n📊 Final Score: %d out of 3\n", score);
    printf("🎉 Thanks for playing!\n");

    return 0;
}
