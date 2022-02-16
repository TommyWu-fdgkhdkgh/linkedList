/* singly-linked list */

/* doubly-linked list */
typedef struct dlNode_s dlNode_t;
struct dlNode_s {
  dlNode_t *prev, *next; 
};

void DlPrePend(dlNode_t **p2head, dlNode_t *add);
void DlAppend(dlNode_t **p2head, dlNode_t *add);

void DlPrePendElem(dlNode_t **p2head, dlNode_t *add, dlNode_t *elem);
void DlAppenElem(dlNode_t **p2head, dlNode_t *add, dlNode_t *elem);
void DlReplaceElem(dlNode_t **p2head, dlNode_t *rep, dlNode_t *elem);

void DlInsertInorder(dlNode_t **p2head,
                     dlNode_t *add,
                     int (*cmp)(dlNode_t *a, dlNode_t *b));
void DlConcat(dlNode_t **p2head1, dlNode_t **p2head2);
void DlUnLink(dlNode_t **p2head, dlNode_t *del);
void DlSort(dlNode_t **p2head,
            int (*cmp)(dlNode_t *a, dlNode_t *b));

void DlSearch(dlNode_t *head);
void DlSearchScalar();

void DlLowerBound();
unsigned long long DlCount(dlNode_t *head);

#define DL_FOREACH(head, elt) \
	for((elt) = (head);(elt) != NULL;(elt) = (elt)->next) 

/* circular doubly-linked list */














