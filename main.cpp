#include"RiverTree.hpp"

int main(){
    RiverTree tree;
    
    Tributary* cowlitz = new Tributary("name", 169, 6698, 287);
    
    Tributary* lewis = new Tributary("Lewis", 153, 2709, 173);
    Tributary* willamette = new Tributary("Willamette", 301, 28949, 1099);
    Tributary* sandy = new Tributary("Sandy", 92, 1316, 65);
    
    Dam* bonneville = new Dam("Bonneville Dam");
    
    Tributary* klickitat = new Tributary("Klickitat", 154, 3496, 45);
    Tributary* deschutes = new Tributary("Deschutes", 406, 27550, 216);
    Tributary* johnday = new Tributary("John Day", 457, 20521, 80);
    Tributary* willowCreek = new Tributary("Willow Creek", 127, 2300, 1);
    Tributary* umatilla = new Tributary("Umatilla", 143, 6345, 14);
    Dam* mcnary = new Dam("McNary Dam");
    
    Tributary* snake = new Tributary("Snake", 1735, 260938, 1756);
    Tributary* Yakima = new Tributary("Yakima", 344, 15930, 100);
    Tributary* crabCreek = new Tributary("Crab Creek", 262, 13200, 40);
    Tributary* okanogan = new Tributary("Okanogan", 185, 21386, 99);
    Tributary* spokane = new Tributary("Spokane", 179, 17353, 229);

    
    tree.add_trib(cowlitz);
    tree.add_trib(lewis);
    tree.add_trib(willamette);
    tree.add_trib(sandy);
    tree.add_dam(bonneville);
    
    tree.add_trib(klickitat);
    tree.add_trib(deschutes);
    tree.add_trib(johnday);
    tree.add_trib(willowCreek);
    tree.add_trib(umatilla);
    tree.add_dam(mcnary);
    tree.add_trib(snake);
    tree.add_trib(Yakima);
    tree.add_trib(crabCreek);
    tree.add_trib(okanogan);
    tree.add_trib(spokane);
    
    tree.print_tribs();
    
    return 0;
}