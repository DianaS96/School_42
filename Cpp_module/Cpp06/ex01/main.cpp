#include <iostream>

typedef struct s_data {
    int data;
} Data;

uintptr_t serialize(Data* ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data *>(raw));
}

int main(void) {
    Data info;
    uintptr_t serialized;
    Data *deserialized;

    info.data = 100;
    std::cout << "---------------------BEFORE---------------------"<< std::endl;
    std::cout << "Value: "<< info.data << std::endl;
    std::cout << "Address: " << &info.data << std::endl;

    std::cout << "---------------------SERIALIZATION---------------------" << std::endl;
    serialized = serialize(&info);
    std::cout << "Value (uintptr_t): "<< serialized << std::endl;
    std::cout << "---------------------DESERIALIZATION---------------------" << std::endl;
    deserialized = deserialize(serialized);
    std::cout << "Value: "<< deserialized->data << std::endl;
    std::cout << "Address: " << &deserialized->data << std::endl;
    std::cout << "Address (deserialized): " << deserialized << std::endl;
    std::cout << "Address (info): " << &info << std::endl;
    if (&info.data != &deserialized->data || deserialized != &info)
        std::cout << "F**k! Smth went wrong" << std::endl;
    else
        std::cout << "Ok" << std::endl;    
    return (0);
}