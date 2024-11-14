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

    cout << "Escolha o tipo de ve�culo:" << endl;
    cout << "1. Carro" << endl;
    cout << "2. �nibus" << endl;
    cout << "3. Caminh�o Leve" << endl;
    cout << "4. Caminh�o Pesado" << endl;
    cout << "Digite o tipo de ve�culo: ";
    cin >> tipo;

    cout << "Digite a placa do ve�culo: ";
    cin >> placa;
    cout << "Digite a descri��o do ve�culo: ";
    cin.ignore();  // Limpa o buffer de entrada
    getline(cin, descricao);
    cout << "Digite a quilometragem do ve�culo: ";
    cin >> quilometragem;

    Vehicle* veiculo = nullptr;

    switch (tipo) {
        case 1:
            cout << "Digite o n�mero de portas do carro: ";
            cin >> numeroPortas;
            veiculo = new Car(placa, descricao, quilometragem, numeroPortas);
            break;
        case 2:
            cout << "Digite a capacidade de passageiros do �nibus: ";
            cin >> capacidadePassageiros;
            veiculo = new Bus(placa, descricao, quilometragem, capacidadePassageiros);
            break;
        case 3:
            cout << "Digite a capacidade de carga do caminh�o leve: ";
            cin >> capacidadeCarga;
            veiculo = new LightTruck(placa, descricao, quilometragem, capacidadeCarga);
            break;
        case 4:
            cout << "Digite a capacidade de carga do caminh�o pesado: ";
            cin >> capacidadeCarga;
            veiculo = new HeavyTruck(placa, descricao, quilometragem, capacidadeCarga);
            break;
        default:
            cout << "Tipo de ve�culo inv�lido!" << endl;
            return;
    }

    vehicles.push_back(veiculo);
    cout << "Ve�culo cadastrado com sucesso!" << endl;
}

void mostrarRelatorios(vector<Vehicle*>& vehicles) {
    for (auto& v : vehicles) {
        cout << "Ve�culo: " << v->GetInformation() << endl;
    }
}

void pesquisarVeiculo(vector<Vehicle*>& vehicles) {
    string placa;
    cout << "Digite a placa do ve�culo: ";
    cin >> placa;

    Vehicle* veiculoEscolhido = nullptr;
    for (auto& v : vehicles) {
        if (v->getPlaca() == placa) {
            veiculoEscolhido = v;
            break;
        }
    }

    if (veiculoEscolhido == nullptr) {
        cout << "Ve�culo n�o encontrado!" << endl;
    } else {
        cout << "Ve�culo encontrado: " << veiculoEscolhido->GetInformation() << endl;
    }
}

int main() {
    vector<Vehicle*> vehicles;
    int opcao;

    do {
        cout << "Menu de Op��es:" << endl;
        cout << "1. Cadastrar Ve�culo" << endl;
        cout << "2. Mostrar Relat�rios" << endl;
        cout << "3. Pesquisar Ve�culo" << endl;
        cout << "4. Sair" << endl;
        cout << "Escolha uma op��o: ";
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
                cout << "Op��o inv�lida!" << endl;
        }

    } while (opcao != 4);

    // Liberar a mem�ria alocada
    for (auto& v : vehicles) {
        delete v;
    }

    return 0;
}

