// Assignment 2 20T1 CP1511: Pokedex
// pokedex.c
//
// This program was written by Ivania Jesslyn Setiawan (z5287669)
// on 28/03/2020
//
// Version 1.0.0: Assignment released.
// Version 1.0.1: Minor clarifications about `struct pokenode`.
// Version 1.1.0: Moved destroy_pokedex function to correct location.
// Version 1.1.1: Renamed "pokemon_id" to "id" in change_current_pokemon.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Add any extra #includes your code needs here.
//
// But note you are not permitted to use functions from string.h
// so do not #include <string.h>

#include "pokedex.h"

// Add your own #defines here.
#define TRUE 1
#define FALSE 0
#define NONE_TYPE 0

// Note you are not permitted to use arrays in struct pokedex,
// you must use a linked list.
//
// You are also not permitted to use arrays in any of the functions
// below.
//
// The only exception is that char arrays are permitted for
// search_pokemon and functions it may call, as well as the string
// returned by pokemon_name (from pokemon.h).
//
// You will need to add fields to struct pokedex.
// You may change or delete the head field.

struct pokedex {
    struct pokenode *head;
    struct pokenode *select;
};


// You don't have to use the provided struct pokenode, you are free to
// make your own struct instead.
// If you use the provided struct pokenode, you will need to add fields
// to it to store other information.

struct pokenode {
    struct pokenode *next;
    Pokemon         pokemon;
    int found;
    struct pokenode *evolve;
};

typedef struct pokenode Pokenode;

// Add any other structs you define here.
struct pokedexType {
    struct pokenode *head;
    struct pokenode *select;
};

struct pokedexFound {
    struct pokenode *head;
    struct pokenode *select;
};

struct pokedexSearch {
    struct pokenode *head;
    struct pokenode *select;
};

// Add prototypes for any extra functions you create here.
void add_pokemon(Pokedex pokedex, Pokemon pokemon);
struct pokenode *new_pokenode(Pokemon pokemon);
void add_to_end (Pokedex pokedex, Pokenode *add);
void printID(Pokemon pokemon);
int strLength (char *name);
void print_show_ev (Pokenode *evolution);
Pokemon copy_pokemon (Pokemon pokemon);
static void sortPokemon(Pokedex pokedex);
int nameCompare (struct pokenode *curr, char *text);
static char *shift_tolower (char *text);
static char *stringCopy(char *text2, char *text);
static int duplicate_pokemon(Pokedex pokedex, Pokenode *add);

// You need to implement the following 20 functions.
// In other words, replace the lines calling fprintf & exit with your code.
// You can find descriptions of what each function should do in pokedex.h


