//name: Patrick Vanegas//empl id: 15172605
#include <iostream>
#include <cassert>
#include "sequence2.h"

using namespace std;

namespace main_savitch_4 { 

sequence::sequence(size_type initial_capacity) { 
  data = new value_type[initial_capacity]; 
  capacity = initial_capacity; current_index = 0; 
  used = 0; 
}
 sequence::sequence(const sequence& source) { 
     if (this == &source) return; 
     
     data = new value_type[source.capacity]; 
     size_type i; 
     
     for (i = 0; i < source.used; i++) {
        data[i] = source.data[i]; 
     }
     
     used = source.used; 
     current_index = source.current_index; 
     capacity = source.capacity;  
 }  
 
 sequence::~sequence() { 
     delete[] data; 
     used = 0; 
     current_index = 0;
     capacity = 0; 
 }
 
 void sequence::resize(size_type new_capacity) {  
      value_type *larger_array;
      
      if (new_capacity == capacity) 
          return; 
          
      if (new_capacity < used) 
         new_capacity = used; 
         larger_array = new value_type[new_capacity];  
         size_type i; 
         
             for (i = 0; i < used; i++) { 
                larger_array[i] = data[i]; 
             }
             
       delete[] data; 
       data = larger_array; 
       capacity = new_capacity; 
 }  
 
 void sequence::start() { 
 current_index = 0; 
 }
 
 void sequence::advance() { 
  assert(is_item());  
  current_index++;   
 } 
 
 bool sequence::is_item() const { 
 return (current_index < used); 
 }
 
 sequence::size_type sequence::size() const { 
 return used; 
 }
 
 void sequence::insert(const value_type& entry) { 
 if (used >= capacity) 
    resize(2 * capacity); 
 
   assert(used < capacity);  
   size_type i; 
   
   if (!is_item()) 
      current_index = 0; 
 
 for (i = used; i > current_index; i--) 
   data[i] = data[i - 1]; 
   data[current_index] = entry; used++; 
 }
 
 void sequence::attach(const value_type& entry) { 
   if (used >= capacity) 
    resize(2 * capacity); 
    
 //in case I need more space 
 assert(size() < capacity);  
 size_type i; 
 
 if (!is_item()) 
  data[current_index] = entry; 
 else {
     for (i = used; i > current_index + 1; i--) 
     data[i] = data[i - 1];
     data[current_index + 1] = entry; current_index++; } used++; 
     } 
 }  
 
 void sequence::remove_current() { 
 assert(is_item());  
   for (size_type i = current_index + 1; i < used; i++) 
   data[i - 1] = data[i]; used--;   
 }  
 
 void sequence::operator=(const sequence& source) {
 if (this == &source) return; //self assignment  
   value_type* new_data; 
 if (capacity != source.capacity) { 
     new_data = new value_type[source.capacity]; 
     delete[] data;  
     data = new_data; 
     capacity = source.capacity; 
 
 }
 // Copy the data from the source array: 
 used = source.used; 
 size_type i; 
 for (i = 0; i < source.used; i++) {
      data[i] = source.data[i]; 
  } 
  current_index = source.current_index; 
  
}
 sequence::value_type sequence::current() const { 
 assert(is_item()); 
 return data[current_index]; 
 }
}

