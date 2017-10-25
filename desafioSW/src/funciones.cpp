#include <stdio.h>
#include <stdlib.h>

#include "desafioSW.h"


void mapaPlanetas(struct TPlanet *p){
	for(int i = 0; i < MAX_P; i++){
		for(int j = 0; j < MAX_P; j++){
			p[i].trayectos[j] = -1;
			p[i].tiempos[j] = -1;
		}
		p[i].vFinal = -1;
		p[i].vTemporal = 100;
	};

	//pA
	p[0].trayectos[0] = 1;
	p[0].trayectos[1] = 9;

	p[0].tiempos[0] = 5;
	p[0].tiempos[1] = 4;

	//pB
	p[1].trayectos[0] = 0;
	p[1].trayectos[1] = 2;
	p[1].trayectos[2] = 3;
	p[1].trayectos[3] = 4;

	p[1].tiempos[0] = 5;
	p[1].tiempos[1] = 4;
	p[1].tiempos[2] = 5;
	p[1].tiempos[3] = 6;

	//pC
	p[2].trayectos[0] = 1;
	p[2].trayectos[1] = 3;
	p[2].trayectos[2] = 4;

	p[2].tiempos[0] = 4;
	p[2].tiempos[1] = 3;
	p[2].tiempos[2] = 3;

	//pD
	p[3].trayectos[0] = 1;
	p[3].trayectos[1] = 2;
	p[3].trayectos[2] = 4;
	p[3].trayectos[3] = 8;

	p[3].tiempos[0] = 5;
	p[3].tiempos[1] = 3;
	p[3].tiempos[2] = 10;
	p[3].tiempos[3] = 3;

	//pE
	p[4].trayectos[0] = 1;
	p[4].trayectos[1] = 2;
	p[4].trayectos[2] = 3;
	p[4].trayectos[3] = 5;
	p[4].trayectos[4] = 7;

	p[4].tiempos[0] = 6;
	p[4].tiempos[1] = 3;
	p[4].tiempos[2] = 10;
	p[4].tiempos[3] = 3;
	p[4].tiempos[4] = 5;

	//pF
	p[5].trayectos[0] = 4;
	p[5].trayectos[1] = 6;

	p[5].tiempos[0] = 3;
	p[5].tiempos[1] = 1;

	//pG
	p[6].trayectos[0] = 5;
	
	p[6].tiempos[0] = 1;

	//pH
	p[7].trayectos[0] = 4;
	p[7].trayectos[1] = 8;
	p[7].trayectos[2] = 9;

	p[7].tiempos[0] = 5;
	p[7].tiempos[1] = 2;
	p[7].tiempos[2] = 4;

	//pI
	p[8].trayectos[0] = 3;
	p[8].trayectos[1] = 7;	

	p[8].tiempos[0] = 3;
	p[8].tiempos[1] = 2;	

	//pJ
	p[9].trayectos[0] = 0;
	p[9].trayectos[1] = 7;

	p[9].tiempos[0] = 4;
	p[9].tiempos[1] = 4;	

}


int comprobarDatosIntroducidos(int o, int d){
	if ((o < 0 || o >= MAX_P) || (d < 0 || d >= MAX_P)){
		printf("Ha introducido algún dato incorrecto. No se puede calcular la ruta.\n");
		return 1;
	}
	if(o == d){
		printf("El Origen y el destino son el mismo, por lo que el tiempo que tarda en llegar hasta el es de 0 horas, y solo pasa por el planeta %i.\n", o);
		return 1;
	}
	return 0;
}


int tiempoHaciaOrigen(int tray[], int origen){
	for(int i = 0; i < MAX_P; i++){
		if(tray[i] == origen)
			return i;
	}

	return MAX_P-1;
}
