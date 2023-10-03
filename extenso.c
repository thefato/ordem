#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void escrita(int num, char *ne, int sex, int tipo);
void ordinal(int nume, char *ner, int sx, int tip);
void numeroextenso(int n, char *nue, int s, int t); // s=sexo,n=valor,nue=extenso

main() {
  setlocale(LC_ALL, "Portuguese");
  int valor, c, d, u, sexo, tipo;
  char nxt[500];
  printf("Digite o valor entre 0 e 999.999.999: ");
  scanf("%d", &valor);
  printf("Digite 0 para masculino e 1 para feminino: ");
  scanf("%d", &sexo);
  printf("Digite 0 para cardinal e 1 para ordinal: ");
  scanf("%d", &tipo);
  getchar();
  numeroextenso(valor, nxt, sexo, tipo); // char n precisa de &
  printf("numero extenso: %s", nxt); // onde escreve o nue que retornou para nxt
}

void numeroextenso(int n, char *nue, int s, int t) {
  int milhao, mil, cent;
  char next[500];
  char nuext[500];
  strcpy(next, "");
  strcpy(nuext, "");

  milhao = (int)n / 1000000;          // separado os milhoes
  mil = (int)((n % 1000000) / 1000);  // separado os milhares
  cent = (int)((n % 1000000) % 1000); // separado centenas

switch(t){
  case 0:{
   if (milhao != 0) {
      if (milhao == 1) {
        strcpy(nuext, "um milhão ");
        if ((milhao == 1) && (mil == 0) && (cent != 0))
          strcat(nuext, "e ");
      } else {
        escrita(milhao, next, s,t); // chama a funçao para escrever por extenso e retorna em next
        strcpy(nuext, next);        // manda next para nuext para juntar tudo
        strcat(nuext, " milhões "); // adiciona milhoes ao final dessa parte
        if ((milhao > 1) && (mil != 0) || (cent != 0))
          strcat(nuext, "e ");
      }
    } 
if (mil != 0) {
      strcpy(next, "");
   if ((mil > 1) && (milhao < 0)){
      escrita(mil, next, s,t); // chama a funçao escrever por extenso e retorna em next
      strcat(nuext, next); // manda next para nuext para juntar tudo
   }
      strcat(nuext, " mil "); // adiciona mil ao final
      if ((mil > 0) && (cent != 0))
        strcat(nuext, "e ");
      {}
    }
  }  
  break;

  
   case 1:{
       if (milhao != 0) {
      if (milhao == 1) {
        if (s==0){
        strcpy(nuext, "um milionésimo ");
          }else if(s==1){
            strcpy(nuext, "uma milionésima ");
          }
      } else {
        escrita(milhao, next, s,t); // chama a funçao para escrever por extenso e retorna em next
        strcpy(nuext, next);// manda next para nuext para juntar tudo
        if (s==0){
        strcat(nuext, " milionésimo "); // adiciona milhoes ao final dessa parte
        }else if(s==1){
          strcat(nuext, " milionésima "); // adiciona milhoes ao final dessa parte
        }
      }
    } 
if (mil != 0) {
      strcpy(next, "");
  if (mil > 1){
      escrita(mil, next, s,t); // chama a funçao escrever por extenso e retorna em next
      strcat(nuext, next); // manda next para nuext para juntar tudo
  }
  if (s==0){
     strcat(nuext, " milésimo"); // adiciona mil ao final
  } else {
     strcat(nuext, " milésima"); // adiciona mil ao final
  }
      {}

      {}
  strcat(nuext, " ");
    }
   }
     
   break;

  
}

  if (cent != 0) {
    strcpy(next, "");
    if (t == 0) {
      escrita(cent, next, s, t); // chama função centena e retorna em next
    } else if (t == 1) {
      ordinal(cent, next, s, t); // chama função centena e retorna em next
    }
    strcat(nuext, next); // manda next para nuext para juntar tudo
  }

  strcpy(nue,nuext); // nuext passa o q tem dentro para nue e nue volta para main
}

