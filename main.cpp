#include <iostream>
#include "Ciccoida/Ciccoida.h"


int main() {
    Prog2::Ciccoida c;
    int fl1 = 1;
    double a;
    while(fl1){
        std::cout<<"Your cissoida is: y^2=x^3/("<<c.get()<<"*2-x)"<<std::endl;
        std::cout<<"asymptote: "<<c.asymptote()<<std::endl;
        std::cout<<"square: "<<c.square()<<std::endl;
        std::cout<<"volume: "<<c.volume()<<std::endl;
        std::cout<<"Enter angle for calculate distance or press ctrl+D to exit:";
        int grad;
        if (Prog2::getNum(grad)==-1){
            break;
        }
        if (c.distance(grad)<0){
            std::cout<<"This angle goes beyond the available"<<std::endl;
        }else {
            std::cout << "distance:" << c.distance(grad) << std::endl;
        }
        std::cout<<"Enter x for calculate y(x) and coefficient or press ctrl+D to exit:";
        int x;
        if (Prog2::getNum(x)==-1){
            break;
        }
        try {
            double res = c.value_y(x);/*вспомогательный элемент, чтобы в случае неправильного
                *ввода х не выводилась часть, находящаяся до вызова метода value_y*/
            std::cout << "y(x) = +-" << res << std::endl;
            std::cout<<"coefficient ="<<c.coefficient(x)<<std::endl;
        }catch (const char *a){
            std::cout<<a<<std::endl;
        }
        std::cout<<"Enter new a or press ctrl+D to exit:";
        int a1;
        if (Prog2::getNum(a1)==-1){
            fl1 = 0;
        }else {
            try {
                c.set(a1);
            }catch(std::exception &ex){
                std::cout<<ex.what()<<std::endl;
            }
        }
    }
    return 0;
}