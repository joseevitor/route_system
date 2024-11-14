#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Vehicle {
public:
    Vehicle(string placa, string descricao, size_t quilometragem)
        : placa(placa), descricao(descricao), quilometragem(quilometragem) {}

    virtual string GetInformation() const {
        return "Placa: " + placa + ", Descrição: " + descricao + ", Quilometragem: " + to_string(quilometragem);
    }

    string getPlaca() const {
        return placa;
    }

protected:
    string placa;
    string descricao;
    size_t quilometragem;
};

#endif // VEHICLE_H
