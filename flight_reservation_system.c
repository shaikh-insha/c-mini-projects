#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FLIGHTS 100
#define MAX_BOOKINGS 100

typedef struct {
    char flight_number[10];
    char destination[50];
    int available_seats;
} Flight;

typedef struct {
    char flight_number[10];
    int seats_booked;
} Booking;

// Function prototypes
void viewAvailableFlights();
void bookAFlight();
void cancelReservation();
void viewCurrentBookings();
void loadFlights();
void saveFlights();
void loadBookings();
void saveBookings();
Flight flights[MAX_FLIGHTS];
Booking bookings[MAX_BOOKINGS];
int flight_count = 0;
int booking_count = 0;

int main() {
    loadFlights();
    loadBookings();

    flight_count = 3;
    strcpy(flights[0].flight_number, "FL001");
    strcpy(flights[0].destination, "New York");
    flights[0].available_seats = 100;

    strcpy(flights[1].flight_number, "FL002");
    strcpy(flights[1].destination, "London");
    flights[1].available_seats = 150;

    strcpy(flights[2].flight_number, "FL003");
    strcpy(flights[2].destination, "Tokyo");
    flights[2].available_seats = 200;

    int choice;
    do {
        printf("\n--- Flight Reservation System ---\n");
        printf("1. View Available Flights\n");
        printf("2. Book a Flight\n");
        printf("3. Cancel Reservation\n");
        printf("4. View Current Bookings\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewAvailableFlights();
                break;
            case 2:
                bookAFlight();
                break;
            case 3:
                cancelReservation();
                break;
            case 4:
                viewCurrentBookings();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    saveFlights();
    saveBookings();

    return 0;
}

void viewAvailableFlights() {
    printf("\nAvailable Flights:\n");
    printf("%-15s %-20s %-15s\n", "Flight Number", "Destination", "Available Seats");
    for (int i = 0; i < flight_count; i++) {
        printf("%-15s %-20s %-15d\n", flights[i].flight_number, flights[i].destination, flights[i].available_seats);
    }
}

void bookAFlight() {
    char flight_number[10];
    int seats;
    printf("\nEnter Flight Number to book: ");
    scanf("%s", flight_number);
    printf("Enter number of seats to book: ");
    scanf("%d", &seats);

    for (int i = 0; i < flight_count; i++) {
        if (strcmp(flights[i].flight_number, flight_number) == 0) {
            if (flights[i].available_seats >= seats) {
                flights[i].available_seats -= seats;
                strcpy(bookings[booking_count].flight_number, flight_number);
                bookings[booking_count].seats_booked = seats;
                booking_count++;
                printf("Booking successful!\n");
            } else {
                printf("Not enough seats available.\n");
            }
            return;
        }
    }
    printf("Flight not found.\n");
}

void cancelReservation() {
    char flight_number[10];
    printf("\nEnter Flight Number to cancel: ");
    scanf("%s", flight_number);

    for (int i = 0; i < booking_count; i++) {
        if (strcmp(bookings[i].flight_number, flight_number) == 0) {
            for (int j = 0; j < flight_count; j++) {
                if (strcmp(flights[j].flight_number, flight_number) == 0) {
                    flights[j].available_seats += bookings[i].seats_booked;
                    printf("Reservation canceled successfully!\n");
                }
            }
            // Shift remaining bookings
            for (int k = i; k < booking_count - 1; k++) {
                bookings[k] = bookings[k + 1];
            }
            booking_count--;
            return;
        }
    }
    printf("Booking not found.\n");
}

void viewCurrentBookings() {
    printf("\nCurrent Bookings:\n");
    printf("%-15s %-15s\n", "Flight Number", "Seats Booked");
    for (int i = 0; i < booking_count; i++) {
        printf("%-15s %-15d\n", bookings[i].flight_number, bookings[i].seats_booked);
    }
}

void loadFlights() {
    FILE *file = fopen("flights.dat", "rb");
    if (file == NULL) {
        printf("No flight data found. Starting with an empty flight list.\n");
        return;
    }
    fread(&flight_count, sizeof(int), 1, file);
    fread(flights, sizeof(Flight), flight_count, file);
    fclose(file);
}

void saveFlights() {
    FILE *file = fopen("flights.dat", "wb");
    fwrite(&flight_count, sizeof(int), 1, file);
    fwrite(flights, sizeof(Flight), flight_count, file);
    fclose(file);
}

void loadBookings() {
    FILE *file = fopen("bookings.dat", "rb");
    if (file == NULL) {
        printf("No booking data found. Starting with an empty booking list.\n");
        return;
    }
    fread(&booking_count, sizeof(int), 1, file);
    fread(bookings, sizeof(Booking), booking_count, file);
    fclose(file);
}

void saveBookings() {
    FILE *file = fopen("bookings.dat", "wb");
    fwrite(&booking_count, sizeof(int), 1, file);
    fwrite(bookings, sizeof(Booking), booking_count, file);
    fclose(file);
}
