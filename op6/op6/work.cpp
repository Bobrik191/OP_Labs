#include<iostream>
#include<string>

template<typename T>
struct Node {
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;
    T data;
    Node(T data) : data(data) {}
};

template<typename T>
class Iterator {
public:
    Iterator(Node<T>* head) : head(head) {}

    Iterator<T> next() const {
        Iterator<T> temp = *this;
        if (temp.head != nullptr) {
            ++temp;
        }
        return temp;
    }

    Iterator<T> prev() const {
        Iterator<T> temp = *this;
        if (temp.head != nullptr && temp.head->prev != nullptr) {
            --temp;
        }
        return temp;
    }


    Iterator<T> operator++(int var) {
        if (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;

            return temp;
        }

        return nullptr;
    }

    Iterator<T> operator++() {
        if (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            return temp;
        }

        return nullptr;
    }

    Iterator<T> operator--() {
        if (head->prev != nullptr) {
            head = head->prev;

            return head;
        }
    }

    T operator*() {
        return head->data;
    }

    bool operator!=(const Iterator<T>& it) {
        return head != it.head;
    }

private:
    Node<T>* head;
};

template<typename T>
class Deque {
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
public:

    void push_front(T data) {
        if (head == nullptr) {
            head = new Node<T>(data);
            tail = head;
            return;
        }

        Node<T>* newNode = new Node<T>(data);
        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
        current->next->prev = current;
        tail = current->next;
    }

    void push_back(T data) {
        if (head == nullptr) {
            head = new Node<T>(data);
            tail = head;
            return;
        }

        Node<T>* newNode = new Node<T>(data);
        Node<T>* temp = head;
        head = newNode;
        head->next = temp;
        temp->prev = head;
    }

    void pop_back() {
        if (head == nullptr || head == tail) return;
        Node<T>* temp = head;
        head = temp->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
    }

    void pop_front() {
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node<T>* temp = tail;
            tail = temp->prev;
            tail->next = nullptr;
            delete temp;
        }
    }

    void clear() {
        Node<T>* current = head;
        Node<T>* temp = nullptr;
        while (current != nullptr) {
            temp = current;
            current = current->next;
            delete temp;
        }

        head = nullptr;
        tail = nullptr;
    }

    void print() const {
        Iterator<T> it = begin();
        while (it != end()) {
            std::cout << *it << " ";
            ++it;
        }

        std::cout << std::endl;
    }

    void printElement(int index) {
        if (index < 0) {
            std::cout << "Invalid index." << std::endl;
            return;
        }

        Iterator<T> first = begin();
        Iterator<T> last = end();

        int count = 0;
        for (Iterator<T> it = first; it != last; ++it) {
            if (count == index) {
                std::cout << "Current Element: " << *it << std::endl;

                if (it != first) {
                    std::cout << "Previous Element: " << *(it.prev()) << std::endl;
                }
                else {
                    std::cout << "Previous Element not exist" << std::endl;
                }

                Iterator<T> next = it.next();
                if (next != last) {
                    std::cout << "Next Element: " << *next << std::endl;
                }
                else {
                    std::cout << "Next Element not exist" << std::endl;
                }

                std::cout << "First Element: " << *begin() << std::endl;
                std::cout << "Last Element: " << *rbegin() << std::endl;

                return;
            }
            count++;
        }
    }

    //void print() const {
    //    Node<T>* current = head;
    //    while (current != nullptr) {
    //        std::cout << current->data << " ";
    //        current = current->next;
    //    }

    //    std::cout << std::endl;
    //}

    bool empty() const {
        return head == nullptr;
    }

    Iterator<T> begin() const {
        return Iterator<T>(head);
    }

    Iterator<T> end() const {
        return Iterator<T>(nullptr);
    }

    Iterator<T> rbegin() const {
        return Iterator<T>(tail);
    }

    ~Deque() {
        Node<T>* current = head;
        Node<T>* temp = nullptr;
        while (current != nullptr) {
            temp = current;
            current = current->next;
            delete temp;
        }

        head = nullptr;
        tail = nullptr;
    }
};

