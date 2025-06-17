#include "Hash_Table.h"

Hash_Table::Hash_Table() {}

Hash_Table::~Hash_Table() {
    for(int i = 0; i < SIZE; i++) {
        Node* head = data_map[i];
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }
}


void Hash_Table::print_table() {
    for (int i = 0; i < SIZE; i++) {
        Node* temp = data_map[i];
        if (temp) {
            std::cout << "[" << i << "] ";
            while (temp) {
                std::cout << "{" << temp->key << ": " << temp->value << "}";
                if (temp->next) {
                    std::cout << " -> ";
                }
                temp = temp->next;
            }
            std::cout << std::endl;
        } else {
            std::cout << "[" << i << "] ( )" << std::endl;
        }
    }
}



int Hash_Table::hash(const std::string key) {
    int hash = 0;
    for (size_t i = 0; i < key.length(); i++) {
        int ascii_value = int(key[i]);
        hash = (hash + ascii_value * 23) % SIZE;
        // number 23 is a magic number here, 
        // it has no particular meaning, 
        // it's here only to make a hash value more 'random'
        // (according to the course author)
    }
    return hash;
}


void Hash_Table::set(const std::string key, const int value) {
    int index = hash(key);
    Node* new_node = new Node(key, value);
    if (data_map[index] == nullptr) {
        data_map[index] = new_node;
    } else {
        Node* temp = data_map[index];
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

std::optional<int> Hash_Table::get(const std::string key) {
    int index = hash(key);
    Node* temp = data_map[index];
    while (temp) {
        if (temp->key == key) return temp->value;
        temp = temp->next;
    }

    return std::nullopt;
}

std::vector<std::string> Hash_Table::keys() {
    std::vector<std::string> all_keys;

    for (int i = 0; i < SIZE; i++) {
        Node* temp = data_map[i];
        while (temp) {
            all_keys.push_back(temp->key);
            temp = temp->next;
        }
    }

    return all_keys;
}