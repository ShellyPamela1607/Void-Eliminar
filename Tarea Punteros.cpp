#include <iostream>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include<windows.h>

using namespace std;
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 } 

struct Estudiante{
	int *codigo,**pm_notas;
	string *nombre;
};

int main()
{
	int filaest=0,columnanot=0;
	int **pm_notas,*codigo;
	string *nombre;
	gotoxy(30,1); cout<<"TAREA PUNTEROS"<<endl<<endl;
	cout<<"NUMERO DE ESTUDIANTES A INGRESAR: ";
	cin>>filaest;	
	cout<<"CANTIDAD DE NOTAS A INGRESAR: ";
	cin>>columnanot;	
	system("cls");
	
	pm_notas = new  int *[filaest];
	codigo = new int [filaest];
	nombre = new string [filaest];
	
	for (int i=0;i<filaest;i++){
	pm_notas[i] = new int[columnanot]; 	
	}
	
	
	gotoxy(30,1); cout<<"INGRESO DE NOTAS"<<endl<<endl;
	
	for (int i=0;i<filaest;i++){
		
		cout<<"ESTUDIANTE "<<i+1<<endl;
		cout<<"Ingrese el codigo: ";
		cin>>codigo[i];
		cin.ignore();
		cout<<"Ingrese el nombre: ";
		getline(cin,nombre[i]);
		for (int ii=0;ii<columnanot;ii++){
			cout<<"Ingrese la Nota #"<<++ii<<": ";
			cin>>*(*(pm_notas+i)+ii);
			ii--;
			}
			cout<<endl<<endl;
	}
		system("cls");
	
	
		gotoxy(30,1); cout<<"MOSTRAR DATOS INGRESADOS"<<endl<<endl;
	
	for (int i=0;i<filaest;i++){
			cout<<"ESTUDIANTE "<<i+1<<endl<<endl;
			cout<<"CODIGO: ";
			cout<<codigo[i]<<endl;
			cout<<"NOMBRE: ";
			cout<<nombre[i]<<endl;
	
		for (int ii=0;ii<columnanot;ii++){
			cout<<"NOTA #"<<++ii<<": ";
			cout<<*(*(pm_notas+i)+ii)<<endl;
			ii--;	
			}
			
		cout<<endl;	
	}
	
	for (int i=0;i<filaest;i++){
		delete [] pm_notas[i];
	}
	
	delete [] pm_notas;

	system("PAUSE");
	return 0;
}


