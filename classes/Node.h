#include <iostream>
#include <string>

using namespace std;

struct Point{
    int x; //Also considered first point
    int y; //Also considered second point
};

struct Node{
    Point point;
    Point x_range;
    Point y_range;
    int key;
    Node* north_west;
    Node* north_east;
    Node* south_west;
    Node* south_east;

    Node(Point _point, int value, Node* nw, Node* ne, Node* sw, Node* se):
    point(_point), key(value), north_west(nw), north_east(ne), south_west(sw),
    south_east(se){}

    Node(Point _point, int value){
        north_east = north_west = south_east = south_west = nullptr;
        point = _point;
        key = value;
    }

    Node(){}
};