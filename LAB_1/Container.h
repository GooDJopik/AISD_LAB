#include <iostream>
#include <cmath>
#include <complex>
const float epsilon = 0.0001f;
using namespace std;

namespace matrix {
	template <typename T>
	class Container {
	private:
		int _size;
		T* _vector;
	public:
		Container();
		Container(int size);
		Container(const Container<T>& other);
		int get_size();
		~Container();
		void Swap(Container<T>& other);
		bool operator==(const Container<T>& other) const;
		bool operator!=(const Container<T>& other) const;
		Container<T>& operator=(const Container<T>& other);
		T& operator[](int num);
		T operator[](int num) const;

	};

	template <typename T>
	Container<T>::Container() {
		this->_vector = nullptr;
		this->_size = 0;
	}

	template <typename T>
	T Container<T>::operator[](int num) const {
		if (num < 0 || num >= this->_size) {
			throw runtime_error("Index out of range");
		}
		return this->_vector[num];
	}
	template <typename T>
	Container<T>& Container<T>::operator=(const Container<T>& other) {
		Container<T> other_copy(other);
		this->Swap(other_copy);
		return *this;
	}

	template<typename T>
	T& Container<T>::operator[](int num) {	
		if (num < 0 || num >= this->_size) {
			throw runtime_error("Index out of range");
		}
		return this->_vector[num];
	}

	template <typename T>
	Container<T>::Container(const Container<T>& other) {
		this->_size = other._size;
		this->_vector = new T[_size];
		for (int i = 0; i < _size; i++) {
			this->_vector[i] = other._vector[i];
		}
	}

	template<typename T>
	void Container<T>::Swap(Container<T>& other) {
		std::swap(this->_vector, other._vector);
		std::swap(this->_size, other._size);
	}

	template<typename T>
	bool Container<T>::operator==(const Container<T>& other) const {
		if (this->_size == other._size) {
			for (int i = 0; i < this->_size; i++) {
				if ((*this)[i] - other[i]) {
					return false;
				}
			}
			return true;
		}
		return false;
	}

	bool Container<float>::operator==(const Container<float>& other) const {
		if (this->_size == other._size) {
			for (int i = 0; i < this->_size; i++) {
				if (fabs((*this)[i] - other[i]) <= epsilon) {
					return false;
				}
			}	
			return true;
		}
		return false;
	}

	template<typename T>
	bool Container<T>::operator!=(const Container<T>& other) const {
		return !((*this) == other);
	}

	template<typename T>
	int Container<T>::get_size() {
		return this->_size;
	}
	template<typename T>
	Container<T>::Container(int size) {
		this->_size = size;
		this->_vector = new	T[_size];
		for (int i = 0; i < _size; ++i) {
			_vector[i] = 0;
		}
	}

	template<typename T>
	Container<T>::~Container() {
		delete[] this->_vector;
	}
	
}