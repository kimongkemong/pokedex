// Assignment 2 20T1 COMP1511: Pokedex
// test_pokedex.c
//
// This file allows you to automatically test the functions you
// implement in pokedex.c.
//
// This program was written by Ivania Jesslyn Setiawan (z5287669)
// on 12/04/2020
//
// Version 1.0.0: Assignment released.
// Version 1.0.1: Added pointer check for the provided tests.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "pokedex.h"

// Add your own #defines here.
// Sample data on Venusaur, the Pokemon with pokemon_id 3.
#define VENUSAUR_ID 3
#define VENUSAUR_NAME "Venusaur"
#define VENUSAUR_HEIGHT 2.0
#define VENUSAUR_WEIGHT 100.0
#define VENUSAUR_FIRST_TYPE POISON_TYPE
#define VENUSAUR_SECOND_TYPE GRASS_TYPE

// Sample data on Bulbasaur, the Pokemon with pokemon_id 1.
#define BULBASAUR_ID 1
#define BULBASAUR_NAME "Bulbasaur"
#define BULBASAUR_HEIGHT 0.7
#define BULBASAUR_WEIGHT 6.9
#define BULBASAUR_FIRST_TYPE POISON_TYPE
#define BULBASAUR_SECOND_TYPE GRASS_TYPE

// Sample data on Ivysaur, the Pokemon with pokemon_id 2.
#define IVYSAUR_ID 2
#define IVYSAUR_NAME "Ivysaur"
#define IVYSAUR_HEIGHT 1.0
#define IVYSAUR_WEIGHT 13.0
#define IVYSAUR_FIRST_TYPE POISON_TYPE
#define IVYSAUR_SECOND_TYPE GRASS_TYPE

// Sample data on Wartortle, the Pokemon with pokemon_id 8.
#define WARTORTLE_ID 8
#define WARTORTLE_NAME "Wartortle"
#define WARTORTLE_HEIGHT 1.0
#define WARTORTLE_WEIGHT 22.5
#define WARTORTLE_FIRST_TYPE WATER_TYPE
#define WARTORTLE_SECOND_TYPE NONE_TYPE

// Sample data on Caterpie, the Pokemon with pokemon_id 10.
#define CATERPIE_ID 10
#define CATERPIE_NAME "Caterpie"
#define CATERPIE_HEIGHT 0.3
#define CATERPIE_WEIGHT 2.9
#define CATERPIE_FIRST_TYPE BUG_TYPE
#define CATERPIE_SECOND_TYPE NONE_TYPE

// Sample data on Pikachu, the Pokemon with pokemon_id 25.
#define PIKACHU_ID 25
#define PIKACHU_NAME "Pikachu"
#define PIKACHU_HEIGHT 0.4
#define PIKACHU_WEIGHT 6.0
#define PIKACHU_FIRST_TYPE ELECTRIC_TYPE
#define PIKACHU_SECOND_TYPE NONE_TYPE

// Sample data on Spearow, the Pokemon with pokemon_id 21.
#define SPEAROW_ID 21
#define SPEAROW_NAME "Spearow"
#define SPEAROW_HEIGHT 0.3
#define SPEAROW_WEIGHT 2.0
#define SPEAROW_FIRST_TYPE FLYING_TYPE
#define SPEAROW_SECOND_TYPE NORMAL_TYPE

// Sample data on Clefable, the Pokemon with pokemon_id 36.
#define CLEFABLE_ID 36
#define CLEFABLE_NAME "Clefable"
#define CLEFABLE_HEIGHT 1.3
#define CLEFABLE_WEIGHT 40.0
#define CLEFABLE_FIRST_TYPE FAIRY_TYPE
#define CLEFABLE_SECOND_TYPE NONE_TYPE


// Add your own prototypes here.
static void test_prev_pokemon(void);
static void test_moving_pokemon(void);
static void test_remove_pokemon(void);
static void test_evolve_pokemon(void);
static void test_get_type_pokemon(void);
static void test_search_pokemon(void);

// Tests for Pokedex functions from pokedex.c.
static void test_new_pokedex(void);
static void test_add_pokemon(void);
static void test_get_found_pokemon(void);
static void test_next_pokemon(void);


// Helper functions for creating/comparing Pokemon.
static Pokemon create_bulbasaur(void);
static Pokemon create_ivysaur(void);
static Pokemon create_venusaur(void);
static Pokemon create_pikachu(void);
static Pokemon create_clefable(void);
static Pokemon create_spearow(void);
static Pokemon create_wartortle(void);
static Pokemon create_caterpie(void);
static int is_same_pokemon(Pokemon first, Pokemon second);
static int is_copied_pokemon(Pokemon first, Pokemon second);
static int is_same_id(int id_first, int id_second);


