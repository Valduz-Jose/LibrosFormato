#include <iostream>

using namespace std;
int main(){
	
	cout<<"Bienvenido"<<endl;
	//Variables
	int numerocliente=0,Nfisico=0,Ndigital=0,ubicacion=0,TotalFisicos=0,TotalDigitales=0,Total,costoEnvio=0,TotalEjemplaresFisicos=0;
	int TotalEjemplaresDigitales=0,Ndigitalanterior=0,continuar=0;
	float  descuento=0,MontoTotal=0,TotalconDescuento=0,totaldescuentos=0,descuentosechos=0,DescuentosPromedio=0;
	string nombre,nombremasEjemplaresDigitales,ubicacionC,ubicacionmasDigitales;
	
	do{
		cout<<"\nNombre: ";
		cin>>nombre;
		fflush(stdin);//limpio el buffer para evitar errores
		cout<<"Cantidad de ejemplares a Adquirir en Formato fisico: ";// Precio=75
		cin>>Nfisico;
		fflush(stdin);
		cout<<"Cantidad de ejemplares a Adquirir en Formato Digital: ";// Precio=45
		cin>>Ndigital;
		fflush(stdin);
		cout<<"Ubicación Geografica: \n 1 (Occidente) \n 2(Oriente) \n 3 (Centro) \n";
		cin>>ubicacion;
		fflush(stdin);
		Total=Nfisico+Ndigital;
		TotalEjemplaresFisicos=TotalEjemplaresFisicos+Nfisico;
		TotalEjemplaresDigitales=TotalEjemplaresDigitales+Ndigital;
		//Descuento
		MontoTotal=(Nfisico*75)+(Ndigital*45);
		
		descuento=Total*0.02;//Nuevo Valor del descuento
		descuentosechos++;
		totaldescuentos=totaldescuentos+descuento;
		
		if(Total>=50){//la premisa hace q para mas de 50 libros sea gratis asi que controlamos el error
			descuento=1;
		}
		TotalconDescuento=MontoTotal*descuento;
		//costos de Envio
		if(ubicacion==1){
			costoEnvio=45;
			ubicacionC="Occidente";
		}else if(ubicacion==2){
			costoEnvio=35;
			ubicacionC="Oriente";
		}else if(ubicacion==3){
			costoEnvio=25;
			ubicacionC="Centro";
		}else{
			cout<<"La Ubicación Ingresada No puede ser Procesada";
			costoEnvio=45;
			ubicacionC="N/A";
		}
		if(Ndigital>3||Nfisico>3){//envio gratis
			costoEnvio=0;
		}
		if(Ndigital>=Ndigitalanterior&&Nfisico==0){//Ninguno Impreso pero el que mas lleve Digitales
			Ndigitalanterior=Ndigital;
			nombremasEjemplaresDigitales=nombre;
			ubicacionmasDigitales=ubicacionC;
		}
		//b)Indicar a cada cliente, monto en Bs.F de la compra y el cosoto de envio
		cout<<"Monto Total: "<<MontoTotal<<" Bs.F\n";
		cout<<"Descuento: "<<descuento*100<<"% = "<<TotalconDescuento<<endl;
		cout<<"Total a Pagar: "<<MontoTotal-TotalconDescuento;
		if(costoEnvio==0){
			cout<<"\nEnvio Gratuito"<<endl;
		}else{
			cout<<"Costo de Envio: "<<costoEnvio<<endl;
		}
		cout<<"Ingresar otor cliente? \n1 (si) \n2 (no)";
		cin>>continuar;
	}while(continuar==1);
	
	//a)Calcular y Mostrar el total de ejemplares vendidos,de cada formato
	cout<<"Total de Ejemplares Fisicos: "<<TotalEjemplaresFisicos<<endl;
	cout<<"Total de Ejemplares Digitales: "<<TotalEjemplaresDigitales<<endl;
	//c) Descuentos Promedio
	DescuentosPromedio=totaldescuentos/descuentosechos;
	cout<<"Descuento Promedio Otorgado a los Clientes: "<<DescuentosPromedio*100<<"% \n";
	//d) Determinar La Region y el Nombre del Cliente que lleve mas ejemplares digitale spero nunguno fisico
	cout<<"Cliente con mas Ejemplares Digitales y ninguno fisico: \n"<<nombremasEjemplaresDigitales<<"\nUbicado en: "<<ubicacionmasDigitales<<endl;
	
	return 0;
}
