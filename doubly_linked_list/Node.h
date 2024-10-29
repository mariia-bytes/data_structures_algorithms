#ifndef NODE_H
#define NODE_H

class Node {
    public:
        int value;
        Node* next;
        Node* prev;

    Node (int value) {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

#endif // NODE_H