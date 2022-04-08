#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

struct node {
  int data;
  node* next;
  node(int value) : data(value), next(nullptr) {}
};

class queue {
 private:
  node* front = nullptr;
  node* rear = nullptr;
  size_t q_size = 0;

 public:
  queue();
  queue(const queue& other);
  queue(std::vector<int>);
  ~queue();
  void enqueue(const int);
  void dequeue();
  size_t size() const;
  bool is_empty() const;
  int get_front() const;
  void display() const;
  int perform_variant();
  static queue* merge(queue*, queue*);

 protected:
  node* get_front_node();
  queue* copy() const;
};
