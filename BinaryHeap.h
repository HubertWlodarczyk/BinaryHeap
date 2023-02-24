#ifndef BINARYHEAP_BINARYHEAP_H
#define BINARYHEAP_BINARYHEAP_H

class BinaryHeap {
    int* Nodes;
    int Size;
    int OccupiedSize;
    void RepairUp(int);
    void RepairDown(int);
    void ExtendArray();
public:
    BinaryHeap();
    ~BinaryHeap();
    void AddElement(int);
    int GiveMax();
    void CleanHeap();
    void ShowHeap();
};


#endif //BINARYHEAP_BINARYHEAP_H
