#ifndef RIVERTREE_HPP
#define RIVERTREE_HPP
#include<string>

struct Tributary{
    std::string name;           // Name of the tributary
    int location[2];            // Array for location, (coordinates) not sure if needed but could help to structure the tree
    int length;                 // Length of how long tributary is, wikipedia shows this variable

};
struct Dam{
    std::string name;           // name of the dam
    int location[2];            // Location (coordinates), could help with structuring

};
struct RiverNode{
    int type;                   // Correlates to type of node, either a dam or a tributary
    RiverNode* left;            // Left and right pointers to maintain tree structure
    RiverNode* right;           // Right pointer

    Tributary trib;             // Not sure if need both right now, but idea is that can have 2 different types of nodes
    Dam dam;                    // Dam ^

    RiverNode();                // Constructors and destructors for handling creating a node: How do we handle to types of nodes
//  RiverNode(int type)         // Overloading (two different types?)
    ~RiverNode();               // No need for destructor? Nothing is deleted from river

};
class RiverTree{
    private:
        RiverNode* root;        // Root will represent the mouth of the columbia river
        void add_dam(std::string name, int location[2]);        // helper functions?...
        void add_dam(RiverNode* node);
        void add_tributary(std::string name, int location[2]);
        void add_tributary(RiverNode* node);
    public:
        void traverse_to(std::string name);     // For traversing, name can represent either a dam or a tributary
        void traverse_to(int location[2]);      // can traverse to a location, get what is there.
        void add_tributary();                   // For adding / inserting, not sure if needed because the river is always the same
        void add_dam();
        



};


#endif