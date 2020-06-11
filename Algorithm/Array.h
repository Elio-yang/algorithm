/*
	+---------------------------------------+
	|	Array.h 							|
	|										|
	|	Author:Elio Yang					|
	|	Created on 10/06/2020				|
	|										|
	|	Header      						|
	|										|
	|	Compiled in Visual Studio 2017		|
	|										|
	+---------------------------------------+

*/
#pragma once

#define HEAP_FAILURE -2
#define ARRAY_ERASED -1
#define SUCCESS 0
#define INVALID_POSITION 1
#define POSITION_INIT 2
#define POSITION_NOT_INIT 3
#define POSITION_EMPTY 4
#define ARRAY_FULL 5

// +-------------------------------------+
// |           struct Array              |
// +-------------------------------------+
typedef struct Array {
	int size;
	int *arr;
}Array;

// +-------------------------------------+
// |           Create Array              |
// +-------------------------------------+
Array* creatArray(int size);
Array* getCopyArray(Array *array);

// +-------------------------------------+
// |                I/O                  |
// +-------------------------------------+
int insertValueArray(Array*array, int position, int value);
int removeValueArray(Array*array, int position);
int pushValueArray(Array*array, int value);

// +-------------------------------------+
// |               Erase                 |
// +-------------------------------------+
int eraseArray(Array*array);

// +-------------------------------------+
// |               Switching             |
// +-------------------------------------+
int swichValuesArray(Array*array, int position1, int position2);
int reverseArray(Array*array);

// +-------------------------------------+
// |               Sorting               |
// +-------------------------------------+
int bubbleSortArray(Array*array);
int selectionSortArray(Array*array);

// +-------------------------------------+
// |               Searching             |
// +-------------------------------------+
int valueOccurrenceArray(Array*array, int value);
int findMaxArray(Array*array);
int findMinArray(Array*array);

// +-------------------------------------+
// |                Print                |
// +-------------------------------------+
int printArray(Array*array);