Pokedex new_pokedex(void) {
    Pokedex new_pokedex = malloc(sizeof (struct pokedex));
    assert(new_pokedex != NULL);
    // add your own code here
    new_pokedex->head = NULL;
    return new_pokedex;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                          //
////////////////////////////////////////////////////////////////////////

void add_pokemon(Pokedex pokedex, Pokemon pokemon) {
    Pokenode *add = new_pokenode(pokemon);
    int duplicate = duplicate_pokemon(pokedex, add);
    if (duplicate == TRUE) {
        printf("The pokemon with ID %d already exist in the Pokedex!\n", pokemon_id(add->pokemon));
        exit(EXIT_FAILURE);
    } else {
        add_to_end(pokedex, add);
    }
}

void detail_pokemon(Pokedex pokedex) {
    //if the pokedex is empty, do nothing
    if (pokedex->head == NULL) {
        return;
    }

    Pokemon pokemon = get_current_pokemon(pokedex);
    //print the current pokemon ID  
    printf("Id: ");
    printID(pokemon);
    printf("\nName: ");
    
    if (pokedex->select->found != TRUE) { //Pokemon has not been found
        int i;
        char *name = pokemon_name(pokemon);
        int length = strLength(name); 
        //print the "*" according to the length of the pokemon name
        for(i = 0; i < length; i++) { 
            printf("*");
        }
        printf("\nHeight: --");
        printf("\nWeight: --");
        printf("\nType: --\n");
    } else { //Pokemon has already been found
        printf("%s", pokemon_name(pokemon));
        printf("\nHeight: %.1lfm", pokemon_height(pokemon));
        printf("\nWeight: %.1lfkg", pokemon_weight(pokemon));
        //checking the type of pokemon and printing according to the format
        if (pokemon_first_type(pokemon) == NONE_TYPE) { 
            printf("\nType: %s\n", pokemon_type_to_string
            (pokemon_second_type(pokemon)));
        } else if (pokemon_second_type(pokemon) == NONE_TYPE) {
            printf("\nType: %s\n", pokemon_type_to_string
            (pokemon_first_type(pokemon)));
        } else {
            printf("\nType: %s %s\n", pokemon_type_to_string
            (pokemon_first_type(pokemon)), pokemon_type_to_string
            (pokemon_second_type(pokemon)));
        }
    }
    
}

Pokemon get_current_pokemon(Pokedex pokedex) {
    struct pokenode *curr = pokedex->select;
    
    if (curr == NULL) { //if the pokedex is empty
        printf("There's no pokemon in pokedex");
        exit(EXIT_SUCCESS);
    }
    //put a specific pokemon to be selected
    Pokemon currPokemon = pokedex->select->pokemon; 
    return currPokemon;
}

void find_current_pokemon(Pokedex pokedex) {
    //if the pokedex is empty
    if (pokedex->head == NULL) {
        return;
    }
    //assign the pokenode at the pokedex to be found
    struct pokenode *curr = pokedex->select;
    curr->found = TRUE;
}

void print_pokemon(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    //checking the whole pokedex of pokemon
    while (curr != NULL) {
        //if the current pokemon at pokedex is the same as the selected one
        if (curr == pokedex->select) {
            printf("--> ");
        } else {
            printf("    ");
        }
        //printing the ID of the current of pokemon
        printf("#");
        printID(curr->pokemon);
        printf(": ");
        if (curr->found == TRUE) { //pokemon has already been found
            printf("%s", pokemon_name(curr->pokemon));
        } else {
            int i;
            char *name = pokemon_name(curr->pokemon);//pokemon hasn"t been found
            int length = strLength(name);
            //print the name with "*", because has not been found
            for(i = 0; i < length; i++) {
                printf("*");
            }
        }
        printf("\n");
        //increment to the next pokemon
        curr = curr->next;
    }
    
}

////////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                          //
////////////////////////////////////////////////////////////////////////

void next_pokemon(Pokedex pokedex) {
    //if the pokedex is empty or there is only one pokemon in the pokedex
    if (pokedex->head == NULL || pokedex->head->next == NULL) {
        return;
    }
    
    struct pokenode *curr = pokedex->select;
    //Pokemon is not empty and the next pokemon also exist, 
    //change the selected pokemon to the next one
    if (curr->next != NULL && curr != NULL) {
        pokedex->select = pokedex->select->next;
    } 
}

void prev_pokemon(Pokedex pokedex) {
    //Pokedex is empty
    if (pokedex->head == NULL) {
        return;
    }

    struct pokenode *curr = pokedex->head;
    struct pokenode *prev = NULL;
    //while the current pokemon is not the same as the selected pokemon
    while (pokedex->select != curr) { 
        prev = curr; //so that the previous move with pokedex->head
        curr = curr->next; 
    }
    // Selected pokemon is the previous one 
    if (prev != NULL) {
        pokedex->select = prev;
    }
    
}

void change_current_pokemon(Pokedex pokedex, int id) {
    //Pokedex is empty
    if (pokedex->head == NULL) {
        return;
    }

    struct pokenode *curr = pokedex->head;
    //find the pokemon with the ID according to the input
    while (pokemon_id(curr->pokemon) != id) {
        curr = curr->next;
    }
    //Set the selected pokemon to the previously found pokemon
    pokedex->select = curr; 
}

void remove_pokemon(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    struct pokenode *prev = NULL;
    
    //find the selected pokemon to be removed
    while (pokedex->select != curr && curr->next != NULL) {
        prev = curr; //so that the "prev" incremented with "curr"
        curr = curr->next;
    }   
    //Removed pokemon is at the beginning
    if (prev == NULL) {
        pokedex->head = pokedex->select->next;
        pokedex->select = pokedex->head;
        destroy_pokemon(curr->pokemon);
        free(curr);
    } else if (curr->next == NULL) { //Removed pokemon is at the end of pokedex
        pokedex->select = prev;
        prev->next = NULL;
        destroy_pokemon(curr->pokemon);
        free(curr);
    } else { //Removed pokemon is somewhere in the middle of the pokedex
        prev->next = curr->next;
        pokedex->select = prev->next;
        destroy_pokemon(curr->pokemon);
        free(curr);
    }    
}

void destroy_pokedex(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    struct pokenode *temp;
    //Destroy all the pokemon in the pokedex, then destroy the pokedex
    while (curr != NULL) {
        temp = curr;
        curr = curr->next;
        destroy_pokemon(temp->pokemon);
        free(temp);    
    }
    free(pokedex);
}

int count_found_pokemon(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    int count = 0;
    //check the whole pokedex
    while (curr != NULL) {
        if (curr->found == TRUE) { //if Pokemon has been found
            count++;
        }
        curr = curr->next;
    }
    return count;
}

int count_total_pokemon(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    int count = 0;
    //count all of the pokemon in the pokedex
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}


////////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                          //
////////////////////////////////////////////////////////////////////////

void add_pokemon_evolution(Pokedex pokedex, int from_id, int to_id) {
    struct pokenode *curr = pokedex->head;
    struct pokenode *curr2 = pokedex->head;
    struct pokenode *from;
    struct pokenode *toId;
    
    //find the pokemon to be the beginning of the evolution
    while (pokemon_id(curr->pokemon) != from_id) {
        curr = curr->next;
    } 
    from = curr;
    
    //find the pokemon to evolve to
    while (pokemon_id(curr2->pokemon) != to_id) {
        curr2 = curr2->next;
    }
    toId = curr2;
    
    //append the "from" pokemon and "to" pokemon 
    from->evolve = toId;
    
}

void show_evolutions(Pokedex pokedex) {
    struct pokenode *curr = pokedex->select; 
    //printing the id of all the first pokemon evolution
    printf("#");
    printID(curr->pokemon);
    printf(" ");
    if (curr->found == FALSE) { //Pokemon has not been found
        printf("???? [????]");
    } else { //Pokemon has been found
        printf("%s [", pokemon_name(curr->pokemon));
        print_show_ev(curr);
    }
    curr = curr->evolve; // move to the next pokemon evolution
    
    //Do the same as previous but in a loop until no more evolution
    while (curr != NULL) {
        printf(" --> ");
        printf("#");
        printID(curr->pokemon);
        printf(" ");
        if (curr->found == FALSE) {
            printf("???? [????]");
        } else {
            printf("%s [", pokemon_name(curr->pokemon));
            print_show_ev(curr);
        }
        curr = curr->evolve;
    }
    printf("\n");
}

int get_next_evolution(Pokedex pokedex) {
    struct pokenode *curr = pokedex->select;
    
    //There is no pokemon evolution
    if (curr->evolve == NULL) {
        return DOES_NOT_EVOLVE;
    }
    
    return pokemon_id(curr->evolve->pokemon);
}

////////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                          //
////////////////////////////////////////////////////////////////////////

Pokedex get_pokemon_of_type(Pokedex pokedex, pokemon_type type) {
    //Pokedex is empty
    if (pokedex->head == NULL) {
        return NULL;
    }
    //Type is not fulfill the criteria
    if (type == NONE_TYPE || type == INVALID_TYPE || type == MAX_TYPE) {
        return NULL;
    }
    //Creates a new pokedex
    Pokedex pokedexType = new_pokedex();
    
    struct pokenode *curr = pokedex->head;  
    
    while (curr != NULL) {
        //One of the type of the pokemon suitable with the type and pokemon 
        //has been found
        if ((pokemon_first_type(curr->pokemon) == type || 
        pokemon_second_type(curr->pokemon) == type) && (curr->found == TRUE)) { 
            //create a clone of the pokemon
            Pokemon typePokemon = copy_pokemon(curr->pokemon); 
            //create a pokenode that contains the pokemon clone
            Pokenode *add = new_pokenode(typePokemon); 
            add->found = TRUE; 
            add_to_end(pokedexType, add);  // append to the last pokenode    
        }
        curr = curr->next;
    } 
    return pokedexType;
}

Pokedex get_found_pokemon(Pokedex pokedex) {
    //Creates a new pokedex
    Pokedex pokedexFound = new_pokedex();
    
    struct pokenode *curr = pokedex->head;  
    //the same as get_type
    while (curr != NULL) {
        if (curr->found == TRUE) { //Pokemon has been found
            Pokemon findPokemon = copy_pokemon(curr->pokemon);
            Pokenode *add = new_pokenode(findPokemon);
            add->found = TRUE;
            add_to_end(pokedexFound, add);
        }
        curr = curr->next;
    }
    //Sorting the pokemon ID in the ascending order
    sortPokemon(pokedexFound);

    return pokedexFound;
}

Pokedex search_pokemon(Pokedex pokedex, char *text) {
    //Creates a new pokedex
    Pokedex pokedexSearch = new_pokedex();
    
    struct pokenode *curr = pokedex->head;
    //the same as get_type
    while (curr != NULL) {  
        //Finding the text in the pokemon_name
        int check = nameCompare(curr, text); 
        if (check == TRUE && curr->found == TRUE) {
            Pokemon searchPokemon = copy_pokemon(curr->pokemon);
            Pokenode *add = new_pokenode(searchPokemon);
            add->found = TRUE;
            add_to_end(pokedexSearch, add);
        }
        curr = curr->next;
    }
    return pokedexSearch;
}

// Add definitions for your own functions below.
//Creates new pokenode everytimes it is called
Pokenode *new_pokenode(Pokemon pokemon) {
    Pokenode *newNodeBox = malloc(sizeof(Pokenode));
    newNodeBox->pokemon = pokemon;
    newNodeBox->next = NULL;
    newNodeBox->evolve = NULL;
    newNodeBox->found = FALSE;
    return newNodeBox; 
}

//Attaching the new pokenode to the end of the linked list
void add_to_end(Pokedex pokedex, Pokenode *add) {
    if (pokedex->head == NULL) { // if the pokedex is empty, add to the start
        pokedex->head = add;
        pokedex->select = add;  
    } else { //if the pokedex is not empty, add to the end
        Pokenode *curr = pokedex->head;
        while (curr->next != NULL) {
            curr = curr->next; //Finding the end
        }
        curr->next = add;
    }
}

//print the ID of each pokemon according to the format
void printID(Pokemon pokemon) {    
    if (pokemon_id(pokemon) < 10) {
        printf("00%d", pokemon_id(pokemon));
    } else if (pokemon_id(pokemon) < 100) {
        printf("0%d", pokemon_id(pokemon));
    } else {
        printf("%d", pokemon_id(pokemon));
    }
}
//counting the length of pokemon name to print "*"
int strLength(char *name) {
    int count = 0;
    int i = 0;
    while (name[i] != '\0') {
        count++;
        i++;
    }
    return count;
}
//printing evolution type according to format
void print_show_ev(Pokenode *evolution) {
    struct pokenode *curr = evolution;
    
    if (pokemon_first_type(curr->pokemon) == NONE_TYPE) {
        printf("%s]", pokemon_type_to_string(pokemon_second_type
        (curr->pokemon)));
    } else if (pokemon_second_type(curr->pokemon) == NONE_TYPE) {
        printf("%s]", pokemon_type_to_string(pokemon_first_type(curr->pokemon)));
    } else {
        printf("%s, %s]", pokemon_type_to_string(pokemon_first_type
        (curr->pokemon)), pokemon_type_to_string(pokemon_second_type
        (curr->pokemon)));
    }
}
//Creates a clone of pokemon 
Pokemon copy_pokemon(Pokemon pokemon) {
    
    Pokemon copiedPokemon = new_pokemon(pokemon_id(pokemon), 
    pokemon_name(pokemon), pokemon_height(pokemon), pokemon_weight(pokemon), 
    pokemon_first_type(pokemon), pokemon_second_type(pokemon));
    
    return copiedPokemon;
}
//Sorting pokemon ID in ascending order
static void sortPokemon (Pokedex pokedex) {
    Pokenode *curr = pokedex->head;
    Pokenode *after = NULL;
    Pokemon temp;
    
    if (pokedex->head == NULL) {
        return;
    } else {
        while (curr != NULL) {
            //Pokenode "after" points to the next current;
            after = curr->next;
            while (after != NULL) {
                //If current pokemon ID is greater than the next current ID
                //swap the data
                if (pokemon_id(curr->pokemon) > pokemon_id(after->pokemon)) {
                    temp = curr->pokemon;
                    curr->pokemon = after->pokemon;
                    after->pokemon = temp;
                }
                after = after->next;
            }
            curr = curr->next;
        }
    }

}
//Comparing pokemon name to the text provided in search_pokemon
int nameCompare (struct pokenode *curr, char *text) {
    char *text2 = malloc(sizeof(text));
    char *copy_text = stringCopy(text2, text); 
        
    Pokemon searchPokemon = copy_pokemon(curr->pokemon);
    int check = FALSE;
    int text_length = strLength(copy_text);
    char *pokemonName = pokemon_name(searchPokemon);
    int name_length = strLength(pokemonName);
    char *lower_text = shift_tolower(copy_text);
    char *lower_name = shift_tolower(pokemonName);    
    
    if (text_length > name_length) {
        destroy_pokemon(searchPokemon);
        free(text2);
        return check;
    }
    
    int i = 0;
    while (i <= name_length - text_length) {
        int j = 0;
        while (j < text_length) {
            if (lower_name[i + j] != lower_text[j]) {
                break;  
            }
            j++;
        }    
        if (j == text_length) {
            check = TRUE;
            destroy_pokemon(searchPokemon);
            free(text2);
            return check;
        }
        i++;
    }  
    destroy_pokemon(searchPokemon);
    free(text2);
    return check;
}
//Shifting string to lower case
static char *shift_tolower (char *text) {
    int i = 0;
    while (text[i] != '\0') {
        if (text[i] <= 'Z' && text[i] >= 'A') {
            text[i] = text[i] - ('A' -'a');
        }
        i++;
    }         
    return text;
}
//Create a copy of the text searched
static char *stringCopy (char *text2, char *text) {
    int i = 0;
    while (text[i] != '\0') {
        text2[i] = text[i];
        i++;
    }
    text2[i] = '\0';
    return text2;
}
//Check whether the new pokemon already exist int the pokedex
static int duplicate_pokemon(Pokedex pokedex, Pokenode *add) {
    int duplicate = FALSE;
    Pokenode *curr = pokedex->head;
    while (curr != NULL) {
        if (pokemon_id(curr->pokemon) == pokemon_id(add->pokemon)) {
            duplicate = TRUE;
        }   
        curr = curr->next;
    }
    return duplicate;
}



