
#ifndef LIGHTTRUCK_H
#define LIGHTTRUCK_H

#include "Vehicle.h"
using namespace std;

class LightTruck : public Vehicle {
public:
    LightTruck(string placa, string descricao, size_t quilometragem, float capacidadeCarga)
        : Vehicle(placa, descricao, quilometragem), capacidadeCarga(capacidadeCarga) {}

    string GetInformation() const override {
        return Vehicle::GetInformation() + ", Capacidade de Carga: " + to_string(capacidadeCarga) + "kg";
    }

private:
    float capacidadeCarga;
};

#endif // LIGHTTRUCK_H
