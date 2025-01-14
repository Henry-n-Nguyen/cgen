#include "p1w.h"

#include "tests/base/utils.h"

int t1() {
  p1w_t q = p1w_create(PRIORITY_MAX, gtype_cmp_l);
  p1w_enqueue(q, gtype_l(10));
  p1w_enqueue(q, gtype_l(30));
  p1w_enqueue(q, gtype_l(20));
  p1w_enqueue(q, gtype_l(50));
  p1w_enqueue(q, gtype_l(60));
  CHECK_ECHO(p1w_dequeue(q).l == 60);
  CHECK_ECHO(p1w_dequeue(q).l == 50);
  CHECK_ECHO(p1w_dequeue(q).l == 30);
  CHECK_ECHO(p1w_peek(q).l == 20);
  CHECK_ECHO(p1w_dequeue(q).l == 20);
  CHECK_ECHO(p1w_dequeue(q).l == 10);
  CHECK_ECHO(p1w_is_empty(q));
  p1w_free(q);
}

int t2() {
  p1w_t q = p1w_create(PRIORITY_MIN, gtype_cmp_l);
  p1w_enqueue(q, gtype_l(10));
  p1w_enqueue(q, gtype_l(30));
  p1w_enqueue(q, gtype_l(20));
  p1w_enqueue(q, gtype_l(60));
  p1w_enqueue(q, gtype_l(50));
  CHECK_ECHO(p1w_dequeue(q).l == 10);
  CHECK_ECHO(p1w_dequeue(q).l == 20);
  CHECK_ECHO(p1w_peek(q).l == 30);
  CHECK_ECHO(p1w_dequeue(q).l == 30);
  CHECK_ECHO(p1w_dequeue(q).l == 50);
  CHECK_ECHO(p1w_dequeue(q).l == 60);
  CHECK_ECHO(p1w_is_empty(q));
  p1w_free(q);
}

int main() {
  CHECK_ECHO(t1() == 0);
  CHECK_ECHO(t2() == 0);
  TEST_OK();
}