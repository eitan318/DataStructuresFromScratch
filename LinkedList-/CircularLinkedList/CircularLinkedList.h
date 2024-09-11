template <typename T>
class CircularLinkedList : public ILinkedList<T> {
private:
    struct Node {  // Node is nested inside SinglyLinkedList
        T data;
        Node* next;

        Node(T value) : data(value), next(nullptr) {}
    };

    Node* last;
    int count;
    Node* reverse_recursive(Node* curr);

    static void default_print(T data) {
        std::cout << data << " ";
    }

public:
    CircularLinkedList() : head(nullptr), tail(nullptr), count(0) {}
    ~CircularLinkedList();

    void add_start(T value) override;
    void add_end(T value) override;
    void print(void (*print_func)(T) = default_print) override;
    bool remove_node(T node_data) override;
    T remove_at(int idx) override;
    void insert_at(T data, int idx) override;
    void reverse() override;
    T get(int idx) override;
    T get_last() override;
    void set(int idx, T new_value) override;
    void set_last(T new_value) override;
    void move_node(int idxFrom, int idxTo) override;
    void replace(int one_idx, int second_idx) override;
    bool is_empty() override;
    int Count() override;

};

template <typename T>
inline void CircularLinkedList<T>::add_start(T value)
{
    Node* newNode = new Node(value);
    if (this->last == nullptr) {
        this->last = newNode;
        this->last->next = newNode;
    } else {
        newNode->next = this->last->next;
        this->last->next = newNode;
    }
    count++;
}


template <typename T>
inline void CircularLinkedList<T>::add_end(T value)
{
    Node* newNode = new Node(value);
    if (this->last == nullptr) {
        this->last = newNode;
        this->last->next = newNode;
    } else {
        newNode->next = this->last->next;
        this->last->next = newNode;
        this->last = newNode;
    }
    count++;
}

template <typename T>
inline void CircularLinkedList<T>::print(void (*print_func)(T))
{
    if(this->last == nullptr){
        return;
    }
    Node* curr = this->last->next;
    while(curr != this->last) {
        print_func(curr->value);
    }
}

template <typename T>
inline bool CircularLinkedList<T>::remove_node(T node_data)
{
    if(this->last == nullptr){
        return false;
    }

    Node* curr = this->last->next;
    Node* prev = this->last;

    while(curr != this->last) {
        if(curr->data == node_data){
            prev->next = curr->next;
            delete curr;
            return true; 
        }
        curr = curr->next;
        prev = prev->next;   
    }
    return false;
}

template <typename T>
inline T CircularLinkedList<T>::remove_at(int idx)
{
    if(idx < 0 || idx >= this->count){
        std::cerr << "idx out of range." << std::endl;
    }

    if(this->last == nullptr){
        std::cerr << "list empty." << std::endl;
    }

    Node* curr = this->last->next;
    Node* prev = this->last;

    for(int i = idx; i < this->count; i++){
        curr = curr->next;
        prev = prev->next;
    }

    prev->next = curr->next;
    return curr; 
}

template <typename T>
inline void CircularLinkedList<T>::reverse()
{
}

template <typename T>
inline T CircularLinkedList<T>::get(int idx)
{
    return T();
}

template <typename T>
inline T CircularLinkedList<T>::get_last()
{
    return T();
}

template <typename T>
inline void CircularLinkedList<T>::set(int idx, T new_value)
{
}

template <typename T>
inline void CircularLinkedList<T>::set_last(T new_value)
{
}

template <typename T>
inline void CircularLinkedList<T>::move_node(int idxFrom, int idxTo)
{
}

template <typename T>
inline void CircularLinkedList<T>::replace(int one_idx, int second_idx)
{
}

template <typename T>
inline bool CircularLinkedList<T>::is_empty()
{
    return this->size() == 0;
}

template <typename T>
inline int CircularLinkedList<T>::Count()
{
    return this->count;
}
