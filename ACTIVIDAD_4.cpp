#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Estudiante{
private:
string nombre;
int a_nacimiento;
double promedio;
int edad;
double presupuesto=0;
public:

Estudiante(){
    nombre="NN";
    a_nacimiento=0;
    promedio=0;
    edad=0;
    presupuesto=0;
    
}
Estudiante(string nombre_,int a_nacimiento_,double promedio_,double presupuesto_){
    nombre=nombre_;
    a_nacimiento=a_nacimiento_;
    promedio=promedio_;
    edad=2026-a_nacimiento;
    presupuesto=presupuesto_;
}
void setEstudiante(){
    cout<<"Ingrese el nombre del Estudiante:";cin>>nombre;
    cout<<"Ingrese el anio de nacimiento:";cin>>a_nacimiento;
a_nacimiento=validarAnio(a_nacimiento);
    cout<<"Ingrese el Promedio:"; cin>>promedio;
promedio=validarPromedio(promedio);
edad=2026-a_nacimiento;
    cout<<"Ingrese el presupuesto:";cin>>presupuesto;
}
double getPromedio(){
    return promedio;
}
string getNombre(){
    return nombre;
}
int getAniodeNacimiento(){
    return a_nacimiento;
}
double getPresupuesto(){
    return presupuesto;
}
double validarPromedio(double num){
    while(num<0 || num>4 || cin.fail()){
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"Ingrese un numero que se encuentre en el rango de 0-4"<<endl;
        cin>>num;}
        return num;}

int validarAnio(int a){
    while(a<2000 || a>2008 || cin.fail()){
            cin.clear();
            cin.ignore(1000,'\n');
        cout<<"Ingrese un anio valido entre 2000-2008"<<endl;
            cin>>a;}
    return a;
}
double getIndiceUniversidad(){
    return abs(promedio-3)*presupuesto;
}
void mostrar(){
    cout<<"Nombre:"<<nombre<<endl;
    cout<<"Anio de nacimiento:"<<a_nacimiento<<endl;
    cout<<"Promedio:"<<promedio<<endl;
    cout<<"Edad:"<<edad<<endl;
    cout<<"Presupuesto:"<<presupuesto<<endl;
    cout<<"Indice de Universidad:"<<getIndiceUniversidad()<<endl<<endl;
}


};

void ingresar(vector<Estudiante> &arr_,int a){
int indice;
int op1;  
            cout<<"1->Ingresar por defecto"<<endl;            
            cout<<"2->Ingresar con datos"<<endl;
            cin>>op1;
            if(op1==1){
                Estudiante arr1;
                if(a==1){
                cout<<"Se agrego al estudiante correctamente"<<endl;
                arr_.push_back(arr1);}
                else if(a==2){
                        cout<<"Ingrese la posicion entre 0 - "<<arr_.size()<<":"<<endl; 
                    cin>>indice;
                    while(indice<0 || indice>arr_.size()){
                        cout<<"Ingrese la posicion entre 0 - "<<arr_.size()<<":"<<endl; 
                        cin>>indice;
                    }
                    cout<<"Se agrego al estudiante correctamente"<<endl;
                    arr_.insert(arr_.begin()+indice,arr1);}}

            else if(op1==2){
                    Estudiante arr2;
                    arr2.setEstudiante();
                    if(a==1){
                    cout<<"Se agrego al estudiante correctamente"<<endl;
                    arr_.push_back(arr2);}

                    else if(a==2){
                        
                        cout<<"Ingrese la posicion entre 0 - "<<arr_.size()<<":"<<endl; 
        
                    cin>>indice;
                    while(indice<0 || indice>arr_.size()){
                        cout<<"Ingrese la posicion entre 0 - "<<arr_.size()<<":"<<endl; 
                        cin>>indice;
                    }
                    cout<<"Se agrego al estudiante correctamente"<<endl;
                    arr_.insert(arr_.begin()+indice,arr2);}
                }
}

void Menu(vector<Estudiante> &arr){
    
int op;
    cout<<"1->Ingresar un estudiante"<<endl;
    cout<<"2->Eliminar un Estudiante"<<endl;
    cout<<"3->Sobrescribir los datos de un estudiante"<<endl;
    cout<<"4->Ordenar por anio de nacimiento,promedio,presupuesto y por indice universidad"<<endl;
    cout<<"5->Mostrar la lista de estudiantes"<<endl;
    cout<<"6->Terminar Programa"<<endl;
       
    do{
         cout<<"Elija una opcion"<<endl;
        cin>>op;

       switch(op){
        case 1:{
            int op_;
            cout<<"1->Ingresar al final"<<endl;
            cout<<"2->Ingresar por indice"<<endl;
            cin>>op_;
            if(op_==1){
                ingresar(arr,1);}
            else if(op_==2){
                ingresar(arr,2);}
           break;}
        case 2:{
            if(arr.size()!=0){
                int op_2;
                cout<<"1->Eliminar el ultimo elemento"<<endl;
                cout<<"2->Eliminar por indice"<<endl;
                cin>>op_2;
                if(op_2==1){
                    arr.pop_back();
                }
                else if(op_2==2){
                    int indice=0;
                    cout<<"Ingrese el indice:";cin>>indice;

                    while(indice<0 || indice>=arr.size()){
                        cout<<"Ingrese la posicion entre 0 - "<<arr.size()-1<<":"<<endl; 
                        cin>>indice;
                    }
                    arr.erase(arr.begin()+indice);
                }}
                else{
                cout<<"El vector no tiene elementos elija otra opcion"<<endl;}
            break;}
        case 3:{
            if(arr.size()!=0){
                    int indice1=0;
                    cout<<"Ingrese el indice del estudiante que quiere modificar:";cin>>indice1;
                    
                    while(indice1<0 || indice1>=arr.size()){
                        cout<<"Ingrese la posicion entre 0 - "<<arr.size()-1<<":"<<endl; 
                        cin>>indice1;
                    }
                    arr[indice1].setEstudiante();}
                    else{
                        cout<<"No hay estudiantes registrados"<<endl;
                    }

                break;}
                case 4:{
                    int valor;
                    cout<<"1->Por Anio de Nacimiento"<<endl;
                    cout<<"2->Por GPA"<<endl;
                    cout<<"3->Por Presupesto"<<endl;
                    cout<<"4->Por indice Universidad"<<endl;
                    cin>>valor;
                    
                    if(valor==1){
                        sort(arr.begin(),arr.end(),[](Estudiante &a,Estudiante &b){
                            return a.getAniodeNacimiento()<b.getAniodeNacimiento();
                        });
                    }

                    else if(valor==2){
                        sort(arr.begin(),arr.end(),[](Estudiante &a,Estudiante &b){
                            return a.getPromedio()<b.getPromedio();
                        });
                    }
                    else if(valor==3){
                        sort(arr.begin(),arr.end(),[](Estudiante &a,Estudiante &b){
                            return a.getPresupuesto()<b.getPresupuesto();
                        });
                    }
                    else if(valor==4){
                    sort(arr.begin(),arr.end(),[](Estudiante &a,Estudiante &b){
                        return a.getIndiceUniversidad()<b.getIndiceUniversidad();

                    });}
                break;}
                case 5:{
                    for(Estudiante x:arr){
                        x.mostrar();
                    }
                break;}}
    } while (op!=6);
cout<<"Programa terminado"<<endl;
}
int main(){
    vector<Estudiante> arr;
    Menu(arr);


    return 0;
}