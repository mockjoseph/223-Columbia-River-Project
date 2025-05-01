#include "RiverTree.hpp"
#include <iostream>

// Default constructor, normally should never be used
Dam::Dam(){
    name;
}
Dam::Dam(char name[]){
    for(int i = 0; i < 99; ++i){
        this->name[i] = name[i];     // need to make sure name is filled with null after meaningful character
    }
}
Tributary::Tributary(){
    name;
    length = 0;
    basinSize = 0;
    averageDischarge = 0;
}
Tributary::Tributary(char name[100], int length, int basinSize, int averageDischarge){
    for(int i = 0; i < 100; ++i){
        this->name[i] = name[i];    // need to make sure name is filled with null after meaningful character
    }
    this->length = length;
    this->basinSize = basinSize;
    this->averageDischarge = averageDischarge;
}
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

