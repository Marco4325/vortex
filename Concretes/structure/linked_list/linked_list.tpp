#include "../../../Includes/structure/linked_list.hpp"
#include <iostream>

namespace vtx{
    
    namespace structure{
        
        template<typename T>
        linked_list<T>::linked_list(){
            this->head = nullptr;
            this->tail = nullptr;
            this->list_size = 0;
        }
        
        template<typename T>
        linked_list<T>::~linked_list(){
            this->clear();
        }
        
        template<typename T>
        void linked_list<T>::clear(){
            node<T>* aux_node = this->head;
            while(aux_node){
                node<T>* next_node = aux_node->next_node;
                delete aux_node;
                aux_node = next_node;
            }
        
            this->head = nullptr;
            this->tail = nullptr;
            this->list_size = 0;
        }

        template<typename T>
        int linked_list<T>::size(){
            return this->list_size;
        }

        template<typename T>
        void linked_list<T>::push_back(T _element){

            node<T>* new_node = new node<T>;
            new_node->element = _element;

            if(this->head == nullptr){
                this->head = new_node;
                this->tail = new_node;
                this->list_size++;
                return;
            }
            
            this->tail->next_node = new_node;
            this->tail = new_node;
            this->list_size++;
        }

        template<typename T>
        void linked_list<T>::push_front(T _element){

            node<T>* new_node = new node<T>;
            new_node->element = _element;

            if(this->head == nullptr){
                this->head = new_node;
                this->tail = new_node;
                this->list_size++;
                return;
            }
            
            new_node->next_node = this->head;
            this->head = new_node;
            this->list_size++;
        }

        template<typename T>
        void linked_list<T>::pop_back(){
        if(this->list_size == 0) return;
            node<T>* aux = this->head;
            
            if(this->list_size == 1){
                delete aux;
                this->head = nullptr;
                this->tail = nullptr;
                this->list_size--;
                return;
            }

            while(aux->next_node->next_node)
                aux = aux->next_node;

            delete aux->next_node;
            aux->next_node = nullptr;
            this->tail = aux;
            this->list_size--;
        }

        template<typename T>
        void linked_list<T>::pop_front(){
            if(this->head == nullptr) return;

            node<T>* temporary_node = this->head;
            this->head = this->head->next_node;
            delete temporary_node;

            this->list_size--;
        }

        template<typename T>
        void linked_list<T>::insert_at(int _pos, T _element){
        if(_pos < 0 || _pos > this->list_size) return;
            node<T>* new_node = new node<T>, *aux = this->head;
            new_node->element = _element;

            if( _pos == 0 ){
                this->push_front(_element);
                return;
            }

            if( _pos == this->list_size ){
                this->push_back(_element);
                return;
            }

            for(int i = 0; i < (_pos - 1); i++)
                aux = aux->next_node;
            
            new_node->next_node = aux->next_node;
            aux->next_node = new_node;
            this->list_size++;
        }

        template<typename T>
        void linked_list<T>::remove_at(int _pos){
        if(_pos < 0 || _pos >= this->list_size) return;
            node<T>* aux = this->head;

            if( _pos == 0 ){
                this->pop_front();
                return;
            }

            if( _pos == this->list_size ){
                this->pop_back();
                return;
            }

            for(int i = 0; i < (_pos - 1); i++)
                aux = aux->next_node;
            
            node<T>* temporary_node = aux->next_node;
            aux->next_node = aux->next_node->next_node;
            delete temporary_node;
            this->list_size--;
        }

        template<typename T>
        void linked_list<T>::print_list(){
            node<T>* aux_node = this->head;
            std::cout << "List: ";
            while(aux_node){
                std::cout << aux_node->element << " ";
                aux_node = aux_node->next_node;
            }
            std::cout << "\n\n";
        }

    }
}
