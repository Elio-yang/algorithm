/*
	+---------------------------------------+
    |   ArrayTests.c                        |
	|                                       |
	|   Author:Elio Yang                    |
	|   Created on 10/06/2020               |
	|                                       |
	|   Tests                               |
	|                                       |
	|	Compiled in Visual Studio 2017      |
	|                                       |
	+---------------------------------------+
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Array.h"

int main() {

	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |               Array Tests           |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	Array*array1 = creatArray(10);
	for (int i = 0; i < array1->size; i++) {
		insertValueArray(array1, i, i + 1);
	}
	printf("Array is:\n");
	printArray(array1);

	Array* array2 = getCopyArray(array1);
	printArray(array2);

	printf("\nCode:%d\n", removeValueArray(array2, 3));
	printArray(array2);

	printf("\nCode:%d\n", pushValueArray(array2, 12));
	printArray(array2);

	Array*array3 = getCopyArray(array1);
	printf("\nCode:%d\n", switchValuesArray(array3, 4, 6));
	printArray(array3);

	printf("\nCode:%d\n", reverseArray(array3));
	printArray(array3);

	Array*array4 = creatArray(50);
	srand(time(NULL));
	for (int i = 0; i < array4->size; i++) {
		insertValueArray(array4, i, rand());
	}
	Array* array4_c1 = getCopyArray(array4);
	Array* array4_c2 = getCopyArray(array4);

	printf("\nOriginal array:");
	printArray(array4_c1);
	
	printf("\nBubble sort:");
	clock_t start1 = clock();
	bubbleSortArray(array4_c1);
	clock_t end1 = clock();
	double time1 = (double)(end1 - start1);
	printArray(array4_c1);

	printf("\nSelection sort:");
	clock_t start2 = clock();
	selectionSortArray(array4_c2);
	clock_t end2 = clock();
	double time2 = (double)(end2 - start2) ;
	printArray(array4_c2);

	printf("\nTotal time used  under bubble sort: %lf ", time1);
	printf("\nTotal time used under selection sort: %lf ", time2);

	printf("\nvalue 6 occurred %d time(s) in this array", valueOccurrenceArray(array4, 6));
	printf("\n max element is %d", findMaxArray(array4));
	printf("\n min element is %d", findMinArray(array4));

	return 0;
}