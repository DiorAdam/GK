#include <iostream>
#include <vector>
#include <list>
#include <string>

template <typename T>
class container{
    public:
        virtual T& operator[](size_t i) const = 0;
        virtual T& back() const = 0;
        virtual T& front() const = 0;
        virtual size_t size() const = 0;
        virtual void push_back(T x) = 0;
        virtual T* begin() const = 0;
        virtual T* end() const = 0;
        ~container(){};
};  

template <typename T>
class vector: public container<T>{
    private:
        T* array;
        size_t sz;
        size_t alloc_sz;
    public:
        vector(){
            array = new T[10];
            alloc_sz = 10;
            sz = 0;
        }

        explicit vector(size_t n){
            array = new T[n];
            alloc_sz = n;
            sz = n;
        }

        size_t size() const override{
            return sz;
        }

        void push_back(T x) override{
            if (alloc_sz > sz){
                array[sz] = x;
            }
            else{
                alloc_sz *= 2;
                T* new_array = new T[alloc_sz];
                std::copy(array, array+sz, new_array);
                new_array[sz] = x;
                delete[] array;
                array = new_array;
            }
            sz++;
        }

        T& operator[](size_t i) const override {
            if (0 <= i && i < sz)
                return array[i];
            throw std::out_of_range{"out of range"};
        }

        T& back() const override {
            return (*this)[sz-1];
        }

        T& front() const override{
            return this->operator[](0);
        }

        T* begin() const override{
            return array;
        }

        T* end() const override{
            return array+sz;
        }

        ~vector(){
            delete[] array;
        }
};

template <typename T>
double avg(container<T>& C){
    T ans = 0;
    for (T d : C)
        ans += d;
    return ans/C.size();
}


int main(){
    vector<double> u;
    vector<int> v(45);

    for (int i=0; i<45; i++){
        u.push_back(i*i);
        v[i] = i*i;
    }
    std::cout << u.front() << "  " << u.back() << '\n';
    std::cout << v.front() << "  " << v.back() << '\n';
    for (int i=10; i<20; i++){
        std::cout << u[i] << "  ";
    }
    std::cout << '\n';
    for (int i=10; i<20; i++){
        std::cout << v[i] << "  ";
    }
    std::cout << '\n';
    try{
        v[46];
    }
    catch(std::out_of_range e){
        std::cout << std::string(e.what()) << '\n';
    }

    std::cout << "average of u: " << avg(u) << '\n';
    std::cout << "average of v: " << avg(v) << '\n';
    return 0;
}

