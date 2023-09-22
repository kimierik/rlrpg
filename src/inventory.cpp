#pragma once




#include <cstdio>
class InvSlot{
    public:
    int itemId=0;
    int quantity=0;

    //debug print
    void print(){
        printf("item id: %d, quantity: %d \n", itemId, quantity);
    }
};






// TODO 
// add things to inventory 
//      just add to inv and it will place the item into a free cell automatically
// remove items
// mouse move items around maybe
//
class Inventory{

    //grid and a grid piece
    //
    public:

    const static int collumns=10;
    const static int rows=5;

    Inventory(){
        //inv slots do not need to be initialised since they are owned
        //but still set it to zero
        for(int collumn =0; collumn <10;collumn++){
            for(int row =0; row <5;row++){
                grid[collumn][row].itemId=0;
                grid[collumn][row].quantity=0;
            }
        }
    }


    // list of inv slot collumns
    // so its   collumn, row
    // maybe change to vector if want more space
    InvSlot grid[collumns][rows];


    void printInventory(){
        for(int collumn =0; collumn <10;collumn++){
            for(int row =0; row <5;row++){
                printf("col:%d, row:%d. has:",collumn,row);
                grid[collumn][row].print();

            }
        }
        printf("\n \n");
    }


    //returns false if the item was not placed into the inventory
    bool addToInv(int id, int quantity){
        //first checks if there is an item with the same id. then adds the quantity to that
        //then if not checs if there is an open space if there is then overrides it

        for(int collumn =0; collumn <collumns;collumn++){
            for(int row =0; row <rows;row++){
                if (grid[collumn][row].itemId==id){
                    grid[collumn][row].quantity+=quantity;
                    printf("found slot at %i, %i\n", collumn,row);
                    return true;
                }
            }
        }

        // loops twice since this was fast to write. if ever is slow then merge this into the first loop
        for(int collumn =0; collumn <collumns;collumn++){
            for(int row =0; row <rows;row++){
                if (grid[collumn][row].itemId==0){
                    grid[collumn][row].quantity+=quantity;
                    grid[collumn][row].itemId+=id;
                    printf("found slot at %i, %i\n", collumn,row);
                    return true;
                }
            }
        }

        return false;
    }


};




