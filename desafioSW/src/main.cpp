//		--------- Desafío Star Wars Exceltic---------
//	-------------------------------------------------------------	
//				Realizado por:
//		https://github.com/GuillermoGomezdr
//	-------------------------------------------------------------
//		---------------------------------------------


#include <stdio.h>
#include <stdlib.h>

#include "desafioSW.h"

int main (int argc, char* argv[]) {
	
	struct TPlanet pA, pB, pC, pD, pE;	
	struct TPlanet p[MAX_P] = {pA, pB, pC, pD, pE};
	mapaPlanetas(p);	

	//Programa
	int origenInicial, destinoFinal;	
	int origen, destino;			// Variables que usaremos para "recorrer el mapa". Su valor irá variando según comprobemos las diferentes rutas.
	int tAcumulado = 0;			// Tiempo Acumulado en trayecto.



	printf("Elige el planeta de Origen:\n");
	scanf("%i", &origenInicial);

	printf("Elige el planeta de Destino:\n");
	scanf("%i", &destinoFinal);

	if(comprobarDatosIntroducidos(origenInicial, destinoFinal))
		return EXIT_SUCCESS;
	
	
	

	// Averiguamos los tiempos.
	origen = origenInicial;
	p[origen].vTemporal = 0;
	p[origen].vFinal = 0;
	for(int i = 0; i < MAX_P; i++){
		for(int j = 0; j < MAX_P; j++){
			if (p[p[origen].trayectos[j]].vFinal < 0 && (tAcumulado + p[origen].tiempos[j]) < p[p[origen].trayectos[j]].vTemporal){
				p[p[origen].trayectos[j]].vTemporal = tAcumulado + p[origen].tiempos[j];
			}
		}
		int vTemporalMenor = -1;
		for(int j = 0; j < MAX_P; j++){
			if(vTemporalMenor == -1 && p[j].vFinal < 0)
				vTemporalMenor = j;
			else if(p[vTemporalMenor].vTemporal > p[j].vTemporal && p[j].vFinal < 0)
				vTemporalMenor = j;
		}
		p[vTemporalMenor].vFinal = p[vTemporalMenor].vTemporal;
		tAcumulado = p[vTemporalMenor].vFinal;
		origen = vTemporalMenor;
	}

	
	//Resultado de averiguar Tiempos:
	printf("\nEl tiempo mínimo para viajar desde %i hasta %i es de: %i h.\n", origenInicial, destinoFinal, p[destinoFinal].vFinal);

	//Averiguamos el recorrido.	
	tAcumulado = p[destinoFinal].vFinal;			//Igualamos a valor Final (tiempo).
	origen = destinoFinal;					//Ahora haremos el recorrido a la inversa para averiguar los planetas por los que pasamos, así que igualamos el origen al destino final.


	printf("Antes de llegar al planeta %i...\n", destinoFinal);	
	while(tAcumulado > 0){
		int seguirBuscando = 1;
		for(int i = 0; i < MAX_P; i++){
			if(tAcumulado - p[p[origen].trayectos[i]].tiempos[tiempoHaciaOrigen(p[p[origen].trayectos[i]].trayectos, origen)] == p[p[origen].trayectos[i]].vFinal
			   && seguirBuscando == 1){
				tAcumulado = p[p[origen].trayectos[i]].vFinal;
				origen = p[origen].trayectos[i];

				if(origen == origenInicial)
					printf("... Sale del planeta %i.\n", origen);
				else
					printf("... Pasa por el planeta %i..\n", origen);

				seguirBuscando = 0;
			}		
		}
	}
	

	return EXIT_SUCCESS;
}
