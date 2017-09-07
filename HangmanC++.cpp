#include <iostream>
#include <windows.h>

using namespace std;

void pedirletra(int &intentos_restantes, string palabra, string respuesta);
string llenar_respuesta (string palabra);

int main()
{
    string palabra;
    string respuesta;

    int intentos_restantes = 5;
    cout << "Palabra" << endl;
    cin >> palabra;
    respuesta = llenar_respuesta(palabra);
    system("cls");
    pedirletra(intentos_restantes, palabra, respuesta);
    return 0;
}

void pedirletra(int &intentos_restantes, string palabra, string respuesta)
{

    char letra;
    bool conf;
    while (intentos_restantes > 0)
    {
        system("cls");
        cout << "afjeaiogahgr: " << respuesta << endl;
        cout << "Palabra hasta ahora: " << respuesta << endl;
        conf = false;
        cout << "Inserte una letra - Intentos restantes: " << intentos_restantes << endl;
        cin >> letra;

        for (int i = 0; i < palabra.size(); i++) //Comprobar existencia de la letra en la palabra
            {
              if (letra == palabra[i])
                {
                    conf = true;
                    palabra[i] = ' ';
                    respuesta[i] = letra;
                }
            }
            if (conf)
            {
                cout << "Encontraste la letra " << letra  << endl;
                system("pause");
            }
            else
            {
                cout << "Ninguna letra coincide" << endl;
                system("pause");
                intentos_restantes--;
            }
    }
}

string llenar_respuesta (string palabra)
{
    for (int i = 0 ; i < palabra.size(); i++){
        palabra[i] = '-';
    }
    return palabra;
}


