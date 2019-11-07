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
        if (!head) {
            return;
        } else {
            LinkedList *temp_node = head;
            delete head;
            head = nullptr;
            head = temp_node->next;
        }
    }

    template<typename ElementType>
    void LinkedList<ElementType>::pop_back() {
        if (!head) {
            return;
        } else {
            LinkedList *temp_node = tail;
            while (temp_node -> next != tail) {
            }
            delete tail;
            tail = nullptr;
            tail = temp_node;
            temp_node -> next = nullptr;
        }
    }

    template<typename ElementType>
    int LinkedList<ElementType>::size() const {
        LinkedList *temp_node = head;
        int size = 0;
        while (temp_node -> next) {
            temp_node = temp_node -> next;
            size++;
        }
        size++;
        return size;
    }

    template<typename ElementType>
    bool LinkedList<ElementType>::empty() const {
        return !head;
    }

    template<typename ElementType>
    void LinkedList<ElementType>::clear() {
        LinkedList *temp_node = head;
        while (temp_node -> next) {
            temp_node = temp_node -> next;
        }
        head = new LinkedListNode(nullptr);
    }

    template<typename ElementType>
    std::ostream &operator<<(std::ostream &os, const LinkedList<ElementType> &list) {

    }

    template<typename ElementType>
    void LinkedList<ElementType>::RemoveOdd() {

    }

    template<typename ElementType>
    bool LinkedList<ElementType>::operator==(const LinkedList<ElementType> &rhs) const {

    }

    template<typename ElementType>
    bool operator!=(const LinkedList<ElementType> &lhs, const LinkedList<ElementType> &rhs) {

    }

    template<typename ElementType>
    typename LinkedList<ElementType>::iterator &LinkedList<ElementType>::iterator::operator++() {

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
    bool
    LinkedList<ElementType>::const_iterator::operator!=(const LinkedList<ElementType>::const_iterator &other) const {

    }

    template<typename ElementType>
    typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::begin() const {

    }

    template<typename ElementType>
    typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::end() const {

    }
}