#include "Buckets.h"

bool Bucket::consume(){
    if(this->isEmpty()){
        return false;
    }else {
        remaining--;
        return true;
    }
}

bool Bucket::isEmpty(){
    return !static_cast<bool>(remaining);
}

sf::Color Bucket::getColor(){
    return color;
}

