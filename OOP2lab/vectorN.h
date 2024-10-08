#pragma once
#include <iostream>

class VectorN
{
    double* cord;
    int n;

public:
    VectorN(int _n);
    ~VectorN();
    VectorN(const VectorN& vect);
    VectorN(int _n, double* _cord);
    
    VectorN operator+(VectorN& vect) const;
    VectorN operator-(VectorN& vect) const;
    VectorN& operator=(const VectorN& vect);
    bool operator==(const VectorN& vect);
    
    
    friend std::ostream& operator<<(std::ostream& os, const VectorN& vect);
    friend std::istream& operator>>(std::istream& is, VectorN& vect);

    void incDim(double val);
    void decDim();
    VectorN& multip(double val);

    int getN() { return n; };
    double* getCord() { return cord; };
    bool setN(int _n);
    bool setCord(int _n, double val);
    
    //стр 26 44 лаба 3

};