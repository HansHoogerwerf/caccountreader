/* 
 * File:   main.c
 * Author: Hans
 *
 * Created on 8 maart 2016, 19:09
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  /* for clrscr */
#include <string.h>


/*
 * 
 */

FILE *fp; /* declare the file pointer */


const char* getfield(char* line, int num) {
    const char* tok;
    for (tok = strtok(line, ",");
            tok && *tok;
            tok = strtok(NULL, ",\n")) { //wtf is dit nou weer arne
        if (!--num)
            return tok;
    }
    return NULL;
}

const void updateBalance(int sender, int receiver, double amount, double AccountBalance[])
{
    int lenghtArray = sizeof(AccountBalance) / sizeof(AccountBalance[0]);
    
    if(sender > 0 && receiver > 0 && amount > 0 && sender < lenghtArray && receiver < lenghtArray) //checks a couple of conditions
    {
        if(AccountBalance[receiver] == NULL)
        {
            AccountBalance[receiver] = 0;
        }
        
        if(AccountBalance[sender] == NULL)
        {
            AccountBalance[sender] = 0;
        }
        
        AccountBalance[receiver] = AccountBalance[receiver] + amount;
        AccountBalance[sender] = AccountBalance[sender] - amount;
    }
}

main() {

    char line[80];

    double AccountBalance[100];


    fp = fopen("c:\\accountReaderMap\\transactions.txt", "r"); /* open the file for reading */
    /* elapsed.dta is the name of the file */
    /* "rt" means open the file for reading text */

    while (fgets(line, 80, fp) != NULL) {
        //printf (line);
        char* tmp = strdup(line);    
        //char *record = strtok(line, ",");
        //printf(record);
        //printf("Field 1 would be %s\n", getfield(tmp, 3));
        
        int* sender = (int) *getfield(tmp, 1);
        int* receiver = (int) *getfield(tmp, 2);
        double amount = (double) *getfield(tmp, 3);
        
        updateBalance(sender, receiver, amount, AccountBalance);


    }
    fclose(fp);
}

