#include "queue1.h"

queue1* queue1::copy() {
  auto q = queue::copy();
  queue1* result = new queue1();
  while (!q->is_empty()) {
    result->enqueue(q->get_front());
    q->dequeue();
  }
  delete q;
  return result;
}

queue1* queue1::merge(queue* lhs, queue* rhs) {
  auto merged = queue::merge(lhs, rhs);
  queue1* result = new queue1();
  while (!merged->is_empty()) {
    result->enqueue(merged->get_front());
    merged->dequeue();
  }
  delete merged;
  return result;
}
