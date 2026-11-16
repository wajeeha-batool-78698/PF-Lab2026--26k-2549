#include <stdio.h>
#include <string.h>

struct Movie {
    char title[50];
    char genre[30];
    char director[50];
    int releaseYear;
    float rating;
};

void addMovie(struct Movie movies[], int *count) {
    if (*count >= 50) {
        printf("Movie list is full!\n");
        return;
    }

    printf("\nEnter Movie Title: ");
    scanf(" %[^\n]", movies[*count].title);

    printf("Enter Genre: ");
    scanf(" %[^\n]", movies[*count].genre);

    printf("Enter Director: ");
    scanf(" %[^\n]", movies[*count].director);

    printf("Enter Release Year: ");
    scanf("%d", &movies[*count].releaseYear);

    printf("Enter Rating (out of 10): ");
    scanf("%f", &movies[*count].rating);

    (*count)++;
    printf("Movie added successfully!\n");
}

void displayAllMovies(struct Movie movies[], int count) {
    int i;
    if (count == 0) {
        printf("\nNo movies added yet.\n");
        return;
    }

    printf("\n--- All Movies ---\n");
    for (i = 0; i < count; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Genre: %s\n", movies[i].genre);
        printf("Director: %s\n", movies[i].director);
        printf("Release Year: %d\n", movies[i].releaseYear);
        printf("Rating: %.1f/10\n", movies[i].rating);
        printf("------------------\n");
    }
}

void searchByGenre(struct Movie movies[], int count) {
    char searchGenre[30];
    int found = 0;
    int i;

    if (count == 0) {
        printf("\nNo movies available to search.\n");
        return;
    }

    printf("\nEnter genre to search: ");
    scanf(" %[^\n]", searchGenre);

    printf("\n--- Search Results ---\n");
    for (i = 0; i < count; i++) {
        if (strcmp(movies[i].genre, searchGenre) == 0) {
            printf("Title: %s | Director: %s | Year: %d | Rating: %.1f\n",
                   movies[i].title, movies[i].director, movies[i].releaseYear, movies[i].rating);
            found = 1;
        }
    }

    if (found == 0) {
        printf("No movies found in this genre.\n");
    }
}

int main() {
    struct Movie movies[50];
    int movieCount = 0;
    int choice;

    while (1) {
        printf("1. Add New Movie\n");
        printf("2. Search Movies by Genre\n");
        printf("3. Display All Movies\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            addMovie(movies, &movieCount);
        } else if (choice == 2) {
            searchByGenre(movies, movieCount);
        } else if (choice == 3) {
            displayAllMovies(movies, movieCount);
        } else if (choice == 4) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
