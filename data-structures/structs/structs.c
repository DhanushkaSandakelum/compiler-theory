#include<stdio.h>

struct record{
    char name[100];
    char gender;
    int age;
};

void main() {
    struct record studentRecord[5];

    int std_no = 2;
    printf("Enter the details: ");

    for(int i = 0; i < std_no; i++){
        printf("\nRecord %d\n", i+1);
        printf("\nEnter name, gender and age: ");
        scanf("%s %c %d", &studentRecord[i].name, &studentRecord[i].gender, &studentRecord[i].age);
    }

    printf("\nName\tGender\tAge\n");
    for(int i = 0; i < std_no; i++){
        printf("\n%s\t%c\t%d", studentRecord[i].name, studentRecord[i].gender, studentRecord[i].age);
    }
}