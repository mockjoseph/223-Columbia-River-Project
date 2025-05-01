#include"RiverTree.hpp"

int main(){
    RiverTree tree;
    Tributary* cowlitz = new Tributary("name", 169, 6698, 287);
    Tributary* lewis = new Tributary("Lewis", 153, 2709, 173);
    Tributary* willamette = new Tributary("Willamette", 301, 28949, 1099);
    Tributary* sandy = new Tributary("Sandy", 92, 1316, 65);
    Dam* bonneville = new Dam("Bonneville Dam");

    

    tree.add_trib(cowlitz);
    tree.add_trib(lewis);
    tree.add_trib(willamette);
    tree.add_trib(sandy);
    tree.add_dam(bonneville);
    
    
    tree.print_tribs();
    
    return 0;
}