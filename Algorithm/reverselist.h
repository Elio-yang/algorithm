#include<stdio.h>
#include<stdlib.h>

typedef struct LinkList list;
typedef struct LinkList* plist;
struct LinkList {
	int data;
	plist next;
};

plist reverseList(plist head);
