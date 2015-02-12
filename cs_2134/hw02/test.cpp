#include <iostream>using namespace std;template< class Object >class memoryBuffer{public:    memoryBuffer(int size=10):theSize(size),objects(new Object[size]){}    memoryBuffer<Object>& operator=( const memoryBuffer& rhs );private:     int theSize;     Object* objects;};template< class Object >memoryBuffer<Object>& memoryBuffer<Object>::operator=(const memoryBuffer<Object>& rhs) {    if (this == *rhs)        return *this;    this->theSize = rhs.theSize;    Object* thisObjects = this->objects;    Object* rhsObjects = rhs.objects;    for (int i = 0; i < rhs.theSize; ++i) {        thisObjects[i] = rhsObjects[i];    }    return *this;}int main() {    memoryBuffer<string> a(20);    memoryBuffer<string> b = a;}