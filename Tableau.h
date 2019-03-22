//
// Created by jessy.borcard on 15.02.2019.
//

#ifndef BATAILLENAVALE_TABLEAU_H
#define BATAILLENAVALE_TABLEAU_H

#define PETIT_BATEAU 1
#define BATEAU_MOYEN 2
#define GRAND_BATEAU 3      //defining const
#define IMMENSE_BATEAU 4
#define SCORE_MULTIPLIER 10


#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


void ecritureDocument(char, float);
int randomiseur();




char tableau_cord[10][10] = {//this is an array where we'll use as a way to show into the command prompt
        "~~~~~~~~~~",
        "~~~~~~~~~~",
        "~~~~~~~~~~",
        "~~~~~~~~~~",
        "~~~~~~~~~~",
        "~~~~~~~~~~",
        "~~~~~~~~~~",
        "~~~~~~~~~~",
        "~~~~~~~~~~",
        "~~~~~~~~~~"

};



void tableauAffichage (){ //for showing the table as a graphic element





    int ligne = 0, colonne = 0, ligne_aff = 0;
    printf("\n");
    for (int col_aff = 1; col_aff < 11 ; ++col_aff) {
        printf("    %d ", col_aff); //it shows the upper numbers
    }
    printf("\n");
    for ( ligne = 0; ligne < 10; ++ligne)
    {
        ligne_aff++;
        for (int i = 0; i < 1; ++i) {

            printf("   -----------------------------------------------------------\n");
        }
        for (int loop1 = 0; loop1 < 1; ++loop1) {
            if (ligne_aff<=9) {
                printf("%d |", ligne_aff); //this is the int to 1 to 9
            }
            if (ligne_aff>=10){
                printf("%d|", ligne_aff); //and this one 10 to 99 because it has two numbers in it, the graphic element will shows normally without being offset
            }

            for ( colonne = 0; colonne < 10; ++colonne) {

                printf(" %c   |", tableau_cord[ligne][colonne]); //print every char from the tableau_cord

            }
            printf("\n");
        }
    }


    printf("   -----------------------------------------------------------\n");





}

