#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
using namespace std;

class Car : public Vehicle {
public:
    Car(string placa, string descricao, size_t quilometragem, int numeroPortas)
        : Vehicle(placa, descricao, quilometragem), numeroPortas(numeroPortas) {}

    string GetInformation() const override {
        return Vehicle::GetInformation() + ", Número de Portas: " + to_string(numeroPortas);
    }

private:
    int numeroPortas;
};

#endif // CAR_H
