#include "RiverTree.hpp"
#include <cassert>
#include <iostream>

void test_dam_creation() {
    std::cout << "Testing Dam creation... ";
    Dam dam("Grand Coulee Dam", "Columbia");
    assert(dam.name == "Grand Coulee Dam");
    assert(dam.parent_name == "Columbia");
    std::cout << "Passed!" << std::endl;
}

void test_tributary_creation() {
    std::cout << "Testing Tributary creation... ";
    Tributary trib("Snake", 1075, 108000, 1610, "Columbia");
    assert(trib.name == "Snake");
    assert(trib.length == 1075);
    assert(trib.basinSize == 108000);
    assert(trib.averageDischarge == 1610);
    assert(trib.parent_name == "Columbia");
    std::cout << "Passed!" << std::endl;
}

void test_rivernode_creation() {
    std::cout << "Testing RiverNode creation... ";
    // Test tributary node
    RiverNode tribNode("Willamette", 301, 28949, 1099, "Columbia");
    assert(tribNode.name == "Willamette");
    assert(tribNode.trib != nullptr);
    
    // Test dam node
    RiverNode damNode("Bonneville Dam", "Columbia");
    assert(damNode.name == "Bonneville Dam");
    assert(damNode.dam != nullptr);
    std::cout << "Passed!" << std::endl;
}

void test_tree_operations() {
    std::cout << "Testing Tree operations... ";
    RiverTree tree;
    
    // Create some nodes
    RiverNode* columbia = new RiverNode("Columbia", 0, 0, 0, "");
    RiverNode* willamette = new RiverNode("Willamette", 301, 28949, 1099, "Columbia");
    RiverNode* bonneville = new RiverNode("Bonneville Dam", "Columbia");
    
    // Test adding nodes
    assert(tree.add_node(columbia, willamette) == true);
    assert(tree.add_node(columbia, bonneville) == true);
    
    // Test finding nodes
    assert(tree.find_node(columbia, "Willamette") != nullptr);
    assert(tree.find_node(columbia, "Bonneville Dam") != nullptr);
    assert(tree.find_node(columbia, "NonExistent") == nullptr);
    
    std::cout << "Passed!" << std::endl;
}

void test_print_functions() {
    std::cout << "Testing print functions (visual verification)... " << std::endl;
    RiverTree tree;
    
    // Build a small test tree
    RiverNode* columbia = new RiverNode("Columbia", 0, 0, 0, "");
    RiverNode* willamette = new RiverNode("Willamette", 301, 28949, 1099, "Columbia");
    RiverNode* bonneville = new RiverNode("Bonneville Dam", "Columbia");
    
    tree.add_node(columbia, willamette);
    tree.add_node(columbia, bonneville);
    
    // These just verify the functions don't crash
    std::cout << "--- Testing print_trib ---" << std::endl;
    tree.print_trib(willamette);
    
    std::cout << "\n--- Testing print_dam ---" << std::endl;
    tree.print_dam(bonneville);
    
    std::cout << "\n--- Testing print_tree ---" << std::endl;
    tree.print_tree(columbia, 0);
    
    std::cout << "Print tests completed (verify output visually)" << std::endl;
}

void test_tree_height() {
    std::cout << "Testing tree height calculation... ";
    RiverTree tree;
    
    // Build a test tree
    RiverNode* root = new RiverNode("Columbia", 0, 0, 0, "");
    RiverNode* child1 = new RiverNode("Willamette", 1, 1, 1, "Columbia");
    RiverNode* child2 = new RiverNode("Snake", 2, 2, 2, "Columbia");
    
    tree.add_node(root, child1);
    tree.add_node(root, child2);
    
    assert(tree.calculate_height(root) == 3); // Root + two levels, because of our chosen tree structure
    
    std::cout << "Passed!" << std::endl;
}

int main() {
    std::cout << "=== Starting RiverTree Unit Tests ===" << std::endl;
    
    test_dam_creation();
    test_tributary_creation();
    test_rivernode_creation();
    test_tree_operations();
    test_print_functions();
    test_tree_height();
    
    std::cout << "=== All Tests Completed ===" << std::endl;
    return 0;
}