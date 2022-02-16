#include "Queue.h"

class DerPrivate: private Queue {
    public:
    DerPrivate();
    ~DerPrivate();
    void countElementsMoreAverage();
    private:
    struct QueueElement* ptrFirstElement;
    struct QueueElement* ptrLastElement;
};