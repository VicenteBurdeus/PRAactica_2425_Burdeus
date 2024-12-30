#include <vector>
#include <iostream>


//Prototipos
template <typename T>
int Separar(std::vector<T> &v, int ini, int fin);
template <typename T>
void QuickSort(std::vector<T> &v, int ini, int fin);
template <typename T>
int BusquedaBinaria(T x, std::vector<T> v, int ini, int fin);
template <typename T>
int BusquedaBinaria_INV(T x, std::vector<T> v, int ini, int fin);



template <typename T>
int BusquedaBinaria(T x, std::vector<T> v, int ini, int fin){
	if(ini>fin){
		return -1;
	}
	int medio=(ini+fin)/2;
	if(v[medio]==x){
		return medio;
	}
	else if(v[medio]>x){
		return BusquedaBinaria(x,v,ini,medio-1);
	}
	else{
		return BusquedaBinaria(x,v,medio+1,fin);
	}
}

template <typename T>
int BusquedaBinaria_INV(T x, std::vector<T> v, int ini, int fin){
	if(ini>fin){
		return -1;
	}
	int medio=(ini+fin)/2;
	if(v[medio]==x){
		return medio;
	}
	else if(v[medio]<x){
		return BusquedaBinaria_INV(x,v,ini,medio-1);
	}
	else{
		return BusquedaBinaria_INV(x,v,medio+1,fin);
	}
}


template <typename T>
void QuickSort(std::vector<T> &v, int ini, int fin){
	if(ini<fin){
		int pivot = Separar(v, ini, fin);
		QuickSort(v, ini, pivot-1);
		QuickSort(v, pivot+1, fin);
	}
}

template <typename T>
int Separar(std::vector<T> &v, int ini, int fin){
	T x=v[fin];
	int i=ini;
	for (int j=ini;j<fin;j++){
		if(v[j]<=x){
			T aux=v[j];
			v[j]=v[i];
			v[i]=aux;
			i++;
		}
	}
	T aux=v[i];
	v[i]=v[fin];
	v[fin]=aux;
	return i;
}
