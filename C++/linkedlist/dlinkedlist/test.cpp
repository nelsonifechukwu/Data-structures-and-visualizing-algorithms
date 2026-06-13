#include "deque.h"


int main(){
    Deque<int> temp;

    for (int i = 4; i < 12; i++){  
    temp.pushBack(i);
    }

    temp.printDeque();


}