# POINTERS IN C

A pointer is a variable that stores the address of a memory location

Pointers are declared using a data type followed by an asterick
```c
int* ptr;
```
Pointers will enable us to determine the value of a variable regardless of previous alternations
```c
    int num;
    int* ptr = &num;
    
    num = 12;
    printf("The value of num is %d \n", *ptr);
    // After several alternations
    //...
    num = 1234;
    printf("The value of num is %d \n", *ptr);
```
```bash
The value of num is 12 
The value of num is 1234 
```
## POINTERS IN ARITHMETICS
It does not make sense in `c` to add two pointers. Remember, pointers are just addresses of memory locations. Therefore if it were allowed to add two pointer, the result would be a new memory location with garbage in it.
```c
int num1;
int num2;
int result = num1 + num2;
    
int* ptr1 = &num1;
int* ptr2 = &num2;
int* ptr_rst = &result;
    
num1 = 100;
num2 = 200;
    
printf("The value of the num1 is %d \n", *ptr1); 
printf("The value of the num2 is %d \n", *ptr2); 
printf("The value of the result is %d \n", *ptr_rst);  
```
```bash
The value of the num1 is 100 
The value of the num2 is 200 
The value of the result is 0 
```
Notice in the above code instead of getting `300` as the `result` our value is `0` which is wrong.

The usefulness of pointer arithmetics is evident when dealing with arrays as shown:
```c
//declare an array
int arr[5] = {10, 20, 30, 40, 50};
// declare a total variable
int total = 0;
//declare a pointer variable
int* ptr;
//assign the pointer to the first element of the array
ptr = arr;
  for(int i = 0; i < 5; i++) {
    total = total + *ptr;
    printf("Adding %d to total becomes %d \n", *ptr, total);
    ptr++;
  }
```
```bash
Adding 10 to total becomes 10 
Adding 20 to total becomes 30 
Adding 30 to total becomes 60 
Adding 40 to total becomes 100 
Adding 50 to total becomes 150 
```

Pointers in `c` are initialized using the following command:
```c
int num;
int* ptr = &num;
```
## Gotcha

> **Segmentation fault** is a specific kind of error caused by accessing memory that 'does not belong to you'. Its a helper function that keeps you from corrupting the memory and introducinng hard to debug bugs.

> Segmentation fault occurs when:
1. Accessing an already freed memory
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    int* ptr = malloc(sizeof(int));
    
    num = 10;
    ptr = &num;
    
    printf("The value of ptr is %d \n", *ptr);
    free(*ptr);
    printf("The value of the new ptr is %d \n", *ptr);
    return 0;
}
```
```bash
The value of ptr is 10 
Segmentation fault
```

2. Writing to a read only memory segment

```c
 char * str = "kello world";
 str[0] = 'h'; 
```
```bash
Segmentation fault
```

3. Derefencing a freed pointer

```c
    int* ptr = malloc(sizeof(int));
    int num = 10;
    
    ptr = &num;
    free(*ptr);
    *ptr=5;
    printf("The value of ptr is %d", *ptr); 
```
```bash
Segmentation fault
```
4. Accessing and out-of-bound Array
```c
    int arr[5];
    arr[10] = 50;
```
```bash
Segmentation fault
```
5. Using a null pointer
```c
    int* ptr;
    *ptr = 5; //error
```
```bash
Segmentation fault
```