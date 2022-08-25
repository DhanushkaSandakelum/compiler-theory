#include <stdio.h>
#include <string.h>

struct record {
	char name[50];
	char gender;
	int age;
};

struct record group[10];

int main() {
	int counter;
	struct record studentRecord[5];
	
	int std_number = 2;
	printf("enter % records of the group\n", std_number);
	
	for(counter = 0; counter < std_number; counter++) {
		printf("Record count: %d\n", counter+1);
		printf("Enter name: ");
		scanf("%s", &studentRecord[counter].name);
		printf("Enter gender: ");
		scanf(" %c", &studentRecord[counter].gender);
		printf("Enter age: ");
		scanf(" %d", &studentRecord[counter].age);
		
	}
	
	printf("Student information list\n");
	for(counter = 0; counter < std_number; counter++) {
		printf("%d: Name - %s Gender - %c Age: %d\n", counter+1,
			studentRecord[counter].name,
			studentRecord[counter].gender,
			studentRecord[counter].age
		);
		
	}
	
	return 0;
}

