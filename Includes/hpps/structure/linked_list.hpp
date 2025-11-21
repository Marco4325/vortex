#pragma once

namespace vtx{

    namespace structure{
        template<typename T>
        class linked_list;
    }

    namespace utils{
        template<typename U>
        void print_sequence( vtx::structure::linked_list<U>*& _list );
    }

    namespace structure{

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
                void clear();

                template<typename U>
                friend void vtx::utils::print_sequence( const vtx::structure::linked_list<U>& _list );    
        };

    }
}

#include "../../../Concretes/structure/linked_list/linked_list.tpp"