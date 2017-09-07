#include <iostream>
#include <windows.h>

using namespace std;

void pedirletra(int &intentos_restantes, string palabra, string respuesta);
string llenar_respuesta (string palabra);
void letras_usadas (char letra, int &usos, array letras[]);

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
    int usos;
    string fin = palabra;
    array letras[27];
    for (int i = 0 ; i < 27 ; i++)
    {
        letras[i] = 0;
    }
    while (intentos_restantes > 0)
    {
        system("cls");
        cout << "afjeaiogahgr: " << respuesta << endl;
        cout << "Palabra hasta ahora: " << respuesta << endl;
        conf = false;
        cout << "Inserte una letra - Intentos restantes: " << intentos_restantes << endl;
        cin >> letra;
        letras_usadas(letra,usos,letras);
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
            if (respuesta == fin)
            {
                system("cls");
                cout << "Ganaste!" << endl;
                intentos_restantes = 0;
            }
    }
    if (respuesta != fin)
    {
        system("cls");
        cout << "Perdiste mongo" << endl;
    }
}

string llenar_respuesta (string palabra)
{
    for (int i = 0 ; i < palabra.size(); i++){
        palabra[i] = '-';
    }
    return palabra;
}


void letras_usadas (char letra, int &usos, array letras[])
{
    for (usos ; usos < 27 ; usos++)
    {
        letras[usos = letra];
    }

}
