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
    std::cout << "What is the name of the dam?" << std::endl;
    std::getline(std::cin, nameOfTrib);
    for(int i = 0; i < 99; ++i){
        if(i < nameOfTrib.size()){
            name[i] = nameOfTrib.at(i);
        }else {
            name[i] = '\0';
        }
    }
    name;
    length = 0;
    basinSize = 0;
    averageDischarge = 0;
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
void RiverTree::add_dam(){
    add_dam(root);
}
void RiverTree::add_dam(RiverNode* node){
    if(node == nullptr){
        RiverNode* new_dam = new RiverNode(2);
        node = new_dam;
        return;
    }else{
        // Traverse further left, (Dams)
        add_dam(node->left);
    }

    return;
}
void RiverTree::add_tributary(){
    RiverNode* new_trib = new RiverNode(1);
    if(root->right->dam == nullptr){
        root->right = new_trib;
    }
    add_tributary(new_trib, root->right);
}
void RiverTree::add_tributary(RiverNode* new_trib, RiverNode* node){
    if(node == nullptr){
        node = new_trib;
        return;
    }else if (new_trib->trib->length < node->trib->length){
        add_tributary(node->left, new_trib);
    }else if (new_trib->trib->length > node->trib->length){
        add_tributary(node->right, new_trib);
    }
}
void RiverTree::print_tribs(){

}

