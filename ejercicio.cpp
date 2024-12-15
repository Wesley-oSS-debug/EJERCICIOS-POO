/* 2024-119046 Wesley Rivaldo Laura Choquejahua*/

#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
class Empresa{
	private:
		int cantClientes;
		int cantEmpleados;
	public:
		Empresa(int, int); // constructor
		void  mostrarEmpresa();
};

Empresa :: Empresa (int cantClientes, int cantEmpleados){
	this->cantClientes=cantClientes;
	this->cantEmpleados=cantEmpleados;
}

void Empresa :: mostrarEmpresa(){
	cout<<"CANTIDAD DE CLIENTES: "<<cantClientes<<endl;
	cout<<"CANTIDADA DE EMPLEADOS: "<<cantEmpleados<<endl;
}

class Persona{
	protected:
		string nombre;
		string domicilio;
	public:
		Persona(string, string); // constructor
		void virtual mostrarDatos();	
		string getName();
		string getDomicilio();
};

Persona :: Persona(string nombre, string domicilio){
	this->nombre=nombre;
	this->domicilio=domicilio;
}

void Persona :: mostrarDatos(){
	cout<<"NOMBRE : "<<nombre<<endl;
	cout<<"DOMICILIO: "<<domicilio<<endl;
}
string Persona :: getName(){
	return nombre;
}

string Persona::getDomicilio(){
	return domicilio;
}
class Cliente : public Persona{
	private:
		string nivelSoci;
		float limCreditos;
	public:
		Cliente(string,string, string, float); // constructor
		void mostrarDatos();			
};

Cliente :: Cliente (string nombre, string domicilio, string nivelSoci, float limCreditos) : Persona(nombre, domicilio){
	this->nivelSoci=nivelSoci;
	this->limCreditos=limCreditos;
}
void Cliente :: mostrarDatos(){
	Persona :: mostrarDatos();
	cout<<" NIVEL SOCIOECONÓMICO: "<<nivelSoci<<endl;
	cout<<"LÍMITE DE CRÉDITOS: "<<limCreditos<<endl;
}

class Empleado : public Persona{
	private:
		string nivel;
		float salario;
	public:
		Empleado (string, string, string, float); // constructor	
		void mostrarDatos();
		string getNivel();
		float getSalario();
};

Empleado :: Empleado (string nombre, string domicilio, string nivel, float salario) : Persona(nombre, domicilio){
	this->nivel=nivel;
	this->salario=salario;
}

void Empleado :: mostrarDatos(){
	Persona :: mostrarDatos();
	cout<<"NIVEL : "<<nivel<<endl;
	cout<<"SALARIO: "<<salario<<endl;
	cout<<"\n--------------------------------------\n";
}

string Empleado::getNivel(){
	return nivel;
}

float Empleado::getSalario(){
	return salario;
}
int main(){
	SetConsoleOutputCP(CP_UTF8);
	string nombre;
	string domicilio;
	float salario;
	string nivel;
	/*int tam;
	cout<<"Ingrese la cantidad de empleados :"; cin>>tam;
	Empresa *em1;
	em1=new Empresa(0,tam);
	em1->mostrarEmpresa();*/
	//--------------------------------------
		Empleado *arr[3]={
			new Empleado("JUAN","Calle Bolivar","B",3),
			new Empleado("MIGUEL","calle tacna","A",2),
			new Empleado("Wesley","calle Apurimac","A",1)};
	
	// guardar los archivos en .txt
	Empleado *aux;
	ofstream archivo;
	archivo.open("empleados.txt");
	for(int i=0;i<3;i++){
		arr[i]->mostrarDatos();
	}
	
	for(int i=0;i<3;i++){
		for(int j=0;j<2-i;j++){
			if(arr[j]->getSalario()<arr[j+1]->getSalario()){
				aux=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=aux;
			}
		}
	}
	
	if(archivo.is_open()){
		for(int i=0;i<3;i++){
			nombre=arr[i]->getName();
			domicilio=arr[i]->getDomicilio();
			nivel=arr[i]->getNivel();
			salario=arr[i]->getSalario();
			archivo<<nombre<<" "<<domicilio<<" "<<nivel<<" "<<salario<<endl;
		}
		archivo.close();
	}
	
	
	return 0;
}