#include <fstream>
#include <sstream>
#include "classes/QuadTree.h"

Quad_tree read_image(string file_name){
    int height = 0, width = 0;
    fstream infile(file_name);
    stringstream ss;
    string inputLine = "";

    // First line : version
    getline(infile,inputLine);
    if(inputLine.compare("P2") != 0) cerr << "Version error" << endl;

    // Second line : comment
    getline(infile,inputLine);

    ss << infile.rdbuf();
    // Third line : size
    ss >> width >> height;

    Quad_tree tree(Point{width,height});

    int num;
    // Following lines : data
    for(int i = 0; i < height; ++i){
        for (int j = 0; j < width; ++j){
            ss >> num;
            tree.insert(Point{i,j},num);
        }
    }
    return tree;
}

int main(){
    /* Quad_tree tree(Point{100, 100});
    tree.insert(Point{50, 50}, 20);
    tree.insert(Point{20, 50}, 20);
    tree.insert(Point{40, 50}, 20);
    tree.insert(Point{50, 30}, 20);
    tree.insert(Point{50, 10}, 20);
    tree.insert(Point{50, 90}, 20); */

    Quad_tree tree(Point{127, 127});
    tree.insert(Point{40, 45}, 20);
    tree.insert(Point{15, 70}, 20);
    tree.insert(Point{70, 10}, 20);
    tree.insert(Point{69, 50}, 20);
    tree.insert(Point{55, 80}, 20);
    tree.insert(Point{80, 90}, 20);

    /* string file = "img/dragon.pgm";
    Quad_tree tree = read_image(file); */

    return 0;
}