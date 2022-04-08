#include <iostream>
#include<string>
#include "queue1.h"
#include "queue2.h"
#include "queue3.h"

// Enum ��� ������������ ����� ������������ ����� queue1, queue2, queue3
enum class QueueMode {
  PublicInheritance, // mode - 0
  ProtectedInheritance, // mode - 1
  PrivateInheritance // mode - 2
};

// ���������� ���������� ����������
bool isRun = true;
QueueMode q_mode = QueueMode::PublicInheritance;
queue1* q1 = new queue1();
queue2* q2 = new queue2();
queue3* q3 = new queue3();

// ������� ������ ����������� ���������� ���� ������������
void display_menu() {
  std::cout << "����� ���������� � ������ ���������, ������������!" << std::endl;
  std::cout << "----���� ��������----" << std::endl;
  std::cout << "1 - ���������� �������� � ������� (� ������� 1 <number>)" << std::endl;
  std::cout << "2 - ���������� �������� �� �������" << std::endl;
  std::cout << "3 - ����� ������� �� �����" << std::endl;
  std::cout << "4 - ���������� ������� �� ��������" << std::endl;
  std::cout << "5 - �������� ����� �������" << std::endl;
  std::cout << "6 - ������� ���� ��������" << std::endl;
  std::cout << "7 - ����� �� ���������." << std::endl;
  std::cout << "8 - ������� �������� ������� (� ������� 8 <mode>)" << std::endl;
  std::cout << "������ ������ �������: " << static_cast<int>(q_mode) << std::endl;
  std::cout << "������� �������: ";
}

// ������� ��������� ����� ������������
void process_input() {
  int operation;
  std::cin >> operation; // ��������� ������� ������������
  if (operation == 1)
  {
    int data;
    std::cin >> data; // ��������� ����� ����������� �������
    switch (q_mode) { // � ����������� �� q_mode ��������� ������� � ������������� ���� �������
      case QueueMode::PublicInheritance:
        q1->enqueue(data);
        break;
      case QueueMode::ProtectedInheritance:
        q2->enqueue(data);
        break;
      case QueueMode::PrivateInheritance:
        q3->enqueue(data);
        break;
      default:
        break;
    }
  }
  else if (operation == 2)
  {
    switch (q_mode) {
      case QueueMode::PublicInheritance:
        q1->dequeue();
        break;
      case QueueMode::ProtectedInheritance:
        q2->dequeue();
        break;
      case QueueMode::PrivateInheritance:
        q3->dequeue();
        break;
      default:
        break;
    }
  }
  else if (operation == 3)
  {
    switch (q_mode) {
      case QueueMode::PublicInheritance:
        q1->display();
        break;
      case QueueMode::ProtectedInheritance:
        q2->display();
        break;
      case QueueMode::PrivateInheritance:
        q3->display();
        break;
      default:
        break;
    }
  }
  else if (operation == 4) {
      switch (q_mode) {
        case QueueMode::PublicInheritance:
          std::cout << q1->perform_variant() << std::endl;
          break;
        case QueueMode::ProtectedInheritance:
          std::cout << q2->perform_variant() << std::endl;
          break;
        case QueueMode::PrivateInheritance:
          std::cout << q3->perform_variant() << std::endl;
          break;
        default:
          break;
      }
  } else if (operation == 5)
  {
    switch (q_mode) {
      case QueueMode::PublicInheritance: {
        auto q_copy = q1->copy();
        std::cout << "������������ �������: ";
        q1->display();
        std::cout << "�����: ";
        q_copy->display();
        delete q_copy;
        break;
      }
      case QueueMode::ProtectedInheritance: {
        auto q_copy = q2->copy();
        std::cout << "������������ �������: ";
        q2->display();
        std::cout << "�����: ";
        q_copy->display();
        delete q_copy;
        break;
      }
      case QueueMode::PrivateInheritance: {
        auto q_copy = q3->copy();
        std::cout << "������������ �������: ";
        q3->display();
        std::cout << "�����: ";
        q_copy->display();
        delete q_copy;
        break;
      }
      default:
        break;
    }
  }
  else if (operation == 6)
  {
    switch (q_mode) {
      case QueueMode::PublicInheritance: {
        queue1* tmp = new queue1();
        tmp->enqueue(5);
        tmp->enqueue(7);
        tmp->enqueue(9);
        tmp->enqueue(41);
        tmp->enqueue(452);
        auto merged = queue1::merge(tmp, q1);
        std::cout << "������� �����: ";
        tmp->display();
        std::cout << "�: ";
        q1->display();
        std::cout << "=" << std::endl;
        merged->display();
        delete tmp;
        delete merged;
        break;
      }
      case QueueMode::ProtectedInheritance: {
        queue2* tmp = new queue2();
        tmp->enqueue(1);
        tmp->enqueue(2);
        tmp->enqueue(3);
        tmp->enqueue(4);
        tmp->enqueue(452);
        auto merged = queue2::merge(tmp, q2);
        std::cout << "������� �����: ";
        tmp->display();
        std::cout << "�: ";
        q2->display();
        std::cout << "=" << std::endl;
        merged->display();
        delete tmp;
        delete merged;
        break;
      }
      case QueueMode::PrivateInheritance: {
        queue3* tmp = new queue3();
        tmp->enqueue(1);
        tmp->enqueue(2);
        tmp->enqueue(3);
        tmp->enqueue(4);
        tmp->enqueue(452);
        auto merged = queue3::merge(tmp, q3);
        std::cout << "������� �����: ";
        tmp->display();
        std::cout << "�: ";
        q3->display();
        std::cout << "=" << std::endl;
        merged->display();
        delete tmp;
        delete merged;
        break;
      }
      default:
        break;
    }
  }
  else if (operation == 7)
  {
    isRun = false;
  }
  else if (operation == 8)
  {
    int mode;
    std::cin >> mode;
    switch (mode) {
      case 0:
        q_mode = QueueMode::PublicInheritance;
        break;
      case 1:
        q_mode = QueueMode::ProtectedInheritance;
        break;
      case 2:
        q_mode = QueueMode::PrivateInheritance;
        break;
      default:
        std::cout << "������������ ����: " << mode << std::endl;
        break;
    }
  } else {
    std::cout << "����������� �������: " << operation << std::endl;
  }
}

int main() {
  setlocale(0, ""); // ������������� ������� ���� � �������
  // �������� ��������� ���� ����������
  while (isRun) {
    display_menu(); // ����������� ����
    process_input(); // ��������� ����������������� �����
  }
  std::cout << "����� ��������. �� ��������!" << std::endl;
  delete q1;
  delete q2;
  delete q3;
  return 0;
}
