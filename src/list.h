#ifndef LIST_H_
#define LIST_H_

typedef struct Node_ {
  void *data_;
  struct Node_ *next_;
} Node;

typedef struct {
  Node *node_;
} ListIterator;

typedef struct {
  Node *head_;
  Node *tail_;
  int size_;
  void(*destroy_cb_)(void *data);
} List ;

void list_init(List *list, void(*destroy_cb)(void *data));
void list_destroy(List *list);
void list_add_head(List *list, void *data);
void list_add_tail(List *list, void *data);
void *list_head(List *list);
void *list_tail(List *list);
void *list_remove_head(List *list);
void *list_remove_tail(List *list);
ListIterator list_iterator(List *list);
void *list_next(ListIterator *it);
int list_size(List *list);


#endif /* end of include guard: LIST_H_ */
