#include <iostream>
using namespace std;

template<typename T>
struct Node {
    T data;
    Node* next;

    Node(const T& newData) : data(newData), next(nullptr) {}
};


template <typename T>
class ForwardList {
private:
    Node<T>* head;

public:
    ForwardList() : head(nullptr) {}

    T front() {
        if (empty()) {
            throw out_of_range("Lista vacia");
        }
        return head->data;
    }

    T back() {
        if (empty()) {
            throw out_of_range("List vacia");
        }
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp->data;
    }
    void push_front(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    void push_back(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (empty()) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    T pop_front() {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }
        Node<T>* temp = head;
        T value = temp->data;
        head = head->next;
        delete temp;
        return value;
    }
    T pop_back() {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }
        if (head->next == nullptr) {
            return pop_front();
        }
        Node<T>* current = head;
        Node<T>* prev = nullptr;
        while (current->next != nullptr) {
            prev = current;
            current = current->next;
        }
        T value = current->data;
        prev->next = nullptr;
        delete current;
        return value;
    }
    T operator[](int index) {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }
        Node<T>* current = head;
        for (int i = 0; i < index; ++i) {
            if (current == nullptr) {
                throw std::out_of_range("Index out of range");
            }
            current = current->next;
        }
        if (current == nullptr) {
            throw std::out_of_range("Index out of range");
        }
        return current->data;
    }
    bool empty() {
        return head == nullptr;
    }
    void clear() {
        while (!empty()) {
            pop_front();
        }
    }
    void sort() { //se uso bubblesort
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        bool swapped;
        Node<T>* current;
        T temp;

        do {
            swapped = false;
            current = head;

            while (current->next != nullptr) {
                if (current->data > current->next->data) {
                    temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);
    }

void reverse() {
        Node<T>* prev = nullptr;
        Node<T>* current = head;
        Node<T>* next = nullptr;
            while (current != nullptr) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }

            head = prev;
        }

        // Destructor para liberar la memoria utilizada por los nodos
        ~ForwardList() {
            clear();
        }
        void print_list(){
        Node<T>* temp = head;
            while (temp != nullptr){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
    }
};


int main() {
    ForwardList<int> forward_list;
    forward_list.push_back(1);
    forward_list.push_back(2);
    forward_list.push_back(3);
    forward_list.push_back(4);
    forward_list.push_back(5);

    cout<< "Lista despues de push_back: "<<endl;
    forward_list.print_list();

    cout<<endl;

    forward_list.push_front(0);
    forward_list.push_front(6);

    cout<< "Lista despues de push_front: "<<endl;
    forward_list.print_list();

    cout<<endl;

    cout << "Front: " << forward_list.front() << endl;
    cout << "Back: " << forward_list.back() << endl;

    cout<<endl;

    forward_list.pop_back();
    cout<< "Lista despues de pop_back: "<<endl;
    forward_list.print_list();

    cout<<endl;

    forward_list.pop_front();
    cout<< "Lista despues de pop_front: "<<endl;
    forward_list.print_list();

    cout<<endl;

    cout << "Front: " << forward_list.front() << std::endl;
    cout << "Back: " << forward_list.back() << std::endl;

    cout<<endl;

    forward_list.reverse();
    cout << "Lista despues de reverse: "<<endl;
    forward_list.print_list();

    cout<<endl;

    forward_list.sort();
    cout << "Lista despues de sort: "<<endl;
    forward_list.print_list();

    cout<<endl;

    forward_list.clear();
    cout << "lista despues de clear: "<<endl;
    forward_list.print_list();

    cout<<endl;

    return 0;
}
