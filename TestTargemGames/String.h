#pragma once
#pragma warning(disable: 4996)

#include <iostream>
using std::ostream;
using std::istream;

class String
{
private:
    friend String operator+(const String& lhs, const String& rhs);
    friend String operator+=(const String& lhs, const String& rhs);
    char* data;

public:
    String();
    String(char* str);
    String(const char* str);
    String(const String& source); //copy
    String(String&& source);    // move

    void Print();

    ~String() { delete data; }

    String& operator+=(const String& b) {
        *this += b.data;
        return *this;
    }
    String& operator+=(const char* b) {
        int length = strlen(data) + strlen(b);
        char* buff = new char[length + 1];

        strcpy(buff, data);
        strcat(buff, b);
        buff[length] = '\0';

        data = buff;
        //delete[] buff;
        return *this;
    }

    String operator+(const String& b) {
        String temp = *this + b.data;
        return temp;
    }
    String operator+(const char* b) {
        int length = strlen(data) + strlen(b);
        char* buff = new char[length + 1];

        strcpy(buff, data);
        strcat(buff, b);
        buff[length] = '\0';

        String temp{ buff };
        delete[] buff;
        return temp;
    }

    String& operator=(const String& b) {
        if (this == &b)
            return *this;
        delete[] data;
        data = new char[strlen(b.data) + 1];
        strcpy(data, b.data);
        return *this;
    }
    /*
    bool operator < (const String& b) const {
        int ret = strcmp(data, b.data);
        return ret < 0;
    }
    */
    bool operator < (const String& b) const {
        int i = 0;
        int stop = strlen(data) < strlen(b.data) ? strlen(data) : strlen(b.data);
        while (i < stop) {
            if (tolower(data[i]) < tolower(b.data[i]))
                return true;
            if(tolower(data[i]) > tolower(b.data[i]))
                return false;
            i++;
        }
        return i == strlen(data);
    }
};


