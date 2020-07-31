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
	this->Array = new T[this->maxSize];
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
	
	int parent = -1;

	if (_bot > _root) {
		
		parent = (_root - 1) / 2;

		if (this->Array[parent] < this->Array[_bot]) {
			this->SwapNode(parent, _bot);
			ReHeapUp(_root, parent);
		}
	}
	return;
}

template <typename T>
void HeapMax<T>::ReHeapDown(int _par, int _bot) {
	
	int left, right, max;

	left = (2 * _par) + 1;
	right = (2 * _par) + 2;

	if (left <= _bot) {
		if (left == _bot) {
			max = left;
		}
		else {
			if (this->Array[left] < this->Array[right]) {
				max = right;
			}
			else {
				max = left;
			}
		}
		if (this->Array[max] > this->Array[_bot]) {
			this->SwapNode(max, _bot);
			ReHeapDown(max, _bot);
		}
	}
	return;
}

template <typename T>
void HeapMax<T>::Retrieve(T& _item, bool& _isFound, int _par) {

	int left = -1, right = -1;
	left = (2 * _par) + 1;
	right = (2 * _par) + 2;

	if (_item == this->Array[_par]) {
		_item = this->Array[_par];
		_isFound = true;
		return;
	}
	if (left < this->lastNode && !_isFound) {
		Retrieve(_item, _isFound, left);
	}
	if (right < this->lastNode && !_isFound) {
		Retrieve(_item, _isFound, right);
	}
	return;
}