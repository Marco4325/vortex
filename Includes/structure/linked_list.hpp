#pragma once

namespace vtx{
    namespace structure{

        template<typename T>
        class node{
            public:
                T element;
                node* next_node;      
        };

        template<typename T>
        class linked_list{
            private:
                node<T>* head;
                node<T>* tail;
                int list_size;

            public:
                linked_list();
                ~linked_list();

                void push_back(T _element);
                void push_front(T _element);

                void pop_back();
                void pop_front();

                void insert_at(int _pos, T _element);
                void remove_at(int _pos);

                //void push_back_array(T* _array); TODO
                //void push_front_array(T* _array); TODO

                int size();
                void print_list();
                void clear();
        };

    }
}

#include "../../Concretes/structure/linked_list/linked_list.tpp"