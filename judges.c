#include <stdio.h>
#include <stdlib.h>

#define MAX_JUDGES 100  // Define a reasonable max limit for judges

// Struct to store judge information
typedef struct {
    char name[50];
    char gender[10];
    char affiliation[50];
    char title[50];
    char specialty[50];
    char email[50];
    char phone[20];
} Judge;

// Function prototypes
void enterJudgeData(Judge judges[], int totalJudges);
void displayJudges(const char *project, Judge judges[], int totalJudges);

int main() {
    char project[50];
    int totalJudges;
    
    printf("####################################\n");
    printf("#      Judge List Data Entry      #\n");
    printf("####################################\n");

    printf("Participating Project: ");
    fgets(project, sizeof(project), stdin);
    
    do {
        printf("Total Number of Judges: ");
        scanf("%d", &totalJudges);
        getchar(); // Consume newline character
        if (totalJudges <= 0 || totalJudges > MAX_JUDGES) {
            printf("Invalid number of judges. Please enter a valid number.\n");
        }
    } while (totalJudges <= 0 || totalJudges > MAX_JUDGES);
    
    Judge judges[totalJudges];
    
    // Enter judge information
    enterJudgeData(judges, totalJudges);

    // Ask user whether to display the information
    char check;
    printf("\"Should we check the judge information? (Y/N): \" ");
    scanf(" %c", &check);

    if (check == 'Y' || check == 'y') {
        displayJudges(project, judges, totalJudges);
    } else {
        printf("Program terminated.\n");
    }

    return 0;
}

// Function to enter judge data
void enterJudgeData(Judge judges[], int totalJudges) {
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("Starting to input information for %d judges.\n", totalJudges);
    printf("++++++++++++++++++++++++++++++++++++\n");

    for (int i = 0; i < totalJudges; i++) {
        printf("[Judge %d]\n", i + 1);
        printf("Name: "); fgets(judges[i].name, sizeof(judges[i].name), stdin);
        printf("Gender: "); fgets(judges[i].gender, sizeof(judges[i].gender), stdin);
        printf("Affiliation: "); fgets(judges[i].affiliation, sizeof(judges[i].affiliation), stdin);
        printf("Title: "); fgets(judges[i].title, sizeof(judges[i].title), stdin);
        printf("Specialty: "); fgets(judges[i].specialty, sizeof(judges[i].specialty), stdin);
        printf("Email: "); fgets(judges[i].email, sizeof(judges[i].email), stdin);
        printf("Phone: "); fgets(judges[i].phone, sizeof(judges[i].phone), stdin);
    }
    
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("Judge information entry is complete.\n");
    printf("++++++++++++++++++++++++++++++++++++\n");
}

// Function to display judge data
void displayJudges(const char *project, Judge judges[], int totalJudges) {
    printf("####################################\n");
    printf("#        Display Judge Data        #\n");
    printf("####################################\n");

    printf("Project: %s\n", project);

    for (int i = 0; i < totalJudges; i++) {
        printf("[Judge %d]\n", i + 1);
        printf("Name: %s", judges[i].name);
        printf("Gender: %s", judges[i].gender);
        printf("Affiliation: %s", judges[i].affiliation);
        printf("Title: %s", judges[i].title);
        printf("Expertise: %s", judges[i].specialty);
        printf("Email: %s", judges[i].email);
        printf("Phone: %s", judges[i].phone);
        printf("-----------------------------------\n");
    }
}