#include <iostream>
using namespace std;
#include <string>
#include <cctype>
#include <cassert>

//MUST FINISH INCLUDING -1 STATEMENTS

//Returns true when an element in the array is found more than once; false otherwise or if there are no elements because size is less than or equal to zero.  For example, for the array folks[ 8 ] show above, hasDuplicates( folks, 5 ) should return false.  hasDuplicates( folks, -1 ) should also return false.  hasDuplicates( folks, 8 ) should return true.
bool hasDuplicates( const std::string array[ ],  int size ){
    bool duplicates=false;
    
    if (size<=0) {
        return false;
    }
    
    for (int i=0; i<size-1; i++) {
        for (int j=i+1; j<size; j++) {
            if (array[i] == array[j]) {
                duplicates=true;
            }
        }
    }
    return duplicates;
}


//Returns the total number of digit characters (that is, the characters '0' - '9') found in all the elements of the passed array argument.  Return -1 if there are no elements because size is less than or equal to zero.  For example, for the array people[ 5 ] show above, countAllDigits( folks, 8 ) should return 3.    countAllDigits( folks, -108 ) should return -1.
int  countAllDigits( const std::string array[ ] , int size ){
    int numDigits=0;
    
    if (size<=0) {
        return -1;
    }
    
    for (int i=0; i<size; i++) {
        for (int j=0; j<array[i].size(); j++) {
            if (array[i].at(j) <= '9') {
                numDigits++;
            }
        }
    }
    
    return numDigits;
}


//If every value in the array is smaller than the one that precedes it, return true; otherwise return false or if size is less than zero return false .  For example, for the array people[ 5 ] shown above, isInDecreasingOrder( people, 5 )  should return false.  When passed an array of size 0 or 1, isInIncreasingOrder( ... ) will return true, since the function will not find a pair of values that fail to meet its ordering criteria.
bool isInDecreasingOrder( const std::string array[ ], int size ){
    bool decreasingOrder=true;
    
    if (size<0) {
        return false;
    }
    if (size==0 || size == 1) {
        return true;
    }
    for (int i=0; i<size-1; i++) {
        if (array[i] <= array[i+1]) {
            decreasingOrder=false;
            break;
        }
    }
    
    return decreasingOrder;
}



//Adjust the items found in the array, shifting each value to the right by amount parameter, filling the resulting first amount elements of the array with the placeholder parameter and returning the number of times the placeholder value was used after all the shifting has been performed or -1 if the size or amount is less than zero.  For example,  for the array people[ 5 ]  shown above,  shiftRight( people, 5, 3, "foo" )  should return 3 and adjust the array to have the values { "foo", "foo", "foo", "samwell", "jon" };    shiftRight( people, -5, 3, "foo" )   should return -1.  shiftRight( people, 5, 25, "foo" ) should return 5 and adjust the array to have the values  { "foo", "foo", "foo", "foo", "foo" };
int  shiftRight( std::string array[ ], int size, int amount, std::string placeholder ){

    if (amount<0 || size < 0) {
        return -1;
    }
    
    if (amount<size) {
        
        for (int i=0; i< size-amount; i++) {
            array[size-i-1]=array[size-amount-i-1];
        }
        for (int j=0; j<amount; j++) {
            array[j]=placeholder;
        }
        
        //print the shifted array
        for (int k=0; k<size; k++) {
            cerr<< array[k]<< "  ";
        }
    }
    
    if (amount>=size) {
        for (int i=0; i< size; i++) {
            array[i]=placeholder;
            cerr<< array[i]<< "  ";
        }
    }
    
    return amount;
}

//Return the smallest index of the element whose value equals the match parameter in the array.  Return -1 if the item was not found or there are no elements because size is less than zero.  For example, for the array folks[ 8 ] shown above, find( folks, 5, "foo" ) should return the value -1, since "foo" was not found.  find( folks, -500, "foo" ) should also return -1.  find( folks, 8, "jon" ) should return 1.
int  find( const std::string array[ ], int size, std::string match ){
    int index=-1;
    if (size>=0) {
        for (int i=0; i<size; i++) {
            if (array[i]==match) {
                index=i;
                break;
            }
        }
    }
    return index;
}

