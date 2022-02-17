#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
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

void testDlAppend() {

}

void testDlPrePend() {
   Node *tmp = NULL;
   dlNode_t *root = NULL;

   Node *an = (Node *)malloc(sizeof(Node));   
   memset(an, 0, sizeof(Node));
   an->data = 10;
   
   Node *bn = (Node *)malloc(sizeof(Node));
   memset(bn, 0, sizeof(Node));
   bn->data = 20;

   Node *cn = (Node *)malloc(sizeof(Node));
   memset(cn, 0, sizeof(Node));
   cn->data = 5;
 
   DlPrePend(&root, &(an->dlNode));
   tmp = container_of(root, Node, dlNode);
   assert(tmp->data == an->data);

   DlPrePend(&root, &(cn->dlNode));
   tmp = container_of(root, Node, dlNode);
   assert(tmp->data == cn->data);
  
   DlPrePend(&root, &(bn->dlNode));
   tmp = container_of(root, Node, dlNode);
   assert(tmp->data == bn->data);

   dlNode_t *elt = NULL; 
   DL_FOREACH(root, elt) {
      Node *tn = container_of(elt, Node, dlNode);
      printf(" %d ", tn->data);
   }
   printf("\n");

   free(an);
   free(bn);
   free(cn);
}

void testDlInsertInorder() {
   dlNode_t *root = NULL;

   Node *an = (Node *)malloc(sizeof(Node));   
   memset(an, 0, sizeof(Node));
   an->data = 10;
   
   Node *bn = (Node *)malloc(sizeof(Node));
   memset(bn, 0, sizeof(Node));
   bn->data = 20;

   Node *cn = (Node *)malloc(sizeof(Node));
   memset(cn, 0, sizeof(Node));
   cn->data = 5;

   DlInsertInorder(&root, &bn->dlNode, cmpDl); 
   DlInsertInorder(&root, &an->dlNode, cmpDl); 
   DlInsertInorder(&root, &cn->dlNode, cmpDl); 

   dlNode_t *elt = NULL; 

   DL_FOREACH(root, elt) {
      Node *tn = container_of(elt, Node, dlNode);
      printf(" %d ", tn->data);
   }
   printf("\n");

   DlUnLink(&root, &bn->dlNode);

   DL_FOREACH(root, elt) {
      Node *tn = container_of(elt, Node, dlNode);
      printf(" %d ", tn->data);
   }
   printf("\n");

   DlInsertInorder(&root, &bn->dlNode, cmpDl); 
   DlUnLink(&root, &cn->dlNode);

   DL_FOREACH(root, elt) {
      Node *tn = container_of(elt, Node, dlNode);
      printf(" %d ", tn->data);
   }
   printf("\n");

   DlInsertInorder(&root, &cn->dlNode, cmpDl); 
   DlUnLink(&root, &an->dlNode);

   DL_FOREACH(root, elt) {
      Node *tn = container_of(elt, Node, dlNode);
      printf(" %d ", tn->data);
   }
   printf("\n");

   free(an);
   free(bn);
   free(cn);
}

int main() {

   testDlPrePend();
   
   testDlInsertInorder();

   return 0;
}





