#include <iostream>
using namespace std;

class VecImpl
{
public:
    VecImpl(int s) :
        sz{s},
        elem{new double[s]}
    {
        for (int i = 0; i < s; ++i)
            elem[i] = 0;
    }

    VecImpl() :
        sz{0},
        elem{nullptr}
    {}

    ~VecImpl() {
        delete[] elem;
    }

    int size() const {
        return sz;
    }

    void setSize(int size) {
        sz = size;
        elem = new double[size];
    }

    double get(int index) const {
        return elem[index];
    }

    void set(int index, double val) {
        elem[index] = val;
    }

private:
    int sz;
    double* elem;

};



int main()
{
    cout << "Hello World!" << endl;

    VecImpl v(3);
    v.set(0, 12);
    cout << v.get(0) << endl;

    {
        VecImpl* vec = new VecImpl(5);
        vec->set(0,12);
        cout << vec->get(0) << endl;
        delete vec;
    }

    {
        VecImpl* vec2 = new VecImpl[4];
        vec2->setSize(3);
        vec2->set(0,13);
        cout << vec2->get(0) << endl;

        (vec2+1)->setSize(4);
        (vec2+1)->set(0,56);
        cout << (vec2+1)->get(0) << endl;

        delete[] vec2;
    }

    {
        void* pv = new int;
        void* pv1 = new double[10];
        int* pi = static_cast<int*>(pv);
        cout << pv << " : " << pi << endl;
        *pi = 67;
    }




    return 0;
}
