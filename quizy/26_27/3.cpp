#include <cstdint>
#include <iostream> 

namespace first {
    void foo() {
        uint16_t x = 65535;
        uint16_t y = x * x;

        std::cout << "x = " << x << ", y = " << y << "\n";

        // x = 65535, y = 1
        // x = 65535, y = 131070
        // undefined behavior
        // compilation error
    }
}

namespace second {
    void foo() {
        int a = 0;
        
        decltype(a) x = a;
        decltype((a)) y = a;

        x = 2;
        std::cout << a << "\n";

        y = 3;
        std::cout << a << "\n";

        // 2, 3
        // 0, 3
        // 0, 0
        // compilation error
    }
}

namespace third {
    struct B {
        void f(int) { std::cout << "B::f called\n"; }
    };

    struct D {
        void f(std::string) { std::cout << "D::f called\n"; }
    };

    void foo() {
        D{}.f(42);
    }
}

namespace fourth {
    void foo() {
        std::string s = "ala ma kota";

        if (s.find("nie ma mnie")) {
            std::cout << "jestem\n";
        }

        // jestem zostanie wypisane
        // jestem nie zostanie wypisane
        // compilation errro
        // undefined behavior
    }
}

namespace fifth {
    void foo() {
        <:]{%>();

        // nic nie robi
        // implementation-defined behavior
        // compilation error
        // undefined behavior
    }
}
