#include <stdio.h> 

#include <stddef.h> 

typedef struct { 

 long number; //4 bytes

 char *name; //pointer to char(4)

 char *phone; //point to char(4)

 double salary; //8 bytes

} Employee, *PtrToEmployee; 

typedef const Employee *PtrToConstEmployee; 