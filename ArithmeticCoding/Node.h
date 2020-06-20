#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

typedef struct node* Node;

Node newNode(char c, int freq);

char getKeyNode(Node n);

int getContentNode(Node n);

Node addContentNode(Node n, int add);

#endif // NODE_H_INCLUDED
