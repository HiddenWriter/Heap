#pragma once
template <typename T>
class HeapBase {
public:
	HeapBase();
	virtual ~HeapBase();

	virtual int Add(T _item);

	virtual int Delete(T _item);

	int Display();

	virtual int Search(T& _item);

	int Clear();

	int Modify(T _item);

	int GetLength() const;

	bool IsFull();

	bool IsEmpty();

	virtual void ReHeapDown(int _par, int _bot) = 0;

	virtual void ReHeapUp(int _root, int _bot) = 0;

	virtual void Retrieve(T& _item, bool& _isFound, int _par) = 0;

	virtual void Delete(T _item, bool& _isDeleted, int _par) = 0;

protected:

	T* Array;
	int lastNode;
	int maxSize;

};

template <typename T>
HeapBase<T>::HeapBase() {
	maxSize = ARRAY_SIZE;
	this->Array = new T[maxSize];
	this->lastNode = 0;
	return;
}

template <typename T>
HeapBase<T>::~HeapBase() {
	this->Clear();
	return;
}

template <typename T>
bool HeapBase<T>::IsFull() {
	if (this->lastNode == maxSize) {
		return true;
	}
	else return false;
}

template <typename T>
bool HeapBase<T>::IsEmpty() {
	if (this->lastNode == 0) { return true; }
	else return false;
}

template <typename T>
int HeapBase<T>::Display() {
	for (int i = 0; i < this->lastNode; i++) {
		std::cout << this->Array[i];
	}
	return 1;
}

template <typename T>
int HeapBase<T>::GetLength()const {
	return this->lastNode;
}

template <typename T>
int HeapBase<T>::Clear() {
	this->Array = nullptr;
	delete[] this->Array;
	return 1;
}

template <typename T>
int HeapBase<T>::Add(T _item) {
	if (IsFull()) {
		return 0;
	}
	else {
		this->Array[this->lastNode] = _item;
		ReHeapUp(0, this->lastNode);
		this->lastNode++;
		return 1;
	}
}

template <typename T>
int HeapBase<T>::Delete(T _item) {
	bool isDeleted = false;
	Delete(_item, isDeleted, 0);
	
	if (isDeleted) {
		this->lastNode--;
		return 1;
	}
	else {
		return 0;
	}
}

template <typename T>
int HeapBase<T>::Search(T& _item) {
	bool isFound = false;
	Retrieve(_item, isFound);
	return isFound;
}

template <typename T>
int HeapBase<T>::Modify(T _item) {
	bool isFound = false;
	return 1;
}
