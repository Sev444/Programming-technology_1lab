#pragma once
#include "queue.h"
class queue1 : public queue {
 public:
  queue1* copy();
  static queue1* merge(queue* lhs, queue* rhs);
};
