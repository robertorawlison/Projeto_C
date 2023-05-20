#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct{
  char timestamp[20];
  float age;
  char streaming_service[35];
  float hours_per_day;
  char while_working[5];
  char instrumentalist[5];
  char composer[5];
  char fav_genre[20];
  char exploratory[5];
  char foreign_languages[5];
  float bpm;

  char frequency_classical[20];
  char frequency_country[20];
  char frequency_edm[20];
  char frequency_folk[20];
  char frequency_gospel[20];
  char frequency_hip_hop[20];
  char frequency_jazz[20];
  char frequency_kpop[20];
  char frequency_latin[20];
  char frequency_lofi[20];
  char frequency_metal[20];
  char frequency_pop[20];
  char frequency_rb[20];
  char frequency_rap[20];
  char frequency_rock[20];
  char frequency_video_game_music[20];

  float anxiety;
  float depression;
  float insomnia;
  float ocd;
  char music_effects[25];
}tDados_csv;

void imprimirStructEspecifica(tDados_csv* dados[], int indice) {
  printf("Dados do struct no índice %d:\n", indice);
  printf("Timestamp: %s\n", dados[indice]->timestamp);
  printf("Age: %.1f\n", dados[indice]->age);
  printf("Streaming Service: %s\n", dados[indice]->streaming_service);
  printf("Hours per Day: %.1f\n", dados[indice]->hours_per_day);
  printf("While Working: %s\n", dados[indice]->while_working);
  printf("Instrumentalist: %s\n", dados[indice]->instrumentalist);
  printf("Composer: %s\n", dados[indice]->composer);
  printf("Favorite Genre: %s\n", dados[indice]->fav_genre);
  printf("Exploratory: %s\n", dados[indice]->exploratory);
  printf("Foreign Languages: %s\n", dados[indice]->foreign_languages);
  printf("BPM: %.1f\n", dados[indice]->bpm);
  printf("Frequency Classical: %s\n", dados[indice]->frequency_classical);
  printf("Frequency Country: %s\n", dados[indice]->frequency_country);
  printf("Frequency EDM: %s\n", dados[indice]->frequency_edm);
  printf("Frequency Folk: %s\n", dados[indice]->frequency_folk);
  printf("Frequency Gospel: %s\n", dados[indice]->frequency_gospel);
  printf("Frequency Hip Hop: %s\n", dados[indice]->frequency_hip_hop);
  printf("Frequency Jazz: %s\n", dados[indice]->frequency_jazz);
  printf("Frequency K-pop: %s\n", dados[indice]->frequency_kpop);
  printf("Frequency Latin: %s\n", dados[indice]->frequency_latin);
  printf("Frequency Lo-fi: %s\n", dados[indice]->frequency_lofi);
  printf("Frequency Metal: %s\n", dados[indice]->frequency_metal);
  printf("Frequency Pop: %s\n", dados[indice]->frequency_pop);
  printf("Frequency R&B: %s\n", dados[indice]->frequency_rb);
  printf("Frequency Rap: %s\n", dados[indice]->frequency_rap);
  printf("Frequency Rock: %s\n", dados[indice]->frequency_rock);
  printf("Frequency Video Game Music: %s\n", dados[indice]->frequency_video_game_music);
  printf("Anxiety: %.2f\n", dados[indice]->anxiety);
  printf("Depression: %.2f\n", dados[indice]->depression);
  printf("Insomnia: %.2f\n", dados[indice]->depression);
  printf("OCD: %.2f\n", dados[indice]->ocd);
  printf("Music Effects: %s\n", dados[indice]->music_effects);
}

void preencherDadosCSV(tDados_csv* dados[], int numLinhas) {
  FILE* arquivo = fopen("arquivo_corrigido.csv", "r");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    exit(1);
  }

  char linha[10000]; // Tamanho arbitrário para a linha
  fgets(linha, sizeof(linha), arquivo); // Descarta a primeira linha do CSV (cabeçalho)

  for (int i = 0; i < numLinhas; i++) {
    if (fgets(linha, sizeof(linha), arquivo)) {
      sscanf(linha, "%[^,],%f,%[^,],%f,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%f,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%f,%f,%f,%f,%[^,]",
             dados[i]->timestamp, &dados[i]->age, dados[i]->streaming_service, &dados[i]->hours_per_day, dados[i]->while_working, dados[i]->instrumentalist, dados[i]->composer, dados[i]->fav_genre,
             dados[i]->exploratory, dados[i]->foreign_languages, &dados[i]->bpm, dados[i]->frequency_classical, dados[i]->frequency_country, dados[i]->frequency_edm, dados[i]->frequency_folk,
             dados[i]->frequency_gospel, dados[i]->frequency_hip_hop, dados[i]->frequency_jazz, dados[i]->frequency_kpop, dados[i]->frequency_latin, dados[i]->frequency_lofi, dados[i]->frequency_metal,
             dados[i]->frequency_pop, dados[i]->frequency_rb, dados[i]->frequency_rap, dados[i]->frequency_rock, dados[i]->frequency_video_game_music, &dados[i]->anxiety, &dados[i]->depression, &dados[i]->insomnia,
             &dados[i]->ocd, dados[i]->music_effects);
    }
  }
  fclose(arquivo);
}

int main() {
  int numLinhas = 735;
  int indice;
  tDados_csv* dados[numLinhas];

  for (int i = 0; i < numLinhas; i++) {
    dados[i] = (tDados_csv*)malloc(sizeof(tDados_csv));
    if (dados[i] == NULL) {
      printf("Erro ao alocar memória.\n");
      exit(1);
      }
  }

  preencherDadosCSV(dados, numLinhas);
  
  printf("Digite o indice a ser buscado\n");
  scanf("%d", &indice);
  imprimirStructEspecifica(dados, indice);

  for (int i = 0; i < numLinhas; i++) {
    free(dados[i]);
  }

  return 0;
}
