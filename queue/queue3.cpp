#include "queue3.h"

int queue3::perform_variant() {
  return queue::perform_variant(); }

void queue3::enqueue(int data) { return queue::enqueue(data); }

void queue3::dequeue() { queue::dequeue(); }

void queue3::display() { queue::display(); }

queue3* queue3::copy() {
  auto q = queue::copy();
  queue3* result = new queue3();
  while (!q->is_empty()) {
    result->enqueue(q->get_front());
    q->dequeue();
  }
  delete q;
  return result;
}

queue3* queue3::merge(queue3* lhs, queue3* rhs) {
  auto merged = queue::merge(lhs, rhs);
  queue3* result = new queue3();
  while (!merged->is_empty()) {
    result->enqueue(merged->get_front());
    merged->dequeue();
  }
  delete merged;
  return result;
}
