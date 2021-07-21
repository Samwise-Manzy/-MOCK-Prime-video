// File Name: assign2_sam234.cpp
//
// Auther Samuel Manzanares
// Date: 06/08/2021
// Assignment Number: 2
// CS 2308.501 Summer 2021
// Instructor: Dr. J. Marcos Palacios

//(MOCK) Prime video team is working on an update to their mobile app,
//I was asked to delope a C++ program that allows users to
//query the digital movie library file of up to 100 movies. Users were given
//a menu of 5 options to choose from for their movie search. 

1. Display movies sorted by title\n"
     << "2. Display movies sorted by rating\n"
     << "3. Lookup title and actors by id\n"
     << "4. Lookup id by title and either actor\n"
     << "5. Quit the Program\n";

//****************This is the line of 80 characters in length*******************
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

struct Data { // struct of data type Data to house movie info
    string id;
    string title;
    string actor1;
    string actor2;
    int releaseYear;
    double rating;
};

//***********************************************************
// sortTitle: sorts title in alphebetical order
//
// arr is the array of movie info
// size is the number of elements in the array
// void return type
//***********************************************************
void sortTitle(Data arr[], int size) { 
    
    bool swap; // indicates end of sorting
    Data temp; // holds temp variable for swap

    do {

        swap = false;
        for (int i = 0; i < (size-1); i++) { // assigns 1-4 and not 0-3

            if (arr[i].title > arr[i+1].title) {

                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swap = true;
            }
        }
        size--;
    } while(swap);

}

//***********************************************************
// sortRating: sorts rating; descending 
//
// arr is the array of movie info
// size is the number of elements in the array
// void return type
//***********************************************************
void sortRating(Data arr[], int size) { //******* need to seperate into 
    
    bool swap; // indicates end of sorting
    Data temp; // holds temp variable for swap

    do {

        swap = false;
        for (int i = 0; i < (size-1); i++) { // assigns 1-4 and not 0-3

            if (arr[i].rating < arr[i+1].rating) {

                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swap = true;
            }
        }
        size--;
    } while(swap);

}

//***********************************************************
// sortId: sorts id for binary search
//
// arr is the array of movie info
// size is the number of elements in the array
// void return type
//***********************************************************
void sortId(Data arr[], int size) { //******* need to seperate into 
    
    bool swap; // indicates end of sorting
    Data temp; // holds temp variable for swap

    do {

        swap = false;
        for (int i = 0; i < (size-1); i++) { // assigns 1-4 and not 0-3

            if (arr[i].id > arr[i+1].id) {

                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swap = true;
            }
        }
        size--;
    } while(swap);

}

//***********************************************************
// searchId: binary search for target id
//
// arr is the array of movie info
// size is the number of elements in the array
// target is the id being searched
// returns array index of target 
//***********************************************************
int searchId (Data arr[], int size, string target) {

    int first = 0, // index of beginning of search list 
        last = size - 1, // index of end of search list
        middle, // index of midpoint of search list
        position = -1, // position of target value 
        targetIndex;

    bool found = false; // flag 

    while (arr[first].id <= target && !found) {

        middle = (first + last) / 2; // calc midpoint

        if (arr[middle].id == target) {
            found = true;
            position = middle;
        } else if (target < arr[middle].id) {
            last = middle - 1; // search list = lower half
        } else {
            first = middle + 1; // search list = upper half
        }
    }
    
    return position;
}

//***********************************************************
// searchTitle: linear search for target title
//
// arr is the array of movie info
// size is the number of elements in the array
// targetTitle is the title being searched
// returns array index of target
//***********************************************************
int searchTitle(Data arr[], int size, string targetTitle) { 


    int position = -1; // positoin of target 

    for (int i = 0; i < size; i++) {
        if (arr[i].title == targetTitle) {
            position = i;
        }
    }
    
    return position;

}

//***********************************************************
// searchActor1: linear search for target actor
//
// arr is the array of movie info
// size is the number of elements in the array
// targetTitle is the actor1 being searched
// returns array index of target
//***********************************************************
int searchActor1(Data arr[], int size, string targetActor) { 

    int position = -1; // positoin of target 

    for (int i = 0; i < size; i++) {
        if (arr[i].actor1 == targetActor) {
            position = i;
        }
    }
    
    return position;
}

//***********************************************************
// searchActor2: linear search for target actor
//
// arr is the array of movie info
// size is the number of elements in the array
// targetTitle is the actor2 being searched
// returns array index of target
//***********************************************************
int searchActor2(Data arr[], int size, string targetActor) { 

    int position = -1; // positoin of target 

    for (int i = 0; i < size; i++) {
        if (arr[i].actor2 == targetActor) {
            position = i;
        }
    }
    
    return position;
}

