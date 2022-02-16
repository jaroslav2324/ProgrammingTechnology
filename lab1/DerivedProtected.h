#include "Queue.h"

class DerProtected: protected Queue {
    public:
    DerProtected();
    ~DerProtected();
    void countElementsMoreAverage();
    private:
    struct QueueElement* ptrFirstElement;
    struct QueueElement* ptrLastElement;
};