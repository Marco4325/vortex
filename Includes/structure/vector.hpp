#pragma once

#include <initializer_list>

#define CAN_USE_BRACKETS_FOR_READING_MACRO int operator[](int _index) { if (_index >= 0 && _index < this->array_size) { return this->array[_index]; } return -1; }

namespace vtx{

    namespace structure{
 
        template<typename T>
        class vector{
            private:
                T* array;
                int array_size, 
                    array_max_size;
                
            public:
                // CONSTRUCTORS AND DESTRUCTOR
                vector( std::initializer_list<T> _array );
                vector( T* _array, int _size );
                vector( int _size );
                vector();
                ~vector();
                CAN_USE_BRACKETS_FOR_READING_MACRO;

                // FUNCTIONS
                void redimension();

                int size();

                void push( T _element );
                void pop();

                void remove_at( int _pos );
                void insert_at( int _pos, T _element );
                void insert_array_at( int _pos, T* _array, int _array_size );
        };

    }

}

#include "../../Concretes/structure/vector/_vector.tpp"
#include "../../Concretes/structure/vector/vector.tpp"