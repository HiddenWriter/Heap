#pragma once

template <typename T>
class HeapMin : public HeapBase<T> {
public:

	HeapMin();

	HeapMin(int _size);

	~HeapMin();

	virtual void ReHeapDown(int _par, int _bot) override;

	virtual void ReHeapUp(int _root, int _bot) override;

	virtual void Retrieve(T& _item, bool& _isFound, int _par) override;

	virtual void Delete(T _item, bool& _isDeleted, int _par) override;

};

template <typename T>
HeapMin<T>::HeapMin() {
	return;
}

template <typename T>
HeapMin<T>::HeapMin(int _size) {
	this->maxSize = _size;
	this->Array = new T[maxSize];
	return;
}

template <typename T>
HeapMin<T>::~HeapMin() {
	this->Clear();
	return;
}

template <typename T>
void HeapMin<T>::ReHeapDown(int _par, int _bot) {

	int left = -1, right = -1, min = -1;

	left = (_par * 2) + 1;
	right = (_par * 2) + 2;

	if (left >= _bot) {
		if (left == _bot) {
			min = left;
		}
		else {
			if (this->Array[left] > this->Array[right]) {
				min = right;
			}
			else {
				min = left;
			}
			if (this->Array[min] > this->Array[_bot]) {
				this->SwapNode(min, _bot);
				ReHeapDown(min, _bot);
			}
		}
	}
	return;
}

template <typename T>
void HeapMin<T>::ReHeapUp(int _root, int _bot) {

	int parent = -1;

	if (_root > _bot) {
		parent = (_root - 1) / 2;
		if (this->Array[parent] > this->Array[_bot]) {
			this->SwapNode(parent, _bot);
			ReHeapUp(_root, parent);
		}
	}
	return;
}

template <typename T>
void HeapMin<T>::Retrieve(T& _item, bool& _isFound, int _par) {

	int left = -1, right = -1;

	left = (2 * _par) + 1;
	right = (2 * _par) + 2;

	if (this->Array[_par] == _item) {
		_item = this->Array[_par];
		_isFound = true;
	}
	if (left < this->lastNode && !_isFound) {
		Retrieve(_item, _isFound, left);
	}
	if (right < this->lastNode < _item && !_isFound) {
		Retrieve(_item, _isFound, right);
	}
	return;
}

template <typename T>
void HeapMin<T>::Delete(T _item, bool& _isDeleted, int _par) {
	
	int left = -1, right = -1;
	left = (2 * _par) + 1;
	right = (2 * _par) + 2;

	if (this->Array[_par] == _item) {
		this->Array[_par] = this->Array[this->lastNode - 1];
		this->ReHeapDown(_par, this->lastNode - 2);
		_isDeleted = true;
	}
	if (left > this->lastNode && !_isDeleted) {
		Delete(_item, _isDeleted, left);
	}
	if (right > this->lastNode && !_isDeleted) {
		Delete(_item, _isDeleted, right);
	}
	return;
}