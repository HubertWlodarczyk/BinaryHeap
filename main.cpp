#include <iostream>
#include "BinaryHeap.h"

int main() {
    BinaryHeap *testHeap = new BinaryHeap;
    for (int i = 50; i < 200; i += 3) {
        testHeap->AddElement(i);
    }
    testHeap->ShowHeap();
    std::cout << testHeap->GiveMax() << std::endl;
    testHeap->CleanHeap();
    testHeap->ShowHeap();
    return 0;
}