//This function should replace every occurrence of the findLetter value with the replaceLetter value found in all the array elements of the passed array argument.  Return the number of letters that were replaced or -1 if the array has no elements because size is less than or equal to zero.  For example, for the array  people[ 5 ]  shown above,  replaceAllCharacters( people, 5, 'z', 'a' )  should return 0 and the array elements should all be unchanged.   replaceAllCharacters( people, -5, 'z', 'a' )  should return -1.  replaceAllCharacaters( people, 5, 'a', '_' ) should return 4 and the array parameter should be changed to:   { "s_mwell", "jon", "m_rg_ery", "d_enerys", "tyrion" };
int  replaceAllCharacters( std::string array[ ], int size, char findLetter, char replaceLetter ){
    int numOfChanges=0;
    
    if (size<=0) {
        return -1;
    }
    
    for (int i=0; i<size; i++) {
        for (int j=0; j<array[i].length(); j++) {
            if (array[i][j]==findLetter) {
                array[i][j]=replaceLetter;
                numOfChanges++;
            }
        }
    }
    
    for (int j=0; j<size; j++) {
        cerr<< array[j] << " ";
    }
    
    return numOfChanges;
}


int main(){
    
    string a[8] = {"samwell", "jon", "margaery", "daenerys", "tyrion", "sansa", "howard123", "jon4"};
    string b[8] = { "perpetual", "hole", "preset", "persuade", "morning", "goat", "desire", "print"};
    string c[10] = { "squeeze", "sanctify", "murky", "immolate", "santify", "subtract", "subtract", "measly" };
    string d[10] = { "smother12", "befell", "153", "willing", "willing", "substantial4", "decorate2", "successful"};
    string e[10] = { "limping", "answer34", "12345678", "rake", "pencil", "same", "tooth", "kite", "kite", "frame"};
    string f[8] = { "disillusioned", "gracefully", "splendid", "leftist", "supers", "12345", "skip", "lux"};
    string g[8] = { "1234567890", "123456789", "12345678", "1234567", "1234567", "123456", "123456", "123"};
    string h[5] = { "veryLongWord", "long word", "medium", "short", "word"};
    string i[0] = {};
    
    
    assert(!hasDuplicates(a, 8));
    assert(!hasDuplicates(b, 8));
    assert(hasDuplicates(c, 10));
    assert(hasDuplicates(d, 8));
    assert(!hasDuplicates(e, 8));
    assert(hasDuplicates(e, 10));
    assert(!hasDuplicates(f, 8));
    assert(hasDuplicates(g, 8));
    assert(!hasDuplicates(h, 5));
    assert(!hasDuplicates(h, -2));
    assert(!hasDuplicates(i, 0));
    
    assert(countAllDigits(a, 8) == 4);
    assert(countAllDigits(b, 8) == 0);
    assert(countAllDigits(e, 8) == 10);
    assert(countAllDigits(f, 8) == 5);
    assert(countAllDigits(g, 8) == 56);
    
    assert(!isInDecreasingOrder(a, 8));
    assert(!isInDecreasingOrder(g, 8));
    assert(!isInDecreasingOrder(f, 8));
    
    cout<< "shiftRight Tests: \n";
    assert(shiftRight(a, 3, 3, "foo") == 3); cerr<< endl;
    assert(shiftRight(b, 7, 3, "foo") == 3); cerr<< endl;
    assert(shiftRight(c, 3, 7, "foo") == 7); cerr<< endl;
    assert(shiftRight(d, -4, 22, "foo") == -1); cerr<< endl;
    assert(shiftRight(e, 8, -5, "foo")== -1); cerr<< endl;
    
    assert(find(f, 8, "skip") == 6);
    assert(find(f, 8, "disillusioned") == 0);
    assert(find(g, 8, "skip") == -1);
    assert(find(g, 8, "123456") == 5);
    assert(find(h, 8, "long word") == 1);
    assert(find(h, 8, "skip") == -1);
    assert(find(i, 8, "skip") == -1);
    
    assert(replaceAllCharacters(a, 8, 'a', '_')); cerr<< endl;
    assert(replaceAllCharacters(b, 8, 'e', '_')); cerr<< endl;
    assert(replaceAllCharacters(c, 8, 'u', '_')); cerr<< endl;
    assert(replaceAllCharacters(d, 8, 'l', '_')); cerr<< endl;
    assert(replaceAllCharacters(e, 8, '3', '_')); cerr<< endl;

    
    cout<<endl;
    return 0;
}