//***********************************************************
// outputById: console output for choice 3 movie data
//
// arr is the array of movie info
// index is the array index of searched element
// void return type
//***********************************************************
void outputById (Data arr[], int index) {

    cout << "The Movie with id " << arr[index].id << " is:\n"
         << arr[index].title << endl
         << "Actors:\n"
         << arr[index].actor1 << endl
         << arr[index].actor2 << endl;

}

//***********************************************************
// outputTitleActor: console output for choice 4 movie data
//
// arr is the array of movie info
// index is the array index of searched element
// void return type
//***********************************************************
void outputTitleActor (Data arr[], int index) {

    cout << "The id of " << arr[index].title
         << " with " << arr[index].actor1 
         << " and " << arr[index].actor2 
         << " is " << arr[index].id << endl;

}

//***********************************************************
// choice3: console output for choice3
//
// movies is the array of movie info
// count is the size of array
// void return type
//***********************************************************
void choice3(Data movies[], int count) {

    string inputId; // user input id
    int index; // searched index of inputId
    cout << "Enter the id of the movie: ";
    cin >> inputId;

    if (searchId(movies, count, inputId) == -1) {
        cout << "No movie found with that id.\n";
    } else {
        cout << endl;
        sortId(movies, count);
        index = searchId(movies, count, inputId);
        outputById(movies, index);
    }

}

//***********************************************************
// choice4: console output for choice4
//
// movies is the array of movie info
// count is the size of array
// void return type
//***********************************************************
void choice4(Data movies[], int count) {
    string title, actor; // user input title search 
    // user input actor
    int titleIndex, actorIndex; //array index of found title
    // array index of found actor

    cout << "Enter the title: ";
    cin >> ws;
    getline(cin, title);

    cout << "Enter either actor: ";
    cin >> ws;
    getline(cin, actor);
    cout << endl;

    titleIndex = searchTitle(movies, count, title);

    if (searchActor1(movies, count, actor) != -1) {
        actorIndex = searchActor1(movies, count, actor);
    } else if (searchActor2(movies, count, actor) != -1) {
        actorIndex = searchActor2(movies, count, actor);
    } else {
        actorIndex = -1;
    }

    if (actorIndex == titleIndex && actorIndex != -1) {
        outputTitleActor(movies, titleIndex);
    } else {
        cout << "No id found with that title and/or actor.\n";
    }

}

//***********************************************************
// output: console output formate for choice 1 & 2
//
// arr is the array of movie info
// size is the size of array
// void return type
//***********************************************************
void output(Data arr[], int size) { 

    for (int i = 0; i < size; i++) { 
        cout << setw(23) << left << arr[i].title
             << setw(21) << left << arr[i].actor1
             << setw(21) << left << arr[i].actor2
             << setw(7) << left << arr[i].releaseYear
             << setw(4) << left << arr[i].rating << endl;
    }

}

//***********************************************************
// displayMenu: menu console output 
//
// void return type
//***********************************************************
void displayMenu() {

    cout << "\nMenu\n\n";
    cout << "1. Display movies sorted by title\n"
         << "2. Display movies sorted by rating\n"
         << "3. Lookup title and actors by id\n"
         << "4. Lookup id by title and either actor\n"
         << "5. Quit the Program\n";

}

int main() {    

    int choice; // user menu input choice

    const int SIZE = 100; // const for arr max size
    Data movieData[SIZE]; // array of structures for movie library data input


    ifstream fin; 

    fin.open("program2library.txt");

     // Error check to ensure the input file opened:
    if (!fin) {
        cout << "Could not open file. Terminating program.\n";
        return -1;
    }

    int count = 0; //track how many movies are in file 

    while (!fin.eof() && count < SIZE) {

        fin >> movieData[count].id;
        fin >> ws; 
        getline(fin, movieData[count].title);
        fin >> ws;
        getline(fin, movieData[count].actor1);
        fin >> ws;
        getline(fin, movieData[count].actor2);
        fin >> movieData[count].releaseYear >> movieData[count].rating;

        count++;
    }

     displayMenu();
     cout << endl;

     cout << "Enter your choice: ";
     cin >> choice;
     cout << endl;

     while (choice < 1 && choice > 5) {
         cout << "Invalid choice. Please enter again: ";
         cin >> choice;
     }
    
     while (choice != 5) {
         if(choice == 1) {
             sortTitle(movieData, count);
             output(movieData, count);
         } else if(choice == 2) {
             sortRating(movieData, count);
             output(movieData, count);
         } else if(choice == 3) {
             choice3(movieData, count);
         } else {
             choice4(movieData, count);
         }

         displayMenu();
         cout << endl;

         cout << "Enter your choice: ";
         cin >> choice;
         cout << endl;

     }

     cout << "Thank you for using the Prime Video app.\n\n";

    sortTitle(movieData, count);

    cout << movieData[0].title << endl;
    

    return 0;
}
