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

    using iterator        = T*;               
    using const_iterator  = const T*;
    using size_type       = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference       = T&;               
    using const_reference = const T&;   
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    // Constructor
    /**
     * @brief Default construktorius, sukuria tuscia vektoriu
     */
    Vektorius() : data(nullptr), sz(0), cap(0) {}
    
    /**
     * @brief Konstruktorius, sukuria vektoriu su nurodytu dydziu
     * @param size - norimas dydis
     */
    Vektorius(size_t size) : sz(size), cap(size) {
        data = new T[cap];
        for (size_t i = 0; i < sz; ++i) {
            data[i] = T();
        }
    }

    /**
     * @brief Konstruktorius, sukuria vektoriu su nurodytu dydziu ir uzpildo jį nurodyta reiksme
     * @param size - norimas dydis
     * @param value - reiksme, kuria uzpildomas vektorius
     */
    Vektorius(size_t size, const T& value) : sz(size), cap(size) {
        data = new T[cap];
        for (size_t i = 0; i < sz; ++i) {
            data[i] = value;
        }
    }

        /**
     * @brief Konstruktorius su initializer_list
     * @param ilist - sąrašas pradinių reikšmių
     */
    Vektorius(std::initializer_list<T> ilist) : sz(ilist.size()), cap(ilist.size()) {
        data = new T[cap];
        size_t i = 0;
        for (const auto& val : ilist) {
            data[i++] = val;
        }
    }


    /**
     * @brief Destruktorius
     */
    ~Vektorius() {
        delete[] data;
    }

    /**
     * @brief Copy constructorius
     */
    Vektorius(const Vektorius& other) {
        sz = other.sz;
        cap = other.cap;
        data = new T[cap];
        for (size_t i = 0; i < sz; ++i) {
            data[i] = other.data[i];
        }
    }

    /**
     * @brief Copy assignment operatorius
     */
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

    /**
     * @brief Move constructorius
     */
    Vektorius(Vektorius&& other) noexcept {
        data = other.data;
        sz = other.sz;
        cap = other.cap;
        other.data = nullptr;
        other.sz = other.cap = 0;
    }

    /**
     * @brief Move assignment operatorius
     */
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
    
    /**
     * @brief Swap funkcija
     * @param other - kitas vektorius
     */
    void swap(Vektorius& other) {
        std::swap(data, other.data);
        std::swap(sz, other.sz);
        std::swap(cap, other.cap);
    }

    /**
     * @brief Priskiria vektoriui nauja reiksme
     * @param count - norimas dydis
     * @param value - reiksme, kuria uzpildomas vektorius
     */
    void assign(size_t count, const T& value ){

        if (count > cap) {
            reallocate(count);
        }
        for (int i = 0; i < count; ++i) {
            data[i] = value;
        }
        sz = count;
    }

    /**
     * @brief Priskiria vektoriui nauja reiksme
     * @param first - iteratorius, nurodantis pradzia
     * @param last - iteratorius, nurodantis pabaiga
     */
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

    /**
     * @brief Priskiria vektoriui nauja reiksme
     * @param ilist - inicializavimo sarasas
     */
    void assign( std::initializer_list<T> ilist ) {
        size_t count = ilist.size();
        if (count > cap) {
            reallocate(count);
        }
        size_t i = 0;
        for (const auto& item : ilist) {
            data[i++] = item;
        }
        sz = count;
    }

    /**
     * @brief Sumažina vektoriaus talpą iki jo dydžio
     */
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

    /**
     * @brief Ištrina elementą iš vektoriaus
     * @param pos - iteratorius, nurodantis elementą, kurį reikia ištrinti
     * @return iteratorius, nurodantis į elementą po ištrinto
     */
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
    
    /**
     * @brief Ištrina elementus iš vektoriaus
     * @param first - iteratorius, nurodantis nuo kur trinti
     * @param last - iteratorius, nurodantis iki kur trinti
     * @return iteratorius, nurodantis į elementą po ištrinto
     */
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

    /**
     * @brief Įterpia elementą į vektorių
     * @param pos - iteratorius, nurodantis vietą, kur reikia įterpti
     * @param value - reiksme, kurią reikia įterpti
     * @return iteratorius, nurodantis į įterptą elementą
     */
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

    /**
     * @brief Įterpia elementą į vektorių naudodamas move semantika
     * @param pos - iteratorius, nurodantis vietą, kur reikia įterpti
     * @param value - reiksme, kurią reikia įterpti
     * @return iteratorius, nurodantis į įterptą elementą
     */
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

    /**
     * @brief Įterpia kelis elementus į vektorių
     * @param pos - iteratorius, nurodantis vietą, kur reikia įterpti
     * @param count - kiek elementų reikia įterpti
     * @param value - reiksme, kurią reikia įterpti
     * @return iteratorius, nurodantis į pirmą įterptą elementą
     */
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

    /**
     * @brief Įterpia kelis elementus į vektorių per pointerius
     * @param pos - iteratorius, nurodantis vietą, kur reikia įterpti
     * @param first - iteratorius, nurodantis duomenu pradzia
     * @param last - iteratorius, nurodantis duomenu pabaiga
     * @return iteratorius, nurodantis į pirmą įterptą elementą
     */
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

    /**
     * @brief sukuriamas elementą į vektorių su emplace
     * @param pos - iteratorius, nurodantis vietą, kur reikia įterpti
     * @param args - argumentai, kuriuos reikia perduoti elementui
     * @return iteratorius, nurodantis į įterptą elementą
     */
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


    /**
     * @brief Prideda elementą į vektoriaus gala
     * @param value - reiksme, kurią prides
     */
    void push_back(const T& value) {
        if (sz >= cap) {
            reallocate(cap == 0 ? 1 : cap * 2);
        }
        data[sz++] = value;
    }
    
    /**
     * @brief Ištrina paskutinį elementą iš vektoriaus
     * @return - paskutinio elemento reiksme
     */
    void pop_back() {
        if (sz > 0) --sz;
    }

    /**
     * @brief Gražina vektoriaus dydį
     */
    size_t size() const { return sz; }

    /**
     * @brief Gražina vektoriaus talpą
     */
    size_t capacity() const { return cap; }

    /**
     * @brief Gražina ar vektorius yra tuscias
     */
    bool empty() const { return sz == 0; }

    /**
     * @brief Ištrina visus elementus iš vektoriaus
     */
    void clear() {
        for (size_t i = 0; i < sz; ++i) {
            data[i].~T();
        }
        sz = 0;
    }

    /**
     * @brief Rezervuoja talpą vektoriui
     * @param new_cap - nauja talpa
     */
    void reserve(size_t new_cap) {
        if (new_cap > cap)
            reallocate(new_cap);
    }

    /**
     * @brief Pakeičia vektoriaus dydį
     * @param count - naujas dydis
     */
    void resize( size_t count ){
        if (count > cap) {
            reallocate(count);
        }
        for (size_t i = sz; i < count; ++i) {
            data[i] = T();
        }
        sz = count;
    }


    /**
     * @brief Gražina elementą pagal nurodytą indeksą
     * @param pos - indeksas
     * @return - elementas
     * @throw std::out_of_range - jei indeksas yra už ribų
     */
    reference at( size_type pos ){
        if (pos >= sz) {
            throw std::out_of_range("Index out of range");
        }
        return data[pos];
    }

    /**
     * @brief Gražina elementą pagal nurodytą indeksą
     * @param pos - indeksas
     * @return - elementas
     * @throw std::out_of_range - jei indeksas yra už ribų
     */
    const_reference at( size_type pos ) const {
        if (pos >= sz) {
            throw std::out_of_range("Index out of range");
        }
        return data[pos];
    }


    /**
     * @brief Gražina elementą pagal nurodytą indeksą
     * @param index - indeksas
     * @return - elementas
     */
    T& operator[](size_t index) {
        return data[index];
    }

    /**
     * @brief Gražina elementą pagal nurodytą indeksą
     * @param index - indeksas
     * @return - elementas
     */
    const T& operator[](size_t index) const {
        return data[index];
    }

    /**
     * @brief Operatorius, lyginantis du vektorius
     * @param other - kitas vektorius
     * @return - true, jei vektoriai yra lygūs
     */
    bool operator==( const Vektorius<T>& other ) const {
        if (sz != other.sz) return false;
        for (size_t i = 0; i < sz; ++i) {
            if (data[i] != other.data[i]) return false;
        }
        return true;
    }

    /**
     * @brief Operatorius, lyginantis du vektorius
     * @param other - kitas vektorius
     * @return - true, jei vektoriai yra nelygūs
     */
    bool operator!=( const Vektorius<T>& other ) const {
        return !(*this == other);
    }

    /**
     * @brief Operatorius, lyginantis du vektorius
     * @param other - kitas vektorius
     * @return - true, jei pirmas vektorius mažesnis už antrą
     */
    bool operator<( const Vektorius<T>& other ) const {
        for (size_t i = 0; i < std::min(sz, other.sz); ++i) {
            if (data[i] < other.data[i]) return true;
            if (data[i] > other.data[i]) return false;
        }
        return sz < other.sz;
    }

    /**
     * @brief Operatorius, lyginantis du vektorius
     * @param other - kitas vektorius
     * @return - true, jei pirmas vektorius mažesnis arba lygus antram
     */
    bool operator<=( const Vektorius<T>& other ) const {
        for (size_t i = 0; i < std::min(sz, other.sz); ++i) {
            if (data[i] < other.data[i]) return true;
            if (data[i] > other.data[i]) return false;
        }
        return sz <= other.sz;
    }

    /**
     * @brief Operatorius, lyginantis du vektorius
     * @param other - kitas vektorius
     * @return - true, jei pirmas vektorius didesnis už antrą
     */
    bool operator>( const Vektorius<T>& other ) const {
        for (size_t i = 0; i < std::min(sz, other.sz); ++i) {
            if (data[i] < other.data[i]) return false;
            if (data[i] > other.data[i]) return true;
        }
        return sz > other.sz;
    }    

    /**
     * @brief Operatorius, lyginantis du vektorius
     * @param other - kitas vektorius
     * @return - true, jei pirmas vektorius didesnis arba lygus antram
     */
    bool operator>=( const Vektorius<T>& other ) const {
        for (size_t i = 0; i < std::min(sz, other.sz); ++i) {
            if (data[i] < other.data[i]) return false;
            if (data[i] > other.data[i]) return true;
        }
        return sz >= other.sz;
    } 

    /**
     * @brief Gražina iteratorių, nurodantį į pirmą vektoriaus elementą
     * @return - iteratorius, nurodantis į pirmą elementą
     */
    iterator begin() { return data; }
    const_iterator begin() const { return data; }
    const_iterator cbegin() const { return data; }

    /**
     * @brief Gražina  atbula iteratorių, nurodantį į paskutinį vektoriaus elementą
     * @return - atbulas iteratorius, nurodantis į paskutinį elementą
     */
    reverse_iterator rbegin(){ return reverse_iterator(end()); }
    const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
    const_reverse_iterator crbegin() const noexcept { return const_reverse_iterator(end()); }

    /**
     * @brief Gražina iteratorių, nurodantį į vektoriaus pabaigą
     * @return - iteratorius, nurodantis į vektoriaus pabaigą
     */
    iterator end() { return data + sz; }
    const_iterator end() const { return data + sz; }
    const_iterator cend() const { return data + sz; }

    /**
     * @brief Gražina atbula iteratorių, nurodantį į vektoriaus pabaigą
     * @return - atbulas iteratorius, nurodantis į vektoriaus pabaigą
     */
    reverse_iterator rend() { return reverse_iterator(begin()); }
    const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }
    const_reverse_iterator crend() const noexcept { return const_reverse_iterator(begin()); }

    /**
     * @brief Gražina pirmą elementą
     * @return - pirmas elementas
     */
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

    /**
     * @brief Gražina paskutinį elementą
     * @return - paskutinis elementas
     */
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

    /**
     * @brief Gražina vektoriaus duomenų masyvą (taspats kaip std::vector::data())
     * @return - duomenų masyvas
     */
    T* storage() {
        return data;
    }
    const T* storage() const {
        return data;
    }


};

#endif // VEKTORIUS_H