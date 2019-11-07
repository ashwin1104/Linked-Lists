#include <utility>
#include <cassert>
#include "ll.h"

namespace cs126linkedlist {
    template<typename ElementType>
    LinkedList<ElementType>::LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    template<typename ElementType>
    LinkedList<ElementType>::LinkedList(const std::vector<ElementType> &values) {
        head = new LinkedListNode(values.at(0));
        LinkedListNode *temp_node = head;
        for (int i = 1; i < values.size(); i++) {
            temp_node -> next = new LinkedListNode(values.at(i));
            temp_node = temp_node -> next;
        }
        tail = temp_node;
    }

    // Copy constructor
    template<typename ElementType>
    LinkedList<ElementType>::LinkedList(const LinkedList<ElementType> &source) {
        LinkedListNode *temp_node = source.head;
        head = temp_node;
        temp_node = temp_node -> next;
        while (temp_node != nullptr) {
            push_back(temp_node -> data);
            temp_node = temp_node -> next;
        }
        tail = source.tail;
    }

    // Move constructor
    template<typename ElementType>
    LinkedList<ElementType>::LinkedList(LinkedList<ElementType> &&source) noexcept {
//        head = source.head;
//        LinkedListNode *current_node = source.head -> next;
//        while (current_node != nullptr) {
//            push_back(current_node -> data);
//            LinkedListNode *next_node = current_node -> next;
//            delete current_node;
//            current_node = next_node;
//        }
//        tail = source.tail;
    }

    // Destructor
    template<typename ElementType>
    LinkedList<ElementType>::~LinkedList() {
//        LinkedListNode *current_node = head;
//        while(current_node != nullptr) {
//            LinkedListNode *next_node = current_node -> next;
//            delete current_node;
//            current_node = next_node;
//        }
//        head = nullptr;
//        tail = nullptr;
    }

    // Copy assignment operator
    template<typename ElementType>
    LinkedList<ElementType> &LinkedList<ElementType>::operator=(const LinkedList<ElementType> &source) {
        LinkedList copy_list = LinkedList(source);
        return copy_list;
    }

    // Move assignment operator
    template<typename ElementType>
    LinkedList<ElementType> &LinkedList<ElementType>::operator=(LinkedList<ElementType> &&source) noexcept {
        LinkedList move_list = LinkedList(source);
        return move_list;
    }

    template<typename ElementType>
    void LinkedList<ElementType>::push_front(ElementType value) {
        LinkedListNode *node;
        node = new LinkedListNode(value);
        if (head == nullptr) {
            head = node;
        } else {
            LinkedListNode *old_head = head;
            node -> next = old_head;
            head = node;
        }
    }

    template<typename ElementType>
    void LinkedList<ElementType>::push_back(ElementType value) {
        LinkedListNode *node;
        node = new LinkedListNode(value);
        if (head == nullptr) {
            head = node;
        } else {
            tail -> next = node;
            tail = node;
        }
    }

    template<typename ElementType>
    ElementType LinkedList<ElementType>::front() const {
        return head->data;
    }

    template<typename ElementType>
    ElementType LinkedList<ElementType>::back() const {
        return tail->data;
    }

    template<typename ElementType>
    void LinkedList<ElementType>::pop_front() {
        if (head == nullptr) {
            return;
        } else {
            head = head -> next;
        }
    }

    template<typename ElementType>
    void LinkedList<ElementType>::pop_back() {
        if (head == nullptr) {
            return;
        } else {
            LinkedListNode *temp = head;
            while (temp -> next != tail) {
                temp = temp -> next;
            }
            delete temp -> next;
            tail = temp;
        }
    }

    template<typename ElementType>
    int LinkedList<ElementType>::size() const {
        LinkedListNode *temp_node = head;
        int size = 0;
        while (temp_node -> next != nullptr) {
            temp_node = temp_node -> next;
            size++;
        }
        size++;
        return size;
    }

    template<typename ElementType>
    bool LinkedList<ElementType>::empty() const {
        return head == nullptr;
    }

    template<typename ElementType>
    void LinkedList<ElementType>::clear() {
        LinkedListNode *current_node = head;
        while (current_node -> next) {
            LinkedListNode *next_node = current_node -> next;
            delete current_node;
            current_node = next_node;
        }
        head = nullptr;
        tail = nullptr;
    }

    template<typename ElementType>
    std::ostream &operator<<(std::ostream &os, LinkedList<ElementType> &list) {
        if (list.empty() || list.empty()) {
            os << "";
            return os;
        } else {
            while (list.head->next != nullptr) {
                os << list.front() << ", ";
                list.pop_front();
            }
            os << list.front() << std::endl;
        }
        return os;
    }

    template<typename ElementType>
    void LinkedList<ElementType>::RemoveOdd() {
        if (size() <= 1) {
            return;
        }
        LinkedListNode *current_node = head -> next;
        if (current_node != nullptr) {
            head -> next = current_node -> next;
        }
        else {
            head -> next = nullptr;
            delete current_node;
            return;
        }
        bool isOdd = true;
        while (current_node -> next -> next != nullptr) {
            LinkedListNode *next_node = current_node -> next;
            if (isOdd) {
                delete current_node;
            }
            else {
                current_node -> next = next_node -> next;
            }
            isOdd = !isOdd;
        }
        if (isOdd) {
            delete current_node;
        }
    }

    template<typename ElementType>
    bool LinkedList<ElementType>::operator==(const LinkedList<ElementType> &rhs) const {
        LinkedListNode *current_node = head;
        LinkedListNode *enemy_node = rhs.head;
        if (size() != rhs.size()) {
            return false;
        }
        for (int iterator = 0; iterator < size(); iterator++) {
            if (current_node -> data != enemy_node -> data) {
                return false;
            }
            current_node = current_node -> next;
            enemy_node = enemy_node -> next;
        }
    }

    template<typename ElementType>
    bool operator!=(const LinkedList<ElementType> &lhs, const LinkedList<ElementType> &rhs) {
        return(!(lhs == rhs));
    }

    template<typename ElementType>
    typename LinkedList<ElementType>::iterator &LinkedList<ElementType>::iterator::operator++() {
        iterator
        LinkedListNode temp_node;
        return temp_node.data;
    }

    template<typename ElementType>
    ElementType &LinkedList<ElementType>::iterator::operator*() const {
    }

    template<typename ElementType>
    bool LinkedList<ElementType>::iterator::operator!=(const LinkedList<ElementType>::iterator &other) const {

    }

    template<typename ElementType>
    typename LinkedList<ElementType>::iterator LinkedList<ElementType>::begin() {

    }

    template<typename ElementType>
    typename LinkedList<ElementType>::iterator LinkedList<ElementType>::end() {

    }

    template<typename ElementType>
    typename LinkedList<ElementType>::const_iterator &LinkedList<ElementType>::const_iterator::operator++() {

    }

    template<typename ElementType>
    const ElementType &LinkedList<ElementType>::const_iterator::operator*() const {

    }

    template<typename ElementType>
    bool LinkedList<ElementType>::const_iterator::operator!=(const LinkedList<ElementType>::const_iterator &other) const {

    }

    template<typename ElementType>
    typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::begin() const {
        iterator temp = new iterator(head);
        return temp;
    }

    template<typename ElementType>
    typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::end() const {
        iterator temp = new iterator(tail);
        return temp;
    }
}