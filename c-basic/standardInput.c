#include<stdio.h>

int main(){
   struct 
   {
    char name[50];
    char gender;
    int age;
   } person;
   
   printf("name>> ");
   scanf("%s", person.name);
   printf("gender>> ");
   scanf(" %c", &person.gender);
   printf("age>> ");
   scanf(" %d", &person.age);

   printf("\nname: %s | gender: %c | age: %d", person.name, person.gender, person.age);
}