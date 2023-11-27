#include "Buckets.h"

bool Bucket::consume(){
    if(this->isEmpty()){
        return false;
    }else {
        remaining--;
        return true;
    }
}

