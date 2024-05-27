/*

Just a simple linked list. Adding here as a potential utility for other problems.

*/

#include <iostream>

using namespace std;

template <typename T>
class Node {
    private:
        T _value;
        Node* _node;
    public:
        Node() : _node(nullptr) { }
        void setVal(const T& val) {
            _value = val;
        }
        T getVal() const {
            return _value;
        }
        void setNext(Node* nextNode) {
            _node = nextNode;
        }
        Node* getNext() const {
            return _node;
        }
};

template <typename T>
class LinkedList {
    private:
        Node<T>* headNode;    

    public:
        LinkedList() : headNode(nullptr) { };
        Node<T>* getHead() {
            return headNode;
        }
        void appendNode(Node<T>* newNode) {
            if (headNode == nullptr) {
                headNode = newNode;
            } else {
                Node<T>* lastNode = getHead();
                while (lastNode->getNext() != nullptr) {
                    lastNode = lastNode->getNext();
            }
            lastNode->setNext(newNode);
        }
    }
};

template <typename T>
class DoubleNode : Node<T> {
    private:
        DoubleNode* _prev;
    public:
        DoubleNode() : Node<T>(), _prev(nullptr) {}
        void setPrev(DoubleNode* prevNode) {
            _prev = prevNode;
        }
        DoubleNode* getPrev() const {
            return _prev;
        }
};