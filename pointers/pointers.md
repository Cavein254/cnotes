# POINTERS IN C

A pointer is a variable that stores the address of a memory location. Pointer are used to access the memory locations of variables and manupilate their addresses. 
To understand, you can think of memory as a large city. A city has numerous houses. So how do we differentiate between houses? We can use Mail box numbers to make this diffrentiation. Mail box numbers are similar to addresses in memory.

#### Declaring pointers in C

Pointers are declared using a data type followed by an asterick
```c
int* ptr;
```

After declaration, we can now initialize pointers using the ampersand symbol `&`
```c
int num = 10;
int* ptr;
ptr = &num;
```
Note the the `&` symbol returns the memory address in the above case the memory address of `a`.
```c
#include <stdio.h>

int main () {
    int num = 10;
    int* ptr;
    ptr = &num;
    printf("The address of num is %p \n", &num);
    printf("The address of ptr is %p \n", ptr);
    //Accessing the value of variable directly
    printf("The value of num is %d \n", num);
    //Accessing the value of variable indirectly
    printf("The value of ptr is %d \n", *ptr);
}
```
```bash
The address of num is 0x7ffd7483f0bc 
The address of ptr is 0x7ffd7483f0bc 
The value of num is 10 
The value of ptr is 10 
```
Notice that we use the `%p` in `printf` to display the addresses. As shown above, `ptr` has the same address as `num`. These addresses also contain the same values.
#### Pointer initialization
Pointers in `c` are initialized using the following command:
```c
int num;
int* ptr = &num;
```
#### Dereferencing a pointer
When we have the address of a variable, we can find the value within the memory by dereferencing the pointer to display the contents.
```c
in a = 10;
printf("%d \n", *(&a));
```
An advantage of using pointers is that it enables us to determine the value of a variable regardless of previous alternations
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
## POINTER IN ARITHMETICS
It does not make sense in `c` to add two pointers. Remember, pointers are just addresses of memory locations. Therefore if it were allowed to add two pointer, the result would be a new memory location with garbage in it.
The usefulness of pointer arithmetics is evident when dealing with arrays as shown:
```c
//declare an array
int arr[5] = {10, 20, 30, 40, 50};
// declare a total variable
int total = 0;
//declare a pointer variable
int* ptr;
//assign the pointer to the first element of the array
ptr = arr; //This is similar to ptr == &a[0]
  for(int i = 0; i < 5; i++) {
    total = total + *ptr;
    printf("Adding %d to total becomes %d \n", *ptr, total);
    ptr++; //Move the pointer to the next location
  }
```
```bash
Adding 10 to total becomes 10 
Adding 20 to total becomes 30 
Adding 30 to total becomes 60 
Adding 40 to total becomes 100 
Adding 50 to total becomes 150 
```


## POINTERS AND STRINGS
In c, strings are array of characters that end with the zero delimitor `\0`;
```c
char my_string = [20];
my_string[0]='I';
my_string[1]=' ';
my_string[2]='c';
my_string[3]='o';
my_string[4]='d';
my_string[5]='e';
my_string[6]='\0';
```
The above `my_string` is a valid string in c. The above can also be written as
```c
char my_string[20] = {'I', ' ', 'c', 'o', 'd', 'e', '\0'};
```
But a much simpler way is:
```c
char my_string[20] = "I code";
```
When using double quotes, there is no need of adding `\0`.
```c
char str1[50] = "We doing hard things";
char str2[50];
    
char* p1;
char* p2;
    
p1 = str1;
p2 = str2;
    
printf("The original value of str1 is:=>  %s \n", str1);
printf("The original value of str2 is:=>  %s \n", str2);
    
while (*p1 != '\0') // '\0' represents the end of the string
{
    *p2 = *p1;
    //move the pointer to the next location
    *p1++;
    *p2++;
}
// Add '\0' to the end of the string
*p2 = '\0';
    
printf("The new value of str1 is:=>  %s \n", str1);
printf("The new value of str2 is:=>  %s \n", str2);
    
return 0;
```
```bash
The original value of str1 is:=>  We doing hard things 
The original value of str2 is:=>   
The new value of str1 is:=>  We doing hard things 
The new value of str2 is:=>  We doing hard things 
```
Assuming: 
```c
int a = 10;
int* ptr = &a;
```
Then;
| **Expression**   | **Equivalent** | **Answer** |
|------------------|----------------|------------|
| z = *ptr + 10    | z = a + 10     | z = 30     |
| *ptr = *ptr + 10 | a = a + 10     | a = 30     |
| *ptr+=10         | a+=10          | a = 30     |
| *ptr++           | a++            | 11         |

## TYPES OF POINTERS
The C language provides a variety of pointers.

1. THE NULL POINTER


This is a pointer with a value of '0'. Null pointers are useful in declaring pointers that have not been assigned addresses. 
```c
int* a = NULL;
printf("The value of a is %d", a);
```
```bash
The value of a is 0
```
2. THE VOID (GENERIC) POINTER


This type of pointer has no data type. This pointer is useful when storing variables that have unknown data types
```c
void* a = NULL
```
3. THE WILD POINTER


This is a pointer that has not yet been initialized. They point to memory location that are unknown and contain garbage data. Therefore, not advisable to use as it may crush your program.
```c
int* a; //Wild pointer
printf("%d",*a);
```
```bash
Segmentation fault
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