void tableauChoix(){
    int col = 11, lig = 11, coup_donne = 0, nbr_de_coup = 0, choix_code, ligne = 0, colonne = 0, num = 0, random = 0;
    float score = 0; //declaring and initializing variables
    char captain_name[256] = {0};
    int vie_bateau = 0;
    int vie_petit_bateau = 2; //this is how much the boats have squares
    int vie_moyen_bateau = 3; //this is how much the boats have squares
    int vie_grand_bateau = 8; //this is how much the boats have squares but this one has two boats, so it takes 4*2
    int vie_immense_beateau = 5; //this is how much the boats have squares
    static int tableau [10][10] = { //this is where boats are, hard-coded, 1 are small boats, 2 are medium boats, 3 are big boats and 4 the huge boats
            0,0,1,1,0,0,0,0,0,2,
            0,0,0,0,0,0,0,0,0,2,
            0,3,3,3,3,0,0,0,0,2,
            0,0,0,0,0,0,0,3,0,0,
            0,0,0,0,0,0,0,3,0,0,
            0,0,0,0,0,0,0,3,0,0,
            0,0,0,0,0,0,0,3,0,0,
            0,0,0,0,0,0,0,0,0,0,
            0,4,4,4,4,4,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,

    },tableau_choix [10][10] = { 0 };//this is on what the code will work with

    random = randomiseur();

    FILE * fptr; //creating a fptr var from FILE
    if (random == 1){
    fptr = fopen("tableau1.txt","r");//opening the file Tableaux.txt
    } else if (random == 2) {
        fptr =fopen("tableau2.txt", "r");
    } else if (random == 3){
        fptr=fopen("tableau3.txt", "r");
    } else
    {
        printf("erreur dans le chargement de la carte");
    }


    vie_bateau = vie_bateau + vie_petit_bateau + vie_moyen_bateau + vie_grand_bateau + vie_immense_beateau;//adds every life's boat into vie_bateau



    printf("comment s'appel le capitaine ? (un seul nom)\n");
    scanf("%s", captain_name); //save the input into captain_name as char



    printf("avez vous un code de triche? (1 = oui) : ");
    scanf("%d", &choix_code);//save the input into choix_code

    if (choix_code == 1){//if choix_code equals 1 the condition become true
        printf("Code de triche (décimal) : ");
        scanf("%d", &choix_code);//save the input into choix_code
        if (choix_code == 1234){//if choix_code equals 1234 the condition become true
            goto triche;
        }
    } else
        {

        printf("Choissez votre carte(1 = carte de base, 2 = carte créée par vous)");
        scanf("%d", &choix_code);

        if (choix_code == 1){ // if the choix_code equals 1 the condition becomes true
            while(ligne < 10) {//do 10 times
                while(colonne < 10) {//do 10 times
                    tableau_choix[ligne][colonne] = tableau[ligne][colonne]; //save the array tableau to tableau_choix
                    colonne++; //adds 1 to a
                }
                colonne = 0; //reset colonne
                ligne++;//adds 1 to i
            }
        } else if (choix_code == 2){// if the choix_code equals 2 the condition becomes true
            while(ligne < 10) {//do 10 times
                while(colonne < 10) {//do 10 times

                    if (fptr == NULL){
                        printf("Error! opening file");

                        // Program exits if the file pointer returns NULL.
                        exit(1);
                    }
                    num = fgetc(fptr); // reading fptr which reads Tableaux.txt




                    if(num == 48){
                        num = 0;
                    }
                    if (num == 49){
                        num = PETIT_BATEAU; //convert ascii to binary
                    }
                    if (num == 50){
                        num = BATEAU_MOYEN;//convert ascii to binary
                    }

                    if(num == 51){
                        num = GRAND_BATEAU;//convert ascii to binary
                    }
                    if(num == 52){
                        num = IMMENSE_BATEAU;//convert ascii to binary
                    }
                    tableau_choix[ligne][colonne] = num; //save num into tableau_choix

                    colonne++; //adds 1 to a

                }
                colonne = 0; //reset colonne
                ligne++;//adds 1 to i
            }
            fclose(fptr); // close tableaux.txt
        }

    printf("en combien de coup voulez vous jouer ? ");
    scanf("%d", &nbr_de_coup); //save the input to nbre_de_coup

    do
    {
        printf("\t\t-----la carte de %s-----", captain_name);



        tableauAffichage();


        printf("\nchoix de Ligne : ");
        scanf("%d", &lig); //save the input to lig
        lig--;

        printf("\nchoix de Colonne : ");
        scanf("%d", &col); //save the input to col
        col--;

        if (tableau_cord[lig][col] == *"X" || tableau_cord[lig][col] == *"-"){
            printf("cette case est déjà touchée\n");
        }

        if(tableau_choix[lig][col] == 0){
            printf("loupé! \n\n\n"); //if the player's choice of lig and col equals 0 it says loupé
            tableau_cord[lig][col] = *"-";
        }


        if (tableau_cord[lig][col] == *"X") {//beep

        }else {
            if (tableau_choix[lig][col] == PETIT_BATEAU) { // if the player's choice of lig and col equals 1 the result is true
                tableau_cord[lig][col] = *"X"; //replacing the tableau_cord value depending on lig and col by an X
                printf("\ntouché! \n\n\n");
                score++; //adds 1 to score
                vie_petit_bateau--; //soustract 1 from vie_petit_bateau
                vie_bateau--; //soustract 1 from vie_bateau
                if (vie_petit_bateau ==
                    0) {  // if vie_petit_bateau equals 0 the condition shows that the petit bateau sinked


                    printf("Le petit bâteau à été coulé!!\n\n");
                    score = PETIT_BATEAU * SCORE_MULTIPLIER;
                }


            }
            if (tableau_choix[lig][col] == BATEAU_MOYEN) { // if the player's choice of lig and col equals 2 the result is true
                tableau_cord[lig][col] = *"X"; //replacing the tableau_cord value depending on lig and col by an X
                printf("\ntouché! \n\n\n");
                score++; //adds 1 to score
                vie_moyen_bateau--; //soustract 1 from vie_moyen_bateau
                vie_bateau--; //soustract 1 from vie_bateau
                if (vie_moyen_bateau ==
                    0) {  // if vie_moyen_bateau equals 0 the condition shows that the moyen bateau sinked

                    printf("Le bâteau moyen à été coulé!!\n\n");
                    score = BATEAU_MOYEN * SCORE_MULTIPLIER;
                }
            }
            if (tableau_choix[lig][col] == GRAND_BATEAU) { // if the player's choice of lig and col equals 3 the result is true
                tableau_cord[lig][col] = *"X"; //replacing the tableau_cord value depending on lig and col by an X
                printf("\ntouché! \n\n\n");
                score++; //adds 1 to score
                vie_grand_bateau--; //soustract 1 from vie_grand_bateau
                vie_bateau--; //soustract 1 from vie_bateau
                if (vie_grand_bateau ==
                    0) {  // if vie_grand_bateau equals 0 the condition shows that the grand bateau sinked

                    printf("Le grand bâteau à été coulé!! \n\n");
                    score = GRAND_BATEAU * SCORE_MULTIPLIER;
                }
            }
            if (tableau_choix[lig][col] == IMMENSE_BATEAU) { // if the player's choice of lig and col equals 4 the result is true
                tableau_cord[lig][col] = *"X"; //replacing the tableau_cord value depending on lig and col by an X
                printf("\ntouché! \n\n\n");
                score++; //adds 1 to score
                vie_immense_beateau--; //soustract 1 from vie_immense_bateau
                vie_bateau--; //soustract 1 from vie_bateau
                if (vie_immense_beateau ==
                    0) { // if vie_immense_bateau equals 0 the condition shows that the immense bateau sinked
                    printf("L'immense Bâteau à été coulé!!\n\n");
                    score = IMMENSE_BATEAU * SCORE_MULTIPLIER; //save 4*10 into score
                }
            }
            if (vie_bateau == 0) {
                triche:
                printf("vous avez gagner %s !\n", captain_name);
                printf(" nombres de coup : %d \n", coup_donne); // if vie de bateau equals 0 the victory menu shows
                score = score / coup_donne;
                ecritureDocument(captain_name, score); //calls ecriture document with parameters captain_name and score
                system("pause");

            }
        }









        coup_donne++;
    } while (coup_donne < nbr_de_coup); //this loop makes loops depending on how many times the player wants to play
    }
}
int menu(){ // this is the main menu


    int choix = 0;




    printf("--------Bataille Navale! 0.1--------\n");






    do {
        printf("1.Jouer \n");
        printf("2.Aide de jeu\n");
        printf("3.quiitez le programme\n");
        printf("votre choix :");
        scanf("%d", &choix);
        switch (choix) {

            case 1:

                tableauChoix(); //calling the tableauChoix function without any arguments


                break;
            case 2:
                printf("\nchoisissez une case et notez la en bas du programme, si la case n'est pas valable, le programme vous redemendra. \n");
                break;
            case 3:
                return 1;
        }
    }while(choix >= 3); //loop for re-asking the question if choix is bigger than 3


}



void ecritureDocument(char nom_captaine, float score){ //this function has two parameters, it write down char and int into a file called score

    FILE*fp;



    fp = fopen("Score.txt", "w"); //open Score.txt
    fputs(nom_captaine, fp); //put the name of the captain into fp
    fputs("-", fp); //put a - into fp
    fprintf(fp, "%0.3f", score); //print into fp score as int
    fclose(fp); //close fp
}


int randomiseur()
{
    int valeur=0;

    srand((unsigned) time(NULL));
    valeur=rand() % 3;

    return valeur;

};


#endif //BATAILLENAVALE_TABLEAU_H
