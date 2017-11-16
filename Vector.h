#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

class vector
{
    private:
        int* data;
        int tamano;
    public:
        vector();
        vector(int* value, int n);
        void set(int i);
        void get(int i);
        int size();
        ~vector();

        vector& operator =(const vector &v1);
        vector& operator *(const vector &v1);
        vector& operator +(const vector &v1);
        vector& operator -(const vector &v1);
        vector& operator +=(const vector &v1);
        vector& operator -=(const vector &v1);


};


#endif // VECTOR_H_INCLUDED
