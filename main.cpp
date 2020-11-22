#include <iostream>



using namespace std;



void f1(void);





struct myArray {

    double* Array;

    int size;

    int cap;

    myArray()

    {

        cap = 1;

        size = 0;

        Array = new double;

    }

    myArray(int n)

    {

        cap = n;

        size = 0;

        Array = new double[cap];

    }

     myArray(const double a[], int n) {

        size = n;

        cap = n + 5;

        Array = new double[cap];

        for (int i = 0; i < size; i++) {

            Array[i] = a[i];

        }

    }

    void copy(myArray A) {

        size = A.size;

        cap = A.cap;

        delete[] Array;

        Array = new double[cap];

        for (int i = 0; i < A.size; i++)

            Array[i] = A.Array[i];



    }

    myArray(const myArray& A)

    {

        copy(A);

    }

    myArray operator =(const myArray& A) {

        copy(A);

        return A;

    }

    ~myArray()

    {

        delete[] Array;

    }



    void set(double x) //add X to end of array

    {

        if (size < cap)

        {

            Array[size] = x;

            size++;

        }

        else

        {

            int* temp = new int[cap]; 

            for (int i = 0; i < cap; i++) //set member of this Array to new array named temp

                temp[i] = Array[i];

            delete[] Array; 

            int* Array = new int[cap * 2]; 

            for (int i = 0; i < cap; i++)

                Array[i] = temp[i];

            delete[] temp; //free space of temp with delet that

            cap *= 2; 

            Array[size] = x; //set

            size++;

        }

    }

    void print(void) {

        cout << " size  = " << size << endl;

        for (int i = 0; i < size; i++)

            cout << "a[" << i << "] = " << Array[i] << endl;

    }

    myArray   add(myArray A) {

        myArray B(size);

        for (int i = 0; i < size; i++)

            B.Array[i] = Array[i] + A.Array[i];

        return B;

    }

    myArray   sub(myArray A) {

        myArray B(cap);

        B.size = A.size;

        for (int i = 0; i < A.size; i++)

            B.Array[i] = Array[i] - A.Array[i];

        return B;

    }

    myArray   dot(myArray A) {

        myArray B(cap);

        for (int i = 0; i < size; i++)

            B.Array[i] = Array[i] * A.Array[i];

        return B;

    }

};





int main(void)

{

    f1();

    return 0;

}

void f1(void) {



    double x[]{ 1,2,3 };

    myArray a(x, 3), b(3);

    b.set(5.6);

    b.set(7.5);

    myArray c = a;

    cout << endl << "a:" << endl;

    a.print();

    cout << endl << "b:" << endl;

    b.print();

    cout << endl << "c:" << endl;

    c.print();

    b = a = c;

    cout << endl << "a:" << endl;

    a.print();

    cout << endl << "b:" << endl;

    b.print();

    cout << endl << "c:" << endl;

    c.print();



}

