#include "container.h"

class SelectionSort : public Sort {
public:
    SelectionSort() : Sort() {};
    void sort(Container* container) {
        int min = 0;
        for (int i = 0; i < container->size(); i++) {
            for (int j = i; j < container->size(); j++) {
                if (container->at(j)->evaluate() < container->at(min)->evaluate()) {
                    min = j;
                }
            }
            container->swap(min, i);
        }
    }
};
