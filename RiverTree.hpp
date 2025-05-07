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
    std::string name;              // Name of the tributary (saw somewhere char array is better for writing to binary file)
    int length;                 // Length of how long tributary is, wikipedia shows this variable
    int basinSize;              // From wiki, forget decimals, round for easier binary file
    int averageDischarge;

    std::string parent_name;


    Tributary();    // Default constructor (asks for what the data is)
    Tributary(std::string name, int length, int basinSize, int averageDischarge, std::string parent_name); // Paramaterized contructor for inputting data
};
struct Dam{
    std::string name;           // name of the dam  (saw somewhere char array is better for writing to binary file)

    std::string parent_name;

    Dam();  // Default, asks for input
    Dam(std::string name, std::string parent_name);      // Paramaterized, manually input
};

struct RiverNode{
    RiverNode* left;            // Left and right pointers to maintain tree structure
    RiverNode* right;           // Right pointer
    Dam* dam;                   // Dam pointer, 
    Tributary* trib;            // Tributary pointer, river nodes will only contain one, oher will be nullptr

    RiverNode* parent = nullptr;         // Parent pointer for traversing back up the tree NOTE: this is only used in explore tree, so it is only populated there, for now
    
    std::string name = "Columbia";    // A little wonky rn, but this will be updated to the name of the tributary or dam in the contructor now

    RiverNode();  
    RiverNode(int type);               // Constructors and destructors for handling creating a node: How do we handle two types of nodes
    RiverNode(Dam* dam, Tributary* trib);
    RiverNode(std::string name, int length, int basinSize, int averageDischarge, std::string parent_name);
    RiverNode(std::string name, std::string parent_name);
    RiverNode(const RiverNode& other);
   // ~RiverNode();                            // No need for destructor? Nothing is deleted from river
    
};
class RiverTree{
    private:
        //void add_dam(char name[100]);        // helper functions?...
        RiverNode* add_dam(RiverNode* node);
        //void add_tributary(std::string name, int location[2]);
        RiverNode* add_tributary(RiverNode* new_trib);
        void print_tribs(RiverNode* node);
        void print_dams(RiverNode* node);
        void traverse(RiverNode* node);
    public:
        RiverNode* root;        // Root will represent the mouth of the columbia river
        RiverTree();
        RiverTree(int val);
        RiverNode* getRoot() const;
        void add_node_interactive();
        void traverse_to(std::string name);     // For traversing, name can represent either a dam or a tributary
        void traverse_to(int location[2]);      // can traverse to a location, get what is there.
        void add_tributary();                   // For adding / inserting, not sure if needed because the river is always the same
        void add_dam();
        void print_tribs();
        void print_trib(RiverNode* node);
        void print_dam(RiverNode* node);
        void print_dams();
        void add(int val);
        void traverse();
        RiverNode* find_node(RiverNode* node, std::string name); // For traversing to a node, will return the node if found, nullptr if not found
        bool add_node(RiverNode* root, RiverNode* node);
        void add_dam(Dam* dam);
        void add_trib(Tributary* trib);

        void print_tree(RiverNode* root, int depth); // helper function for printing the tree
        void print_tree(RiverNode* root, int depth, int tree_height); // for printing the tree
        void print_node(RiverNode* node); // For printing a node, will print the tributary or dam data
        int calculate_height(RiverNode* root); // For calculating the height of the tree


};


#endif