// Attendence system 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 20

char stuName[MAX_STUDENTS][30];
int presentAttendance[MAX_STUDENTS];
int absentAttendance[MAX_STUDENTS];
int indexNumber = 0;

float calculatePercentage(int present, int total) {
    if (total > 0) {

        return ((float)present / total) * 100;
    } else {

        return 0;
    }
}


void checkAttendance() {
    printf("\n         Total Present | Total Absent\n");
    for (int i = 0; i < indexNumber; i++) {
        printf("%s", stuName[i]);
        printf("              %d             %d \n", presentAttendance[i], absentAttendance[i]);
    }
}


void addStudent() {
    int num, add;
    if (indexNumber == 0) {
        printf("Enter the many students you want to add: ");
        scanf("%d", &num);
        for (int i = 0; i < num; i++) {
            printf("\nEnter %d student name to add in the attendance register: ", i + 1);
            scanf("%s", stuName[i]);
            indexNumber++;
        }
    } 
    else {
        printf("Enter how many students you want to add: ");
        scanf("%d", &num);
        add = indexNumber + num;
        for (int i = indexNumber; i < add; i++) {
            printf("\nEnter %d student name to add in the attendance register: ", i + 1);
            scanf("%s", stuName[i]);
            indexNumber++;
        }
    }
}


//function to remove student from student list
void removeStudent() {
    char name[30];
    printf("Enter student name you want to remove: ");
    scanf("%s", name);
    for (int i = 0; i < indexNumber; i++) {
        if (strcmp(name, stuName[i]) == 0) {
            for (int j = i; j < indexNumber; j++) {
                strcpy(stuName[j], stuName[j + 1]);
                presentAttendance[i] = presentAttendance[i + 1];
                absentAttendance[i] = absentAttendance[i + 1];
            }
            indexNumber--;
            printf("\n%s student is removed\n", name);
            break;
        } 
        else if (i == indexNumber - 1) {
            printf("This name does not exist\n");
        }
    }
}

//function to add attendence of a student
void takeAttendance() {
    char ch;
    printf("\nEnter Y for present and N for absent\n");

    for (int i = 0; i < indexNumber; i++) {

        while (1) {
            printf("%d. %s is present: ", i + 1, stuName[i]);
            scanf(" %c", &ch);

            if (ch == 'Y' || ch == 'y') {
                presentAttendance[i] += 1;
                break;
            } 
            else if (ch == 'N' || ch == 'n') {
                absentAttendance[i] += 1;
                break;
            }
            else {
                printf("Invalid character. Try again\n");

            }
        }
    }
}

//function to check eligibility of student for exam
void checkEligibility() {
    printf("\nEligibility for Upcoming Exam:\n");
    printf("----------------------------\n");
    for (int i = 0; i < indexNumber; i++) {
        float attendancePercentage = calculatePercentage(presentAttendance[i], presentAttendance[i] + absentAttendance[i]);

        printf("%s: %.2f%% ", stuName[i], attendancePercentage);

        if (attendancePercentage >= 75.0) {
            printf("(Eligible for exam)\n");
        } 
        else {
            printf("(Not eligible for exam)\n");
        }
    }
}

int main() {
    int choose;
    do {
        printf("\n*****Main Menu****\n");
        printf("Enter 1 for add student\n");
        printf("Enter 2 for take attendance\n");
        printf("Enter 3 for check attendance\n");
        printf("Enter 4 for remove student\n");
        printf("Enter 5 for check eligibility for exam\n");
        printf("Enter 6 for exit\n");
        printf("Please choose any menu: ");
        scanf("%d", &choose);
        switch (choose) {
            case 1:
                addStudent();
                break;
            case 2:
                takeAttendance();
                break;
            case 3:
                checkAttendance();
                break;
            case 4:
                removeStudent();
                break;
            case 5:
                checkEligibility();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please choose a valid option.\n");
        }
    } while (choose != 6);

    return 0;
}
