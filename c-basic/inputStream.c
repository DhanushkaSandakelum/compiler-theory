#include<stdio.h>

int main() {
    char name[200];

    printf("name>> ");
    fgets(name, sizeof(name), stdin);
    printf("Name is %s", name);
}