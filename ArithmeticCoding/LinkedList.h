#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#define EMPTYLIST NULL
#define ERROR ((void*) -1)

typedef struct linkedList* LinkedList;
typedef struct limits_config* LimitsConfig;

LinkedList newLinkedList();

LimitsConfig newLimitsConfig(double low, double high);

LinkedList getNextNodeLinkedList(LinkedList ll);

LinkedList searchLinkedList(LinkedList, char);

void* getContentLinkedList(LinkedList);

LimitsConfig getLimitsConfigLinkedList(LinkedList ll);

double getLowLimitsConfig(LimitsConfig lc);

double getHighLimitsConfig(LimitsConfig lc);

LinkedList nextLinkedList(LinkedList);

LinkedList insertAfterLinkedList(LinkedList, char, void*);

LinkedList insertBeginningLinkedList(LinkedList, char, void*);

LinkedList insertLimitsConfigBeginningLinkedList(LinkedList ll, char key, LimitsConfig lc);

LinkedList updateLinkedList(LinkedList ll, char key, void* content);

LinkedList removeAfterLinkedList(LinkedList);

LinkedList removeByKeyLinkedList(LinkedList, char);

LinkedList removeBeginningLinkedList(LinkedList);

LinkedList invertLinkedList(LinkedList);

void deleteLinkedList(LinkedList);

void toString(LinkedList ll);

int sizeLinkedList(LinkedList ll);

#endif // LINKEDLIST_H_INCLUDED
