#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define OK 1
#define OVERFLOW -2

typedef struct {
    char number[20];
    char name[20];
    double mathscore;
    double englishscore;
    double computerscore;
    double averscore;
} student;

typedef struct {
    student* elem; // Points to the base address of data elements
    int length;    // Current length of the linear table
} SqList;

// Initialize an empty sequential table L
int InitList(SqList* L) {
    L->elem = (student*)malloc(sizeof(student) * MAX); // Allocate memory using malloc
    if (!L->elem)
        exit(OVERFLOW);
    L->length = 0;
    return OK;
}

// Record student scores
void luru(SqList* s) {
    printf("Enter the number of students: ");
    int n;
    scanf("%d", &n);
    s->length += n;
    for (int i = 0; i < n; i++) {
        printf("Enter information for student %d:\n", i + 1);
        printf("Student ID: ");
        scanf("%s", s->elem[i].number);
        printf("Name: ");
        scanf("%s", s->elem[i].name);
        printf("Math score: ");
        scanf("%lf", &s->elem[i].mathscore);
        printf("English score: ");
        scanf("%lf", &s->elem[i].englishscore);
        printf("Computer score: ");
        scanf("%lf", &s->elem[i].computerscore);
        printf("---------------------------------------\n");
    }
}

// Write student data to a file
void shuchu(SqList* s) {
    FILE* fp;
    if ((fp = fopen("input.dat", "w")) == NULL) {
        printf("Cannot open file!\n");
        return;
    }
    for (int i = 0; i < s->length; i++) {
        fprintf(fp, "Student ID: %s\tName: %s\tMath score: %.1lf\tEnglish score: %.1lf\tComputer score: %.1lf\tAverage score: %.1lf\n",
            s->elem[i].number, s->elem[i].name, s->elem[i].mathscore,
            s->elem[i].englishscore, s->elem[i].computerscore, s->elem[i].averscore);
    }
    fclose(fp);
}

// Sort scores for each subject from highest to lowest
void mathsort(SqList* s) {
    student temp;
    FILE* fp;
    if ((fp = fopen("MathScoreSorted.dat", "w")) == NULL) {
        printf("Cannot open file!\n");
        return;
    }
    for (int i = 0; i < s->length; i++) {
        s->elem[i].averscore = (s->elem[i].computerscore + s->elem[i].englishscore + s->elem[i].mathscore) / 3;
    }
    for (int i = 0; i < s->length - 1; i++) {
        for (int j = 0; j < s->length - 1 - i; j++) {
            if (s->elem[j].mathscore < s->elem[j + 1].mathscore) {
                temp = s->elem[j];
                s->elem[j] = s->elem[j + 1];
                s->elem[j + 1] = temp;
            }
        }
    }
    printf("Math scores sorted:\n");
    fprintf(fp, "Math scores sorted:\n");
    for (int i = 0; i < s->length; i++) {
        fprintf(fp, "Student ID: %s\tName: %s\tMath score: %.1lf\n",
            s->elem[i].number, s->elem[i].name, s->elem[i].mathscore);
        printf("Student ID: %s\tName: %s\tMath score: %.1lf\n",
            s->elem[i].number, s->elem[i].name, s->elem[i].mathscore);
    }
    fclose(fp);
}

// English score sorting
void englishsort(SqList* s) {
    student temp;
    FILE* fp;
    if ((fp = fopen("EnglishScoreSorted.dat", "w")) == NULL) {
        printf("Cannot open file!\n");
        return;
    }
    for (int i = 0; i < s->length; i++) {
        s->elem[i].averscore = (s->elem[i].computerscore + s->elem[i].englishscore + s->elem[i].mathscore) / 3;
    }
    for (int i = 0; i < s->length - 1; i++) {
        for (int j = 0; j < s->length - 1 - i; j++) {
            if (s->elem[j].englishscore < s->elem[j + 1].englishscore) {
                temp = s->elem[j];
                s->elem[j] = s->elem[j + 1];
                s->elem[j + 1] = temp;
            }
        }
    }
    printf("English scores sorted:\n");
    fprintf(fp, "English scores sorted:\n");
    for (int i = 0; i < s->length; i++) {
        fprintf(fp, "Student ID: %s\tName: %s\tEnglish score: %.1lf\n",
            s->elem[i].number, s->elem[i].name, s->elem[i].englishscore);
        printf("Student ID: %s\tName: %s\tEnglish score: %.1lf\n",
            s->elem[i].number, s->elem[i].name, s->elem[i].englishscore);
    }
    fclose(fp);
}

