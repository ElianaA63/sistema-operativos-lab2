#include "types.h"
#include "stat.h"
#include "user.h"

// "Limpia" la pantalla, devolviendo un rectángulo negro
void
clearscreen()
{
  plotrectangle(0,0,320,200,0);
}

// Programa de prueba: cambiar a modo gráfico, esperar, y cambiar a modo texto
int
main(int argc, char *argv[])
{
  // Cambiar a modo gráfico
  modeswitch(1);

  // Pruebas de la funcion 'plotrectangle'
  clearscreen();
  plotrectangle(20,20,300,180,4);

  sleep(500);

  // Cambiar a modo texto
  modeswitch(0);
  exit();
}