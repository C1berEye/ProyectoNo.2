//Proyecto No.2 - Archivos
//Orden de funciones: Main, Menu, agregar, verifica, buscar, modificar, eliminar, ver.
#include<iostream>
#include <windows.h>
#include <fstream> //libreria de archivos
using namespace std;

int menu(){
    int a;
    a=0;
    system("cls");
    cout<<"-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n"<<endl;
    cout<<"\t\t\t  Universidad de Panama"<<endl;
    cout<<"\t\t\tCentro Regional de Azuero"<<endl;
    cout<<"\t\t\t Facultad de Informatica"<<endl;
    cout<<"\t\t\t       Proyecto No.2\n"<<endl;
    cout<<"-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ MENU -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\n";
    cout<<"1. Agregar un Estudinte (ALTA)"<<endl;
    cout<<"2. Buscar un Estudiante"<<endl;
    cout<<"3. Modificar datos de un estudiante"<<endl;
    cout<<"4. Eliminar Estudiante"<<endl;
    cout<<"5. Ver Registro"<<endl;
    cout<<"6. Salir del Programa"<<endl;
    cout<<"Seleccione una opcion: ";
    cin>>a;
    return a;
}
bool verifica(string cedu){//funcion booleana que verifica si la cedula esta registrada en el archivo
    ifstream leer("Registro.txt",ios::in);
    string nomb, ape, ced;
    int ppar,ppro,pas,nse,nfi;
    leer>>nomb;
    while(!leer.eof()){
        leer>>ape;
        leer>>ced;
        leer>>ppar;
        leer>>ppro;
        leer>>pas;
        leer>>nse;
        leer>>nfi;
        if(ced == cedu){ //si Cedula ya existe...
            system("cls");
            cout<<"\n\nERROR: La cedula ya existe en el registro\n\n";
            system("pause");
            leer.close();// cierra el archivo
            return false;//La cedula existe
        }
        leer>>nomb;//vuelve al inicio del siguiente registro para seguirlo leyendo
    }
    //Si Cedula no esta en el registro, entonces
    leer.close();// cierra el archivo
    return true;//La cedula no existe
}
void agregar(ofstream &es){
    system("cls");
    cout<<"-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ AGREGAR ESTUDIANTE -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    int x;
    int ppar,ppro,pas,nse,nfi;
    string nomb, ape, ced;
    es.open("Registro.txt",ios::out|ios::app);//Crea el archivo Personas.txt o le añade datos si ya esta creado
    cout<<"Ingresar Nombre del Estudiante: ";
    cin>>nomb;
    cout<<"Ingresar Apellido del Estudiante: ";
    cin>>ape;
    cout<<"Ingresar Cedula del Estudiante: ";
    cin>>ced;
    cout<<"Ingresar porcentaje de Parciales(maximo 30%): ";
    cin>>ppar;
    if(ppar>30){
        ppar=0;
        cout<<"\n*El porcentaje maximo para Parciales es de 30%\n\n";
        system("pause");
        cout<<"\nIngresar porcentaje de Parciales(maximo 30%): ";
        cin>>ppar;
    }
    cout<<"Ingresar porcentaje de Proyectos(maximo 35%): ";
    cin>>ppro;
    if(ppro>35){
        ppro=0;
        cout<<"\n*El porcentaje maximo para Proyectos es de 35%\n\n";
        system("pause");
        cout<<"\nIngresar porcentaje de Proyectos(maximo 35%): ";
        cin>>ppro;
    }
    cout<<"Ingresar porcentaje de Asistencias(maximo 5%): ";
    cin>>pas;
    if(pas>5){
        pas=0;
        cout<<"\n*El porcentaje maximo para Asistencias es de 5%\n\n";
        system("pause");
        cout<<"\nIngresar porcentaje de Asistencias(maximo 5%): ";
        cin>>pas;
    }
    cout<<"Ingresar nota Semestral(maximo 30%): ";
    cin>>nse;
    if(nse>30){
        nse=0;
        cout<<"\n*El porcentaje maximo para nota Semestral es de 30%\n\n";
        system("pause");
        cout<<"\nIngresar nota Semestral(maximo 30%): ";
        cin>>nse;
    }
    nfi=ppar+ppro+pas+nse;//Calcular Nota final
    if(verifica(ced)){//Verificar que Cedula no este ya ingresada
        es<<nomb<<" "<<ape<<" "<<ced<<" "<<ppar<<" "<<ppro<<" "<<pas<<" "<<nse<<" "<<nfi<<"\n";
    }
    es.close();
}
void buscar(ifstream &Lec){
    string nombr, apell, cedul,cedaux;
    int pparc,pproy,pasi,nsem,nfin;
    bool encontrado = false; //variable booleana, si se encuentra el estudiante cambiara a true
    system("cls");
    Lec.open("Registro.txt", ios::in);
    if (Lec.is_open()){
        cout<<"-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ BUSCAR ESTUDIANTE -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
        cout<<"Digite la cedula: ";
        cin>>cedaux;
        Lec>>nombr;
        while(!Lec.eof()&&!encontrado){
            Lec>>apell;
            Lec>>cedul;
            Lec>>pparc;
            Lec>>pproy;
            Lec>>pasi;
            Lec>>nsem;
            Lec>>nfin;
            if(cedul==cedaux){
                cout<<"\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\n";
                cout<<"Nombre---->: "<<nombr<<endl;
                cout<<"Apellido-->: "<<apell<<endl;
                cout<<"Cedula---->: "<<cedul<<endl;
                cout<<"**Notas**"<<endl;
                cout<<"Parciales--->: "<<pparc<<endl;
                cout<<"Proyectos--->: "<<pproy<<endl;
                cout<<"Asistencia-->: "<<pasi<<endl;
                cout<<"Semestral--->: "<<nsem<<endl;
                cout<<"Nota Final-->: "<<nfin<<endl;
                cout<<"\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\n";
                encontrado=true;
            }
            Lec>>nombr;
        }
        Lec.close();
        if(!encontrado)
            cout<<"\nERROR, Estudiante no encontrado"<<endl<<endl;
    }else
        cout<<"\n\nERROR, no se encontro el Registro"<<endl<<endl;
    system("pause");
}
void modificar(ifstream &Lec){
    string nombr, apell, cedul;
    string nombraux, apellaux, cedulaux;
    int pparc,pproy,pasi,nsem,nfin,op;
    int pparcaux,pproyaux,pasiaux,nsemaux,nfinaux;
    bool encontrado = false;
    system("cls");
    cout<<"-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ MODIFICAR ESTUDIANTE -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    Lec.open("Registro.txt", ios::in);
    ofstream aux("auxiliar.txt", ios::out);//se crea nuevo documento modificado
    if(Lec.is_open()){
        cout<<"Digite la cedula: ";
        cin>>cedulaux;
        Lec>>nombr;
        while(!Lec.eof()&&!encontrado){
            Lec>>apell;
            Lec>>cedul;
            Lec>>pparc;
            Lec>>pproy;
            Lec>>pasi;
            Lec>>nsem;
            Lec>>nfin;
            if(cedul==cedulaux){
                cout<<"Modificar:\n1.Nombre\n2.Apellido\n3.Cedula\n4.Parciales\n5.Proyectos\n6.Asistencias\n7.Semestral\n8.Regresar\nSeleccione una opcion: ";
                cin>>op;
                switch(op){
                    case 1:
                        cout<<"\nIngrese el nuevo Nombre: ";
                        cin>>nombraux;
                        aux<<nombraux<<" "<<apell<<" "<<cedul<<" "<<pparc<<" "<<pproy<<" "<<pasi<<" "<<nsem<<" "<<nfin<<"\n";
                        encontrado=true;
                    break;
                    case 2:
                        cout<<"\nIngrese el nuevo Apellido: ";
                        cin>>apellaux;
                        aux<<nombr<<" "<<apellaux<<" "<<cedul<<" "<<pparc<<" "<<pproy<<" "<<pasi<<" "<<nsem<<" "<<nfin<<"\n";
                        encontrado=true;
                    break;
                    case 3:
                        cout<<"\nIngrese la nueva Cedula: ";
                        cin>>cedulaux;
                        aux<<nombr<<" "<<apell<<" "<<cedulaux<<" "<<pparc<<" "<<pproy<<" "<<pasi<<" "<<nsem<<" "<<nfin<<"\n";
                        encontrado=true;
                    break;
                    case 4:
                        cout<<"\nIngrese el nuevo Porcentaje de Parciales: ";
                        cin>>pparcaux;
                        nfin=pparcaux+pproy+pasi+nsem;
                        aux<<nombr<<" "<<apell<<" "<<cedul<<" "<<pparcaux<<" "<<pproy<<" "<<pasi<<" "<<nsem<<" "<<nfin<<"\n";
                        encontrado=true;
                    break;
                    case 5:
                        cout<<"\nIngrese el nuevo Porcentaje de Proyectos: ";
                        cin>>pproyaux;
                        nfin=pparc+pproyaux+pasi+nsem;
                        aux<<nombr<<" "<<apell<<" "<<cedul<<" "<<pparc<<" "<<pproyaux<<" "<<pasi<<" "<<nsem<<" "<<nfin<<"\n";
                        encontrado=true;
                    break;
                    case 6:
                        cout<<"\nIngrese el nuevo Porcentaje de Asistencias: ";
                        cin>>pasiaux;
                        nfin=pparc+pproy+pasiaux+nsem;
                        aux<<nombr<<" "<<apell<<" "<<cedul<<" "<<pparc<<" "<<pproy<<" "<<pasiaux<<" "<<nsem<<" "<<nfin<<"\n";
                        encontrado=true;
                    break;
                    case 7:
                        cout<<"\nIngrese el nuevo Porcentaje de Semestral: ";
                        cin>>nsemaux;
                        nfin=pparc+pproy+pasi+nsemaux;
                        aux<<nombr<<" "<<apell<<" "<<cedul<<" "<<pparc<<" "<<pproy<<" "<<pasi<<" "<<nsemaux<<" "<<nfin<<"\n";
                        encontrado=true;
                    break;
                    case 8:
                        system("Pause");
                        aux<<nombr<<" "<<apell<<" "<<cedul<<" "<<pparc<<" "<<pproy<<" "<<pasi<<" "<<nsem<<" "<<nfin<<"\n";
                        encontrado=true;
                    break;
                    default:
                    system("cls");
                    cout<<"Opcion incorrecta, vuelva a intentarlo\n\n";
                    system("pause");
                    op=0;
                }
        }else{
            aux<<nombr<<" "<<apell<<" "<<cedul<<" "<<pparc<<" "<<pproy<<" "<<pasi<<" "<<nsem<<" "<<nfin<<"\n";
        }
        Lec>>nombr;
        }
        Lec.close();
        aux.close();
    if(!encontrado)
        cout<<"\nERROR, Estudiante no encontrado"<<endl<<endl;
    }else
        cout<<"\n\nERROR, no se encontro el Registro"<<endl<<endl;//En caso de que no exista nigun archivo previo
    remove("Registro.txt");// Se borra el archivo antiguo
    rename("auxiliar.txt", "Registro.txt");// Se le cambia el nombre al archivo modificado
    system("pause");
}
void eliminar(ifstream &Lec){
    system("cls");
    string cedul, nombr, apell;
    string cedulaux;
    int pparc,pproy,pasi,nsem,nfin;
    bool encontrado = false;
    cout<<"-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ ELIMINAR ESTUDIANTE -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    Lec.open("Registro.txt", ios::in);
    ofstream aux("auxiliar.txt", ios::out);//se crea nuevo documento sin el registro borrado
    if(Lec.is_open()){
        cout<<"Digite la cedula: ";
        cin>>cedulaux;
        Lec>>nombr;
        while(!Lec.eof()){
            Lec>>apell;
            Lec>>cedul;
            Lec>>pparc;
            Lec>>pproy;
            Lec>>pasi;
            Lec>>nsem;
            Lec>>nfin;
            if(cedul==cedulaux){
                cout<<"\nSe elimino correctamente...\n\n";
                encontrado=true;
            }else{
                aux<<nombr<<" "<<apell<<" "<<cedul<<" "<<pparc<<" "<<pproy<<" "<<pasi<<" "<<nsem<<" "<<nfin<<"\n";
            }
            Lec>>nombr;
        }
        Lec.close();
        aux.close();
    if(!encontrado)
        cout<<"\nERROR, Estudiante no encontrado"<<endl<<endl;
    }else
        cout<<"\n\nERROR, no se encontro el Registro"<<endl<<endl;//En caso de que no exista nigun archivo previo
    remove("Registro.txt");// Se borra el archivo antiguo
    rename("auxiliar.txt", "Registro.txt");// Se le cambia el nombre al archivo sin el registro borrado
    system("pause");
}
void ver(ifstream &Lec){
    string cedul, nombr, apell;
    int pparc,pproy,pasi,nsem,nfin;
    pparc=pproy=pasi=nsem=nfin=0;
    system("cls");
    fflush(stdin);
    Lec.open("Registro.txt", ios::in);
    if (Lec.is_open()){
        cout<<"-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ REGISTROS -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
        Lec>>nombr;
        while(!Lec.eof()){
            Lec>>apell;
            Lec>>cedul;
            Lec>>pparc;
            Lec>>pproy;
            Lec>>pasi;
            Lec>>nsem;
            Lec>>nfin;
            cout<<"Nombre------>: "<<nombr<<endl;
            cout<<"Apellido---->: "<<apell<<endl;
            cout<<"Cedula------>: "<<cedul<<endl;
            cout<<"**Notas**"<<endl;
            cout<<"Parciales--->: "<<pparc<<endl;
            cout<<"Proyectos--->: "<<pproy<<endl;
            cout<<"Asistencia-->: "<<pasi<<endl;
            cout<<"Semestral--->: "<<nsem<<endl;
            cout<<"Nota Final-->: "<<nfin<<endl;
            cout<<"\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\n";
            Lec>>nombr;
        }
        Lec.close();
        }else
            cout<<"\n\nERROR, no se encontro el Registro"<<endl<<endl;
    system("pause");
}
int main(){
    ofstream Esc; //variable para escribir en el archivo
    ifstream Lec;
    int op;
    do{
        system("cls");
        op=menu();
        switch(op){
            case 1:
                agregar(Esc);
            break;
            case 2:
                buscar(Lec);
            break;
            case 3:
                modificar(Lec);
            break;
            case 4:
                eliminar(Lec);
            break;
            case 5:
                ver(Lec);
            break;
            case 6:
                system("cls");
                cout<<"\n  Hasta luego...\n";
            break;
            default:
                system("cls");
                cout<<"Opcion incorrecta, vuelva a intentarlo\n\n";
                system("pause");
                op=0;
        }
    }while (op!=6);
}
