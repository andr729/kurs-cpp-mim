#include <iostream>



namespace t1 {

    namespace lib {
        void foo(int) {
            std::cout << "int\n";
        }
    }

    using lib::foo;

    namespace lib {
        void foo(double) {
            std::cout << "double\n";
        }
    }

    void test() {
        foo(1.5);
    }
}

namespace t2 {

    int five() {
        return 5;
    }

    extern int b;
    extern int d;

    int a = b + 1;
    int c = d + 1;

    int b = 5;
    int d = five();

    void test() {
        std::cout << a << " " << c << "\n";
    }
}


namespace t3 {

#define MAX(a, b) ((a) > (b) ? (a) : (b))

    void test() {
        int i = 4;
        int j = 3;
        int m = MAX(i++, j);
        std::cout << m << " " << i << "\n";
    }
}

namespace t4 {

    void foo(double) {
        std::cout << "double\n";
    }

    namespace inner {

        void foo(int) {
            std::cout << "int\n";
        }

        void test() {
            foo(1.5);
        }
    }
}

int main() {
    t1::test();
    t2::test();
    t3::test();
    t4::inner::test();
}
