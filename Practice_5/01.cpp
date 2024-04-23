#include <iostream>

using namespace std;

// Определение структуры узла
struct Node {
    float data;
    Node* next;

    Node(float value) : data(value), next(nullptr) {}
};

// Односвязный список
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Вставка нового узла
    void insertAtBeginning(float data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Удаление узла
    void deleteNode(float key) {
        Node* temp = head;
        Node* prev = nullptr;

        if (temp != nullptr && temp->data == key) {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) return;

        prev->next = temp->next;
        delete temp;
    }

    // Вывод списка
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // Перенос первых k узлов в конец списка
    void moveFirstKToEnd(int k) {
        if (head == nullptr || k <= 0) return;

        Node* current = head;
        int count = 1;
        while (count < k && current != nullptr) {
            current = current->next;
            count++;
        }

        if (current == nullptr) return;

        Node* kthNode = current;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = head;
        head = kthNode->next;
        kthNode->next = nullptr;
    }

    // Переставляет местами узлы с максимальным и минимальным значениями
    void swapMaxMinNodes() {
        if (head == nullptr || head->next == nullptr) return;

        Node* maxNode = head;
        Node* minNode = head;
        Node* current = head->next;

        while (current != nullptr) {
            if (current->data > maxNode->data) {
                maxNode = current;
            } else if (current->data < minNode->data) {
                minNode = current;
            }
            current = current->next;
        }

        if (maxNode == minNode) return;

        float temp = maxNode->data;
        maxNode->data = minNode->data;
        minNode->data = temp;
    }

    // Удаляет предпоследний узел списка
    void deleteSecondLastNode() {
        if (head == nullptr || head->next == nullptr) return;

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        Node* secondLastNode = temp->next;
        temp->next = temp->next->next;
        delete secondLastNode;
    }
};

int main() {
    LinkedList linkedList;
    int n;
    std::cout << "Enter the number of elements in the list: ";
    std::cin >> n;
    std::cout << "Enter the elements of the list: " << std::endl;
    for (int i = 0; i < n; ++i) {
        float data;
        std::cin >> data;
        linkedList.insertAtBeginning(data);
    }

    int choice;
    do {
        std::cout << "\nChoose an operation:" << std::endl;
        std::cout << "1. Print the list" << std::endl;
        std::cout << "2. Move the first k elements to the end of the list" << std::endl;
        std::cout << "3. Swap nodes with maximum and minimum values" << std::endl;
        std::cout << "4. Delete the second last node of the list" << std::endl;
        std::cout << "5. Exit" << std::endl;

        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "List: ";
                linkedList.printList();
                break;
            case 2:
                int k;
                std::cout << "Enter the number of nodes to move to the end: ";
                std::cin >> k;
                linkedList.moveFirstKToEnd(k);
                std::cout << "Nodes moved." << std::endl;
                break;
            case 3:
                linkedList.swapMaxMinNodes();
                std::cout << "Nodes with maximum and minimum values swapped." << std::endl;
                break;
            case 4:
                linkedList.deleteSecondLastNode();
                std::cout << "Second last node deleted." << std::endl;
                break;
            case 5:
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}
