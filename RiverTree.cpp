#include "RiverTree.hpp"
#include <iostream>


// Default constructor, normally should never be used
Dam::Dam(){
    //char name[100];
    std::string nameOfDam = "";
    std::cout << "What is the name of the dam?" << std::endl;
    std::getline(std::cin, nameOfDam);
    for(int i = 0; i < 99; ++i){
        if(i < nameOfDam.size()){
            name[i] = nameOfDam.at(i);
        }else {
            name[i] = '\0';
        }
    }
}
/*
Dam::Dam(char name[]){
    for(int i = 0; i < 99; ++i){
        this->name[i] = name[i];     // need to make sure name is filled with null after meaningful character
    }
}*/
Tributary::Tributary(){
    std::string nameOfTrib = "";
    std::string trash;
    std::cout << "What is the name of the tributary?" << std::endl;
    std::getline(std::cin, nameOfTrib);
    for(int i = 0; i < 99; ++i){
        if(i < nameOfTrib.size()){
            name[i] = nameOfTrib.at(i);
        }else {
            name[i] = '\0';
        }
    }
    std::cout << "Length?" << std::endl;
    std::cin >> length;
    std::getline(std::cin, trash);
    std::cout << "Basin Size?" << std::endl;
    std::cin >> basinSize;
    std::getline(std::cin, trash);
    std::cout << "Average Discharge?" << std::endl;
    std::cin >> averageDischarge;
    
}
/*
Tributary::Tributary(char name[100], int length, int basinSize, int averageDischarge){
    for(int i = 0; i < 100; ++i){
        this->name[i] = name[i];    // need to make sure name is filled with null after meaningful character
    }
    this->length = length;
    this->basinSize = basinSize;
    this->averageDischarge = averageDischarge;
}
*/
RiverNode::RiverNode(){
    this->dam = nullptr;
    this->trib = nullptr;
    this->left = nullptr;
    this->right = nullptr;
    
}



// RIVERNODE Constructor, type is 1 for tributary node, 2 is dam node
RiverNode::RiverNode(int type){
    if(type == 1){
        this->trib = new Tributary();
        this->dam = nullptr;
        this->left = nullptr;
        this->right = nullptr;
    }else if(type == 2){
        this->dam = new Dam();
        this->trib = nullptr;
        this->left = nullptr;
        this->right = nullptr;

    }else if (type == 0){
        // Root / mouth

        }else{
        RiverNode();
    }
    
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
void RiverTree::print_trib(RiverNode* node){
    std::cout << "_________________________" << std::endl;
    std::cout << node->trib->name << std::endl;
    std::cout << std::endl;
    std::cout << "Length: " << node->trib->length << std::endl;
    std::cout << "Basin Size: " << node->trib->basinSize << std::endl;
    std::cout << "Average Discharge: " << node->trib->averageDischarge << std::endl;
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

void RiverTree::add_dam(){
    add_dam(root);
}   
RiverNode* RiverTree::add_dam(RiverNode* node){
    if(node->left == nullptr && node->right == nullptr){
        RiverNode* new_dam = new RiverNode(2);
        node->right = new_dam;
        return new_dam;
    }else if(node->right != nullptr){
        add_dam(node->right);
    }else if(node->left != nullptr){
        add_dam(node->left);
    }
    //return;
}
void RiverTree::add_tributary(){
    add_tributary(root);
}
RiverNode* RiverTree::add_tributary(RiverNode* node){
    if(node->left == nullptr && node->right == nullptr){
        RiverNode* new_trib = new RiverNode(1);
        node->left = new_trib;
        return new_trib;
    }else if(node->right != nullptr){
        add_tributary(node->right);
    }else if(node->left != nullptr){
        add_tributary(node->left);
    }
    
}

// Function that I think could help with binary file:
void RiverTree::add(int val){
    // 1 for dam adding, 0 tributary adding
    RiverNode* new_node;
    if(val == 1){
        new_node = add_dam(root);
    }if(val == 0){
        new_node = add_tributary(root);
    }
    // Write new node to binary file, should contain all infromation based on the node that has been added
    // Only issue is that the root will need to be written when I defined it in the tree constructior
}




