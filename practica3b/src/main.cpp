#include <iostream>
#include <cstring>
#include <string>


using namespace std;



struct Conjunto{
string *datos;
int util;
};

bool pertenece(Conjunto &c, string &elem) {

    for(int i = 0; i < c.util; i++) {
        if(c.datos[i] == elem) return true;
    }

    return false;
}

Conjunto union1(Conjunto &c1, Conjunto &c2){

    int contador=c1.util;

    for (int i = 0; i < c2.util; i++){//cuenta cuantos datos de c2 no hay en c1

        if(!pertenece(c1,c2.datos[i])){
            contador++;
        }

    }
    
    Conjunto aux;
    int nuevo_util = contador;
    aux.datos = new string[nuevo_util];
    aux.util = 0;

    for (int i = 0; i < c1.util; i++)
    {
        aux.datos[aux.util] = c1.datos[i];
        aux.util++;
    }

    for (int i = 0; i < c2.util; i++)
    {
        if(!pertenece(c1,c2.datos[i])){
            aux.datos[aux.util] = c2.datos[i]; 
            aux.util++;
        }
    }

    return aux;
    
}

Conjunto interseccion(Conjunto &c1, Conjunto &c2){
    
    int contador = 0;

    // Contar elementos comunes
    for (int i = 0; i < c1.util; i++){
        if(pertenece(c2, c1.datos[i])){
            contador++;
        }
    }

    Conjunto aux;
    aux.datos = new string[contador];
    aux.util = 0;

    // Guardar elementos comunes
    for (int i = 0; i < c1.util; i++){
        if(pertenece(c2, c1.datos[i]) && !pertenece(aux, c1.datos[i])){
            aux.datos[aux.util] = c1.datos[i];
            aux.util++;
        }
    }

    return aux;

}


int main(){
Conjunto c1;
Conjunto c2;


c1.util = 3;
c1.datos = new string[3] {"Edward","Greed","Sin"};
 
c2.util = 3;
c2.datos = new string[3] {"Harry","Edward","Elrick"};

Conjunto u = union1(c1, c2);
Conjunto i = interseccion(c1, c2);

cout << "Union: ";
for(int j = 0; j < u.util; j++) {
    cout << u.datos[j] << " ";
}
   
    
cout << "\nInterseccion: ";
for(int j = 0; j < i.util; j++) {
    cout << i.datos[j] << " ";
}
    
cout << endl;

// Liberar memoria
delete[] c1.datos;
delete[] c2.datos;
delete[] u.datos;
delete[] i.datos; 

return 0;

}