#ifndef Kisi_hpp
#define Kisi_hpp

#include <string>

class Kisi
{
public:
    int height;
    std::string ad;
    int age;
    Kisi();
    Kisi(int, std::string, int);
    ~Kisi();
};

#endif