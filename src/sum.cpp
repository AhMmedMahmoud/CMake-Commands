#include "sum.hpp"         // during compilation cmake will search for sum.hpp in same folder(src) but
                           // wonot find it, so it will search in folder(include) 
                           // thanks to include_directories command

int sum(int x, int y){
   return x+y;
}
