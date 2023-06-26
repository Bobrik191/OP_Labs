#pragma once
#include <string>

template<typename T>
struct Node;

template<typename T>
class Iterator;

template<typename T>
class Deque {
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
public:
    void push_front(T data);
    void push_back(T data);
    void pop_back();
    void pop_front();
    void clear();
    void print() const;
    bool empty() const;
    void printElement(int);
    Iterator<T> rbegin();
    Iterator<T> begin();
    Iterator<T> end();
    ~Deque();
};

void test_cases(const std::string& type);


