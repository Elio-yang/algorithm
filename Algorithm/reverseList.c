#ifndef _REVERSELIST_H_
#include"reverselist.h"
#endif // !_REVERSELIST_H_

plist reverseList(plist head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	plist List = (plist)malloc(sizeof(list));
	List = reverseList(head->next);
	plist node1 = (plist)malloc(sizeof(list));
	node1 = head->next;
	node1->next = head;
	head->next = NULL;
	return List;
}