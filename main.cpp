#include <iostream>
#include "bird.h"

class Duck : public Bird{
    public:
    Duck() : Bird("Duck"){
        cry();
    }

    void cry() override{
        std::cout<<"Quack!"<<std::endl;
    }

    void fly() override{
        std::cout <<"This bird can fly." <<std::endl;
    }

    void swim() override{
        std::cout <<"This bird can swim."<<std::endl;
    }

    ~Duck() override{
        cry();
    }
};

class Penguin : public Bird{
    public:
    Penguin() : Bird("Penguin") {
        cry();
    }

    void cry() override {
        std::cout << "Squawk!" << std::endl;
    }

    void fly() override {
        std::cout << "This bird can't fly." << std::endl;
    }

    void swim() override{
        std::cout<<"This bird can swim."<<std::endl;
    }

    ~Penguin() override {
        cry();
    }
};

class Eagle : public Bird{
    public:
    Eagle() : Bird("Eagle"){
        cry();
    }

    void cry() override{
        std::cout <<"Screech!"<<std::endl;
    }

    void fly() override{
        std::cout<<"This bird can fly."<<std::endl;
    }

    void swim() override{
        std::cout<<"This bird can't swim." <<std::endl;
    }

    ~Eagle() override{
        cry();
    }
};


int main() {
    Bird* birds[] = {
        new Duck(),
        new Penguin(),
        new Eagle()
    };
    std::cout << "----------------------\n";

    const int numBirds = sizeof(birds) / sizeof(birds[0]);

    for (int i = 0; i < numBirds; ++i) {
        std::cout << "Bird #" << i + 1 << ":\n";
        birds[i]->display();
        birds[i]->fly();
        birds[i]->swim();
        std::cout << "----------------------\n";
    }

    for (int i = 0; i < numBirds; ++i) {
        delete birds[i];
    }

    return 0;
};