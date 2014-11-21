#include <cstdlib>
#include <iostream>
#include <new>
#include <stack>
using namespace std;


class ListaEnlazada
{
	public:
		double numero;
		ListaEnlazada * siguiente;
		ListaEnlazada(){ numero = 0; siguiente = NULL;}
		void RecorreLista(ListaEnlazada*inicio);
		void SetNumero(double tmp) { numero = tmp; }
};

ListaEnlazada * inicio;
ListaEnlazada * actual;
ListaEnlazada * ultimo;

void NuevoElemento(double numero)
{
	if(inicio==NULL)
	{
		inicio = new ListaEnlazada;
		inicio->SetNumero(numero);
		ultimo=inicio;
	}
	else
	{
		actual = new ListaEnlazada;
		ultimo->siguiente = actual;
		actual->SetNumero(numero);
		ultimo=actual;
	}
}

int main()
{
	double tmp;
	
	std::stack<double> pila;
	
	for(int i=0; i<100; i++)
	{
		tmp = double(rand());
		cout<<i+1<<": "<<tmp<<endl;
		NuevoElemento(tmp);
	}
	
	cout<<endl;
	cout<<"Primero: "<<inicio->numero<<endl;
	cout<<"Ultimo: "<<ultimo->numero<<endl;
	cout<<endl;
	
	actual=inicio;
	
	while(actual != NULL)
	{
		pila.push(actual->numero);
		actual = actual->siguiente;
	}
	
	while (!pila.empty())
	{
	    cout << pila.top()<<endl;
	    pila.pop();
	}
	
	delete inicio;
	delete ultimo;
	delete actual;
	
	return 0;
}
