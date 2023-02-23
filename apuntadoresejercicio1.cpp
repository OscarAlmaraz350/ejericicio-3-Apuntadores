#include <iostream>
using namespace std;

int main() 
{
    int n;
    cout << "¿Que tan grande es la lista?, escribe la longitud de la lista ";
    cin >> n;
    int lista[n];
    for (int i = 0; i < n; i++) 
	{
        cout << "Ingresa el numero " << i+1 << ": ";
        cin >> lista[i];
    }
    int* max = &lista[0]; 
    int* min = &lista[0];
    for (int i = 1; i < n; i++) 
	{ 
        if (lista[i] > *max) 
		{ 
        max = &lista[i]; 
        }
        if (lista[i] < *min) 
		{
        min = &lista[i]; 
        }
    }
    int &VMax=*max, &VMin=*min, x;
    cout << "El numero mayor de la lista es: " << VMax << endl; 
    cout << "El numero menor de la lista es: " << VMin << endl;
    cout <<"Escribe algun numero que este dentro del rango"<<endl;
    
    cin>>x;
    
     if (x<VMax & x>VMin){
        cout<<"El numero esta entre el mayor y el menor"<<endl;
     }
	 else{
        cout<<"El numero no se encuentra en el rango del valor max y el valor min";
     }
    return 0;
}