void escrita(int num, char *ne, int sex, int t) {
  int c, d, u;
  char centena[50], dezena[50], unidade[50], numero[500];
  strcpy(centena, "");
  strcpy(dezena, "");
  strcpy(unidade, "");

  if ((num < 0) && (num > 999)) {
    printf("Valor fora do intervalo válido 0-999");
  } else {
    c = (int)num / 100;
    d = (int)((num % 100) / 10);
    u = (int)((num % 100) % 10);
  }

  switch (c) {
  case 1: {
    if ((d == 0) && (u == 0)) {
      strcpy(centena, "cem");
    } else {
      strcpy(centena, "cento e ");
    }
  } break;
  case 2: {
    if ((d == 0) && (u == 0)) {
      if (sex == 0) {
        strcpy(centena, "duzentos ");
      } else {
        strcpy(centena, "duzentas ");
      }
    } else {
      if (sex == 0) {
        strcpy(centena, "duzentos e ");
      } else {
        strcpy(centena, "duzentas e ");
      }
    }
  } break;
  case 3: {
    if ((d == 0) && (u == 0)) {
      if (sex == 0) {
        strcpy(centena, "trezentos ");
      } else {
        strcpy(centena, "trezentas ");
      }
    } else {
      if (sex == 0) {
        strcpy(centena, "trezentos e ");
      } else {
        strcpy(centena, "trezentas e ");
      }
    }
  } break;
  case 4: {
    if ((d == 0) && (u == 0)) {
      if (sex == 0) {
        strcpy(centena, "quatrocentos ");
      } else {
        strcpy(centena, "quatrocentas ");
      }
    } else {
      if (sex == 0) {
        strcpy(centena, "quatrocentos e ");
      } else {
        strcpy(centena, "quatrocentas e ");
      }
    }
  } break;
  case 5: {
    if ((d == 0) && (u == 0)) {
      if (sex == 0) {
        strcpy(centena, "quinhentos ");
      } else {
        strcpy(centena, "quinhentas ");
      }
    } else {
      if (sex == 0) {
        strcpy(centena, "quinhentos e ");
      } else {
        strcpy(centena, "quinhentas e ");
      }
    }
  } break;
  case 6: {
    if ((d == 0) && (u == 0)) {
      if (sex == 0) {
        strcpy(centena, "seiscentos ");
      } else {
        strcpy(centena, "seicentas ");
      }
    } else {
      if (sex == 0) {
        strcpy(centena, "seiscentos e ");
      } else {
        strcpy(centena, "seiscentas e ");
      }
    }
  } break;
  case 7: {
    if ((d == 0) && (u == 0)) {
      if (sex == 0) {
        strcpy(centena, "setecentos ");
      } else {
        strcpy(centena, "setecentas ");
      }
    } else {
      if (sex == 0) {
        strcpy(centena, "setecentos e ");
      } else {
        strcpy(centena, "setecentas e ");
      }
    }
  } break;
  case 8: {
    if ((d == 0) && (u == 0)) {
      if (sex == 0) {
        strcpy(centena, "oitocentos ");
      } else {
        strcpy(centena, "oitocentas ");
      }
    } else {
      if (sex == 0) {
        strcpy(centena, "oitocentos e ");
      } else {
        strcpy(centena, "oitocentas e ");
      }
    }
  } break;
  case 9: {
    if ((d == 0) && (u == 0)) {
      if (sex == 0) {
        strcpy(centena, "novecentos ");
      } else {
        strcpy(centena, "novecentas ");
      }
    } else {
      if (sex == 0) {
        strcpy(centena, "novecentos e ");
      } else {
        strcpy(centena, "novecentas e ");
      }
    }
  } break;
  }

  switch (d) {
  case 2: {
    if (u == 0) {
      strcpy(dezena, "vinte ");
    } else {
      strcpy(dezena, "vinte e ");
    }
  } break;
  case 3: {
    if (u == 0) {
      strcpy(dezena, "trinta ");
    } else {
      strcpy(dezena, "trinta e ");
    }
  } break;
  case 4: {
    if (u == 0) {
      strcpy(dezena, "quarenta ");
    } else {
      strcpy(dezena, "quarenta e ");
    }
  } break;
  case 5: {
    if (u == 0) {
      strcpy(dezena, "cinquenta ");
    } else {
      strcpy(dezena, "cinquenta e ");
    }
  } break;
  case 6: {
    if (u == 0) {
      strcpy(dezena, "sessenta ");
    } else {
      strcpy(dezena, "sessenta e ");
    }
  } break;
  case 7: {
    if (u == 0) {
      strcpy(dezena, "setenta ");
    } else {
      strcpy(dezena, "setenta e ");
    }
  } break;
  case 8: {
    if (u == 0) {
      strcpy(dezena, "oitenta ");
    } else {
      strcpy(dezena, "oitenta e ");
    }
  } break;
  case 9: {
    if (u == 0) {
      strcpy(dezena, "noventa ");
    } else {
      strcpy(dezena, "noventa e ");
    }
  } break;
  case 1: {
    if (u == 0)
      strcpy(dezena, "dez");
    if (u == 1)
      strcpy(dezena, "onze");
    if (u == 2)
      strcpy(dezena, "doze");
    if (u == 3)
      strcpy(dezena, "treze");
    if (u == 4)
      strcpy(dezena, "catorze");
    if (u == 5)
      strcpy(dezena, "quinze");
    if (u == 6)
      strcpy(dezena, "dezesseis");
    if (u == 7)
      strcpy(dezena, "dezesete");
    if (u == 8)
      strcpy(dezena, "dezoito");
    if (u == 9)
      strcpy(dezena, "dezenove");
  } break;
  }

  if (d != 1) {
    switch (u) {
    case 1: {
      if (sex != 0) {
        strcpy(unidade, "uma");
      } else {
        strcpy(unidade, "um");
      }
    } break;
    case 2: {
      if (sex != 0) {
        strcpy(unidade, "duas");
      } else {
        strcpy(unidade, "dois");
      }
    } break;
    case 3: {
      strcpy(unidade, "três");
    } break;
    case 4: {
      strcpy(unidade, "quatro");
    } break;
    case 5: {
      strcpy(unidade, "cinco");
    } break;
    case 6: {
      strcpy(unidade, "seis");
    } break;
    case 7: {
      strcpy(unidade, "sete");
    } break;
    case 8: {
      strcpy(unidade, "oito");
    } break;
    case 9: {
      strcpy(unidade, "nove");
    } break;
    }
  }

  strcpy(numero, "");
  strcat(numero,centena); // coloca na ordem em que adiciona logo centena,dezena,unidade
  strcat(numero, dezena);
  strcat(numero, unidade);
  strcpy(ne, numero); // transfere tudo para ne
}