int main(int argc, char *argv[]) {
    printf("Welcome to the COMP1511 Pokedex Tests!\n");

    printf("\n==================== Pokedex Tests ====================\n");

    test_new_pokedex();
    test_add_pokemon();
    test_next_pokemon();
    test_get_found_pokemon();
    test_prev_pokemon();
    test_moving_pokemon();
    test_remove_pokemon();
    test_evolve_pokemon();
    test_get_type_pokemon();
    test_search_pokemon();
    
    printf("\nAll Pokedex tests passed, you are Awesome!\n");
}


////////////////////////////////////////////////////////////////////////
//                     Pokedex Test Functions                         //
////////////////////////////////////////////////////////////////////////

// `test_new_pokedex` checks whether the new_pokedex and destroy_pokedex
// functions work correctly, to the extent that it can.
//
// It does this by creating a new Pokedex, checking that it's not NULL,
// then calling destroy_pokedex.
//
// Note that it isn't possible to check whether destroy_pokedex has
// successfully destroyed/freed the Pokedex, so the best we can do is to
// call the function and make sure that it doesn't crash..
static void test_new_pokedex(void) {
    printf("\n>> Testing new_pokedex\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("       --> Checking that the returned Pokedex is not NULL\n");
    assert(pokedex != NULL);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed new_pokedex tests!\n");
}

// `test_add_pokemon` checks whether the add_pokemon function works
// correctly.
//
// It does this by creating the Pokemon Bulbasaur (using the helper
// functions in this file and the provided code in pokemon.c), and
// calling add_pokemon to add it to the Pokedex.
//
// Some of the ways that you could extend these test would include:
//   - adding additional Pokemon other than just Bulbasaur,
//   - checking whether the currently selected Pokemon is correctly set,
//   - checking that functions such as `count_total_pokemon` return the
//     correct result after more Pokemon are added,
//   - ... and more!
static void test_add_pokemon(void) {
    printf("\n>> Testing add_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur\n");
    Pokemon bulbasaur = create_bulbasaur();

    printf("    ... Adding Bulbasaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    
    printf("    ... Creating Venusaur\n");
    Pokemon venusaur = create_venusaur();
    
    printf("    ... Adding Venusaur to the Pokedex\n");
    add_pokemon(pokedex, venusaur);
    
    printf("    ... Creating Pikachu\n");
    Pokemon pikachu = create_pikachu();

    printf("    ... Adding Pikachu to the Pokedex\n");
    add_pokemon(pokedex, pikachu);
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed add_pokemon tests!\n");
}

// `test_next_pokemon` checks whether the next_pokemon function works
// correctly.
//
// It does this by creating two Pokemon: Bulbasaur and Ivysaur (using
// the helper functions in this file and the provided code in pokemon.c).
//
// It then adds these to the Pokedex, then checks that calling the
// next_pokemon function changes the currently selected Pokemon from
// Bulbasaur to Ivysaur.
//
// Some of the ways that you could extend these tests would include:
//   - adding even more Pokemon to the Pokedex,
//   - calling the next_pokemon function when there is no "next" Pokemon,
//   - calling the next_pokemon function when there are no Pokemon in
//     the Pokedex,
//   - ... and more!
static void test_next_pokemon(void) {
    printf("\n>> Testing next_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed next_pokemon tests!\n");
}

// `test_get_found_pokemon` checks whether the get_found_pokemon
// function works correctly.
//
// It does this by creating two Pokemon: Bulbasaur and Ivysaur (using
// the helper functions in this file and the provided code in pokemon.c).
//
// It then adds these to the Pokedex, sets Bulbasaur to be found, and
// then calls the get_found_pokemon function to get all of the Pokemon
// which have been found (which should be just the one, Bulbasaur).
//
// Some of the ways that you could extend these tests would include:
//   - calling the get_found_pokemon function on an empty Pokedex,
//   - calling the get_found_pokemon function on a Pokedex where none of
//     the Pokemon have been found,
//   - checking that the Pokemon in the new Pokedex are in ascending
//     order of pokemon_id (regardless of the order that they appeared
//     in the original Pokedex),
//   - checking that the currently selected Pokemon in the returned
//     Pokedex has been set correctly,
//   - checking that the original Pokedex has not been modified,
//   - ... and more!
static void test_get_found_pokemon(void) {
    printf("\n>> Testing get_found_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(get_current_pokemon(pokedex) == bulbasaur);
    
    printf("    ... Setting Bulbasaur to be found\n");
    find_current_pokemon(pokedex);

    printf("    ... Getting all found Pokemon\n");
    Pokedex found_pokedex = get_found_pokemon(pokedex);

    printf("       --> Checking the correct Pokemon were copied and returned\n");
    assert(count_total_pokemon(found_pokedex) == 1);
    assert(count_found_pokemon(found_pokedex) == 1);
    assert(is_copied_pokemon(get_current_pokemon(found_pokedex), bulbasaur));

    printf("    ... Destroying both Pokedexes\n");
    destroy_pokedex(pokedex);
    destroy_pokedex(found_pokedex);

    printf(">> Passed get_found_pokemon tests!\n");
}


// Write your own Pokedex tests here!

//Test for prev_pokemon, checks whether the pokenode correctly move to the
//previous pokenode 
static void test_prev_pokemon(void) {
    printf("\n>> Testing prev_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    printf("    ... Moving to the previous pokemon\n");
    prev_pokemon(pokedex);
    
    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed next_pokemon tests!\n");
}
//Checking whether the pokenode can move to the next pokemon, previous pokemon
//, and change to spesific pokemon id
static void test_moving_pokemon(void) {
    printf("\n>> Testing moving_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur, Pikachu, Wartortle, Venusaur ");
    printf("and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    Pokemon venusaur = create_venusaur();
    Pokemon pikachu = create_pikachu();
    Pokemon wartortle = create_wartortle();

    printf("    ... Adding Bulbasaur, Pikachu, Wartortle, Venusaur and ");
    printf("Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    add_pokemon(pokedex, venusaur);
    add_pokemon(pokedex, pikachu);
    add_pokemon(pokedex, wartortle);

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);
    
    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);
    
    printf("       --> Checking that the current Pokemon is Venusaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), venusaur));
    
    printf("    ... Moving to the previous pokemon\n");
    prev_pokemon(pokedex);
    
    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    printf("    ... Setting Ivysaur to be found\n");
    find_current_pokemon(pokedex);
    
    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);
    
    printf("    ... Setting Venusaur to be found\n");
    find_current_pokemon(pokedex);
    
    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);
    
    printf("    ... Setting Pikachu to be found\n");
    find_current_pokemon(pokedex);
    
    printf("    ... Moving to Ivysaur\n");
    change_current_pokemon(pokedex, IVYSAUR_ID); 
    
    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));   

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed moving_pokemon tests!\n");
}
//Check if the current pokemon are removed the selected pokemon move to 
//the right posision
static void test_remove_pokemon(void) {
    printf("\n>> Testing remove_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur, Pikachu, Wartortle, Venusaur, Clefable");
    printf(" and Spearow\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon venusaur = create_venusaur();
    Pokemon pikachu = create_pikachu();
    Pokemon wartortle = create_wartortle();
    Pokemon spearow = create_spearow();
    Pokemon clefable = create_clefable();

    printf("    ... Adding Bulbasaur, Pikachu, Wartortle, Venusaur ,Clefable ");
    printf("and Spearow to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, venusaur);
    add_pokemon(pokedex, pikachu);
    add_pokemon(pokedex, wartortle);
    add_pokemon(pokedex, spearow);
    add_pokemon(pokedex, clefable);

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    
    printf("    ... Removing the current pokemon\n");
    remove_pokemon(pokedex);
    
    printf("       --> Checking that the current Pokemon is Venusaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), venusaur)); 
    
    printf("    ... Moving to Wartortle\n");
    change_current_pokemon(pokedex, WARTORTLE_ID);   
    
    printf("    ... Removing the current pokemon\n");
    remove_pokemon(pokedex);
    
    printf("       --> Checking that the current Pokemon is Spearow\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), spearow)); 
    
    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);   
    
    printf("    ... Removing the current pokemon\n");
    remove_pokemon(pokedex);
    
    printf("       --> Checking that the current Pokemon is Spearow\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), spearow)); 
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed remove_pokemon tests!\n");
    
}
//Checking if the pokemon evolve correctly and check if the next evolution 
//is correct
static void test_evolve_pokemon(void) {
    printf("\n>> Testing evolve_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Pikachu, Caterpie and Ivysaur\n");
    Pokemon pikachu = create_pikachu();
    Pokemon caterpie = create_caterpie();
    Pokemon ivysaur = create_ivysaur();
    
    printf("    ... Adding Pikachu, Caterpie and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, pikachu);
    add_pokemon(pokedex, caterpie);
    add_pokemon(pokedex, ivysaur);
    
    printf("    ... Evolve Pikachu to Caterpie\n");
    add_pokemon_evolution(pokedex, PIKACHU_ID, CATERPIE_ID);
    
    printf("       --> Checking that the next pokemon evolution is Caterpie\n");
    assert(is_same_id(get_next_evolution(pokedex), CATERPIE_ID));
    
    printf("    ... Evolve Caterpie to Ivysaur\n");
    add_pokemon_evolution(pokedex, CATERPIE_ID, IVYSAUR_ID);
    
    printf("       --> Checking that the next pokemon evolution is Caterpie\n");
    assert(is_same_id(get_next_evolution(pokedex), CATERPIE_ID));    
    
    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex); 
    
    printf("       --> Checking that the next pokemon evolution is Ivysaur\n");
    assert(is_same_id(get_next_evolution(pokedex), IVYSAUR_ID));  
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed evolve_pokemon tests!\n");
    
}
//check whether the new pokedex that contains pokemon with all the same type
static void test_get_type_pokemon(void) {
    printf("\n>> Testing get_type_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Wartortle, Pikachu, Spearow, Venusaur, Clefable");
    printf(" and Bulbasaur\n");
    Pokemon wartortle = create_wartortle();
    Pokemon pikachu = create_pikachu();
    Pokemon spearow = create_spearow();
    Pokemon venusaur = create_venusaur();
    Pokemon clefable = create_clefable();
    Pokemon bulbasaur = create_bulbasaur();

    printf("    ... Adding Wartortle, Pikachu, Spearow, Venusaur, Clefable ");
    printf("and Bulbasaur to the Pokedex\n");
    add_pokemon(pokedex, wartortle);
    add_pokemon(pokedex, pikachu);
    add_pokemon(pokedex, spearow);
    add_pokemon(pokedex, venusaur);
    add_pokemon(pokedex, clefable);
    add_pokemon(pokedex, bulbasaur);
    
    printf("       --> Checking that the current Pokemon is Wartortle\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), wartortle));
    
    printf("    ... Moving to Venusaur\n");
    change_current_pokemon(pokedex, VENUSAUR_ID);
    
    printf("    ... Setting Venusaur to be found\n");
    find_current_pokemon(pokedex);
    
    printf("    ... Moving to Bulbasaur\n");
    change_current_pokemon(pokedex, BULBASAUR_ID); 
    
    printf("    ... Setting Bulbasaur to be found\n");
    find_current_pokemon(pokedex);
    
    printf("    ... Getting all Pokemon with type Grass\n");
    Pokedex type_pokedex = get_pokemon_of_type(pokedex, GRASS_TYPE);
    
    printf("       --> Checking the correct Pokemon were copied and returned\n");
    assert(count_total_pokemon(type_pokedex) == 2);
    assert(count_found_pokemon(type_pokedex) == 2);
    assert(is_copied_pokemon(get_current_pokemon(type_pokedex), venusaur));
    next_pokemon(type_pokedex);
    assert(is_copied_pokemon(get_current_pokemon(type_pokedex), bulbasaur));
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed get_type_pokemon tests!\n");
    
}
//check whether the new pokedex contains the correct pokemon that has a spesific
//character in the pokemon name
static void test_search_pokemon(void) {
    printf("\n>> Testing search_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Wartortle, Venusaur, Clefable and Bulbasaur\n");
    Pokemon wartortle = create_wartortle();
    Pokemon venusaur = create_venusaur();
    Pokemon clefable = create_clefable();
    Pokemon bulbasaur = create_bulbasaur();

    printf("    ... Adding Wartortle, Venusaur, Clefable and Bulbasaur to ");
    printf("the Pokedex\n");
    add_pokemon(pokedex, wartortle);
    add_pokemon(pokedex, venusaur);
    add_pokemon(pokedex, clefable);
    add_pokemon(pokedex, bulbasaur);
    
    printf("       --> Checking that the current Pokemon is Wartortle\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), wartortle));

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);       
    
    printf("    ... Setting Venusaur to be found\n");
    find_current_pokemon(pokedex);
    
    printf("    ... Moving to Bulbasaur\n");
    change_current_pokemon(pokedex, BULBASAUR_ID);
    
    printf("    ... Setting Bulbasaur to be found\n");
    find_current_pokemon(pokedex); 
    
    printf("    ... Getting all Pokemon that has character 'SaU'\n");
    char *search_word = "SaU";
    Pokedex search_pokedex = search_pokemon(pokedex, search_word);
    
    printf("       --> Checking the correct Pokemon were copied and returned\n");
    assert(count_total_pokemon(search_pokedex) == 2);
    assert(count_found_pokemon(search_pokedex) == 2);
    assert(is_copied_pokemon(get_current_pokemon(search_pokedex), venusaur));
    next_pokemon(search_pokedex);
    assert(is_copied_pokemon(get_current_pokemon(search_pokedex), bulbasaur));
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed search_pokemon tests!\n");
       
}
    

////////////////////////////////////////////////////////////////////////
//                     Helper Functions                               //
////////////////////////////////////////////////////////////////////////

// Helper function to create Bulbasaur for testing purposes.
static Pokemon create_bulbasaur(void) {
    Pokemon pokemon = new_pokemon(
            BULBASAUR_ID, BULBASAUR_NAME,
            BULBASAUR_HEIGHT, BULBASAUR_WEIGHT,
            BULBASAUR_FIRST_TYPE,
            BULBASAUR_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Ivysaur for testing purposes.
static Pokemon create_ivysaur(void) {
    Pokemon pokemon = new_pokemon(
            IVYSAUR_ID, IVYSAUR_NAME,
            IVYSAUR_HEIGHT, IVYSAUR_WEIGHT,
            IVYSAUR_FIRST_TYPE,
            IVYSAUR_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Venusaur for testing purposes.
static Pokemon create_venusaur(void) {
    Pokemon pokemon = new_pokemon(
            VENUSAUR_ID, VENUSAUR_NAME,
            VENUSAUR_HEIGHT, VENUSAUR_WEIGHT,
            VENUSAUR_FIRST_TYPE,
            VENUSAUR_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to compare whether two Pokemon are the same.
// This checks that the two pointers contain the same address, i.e.
// they are both pointing to the same pokemon struct in memory.
//
// Pokemon ivysaur = new_pokemon(0, 'ivysaur', 1.0, 13.0, GRASS_TYPE, 
//POISON_TYPE)
// Pokemon also_ivysaur = ivysaur
// is_same_pokemon(ivysaur, also_ivysaur) == TRUE
static int is_same_pokemon(Pokemon first, Pokemon second) {
    return first == second;
}

// Helper function to compare whether one Pokemon is a *copy* of
// another, based on whether their attributes match (e.g. pokemon_id,
// height, weight, etc).
// 
// It also checks that the pointers do *not* match -- i.e. that the
// pointers aren't both pointing to the same pokemon struct in memory.
// If the pointers both contain the same address, then the second
// Pokemon is not a *copy* of the first Pokemon.
// 
// This function doesn't (yet) check that the Pokemon's names match
// (but perhaps you could add that check yourself...).
static int is_copied_pokemon(Pokemon first, Pokemon second) {
    return (pokemon_id(first) == pokemon_id(second))
    &&  (first != second)
    &&  (pokemon_height(first) == pokemon_height(second))
    &&  (pokemon_weight(first) == pokemon_weight(second))
    &&  (pokemon_first_type(first) == pokemon_first_type(second))
    &&  (pokemon_second_type(first) == pokemon_second_type(second));
}

// Write your own helper functions here!
// Helper function to create Pikachu for testing purposes.
static Pokemon create_pikachu(void) {
    Pokemon pokemon = new_pokemon(
            PIKACHU_ID, PIKACHU_NAME,
            PIKACHU_HEIGHT, PIKACHU_WEIGHT,
            PIKACHU_FIRST_TYPE,
            PIKACHU_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Wartortle for testing purposes.
static Pokemon create_wartortle(void) {
    Pokemon pokemon = new_pokemon(
            WARTORTLE_ID, WARTORTLE_NAME,
            WARTORTLE_HEIGHT, WARTORTLE_WEIGHT,
            WARTORTLE_FIRST_TYPE,
            WARTORTLE_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Caterpie for testing purposes.
static Pokemon create_caterpie(void) {
    Pokemon pokemon = new_pokemon(
            CATERPIE_ID, CATERPIE_NAME,
            CATERPIE_HEIGHT, CATERPIE_WEIGHT,
            CATERPIE_FIRST_TYPE,
            CATERPIE_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Spearow for testing purposes.
static Pokemon create_spearow(void) {
    Pokemon pokemon = new_pokemon(
            SPEAROW_ID, SPEAROW_NAME,
            SPEAROW_HEIGHT, SPEAROW_WEIGHT,
            SPEAROW_FIRST_TYPE,
            SPEAROW_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Clefable for testing purposes.
static Pokemon create_clefable(void) {
    Pokemon pokemon = new_pokemon(
            CLEFABLE_ID, CLEFABLE_NAME,
            CLEFABLE_HEIGHT, CLEFABLE_WEIGHT,
            CLEFABLE_FIRST_TYPE,
            CLEFABLE_SECOND_TYPE
    );
    return pokemon;
}
static int is_same_id(int id_first, int id_second) {
    return id_first == id_second;
}

