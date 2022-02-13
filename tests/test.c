#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member) ({ \
     const typeof( ((type *)0)->member ) *__mptr = (ptr); \
     (type *)( (char *)__mptr - offsetof(type,member) );})

typedef struct Node Node;
struct Node {
   int data;
   dlNode_t dlNode;
};

int cmpDl(dlNode_t *a, dlNode_t *b) {
   Node *ae = container_of(a, Node, dlNode);
   Node *be = container_of(b, Node, dlNode);
   return be->data < ae->data;
}

int main() {
   

   return 0;
}
