#include "Ciccoida.h"
#include <iostream>
#include <cmath>

namespace Prog2{
    Ciccoida::Ciccoida(double rad) {
        a = rad;
    }

    Ciccoida::Ciccoida(const Ciccoida &ciccoida) {
        a = ciccoida.a;
    }

    double Ciccoida::distance(double grad) const {
        while(grad>=360 || grad<0){/*здесь угол преобразуется в угол, лежащий в промежутке от 0 до 2*pi*/
            if (grad>=360)
                grad-=360;
            else
                grad+=360;
        }
        if (a<0){
            if (grad<=90 || grad>=270)//проверка на правильность угла, если а<0
                return -1;
            grad = PI/180 *grad;
            return 2*a* sin(grad)* sin(grad)/ cos(grad);
        }else{
            if (grad>=90&&grad<=270)//проверка на правильность угла, если а>0
                return -2;
            grad = PI/180 *grad;
            return 2*a* sin(grad)* sin(grad)/ cos(grad);
        }
    }

    double Ciccoida::value_y(double x) const{
        if (2*a-x==0){
            throw "invalid x";
        }
        double prom = x*x*x/(2*a-x);//вводится переменная для того, чтобы не выполнять вычисления дважды
        if (prom<0)
            throw "invalid x";
        return sqrt(prom);
    }

    double Ciccoida::coefficient(double x) const {/*Геометрическое место оснований перпендикуляров,
    * опущенных из вершин параболы на ее касательные есть циссоида
    * y^2 = -(x^3)/(p/2 - x), где p - является искомым коэффициентом*/
        return -2*(pow(x,3)/ pow(value_y(x),2)-x);
    }

    double Ciccoida::volume() const {
        double res = 2*PI*PI*a*a*a;
        if (res<0){
            res *= -1;
        }
        return res;
    }
}