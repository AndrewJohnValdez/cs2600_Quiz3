//Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c 

//gcc employeeMain.c employeeTable.c employeeTwo.c 

#include <string.h> 

#include <stdlib.h> 

#include "employee.h" 

int main(void)
{ 
   //defined in employeeSearchOne.c 
   PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind); 
   PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
   PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);
   PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char * phoneToFind); 

   //defined in employeeTable.c 
   extern Employee EmployeeTable[];  
   //extern means this variable was defined somewhere else and is being used here

   extern const int EmployeeTableEntries;  
 
   PtrToEmployee matchPtr; //Declaration 

   matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045); 

   //Example not found 
   if (matchPtr != NULL) 
      printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable); 
   else 
      printf("Employee ID is NOT found in the record\n"); 


   //Example found 
   matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat"); 
 
   if (matchPtr != NULL) 
      printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable); 
   else 
      printf("Employee Tony Bobcat is NOT found in the record\n"); 

   //Assignment: have a search function look for a match and no match for phone number and salary

   //Example found (Tammy Franklin's number)
   matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "213-555-1212");

   if(matchPtr != NULL)
      printf("Employee Phone Number 213-555-1212 is in record %d\n", matchPtr - EmployeeTable);
   else 
      printf("Employee Phone Number is NOT found in the record\n");

   //Example not found
   matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "201-293-2849");

   if(matchPtr != NULL)
      printf("Employee Phone Number 213-555-1212 is in record %d\n", matchPtr - EmployeeTable);
    else 
      printf("Employee Phone Number is NOT found in the record\n");

   //Tony Bobcat salary
   matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 6.34);

   if(matchPtr != NULL)
      printf("Employee Salary 6.34 is in record %d\n", matchPtr - EmployeeTable);
   else 
      printf("Employee Salary is NOT found in the record\n");

   //No Salary Found
   matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 1.24);

   if(matchPtr != NULL)
      printf("Employee Salary 6.34 is in record %d\n", matchPtr - EmployeeTable);
   else 
      printf("Employee Salary is NOT found in the record\n");


 return EXIT_SUCCESS; 
} 