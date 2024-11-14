
#ifndef BUS_H
#define BUS_H

#include "Vehicle.h"
using namespace std;

class Bus : public Vehicle {
public:
    Bus(string placa, string descricao, size_t quilometragem, int capacidadePassageiros)
        : Vehicle(placa, descricao, quilometragem), capacidadePassageiros(capacidadePassageiros) {}

    string GetInformation() const override {
        return Vehicle::GetInformation() + ", Capacidade de Passageiros: " + to_string(capacidadePassageiros);
    }

private:
    int capacidadePassageiros;
};

#endif // BUS_H
