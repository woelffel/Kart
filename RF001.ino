#include "glcd.h"
#include <glcd_Buildinfo.h>
#include <glcd_Config.h>
#include "fonts/allFonts.h"

#define SampleTime 10
#define botaoStart 18

double lastTime;

volatile char centesimos, segundos, minutos;
volatile boolean mudouCrono = true;
volatile boolean cronoLigado = false;


void setup ()
{
  GLCD.SelectFont(System5x7);
  GLCD.Init(NON_INVERTED);
  
  inicializacao();
  
  attachInterrupt(5, FlagCronometro, RISING);
  
  pinMode(botaoStart, INPUT);
}

void loop ()
{
  // Chama a função ajustaCronometro a cada 10ms //
  if ((millis() - lastTime >= SampleTime) && (cronoLigado == true)) 
  {
    ajustaCronometro();
    lastTime = millis();
  }
  if (mudouCrono)
  {
    printaTempo();
  }
}

// Escreve no LCD o cronômetro //
void printaTempo()
{
  GLCD.CursorTo(0,1);
  GLCD.print(minutos,DEC);
  GLCD.print(':');
  GLCD.print(segundos,DEC);
  GLCD.print(':');
  GLCD.print(centesimos,DEC);
  GLCD.print("   ");
  mudouCrono = false;
}

// Inicia/reinicia a contagem de tempo //
void inicializacao()
{
  GLCD.CursorTo(0,0);
  GLCD.print("Tempo");
  GLCD.CursorTo(0,4);
  GLCD.print("Tomadas");
  GLCD.CursorTo(0,5); 
  GLCD.print("1: ");
  GLCD.CursorTo(0,6);
  GLCD.print("2: ");
  GLCD.CursorTo(0,7);
  GLCD.print("3: ");
  minutos = 0;
  segundos = 0;
  centesimos = 0;
}


// Função cronômetro //
void ajustaCronometro()
{
  centesimos++;
  if (centesimos == 100)
  {
    centesimos = 0;
    segundos++;
    if (segundos == 60)
    { 
      segundos = 0;
      minutos ++;
    }
  }
  mudouCrono = true;
}

// Flag para o botao nao atrapalhar na contagem //
void FlagCronometro ()
{
  // Flag liga/desliga cronômetro //
  cronoLigado = !cronoLigado;
  delay(5);
  
}

