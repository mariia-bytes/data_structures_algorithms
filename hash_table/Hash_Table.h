#ifndef HASH_TABLE
#define HASH_TABLE

#include <iostream>
#include <vector>
#include <optional>
#include "Node.h"

class Hash_Table {
private:
    static const int SIZE = 7;
    Node* data_map[SIZE];

public:
    Hash_Table();
    ~Hash_Table();
    void print_table();
    int hash(const std::string key);
    void set(const std::string key, const int value);
    std::optional<int> get(const std::string key);
    std::vector<std::string> keys();
};

#endif // HASH_TABLE