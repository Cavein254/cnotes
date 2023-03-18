/*
Dynamic allocation  of memory using pointers
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* marks_arr;
    int total_marks = 0;
    int num = 0;
    printf("Enter the number of students \n");
    scanf("%d", &num);
    marks_arr = malloc(num * sizeof(int));
    for(int i = 0; i < num; i++) {
        int mark = 0;
        printf("Enter the marks of student %d \n", i+1);
        scanf("%d", &mark);
        marks_arr[i] = mark;
        total_marks  = total_marks + mark;
    }
    for(int j = 0; j < num; j++){
        printf("The %d student got %d \n", j+1, marks_arr[j]);
    }
    printf("The total marks is : %d", total_marks);
    free(marks_arr);
    return 0;
    
}
