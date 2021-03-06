#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

//#define OMEGA 72

class vector
{
    public:
        int* data;
        int tamano;
        static const int OMEGA = 71;
    
        vector();
        vector(int* value, int n);
	vector(int n, int tam);
        void set(int i, int value);
        int get(int i);
        int size();
        ~vector();

        bool zeros();

        void operator =(const vector &v1);
	void operator =(vector* v1);
        vector& operator *(const vector &v1);
        vector& operator +(const vector &v1);
        vector& operator -(const vector &v1);
        void operator +=(const vector &v1);
        void operator -=(const vector &v1);

	bool operator >=(const vector &v1);
	bool operator >(const vector &v1);
    vector mayor(const vector &v1);
	bool operator <=(const vector &v1);
	bool operator <(const vector &v1);
	bool operator ==(const vector &v1);
};

bool operator >=(const vector &v0, const vector &v1);
bool operator >(const vector &v0, const vector &v1);
bool operator <=(const vector &v0, const vector &v1);
bool operator <(const vector &v0, const vector &v1);
bool operator ==(const vector &v0, const vector &v1);


//Test!!

#endif // VECTOR_H_INCLUDED
