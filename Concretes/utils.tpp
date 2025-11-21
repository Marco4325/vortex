#include "../Includes/hpps/utils.hpp"
#include <iostream>

template<typename T>
void vtx::utils::print_sequence( const vtx::structure::vector<T>& _vector ){
    std::cout << "\nVector: ";
    for(int i = 0; i < _vector.size(); i++){
        std::cout << _vector[i];
        if( i < (_vector.size() - 1) )
            std::cout << " | ";
    }std::cout << "\n\n";
}

template<typename U>
void vtx::utils::print_sequence( const vtx::structure::linked_list<U>& _list ){
    auto* aux_node = _list.head;
    
    int counter = 0;
    std::cout << "\nList: ";
    while(aux_node){
        std::cout << aux_node->element;
        
        if( counter < (_list.list_size - 1))
            std::cout << " | ";

        aux_node = aux_node->next_node;
        counter++;
    }std::cout << "\n\n";

}