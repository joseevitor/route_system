
#ifndef HEAVYTRUCK_H
#define HEAVYTRUCK_H

#include "Vehicle.h"
using namespace std;

class HeavyTruck : public Vehicle {
public:
    HeavyTruck(string placa, string descricao, size_t quilometragem, float capacidadeCarga)
        : Vehicle(placa, descricao, quilometragem), capacidadeCarga(capacidadeCarga) {}

    string GetInformation() const override {
        return Vehicle::GetInformation() + ", Capacidade de Carga: " + to_string(capacidadeCarga) + "kg";
    }

private:
    float capacidadeCarga;
};

#endif // HEAVYTRUCK_H
