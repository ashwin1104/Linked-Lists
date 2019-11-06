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

    }

    // Copy constructor
    template<typename ElementType>
    LinkedList<ElementType>::LinkedList(const LinkedList<ElementType> &source) {

    }

    // Move constructor
    template<typename ElementType>
    LinkedList<ElementType>::LinkedList(LinkedList<ElementType> &&source) noexcept {

    }

    // Destructor
    template<typename ElementType>
    LinkedList<ElementType>::~LinkedList() {

    }

    // Copy assignment operator
    template<typename ElementType>
    LinkedList<ElementType> &LinkedList<ElementType>::operator=(const LinkedList<ElementType> &source) {

    }

    // Move assignment operator
    template<typename ElementType>
    LinkedList<ElementType> &LinkedList<ElementType>::operator=(LinkedList<ElementType> &&source) noexcept {

    }

    template<typename ElementType>
    void LinkedList<ElementType>::push_front(ElementType value) {
        LinkedListNode *node = new LinkedListNode(value);
        if (!head) {
            head = node;
        } else {
            LinkedList *old_head = head;
            LinkedListNode *new_node = new LinkedListNode(value);
            head = new_node;
            new_node -> next = old_head;
            while (old_head -> next) {
                old_head = old_head -> next;
            }
        }
    }

    template<typename ElementType>
    void LinkedList<ElementType>::push_back(ElementType value) {
        LinkedListNode *node = new LinkedListNode(value);
        if (!head) {
            head = node;
        } else {
            LinkedListNode *tempNode = head;
            while (tempNode -> next) {
                tempNode = tempNode -> next;
            }
            tempNode -> next = new LinkedListNode(value);
            tail = tempNode;
        }
    }

    template<typename ElementType>
    ElementType LinkedList<ElementType>::front() const {
        return head;
    }

    template<typename ElementType>
    ElementType LinkedList<ElementType>::back() const {
        return tail;
    }

    template<typename ElementType>
    void LinkedList<ElementType>::pop_front() {
        if (!head) {
            return;
        } else {
            LinkedList *temp_node = head;
            delete head;
            head = nullptr;
            head = temp_node -> next;
        }
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
        return size;
    }

    template<typename ElementType>
    bool LinkedList<ElementType>::empty() const {
        if (!head) {
            return true;
        }
        return false;
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