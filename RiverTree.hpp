#ifndef RIVERTREE_HPP
#define RIVERTREE_HPP
#include<string>

/*
 SLIGHT UPDATES TO STRUCTURE:
    Dams will go to the left of tree, tributaries to the left, will probs be ineffecient, will see if there is room
    for optimization after doing more coding??

    Nodes will either have a dam or tributary struct, if it has a dam tributary will be null, vice versa

*/



struct Tributary{
    char name[50];              // Name of the tributary (saw somewhere char array is better for writing to binary file)
    int length;                 // Length of how long tributary is, wikipedia shows this variable
    int basinSize;              // From wiki, forget decimals, round for easier binary file
    int averageDischarge;

    Tributary();
    Tributary(char name[], int length, int basinSize, int averageDischarge);
};
struct Dam{
    char name[100];           // name of the dam  (saw somewhere char array is better for writing to binary file)

    Dam();
    Dam(char name[]);
};

struct RiverNode{
    RiverNode* left;            // Left and right pointers to maintain tree structure
    RiverNode* right;           // Right pointer
    Dam* dam;                   // Dam pointer, 
    Tributary* trib;            // Tributary pointer, river nodes will only contain one, oher will be nullptr
    
    char name[14] = {'C', 'o', 'l', 'u', 'm', 'b', 'i', 'a', ' ', 'R', 'i', 'v', 'e', 'r'};

    RiverNode();  
    RiverNode(int type);               // Constructors and destructors for handling creating a node: How do we handle to types of nodes
    RiverNode(Dam* dam, Tributary* trib);
   // ~RiverNode();                            // No need for destructor? Nothing is deleted from river
    
};
class RiverTree{
    private:
        RiverNode* root;        // Root will represent the mouth of the columbia river
        void add_dam(char name[100]);        // helper functions?...
        RiverNode* add_dam(RiverNode* node);
        void add_tributary(std::string name, int location[2]);
        RiverNode* add_tributary(RiverNode* new_trib);
        void print_tribs(RiverNode* node);
        void print_dams(RiverNode* node);
    public:
        RiverTree();
        RiverTree(int val);
        void traverse_to(std::string name);     // For traversing, name can represent either a dam or a tributary
        void traverse_to(int location[2]);      // can traverse to a location, get what is there.
        void add_tributary();                   // For adding / inserting, not sure if needed because the river is always the same
        void add_dam();
        void print_tribs();
        void print_trib(RiverNode* node);
        void print_dam(RiverNode* node);
        void print_dams();
        void add(int val);
        



};


#endif