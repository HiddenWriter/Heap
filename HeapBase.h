#pragma once
template <typename T>
class HeapBase {
public:
	HeapBase();
	virtual ~HeapBase();

	virtual int Add(T _item);

	virtual int Delete(T _item);

	virtual int Search(T& _item);

	int Display();

	int Clear();

	int Modify(T _item);

	int GetLength() const;

	bool IsFull();

	bool IsEmpty();

	void SwapNode(int _forward, int _backward);

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
	if (this->lastNode == 0) {
		return 0;
	}
	else {
		for (int i = 0; i < this->lastNode; i++) {
			std::cout << this->Array[i];
		}
		return 1;
	}
}

template <typename T>
int HeapBase<T>::GetLength()const {
	return this->lastNode;
}

template <typename T>
int HeapBase<T>::Clear() {
	this->Array = nullptr;
	this->lastNode = 0;
	delete[] this->Array;
	this->Array = new T[this->maxSize];

	return 1;
}

template <typename T>
int HeapBase<T>::Add(T _item) {

	if (IsFull() || Search(_item)) {
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
	if (this->IsEmpty()) {
		return 0;
	}
	else {
		Delete(_item, isDeleted, 0);

		if (isDeleted) {
			this->lastNode--;
			return 1;
		}
		else {
			return 0;
		}
	}
}

template <typename T>
int HeapBase<T>::Search(T& _item) {
	if (this->IsEmpty()) {
		return 0;
	}
	else {
		bool isFound = false;
		Retrieve(_item, isFound, 0);
		return isFound;
	}
}

template <typename T>
int HeapBase<T>::Modify(T _item) {
	bool isFound = false;
	if (this->IsEmpty()) {
		return 0;
	}
	else {
		T temp = _item;
		this->Delete(_item);
		this->Add(temp);
		return 1;
	}
}

template <typename T>
void HeapBase<T>::SwapNode(int _forward, int _backward) {
	T temp = this->Array[_forward];
	this->Array[_forward] = this->Array[_backward];
	this->Array[_backward] = temp;
	return;
}