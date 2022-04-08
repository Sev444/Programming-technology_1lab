#include "queue2.h"

int queue2::perform_variant() {
  return queue::perform_variant(); }

void queue2::enqueue(int data) { return queue::enqueue(data); }

void queue2::dequeue() { queue::dequeue(); }

void queue2::display() { queue::display(); }

queue2* queue2::copy() {
  auto q = queue::copy();
  queue2* result = new queue2();
  while (!q->is_empty()) {
    result->enqueue(q->get_front());
    q->dequeue();
  }
  delete q;
  return result;
}

queue2* queue2::merge(queue2* lhs, queue2* rhs) {
  auto merged = queue::merge(lhs, rhs);
  queue2* result = new queue2();
  while (!merged->is_empty()) {
    result->enqueue(merged->get_front());
    merged->dequeue();
  }
  delete merged;
  return result;
}