void test_cases(const std::string& type) {
    if (type == "int") {
        Deque<int> deque;
        int size;
        std::cout << "Enter size (up to 20): ";
        std::cin >> size;
        std::cout << "Enter " << size << " integer values: ";
        for (int i = 0; i < size; i++) {
            int value;
            std::cin >> value;
            deque.push_back(value);
        }

        std::cout << "Deque: ";
        deque.print();
        deque.pop_back();
        std::cout << "Deque after pop back: ";
        deque.print();
        deque.pop_front();
        std::cout << "Deque after pop front: ";
        deque.print();

        //std::cout << "Deque after popping: ";
        //deque.print();

        std::cout << "Enter an integer value to push back: ";
        int value;
        std::cin >> value;
        deque.push_back(value);
        std::cout << "Deque after pushing back: ";
        deque.print();
        std::cout << "Enter an integer value to push front: ";
        int value1;
        std::cin >> value1;
        deque.push_front(value1);
        std::cout << "Deque after pushing front: ";
        deque.print();

        int index;
        std::cout << "Enter an index: ";
        std::cin >> index;
        deque.printElement(index);

        //int indexprev;
        //std::cout << "Enter index for iterator: ";
        //std::cin >> indexprev;
        //deque.prevIt(indexprev);

        std::cout << "Clear called" << std::endl;
        deque.clear();
        std::cout << "Is deque empty? " << deque.empty() << std::endl;
    }
    else if (type == "double") {
        Deque<double> deque;
        int size;
        std::cout << "Enter size (up to 20): ";
        std::cin >> size;
        std::cout << "Enter " << size << " double values: ";
        for (int i = 0; i < size; i++) {
            double value;
            std::cin >> value;
            deque.push_back(value);
        }

        std::cout << "Deque: ";
        deque.print();
        deque.pop_back();
        std::cout << "Deque after pop back: ";
        deque.print();
        deque.pop_front();
        std::cout << "Deque after pop front: ";
        deque.print();

        //std::cout << "Deque after popping: ";
        //deque.print();

        std::cout << "Enter an double value to push back: ";
        double value;
        std::cin >> value;
        deque.push_back(value);
        std::cout << "Deque after pushing back: ";
        deque.print();
        std::cout << "Enter an double value to push front: ";
        double value1;
        std::cin >> value1;
        deque.push_front(value1);
        std::cout << "Deque after pushing front: ";
        deque.print();

        int index;
        std::cout << "Enter an index: ";
        std::cin >> index;
        deque.printElement(index);

        std::cout << "Clear called" << std::endl;
        deque.clear();
        std::cout << "Is deque empty? " << deque.empty() << std::endl;
    }
    else if (type == "string") {
        Deque<std::string> deque;
        int size;
        std::cout << "Enter size (up to 20): ";
        std::cin >> size;
        std::cout << "Enter " << size << " string values: ";
        for (int i = 0; i < size; i++) {
            std::string value;
            std::cin >> value;
            deque.push_back(value);
        }
        //std::cout << "Enter 3 string values: ";
        //for (size_t i = 0; i < 3; i++) {
        //    std::string value;
        //    std::cin >> value;
        //    deque.push_back(value);
        //}

        std::cout << "Deque: ";
        deque.print();
        deque.pop_back();
        std::cout << "Deque after pop back: ";
        deque.print();
        deque.pop_front();
        std::cout << "Deque after pop front: ";
        deque.print();

        //std::cout << "Deque after popping: ";
        //deque.print();

        std::cout << "Enter an string value to push back: ";
        std::string value;
        std::cin >> value;
        deque.push_back(value);
        std::cout << "Deque after pushing back: ";
        deque.print();
        std::cout << "Enter an string value to push front: ";
        std::string value1;
        std::cin >> value1;
        deque.push_front(value1);
        std::cout << "Deque after pushing front: ";
        deque.print();

        int index;
        std::cout << "Enter an index: ";
        std::cin >> index;
        deque.printElement(index);

        //std::cout << "Deque: ";
        //deque.print();
        //deque.pop_back();
        //std::cout << "Deque after popping back: ";
        //deque.print();
        //std::cout << "Enter a string value to push back: ";
        //std::string value;
        //std::cin >> value;
        //deque.push_back(value);
        //std::cout << "Deque after pushing back: ";
        //deque.print();

        std::cout << "Clear called" << std::endl;
        deque.clear();
        std::cout << "Is deque empty? " << deque.empty() << std::endl;
    }
}