// Computer score sorting
void computersort(SqList* s) {
    student temp;
    FILE* fp;
    if ((fp = fopen("ComputerScoreSorted.dat", "w")) == NULL) {
        printf("Cannot open file!\n");
        return;
    }
    for (int i = 0; i < s->length; i++) {
        s->elem[i].averscore = (s->elem[i].computerscore + s->elem[i].englishscore + s->elem[i].mathscore) / 3;
    }
    for (int i = 0; i < s->length - 1; i++) {
        for (int j = 0; j < s->length - 1 - i; j++) {
            if (s->elem[j].computerscore < s->elem[j + 1].computerscore) {
                temp = s->elem[j];
                s->elem[j] = s->elem[j + 1];
                s->elem[j + 1] = temp;
            }
        }
    }
    printf("Computer scores sorted:\n");
    fprintf(fp, "Computer scores sorted:\n");
    for (int i = 0; i < s->length; i++) {
        fprintf(fp, "Student ID: %s\tName: %s\tComputer score: %.1lf\n",
            s->elem[i].number, s->elem[i].name, s->elem[i].computerscore);
        printf("Student ID: %s\tName: %s\tComputer score: %.1lf\n",
            s->elem[i].number, s->elem[i].name, s->elem[i].computerscore);
    }
    fclose(fp);
}

// Sorting by average score
void average(SqList* s) {
    student temp;
    FILE* fp;
    if ((fp = fopen("AverageScoreSorted.dat", "w")) == NULL) {
        printf("Cannot open file!\n");
        return;
    }
    for (int i = 0; i < s->length; i++) {
        s->elem[i].averscore = (s->elem[i].computerscore + s->elem[i].englishscore + s->elem[i].mathscore) / 3;
    }
    for (int i = 0; i < s->length - 1; i++) {
        for (int j = 0; j < s->length - 1 - i; j++) {
            if (s->elem[j].averscore < s->elem[j + 1].averscore) {
                temp = s->elem[j];
                s->elem[j] = s->elem[j + 1];
                s->elem[j + 1] = temp;
            }
        }
    }
    printf("Sorted by average score:\n");
    fprintf(fp, "Sorted by average score:\n");
    for (int i = 0; i < s->length; i++) {
        fprintf(fp, "Student ID: %s\tName: %s\tMath score: %.1lf\tEnglish score: %.1lf\tComputer score: %.1lf\tAverage score: %.1lf\n",
            s->elem[i].number, s->elem[i].name, s->elem[i].mathscore,
            s->elem[i].englishscore, s->elem[i].computerscore, s->elem[i].averscore);
        printf("Student ID: %s\tName: %s\tMath score: %.1lf\tEnglish score: %.1lf\tComputer score: %.1lf\tAverage score: %.1lf\n",
            s->elem[i].number, s->elem[i].name, s->elem[i].mathscore,
            s->elem[i].englishscore, s->elem[i].computerscore, s->elem[i].averscore);
    }
    fclose(fp);
}

// Function to determine score range
int fenduan(double x) {
    if (x < 60) return 0;
    else if (60 <= x && x < 70) return 1;
    else if (70 <= x && x < 80) return 2;
    else if (80 <= x && x < 90) return 3;
    else if (90 <= x && x <= 100) return 4;
}

