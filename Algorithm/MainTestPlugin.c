#include<stdio.h>
#include<stdlib.h>
#include"reverselist.h"//��ת������

int main() {
/*******************��ת������*************************/
	plist head = (plist)malloc(sizeof(list));
	plist Node1 = (plist)malloc(sizeof(list));
	plist Node2 = (plist)malloc(sizeof(list));
	plist Node3 = (plist)malloc(sizeof(list));
	head->next = Node1;
	Node1->data = 1;
	Node1->next = Node2;
	Node2->data = 2;
	Node2->next = Node3;
	Node3->data = 3;
	Node3->next = NULL;
	plist newList = (plist)malloc(sizeof(list));
	newList = reverseList(head);
	while (newList->next!=NULL) {
		printf("%d", newList->data);
		newList = newList->next;
	}
/****************************************************/
	return 0;
}