#include <iostream>
using namespace std;

class Vehiculo {
private:
    string marca;
    int modelo;
    int precio;

public:
    Vehiculo(string ma, int mo, int p) {
        marca = ma;
        modelo = mo;
        precio = p;
    }

    // Getters
    string getMarca() { return marca; }
    int getModelo() { return modelo; }
    int getPrecio() { return precio; }

    // Setters
    void setMarca(string ma) { marca = ma; }
    void setModelo(int mo) { modelo = mo; }
    void setPrecio(int p) {
        if (p > 0) {
            precio = p;
        }
        else {
            cout << "Error: El precio no puede ser negativo." << endl;
        }
    }

    void mostrarInfoVe() {
        cout << "Marca: " << marca
            << "\nModelo: " << modelo
            << "\nPrecio: Q" << precio << endl;
    }
};

class Automovil : public Vehiculo {
protected:
    double kilometraje;

public:
    Automovil(string marca, int modelo, int precio, double kilometraje)
        : Vehiculo(marca, modelo, precio), kilometraje(kilometraje) {
    }

    void mostrarInfoAu() {
        mostrarInfoVe();
        cout << "Kilometraje del Automovil: " << kilometraje << " km recorridos" << endl;
    }
};

class Moto : public Vehiculo {
protected:
    int repuestos;

public:
    Moto(string marca, int modelo, int precio, int repuestos)
        : Vehiculo(marca, modelo, precio), repuestos(repuestos) {
    }

    void mostrarInfoMo() {
        mostrarInfoVe();
        cout << "Usted cuenta con " << repuestos << " repuestos extra" << endl;
    }
};

class Camioneta : public Vehiculo {
protected:
    double peso;

public:
    Camioneta(string marca, int modelo, int precio, double peso)
        : Vehiculo(marca, modelo, precio), peso(peso) {
    }

    void mostrarInfoCam() {
        mostrarInfoVe();
        cout << "La camioneta tiene una capacidad de carga de: " << peso << " toneladas" << endl;
    }
};

class Cliente : public Vehiculo {
protected:
    string nombre, compra;

public:
    Cliente(string marca, int modelo, int precio, string nombre, string compra)
        : Vehiculo(marca, modelo, precio), nombre(nombre), compra(compra) {
    }

    void mostrarInfoCl() {
        mostrarInfoVe();
        cout << "El cliente se llama: " << nombre << " y ha comprado " << compra << " de agencia." << endl;
    }
};

int main() {
    Automovil a1("Toyota Corolla", 2022, 25000, 31234);
    a1.mostrarInfoAu();
    cout << endl;

    Moto m1("Yamaha R1", 2021, 18000, 4);
    m1.mostrarInfoMo();
    cout << endl;

    Camioneta c1("Ford Ranger", 2020, 30000, 1.5);
    c1.mostrarInfoCam();
    cout << endl;

    Cliente cl1("Toyota Corolla", 2022, 25000, "Juan", "Toyota Yaris");
    cl1.mostrarInfoCl();
    cout << endl;

    return 0;
}