// Score analysis
void fenxi(SqList* s) {
    double math_result[8] = { 0 }, english_result[8] = { 0 }, computer_result[8] = { 0 };
    for (int i = 0; i < s->length; i++) {
        math_result[0] += s->elem[i].mathscore;
        english_result[0] += s->elem[i].englishscore;
        computer_result[0] += s->elem[i].computerscore;

        int q1 = fenduan(s->elem[i].mathscore);
        switch (q1) {
        case 0: math_result[1]++; break;
        case 1: math_result[2]++; break;
        case 2: math_result[3]++; break;
        case 3: math_result[4]++; break;
        case 4: math_result[5]++; break;
        }

        int q2 = fenduan(s->elem[i].englishscore);
        switch (q2) {
        case 0: english_result[1]++; break;
        case 1: english_result[2]++; break;
        case 2: english_result[3]++; break;
        case 3: english_result[4]++; break;
        case 4: english_result[5]++; break;
        }

        int q3 = fenduan(s->elem[i].computerscore);
        switch (q3) {
        case 0: computer_result[1]++; break;
        case 1: computer_result[2]++; break;
        case 2: computer_result[3]++; break;
        case 3: computer_result[4]++; break;
        case 4: computer_result[5]++; break;
        }

        if (s->elem[i].mathscore > math_result[6]) math_result[6] = s->elem[i].mathscore;
        if (s->elem[i].englishscore > english_result[6]) english_result[6] = s->elem[i].englishscore;
        if (s->elem[i].computerscore > computer_result[6]) computer_result[6] = s->elem[i].computerscore;

        if (s->elem[i].mathscore < math_result[7]) math_result[7] = s->elem[i].mathscore;
        if (s->elem[i].englishscore < english_result[7]) english_result[7] = s->elem[i].englishscore;
        if (s->elem[i].computerscore < computer_result[7]) computer_result[7] = s->elem[i].computerscore;
    }

    math_result[0] = math_result[0] / s->length;
    english_result[0] = english_result[0] / s->length;
    computer_result[0] = computer_result[0] / s->length;

    printf("Math average score: %.1lf\n", math_result[0]);
    printf("Number of students with failing math score: %.0lf\n", math_result[1]);
    printf("Number of students with math score between 60-69: %.0lf\n", math_result[2]);
    printf("Number of students with math score between 70-79: %.0lf\n", math_result[3]);
    printf("Number of students with math score between 80-89: %.0lf\n", math_result[4]);
    printf("Number of students with math score above 90: %.0lf\n", math_result[5]);
    printf("Maximum math score: %.1lf\n", math_result[6]);
    printf("Minimum math score: %.1lf\n", math_result[7]);

    printf("English average score: %.1lf\n", english_result[0]);
    printf("Number of students with failing English score: %.0lf\n", english_result[1]);
    printf("Number of students with English score between 60-69: %.0lf\n", english_result[2]);
    printf("Number of students with English score between 70-79: %.0lf\n", english_result[3]);
    printf("Number of students with English score between 80-89: %.0lf\n", english_result[4]);
    printf("Number of students with English score above 90: %.0lf\n", english_result[5]);
    printf("Maximum English score: %.1lf\n", english_result[6]);
    printf("Minimum English score: %.1lf\n", english_result[7]);

    printf("Computer average score: %.1lf\n", computer_result[0]);
    printf("Number of students with failing Computer score: %.0lf\n", computer_result[1]);
    printf("Number of students with Computer score between 60-69: %.0lf\n", computer_result[2]);
    printf("Number of students with Computer score between 70-79: %.0lf\n", computer_result[3]);
    printf("Number of students with Computer score between 80-89: %.0lf\n", computer_result[4]);
    printf("Number of students with Computer score above 90: %.0lf\n", computer_result[5]);
    printf("Maximum Computer score: %.1lf\n", computer_result[6]);
    printf("Minimum Computer score: %.1lf\n", computer_result[7]);
}



// Function to search for a student's scores by their ID
void search(SqList* s) {
    char num[20];
    int found = 0;
    printf("Please enter the student ID to search: ");
    scanf("%s", num);
    for (int i = 0; i < s->length; i++) {
        if (strcmp(s->elem[i].number, num) == 0) {
            printf("Student information:\n");
            printf("Student ID: %s\tName: %s\tMath score: %.1lf\tEnglish score: %.1lf\tComputer score: %.1lf\tAverage score: %.1lf\n",
                s->elem[i].number, s->elem[i].name, s->elem[i].mathscore,
                s->elem[i].englishscore, s->elem[i].computerscore, s->elem[i].averscore);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student information not found.\n");
    }
}

// Main function
int main() {
    SqList studentList;
    int choice;

    if (InitList(&studentList) != OK) {
        printf("Initialization failed!\n");
        return 1;
    }

    while (1) {
        printf("\nStudent Score Management System\n");
        printf("1. Enter student scores\n");
        printf("2. Output student scores\n");
        printf("3. Sort by Math score\n");
        printf("4. Sort by English score\n");
        printf("5. Sort by Computer score\n");
        printf("6. Sort by average score\n");
        printf("7. Score analysis\n");
        printf("8. Search for student scores\n");
        printf("0. Exit\n");
        printf("Please select an option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            luru(&studentList);
            break;
        case 2:
            shuchu(&studentList);
            break;
        case 3:
            mathsort(&studentList);
            break;
        case 4:
            englishsort(&studentList);
            break;
        case 5:
            computersort(&studentList);
            break;
        case 6:
            average(&studentList);
            break;
        case 7:
            fenxi(&studentList);
            break;
        case 8:
            search(&studentList);
            break;
        case 0:
            exit(0);
        default:
            printf("Invalid option, please try again.\n");
        }
    }
    return 0;
}


