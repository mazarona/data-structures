
class Vector {

private:
  int *data;
  int capacity;
  int size;

  /* Helper Functions */

  // TODO: Update Capacity

  // TODO: Reserve if(new capacit < size ) return;
  void reserve(int newCapacity) {
    if (newCapacity < size)
      return;
  }

  void copy(const Vector &cpy) {
    capacity = size = cpy.getSize();
    if (data != nullptr) {
      delete[] data;
      data = nullptr;
    }
    data = new int[capacity];
    for (int i = 0; i < size; i++)
      data[i] = cpy.data[i];
  }

public:
  /* Constructors */

  // First Default Constructor
  Vector() : data(nullptr), capacity(0), size(0) {}

  // Second Constructor
  Vector(const int sz, const int val) {
    capacity = size = sz;
    data = new int[capacity];
    for (int i = 0; i < size; i++)
      data[i] = val;
  }

  // Third Copy Constructor (has to be by reference?).
  Vector(const Vector &cpy) { copy(cpy); }

  /* Getters */

  int getSize() const { return size; }
  int getCapacity() const { return capacity; }

  /* API */

  bool empty() const { return size == 0; }

  int back() const {
    // TODO: Exception Handling
    return data[size - 1];
  }

  int front() const {
    // TODO: Exception Handling
    return data[0];
  }

  void pushBack(const int val) {
    if (size == capacity) {
      reserve((capacity << 1) + (capacity == 0));
    }
    data[size++] = val;
  }

  void clear() {
    size = capacity = 0;
    if (data != nullptr)
      delete[] data;
    data = nullptr;
  }

  /* Operators */

  Vector &operator=(const Vector &cpy) {
    copy(cpy);
    return *this;
  }

  /* Destructor */

  ~Vector() { delete[] data; }
};
