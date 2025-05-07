#include "RiverTree.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <limits>


// Default constructor, normally should never be used
Dam::Dam(){
    //char name[100];
    std::string nameOfDam = "";
    std::string parent = "";
    std::string trash;
    std::cout << "What is the name of the dam?" << std::endl;
    std::getline(std::cin, nameOfDam);
    this->name = nameOfDam;
    std::cout << "What tributary is this dam on?" << std::endl;
    std::getline(std::cin, parent);
    parent_name = parent;
}

Dam::Dam(std::string name, std::string parent_name){
    this->name = name;
    this->parent_name = parent_name;
}
Tributary::Tributary(){
    std::string nameOfTrib = "";
    std::string trash;
    std::cout << "What is the name of the tributary?" << std::endl;
    std::getline(std::cin, nameOfTrib);
    this->name = nameOfTrib;
    std::cout << "Length?" << std::endl;
    std::cin >> length;
    std::getline(std::cin, trash);
    std::cout << "Basin Size?" << std::endl;
    std::cin >> basinSize;
    std::getline(std::cin, trash);
    std::cout << "Average Discharge?" << std::endl;
    std::cin >> averageDischarge;
    std::getline(std::cin, trash);
    std::cout << "What tributary is this branching off of?" << std::endl;
    std::cin >> parent_name;
}

Tributary::Tributary(std::string name, int length, int basinSize, int averageDischarge, std::string parent_name){
    this->name = name;
    this->length = length;
    this->basinSize = basinSize;
    this->averageDischarge = averageDischarge;
    this->parent_name = parent_name;
}

