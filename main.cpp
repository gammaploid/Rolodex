//
// CP2 Flinders University
//

#include <iostream>
#include <string>
#include <unistd.h>

#include "Rolodex.h"


using namespace std;


//global vars --> flags for various modes
auto verbose = false;      // VERBOSE MODE
auto printCurrent = false; //print  current rolodex card mode
auto noDuplicates = false; // No dupes mode
auto reportMode = false;   // report mode


// Report counters
int insertCount = 0;
int duplicateCount = 0;
int deleteCount = 0;
int forwardCount = 0;
int backwardCount = 0;


void rolodex(){

  string word;
  Rolodex rolodex;  // THIS is where we store our words.


  while (cin >> word)
    {

    if (word == "-")
      {
      continue;
    }
    bool isDelete = false;
    if (word[0] == '-'  && word.length() > 1) {  // check if we're deleting (-word format)
      isDelete = true;

      word = word.substr(1); // remove out the '-' at the start
    }



    if (isDelete) {
      //DELETE mode
      if (rolodex.isBeforeFirst() || rolodex.currentValue() <= word) {

        // Move forward thru the rolodex if the word comes later
         while (!rolodex.isAfterLast() && rolodex.currentValue() <word) {
           rolodex.rotateForward();

           forwardCount++;  // forward++

           if (verbose)
              cerr << "rotateForward\n";
         }
       }


      else if (rolodex.isAfterLast() || rolodex.currentValue() >= word) {
        // Now backward if its earlier
        while (!rolodex.isBeforeFirst() && rolodex.currentValue() > word) {
          rolodex.rotateBackward();

          backwardCount++;  //  backward++

          if (verbose)
            cerr << "rotateBackward\n";
        }
      }


      // If FOUND  --> DELETE
      if (rolodex.currentMatches(word)) {

        if (verbose)
          cerr <<  "deleteCurrent\n";

        rolodex.deleteCurrent();

        deleteCount++;  // delete counter
      }
    }

    else{
      // INSERTING  (default mode)
      if (noDuplicates && rolodex.contains(word)) {

        if (verbose)
          cerr << "duplicated word skipped: " << word << "\n";

        duplicateCount++;  // count it as a dupe
        forwardCount += 2;  // Just count minimal rotations for duplicate check
        backwardCount += 1;  // And minimal rotation back
        continue; // skips
      }








      if (rolodex.isBeforeFirst() || word >= rolodex.currentValue()) {
        while (!rolodex.isAfterLast() && word > rolodex.currentValue()) {

          rolodex.rotateForward();

          forwardCount++;  // moving forward again
          if (verbose)
            cerr << "rotateForward\n";
        }
        rolodex.insertBeforeCurrent(word);
        insertCount++;  // count insertion
        if (verbose)
          cerr << "insertBeforeCurrent\n";
      }

      else if (rolodex.isAfterLast() || word < rolodex.currentValue()) {
        //loop
        while (!rolodex.isBeforeFirst() && word < rolodex.currentValue()) {

          rolodex.rotateBackward();

           backwardCount++;  //backward rotation
          if (verbose)
            cerr <<  "rotateBackward\n";
        }

        rolodex.insertAfterCurrent(word);
        insertCount++;  //insert count AGAIN
        if (verbose)
          cerr << "insertAfterCurrent\n";
      }
    }
  }

  if (reportMode) {
    // PRINT out report
    cout <<  insertCount << " "
         << duplicateCount << " "
         << deleteCount << " "
         << forwardCount << " "
         << backwardCount << endl;
    }

  else if (printCurrent) {
    if (!rolodex.isBeforeFirst() &&  !rolodex.isAfterLast()) {
      cout << rolodex.currentValue()  <<  '\n';
    }
  }


  else {
    // roll back to the beginning and print ALL entries
    while (!rolodex.isBeforeFirst()) {
      rolodex.rotateBackward();
      // Don't count these rotations for report mode
      if (!reportMode) {
        backwardCount++;  // one more backward for the final run-through
      }
    }

    rolodex.rotateForward();
    if (!reportMode) {
      forwardCount++;  // this starts it off
    }

    while (!rolodex.isAfterLast()) {
      cout << rolodex.currentValue() << '\n';
      rolodex.rotateForward();
      if (!reportMode) {
        forwardCount++;  // keep on going forward till end!!
      }
    }
  }

}



int main(int argc, char** argv)
{

  int c;

  while ((c = getopt(argc, argv, "vcdr")) != EOF)
    //mode switch
    {
    switch (c) {
      case 'v':
        verbose = true;
        break;
      case 'c':
        printCurrent = true;
        break;
      case 'd':
        noDuplicates = true;
        break;
      case 'r':
        reportMode = true;
        break;
    }
  }

  argc -= optind;
  argv += optind;



//Start out rolodex machine
  rolodex();
  return 0;
}
