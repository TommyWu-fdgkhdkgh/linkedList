/* singly-linked list */

/* doubly-linked list */
typedef struct dlNode_s dlNode_t;
struct dlNode_s {
  dlNode_t *prev, *next; 
};

void DlPrePend();
void DlAppend();

void DlPrePendElem();
void DlAppenElem();
void DlReplaceElem();

void DlInsertInorder(dlNode_t **p2head,
                     dlNode_t *add,
                     int (*cmp)(dlNode_t *a, dlNode_t *b));
void DlConcat();
void DlUnLink(dlNode_t **p2head, dlNode_t *del);
void DlSort();

void DlSearch();
void DlSearchScalar();

void DlLowerBound();
void DlCount();

#define DL_FOREACH(head, elt) \
	for((elt) = (head);(elt) != NULL;(elt) = (elt)->next) 

/* circular doubly-linked list */














