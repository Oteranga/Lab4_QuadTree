#include "QuadTree.h"

int main(){
    Quad_tree tree(Point{100, 100});
    tree.insert(Point{50, 50}, 20);
    tree.insert(Point{20, 50}, 20);
    tree.insert(Point{40, 50}, 20);
    tree.insert(Point{50, 30}, 20);
    tree.insert(Point{50, 10}, 20);
    tree.insert(Point{50, 90}, 20);

    return 0;
}