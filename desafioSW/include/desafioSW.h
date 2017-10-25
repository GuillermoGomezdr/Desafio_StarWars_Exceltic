#ifndef __DESAFIOSW_H__
#define __DESAFIOSW_H__

#define MAX_P 10

struct TPlanet{
	int trayectos[MAX_P];
	int tiempos[MAX_P];
	int vFinal;
	int vTemporal;
};



#ifdef __cplusplus
extern "C" {
#endif

void mapaPlanetas(struct TPlanet *p);
int comprobarDatosIntroducidos(int o, int d);
int tiempoHaciaOrigen(int tray[], int origen);

#ifdef __cplusplus
}
#endif

#endif
