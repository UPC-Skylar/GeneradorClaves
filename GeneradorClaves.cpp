#include "Header.h"

class Contrasenia {
private:
	int longitud;
	string clave;
public:
	Contrasenia() { this->longitud = 8; this->clave = ""; }
	Contrasenia(int _longitud) { this->longitud = _longitud; }
	//Metodos
	bool esSeguro() {
		int cantMinus = 0, cantMayus = 0, cantNum = 0;
		for (int i = 0; i < this->longitud; i++) {
			if (islower(this->clave[i])) cantMinus++;
			if (isupper(this->clave[i])) cantMayus++;
			if (isdigit(this->clave[i])) cantNum++;
		}
		//Final process
		if (cantMinus > 1 && cantMayus > 2 && cantNum > 5) {
			return true;
		}
		else {
			return false;
		}
	}

	void generarClave() {
		string caracteres = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
		for (int i = 0; i < this->longitud; i++) {
			int posicion = rand() % caracteres.size();
			this->clave += caracteres[posicion];
		}
	}
	//Integracion del metodo set y get
	void setLongitud(int _longitud) { this->longitud = _longitud; }
	int getLongitud() { return this->longitud; }
	string getClave() { return this->clave; }
};

int validaLongitud() {
	int longitud;
	do {
		cout << "\nNOTA: Debe ser mayor o igual a 8 caracteres\n" <<
			"Ingrese la longitud de su contrase�a: ";
		cin >> longitud;
	} while (longitud < 8);
	return longitud;
}

void menu() {
	string eleccion = "";
	Contrasenia key = Contrasenia();
	//Mensaje de bienvenida
	cout << "---------------------- GENERADOR DE CONTRASE�AS ----------------------\n"
		<< "Bienvenido al generador de contrase�as" << endl;

	/* Preguntar al usuario si desea generar la contrase�a, sino
	   se asigna por defecto */
	do {
		cout << "�Desea ingresar la longitud de la contrase�a? (si, no):  ";
		cin >> eleccion;
	} while (eleccion != "si" && eleccion != "no" && eleccion != "Si"
		&& eleccion != "SI" && eleccion != "No" && eleccion != "NO");

	if (eleccion != "")
		key.setLongitud(validaLongitud());

	key.generarClave();

	//Mensajes de salida
	cout << "\n-------------------------------------------------------\n";
	cout << "La longitud de la contrase�a es: " << key.getLongitud() << endl;
	cout << "La contrase�a generada es: " << key.getClave() << endl;
	//Verificacion de la seguridad de la contrase�a
	cout << "La contrase�a " << (key.esSeguro() == 0 ? "NO" : "SI")
		<< " es segura" << endl;
}

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "");

	while (1) {
		system("cls");
		menu();
		_getch();
	}
	return 0;
}