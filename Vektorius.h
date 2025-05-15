#include "std.h"

#ifndef VEKTORIUS_H
#define VEKTORIUS_H

#include <iostream>
#include <iterator>

template <typename T>
class Vektorius {
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

    using iterator        = T*;               // Iterator is a pointer to T
    using const_iterator  = const T*;
    using size_type       = std::size_t;
    using reference       = T&;               // Reference to T
    using const_reference = const T&;   // Const reference to T
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    // Constructor
    Vektorius() : data(nullptr), sz(0), cap(0) {}

    // Destructor
    ~Vektorius() {
        delete[] data;
    }

    // Copy constructor
    Vektorius(const Vektorius& other) {
        sz = other.sz;
        cap = other.cap;
        data = new T[cap];
        for (size_t i = 0; i < sz; ++i) {
            data[i] = other.data[i];
        }
    }

    // Copy assignment
    Vektorius& operator=(const Vektorius& other) {
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
    Vektorius(Vektorius&& other) noexcept {
        data = other.data;
        sz = other.sz;
        cap = other.cap;
        other.data = nullptr;
        other.sz = other.cap = 0;
    }

    // Move assignment
    Vektorius& operator=(Vektorius&& other) noexcept {
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
    

    void swap(Vektorius& other) {
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

    iterator insert( const_iterator pos, const T& value ){
        if (pos < data || pos > data + sz) {
            throw std::out_of_range("Iterator out of range");
        }
        size_t index = pos - data;
        if (sz >= cap) {
            reallocate(cap == 0 ? 1 : cap * 2);
        }
        for (size_t i = sz; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++sz;
        return data + index;
    }

    iterator insert( const_iterator pos, T&& value ){
        if (pos < data || pos > data + sz) {
            throw std::out_of_range("Iterator out of range");
        }
        size_t index = pos - data;
        if (sz >= cap) {
            reallocate(cap == 0 ? 1 : cap * 2);
        }
        for (size_t i = sz; i > index; --i) {
            data[i] = std::move(data[i - 1]);
        }
        data[index] = std::move(value);
        ++sz;
        return data + index;
    }

    iterator insert( const_iterator pos, size_type count, const T& value ){
        if (pos < data || pos > data + sz) {
            throw std::out_of_range("Iterator out of range");
        }
        size_t index = pos - data;
        if (sz + count > cap) {
            reallocate(cap == 0 ? count : cap + count);
        }
        for (size_t i = sz + count - 1; i >= index + count; --i) {
            data[i] = data[i - count];
        }
        for (size_t i = index; i < index + count; ++i) {
            data[i] = value;
        }
        sz += count;
        return data + index;
    }

    template< class InputIt, typename = std::enable_if_t<!std::is_integral_v<InputIt>> >
    iterator insert( const_iterator pos, InputIt first, InputIt last ){
        if (pos < data || pos > data + sz) {
            throw std::out_of_range("Iterator out of range");
        }
        size_t index = pos - data;
        size_t count = last - first;
        if (sz + count > cap) {
            reallocate(cap == 0 ? count : cap + count);
        }
        for (size_t i = sz + count - 1; i >= index + count; --i) {
            data[i] = data[i - count];
        }
        for (size_t i = index; i < index + count; ++i) {
            data[i] = *first++;
        }
        sz += count;
        return data + index;
    }

    template< class... Args >
    iterator emplace( const_iterator pos, Args&&... args ){
        if (pos < data || pos > data + sz) {
            throw std::out_of_range("Iterator out of range");
        }
        size_t index = pos - data;
        if (sz >= cap) {
            reallocate(cap == 0 ? 1 : cap * 2);
        }
        for (size_t i = sz; i > index; --i) {
            data[i] = std::move(data[i - 1]);
        }
        new (&data[index]) T(std::forward<Args>(args)...);
        ++sz;
        return data + index;
    }


    void push_back(const T& value) {
        if (sz >= cap) {
            reallocate(cap == 0 ? 1 : cap * 2);
        }
        data[sz++] = value;
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

    void resize( size_t count ){
        if (count > cap) {
            reallocate(count);
        }
        for (size_t i = sz; i < count; ++i) {
            new (&data[i]) T();
        }
        sz = count;

    }

    reference at( size_type pos ){
        if (pos >= sz) {
            throw std::out_of_range("Index out of range");
        }
        return data[pos];
    }

    const_reference at( size_type pos ) const {
        if (pos >= sz) {
            throw std::out_of_range("Index out of range");
        }
        return data[pos];
    }


    T& operator[](size_t index) {
        return data[index];
    }

    const T& operator[](size_t index) const {
        return data[index];
    }

    bool operator==( const Vektorius<T>& other ) const {
        if (sz != other.sz) return false;
        for (size_t i = 0; i < sz; ++i) {
            if (data[i] != other.data[i]) return false;
        }
        return true;
    }

    bool operator!=( const Vektorius<T>& other ) const {
        return !(*this == other);
    }

    bool operator<( const Vektorius<T>& other ) const {
        for (size_t i = 0; i < std::min(sz, other.sz); ++i) {
            if (data[i] < other.data[i]) return true;
            if (data[i] > other.data[i]) return false;
        }
        return sz < other.sz;
    }

    bool operator<=( const Vektorius<T>& other ) const {
        for (size_t i = 0; i < std::min(sz, other.sz); ++i) {
            if (data[i] < other.data[i]) return true;
            if (data[i] > other.data[i]) return false;
        }
        return sz <= other.sz;
    }

    bool operator>( const Vektorius<T>& other ) const {
        for (size_t i = 0; i < std::min(sz, other.sz); ++i) {
            if (data[i] < other.data[i]) return false;
            if (data[i] > other.data[i]) return true;
        }
        return sz > other.sz;
    }    

    bool operator>=( const Vektorius<T>& other ) const {
        for (size_t i = 0; i < std::min(sz, other.sz); ++i) {
            if (data[i] < other.data[i]) return false;
            if (data[i] > other.data[i]) return true;
        }
        return sz >= other.sz;
    } 


    iterator begin() { return data; }
    const_iterator begin() const { return data; }
    const_iterator cbegin() const { return data; }

    reverse_iterator rbegin(){ return reverse_iterator(end()); }
    const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
    const_reverse_iterator crbegin() const noexcept { return const_reverse_iterator(end()); }

    iterator end() { return data + sz; }
    const_iterator end() const { return data + sz; }
    const_iterator cend() const { return data + sz; }

    reverse_iterator rend() { return reverse_iterator(begin()); }
    const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }
    const_reverse_iterator crend() const noexcept { return const_reverse_iterator(begin()); }

    reference front() {
        if (sz == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return data[0];
    }
    const_reference front() const {
        if (sz == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return data[0];
    }

    reference back() {
        if (sz == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return data[sz - 1];
    }
    const_reference back() const {
        if (sz == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return data[sz - 1];
    }

    T* storage() {
        return data;
    }
    const T* storage() const {
        return data;
    }


};

#endif // VEKTORIUS_H