#include "BinaryHeap.h"
#include <cmath>
#include <iostream>

BinaryHeap::BinaryHeap() {
    this->Nodes = new int[8];
    this->Size = 8;
    this->OccupiedSize = 0;
}

BinaryHeap::~BinaryHeap() {
    delete this->Nodes;
}

void BinaryHeap::RepairUp(int index) {
    if (this->OccupiedSize == 1) return;
    int parentIndex;
    do {
        parentIndex = floor((index - 1.0) / 2);
        if (this->Nodes[parentIndex] >= this->Nodes[index]) return;
        std::swap(this->Nodes[parentIndex], this->Nodes[index]);
        index = parentIndex;
    } while (parentIndex >= 0);
}

void BinaryHeap::RepairDown(int index) {
    if (this->OccupiedSize == 1) return;
    int lChildIndex;
    int rChildIndex;
    do {
        lChildIndex = 2 * index + 1;
        rChildIndex = 2 * index + 2;
        if (lChildIndex <= this->OccupiedSize) {
            if (this->Nodes[lChildIndex] > this->Nodes[index]) {
                std::swap(this->Nodes[index], this->Nodes[lChildIndex]);
                index = lChildIndex;
            }
        }
        if (rChildIndex <= this->OccupiedSize) {
            if (this->Nodes[rChildIndex] > this->Nodes[index]) {
                std::swap(this->Nodes[index], this->Nodes[rChildIndex]);
                index = rChildIndex;
            }
        }
    } while (lChildIndex <= this->OccupiedSize && rChildIndex <= this->OccupiedSize);
}

void BinaryHeap::ExtendArray() {
    this->Size *= 2;
    int *newNodes = new int[this->Size];
    for (int i = 0; i < this->OccupiedSize; i++) {
        newNodes[i] = this->Nodes[i];
    }
    for (int i = this->OccupiedSize; i < this->Size; i++) {
        newNodes[i] = 0;
    }
    delete this->Nodes;
    this->Nodes = newNodes;
}

void BinaryHeap::AddElement(int newElement) {
    this->Nodes[this->OccupiedSize++] = newElement;
    this->RepairUp(this->OccupiedSize - 1);
    if (this->OccupiedSize == this->Size) ExtendArray();
}

int BinaryHeap::GiveMax() {
    int maxValue = this->Nodes[0];
    std::swap(this->Nodes[0], this->Nodes[this->OccupiedSize]);
    this->OccupiedSize--;
    this->RepairDown(0);
    return maxValue;
}

void BinaryHeap::CleanHeap() {
    this->OccupiedSize = 0;
}

void BinaryHeap::ShowHeap() {
    if (this->OccupiedSize == 0) return;
    int power = 0;
    int rowWidth = 0;
    for (int i = 0; i < this->OccupiedSize; i++) {
        std::cout << this->Nodes[i] << "\t";
        rowWidth++;
        if (pow(2, power) == rowWidth) {
            rowWidth = 0;
            power++;
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}
