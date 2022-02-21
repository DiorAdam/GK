#include "list.h"
#include <stdio.h>

int sq( int x ) {
  return x * x;
}

int plus( int x, int y ) {
  return x + y;
}

int main(void) {
  int N = 5;
  List list = empty_list();

  for( int i = 0; i < N; ++i ) {
    list_append( &list, i );
  }

  list_print( list ); // {0, 1, 2, 3, 4}
  list_delete(&list, 3);
  list_delete(&list, 0);
  list_delete(&list, 9);
  list_print(list); //{1, 2, 4}
  list_insert_before(&list, 9, 4);
  list_print(list); // {1, 2, 9, 4}
  list_delete(&list, 4); 
  list_print(list); // {1, 2, 9}
  list_apply(&list, sq);
  printf("%d\n", list_reduce(&list, plus)); // 86
  list_clear( &list );
  return 0;
}
