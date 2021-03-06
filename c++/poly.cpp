// pointers to base class
// Polymorphism + Virtual Function
// polymorphic class: inherits virtual function(s)

#include <iostream>
using namespace std;

// class with >=1 pure virtual function: is called 'abstract base class';
// cannot be used to instantiate objects
// Still can have pointers: Polygon *poly1;

class Polygon {
    protected:
    int width, height;
    
    public:
    Polygon (int w, int h) : width(w), height(h){
    }
    
    void set_values (int a, int b){
        width=a; 
        height=b; 
    }
    
    // not pure virtual function:
    // virtual int area(){
    //    return 0;
    // }
    
    // pure virtual function:
    virtual int area () =0;
    
    void print_area(){
        cout<<this->area()<<"\n";
    }
};

class Rectangle: public Polygon {
    public:
    
    // we need this? Yes, because we dont have a Polygon() constructor
    Rectangle (int w, int h) : Polygon(w, h){
    }
    
    int area(){
        return width*height;
    }
};

class Triangle: public Polygon {
    public:
    
    Triangle (int w, int h) : Polygon(w, h){
    }
        
    int area(){
        return width*height/2;
    }
};

int main () {
    Rectangle rect(4, 5);
    Triangle trgl(4, 5);
    Polygon * ppoly1 = &rect;
    Polygon * ppoly2 = &trgl;
    ppoly1->set_values (4,5);
    ppoly2->set_values (4,5);
    cout << ppoly1->area() << '\n';
    cout << ppoly2->area() << '\n';
    
    Polygon * poly = new Triangle(10, 14);
    Polygon* array[5] = {new Rectangle(3, 8), new Triangle(4, 6), new Triangle(5, 6), new Rectangle(4, 8), new Rectangle(3, 5)};
    for (int i=0; i<5; i++) array[i]->print_area();
    for (Polygon*p:array){
    }
    
    return 0;
}
