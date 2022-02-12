#include "Queue.h"

class DerPublic: public Queue {
    public:
    DerPublic();
    ~DerPublic();
    void countElementsMoreAverage();
    private:
    struct QueueElement* ptrFirstElement;
    struct QueueElement* ptrLastElement;
};