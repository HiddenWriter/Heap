#pragma once

template <typename T>
class HeapMax : public HeapBase<T> {
public:
	HeapMax();
	HeapMax(int _size);
	~HeapMax();

	virtual void ReHeapUp(int _root, int _bot) override;

	virtual void ReHeapDown(int _par, int _bot) override;

	virtual void Retrieve(T& _item, bool& _isFound, int _par) override;

	virtual void Delete(T _item, bool& _isDeleted, int _par) override;

};

template <typename T>
HeapMax<T>::HeapMax() { return; }

template <typename T>
HeapMax<T>::HeapMax(int _size) {
	this->maxSize = _size;
	return;
}

template <typename T>
HeapMax<T>::~HeapMax() {
	this->Clear();
	return;
}

template <typename T>
void HeapMax<T>::Delete(T _item, bool& _isDeleted, int _par) {
	
	int left = _par * 2 + 1;
	int right = _par * 2 + 2;
	
	if (this->Array[_par] == _item) {
		this->Array[_par] = this->Array[this->lastNode - 1];
		this->ReHeapDown(_par, this->lastNode - 2);
		_isDeleted = true;
	}
	if (this->lastNode > left && !_isDeleted) {
		Delete(_item, _isDeleted, left);
	}
	if (this->lastNode > right && !_isDeleted) {
		Delete(_item, _isDeleted, right);
	}
}

template <typename T>
void HeapMax<T>::ReHeapUp(int _root, int _bot) {
	
}