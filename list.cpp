#include <iostream>


struct NIL {
//    typedef NIL Head;
//    typedef NIL Tail;
};

template <typename H, typename T=NIL>
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

template<bool a, typename Lista, int N>
struct CzyZawiera {
    static const bool out = CzyZawiera<(Lista::Head::result == N), typename Lista::Tail, N>::out;
};

template< int N>
struct CzyZawiera<0,NIL,N> {
    static const bool out = 0;
};

template<typename Lista, int N>
struct CzyZawiera<1,Lista,N> {
   static const bool out = 1;
};


template<typename Lista, int N>
struct Find {
    static const bool output = CzyZawiera<(Lista::Head::result == N), Lista, N>::out;
};

int main()
{
//    typedef Lst< Int<1>, Lst< Int<2>, Lst< Int<3> > > > OneTwoThree;
//     std::cout << Int<3>::result << std::endl;
//     std::cout << f1::Head::result << std::endl;

     typedef Lst< Int<3> > f1;
     std::cout << f1::Head::result << std::endl;

     typedef Lst< Int<2>, f1 > f2;
     std::cout << f2::Head::result << std::endl;

     typedef Lst< Int<1>, f2 > f3;
     std::cout << f3::Head::result << std::endl;

     typedef Lst< Int<1>, Lst< Int<2>, Lst< Int<3> > > > OneTwoThree;
     std::cout << OneTwoThree::Tail::Tail::Head::result << std::endl;

     std::cout << "List length: " << How_long<f3>::result << std::endl;
     std::cout << "Czy lista zawiera 4: " << Find<f3,4>::output << std::endl;



return 0;
}
