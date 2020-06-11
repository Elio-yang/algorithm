/*
    +---------------------------------------+
    |   Array.c                             |
    |                                       |
    |   Author:Elio Yang                    |
    |   Created on 10/06/2020               |
    |                                       |
    |   Implementation                      |
    |                                       |
    |	Compiled in Visual Studio 2017      |
    |                                       |
    +---------------------------------------+
*/

/*

		RETURN VALUE 

	-1  array erased
	0   successful
	1   invalid position for this array
	2	this position has been initialized
	3	this position hasn't been initialized
	4	position has already been empty
	5	this array is full 

*/

#include"Array.h"
#include<stdio.h>
#include<stdlib.h>
void swap(Array*array, int position1, int position2);

Array* creatArray(int size) {
	Array* array = (Array*)malloc(sizeof(Array));
	array->arr = (int*)malloc(size * sizeof(int));
	array->size = size;
	int i = 0;
	while (i<size) {
		array->arr [i] = 0;
		i++;
	}
	return array;
}

Array* getCopyArray(Array*arr_sample) {
	Array* array_copy = (Array*)malloc(sizeof(Array));
	array_copy->arr = (int*)malloc(arr_sample->size * sizeof(int));
	array_copy->size = arr_sample->size;
	int i = 0;
	while (i<arr_sample->size) {
		array_copy [i] = arr_sample [i];
		i++;
	}
	return array_copy;
}

int insertValueArray(Array*array, int position, int value) {
	if ((unsigned)position < (unsigned)array->size) {
		if (array->arr [position] != 0) {
			array->arr [position] = value;
			return SUCCESS;
		}
		else {
			return POSITION_INIT;
		}
	}
	return INVALID_POSITION;
}
int removeValueArray(Array*array, int position) {
	if ((unsigned)position <(unsigned) array->size) {
		if (array->arr [position] != 0) {
			array->arr [position] = 0;
			return SUCCESS;
		}
		else {
			return POSITION_EMPTY;
		}
	}
	return INVALID_POSITION;
}

int pushValueArray(Array*array, int value) {
	int flag = 0;
	for (int i = 0; i < array->size; i++) {
		if (array->arr [i] == 0) {
			array->arr [i] = value;
			flag = 1;
			break;
		}
	}
	return (!flag) ? ARRAY_FULL : SUCCESS;
}

int eraseArray(Array*array) {
	int i=0;
	while ((unsigned)i<(unsigned)array->size) {
		array->arr [i] = 0;
		i++;
	}
	return SUCCESS;
}

int swichValuesArray(Array*array, int position1, int position2) {
	if ((((unsigned)array->size - (unsigned)position1) | ((unsigned)array->size - (unsigned)position2) )> 0) {
		array->arr [position1] ^= array->arr [position2];
		array->arr [position2] ^= array->arr [position1];
		array->arr [position1] ^= array->arr [position2];
		return SUCCESS;
	}
	return INVALID_POSITION;
}
void swap(Array*array, int position1, int position2) {
	array->arr [position1] ^= array->arr [position2];
	array->arr [position2] ^= array->arr [position1];
	array->arr [position1] ^= array->arr [position2];
}
int reverseArray(Array*array) {
	for (int i = 0; i < (array->size >>1); i++) {
		swap(array, i, array->size - i - 1);
	}
	return SUCCESS;
}
int bubbleSortArray(Array*array) {
	int i;
	int j;
	for (i = 0; i < array->size-1; i++) {
		for (j = 0; j < array->size - i - 1; j++) {
			if (array->arr [j] > array->arr [j + 1]) {
				swap(array, j, j + 1);
			}
		}
	}
	return SUCCESS;
}
int selectionSortArray(Array*array) {
	int i;
	int j;
	int min;
	for (i = 0; i < array->size - 1; i++) {
		min = i;
		for (j = i + 1; j < array->size; j++) {
			if (array->arr [j] < array->arr [min]) {
				min = j;
			}
		}
		swap(array, min, i);
	}
	return SUCCESS;
}
int valueOccurrenceArray(Array*array, int value) {
	int cnt = 0;
	int i=0;
	while (++i<array->size) {
		if (array->arr [i] == value) {
			cnt++;
		}
	}
	return cnt;
}
int findMaxArray(Array*array) {
	int min = array->arr [0];
	int i=0;
	while (++i<array->size) {
		if (array->arr [i] < min) {
			min = array->arr [i];
		}
	}
	return min;
}

int findMinArray(Array*array) {
	int max = array->arr [0];
	int i = 0;
	while (++i < array->size) {
		if (array->arr [i] < max) {
			max = array->arr [i];
		}
	}
	return max;
}

int printArray(Array*array) {
	printf("\t Array\n");
	int i=0;
	while (++i<array->size) {
		printf("%d ", array->arr [i]);
	}
	printf("\n");
	return SUCCESS;
}