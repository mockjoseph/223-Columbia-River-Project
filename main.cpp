#include"RiverTree.hpp"

int main(){
    RiverTree tree;
    tree.add_dam();
    //tree.print_dams();
    tree.add(1);
    tree.add(0);
    tree.add(1);
    tree.print_tribs();
    tree.print_dams();
    return 0;
}