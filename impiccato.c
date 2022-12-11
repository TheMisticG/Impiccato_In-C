#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
  
#define MAX_LEN 100 // Massima lunghezza della parola 
  
int lunghezzaParola; // Lunghezza della parola 
char parola[MAX_LEN]; // Parola da indovinare 
  
// Funzione per visualizzare l'immagine dell'impiccato 
void visualizzaStato(int numeroTentativi) 
{ 
    if (numeroTentativi == 0) { 
        printf("\n\t --------\n"); 
        printf("\t |      |\n"); 
        printf("\t |      O\n"); 
        printf("\t |     \n"); 
        printf("\t |     \n"); 
        printf("\t |      \n"); 
        printf("\t |      \n"); 
        printf("\t |      \n"); 
        printf("\t |      \n"); 
        printf("\t |      \n"); 
        printf("\t |      \n"); 
        printf("-----------------\n"); 
    } 
    else if (numeroTentativi == 1) { 
        printf("\n\t --------\n"); 
        printf("\t |      |\n"); 
        printf("\t |      O\n"); 
        printf("\t |      |\n"); 
        printf("\t |      |\n"); 
        printf("\t |      \n"); 
        printf("\t |      \n"); 
        printf("\t |      \n"); 
        printf("\t |      \n"); 
        printf("\t |      \n"); 
        printf("\t |      \n"); 
        printf("-----------------\n"); 
    } 
    else if (numeroTentativi == 2) { 
        printf("\n\t --------\n"); 
        printf("\t |      |\n"); 
        printf("\t |      O\n"); 
        printf("\t |     \\|\n"); 
        printf("\t |      |\n"); 
        printf("\t |      \n"); 
        printf("\t |      \n"); 
        printf("\t |      \n"); 
        printf("\t |      \n"); 
        printf("\t |      \n"); 
        printf("\t |      \n"); 
        printf("-----------------\n"); 
    } 
    else if (numeroTentativi == 3) { 
        printf("\n\t --------\n"); 
        printf("\t |      |\n"); 
        printf("\t |      O\n"); 
        printf("\t |     \\|/\n"); 
        printf("\t |      |\n"); 
        printf("\t |      \n"); 
        printf("\t |      \n"); 
        printf("\t |      \n"); 
        printf("\t |      \n"); 
        printf("\t |      \n"); 
        printf("\t |      \n"); 
        printf("-----------------\n"); 
    } 
    else if (numeroTentativi == 4) { 
        printf("\n\t --------\n"); 
        printf("\t |      |\n"); 
        printf("\t |      O\n"); 
        printf("\t |     \\|/\n"); 
        printf("\t |      |\n"); 
        printf("\t |     / \n"); 
        printf("\t |      \n"); 
        printf("\t |      \n"); 
        printf("\t |      \n"); 
        printf("\t |      \n"); 
        printf("\t |      \n"); 
        printf("-----------------\n"); 
    } 
    else if (numeroTentativi == 5) { 
        printf("\n\t --------\n"); 
        printf("\t |      |\n"); 
        printf("\t |      O\n"); 
        printf("\t |     \\|/\n"); 
        printf("\t |      |\n"); 
        printf("\t |     / \\\n"); 
        printf("\t |      \n"); 
        printf("\t |      \n"); 
        printf("\t |      \n"); 
        printf("\t |      \n"); 
        printf("\t |      \n"); 
        printf("-----------------\n"); 
    } 
} 
  
// Funzione per generare parola casuale 
void generaParola() 
{ 
    char parole[][MAX_LEN] = {"avvocato","matematica","programmazione","università"}; 
  
    // Scegli una parola casuale 
    int random = rand() % 4; 
  
    // Copia la parola selezionata in parola[] 
    strcpy(parola, parole[random]); 
  
    // Calcola la lunghezza della parola 
    lunghezzaParola = strlen(parola); 
} 
  
// Funzione per visualizzare la parola con le lettere corrette 
void visualizzaParola(char indovinato[]) 
{ 
    int i; 
    for (i = 0; i < lunghezzaParola; i++) { 
        if (indovinato[i] == '1') 
            printf("%c", parola[i]); 
        else
            printf("_ "); 
    } 
    printf("\n"); 
} 
  
// Funzione che ritorna 1 se la lettera inserita è quella giusta. 
// Altrimenti ritorna 0 
int controllaLettera(char lettera, char indovinato[]) 
{ 
    int i; 
    int risposta = 0; 
  
    for (i = 0; i < lunghezzaParola; ++i) { 
        // Se la lettera inserita è quella giusta 
        if (parola[i] == lettera) { 
            indovinato[i] = 'lettera'; 
            risposta = 1;
        } 
    } 
    return risposta; 
} 
  
int main() 
{ 
    char lettera; 
    int numeroTentativi = 0; 
    int risposta; 
  
    char indovinato[lunghezzaParola]; 
  
    // Genera una parola casuale 
    generaParola(); 
  
    // Inizializza indovinato[] con '_' 
	int i;
    for (i = 0; i < lunghezzaParola; i++) {
        indovinato[i] = '_';
    }
	indovinato[i] = '\0';
  
    while (numeroTentativi < 5) { 
        visualizzaStato(numeroTentativi); 
        visualizzaParola(indovinato); 
  
        // Ottieni la lettera inserita dall'utente 
        printf("%s %s, Inserisci una lettera: ", parola, indovinato); 
        scanf(" %c", &lettera); 
  
        // Controlla se la lettera inserita è quella giusta 
        risposta = controllaLettera(lettera, indovinato); 
  
        // Se la risposta è 0, incrementa il numero di tentativi 
        if (risposta == 0) 
            numeroTentativi++; 
  
        // Se tutte le lettere sono state indovinate, esci dal ciclo 
        if (strcmp(parola, indovinato) == 0) 
            break; 
    } 
  
    visualizzaStato(numeroTentativi); 
    visualizzaParola(indovinato); 
  
    if (numeroTentativi == 5) 
        printf("\nHai perso! La parole era %s.\n", parola); 
    else
        printf("\nHai vinto! La parola era %s.\n", parola); 
  
    return 0; 
}