//Operaciones double linked list
#include <iostream>
using namespace std;
template<typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;

    Node(const T& data_) : data(data_), prev(nullptr), next(nullptr) {}
};

template<typename T>
class DoubleLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    T front() {
        if (empty()) {
            cout << "Lista vacia"<<endl;
        }
        return head->data;
    }

    T back() {
        if (empty()) {
            cout << "Lista vacia"<<endl;
        }
        return tail->data;
    }

    void push_front(T value) {
        Node<T>* nuevo = new Node<T>(value);
        if (empty()) {
            head = tail = nuevo;
        } else {
            nuevo->next = head;
            head->prev = nuevo;
            head = nuevo;
        }
    }

    void push_back(T value) {
        Node<T>* nuevo = new Node<T>(value);
        if (empty()) {
            head = tail = nuevo;
        } else {
            tail->next = nuevo;
            nuevo->prev = tail;
            tail = nuevo;
        }
    }

    T pop_front() {
        if (empty()) {
            cout<<"Lista vacia"<<endl;
        }
        T value = head->data;
        Node<T>* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        return value;
    }

    T pop_back() {
        if (empty()) {
            cout<<"Lista vacia"<<endl;
        }
        T value = tail->data;
        Node<T>* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        return value;
    }

    int size() {
        int contador = 0;
        Node<T>* temp = head;
        while (temp != nullptr) {
            ++contador;
            temp = temp->next;
        }
        return contador;
    }

    void insert(T valor, int pos) {
        if (pos < 0 || pos > size()) {
            cout<<"posicion fuera de rango";
        }
        if (pos == 0) {
            push_front(valor);
        } else if (pos == size()) {
            push_back(valor);
        } else {
            Node<T>* newNode = new Node<T>(valor);
            Node<T>* current = head;
            for (int i = 0; i < pos - 1; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
        }
    }

    void remove(int pos) {
        if (pos < 0 || pos >= size()) {
            cout<<"posicion fuera de rango";
        }
        if (pos == 0) {
            pop_front();
        } else if (pos == size() - 1) {
            pop_back();
        } else {
            Node<T>* current = head;
            for (int i = 0; i < pos; ++i) {
                current = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }
    }

    T operator[](int index) {
        if (index < 0 || index >= size()) {
            cout<<"Indice fuera de rango"<<endl;
        }
        Node<T>* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp->data;
    }

    bool empty() {
        return size() == 0;
    }

    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    void reverse() {
        if (empty() || head == tail) {
            return;
        }
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* temp = current->next;
            current->next = current->prev;
            current->prev = temp;
            if (current->prev == nullptr) {
                break;
            }
            current = current->prev;
        }
        Node<T>* temp = head;
        head = tail;
        tail = temp;
    }

    void print_list(){
        Node<T>* temp = head;
        while (temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    ~DoubleLinkedList() {
        clear();
    }
};

int main() {
    DoubleLinkedList<int> lista_doble;
    lista_doble.push_back(1);
    lista_doble.push_back(2);
    lista_doble.push_back(3);
    lista_doble.push_back(4);

    cout<<"Lista despues de push_back: "<<endl;
    lista_doble.print_list();

    cout<<endl;

    cout << "Front: " << lista_doble.front() << endl;
    cout << "Back: " << lista_doble.back() << endl;

    cout<<endl;

    lista_doble.insert(4, 1);
    cout<<"Lista despues de insert(4,1): "<<endl;
    lista_doble.print_list();

    cout<<endl;

    lista_doble.remove(2);
    cout<<"Lista despues de remove(2): "<<endl;
    lista_doble.print_list();

    cout<<endl;

    cout << "Size: " << lista_doble.size() << endl;
    cout<<endl;
    cout << "Uso de operador [], lista_doble[1] : " << lista_doble[1] << endl;

    cout << "Lista: "<<endl;
    lista_doble.print_list();

    cout<<endl;
    lista_doble.reverse();

    cout << "Lista despues de reverse(): "<<endl;
    lista_doble.print_list();

    return 0;
}
