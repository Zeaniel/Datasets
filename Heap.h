#ifndef Heap_h
#define Heap_h

#define SORT_FILE_ID 1216250 // Special information for the first block of a heap file

#define TRUE 1
#define FALSE 0

typedef struct Record {
	int id;
	char name[15];
	char surname[20];
	char city[25];
} Record;

int HP_CreateFile(char*);
int HP_OpenFile(char*);
int HP_CloseFile(int);
int HP_InsertEntry(int, Record);
void HP_GetAllEntries(int, int, void*);
int HP_SplitFiles(char*, const int);
int HP_DeleteFile(const char*);
int HP_MergeFiles(char*, char*, char*, const int);

Record* bubbleSortedRecords(Record*, const int, const int);
Record* mergeSortedRecords(Record*, Record*, const int, const int, const int);

#endif
