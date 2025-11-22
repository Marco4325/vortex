#pragma once

#include <initializer_list>
#include <stdexcept>

#define CAN_USE_BRACKETS_FOR_READING_MACRO T& operator[](int _index) { if (_index >= 0 && _index < this->array_size) { return this->array[_index]; } return -1; }
#define CAN_USE_BRACKETS_FOR_READING_CONST_MACRO const T& operator[](int _index) const { if (_index >= 0 && _index < this->array_size) { return this->array[_index]; } throw std::range_error("ERROR: Accessing invalid memory."); }

namespace vtx{

        template<typename T>
        class linked_list{

            private:
            class node{
                public:
                    T element;
                    node* next_node;      
            };
            
            node* head;
            node* tail;
            int list_size;
            
            public:
                linked_list( std::initializer_list<T> _array );
                linked_list();
                ~linked_list();
                CAN_USE_BRACKETS_FOR_READING_MACRO;
                CAN_USE_BRACKETS_FOR_READING_CONST_MACRO;

                void push_back(T _element);
                void push_front(T _element);

                void pop_back();
                void pop_front();

                void insert_at(int _pos, T _element);
                void remove_at(int _pos);

                //void push_back_array(T* _array); TODO
                //void push_front_array(T* _array); TODO

                int size();
                void clear();

                template<typename U>
                friend void print_sequence( const linked_list<U>& _list );    
        };
}

#include "../../../Concretes/structure/linked_list/linked_list.tpp"