void ordinal(int nume, char *ner, int sx, int tip) {
  int c, d, u;
  char centena[50], dezena[50], unidade[50], numero[500];
  strcpy(centena, "");
  strcpy(dezena, "");
  strcpy(unidade, "");

  if ((nume < 0) && (nume > 999)) {
    printf("Valor fora do intervalo válido 0-999");
  } else {
    c = (int)nume / 100;
    d = (int)((nume % 100) / 10);
    u = (int)((nume % 100) % 10);
  }

  switch (c) {
  case 1: {
    if (sx == 0) {
      strcpy(centena, "centésimo ");
    } else {
      strcpy(centena, "centésima ");
    }
  } break;
  case 2: {
    if (sx == 0) {
      strcpy(centena, "ducentésimo ");
    } else {
      strcpy(centena, "ducentésima ");
    }
  } break;
  case 3: {
    if (sx == 0) {
      strcpy(centena, "tricentésimo ");
    } else {
      strcpy(centena, "tricentésima ");
    }
  } break;
  case 4: {
    if (sx == 0) {
      strcpy(centena, "quadrigentésimo ");
    } else {
      strcpy(centena, "quadrigentésima ");
    }
  } break;
  case 5: {
    if (sx == 0) {
      strcpy(centena, "quingentésimo ");
    } else {
      strcpy(centena, "quingentésima ");
    }
  } break;
  case 6: {
    if (sx == 0) {
      strcpy(centena, "seiscentésimo ");
    } else {
      strcpy(centena, "seiscentésima ");
    }
  } break;
  case 7: {
    if (sx == 0) {
      strcpy(centena, "septigentésimo ");
    } else {
      strcpy(centena, "septigentésima ");
    }
  } break;
  case 8: {
    if (sx == 0) {
      strcpy(centena, "octigentésimo ");
    } else {
      strcpy(centena, "octigentésima ");
    }
  } break;
  case 9: {
    if (sx == 0) {
      strcpy(centena, "nongentésimo ");
    } else {
      strcpy(centena, "nongentésima ");
    }
  } break;
  }

  switch (d) {
  case 2: {
    if (sx == 0) {
      strcpy(dezena, "vigésimo ");
    } else if (sx == 1) {
      strcpy(dezena, "vigésima ");
    }
  } break;
  case 3: {
    if (sx == 0) {
      strcpy(dezena, "trigésimo ");
    } else if (sx == 1) {
      strcpy(dezena, "trigésima ");
    }
  } break;
  case 4: {
    if (sx == 0) {
      strcpy(dezena, "quadragésimo ");
    } else if (sx == 1) {
      strcpy(dezena, "quadragésima ");
    }
  } break;
  case 5: {
    if (sx == 0) {
      strcpy(dezena, "quinquagésimo ");
    } else if (sx == 1) {
      strcpy(dezena, "quinquagésima ");
    }
  } break;
  case 6: {
    if (sx == 0) {
      strcpy(dezena, "sexagésimo ");
    } else if (sx == 1) {
      strcpy(dezena, "sexagésima ");
    }
  } break;
  case 7: {
    if (sx == 0) {
      strcpy(dezena, "septuagésimo ");
    } else if (sx == 1) {
      strcpy(dezena, "septuagésima ");
    }
  } break;
  case 8: {
    if (sx == 0) {
      strcpy(dezena, "octogésimo ");
    } else if (sx == 1) {
      strcpy(dezena, "octogésima ");
    }
  } break;
  case 9: {
    if (sx == 0) {
      strcpy(dezena, "nonagésimo ");
    } else if (sx == 1) {
      strcpy(dezena, "nonagésima ");
    }
  } break;
  case 1: {
    if (sx == 0) {
      strcpy(dezena, "décimo ");
    } else if (sx == 1) {
      strcpy(dezena, "décima ");
    }
  } break;
  }

  switch (u) {
  case 1: {
    if (sx != 0) {
      strcpy(unidade, "primeira");
    } else {
      strcpy(unidade, "primeiro");
    }
  } break;
  case 2: {
    if (sx != 0) {
      strcpy(unidade, "segunda");
    } else {
      strcpy(unidade, "segundo");
    }
  } break;
  case 3: {
    if (sx != 0) {
      strcpy(unidade, "terceira");
    } else {
      strcpy(unidade, "terceiro");
    }
  } break;
  case 4: {
    if (sx != 0) {
      strcpy(unidade, "quarta");
    } else {
      strcpy(unidade, "quarto");
    }
  } break;
  case 5: {
    if (sx != 0) {
      strcpy(unidade, "quinta");
    } else {
      strcpy(unidade, "quinto");
    }
  } break;
  case 6: {
    if (sx != 0) {
      strcpy(unidade, "sexta");
    } else {
      strcpy(unidade, "sexto");
    }
  } break;
  case 7: {
    if (sx != 0) {
      strcpy(unidade, "sétima");
    } else {
      strcpy(unidade, "sétimo");
    }
  } break;
  case 8: {
    if (sx != 0) {
      strcpy(unidade, "oitava");
    } else {
      strcpy(unidade, "oitavo");
    }
  } break;
  case 9: {
    if (sx != 0) {
      strcpy(unidade, "nona");
    } else {
      strcpy(unidade, "nono");
    }
  } break;
  }

  strcpy(numero, "");
  strcat(
      numero,
      centena); // coloca na ordem em que adiciona logo centena,dezena,unidade
  strcat(numero, dezena);
  strcat(numero, unidade);
  strcpy(ner, numero); // transfere tudo para ne
}