#include<stdio.h>

void main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 0;

    FILE *fp = fopen("data1.txt", "w");

    int i;
    for(i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++){
        n = fprintf(fp, "%3d\n", arr[i]);

        if(n < 0){
            printf("Error in writing the number %d", i);
        }
    }

    fclose(fp);
}