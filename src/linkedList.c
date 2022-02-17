#include "linkedList.h"
#include <stddef.h>
#include <assert.h>

void DlPrePend(dlNode_t **p2head, dlNode_t *add) {
   assert(p2head);

   add->next = *p2head; 
   *p2head = add;
}

void DlAppend(dlNode_t **p2head, dlNode_t *add) {
   assert(p2head); 

   if(!(*p2head)) {
      *p2head = add;
      return;
   } 

   dlNode_t *nown = *p2head;
   while(nown->next) {
      nown = nown->next;
   }
   nown->next = add; 
}

void DlInsertInorder(dlNode_t **p2head,
                     dlNode_t *add,
                     int (*cmp)(dlNode_t *a, dlNode_t *b)) {

   if(NULL == *p2head) {
      *p2head = add;
   } else {
      dlNode_t *last = NULL;
      dlNode_t *now = *p2head;

      while(NULL != now) {
         if(cmp(now, add)) {
            break;
         }
         last = now;
         now = now->next;
      }

      if(NULL == last) {
         add->next = now;
         now->prev = add;
         *p2head = add;
      } else if(NULL == now) {
         last->next = add;
         add->prev = last;
      } else {
         last->next = add;
         now->prev = add;
  
         add->prev = last;
         add->next = now;
      }
   }
}

void DlUnLink(dlNode_t **p2head, dlNode_t *del) {
   if(NULL == *p2head) {
      return;
   } else if(*p2head == del) {
      *p2head = del->next;
      if(*p2head) {
         (*p2head)->prev = NULL;
      }
   } else {
      del->prev->next = del->next;
      if(del->next) {
         del->next->prev = del->prev;
      }
   }
}



