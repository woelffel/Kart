// Flag para o botao nao atrapalhar na contagem //
void FlagCronometro ()
{
  i++;
  
  // Flag liga/desliga cronômetro //
  if ( i >= 1 && i <= TomadaTotal)
  cronoLigado = true;
  else 
  cronoLigado = false;
  delay(5);
  
  TomadaAtual = i-1;
  
  // Se o número atual da tomada for menor que o número de tomadas total do circuito e maior ou igual a 1 //
  if (TomadaAtual <= TomadaTotal && TomadaAtual >= 1) 
    printaTomada(TomadaAtual);
  
  else if (TomadaAtual == TomadaTotal)
  {
    i = 1;
    inicializacao();
  }
  
}
