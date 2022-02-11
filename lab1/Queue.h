
struct QueueElement {
    int number;
    struct QueueElement* ptrNext = nullptr;
};

class Queue {
    public:
    Queue();
    ~Queue();
    void addElement();
    void deleteElement();
    class Queue* copyQueue();
    friend class Queue* mergeQueues(Queue* q1, Queue* q2);
    private:
    struct QueueElement* ptrFirstElement;
    struct QueueElement* ptrLastElement;
    protected:
};