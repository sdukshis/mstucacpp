// DynArray (динамический массив)

#include <stdio.h>
#include <utility>

class DynArray {
private:
    int *data;
    int size;

public:
    DynArray() {
        data = nullptr; // c++ data =  nullptr;
        size = 0;
    }

    DynArray(int n) {
        data = new int[n];
        size = n;
    }

    DynArray(int n, int val) {
        data = new int[n];
        size = n;
        for (int i = 0; i < size; ++i) {
            data[i] = val;
        }
    }
    
    
    DynArray(const DynArray &other) {
        printf("DynArra::copy ctor\n");
        size = other.size;
        data = size ? new int[size] : nullptr;
        for (int i = 0; i < other.size; ++i) {
            data[i] = other.data[i];
        }
    }

    DynArray(DynArray &&other) {
        printf("DynArra::move ctor\n");
        size = other.size;
        data = other.data;
        other.size = 0;
        other.data = nullptr;
    }

    ~DynArray() {
        printf("DynArra::dtor\n");
        if (size) {
            delete[] data;
        }
    }

    DynArray & operator=(const DynArray &other) {
        printf("DynArra::copy =\n");
        if (this != &other) {
            if (size) {
                delete[] data;
            }
            size = other.size;
            data = size ? new int[size] : nullptr;
            for (int i = 0; i < other.size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    DynArray & operator=(DynArray &&other) {
        printf("DynArra::move =\n");
        size = other.size;
        data = other.data;
        other.size = 0;
        other.data = nullptr;

        return *this;
    }

    int getsize() const {
        return size;
    }

    int & operator[](int index) {
        return data[index];
    }

    const int & operator[](int index) const {
        return data[index];
    }

    // friend function 
    friend bool operator==(const DynArray &lhs, const DynArray &rhs);
};

bool operator==(const DynArray &lhs, const DynArray &rhs) {
    if (lhs.size != rhs.size) {
        return false;
    }
    for (int i = 0; i < lhs.size; ++i) {
        if (lhs.data[i] != rhs.data[i]) {
            return false;
        }
    }
    return true;
}          

void print(const DynArray &a) {
    printf("[");
    for (int i = 0; i < a.getsize(); ++i) {
        printf("%d ", a[i]);
    }
    printf("]\n");
}

DynArray sequence(size_t n) {
    DynArray result(n);
    for (int i = 0; i < result.getsize(); ++i) {
        result[i] = i + 1;
    }
    return result;
}



int main(int argc, char const *argv[])
{
    // for (int i = 0; i < 100000000; ++i) {
    //     DynArray a(10000000);
    // }

    // DynArray digits;
    // print(digits);
    // for (int i = 0; i < digits.getsize(); ++i) {
    //     digits[i] = i;
    // }
    // print(digits);

    // DynArray copy(digits); // = digits;

    // for (int i = 0; i < copy.getsize(); ++i) {
    //     copy[i] += 1;
    // }
    // print(copy);
    // print(digits);   

    DynArray result;
    print(result);
    result = sequence(15);
    print(result);

    DynArray copy;
    copy = result;
    copy[0] += 1;
    if (copy == result) {
        printf(" copy and result are equal\n");
    }
    print(result);

    /* code */
    return 0;
}