#pragma once
#include "queue.h"
class queue3 : private queue {
 public:
  int perform_variant();
  void enqueue(int data);
  void dequeue();
  void display();
  queue3* copy();
  static queue3* merge(queue3* lhs, queue3* rhs);
};
