#include "../../../Includes/hpps/structure/vector.hpp"
#include <algorithm>

namespace vtx{

        template<typename T>
        vector<T>::vector( std::initializer_list<T> _array ){
            this->array_size = _array.size();
            this->array_max_size = _array.size();
            this->array = new T[array_max_size];
            int counter = 0;
            for( T element : _array )
                this->array[counter++] = element;

        }

        template<typename T>
        vector<T>::vector( T* _array, int _size ){
            this->array_size = _size;
            this->array_max_size = _size;            
            this->array = new T[array_max_size];
            for(int i = 0; i < _size; i++)
                this->array[i] = _array[i];
        }
        
        template<typename T>
        vector<T>::vector( int _size ){
            this->array_size = _size;
            this->array_max_size = _size;
            this->array = new T[array_max_size];
        }

        template<typename T>
        vector<T>::vector(){
            this->array_size = 0;
            this->array_max_size = 0;
            this->array = new T[array_max_size];
        }

        template<typename T>
        vector<T>::~vector(){
            this->clear();
        }
        
}