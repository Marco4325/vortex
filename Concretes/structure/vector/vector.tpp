#include "../../../Includes/structure/vector.hpp"
#include <iostream>

namespace vtx{
    namespace structure{

        // REDIMENSION VECTOR
        template<typename T>
        void vector<T>::redimension(){
        if( this->array_size < this->array_max_size ){ return; }
        
            this->array_max_size += this->array_size;

            T* new_array = new T[ this->array_max_size ];
            for( int i = 0; i < this->array_size; i++)
                new_array[i] = this->array[i];
            
            delete[] this->array;
            this->array = new_array;
        }

        // INCREMENT VECTOR
        template<typename T>
        void vector<T>::push( T _element ){
            if(this->array_size >= this->array_max_size)
                redimension();
            
            this->array[this->array_size] = _element;
            this->array_size++;
        }

        template<typename T>
        void vector<T>::insert_at( int _pos, T _element ){
            if( _pos < 0 ){
                std::cout << "ERROR: Couldn't insert element because given position less than zero!";
                return;
            }
            if( _pos > this->array_size ){
                std::cout << "ERROR: Couldn't insert element because given position is out of range!";
                return;
            }

            this->array_size++;
            
            if(this->array_size >= this->array_max_size)
                redimension();
                
            for(int i = (this->array_size - 1); i > _pos; i-- )
                this->array[i] = this->array[i - 1];

            this->array[_pos] = _element;
        }

        template<typename T>
        void vector<T>::insert_array_at( int _pos, T* _array, int _array_size ){
            if( _pos < 0 ){
                std::cout << "ERROR: Couldn't insert element because given position less than zero!";
                return;
            }
            if( _pos > this->array_size ){
                std::cout << "ERROR: Couldn't insert element because given position is out of range!";
                return;
            }

            this->array_size += _array_size;

            if(this->array_size >= this->array_max_size)
                redimension();
                
            for(int i = (this->array_size - 1); i > _pos; i-- )
                this->array[i] = this->array[i - _array_size];

            for(int i = 0; i < _array_size; i++)
                this->array[i + _pos] = _array[i];
        }

        // DECREMENT VECTOR
        template<typename T>
        void vector<T>::pop(){
            this->array_size--;
        }

        template<typename T>
        void vector<T>::remove_at( int _pos ){
            for(int i = _pos; i < (this->array_size - 1); i++)
                this->array[i] = this->array[i + 1];

            this->array_size--;
        }

        template<typename T>
        void vector<T>::remove_range_at( int _start, int _end ){
            int quantity_at_range = (_end - _start) + 1;
        
            for( int i = _end; i < this->size(); i++ ){
                
            }
        }

        // SIZE
        template<typename T>
        int vector<T>::size(){
            return this->array_size;
        }

        template<typename T>
        void vector<T>::clear(){
            delete[] this->array;
            this->array = nullptr;
            this->array_size = 0;
            this->array_max_size = 0;
        }

    }
}
