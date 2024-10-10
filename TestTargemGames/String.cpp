#pragma warning(disable: 4996)

#include "String.h"


String::String() : data(nullptr) {
    data = new char[1];
    data[0] = '\0';
};

String::String(char* str)
{
    if (str == nullptr) {
        data = new char[1];
        data[0] = '\0';
    }
    else {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
        data[strlen(data)] = '\0';
    }
}
String::String(const char* str) {
    data = new char[strlen(str) + 1];
    strcpy(data, str);
    data[strlen(data)] = '\0';
}
String::String(const String& source)
{
    data = new char[strlen(source.data) + 1];
    strcpy(data, source.data);
    data[strlen(source.data)] = '\0';
}

String::String(String&& source)
{
    data = source.data;
    source.data = nullptr;
}


void String::Print() {
    std::cout << data << std::endl;
}


