#include "gtest/gtest.h"
#include "Ciccoida.h"


//constructors' test
TEST(CiccoidaConstructor, DefaultConstructor){
    Prog2::Ciccoida c1;
    ASSERT_EQ(1, c1.get());
}

TEST(CiccoidaConstructor, InitConstructor){
    Prog2::Ciccoida c2(10);
    ASSERT_EQ(10, c2.get());
}

//setter's test
TEST(CiccoidaSetter, Setter){
    Prog2::Ciccoida c;
    c.set(5);
    ASSERT_EQ(5, c.get());
    c.set(-10);
    ASSERT_EQ(-10, c.get());
}

//tests other methods
TEST(CiccoidaMethods, SQUARE){//test for calculating the area
    Prog2::Ciccoida c;
    const double near = 0.0001;
    ASSERT_NEAR(3*PI*c.get()*c.get(), c.square(), near);
}

TEST(CiccoidaMethods, Distance){//tests for calculating the distance
    Prog2::Ciccoida c(2);
    const double near = 0.0001;
    ASSERT_NEAR(0, c.distance(0), near);
    ASSERT_NEAR(2*c.get()* sin(PI/8)* sin(PI/8)/ cos(PI/8), c.distance(22.5), near);
    ASSERT_NEAR(2*c.get()* sin(PI/4)* sin(PI/4)/ cos(PI/4), c.distance(45), near);
    ASSERT_NEAR(2*c.get()* sin(-PI/3)* sin(-PI/3)/ cos(-PI/3), c.distance(-60), near);
    c.set(-5);
    ASSERT_NEAR(2*c.get()* sin(PI)* sin(PI)/ cos(PI), c.distance(180), near);
    ASSERT_NEAR(2*c.get()* sin(2*PI/3)* sin(2*PI/3)/ cos(2*PI/3), c.distance(120), near);
    ASSERT_NEAR(2*c.get()* sin(5*PI/4)* sin(5*PI/4)/ cos(5*PI/4), c.distance(225), near);
//    ASSERT_NEAR(2*c.get()* sin(PI/4)* sin(PI/4)/ cos(PI/4), c.distance(45), near);
}

TEST(CiccoidaMethods, VALUEY){//tests for calculating y(x)
    Prog2::Ciccoida c;
    const double near = 0.0001;
    double x=1.43;
    ASSERT_NEAR(sqrt(x*x*x/(2*c.get()-x)), c.value_y(x), near);
    x = 0.42153;
    ASSERT_NEAR(sqrt(x*x*x/(2*c.get()-x)), c.value_y(x), near);
    x = 1;
    ASSERT_NEAR(sqrt(x*x*x/(2*c.get()-x)), c.value_y(x), near);
    c.set(-13);
    x = -5;
    ASSERT_NEAR(sqrt(x*x*x/(2*c.get()-x)), c.value_y(x), near);
    x = -12.43;
    ASSERT_NEAR(sqrt(x*x*x/(2*c.get()-x)), c.value_y(x), near);
    x = -0.54;
    ASSERT_NEAR(sqrt(x*x*x/(2*c.get()-x)), c.value_y(x), near);
}

TEST(CiccoidaMethods, ASYMPTOTE){//tests for calculate asymptote
    Prog2::Ciccoida c(4);
    ASSERT_EQ(2*c.get(), c.asymptote());
    c.set(-8);
    ASSERT_EQ(2*c.get(), c.asymptote());
}

TEST(CiccoidaMethods, VOLUME){//tests for calculating volume
    Prog2::Ciccoida c(3);
    ASSERT_EQ(2*PI*PI*c.get()*c.get()*c.get(), c.volume());
    c.set(-8);
    ASSERT_EQ(-2*PI*PI*c.get()*c.get()*c.get(), c.volume());
}

TEST(CiccoidaMethods, COEFFICIENT){
    Prog2::Ciccoida c(2);
    double x = 3.54;
    ASSERT_EQ(-2*(pow(x,3)/ pow(sqrt(x*x*x/(2*c.get()-x)),2)-x), c.coefficient(x));
    x = 1;
    ASSERT_EQ(-2*(pow(x,3)/ pow(sqrt(x*x*x/(2*c.get()-x)),2)-x), c.coefficient(x));
    c.set(-8);
    x = -3.6536;
    ASSERT_EQ(-2*(pow(x,3)/ pow(sqrt(x*x*x/(2*c.get()-x)),2)-x), c.coefficient(x));
    x = -7;
    ASSERT_EQ(-2*(pow(x,3)/ pow(sqrt(x*x*x/(2*c.get()-x)),2)-x), c.coefficient(x));
}

int _tmain(){
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}