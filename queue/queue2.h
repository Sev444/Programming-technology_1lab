#pragma once
#include "queue.h"
class queue2 : protected queue {
 public:
  int perform_variant();
  void enqueue(int data);
  void dequeue();
  void display();
  queue2* copy();
  static queue2* merge(queue2* lhs, queue2* rhs);
};
