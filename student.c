#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

void addStudent() {
    struct Student s;
    FILE *f = fopen("students.txt", "a");
    
    if (f == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Roll No: ");
    scanf("%d", &s.roll);
    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fprintf(f, "%d,%s,%.2f\n", s.roll, s.name, s.marks);
    fclose(f);
    printf("✅ Record Added Successfully!\n");
}

void viewStudents() {
    struct Student s;
    FILE *f = fopen("students.txt", "r");

    if (f == NULL) {
        printf("⚠️ No data available!\n");
        return;
    }

    printf("\nRoll\tName\t\tMarks\n");
    printf("-----------------------------\n");

    while (fscanf(f, "%d,%[^,],%f\n", &s.roll, s.name, &s.marks) != EOF) {
        printf("%d\t%-15s%.2f\n", s.roll, s.name, s.marks);
    }

    fclose(f);
}

void searchStudent() {
    int roll;
    struct Student s;
    int found = 0;

    printf("Enter Roll Number to Search: ");
    scanf("%d", &roll);

    FILE *f = fopen("students.txt", "r");
    if (f == NULL) {
        printf("⚠️ File not found!\n");
        return;
    }

    while (fscanf(f, "%d,%[^,],%f\n", &s.roll, s.name, &s.marks) != EOF) {
        if (s.roll == roll) {
            printf("✅ Student Found:\nRoll: %d\nName: %s\nMarks: %.2f\n", s.roll, s.name, s.marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("❌ Student not found!\n");
    }

    fclose(f);
}

int main() {
    int choice;

    while (1) {
        printf("\n===== Student Record Management System =====\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student by Roll\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

