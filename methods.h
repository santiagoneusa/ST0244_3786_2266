#include "iostream"
#include "string"

using namespace std;

// clase nodo con constructor
class Node 
{

    public:
    
        char letra;
        string color;
        Node* next; // nodo puntero que contendrá la dirección de memoria del siguiente
    
    
    // constructor
    Node(char letra)
    {
        this -> letra = letra;
        this -> color = "blanco";
        next = NULL; // por defecto los nodos que se crean apuntan al vacío
    }

};

// función palabra pseudoaleatoria:
string palabra_aleatoria()
{

    // arreglo con las palabras
    string palabras[30] = {"ABUELA", "ABISMO", "BARRIO", "BLANCO", "CABEZA", "COCTEL", "ABOGADO", "EDUCADO", "DEPORTE", "FUNERAL", "GIGANTE", "IMPONER", "ELEFANTE", "SERPIENTE", "LEOPARDO", "VENGANZA", "VENTANAL", "TINIEBLA", "LABERINTO", "OBEDIENTE", "XENOFOBIA", "NADADORES", "IDEALIZAR", "HABITABLE", "BIBLIOTECA", "YERBATEROS", "TABAQUISMO", "NACIONALES", "NACIMIENTO", "HABICHUELA"};

    // crea número aleatorio de 1 a 30
    srand (time(NULL));
    int numero_random = rand() % 30;

    // se retorna la palabra en la posición random
    return palabras[numero_random];

}

// función convertir palabra a lista:
Node* palabra_a_lista(string palabra)
{

    // creamos un nodo puntero que sea la cabeza y contenga la primera letra
    Node* head = new Node(palabra[0]);

    // ahora un nodo puntero que va a servir de variable de intercambio
    Node* temporal = head;

    // un ciclo que recorra de la segunda a la última letra
    for (int letra_en_palabra = 1; letra_en_palabra < palabra.size(); letra_en_palabra++)
    {
        // el siguiente de temporal será un nuevo nodo con la siguiente letra de la palabra
        temporal->next = new Node(palabra[letra_en_palabra]);
        // actualizar temporal para que sea su siguiente
        temporal = temporal->next;
    }

    // retornamos el nodo inicial para otras operaciones, recordemos que es una lista simplemente enlazada
    return head;

}

// función comparar listas:
bool comparar_listas(Node* head_palabra_computador, Node* head_palabra_usuario)
{

    // creamos 2 variables temporales para no modificar las cabezas de las listas
    Node* temporal_computador = head_palabra_computador;
    Node* temporal_usuario = head_palabra_usuario;

    // mientras una u otra se acabe, aunque la comprobación de longitud la hacemos desde el main
    while(temporal_computador || temporal_usuario)
    {
        // comparación de letras
        if(temporal_computador->letra != temporal_usuario->letra) return false;
        // se asignan nuevos valores (siguiente)
        temporal_computador = temporal_computador->next;
        temporal_usuario = temporal_usuario->next;
    }

    return true;

}

// función modificar colores: esta función toma una letra de la palabra ingresada por el usuario
// y la compara con todas las letras de la palabra computador
void modificar_colores(Node* head_palabra_computador, Node* head_palabra_usuario)
{

    // creación de variables temporales, para no modificar las que vienen como parámetro
    Node* temporal_computador = head_palabra_computador;
    Node* temporal_usuario = head_palabra_usuario;

    // creación de contadores para llevar seguimiento de la posición
    int contador_computador = 0;
    int contador_usuario = 0;

    // comparar cada letra de la palabra del usuario con la palabra del computador
    while(temporal_usuario != NULL)
    {
        // como estas variables se ven alteradas en el ciclo interno, se inicializan en cada iteración del ciclo externo
        temporal_computador = head_palabra_computador;
        contador_computador = 0;

        while(temporal_computador != NULL)
        {
            // primer condicional: que la letra y la posición sean iguales
            if(temporal_usuario->letra == temporal_computador->letra && contador_usuario == contador_computador)
            {
                // se modifica el color del nodo, que por defecto viene blanco
                temporal_usuario->color = "verde";
                break;
            }
            // segundo condicional: que la letra sea igual pero la posición diferente
            else if(temporal_usuario->letra == temporal_computador->letra && contador_usuario != contador_computador)
            {

                // se modifica el color del nodo, que por defecto viene blanco
                temporal_usuario->color = "amarillo";
            
            }
            
            // en caso de que la letra no se encuentre, no se hará nada

            // incremento
            temporal_computador = temporal_computador->next;
            contador_computador++;
        }
        
        // incremento
        temporal_usuario = temporal_usuario->next;
        contador_usuario++;
    }

}


// función descartar elemento repetido:
void descartar_elemento_repetido(Node* head_palabra_usuario)
{

    // si la letra está en amarillo, mirar si está en otra posición en verde, y si está en verde, cambiar a blanco

    Node* temporal = head_palabra_usuario;
    Node* comparar = head_palabra_usuario;


    while(temporal != NULL)
    {
        if(temporal->color == "amarillo")
        {
            while(comparar != NULL)
            {
                if(temporal->letra == comparar->letra && comparar->color == "verde")
                {
                    temporal->color = "blanco";
                }

                comparar = comparar->next;
            }
        }
        
        temporal = temporal->next;
    }

}

bool imprimir_con_colores(Node* head_palabra_usuario)
{

    Node* temporal_usuario = head_palabra_usuario;
    int contador_nodos = 0;
    int contador_verdes = 0;

    cout << "-> ";

    while(temporal_usuario!= NULL)
    {
        // si el color es verde, imprimir verde
        if(temporal_usuario->color == "verde")
        {
            string verde("\033[0;32m");
            string reset("\033[0m");
            cout << verde << temporal_usuario->letra << reset;
            contador_verdes++;
        }
        // si el color es amarillo, imprimir amarillo
        else if(temporal_usuario->color == "amarillo")
        {
            string amarillo("\033[0;33m");
            string reset("\033[0m");
            cout << amarillo << temporal_usuario->letra << reset;
        }
        // si el color es blanco (porque no se modificó), imprimir blanco
        else
        {
            cout << temporal_usuario->letra;
        }

        // incremento
        temporal_usuario = temporal_usuario->next;
        contador_nodos++;
    }
    
    // un salto de línea para que se vea más bonito
    cout << "\n";
    if(contador_verdes == contador_nodos)
    {
        cout << "\n";
        cout << "   ¡Ganaste el juegooo!" << endl;
        cout << "\n";
        return true;
    }
    else return false;

}

void rojo(Node* head)
{
    Node* temporal = head;

    while(temporal != NULL)
    {
        temporal->color = "rojo";
        temporal = temporal->next;
    }

    temporal = head;

    while(temporal != NULL)
    {
        string rojo("\033[0;31m");
        string reset("\033[0m");
        cout << rojo << temporal->letra << reset;
        temporal = temporal->next;
    }
}

void reset(Node* head)
{
    while(head != NULL)
    {
        head->color = "blanco";
        head = head->next;
    }
}
