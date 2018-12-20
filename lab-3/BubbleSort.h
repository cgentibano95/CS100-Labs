#include "container.h"

class BubbleSort : public Sort { 
  public: 
  void sort(Container* container) {
        for (int i = 1; i < container->size(); i++) {
            bool sort_complete = true;
            for (int j = 0; j < container->size() - 1; j++) {
                if (container->at(j)->evaluate()  > container->at(j + 1)->evaluate())
                {
                    container->swap(j, j+1);
                    sort_complete = false;
                }
            }
            if (sort_complete == true)
                    break;
        }
    }; 
};
