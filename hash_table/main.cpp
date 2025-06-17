#include <iostream>
#include "Hash_Table.h"

int main() {
    std::cout << "\nQuick check the constructor and print\n";

    Hash_Table* my_ht = new Hash_Table();
    my_ht->print_table();

    std::cout << "\nChech the Set function\n";
    my_ht->set("nails", 100);
    my_ht->set("tile", 50);
    my_ht->set("lumber", 80);
    my_ht->set("bolts", 200);
    my_ht->set("screws", 0);

    my_ht->print_table();

    std::cout << "\nQuick check the Get function\n";

    auto tile_val = my_ht->get("tile");
    if (tile_val) {
        std::cout << "\ttile: " << *tile_val << std::endl;
    } else {
        std::cout << "\ttile: Key not found" << std::endl;
    }

    auto invalid_val = my_ht->get("boobies");
    if (invalid_val) {
        std::cout << "\tboobies: " << *invalid_val << std::endl;
    } else {
        std::cout << "\tboobies: key not found" << std::endl;
    }

    std::cout << "\nQuick check the Keys function\n";

    std::vector<std::string> all_keys = my_ht->keys();

    std::cout << "\t[ ";
    for (auto& key : all_keys) {
        std::cout << key << " ";       
    }
    std::cout << "]\n";

    return 0;
}