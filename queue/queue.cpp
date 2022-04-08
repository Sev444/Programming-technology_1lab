#include "queue.h"

queue::queue() {}

// Конструктор. Инициализация очереди вектором элементов.
queue::queue(std::vector<int> initialize_list) {
  for (const auto& item : initialize_list) {
    this->enqueue(item);
  }
}

// Деструктор. Очистка памяти после удаления очереди.
queue::~queue() {
  while (front != nullptr) {
    auto next = front->next;
    delete front;
    front = next;
  }
  front = rear = nullptr;
}

// Добавление элемента в очередь
void queue::enqueue(const int value) {
  auto element = new node(value); // Создаем новый узел
  if (rear == nullptr) { // Если очередь пуста(последний элемент = nullptr)
    // Первый и последний элементы равны друг другу
    rear = element;
    rear->next = nullptr;
    front = rear;
  } else {
    // Если в очереди есть элементы, то меняем указатель на последний элемент.
    // Перед этим устанавливаем указатель next на тот же элемент, чтобы не потерять связь
    rear->next = element;
    rear = element;
  }
  q_size++;
}

// Удаление элементов из очереди
void queue::dequeue() {
  if (is_empty()) { // Если очередь пуста, выходим. Удалять нечего.
    return;
  }
  if (front->next != nullptr) { // Если в очереди не один элемент
    // Сохраняем ссылку на второй элемент
    auto next = front->next;
    // Удаляем первый элемент из очереди
    delete front;
    // Устанавливаем второй элемент в качестве первого
    front = next;
  } else { // если в очереди всего один элемент, то после удаление front и rear равны nullptr
    delete front;
    front = rear = nullptr;
  }
  q_size--;
}

size_t queue::size() const { return q_size; }

bool queue::is_empty() const { return front == nullptr; }

int queue::get_front() const { return front->data; } // получаем значение первого элемента очереди

// Отображение очереди на экран
void queue::display() const {
  auto it = front; // Обьявляем указатель на первый элемент
  while (it != nullptr) { // Пока не дошли до конца очереди(пока указатель указывает на что-то)
    std::cout << it->data << " "; // Выводим на экран
    it = it->next; // Переходим к следующему элементу
  }
  std::cout << std::endl;
}

// Ф-ция копирования очереди
queue* queue::copy() const {
  auto it = front;
  queue* result = new queue();
  while (it != nullptr) {
    result->enqueue(it->data);
    it = it->next;
  }
  return result;
}

// функция слияния двух очередей
queue* queue::merge(queue* lhs, queue* rhs) {
  queue* result = new queue();
  auto lhs_iterator = lhs->get_front_node();
  auto rhs_iterator = rhs->get_front_node();
  while (lhs_iterator != nullptr || rhs_iterator != nullptr) { // Выполняем итерации пока хотя бы в одной очереди есть элементы
    if (lhs_iterator != nullptr) { // если левая очередь не пуста, то добавляем в результирующую очередь элемент
      result->enqueue(lhs_iterator->data);
      lhs_iterator = lhs_iterator->next;
    }
    if (rhs_iterator != nullptr) { // если правая очередь не пуста, то добавляем в результирующую очередь элемент
      result->enqueue(rhs_iterator->data);
      rhs_iterator = rhs_iterator->next;
    }
  }
  return result;
}

// Выполнение задания по варианту
int queue::perform_variant() {
  if (is_empty()) {
    return 0;
  }
  int min;
  int max;
  auto it = get_front_node(); // получаем узел для последующей итерации по очереди
  min = max = it->data;
  while (it->next != nullptr) { // Итерируемся по элементам очереди
    int num = it->next->data;
    min = std::min(min, num); // выбираем минимум
    max = std::max(max, num); // выбираем максимум
    it = it->next;
  }
  return max - min; // возвращаем размах
}

node* queue::get_front_node() { return front; }
