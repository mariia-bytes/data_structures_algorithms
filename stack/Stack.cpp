/*************************************************
 * This Stack.cpp include implimentations of the
 * member and friend functions of a Stack class
 * defined in Stack.h
*************************************************/

#include <iostream>
#include "Node.h"
#include "Stack.h"

std::ostream &operator<<(std::ostream &os, const Stack* s) {
    os << "=\n";
    Node* temp = s->top;
    while (temp) {
        os << temp->value << std::endl;
        if (temp->next) {
            os << "|" << std::endl;
        }
        temp = temp->next;
    }
    os << "=" << std::endl;
    return os;
}