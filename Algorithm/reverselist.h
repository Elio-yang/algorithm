#ifndef _REVERSELIST_H_
#define _REVERSELIST_H_
typedef struct LinkList list;
typedef struct LinkList* plist;
struct LinkList {
	int data;
	plist next;
};

plist reverseList(plist head);
#endif // !_REVERSELIST_H_
