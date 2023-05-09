// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T, int size>
class TPQueue {
 private:
    T* arr;
    int sizeTPQ;
    int first, last;
    int cur;

 public:
    TPQueue():sizeTPQ(size), first(0), last(0), cur(0) {
        arr = new T[sizeTPQ + 1];
    }

    ~TPQueue() {
        delete[] arr;
    }

    void push(const T& value) {
        assert(cur < sizeTPQ);
        if (cur == 0) {
            arr[last++] = value;
            cur++;
        } else {
            int i = last - 1;
            bool op = 0;
            ////////////
            if (i >= first && value.prior > arr[i].prior) {
                while (i >= first && value.prior > arr[i].prior) {
                op = 1;
                arr[i + 1] = arr[i];
                arr[i] = value;
                i--;
                }
            } else {
                arr[last] = value;
            }
            last++;
            cur++;
        }
        if (last > sizeTPQ) {
            last -= sizeTPQ + 1;
        }
    }

    const T& pop() {
        assert(cur > 0);
        cur--;
        if (first > sizeTPQ) {
            first -= sizeTPQ + 1;
        }
        return arr[first++];
    }

    const T& get() {
        assert(cur > 0);
        return arr[first];
    }

    bool isFull() const {
        return cur == sizeTPQ;
    }

    bool isEmpty() const {
        return cur == 0;
    }
};

struct SYM {
    char ch;
    int prior;
};

#endif    // INCLUDE_TPQUEUE_H_
