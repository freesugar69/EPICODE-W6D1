#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Struttura per le domande
typedef struct {
    char domanda[256];
    char risposta1[100];
    char risposta2[100];
    char risposta3[100];
    char risposta_corretta; // Ora usa 'A', 'B', 'C'
} Domanda;

// Variabile globale per il punteggio totale
int punteggio_totale = 0;

// Prototipi delle funzioni
void menu_scelta();
void giocare();
void mostra_introduzione();

int main() {
    mostra_introduzione();
    
    while(1) {
        menu_scelta();
    }
    
    return 0;
}

void mostra_introduzione() {
    printf("=====================================\n");
    printf("    BENVENUTO AL GIOCO DI QUIZ!\n");
    printf("=====================================\n");
    printf("Scopo: Testa le tue conoscenze con domande a scelta multipla!\n");
    printf("Rispondi correttamente per ottenere il punteggio massimo.\n");
    printf("Il punteggio si accumula tra le partite!\n\n");
}

void menu_scelta() {
    char scelta;
    
    printf("\n=== MENU PRINCIPALE ===\n");
    printf("Punteggio accumulato: %d\n", punteggio_totale);
    printf("A - Iniziare una nuova partita\n");
    printf("B - Uscire dal gioco\n");
    printf("Inserisci la tua scelta (A/B): ");
    
    scanf(" %c", &scelta);
    scelta = toupper(scelta);
    
    switch(scelta) {
        case 'A':
            giocare();
            break;
        case 'B':
            printf("\nGrazie per aver giocato! Punteggio finale: %d\n", punteggio_totale);
            exit(0);
        default:
            printf("\nScelta non valida! Riprova.\n");
    }
}

void giocare() {
    char nome[50];
    int punteggio_partita = 0;
    char risposta_utente;
    
    // Array di domande con risposte A, B, C
    Domanda domande[5] = {
        {
            "Qual è la capitale d'Italia?",
            "A) Milano",
            "B) Roma",
            "C) Napoli",
            'B'
        },
        {
            "Quanti pianeti ci sono nel sistema solare?",
            "A) 7",
            "B) 8",
            "C) 9",
            'B'
        },
        {
            "Chi ha scritto la Divina Commedia?",
            "A) Dante Alighieri",
            "B) Petrarca",
            "C) Boccaccio",
            'A'
        },
        {
            "Qual è il fiume più lungo del mondo?",
            "A) Nilo",
            "B) Amazzone",
            "C) Yangtze",
            'A'
        },
        {
            "In quale anno è iniziata la Seconda Guerra Mondiale?",
            "A) 1938",
            "B) 1939",
            "C) 1940",
            'B'
        }
    };
    
    printf("\n=== NUOVA PARTITA ===\n");
    printf("Punteggio accumulato attuale: %d\n", punteggio_totale);
    printf("Inserisci il tuo nome: ");
    scanf(" %49[^\n]", nome);
    
    printf("\nCiao %s! Iniziamo il quiz!\n", nome);
    printf("Rispondi alle domande inserendo A, B o C.\n\n");
    
    // Ciclo per le domande
    for(int i = 0; i < 5; i++) {
        printf("\nDomanda %d: %s\n", i+1, domande[i].domanda);
        printf("%s\n", domande[i].risposta1);
        printf("%s\n", domande[i].risposta2);
        printf("%s\n", domande[i].risposta3);
        
        printf("La tua risposta (A/B/C): ");
        scanf(" %c", &risposta_utente);
        risposta_utente = toupper(risposta_utente);
        
        if(risposta_utente == domande[i].risposta_corretta) {
            printf("Corretto! +1 punto\n");
            punteggio_partita++;
            punteggio_totale++;
        } else {
            printf("Sbagliato! La risposta corretta era: %c\n", domande[i].risposta_corretta);
        }
    }
    
    // Risultato finale
    printf("\n=====================================\n");
    printf("PARTITA TERMINATA!\n");
    printf("Giocatore: %s\n", nome);
    printf("Punteggio di questa partita: %d su 5\n", punteggio_partita);
    printf("Punteggio totale accumulato: %d\n", punteggio_totale);
    
    if(punteggio_partita == 5) {
        printf("Perfetto! Sei un vero esperto!\n");
    } else if(punteggio_partita >= 3) {
        printf("Ottimo lavoro! Buona conoscenza!\n");
    } else if(punteggio_partita >= 1) {
        printf("Discreto, ma puoi fare di meglio!\n");
    } else {
        printf("Studia di più! La prossima volta andrà meglio!\n");
    }
    printf("=====================================\n");
}
