#include "p2w.h"

#include "tests/base/utils.h"

int main() {
  p2wheap_t h = p2w_create();
  p2w_push_with_index(h, 0, gtype_l(0), gtype_cmp_l);
  p2w_push_with_index(h, 1, gtype_l(100), gtype_cmp_l);
  p2w_push_with_index(h, 2, gtype_l(200), gtype_cmp_l);
  p2w_push_with_index(h, 3, gtype_l(300), gtype_cmp_l);
  p2w_push_with_index(h, 5, gtype_l(500), gtype_cmp_l);

  CHECK_MSG(p2w_check(h, gtype_cmp_l) == true, "Check max heap");

  CHECK_MSG(p2w_max(h).l == 500, "Max 500");
  CHECK_MSG(p2w_get(h, 2).l == 200, "Value at 2");
  CHECK_MSG(p2w_get(h, 1).l == 100, "Value at 1");

  p2w_modify(h, 1, gtype_l(10000), gtype_cmp_l);
  CHECK_MSG(p2w_max(h).l == 10000, "Max 10000");
  CHECK_MSG(p2w_max_index(h) == 1, "Max 10000 index 1");

  CHECK_MSG(p2w_delete_max(h, gtype_cmp_l).l == 10000, "Delete max 10000");
  CHECK_MSG(p2w_delete_max(h, gtype_cmp_l).l == 500, "Delete max 500");
  CHECK_MSG(p2w_delete_max(h, gtype_cmp_l).l == 300, "Delete max 300");
  CHECK_MSG(p2w_delete_max(h, gtype_cmp_l).l == 200, "Delete max 200");
  CHECK_MSG(p2w_delete_max(h, gtype_cmp_l).l == 0, "Delete max 0");
  p2w_free(&h);
  return 0;
}