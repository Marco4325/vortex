#pragma once

#include "./structure/linked_list.hpp"
#include "./structure/vector.hpp"

namespace vtx{

    namespace utils{

        template<typename T>
        void print_sequence( vtx::structure::vector<T>& _vector );

        template<typename U>
        void print_sequence( vtx::structure::linked_list<U>*& _list );
        
    }

}

#include "../../Concretes/utils.tpp"