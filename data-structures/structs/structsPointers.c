#include<stdio.h>

struct st{
    char name[50];
    int val;
};

struct st a = {"abc", 20};

void main() {
    struct st* ptr = &a;
    printf("Using direct access");
    printf("\n%s %d", a.name, a.val);
    printf("\nUsing pointer access");
    printf("\n%s %d", ptr->name, ptr->val);
}
