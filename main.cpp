#include <iostream>
#include <vector>
#include <string>
#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Light_Truck.h"
#include "Heavy_Truck.h"

using namespace std;

void cadastrarVeiculo(vector<Vehicle*>& vehicles) {
    int tipo;
    string placa, descricao;
    size_t quilometragem;
    int numeroPortas, capacidadePassageiros;
    float capacidadeCarga;

    cout << "Escolha o tipo de veículo:" << endl;
    cout << "1. Carro" << endl;
    cout << "2. Ônibus" << endl;
    cout << "3. Caminhão Leve" << endl;
    cout << "4. Caminhão Pesado" << endl;
    cout << "Digite o tipo de veículo: ";
    cin >> tipo;

    cout << "Digite a placa do veículo: ";
    cin >> placa;
    cout << "Digite a descrição do veículo: ";
    cin.ignore();  // Limpa o buffer de entrada
    getline(cin, descricao);
    cout << "Digite a quilometragem do veículo: ";
    cin >> quilometragem;

    Vehicle* veiculo = nullptr;

    switch (tipo) {
        case 1:
            cout << "Digite o número de portas do carro: ";
            cin >> numeroPortas;
            veiculo = new Car(placa, descricao, quilometragem, numeroPortas);
            break;
        case 2:
            cout << "Digite a capacidade de passageiros do ônibus: ";
            cin >> capacidadePassageiros;
            veiculo = new Bus(placa, descricao, quilometragem, capacidadePassageiros);
            break;
        case 3:
            cout << "Digite a capacidade de carga do caminhão leve: ";
            cin >> capacidadeCarga;
            veiculo = new LightTruck(placa, descricao, quilometragem, capacidadeCarga);
            break;
        case 4:
            cout << "Digite a capacidade de carga do caminhão pesado: ";
            cin >> capacidadeCarga;
            veiculo = new HeavyTruck(placa, descricao, quilometragem, capacidadeCarga);
            break;
        default:
            cout << "Tipo de veículo inválido!" << endl;
            return;
    }

    vehicles.push_back(veiculo);
    cout << "Veículo cadastrado com sucesso!" << endl;
}

void mostrarRelatorios(vector<Vehicle*>& vehicles) {
    for (auto& v : vehicles) {
        cout << "Veículo: " << v->GetInformation() << endl;
    }
}

void pesquisarVeiculo(vector<Vehicle*>& vehicles) {
    string placa;
    cout << "Digite a placa do veículo: ";
    cin >> placa;

    Vehicle* veiculoEscolhido = nullptr;
    for (auto& v : vehicles) {
        if (v->getPlaca() == placa) {
            veiculoEscolhido = v;
            break;
        }
    }

    if (veiculoEscolhido == nullptr) {
        cout << "Veículo não encontrado!" << endl;
    } else {
        cout << "Veículo encontrado: " << veiculoEscolhido->GetInformation() << endl;
    }
}

int main() {
    vector<Vehicle*> vehicles;
    int opcao;

    do {
        cout << "Menu de Opções:" << endl;
        cout << "1. Cadastrar Veículo" << endl;
        cout << "2. Mostrar Relatórios" << endl;
        cout << "3. Pesquisar Veículo" << endl;
        cout << "4. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarVeiculo(vehicles);
                break;
            case 2:
                mostrarRelatorios(vehicles);
                break;
            case 3:
                pesquisarVeiculo(vehicles);
                break;
            case 4:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
        }

    } while (opcao != 4);

    // Liberar a memória alocada
    for (auto& v : vehicles) {
        delete v;
    }

    return 0;
}

