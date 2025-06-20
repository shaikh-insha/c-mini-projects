#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILENAME "diary.txt"

void add_entry();
void view_entries();
void delete_entries();
void edit_entry();

void add_entry() {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char entry[1000];
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);

    printf("Enter your diary entry: ");
    getchar();  // Consume newline left in buffer from previous input
    fgets(entry, 1000, stdin);

    fprintf(file, "Date: %02d-%02d-%d Time: %02d:%02d\n", local->tm_mday, local->tm_mon + 1, local->tm_year + 1900, local->tm_hour, local->tm_min);
    fprintf(file, "%s\n", entry);
    fprintf(file, "----------------------------------\n");

    fclose(file);
    printf("Diary entry added successfully!\n");
}

void view_entries() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No entries found!\n");
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}

void delete_entries() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fclose(file);
    printf("All diary entries deleted successfully!\n");
}

void edit_entry() {
    FILE *file = fopen(FILENAME, "r+");
    if (file == NULL) {
        printf("No entries found to edit!\n");
        return;
    }

    char buffer[10000];
    char *found = NULL;
    int offset = 0;

    printf("Enter the date (in format DD-MM-YYYY) of the entry you want to edit: ");
    char search_date[20];
    getchar(); // Consume newline left in buffer from previous input
    fgets(search_date, 20, stdin);
    search_date[strcspn(search_date, "\n")] = '\0'; // Remove newline

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if ((found = strstr(buffer, search_date)) != NULL) {
            offset = ftell(file) - strlen(buffer);
            break;
        }
    }

    if (found) {
        fseek(file, offset, SEEK_SET);
        printf("Found entry on %s. Please enter your new text:\n", search_date);

        char new_entry[1000];
        fgets(new_entry, 1000, stdin);

        fprintf(file, "Date: %s %s", search_date, buffer + strlen(search_date));
        fprintf(file, "%s\n", new_entry);
        fprintf(file, "----------------------------------\n");

        printf("Entry updated successfully!\n");
    } else {
        printf("No entry found on the given date.\n");
    }

    fclose(file);
}

void menu() {
    int choice;

    do {
        printf("\n--- Personal Diary System ---\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Edit Entry\n");
        printf("4. Delete All Entries\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                edit_entry();
                break;
            case 4:
                delete_entries();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}
