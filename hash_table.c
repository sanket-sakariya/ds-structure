// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define TABLE_SIZE 10

// typedef struct {
//     int key;
//     int value;
// } Entry;

// typedef struct {
//     Entry *table;
//     int size;
// } HashTable;

// HashTable* createHashTable(int size) {
//     HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
//     hashTable->table = (Entry*)malloc(sizeof(Entry) * size);
//     hashTable->size = size;

//     for (int i = 0; i < size; i++) {
//         hashTable->table[i].key = -1;
//     }

//     return hashTable;
// }

// int hash(int key, int size) {
//     return key % size;
// }

// void insert(HashTable* hashTable, int key, int value) {
//     int index = hash(key, hashTable->size);

//     while (hashTable->table[index].key != -1) {
//         index = (index + 1) % hashTable->size;
//     }

//     hashTable->table[index].key = key;
//     hashTable->table[index].value = value;
// }

// void display(HashTable* hashTable) {
//     printf("Hash Table:\n");
//     printf("Index\tKey\tValue\n");
//     for (int i = 0; i < hashTable->size; i++) {
//         printf("%d\t%d\t%d\n", i, hashTable->table[i].key, hashTable->table[i].value);
//     }
// }

// int main() {
//     HashTable* hashTable = createHashTable(TABLE_SIZE);

//     insert(hashTable, 1, 10);
//     insert(hashTable, 2, 20);
//     insert(hashTable, 12, 120);
//     insert(hashTable, 7, 70);

//     display(hashTable);

//     free(hashTable->table);
//     free(hashTable);

//     return 0;
// }



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct {
    int key;
    int value;
} Entry;

typedef struct {
    Entry *table;
    int size;
} HashTable;

HashTable* createHashTable(int size) {
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    hashTable->table = (Entry*)malloc(sizeof(Entry) * size);
    hashTable->size = size;

    for (int i = 0; i < size; i++) {
        hashTable->table[i].key = -1;
    }

    return hashTable;
}

int hash(int key, int size) {
    return key % size;
}

void insert(HashTable* hashTable, int key, int value) {
    int index = hash(key, hashTable->size);

    while (hashTable->table[index].key != -1) {
        index = (index + 1) % hashTable->size;
    }

    hashTable->table[index].key = key;
    hashTable->table[index].value = value;
}

void display(HashTable* hashTable) {
    printf("Hash Table:\n");
    printf("Index\tKey\tValue\n");
    for (int i = 0; i < hashTable->size; i++) {
        printf("%d\t%d\t%d\n", i, hashTable->table[i].key, hashTable->table[i].value);
    }
}

int main() {
    HashTable* hashTable = createHashTable(TABLE_SIZE);

    int key, value;
    char choice;

    do {
        printf("Enter key: ");
        scanf("%d", &key);

        printf("Enter value: ");
        scanf("%d", &value);

        insert(hashTable, key, value);

        printf("Do you want to insert another key-value pair? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    display(hashTable);

    free(hashTable->table);
    free(hashTable);

    return 0;
}