#include <stdio.h>

// Define a structure to store questions and answers
struct Question {
    char text[256];           // The question
    char choices[4][256];      // The 4 answer choices
    char rightAnswer;          // The correct answer (A, B, C, or D)
};

// Function to ask the quiz questions and count the score
int askQuestions(struct Question quiz[], int numberOfQuestions) {
    char answer;              // Variable to store user's answer
    int points = 0;           // To keep track of the correct answers

    for (int i = 0; i < numberOfQuestions; i++) {
        printf("\nQuestion %d: %s\n", i + 1, quiz[i].text);  // Show the question
        for (int j = 0; j < 4; j++) {
            printf("%c. %s\n", 'A' + j, quiz[i].choices[j]); // Show the choices
        }

        printf("Enter your answer (A, B, C, D): ");
        scanf(" %c", &answer);   // Get the user's answer

        // Check if the answer is correct
        if (answer == quiz[i].rightAnswer) {
            printf("Good job! That's correct!\n");
            points++;           // Increase points if correct
        } else {
            printf("Oops! The correct answer was %c.\n", quiz[i].rightAnswer);
        }
    }

    return points;             // Return the total points
}

int main() {
    // Define the questions and choices
    struct Question quiz[] = {
        {"What is the color of the sky?", 
            {"Blue", "Green", "Red", "Yellow"}, 
            'A'},

        {"Which animal says 'Woof'?", 
            {"Cat", "Dog", "Cow", "Sheep"}, 
            'B'},

        {"Which number comes after 2?", 
            {"1", "4", "3", "5"}, 
            'C'},

        {"What do we drink when thirsty?", 
            {"Milk", "Water", "Juice", "Tea"}, 
            'B'}
    };

    int totalQuestions = sizeof(quiz) / sizeof(quiz[0]);  // Total number of questions
    printf("Welcome to the Simple Quiz Game!\n");

    // Start the quiz and get the score
    int finalScore = askQuestions(quiz, totalQuestions);

    // Show the final score
    printf("\nQuiz Over! You got %d correct out of %d.\n", finalScore, totalQuestions);

    return 0;
}
