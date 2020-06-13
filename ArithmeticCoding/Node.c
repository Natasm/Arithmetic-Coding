#include <stdlib.h>
#include "Node.h"

struct node {
   char ch;
   int frequence;
};

Node newNode(char c, int freq){
    Node createNode = (Node) malloc(sizeof(struct node));
    createNode->ch = c;
    createNode->frequence = freq;
    return createNode;
}

char getKeyNode(Node n){
    return n->ch;
}

int getContentNode(Node n){
    return n->frequence;
}





