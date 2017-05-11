#include "syntax.h"
#include "hash.h"
using namespace NTL;
element &element::operator=(const element &np) {
    argc = np.argc;
    if(!argv) delete[] argv;
    argv = new NTL::ZZ[np.argc];
    for (int i = 0; i < np.argc; ++i) {
        argv[i] = np.argv[i];
    }
    return *this;
}

element::~element() {
    if(argc == 1) delete argv;
    else if(argc > 1) delete [] argv;
}

hash::hash() {
    // element ag[10007];
}
hash::~hash() {}

int main() {
    element a,b;
    ZZ gg;
    a.argc = 3;
    a.argv = new NTL::ZZ[3];
    for (int i = 0; i < 3; ++i) {
        a.argv[i] = 23;
    }
    for (int i = 0; i < 3; ++i) {
        std::cout << a.argv[i] << std::endl;
    }
    gg = 123141414;
    gg++;

    std::cout << gg << std::endl;
    return 0;
}

