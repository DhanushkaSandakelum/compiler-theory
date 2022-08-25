#include <stdio.h>

struct student {
	char name[100];
	int age;
};

struct student st1 = {"Dhanushka", 22};

int main() {
	struct student* ptr = &st1;
	
	printf("Name: %s\n", st1.name);
	printf("Age: %d\n", ptr->age);
}
