#pragma once

#include <initializer_list>
#include <stdexcept>

#define CAN_USE_BRACKETS_FOR_READING_MACRO T& operator[](int _index) { if (_index >= 0 && _index < this->array_size) { return this->array[_index]; } return -1; }
#define CAN_USE_BRACKETS_FOR_READING_CONST_MACRO const T& operator[](int _index) const { if (_index >= 0 && _index < this->array_size) { return this->array[_index]; } throw std::range_error("ERROR: Accessing invalid memory."); }

namespace vtx{
 
        template<typename T>
        class vector{
            private:
                T* array;
                int array_size, 
                    array_max_size;
                void redimension();
                
            public:
                // CONSTRUCTORS AND DESTRUCTOR
                vector( std::initializer_list<T> _array );
                vector( T* _array, int _size );
                vector( int _size );
                vector();
                ~vector();
                CAN_USE_BRACKETS_FOR_READING_MACRO;
                CAN_USE_BRACKETS_FOR_READING_CONST_MACRO;
                // FUNCTIONS

                int size() const;

                void push( T _element );
                void pop();

                void remove_at( int _pos );
                void remove_range_at( int _start, int _end);
                void insert_at( int _pos, T _element );
                void insert_array_at( int _pos, T* _array, int _array_size );
        
                void clear();
        };

}

#include "../../../Concretes/structure/vector/_vector.tpp"
#include "../../../Concretes/structure/vector/vector.tpp"