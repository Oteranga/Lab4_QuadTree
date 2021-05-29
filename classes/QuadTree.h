#include "Node.h"

class Quad_tree{
    private:
        Point box_limit;
        Node* root;

        Node* search(Point coordinates, Node* temp){
            if(temp == nullptr)
                return temp;
            if(temp->x_range.x <= coordinates.x && temp->x_range.x * 1.5 > coordinates.x && 
            temp->y_range.x * 1.5 <= coordinates.y && temp->y_range.y > coordinates.y){
                search(coordinates, temp->north_west);
            }
            else if(temp->x_range.x * 1.5 <= coordinates.x && temp->x_range.y > coordinates.x &&
            temp->y_range.x * 1.5 <= coordinates.y && temp->y_range.y > coordinates.y){
                search(coordinates, temp->north_east);
            }
            else if(temp->x_range.x <= coordinates.x && temp->x_range.x * 1.5 > coordinates.x &&
            temp->y_range.x <= coordinates.y && temp->y_range.x * 1.5 > coordinates.y){
                search(coordinates, temp->south_west);
            }
            else if(temp->x_range.x * 1.5 <= coordinates.x && temp->x_range.y > coordinates.x &&
            temp->y_range.x <= coordinates.y && temp->y_range.x * 1.5 > coordinates.y){
                search(coordinates, temp->south_east);
            }
            return temp;
        }

    public:
        Quad_tree(){
            box_limit = Point{0,0};
            root = nullptr;
        }

        Quad_tree(Point x_point){
            this->box_limit =  x_point;
            this->root = new Node(x_point,0);
        } 

        void insert(Point point, int key){
            if(!root && border_verifier(point)){
                Node* new_node = new Node(point, key);
                root = new_node;
            } else if(border_verifier(point)){
                Node* new_node = new Node(point, key);
                Node* current = root;
                if(point.x < box_limit.x / 2 && point.y >= box_limit.y / 2){
                    if(current->north_west == nullptr){
                        new_node->x_range = Point{0, box_limit.x / 2};
                        new_node->y_range = Point{box_limit.y / 2, box_limit.y};
                        root->north_west = new_node;
                    } else {
                        current = search(point, current->north_west);
                        new_node->x_range = Point{current->x_range.x / 2, current->x_range.y / 2};
                        new_node->y_range = Point{current->y_range.x / 2, current->y_range.y / 2};
                        current->north_west = new_node;
                    }
                }
                else if(point.x >= box_limit.x / 2 && point.y >= box_limit.y / 2){
                    if(current->north_east == nullptr){
                        new_node->x_range = Point{box_limit.x / 2, box_limit.x};
                        new_node->y_range = Point{box_limit.y / 2, box_limit.y};
                        root->north_east = new_node;
                    } else {
                        current = search(point, current->north_east);
                        new_node->x_range = Point{current->x_range.x / 2, current->x_range.y / 2};
                        new_node->y_range = Point{current->y_range.x / 2, current->y_range.y / 2};
                        current->north_east = new_node;
                    }
                }
                else if(point.x < box_limit.x / 2 && point.y < box_limit.y / 2){
                    if(current->south_west == nullptr){
                        new_node->x_range = Point{0, box_limit.x / 2};
                        new_node->y_range = Point{0, box_limit.y/2};
                        root->south_west = new_node;
                    } else{
                        current = search(point, current->south_west);
                        new_node->x_range = Point{current->x_range.x / 2, current->x_range.y / 2};
                        new_node->y_range = Point{current->y_range.x / 2, current->y_range.y / 2};
                        current->south_west = new_node;
                    }
                }
                else if(point.x >= box_limit.x / 2 && point.y < box_limit.y/2){
                    if(current->south_east == nullptr){
                        new_node->x_range = Point{box_limit.x / 2, box_limit.x};
                        new_node->y_range = Point{0, box_limit.y/2};
                        root->south_east = new_node;
                    } else{
                        current = search(point, current->south_east);
                        new_node->x_range = Point{current->x_range.x / 2, current->x_range.y / 2};
                        new_node->y_range = Point{current->y_range.x / 2, current->y_range.y / 2};
                        current->south_east = new_node;
                    }
                }
            }
        }

        void read_image(string file_name){

        }

        bool border_verifier(Point point){
            if(point.x > box_limit.x || point.y > box_limit.y || point.y < 0 || point.x < 0)
                return false;
            else return true;
        }

        void set_box_limit(Point point){
            this->box_limit = point;
        }
};