RiverNode::RiverNode(){
    this->dam = nullptr;
    this->trib = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

RiverNode::RiverNode(std::string name, int length, int basinSize, int averageDischarge, std::string parent_name){
    this->trib = new Tributary(name, length, basinSize, averageDischarge, parent_name);
    this->dam = nullptr;
    this->left = nullptr;
    this->right = nullptr;
    this->name = trib->name; // Set the name of the node to the tributary name
}

RiverNode::RiverNode(std::string name, std::string parent_name){
    this->dam = new Dam(name, parent_name);
    this->trib = nullptr;
    this->left = nullptr;
    this->right = nullptr;
    this->name = dam->name; // Set the name of the node to the dam name
}



// RIVERNODE Constructor, type is 1 for tributary node, 2 is dam node
RiverNode::RiverNode(int type){
    if(type == 1){
        this->trib = new Tributary();
        this->dam = nullptr;
        this->left = nullptr;
        this->right = nullptr;
        this->name = trib->name; // Set the name of the node to the tributary name
    }else if(type == 2){
        this->dam = new Dam();
        this->trib = nullptr;
        this->left = nullptr;
        this->right = nullptr;
        this->name = dam->name; // Set the name of the node to the dam name
    }else if (type == 0){
        // Root / mouth

        }else{
        RiverNode();
    }
    
}

//copy constructor
RiverNode::RiverNode(const RiverNode& other) {
    name = other.name;

    // Deep copy Dam
    if (other.dam != nullptr) {
        dam = new Dam(*other.dam);
    } else {
        dam = nullptr;
    }

    // Deep copy Tributary
    if (other.trib != nullptr) {
        trib = new Tributary(*other.trib);
    } else {
        trib = nullptr;
    }

    // We will not copy children, because this would be bad for copying in our intended tree structure
    left = nullptr;
    right = nullptr;
}


RiverTree::RiverTree(){
    root = new RiverNode();
}
void RiverTree::print_dam(RiverNode* node){
    std::cout << "_______________" << std::endl;
    std::cout << node->dam->name << std::endl;
    std::cout << "----------------" << std::endl;
}
void RiverTree::print_dams(RiverNode* node){
    if(node == nullptr){
        return;
    }
    
    if(node->dam){
        print_dam(node);
    }
    print_dams(node->left);
    print_dams(node->right);
    
}
void RiverTree::print_dams(){
    print_dams(root);
}
void RiverTree::print_node(RiverNode* node){
    if (node->name == "Columbia") {
        std::cout << "_________________________" << std::endl;
        std::cout << node->name << std::endl;
        std::cout << std::endl;
        std::string child_name = node->right ? node->right->name : "None";
        std::cout << "Child?: " << child_name << std::endl;
        std::cout << "------------------------" << std::endl;
    }
    else if(node->trib){
        print_trib(node);
    }else if(node->dam){
        print_dam(node);
    }else{
        std::cout << "No data" << std::endl;
    }

}
void RiverTree::print_trib(RiverNode* node){
    std::cout << "_________________________" << std::endl;
    std::cout << node->name << std::endl;
    std::cout << std::endl;
    std::cout << "Length: " << node->trib->length << std::endl;
    std::cout << "Basin Size: " << node->trib->basinSize << std::endl;
    std::cout << "Average Discharge: " << node->trib->averageDischarge << std::endl;
    std::cout << "Parent: " << node->trib->parent_name << std::endl;
    std::string child_name = node->right ? node->right->name : "None";
    std::cout << "Child?: " << child_name << std::endl;
    std::cout << "------------------------" << std::endl;
}
void RiverTree::print_tribs(){
    print_tribs(root);
}
void RiverTree::print_tribs(RiverNode* node){
    if(node == nullptr){
        return;
    }
    if(node->trib){
        print_trib(node);
    }
    print_tribs(node->left);
    print_tribs(node->right);
}

bool RiverTree::add_node(RiverNode* root, RiverNode* node){
    std::string parent_name = node->trib ? node->trib->parent_name : node->dam->parent_name; // Get the parent name from the tributary or dam
    if (root == nullptr) {
        return false;
    }
    if (root->name == parent_name) {
        if (root->left && (root->left->name == parent_name)) {
            return add_node(root->left, node); // Recursively go left, because we want to add this as far down this 'river' as possible. basically this means there is already a branch in this spot and we want to go down to an open spot
        }
        root->right = node;
        RiverNode* root_copy = new RiverNode(*root); // Create a copy of the root node
        root->left = root_copy; // Set the left child to the copy of the root node
        return true;
    }
    if (add_node(root->left, node)) {
        return true; // Recursively search left and right children
    }
    return add_node(root->right, node); // Recursively search left and right children
}

RiverNode* RiverTree::find_node(RiverNode* root, std::string name) {
    if (root == nullptr) {
        return nullptr;
    }

    if ((root->trib && root->trib->name == name) || (root->dam && root->dam->name == name)) { // confusing syntax here is just making sure these are not null
        return root;
    }

    RiverNode* right_result = find_node(root->right, name);
    if (right_result != nullptr) {
        return right_result;
    }

    return find_node(root->left, name);
}

void RiverTree::print_tree(RiverNode* root, int depth) {
    int tree_height = calculate_height(root); // Calculate the height of the tree
    // std::cout << "Tree Height: " << tree_height << std::endl; // Print the height of the tree
    print_tree(root, depth, tree_height); // Call the overloaded function with the calculated height
}


void RiverTree::print_tree(RiverNode* root, int depth, int tree_height) {
    if (root == nullptr) {
        return;
    }
    print_tree(root->left, depth + 1, tree_height); // Print left subtree first
    for (int i = depth + 1; i < tree_height; i++) {
        std::cout << "               "; // Indent for depth
    }
    std::cout << root->name << std::endl; // Print the current node name
    print_tree(root->right, depth + 1, tree_height); // Print right subtree
}


int RiverTree::calculate_height(RiverNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int left_height = calculate_height(root->left);
    int right_height = calculate_height(root->right);
    return std::max(left_height, right_height) + 1; // Height of the tree is max of left and right subtree heights + 1 for the current node
}

static void collect_leaf_names(RiverNode* node, std::vector<std::string>& leaves) {
    if (!node) return;
    if (node->left == nullptr && node->right == nullptr) {
        leaves.push_back(node->name);
    } else {
        collect_leaf_names(node->left, leaves);
        collect_leaf_names(node->right, leaves);
    }
}

void RiverTree::add_node_interactive() {
    // List all current leaf nodes
    std::vector<std::string> leaves;
    collect_leaf_names(root, leaves);
    std::cout << "Current leaf nodes:\n";
    for (const auto& name : leaves) {
        std::cout << "  - " << name << "\n";
    }

    // Prompt for the parent (leaf) to attach to
    std::cout << "Enter the name of the leaf node to attach to: ";
    std::string parentName;
    std::getline(std::cin, parentName);

    RiverNode* parentNode = find_node(root, parentName);
    if (!parentNode) {
        std::cout << "No node found with name \"" << parentName << "\". Operation canceled.\n";
        return;
    }

    // Prompt for new node type
    std::cout << "Enter new node type (\"dam\" or \"tributary\"): ";
    std::string type;
    std::getline(std::cin, type);

    // Collect properties and construct the new node
    RiverNode* newNode = nullptr;
    if (type == "dam") {
        std::cout << "Enter dam name: ";
        std::string damName;
        std::getline(std::cin, damName);
        newNode = new RiverNode(damName, parentName);

    } else if (type == "tributary") {
        std::cout << "Enter tributary name: ";
        std::string tribName;
        std::getline(std::cin, tribName);

        std::cout << "Enter length (integer): ";
        int length;  
        std::cin >> length;  
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Enter basin size (integer): ";
        int basinSize;  
        std::cin >> basinSize;  
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Enter average discharge (integer): ";
        int avgDischarge;  
        std::cin >> avgDischarge;  
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        newNode = new RiverNode(tribName, length, basinSize, avgDischarge, parentName);

    } else {
        std::cout << "Invalid type entered. Operation canceled.\n";
        return;
    }

    // Attempt to add and report result
    if (add_node(root, newNode)) {
        std::cout << "Node \"" << newNode->name << "\" added successfully under \"" 
                  << parentName << "\".\n";
    } else {
        std::cout << "Failed to attach node to \"" << parentName << "\".\n";
        delete newNode;
    }
}
