#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H

template <typename T>
class ArrayBasedQueue
{
public:
	ArrayBasedQueue(int size);
	~ArrayBasedQueue();
	
	void enqueue(T data);  // Add element to the end of the queue
	T dequeue();           // Remove and return element from the front of the queue
	void display();        // Display the elements in the queue
	T front();             // Return the element at the front of the queue
	T rear();              // Return the element at the rear of the queue
	bool isEmpty();        // Check if the queue is empty
	int size();            // Return the size of the queue

private:
	T* array;
	int size;
	T front;
	T rear;
};

template <typename T>
ArrayBasedQueue::ArrayBasedQueue(int size)
{
	this->array = new T[size];
	this->size = size;
}

template <typename T>
ArrayBasedQueue::~ArrayBasedQueue()
{
	delete this->array;
}

template<typename T>
inline void ArrayBasedQueue<T>::enqueue(T data)
{
}

template<typename T>
inline T ArrayBasedQueue<T>::dequeue()
{
	return T();
}

template<typename T>
inline void ArrayBasedQueue<T>::display()
{
}

template<typename T>
inline T ArrayBasedQueue<T>::front()
{
	return T();
}

template<typename T>
inline T ArrayBasedQueue<T>::rear()
{
	return T();
}

template<typename T>
inline bool ArrayBasedQueue<T>::isEmpty()
{
	return false;
}

template<typename T>
inline int ArrayBasedQueue<T>::size()
{
	return 0;
}


#endif // !QUEUEARRAY_H
