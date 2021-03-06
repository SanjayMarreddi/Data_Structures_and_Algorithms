#include <stdio.h>

class Vector{

private:
    int x;
    int y;

public:
    // We can define numerous Constructors for a Same Class.

    Vector();
    Vector(int c, int d); // Even for Constructors, we can do Function Overloading, i.e. Same Name with different Arguments.

    void set(int x1, int y1){x = x1 ; y = y1;}
    int squarenorm();
    void print(); 
    void print(int z); // Function Overloading (Type of Polymorphism. Polymorphism means, Multiple Objects having the Same Name)
    
    Vector add(Vector v);

    // Operator Overloading 
    Vector operator + (Vector v);
    int operator * (Vector v);
    Vector operator ++ ();
    void operator ++ (int);
};


Vector :: Vector ()
{
     x =0;y=0;
}


Vector :: Vector (int c , int d)
{
     x = c ; y=d;
}


// We can even Return Vectors if required
Vector Vector::operator ++(){
    x++;
    y++;
    Vector v(x,y);
    return v ;
}

void Vector::operator ++(int){
    x++;
    y++;
}

// Dot Product of Two Vectors
int Vector:: operator * (Vector v){
    return (x*v.x + y*v.y);
}

// Without Operator Overloading
Vector Vector::add(Vector v){
    Vector v2;
    v2.set(x+v.x, y+v.y);
    return v2;
}
// Operator Overloading
Vector Vector:: operator + (Vector v){
    Vector v2;
    v2.set(x+v.x, y+v.y);
    return v2;
}

int Vector::squarenorm(){
    return (x*x + y*y);
}

void Vector::print(int z){
    //Scale the vector by z.
    x = z*x;
    y = z*y;
    printf("\n(x,y) = (%d,%d)",x,y);
    
}

void Vector::print(){
    int nm = squarenorm();
    printf("\n(x,y) = (%d,%d)",x,y);
    printf("\nNorm = %d",nm);
}

int main(){
   
/*
The new operator is an operator which denotes a request for memory allocation on the Heap. 
If sufficient memory is available, new operator initializes the memory and returns the address of the newly allocated and
initialized memory to the pointer variable. When you create an object of class using new keyword(normal new).

- The memory for the object is allocated using operator new from heap.
- The constructor of the class is invoked to properly initialize this memory.

    // Allocating the Memory using `new` i.e. DYNAMIC MEMORY ALLOCATION.
    Vector *v = new Vector();  
    Vector *v2 = new Vector(3,6);
    
    v->set(10,20);
    v->print();
    v-> print(2);
    v2->print();

    // Freeing the Memory using `delete`
    delete v ;
    delete v2;

*/    

    Vector u(3,5);  // Static Memory Allocation
    Vector z(0,5);
    Vector v = u.add(z);
    v.print();

    // Using Operator Overloading
    Vector w = u + z;
    w.print();

    // Using Operator Overloading
    int y = u * z;
    printf("\n Dot product is %d",y);

    Vector t = ++u;
    u.print();
    t.print();
    
    z++;
    z.print();
 

}