#include <stdio.h>
#include <string.h>

struct Flight {
    char flightNumber[20];
    char departureCity[50];
    char destinationCity[50];
    char date[20];
    int availableSeats;
};

// Display all available flights
void displayFlights(struct Flight flights[], int count) {
    int i;
    printf("\n--- Available Flights ---\n");
    for (i = 0; i < count; i++) {
        printf("Flight: %s | %s -> %s | Date: %s | Seats Left: %d\n",
               flights[i].flightNumber, flights[i].departureCity,
               flights[i].destinationCity, flights[i].date, flights[i].availableSeats);
    }
    printf("-------------------------\n");
}

// Passenger enters city and date to find & book a flight
void bookSeat(struct Flight flights[], int count) {
    char dep[50], dest[50], travelDate[20];
    int found = 0;
    int i;

    printf("\nEnter Departure City: ");
    scanf(" %[^\n]", dep);

    printf("Enter Destination City: ");
    scanf(" %[^\n]", dest);

    printf("Enter Date (e.g. 20-11-2026): ");
    scanf(" %[^\n]", travelDate);

    for (i = 0; i < count; i++) {
        if (strcmp(flights[i].departureCity, dep) == 0 &&
            strcmp(flights[i].destinationCity, dest) == 0 &&
            strcmp(flights[i].date, travelDate) == 0) {
            
            found = 1;
            printf("\nFlight Found: %s\n", flights[i].flightNumber);

            if (flights[i].availableSeats > 0) {
                flights[i].availableSeats--;
                printf("Seat booked! Remaining seats on %s: %d\n",
                       flights[i].flightNumber, flights[i].availableSeats);
            } else {
                printf("Sorry, no seats available on this flight.\n");
            }
            break;
        }
    }

    if (found == 0) {
        printf("\nNo flight found matching your route and date.\n");
    }
}

int main() {
    // Airline's pre-set schedule (Passenger cannot change total seats)
    struct Flight flights[3] = {
        {"PK-301", "Quetta", "Islamabad", "20-11-2026", 5},
        {"PK-405", "Karachi", "Lahore", "22-11-2026", 2},
        {"PK-102", "Quetta", "Karachi", "25-11-2026", 4}
    };
    int flightCount = 3;
    int choice;

    while (1) {
        printf("1. View All Flights\n");
        printf("2. Book a Seat (Enter City & Date)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            displayFlights(flights, flightCount);
        } else if (choice == 2) {
            bookSeat(flights, flightCount);
        } else if (choice == 3) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
