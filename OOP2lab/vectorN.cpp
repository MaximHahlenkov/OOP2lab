#include "vectorN.h"

VectorN::VectorN(int _n)
{
    n = _n;
    cord = new double[n];
    for (int i = 0; i < n; ++i)
    {
        cord[i] = 0;
    }
}

VectorN::~VectorN() 
{
    delete[] cord;
    cord = nullptr;
}


VectorN::VectorN(const VectorN& vect)
{
    cord = new double[vect.n];
    n = vect.n;
    for (int i = 0; i < n; ++i)
    {
        cord[i] = vect.cord[i];
    }
}

VectorN::VectorN(int _n, double* _cord)
{
    n = _n;
    cord = new double[n];
    for (int i = 0; i < n; ++i)
    {
        cord[i] = _cord[i];
    }
}

VectorN VectorN::operator+(VectorN& vect) const
{
    if (n == vect.n)
    {
        VectorN res(n);
        for (int i = 0; i < n; ++i)
        {
            res.cord[i] = cord[i] + vect.cord[i];
        }
        return res;
    }
    else
    {
        if (n > vect.n)
        {
            VectorN res(n);
            for (int i = 0; i < n; ++i)
            {
                if (i < vect.n)
                    res.cord[i] = cord[i] + vect.cord[i];
                else
                    res.cord[i] = cord[i];
            }
            return res;

        }
        else
        {
            VectorN res(vect.n);
            for (int i = 0; i < vect.n; ++i)
            {
                if (i < n)
                    res.cord[i] = cord[i] + vect.cord[i];
                else
                    res.cord[i] = vect.cord[i];
            }
            return res;
        }
    }
}

VectorN VectorN::operator-(VectorN& vect) const  
{
    if (n == vect.n)
    {
        VectorN res(n);
        for (int i = 0; i < n; ++i)
        {
            res.cord[i] = cord[i] - vect.cord[i];
        }
        return res;
    }
    else
    {
        if (n > vect.n) 
        {
            VectorN res(n);
            for (int i = 0; i < n; ++i)
            {
                if (i < vect.n)
                    res.cord[i] = cord[i] - vect.cord[i];
                else
                    res.cord[i] = cord[i];
            }
            return res;
            
        }
        else 
        {
            VectorN res(vect.n);
            for (int i = 0; i < vect.n; ++i)
            {
                if (i < n)
                    res.cord[i] = cord[i] - vect.cord[i];
                else
                    res.cord[i] = vect.cord[i];
            }
            return res;
        }
    }
}

bool VectorN::operator==(const VectorN& vect)
{
    if (n != vect.n)
        return false;
    for (int i = 0; i < n; ++i) 
    {
        if (cord[i] != vect.cord[i])
            return false;
    }
    return true;
}

void VectorN::incDim(double val)
{
    double* temp = new double[n + 1];
    for (int i = 0; i < n; ++i)
    {
        temp[i] = this->cord[i];
    }
    temp[n] = val;

    delete[] this->cord;
    this->cord = temp;
    this->n += 1;
}

void VectorN::decDim() 
{
    if (this->n > 1) 
    {
        double* temp = new double[n-1];
        for (int i = 0; i < n-1; ++i)
        {
            temp[i] = this->cord[i];
        }

        delete[] this->cord;
        this->cord = temp;
        this->n -= 1;
    }
}
VectorN& VectorN::multip(double val)
{
    for (int i = 0; i < n; ++i) 
    {
        cord[i] *= val;
    }
    return *this;
}

VectorN& VectorN::operator=(const VectorN& vect)
{
    if (this == &vect)
        return *this;

    delete[] cord;
    
    n = vect.n;
    cord = new double[n];
    for (int i = 0; i < n; ++i) 
    {
        cord[i] = vect.cord[i];
    }
    
    return *this;
}

std::ostream& operator<<(std::ostream& os, const VectorN& vect) {
    os << "(";
    for (int i = 0; i < vect.n; ++i) {
        os << vect.cord[i];
        if (i != vect.n - 1) {
            os << ", ";
        }
    }
    os << ")";
    return os;
}

std::istream& operator>>(std::istream& is, VectorN& vect) {
    for (int i = 0; i < vect.n; ++i) {
        is >> vect.cord[i];
    }
    return is;
}

bool VectorN::setN(int _n) 
{
    if (_n < 1)
        return false;
    
    double* temp = new double[_n];
    for (int i = 0; i < _n; ++i) 
    {
        if (n > _n)
            temp[i] = cord[i];
        else
            if (i < n)
                temp[i] = cord[i];
            else
                temp[i] = 0;
    }
    n = _n;
    delete[] cord;
    cord = temp;
    return true;
}

bool VectorN::setCord(int _n, double val) 
{
    if (_n > n)
        return false;
    else
    {
        cord[_n - 1] = val;
        return true;
    }
}
