#include <iostream>
#include <exception>

class smart_array {
public:
	smart_array(int size) {
		s_m = new int[size];
		capacity = size;
	}

	int add_element(int element) {
		if (i == capacity) {
			capacity *= 2;
			int* tmp = new int[capacity];
			for (int j = 0; j < i; j++) {
				tmp[j] = s_m[j];
			}
			delete[]s_m;
			s_m = tmp;
		}
		if (i < capacity) {
			s_m[i] = element;
			i++;
		}

		return element;
	}

	smart_array& operator=(const smart_array& other) {
		if (this != &other) {
			delete s_m;
			if (other.s_m == nullptr) s_m = nullptr;
			else { 
				s_m = new int[other.capacity]; 
				for (int i = 0; i < other.capacity; i++) {
					s_m[i] = other.s_m[i];
				}
			}
		}
		return *this;
	}
	smart_array(const smart_array& other) {
		*this = other;
	}

	int get_element(int id) {
		if (id >= capacity) {
			throw std::exception("wrong index");
		}
		return s_m[id];
	}

	~smart_array() {
		delete[] s_m;
	}
private:
	int* s_m = nullptr;
	int capacity = 0;
	int i = 0;
};

int main() {
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);

		arr = new_array;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}
