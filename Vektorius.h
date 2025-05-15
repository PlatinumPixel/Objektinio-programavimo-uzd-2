#include "std.h"

#ifndef VEKTORIUS_H
#define VEKTORIUS_H

#include <iostream>

template <typename T>
class ManoVektorius {
private:

    T* data;
    size_t sz;
    size_t cap;

    void reallocate(size_t new_cap) {
        T* new_data = new T[new_cap];
        for (size_t i = 0; i < sz; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        cap = new_cap;
    }

public:

    using iterator = T*;               // Iterator is a pointer to T
    using const_iterator = const T*;

    // Constructor
    ManoVektorius() : data(nullptr), sz(0), cap(0) {}

    // Destructor
    ~ManoVektorius() {
        delete[] data;
    }

    // Copy constructor
    ManoVektorius(const ManoVektorius& other) {
        sz = other.sz;
        cap = other.cap;
        data = new T[cap];
        for (size_t i = 0; i < sz; ++i) {
            data[i] = other.data[i];
        }
    }

    // Copy assignment
    ManoVektorius& operator=(const ManoVektorius& other) {
        if (this != &other) {
            delete[] data;
            sz = other.sz;
            cap = other.cap;
            data = new T[cap];
            for (size_t i = 0; i < sz; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Move constructor
    ManoVektorius(ManoVektorius&& other) noexcept {
        data = other.data;
        sz = other.sz;
        cap = other.cap;
        other.data = nullptr;
        other.sz = other.cap = 0;
    }

    // Move assignment
    ManoVektorius& operator=(ManoVektorius&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            sz = other.sz;
            cap = other.cap;
            other.data = nullptr;
            other.sz = other.cap = 0;
        }
        return *this;
    }
    

    void swap(ManoVektorius& other) {
        std::swap(data, other.data);
        std::swap(sz, other.sz);
        std::swap(cap, other.cap);
    }

    void assign(size_t count, const T& value ){

        if (count > cap) {
            reallocate(count);
        }
        for (int i = 0; i < count; ++i) {
            data[i] = value;
        }
        sz = count;
    }

    template< typename InputIt, typename = std::enable_if_t<!std::is_integral_v<InputIt>> >
    void assign( InputIt first, InputIt last ){
        size_t count = last - first;
        if (count < 0) {
            throw std::out_of_range("Iterator out of range");
        }
        if (count > cap) {
            reallocate(count);
        }
        for (size_t i = 0; i < count; ++i) {
            data[i] = *first++;
        }
        sz = count;
    }

    void shrink_to_fit() {
        if (sz < cap) {
            T* new_data = new T[sz];
            for (size_t i = 0; i < sz; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            cap = sz;
        }
    }

    iterator erase( const_iterator pos ){
        if (pos < data || pos >= data + sz) {
            throw std::out_of_range("Iterator out of range");
        }
        size_t index = pos - data;
        for (size_t i = index; i < sz - 1; ++i) {
            data[i] = data[i + 1];
        }
        --sz;
        return data + index;
    }
    
    iterator erase( const_iterator first, const_iterator last ){
        if (first < data || last > data + sz) {
            throw std::out_of_range("Iterator out of range");
        }
        size_t start = first - data;
        size_t end = last - data;
        size_t count = end - start;
        for (size_t i = start; i < sz - count; ++i) {
            data[i] = data[i + count];
        }
        sz -= count;
        return data + start;
    }



    void push_back(const T& value) {
        if (sz >= cap) {
            reallocate(cap == 0 ? 1 : cap * 2);
        }
        data[sz++] = value;
        cout << "Pushed back " << value << endl;
    }

    void pop_back() {
        if (sz > 0) --sz;
    }

    size_t size() const { return sz; }
    size_t capacity() const { return cap; }
    bool empty() const { return sz == 0; }

    void clear() {
        delete[] data;
        data = nullptr;
        sz = 0;
        cap = 0;
    }

    void reserve(size_t new_cap) {
        if (new_cap > cap)
            reallocate(new_cap);
    }

    void resize(size_t new_size, const T& default_value = T()) {
        reserve(new_size);
        for (size_t i = sz; i < new_size; ++i)
            data[i] = default_value;
        sz = new_size;
    }

    T& operator[](size_t index) {
        return data[index];
    }

    const T& operator[](size_t index) const {
        return data[index];
    }

    T* begin() { return data; }
    T* end() { return data + sz; }
};

#endif // VEKTORIUS_H