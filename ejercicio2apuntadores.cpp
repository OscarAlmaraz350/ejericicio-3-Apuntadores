#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Estudiante 
{
    string nombre;
    int ID, calificacion;
};
int Menu()
 {
    int respuesta;
    cout<<"Seleccione una accion"<<endl;
    cout<<""<<endl;
    cout<<"1. Agrega un  estudiante"<<endl;
    cout<<"2. Actualiza de la calificacion de un estudiante"<<endl;
    cout<<"3. Busca estudiantes por su ID"<<endl;
    cout<<"4. Salir"<<endl;
    cin>>respuesta;
    return respuesta;
}
vector<Estudiante> estudiantes;
void agregarEstudiante() 
{
    Estudiante estudiante;
    cout << "Escriba el nombre del estudiante: ";
    cin >> estudiante.nombre;
    cout << "Escriba el ID para el estudiante: (numero) ";
    cin >> estudiante.ID;
    cout << "Escriba la calificación para el estudiante: ";
    cin >> estudiante.calificacion;
    
    estudiantes.push_back(estudiante);
    cout << "El estudiante " << estudiante.nombre << " ha sido agregado." << endl;
}

void actualizarCalificacion() 
{
    int ID;

    cout << "Lista de estudiantes:" << endl;
    for (const Estudiante& estudiante : estudiantes) {
        cout << "ID: " << estudiante.ID
             << ", Nombre: " << estudiante.nombre
             << ", Calificacion: " << estudiante.calificacion << endl;
    }
    
    cout << "Ingrese el ID del estudiante: ";
    cin >> ID;
    bool encontrado = false;
    for (auto& estudiante : estudiantes) 
	{
        if (estudiante.ID == ID) 
		{
            cout << "Ingrese la nueva calificación del estudiante: ";
            int &calif=estudiante.calificacion;
            cin >> calif;
            cout << "La calificación del estudiante " << estudiante.nombre << " se actualizo." << endl;
            encontrado = true;
        }
    }
    if (!encontrado) 
	{
        cout << "No se encontró estudiante con ese identificador." << endl;
    }
}
void buscarEstudiante()
{
    int ID_buscado;
                bool encontrado = false;
                cout << "Ingresa el identificador del estudiante a buscar: ";
                cin >> ID_buscado;
                for (auto& estudiante : estudiantes) 
				{
                    if (estudiante.ID == ID_buscado) 
					{
                        encontrado = true;
                        Estudiante* ptr_estudiante = &estudiante;
                        cout << "Estudiante encontrado: " << endl;
                        cout << "Nombre: " << ptr_estudiante->nombre << endl;
                        cout << "ID: " << ptr_estudiante->ID << endl;
                        cout << "Calificación: " << ptr_estudiante->calificacion << endl;
                    break;
                    }
                }
                if (!encontrado) 
				{
                    cout << "Estudiante no encontrado, intente de nuevo " << endl;
                }
}
int main()
{
int opcion;
    do 
	{
        opcion = Menu();
        switch (opcion) 
		{
            case 1:
                agregarEstudiante();
                break;
            case 2:
                actualizarCalificacion();
                break;
            case 3:
                buscarEstudiante();
                break;
            case 4:
                cout << "Cerrando Aplicacion, lindo dia!" << endl;
                break;
            default:
                cout << "Opcion no valida. Vuelva a intentar." << endl;
                break;
        }
    } while (opcion != 4);
    return 0;
}