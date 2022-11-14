#include <iostream>
#include <exception>

class smart_array {
public:
	smart_array(int size) {
		size_ = size;
		s_m = new int[size_];
		capacity = size_;
	}
	int add_element(int element) {
		if (size_ == capacity) capacity *= 2;
		else if (size_ < capacity) {
			int* tmp = new int[size_];
			for (int j = 0; j < size_; ++j) {
				tmp[j] = s_m[j];
			}
			delete[]s_m;
			s_m = tmp;
			++size_;
		}
		s_m[i] = element;
		i++;
		return element;
	}
	int get_element(int id) {
		if (id >= size_) {
			throw std::exception("wrong index");
		}
		return s_m[id];
	}
	smart_array& operator=(const smart_array& other) {		
		return *this = smart_array(other);
	}

	smart_array(const smart_array& other)
		: smart_array(*other.s_m) {}

	~smart_array() {
		delete[] s_m;
	}
private:
	int* s_m = nullptr;
	int size_ = 0;
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