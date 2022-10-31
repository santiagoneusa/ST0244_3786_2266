#include <iostream>
using namespace std;
#include "methods.h"

int main()
{

    cout << " -- Bienvenido a Wordle --" << endl;
    int variable_entrada;
    cout <<"¿Desea jugar? (sí = 1/no = 0): "; cin >> variable_entrada;

    if (variable_entrada == 0)
    {
        cout << "\nGracias por entrar a Wordle." << endl;
    }
    else
    {

        bool ganar;
        int contador_perdidas = 0;

        while(variable_entrada != 0)
        {

            cout << "\nEl juego tiene una dificultad aleatoria de 6 a 10 letras." << endl;
            
            // se genera una palabra con la función palabra_aleatoria() para dar inicio al juego
            string palabra_computador = palabra_aleatoria();
            

            // si se quiere editar la palabra para efecto de un test, hacerlo aquí:
            // string palabra_computador = "GATO";
            
            
            cout << "\nTu palabra tiene " << palabra_computador.length() << " letras, ¡Buen juego!" << endl;
            
            // la función palabra_a_lista retorna un nodo puntero, por lo tanto lo guardamos en otro nodo puntero
            Node* head_palabra_computador = palabra_a_lista(palabra_computador);

            cout << "\nTienes 6 intentos para adivinar la palabra.\n";
            
            for(int i = 0; i < 6; i++)
            {   
                cout << "Intento " << i + 1 << ": ";
                
                string palabra_usuario;
                bool comprobacion_longitud = true;
                
                while(comprobacion_longitud)
                {
                    cin >> palabra_usuario;

                    if(palabra_usuario.length() > palabra_computador.length() || palabra_usuario.length() < palabra_computador.length())
                    {
                        cout << "Intento no válido, ingrese una palabra de " << palabra_computador.length() << " letras.\nIntento " << i + 1 << ": ";
                    }
                    else
                    {
                        break;
                    }
                }

                Node* head_palabra_usuario = palabra_a_lista(palabra_usuario);

                modificar_colores(head_palabra_computador, head_palabra_usuario);
                descartar_elemento_repetido(head_palabra_usuario);

                ganar = imprimir_con_colores(head_palabra_usuario);

                if(ganar == true) break;

                reset(head_palabra_usuario);

                if(ganar == false) 
                {
                    contador_perdidas++;
                    if(contador_perdidas > 5)
                    {
                        cout << "\n    Perdiste :(" << endl;
                        cout << "La palabra era: ";
                        rojo(head_palabra_computador);
                        reset(head_palabra_computador);
                        cout<< "" << endl;
                        cout<< "" << endl;
                    }
                }
            
            }

        cout <<"¿Desea seguir jugando? (sí = 1/no = 0): "; cin >> variable_entrada;

        }

        cout << "\nGracias por entrar a Wordle." << endl;

    }

    return 0;
    
}
