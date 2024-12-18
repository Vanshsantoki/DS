#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100 
#define M 10            
#define MAX_NAME_LENGTH 50

typedef struct {
    int employeeID;   
    char name[MAX_NAME_LENGTH];
    char department[MAX_NAME_LENGTH];
} Employee;

typedef struct {
    int employeeID;    
    char name[MAX_NAME_LENGTH];
    char department[MAX_NAME_LENGTH];
} HashTableEntry;

int hashFunction(int employeeID, int m) {
    return employeeID % m;
}

void insert(HashTableEntry hashTable[], int m, Employee employee) {
    int index = hashFunction(employee.employeeID, m);
    
    while (hashTable[index].employeeID != 0) {
        index = (index + 1) % m;  
    }

    hashTable[index].employeeID = employee.employeeID;
    strcpy(hashTable[index].name, employee.name);
    strcpy(hashTable[index].department, employee.department);
}

void displayHashTable(HashTableEntry hashTable[], int m) {
    printf("\nHash Table Content:\n");
    for (int i = 0; i < m; i++) {
        if (hashTable[i].employeeID != 0) {
            printf("Index %d: Employee ID = %d, Name = %s, Department = %s\n",
                   i, hashTable[i].employeeID, hashTable[i].name, hashTable[i].department);
        }
    }
}

int main() {
    HashTableEntry hashTable[M] = {0}; 
    
    Employee employees[MAX_RECORDS] = {
        {1234, "Alice", "HR"},
        {2345, "Bob", "IT"},
        {3456, "Charlie", "Finance"},
        {4567, "David", "Marketing"},
        {5678, "Eva", "Sales"}
    };
    
    for (int i = 0; i < 5; i++) {
        insert(hashTable, M, employees[i]);
    }

    displayHashTable(hashTable, M);
    
    return 0;
}
