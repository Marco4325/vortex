#pragma once

#include "./structure/linked_list.hpp"
#include "./structure/vector.hpp"

namespace vtx{

    template<typename T>
    void print_sequence( const vtx::vector<T>& _vector );

    template<typename U>
    void print_sequence( const vtx::linked_list<U>& _list );

}

#include "../../Concretes/utils.tpp"