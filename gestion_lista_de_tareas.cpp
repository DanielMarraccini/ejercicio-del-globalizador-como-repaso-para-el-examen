#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void inputRespuestaMenu(int& respuesta);

vector<string> ejecucionOpciones(int respuesta, vector<string> tareas);

void agregarTareas(vector<string>& tareas);
void verTareas(vector<string> tareas);
void actualizarTareas(vector<string>& tareas);
void eliminarTareas(vector<string>& tareas);

void tareaNoExiste(char& resp, bool& bandera);


int main(){

    int respuesta;

    vector<string> tareas;

    ejecucionOpciones(respuesta, tareas);


    cin.get();
    return 0;
}

void inputRespuestaMenu(int& respuesta){

    bool bandera = false;


    do{

        cout<<"---------Elija una de las siguientes opciones:\n\n";

        cout<<"1. Agregar tarea."<<endl;
        cout<<"2. Ver tarea."<<endl;
        cout<<"3. Actualizar tarea."<<endl;
        cout<<"4. Eliminar tarea."<<endl;
        cout<<"5. Salir."<<endl<<endl;

        cout<<"Respuesta: "; cin>>respuesta;

        if(respuesta < 1 || respuesta > 5){

            cout<<"\n\nOpcion invalida. Debe elegir entre 1-5. Intente de nuevo.\n\n";

        } else{

                bandera = true;
            }

    }while(bandera == false);


    cout<<endl<<endl<<endl;

    cin.ignore();

}

vector<string> ejecucionOpciones(int respuesta, vector<string> tareas){

    do{

        inputRespuestaMenu(respuesta);

        switch(respuesta){

        case 1:
            agregarTareas(tareas); break;
        case 2:
            verTareas(tareas); break;
        case 3:
            actualizarTareas(tareas); break;
        case 4:
            eliminarTareas(tareas); break;
        }

    }while(respuesta != 5);

    return tareas;
}



void agregarTareas(vector<string>& tareas){

    string nuevaTarea;

    cout<<"Ingrese la tarea: "; getline(cin, nuevaTarea);

    tareas.push_back(nuevaTarea);

    cout<<endl<<endl;

    cin.ignore();
}


void verTareas(vector<string> tareas){


    cout<<"Lista de tareas: \n\n";


    for(const string& tarea : tareas){

        cout<<tarea<<endl;
    }

    cout<<endl<<endl;

    cin.ignore();
}


void actualizarTareas(vector<string>& tareas){

    cin.ignore();

    bool bandera = false;

    int ubicacionIndex;

    string tarea;

    char respuesta = 's';

    do{

        cout<<"Cuál tarea desea actualizar?: "; getline(cin, tarea);

        cout<<endl<<endl;

        transform(tarea.begin(), tarea.end(), tarea.begin(), ::tolower);

        for (int i = 0; i < tareas.size(); i++){

            if(tareas[i] == tarea){

                bandera = true;
                ubicacionIndex = i;
                break;
            }
        }

        if(bandera == false){


            tareaNoExiste(respuesta, bandera);
        }

    }while(bandera == false);


    if(respuesta == 's'){

        cout<<"ingrese actualización de la tarea: "; getline(cin, tarea);

        tareas[ubicacionIndex] = tarea;
    }

    cout<<endl<<endl;

}


void eliminarTareas(vector<string>& tareas){

 bool bandera = false;

    int ubicacionIndex;

    string tarea;

    char respuesta = 's';

    do{

        cout<<"Cuál tarea desea eliminar?: "; getline(cin, tarea);

        cout<<endl<<endl;

        transform(tarea.begin(), tarea.end(), tarea.begin(), ::tolower);

        for (int i = 0; i < tareas.size(); i++){

            if(tareas[i] == tarea){

                bandera = true;
                ubicacionIndex = i;
                break;
            }
        }

        if(bandera == false){

            tareaNoExiste(respuesta, bandera);
        }

    }while(bandera == false);


    if(respuesta == 's'){

            string aux;

        for (int i = ubicacionIndex + 1; i<tareas.size();i++){

            aux = tareas[i - 1];
            tareas[i-1] = tareas[i];
            tareas[i] = aux;
        }

        tareas.pop_back();

        cout<<"\nTarea eliminada correctamente.";
    }

    cout<<endl<<endl;

    cin.ignore();
}


void tareaNoExiste(char& resp, bool& bandera){

    do{

        cout<<"La tarea no existe. Desea intentarlo de nuevo?(s/n): "; cin>>resp;

        resp = tolower(resp);

        cout<<endl<<endl;

        switch(resp){

            case 's':
                break;
            case 'n':
                cout<<"Volviendo al menu...";
                bandera = true; break;
            default:
                cout<<"Por favor, ingrese 's' o 'n'.";
                }

        cout<<endl<<endl;

        cin.ignore();

    }while(resp != 's' && resp != 'n');
}
