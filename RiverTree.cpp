#include "RiverTree.hpp"
#include <iostream>

// Default constructor, normally should never be used
RiverNode::RiverNode(){
    this->type = "";
    this->length = -1;
    this->left = nullptr;
    this->right = nullptr;
}
// Dam constructor, type is assumed to be dam, name can be the name of a dam
RiverNode::RiverNode(std::string name){
    this->type = "Dam"   ;   // "Dam"
    this->length = 0;             // Dam has no length, tributary does I think
    this->left = nullptr;
    this->right = nullptr;
}
// Tributary constructor, type is assumed to be tributary becayse dams do not ahve a length
RiverNode::RiverNode(std::string name, int length){
    this->type = "Tributary";     // "Tributary"
    this->name = name;      // name of trib
    this->length = length;  // length of trib
    this->left = nullptr;
    this->right = nullptr;
}