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
    this->dam = new Dam();
    this->trib = new Tributary();
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

    }else{
        RiverNode();
    }
    
}
void RiverTree::print_dam(RiverNode* node){
    for(int i = 0; i < 100; ++i){
        if(node->dam->name[i] == '\0'){
            break;
        }
        std::cout << node->dam->name;
    }
    std::cout << std::endl;
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
    for(int i = 0; i < 100; ++i){
        if(node->trib->name[i] == '\0'){
            break;
        }
        std::cout << node->trib->name[i];
    }
    std::cout << std::endl;
    std::cout << "Length: " << node->trib->length << std::endl;
    std::cout << "Basin Size" << node->trib->basinSize << std::endl;
    std::cout << "Average Discharge" << node->trib->averageDischarge << std::endl;
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
void RiverTree::add_dam(RiverNode* node){
    if(node->left == nullptr && node->right == nullptr){
        RiverNode* new_dam = new RiverNode(2);
        node->right = new_dam;
    }else if(node->right != nullptr){
        add_dam(node->right);
    }else if(node->left != nullptr){
        add_dam(node->left);
    }
    return;
}
void RiverTree::add_tributary(){
    add_tributary(root);
}
void RiverTree::add_tributary(RiverNode* node){
    if(node->left == nullptr && node->right == nullptr){
        RiverNode* new_trib = new RiverNode(1);
        node->left = new_trib;
    }else if(node->right != nullptr){
        add_tributary(node);
    }else if(node->left != nullptr){
        add_tributary(node);
    }
    return;
}
