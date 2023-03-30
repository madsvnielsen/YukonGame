#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

enum suitType{hearts, diamonds, spades, clubs};

struct node {
    int cardValue;
    bool visible;
    enum suitType suit;
    struct node *next;
};

struct linkedList{
    struct node *head;
};


void printLinkedList(struct linkedList list){
    struct node *el = list.head;
    char suitNames[4][10] = {"hearts","diamonds","spades","clubs"};
    while(el != NULL){
        printf("(%d, %s)\n", el->cardValue, suitNames[el->suit]);
        el = el->next;
    }
}


void insert(struct linkedList *list, int cardValue, enum suitType suit, bool visible){
    struct node *newNodeLink = (struct node*) malloc(sizeof (struct node));
    newNodeLink->cardValue = cardValue;
    newNodeLink->suit = suit;
    newNodeLink->next = list->head;
    newNodeLink->visible = visible;
    list->head = newNodeLink;
}

struct node* deleteFirst(struct linkedList *list){
    struct node *deletedElement = list->head;
    list->head = list->head->next;
    return deletedElement;
}

struct node* findElement(struct linkedList list, int cardValue, enum suitType suit){
    struct node* el = list.head;

    if(list.head == NULL){
        return NULL;
    }

    while (el->cardValue != cardValue || el->suit != suit){
        if(el->next == NULL){
            return NULL;
        } else{
            el = el->next;
        }
    }
    return el;
}

struct node* deleteElement(struct linkedList *list, int cardValue, enum suitType suit){
    struct node* el = list->head;
    struct node* prev = NULL;
    if(list->head == NULL){
        return NULL;
    }

    while (el->cardValue != cardValue || el->suit != suit){
        if(el->next == NULL){
            return NULL;
        } else{
            prev = el;
            el = el->next;
        }
    }
    if(el == list->head){
        list->head = list->head->next;
    } else{
        prev->next = el->next;
    }
    return el;



}
struct linkedList cardDeck;

struct linkedList C1;
struct linkedList C2;
struct linkedList C3;
struct linkedList C4;
struct linkedList C5;
struct linkedList C6;
struct linkedList C7;

void cardToString(char *str,struct node *card){
    if(card == NULL){
        return;
    }

    if(!card->visible){
        str[0]='[';
        str[1] = ']';
        return;
    }

    switch (card->cardValue) {
        case 1:
            str[0] = 'A';
            break;
        case 10:
            str[0] = 'T';
            break;
        case 11:
            str[0] = 'J';
            break;
        case 12:
            str[0] = 'Q';
            break;
        case 13:
            str[0] = 'K';
            break;
        default:
            str[0] = card->cardValue + '0';
            break;

    }

    char suitNames[4] = {'H','D','S','C'};
    str[1] = suitNames[card->suit];


}

void printGameBoard(){
    printf("C1\tC2\tC3\tC4\tC5\tC6\tC7\n");
    bool hasMoreCards = true;
    struct node *column1 = C1.head;
    struct node *column2 = C2.head;
    struct node *column3 = C3.head;
    struct node *column4 = C4.head;
    struct node *column5 = C5.head;
    struct node *column6 = C6.head;
    struct node *column7 = C7.head;
    int index = 0;

    while(hasMoreCards || index < 4){
        hasMoreCards = false;

        char c1txt[] = "  ";
        char c2txt[] = "  ";
        char c3txt[] = "  ";
        char c4txt[] = "  ";
        char c5txt[] = "  ";
        char c6txt[] = "  ";
        char c7txt[] = "  ";

       cardToString(&c1txt, column1);
        cardToString(&c2txt, column2);
        cardToString(&c3txt, column3);
        cardToString(&c4txt, column4);
        cardToString(&c5txt, column5);
        cardToString(&c6txt, column6);
        cardToString(&c7txt, column7);



        column1 = column1 == NULL ? NULL : column1->next;
        column2 = column2 == NULL ? NULL : column2->next;
        column3 = column3 == NULL ? NULL : column3->next;
        column4 = column4 == NULL ? NULL : column4->next;
        column5 = column5 == NULL ? NULL : column5->next;
        column6 = column6 == NULL ? NULL : column6->next;
        column7 = column7 == NULL ? NULL : column7->next;

        printf("%s\t%s\t%s\t%s\t%s\t%s\t%s", c1txt,c2txt,c3txt,c4txt,c5txt,c6txt,c7txt);
        if(index == 0){
            printf("\t\t[]\tF1");
        } else if(index == 1){
            printf("\t\t[]\tF2");
        } else if(index == 2){
            printf("\t\t[]\tF3");
        } else if(index == 3){
            printf("\t\t[]\tF3");
        }

        printf("\n");

        if(column1 != NULL ||
            column2 != NULL ||
            column3 != NULL ||
            column4 != NULL ||
            column5 != NULL ||
            column6 != NULL ||
            column7 != NULL
                ){hasMoreCards = true;}

        index++;
    }

    printf("\nLAST Command: %s\nMessage: %s", " ", " ");


}

void loadCardDeck(char* name){
    printf("LOAD");
    FILE *filePointer = fopen("name", "r");
    char line[256];

    while (fgets(line, sizeof (line), filePointer)){
        printf("%s", line);
    }
    fclose(filePointer);


}



void handleInput(){
    printf("\nINPUT > ");
    char* in;
    gets(in);

    if(strcmp(in, "LD") == 0){
        loadCardDeck("test");
    }
}


int main() {
    insert(&C1, 1,spades, true);
    insert(&C1, 2,spades, true);
    insert(&C1, 5,hearts, true);
    insert(&C1, 5,hearts, false);
    insert(&C1, 5,hearts, false);

    insert(&C2, 7, diamonds, true);
    insert(&C2, 3, clubs, true);
    insert(&C2, 1, spades, false);
    insert(&C2, 1, spades, false);

    insert(&C3, 10, diamonds, true);
    insert(&C3, 11, clubs, true);
    insert(&C3, 12, spades, false);
    insert(&C3, 13, spades, false);
    printGameBoard();

    handleInput();

    return 0;
}

