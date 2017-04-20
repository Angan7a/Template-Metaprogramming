#include <iostream>


struct NIL {
    typedef NIL Head;
    typedef NIL Tail;
};

template <typename H=NIL, typename T=NIL>
struct Lst {
    typedef H Head;
    typedef T Tail;
};

template <int N>
struct Int {
    static const int result = N;
};


template<typename List>
struct How_long {
    static const int result = 1 + How_long<typename List::Tail>::result;
};


template<>
struct How_long<NIL> {
    static const int result = 0;
};



int main()
{
//    typedef Lst< Int<1>, Lst< Int<2>, Lst< Int<3> > > > OneTwoThree;
//     std::cout << Int<3>::result << std::endl;
     typedef Lst<> f;
//     std::cout << f1::Head::result << std::endl;

     typedef Lst< Int<3> > f1;
     std::cout << f1::Head::result << std::endl;

     typedef Lst< Int<2>, f1 > f2;
     std::cout << f2::Head::result << std::endl;

     typedef Lst< Int<1>, f2 > f3;
     std::cout << f3::Head::result << std::endl;

  typedef Lst< Int<1>, Lst< Int<2>, Lst< Int<3> > > > OneTwoThree;
     std::cout << OneTwoThree::Tail::Tail::Head::result << std::endl;

     std::cout << How_long<f2>::result << std::endl;
return 0;
}
