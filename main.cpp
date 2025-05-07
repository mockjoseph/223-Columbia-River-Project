#include"RiverTree.hpp"
#include <iostream>
#include <limits>

//function prototypes
void create_tree(RiverTree & tree);
void explore_tree(RiverTree & tree);

int main(){
    RiverTree tree;
    
    create_tree(tree); // Create the tree with the Columbia River and its tributaries and dams
    

    int choice = 0;
    while (choice != 5) {
        std::cout << "\n=== COLUMBIA RIVER SYSTEM MENU ===" << std::endl;
        std::cout << "(1) View Full Tree" << std::endl;
        std::cout << "(2) Explore Tree" << std::endl;
        std::cout << "(3) Print All Dams " << std::endl;
        std::cout << "(4) Add Node (Interactive)\n";
        std::cout << "(5) Quit\n";
        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choice) {
            case 1:
                std::cout << "\n=== FULL RIVER TREE ===" << std::endl;
                tree.print_tree(tree.root, 0);
                break;
                
            case 2:
                // Placeholder for Explore Tree functionality
                explore_tree(tree);
                break;
                
            case 3:
                tree.print_dams();
                break;
            case 4:
                tree.add_node_interactive();
                break;
            
            case 5:
                std::cout<<"Bye"<<std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter 1, 2, 3, 4, or 5 ." << std::endl;
                break;
        }
    }
    
    return 0;
}


void create_tree(RiverTree & tree) {
    // Main Columbia River (ordered west to east)
    tree.add_node(tree.root, new RiverNode("Willamette", 301, 28949, 1099, "Columbia"));
    tree.add_node(tree.root, new RiverNode("Bonneville Dam", "Columbia River"));
    tree.add_node(tree.root, new RiverNode("The Dalles Dam", "Columbia River"));
    tree.add_node(tree.root, new RiverNode("Deschutes", 252, 12700, 180, "Columbia"));
    tree.add_node(tree.root, new RiverNode("John Day", 284, 8100, 55, "Columbia"));
    tree.add_node(tree.root, new RiverNode("McNary Dam", "Columbia River"));
    tree.add_node(tree.root, new RiverNode("Yakima", 344, 15930, 100, "Columbia"));
    tree.add_node(tree.root, new RiverNode("Snake", 1075, 108000, 1610, "Columbia"));
    tree.add_node(tree.root, new RiverNode("Priest Rapids Dam", "Columbia River"));
    tree.add_node(tree.root, new RiverNode("Spokane", 111, 6160, 60, "Columbia"));
    tree.add_node(tree.root, new RiverNode("Grand Coulee Dam", "Columbia River")); 
    tree.add_node(tree.root, new RiverNode("Kootenay", 485, 42386, 299, "Columbia")); 

    // Willamette River tributaries & dams (west to east)
    tree.add_node(tree.root, new RiverNode("Clackamas", 83, 940, 65, "Willamette"));
    tree.add_node(tree.root, new RiverNode("Santiam", 92, 1840, 75, "Willamette"));
    tree.add_node(tree.root, new RiverNode("McKenzie", 90, 1250, 85, "Willamette"));
    tree.add_node(tree.root, new RiverNode("Cougar Dam", "Willamette"));
    tree.add_node(tree.root, new RiverNode("Detroit Dam", "Willamette"));

    // Snake River tributaries & dams (west to east)
    tree.add_node(tree.root, new RiverNode("Boise", 121, 11000, 100, "Snake"));
    tree.add_node(tree.root, new RiverNode("Palouse", 167, 3300, 15, "Snake"));
    tree.add_node(tree.root, new RiverNode("Clearwater", 120, 9500, 120, "Snake"));
    tree.add_node(tree.root, new RiverNode("Salmon", 425, 36000, 310, "Snake"));
    tree.add_node(tree.root, new RiverNode("Ice Harbor Dam", "Snake"));
    tree.add_node(tree.root, new RiverNode("Hells Canyon Dam", "Snake"));

    // Kootenay River tributaries & dams
    tree.add_node(tree.root, new RiverNode("Libby Dam", "Kootenay"));
    tree.add_node(tree.root, new RiverNode("Pend Oreille River", 179, 17353, 229, "Kootenay"));
    tree.add_node(tree.root, new RiverNode("Elk River", 117, 4500, 60, "Kootenay"));
    tree.add_node(tree.root, new RiverNode("Lower Bonnington Dam", "Kootenay"));
    tree.add_node(tree.root, new RiverNode("Upper Bonnington Dam", "Kootenay"));
    tree.add_node(tree.root, new RiverNode("Corra Linn Dam", "Kootenay"));

    tree.add_node(tree.root, new RiverNode("Monroe Street Dam", "Spokane"));
}


void explore_tree(RiverTree & tree) {
    RiverNode* current = tree.root;
    current->parent = nullptr; // Initialize root's parent as nullptr
    
    while (true) {
        tree.print_node(current);
        
        std::cout << "\n=== NAVIGATION OPTIONS ===" << std::endl;
        std::cout << "(1) Move upstream (left child)" << std::endl;
        std::cout << "(2) Move to tributary (right child)" << std::endl;
        if (current->parent != nullptr) {
            std::cout << "(3) Move downstream (to parent)" << std::endl;
        }
        std::cout << "(4) Return to main menu" << std::endl;
        
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1: // Move upstream (left)
                if (current->left != nullptr) {
                    current->left->parent = current; // Set parent before moving
                    current = current->left;
                } else {
                    std::cout << "No upstream path available!\n";
                }
                break;
                
            case 2: // Move to tributary (right)
                if (current->right != nullptr) {
                    current->right->parent = current; // Set parent before moving
                    current = current->right;
                } else {
                    std::cout << "No tributaries available!\n";
                }
                break;
                
            case 3: // Move downstream (parent)
                if (current->parent != nullptr) {
                    current = current->parent;
                } else {
                    std::cout << "Already at the top of the river system!\n";
                }
                break;
                
            case 4: // Return to main menu
                return;
                
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}
