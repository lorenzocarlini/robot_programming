#include <iostream>

struct VecF {
    int size; // Number of elements in vector
    float* v; // Pointer to allocated array of floats

    float get(int i) { return v[i];}  // No check is done on array's bounds

    // The following two methods do the same thing in a different way
    // Both ways have no bound check

    const float& at(int i) const { return v[i]; } // Element access by reference, cpp way (we also make sure the value returned cannot be changed)
    // The first const ensure the return value cannot modified, the second one is needed because calling a non-const method on a const object is not allowed by compilers

    float* atc(int i) {return &v[i];} // Get an element's pointer, the c way

    void set(int i,float f) {v[i]=f;} // Same as above

    // Empty constructor, array size 0 and v is a nullpointer
    VecF() { size=0; v=nullptr;} 

    // Constructor for array of given size, allocated proper size array
    VecF(int size){ 
        this->size=size;
        v=new float[size];
    }

    // Create deep-copy of another VecF structure
    VecF(const VecF& other) {
    size=0; v=0;
    if (! other.size) return; // If empty, return immediately
    size=other.size; v=new float[size];
    for (int i=0; i<size; ++i)
    v[i]=other.v[i];
    }

    // Destructor
    ~VecF() {if (size) delete [] v;}

    // Copy assignment operator
    VecF& operator =(const VecF& other) {
        if (size) delete[] v; size=0; v=0; // If memory is allocated to current VecF for array of floats, free memory
        if (! other.size) return *this;    // If the other VecF is empty, return immediately
        size=other.size; v=new float[size];
        for (int i=0; i<size; ++i)
        v[i]=other.v[i];
        return *this;
    }

    // Addition operator
    VecF operator+(const VecF& other) const{
        VecF returned(*this); // Create new VecF object to return
        if (size!=other.size) { // If the size of the two VecF doesn't match, trow error and return
            std::cerr << "Error: size mismatch!" << std::endl;
            return returned;
        }
        for(int i=0; i<size; ++i)
        returned.v[i]+=other.v[i];
        return returned;
    }

    // Subtraction operator
    VecF operator-(const VecF& other) const{
        VecF returned(*this); // Create new VecF object to return
        if (size!=other.size) { // If the size of the two VecF doesn't match, trow error and return
            std::cerr << "Error: size mismatch!" << std::endl;
            return returned;
        }
        for(int i=0; i<size; ++i)
            returned.v[i]-=other.v[i];
        return returned;
    }

    // Scalar multiplication
    VecF scalar_multiply(float s) const{
        VecF returned(*this); // Create new VecF object to return
        for(int i=0; i<size; ++i)
            returned.v[i]*=s;
        return returned;
    }

    // Dot production, self explainatory
    VecF dot_product(const VecF& other) const{
        if (size!=other.size) { // If the size of the two VecF doesn't match, trow error and return
            std::cerr << "Error: size mismatch!" << std::endl;
            return 0.0f;
        }
        float result = 0.0f;
        for (int i = 0; i < size; ++i)
            result += v[i] * other.v[i];
        return result;
    }
};