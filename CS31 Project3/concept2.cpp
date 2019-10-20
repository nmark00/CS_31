#include <iostream>
using namespace std;
#include <string>
#include <cctype>

// rowerString values:     minutes:seconds  strokes/min    distance    hearrate

// Example of rowerString:       :14    28 s/m     42 m    110
// Example of rowerString:  1:14      999 s/m      42 m    1

//This function returns true if its parameter is a well-formed rower string as described above, or  false otherwise.
bool isHeartrateValid(string rowerString){
    
    int heartrate=-1;
    int x= -1;
    bool range=false;
    
    // determine location of the last number
    for (int i= int(rowerString.length()-1); i>-1; i--) {
        if (isdigit(rowerString[i])) {
            x=i;
            break;
        }
    }
    
    // everything after the heartrate number should be a space
    string ending = rowerString.substr(x+1, rowerString.length()-x-1);
    for (int j=0; j< ending.length(); j++) {
        if (!isspace(ending[j])) {
            return false;
        }
    }
    
    // 1's digit of heartrate
    if (isdigit(rowerString[x])) {
        heartrate= rowerString[x] - '0';
    }
    else
        return false;
    // 10's digit of heartrate
    if (isdigit(rowerString[x-1])) {
        heartrate+= 10*(rowerString[x-1]-'0');
    }
    
    if (rowerString[x-2]=='0' || isspace(rowerString[x-2])) {
        if (rowerString[x-1] == '0') {
            return false;
        }
    }
    
    
    // 100's digit
    if (isdigit(rowerString[x-2]) && isdigit(rowerString[x-1])) {
        heartrate += 100* (rowerString[x-2]-'0');
        if (rowerString[x-2]== '0') {
            return false;
        }
    }
    
    if (isdigit(rowerString[x-2]) && isdigit(rowerString[x-1]) && !isspace(rowerString[x-3])) {
        return false;
    }
    
    // range between 1-999
    if (heartrate<=999 && heartrate >=1) {
        range = true;
    }
    else
        return false;
    
    
    return range;
}


bool isDistanceValid(string rowerString){
    
    bool boolDistance=false;
    bool bounds =false;
    bool range = false;
    int distance;
    int x= -1;
    
    for (int i= int(rowerString.length()-1); i>-1; i--) {
        if (rowerString[i] == 'm') {
            x=i;
            break;
        }
    }
    
    // setting bounds
    if (isspace(rowerString[x+1]) && isspace(rowerString[x-1]) ) {
        bounds = true;
    }
    
    // 1's digit
    if (isdigit(rowerString[x-2])){
        distance= rowerString[x-2] - '0';
    }
    else
        return false;
    // 10's digit
    if (isdigit(rowerString[x-3])) {
        distance+= 10* (rowerString[x-3] - '0');
    }
    if (rowerString[x-4] == '0' || isspace(rowerString[x-4])) {
        if (rowerString[x-3] == '0')
            return false;
    }
    
    // 100's digit
    if (isdigit(rowerString[x-4]) && isdigit(rowerString[x-3])) {
        distance += 100* (rowerString[x-4]-'0');
        if (rowerString[x-4]== '0') {
            return false;
        }
    }
    
    if (isdigit(rowerString[x-4]) && isdigit(rowerString[x-3]) && !isspace(rowerString[x-5])) {
        return false;
    }
    if (distance<=999 && distance >=1) {
        range = true;
    }
    else
        return false;
    
    if (range && bounds) {
        boolDistance= true;
    }
    
    return boolDistance;
}

bool isStrokesRateValid(string rowerString){
   
    bool strokerate=false;
    bool rightbound = false;
    bool leftbound = false;
    bool range = false;
    int x= -1;
    int strokes;
    
    for (int i=0; i< rowerString.length(); i++) {
        
        // must locate 's'
        if (rowerString[i]== 's' ) {
            x=i;
        }
    }
    
    // setting bounds
    if (rowerString[x+1] =='/' && rowerString[x+2] == 'm' && rowerString[x+3] == ' ') {
        rightbound = true;
    }
    if (rowerString[x-1] == ' ') {
        leftbound = true;
    }
    
    // counting strokes
    // 1's digit
    if (isdigit(rowerString[x-2])) {
        strokes = rowerString[x-2] - '0';
    }
    else
        return false;
    // 10's digit
    if (isdigit(rowerString[x-3])) {
        strokes += 10* (rowerString[x-3]-'0');
    }
    if (rowerString[x-4]=='0' || isspace(rowerString[x-4])) {
        if (rowerString[x-3] == '0')
            return false;
    }
    
    // 100's digit
    if (isdigit(rowerString[x-4]) && isdigit(rowerString[x-3])) {
        strokes += 100* (rowerString[x-4]-'0');
        if (rowerString[x-4]== '0') {
            return false;
        }
    }
    
    if (isdigit(rowerString[x-4]) && isdigit(rowerString[x-3]) && !isspace(rowerString[x-5])) {
        return false;
    }
    
    // range between 1-999
    if (strokes<=999 && strokes >=1) {
        range = true;
    }
    else
        return false;

    if (range && leftbound && rightbound) {
        strokerate = true;
    }
    
    return strokerate;
}



bool isTimeValid(string rowerString){
    
    bool time=false;
    
    int x=-1;
    int seconds=60;
    int minutes= 60;
    
    // goes through the string
    for (int i=0; i< rowerString.length(); i++) {
        
        // must locate ':'
        if (rowerString[i]== ':' ) {
            x=i;
        }
    }
            // check the bounds
    if (!(x+3<rowerString.length() )) {
        return false;//break;
    }
            
// checking the seconds-- if they don't exist, then break
    if (isdigit(rowerString[x+1]) && isdigit(rowerString[x+2]) && isspace(rowerString[x+3])) {
        seconds = 10* (rowerString[x+1]- '0');
        seconds += rowerString[x+2] - '0';
    }
            

            
    // checking the 10's minutes
    if (x-2>=0) {
        // 10's minute
        if (isdigit(rowerString[x-1]) && isdigit(rowerString[x-2]) ) {
            if (rowerString[x-2]=='0') {
                return false;//break;
            }
            for (int j=0; j<x-2; j++) {
                if (!isspace(rowerString[j])) {
                    return false;
                }
            }
            minutes = rowerString[x-1] - '0';
            minutes += 10* (rowerString[x-2]-'0');
        }
        
        // 1's minute (with spaces)
        if (isspace(rowerString[x-2]) ) {
            if (rowerString[x-1]=='0') {
                return false;//break;
            }
            for (int j=0; j<x-2; j++) {
                if (!isspace(rowerString[j])) {
                    return false;
                }
            }
            if (isdigit(rowerString[x-1]) ){
                minutes = rowerString[x-1] - '0';
            }
        }
        
        // 0's minute (with spaces)
        if (isspace(rowerString[x-1])) {
            for (int j=0; j<x; j++) {
                if (!isspace(rowerString[j])) {
                    return false;
                }
            }
            minutes = 0;
        }
        
    }
    
    // checking the 1's minutes without spaces
    if (x-1==0 ){
        if (isdigit(rowerString[x-1]) ){
            if (rowerString[x-1]=='0') {
                return false;//break;
            }
            else
                minutes = rowerString[x-1] - '0';
        }
    }
    // checking the 0's minutes without spaces
    if (x==0) {
        minutes=0;
    }
    
    if (seconds<60 && minutes<60) {
        time=true;
    }
    
    return time;
}


bool isValidRowerString(string rowerString)
{
    bool isValid= false;
    
    bool time, strokes, distance, heartrate;
    time= isTimeValid(rowerString);
    strokes= isStrokesRateValid(rowerString);
    distance= isDistanceValid(rowerString);
    heartrate= isHeartrateValid(rowerString);
    
    if (time && strokes && distance && heartrate) {
        isValid = true;
    }
    
    return isValid;
}


//If the parameter is a well-formed rower string, this function should return the total meters rowed so far.  If the parameter is not a valid rower string, return -1.
int totalDistance(string rowerString)
{
    if (!isValidRowerString(rowerString)) {
        return -1;
    }
    
    //bool bounds =false;
    
    int distance;
    int x= -1;
    
    for (int i= int(rowerString.length()-1); i>-1; i--) {
        if (rowerString[i] == 'm') {
            x=i;
            break;
        }
    }
    
    // setting bounds
    /*if (isspace(rowerString[x+1]) && isspace(rowerString[x-1]) ) {
        bounds = true;
    }
    */
    
    // 1's digit
    if (isdigit(rowerString[x-2])){
        distance= rowerString[x-2] - '0';
    }
    else
        return false;
    // 10's digit
    if (isdigit(rowerString[x-3])) {
        distance+= 10* (rowerString[x-3] - '0');
    }
    if (rowerString[x-4] == '0' || isspace(rowerString[x-4])) {
        if (rowerString[x-3] == '0')
            return false;
    }
    
    // 100's digit
    if (isdigit(rowerString[x-4]) && isdigit(rowerString[x-3])) {
        distance += 100* (rowerString[x-4]-'0');
        if (rowerString[x-4]== '0') {
            return false;
        }
    }
    
    return distance;
}


//If the parameter is a well-formed rower string, this function should return the heart rate in beats per minute.  If the parameter is not a valid rower string, return -1.
int heartRate(string rowerString)
{
    if (!isValidRowerString(rowerString)) {
        return -1;
    }
    
    int heartrate=-1;
    int x= -1;
    
    
    // determine location of the last number
    for (int i= int(rowerString.length()-1); i>-1; i--) {
        if (isdigit(rowerString[i])) {
            x=i;
            break;
        }
    }
    
    // everything after the heartrate number should be a space
    string ending = rowerString.substr(x+1, rowerString.length()-x-1);
    for (int j=0; j< ending.length(); j++) {
        if (!isspace(ending[j])) {
            return false;
        }
    }
    
    // 1's digit of heartrate
    if (isdigit(rowerString[x])) {
        heartrate= rowerString[x] - '0';
    }
    else
        return false;
    // 10's digit of heartrate
    if (isdigit(rowerString[x-1])) {
        heartrate+= 10*(rowerString[x-1]-'0');
    }
    
    if (rowerString[x-2]=='0' || isspace(rowerString[x-2])) {
        if (rowerString[x-1] == '0') {
            return false;
        }
    }
    
    
    // 100's digit
    if (isdigit(rowerString[x-2]) && isdigit(rowerString[x-1])) {
        heartrate += 100* (rowerString[x-2]-'0');
        if (rowerString[x-2]== '0') {
            return false;
        }
    }
    
    
    return heartrate;
}


//If the parameter is a well-formed rower string, this function should return the stroke rate in strokers per minute.  If the parameter is not a valid rower string, return -1.
int strokesPerMinute(string rowerString)
{
    if (!isValidRowerString(rowerString)) {
        return -1;
    }
    
    //bool rightbound = false;
    //bool leftbound = false;
    int x= -1;
    int strokes;
    
    for (int i=0; i< rowerString.length(); i++) {
        
        // must locate 's'
        if (rowerString[i]== 's' ) {
            x=i;
        }
    }
    
    // setting bounds
    /*
    if (rowerString[x+1] =='/' && rowerString[x+2] == 'm' && rowerString[x+3] == ' ') {
        rightbound = true;
    }
    if (rowerString[x-1] == ' ') {
        leftbound = true;
    }
    */
    
    // counting strokes
    // 1's digit
    if (isdigit(rowerString[x-2])) {
        strokes = rowerString[x-2] - '0';
    }
    else
        return false;
    // 10's digit
    if (isdigit(rowerString[x-3])) {
        strokes += 10* (rowerString[x-3]-'0');
    }
    if (rowerString[x-4]=='0' || isspace(rowerString[x-4])) {
        if (rowerString[x-3] == '0')
            return false;
    }
    
    // 100's digit
    if (isdigit(rowerString[x-4]) && isdigit(rowerString[x-3])) {
        strokes += 100* (rowerString[x-4]-'0');
        if (rowerString[x-4]== '0') {
            return false;
        }
    }
    
    return strokes;

}


//If the parameter is a well-formed rower string, this function should return the elapsed number of minutes rowing.  If the parameter is not a valid rower string, return -1.
int elapsedMinutes(string rowerString)
{
    if (!isValidRowerString(rowerString)) {
        return -1;
    }
    
    
    int x=-1;
    int minutes= 0;
    
    // goes through the string
    for (int i=0; i< rowerString.length(); i++) {
        
        // must locate ':'
        if (rowerString[i]== ':' ) {
            x=i;
        }
    }
    // check the bounds
    if (!(x+3<rowerString.length() )) {
        return false;//break;
    }

    
    
    // checking the 10's minutes
    if (x-2>=0) {
        // 10's minute
        if (isdigit(rowerString[x-1]) && isdigit(rowerString[x-2]) ) {
            if (rowerString[x-2]=='0') {
                return false;//break;
            }
            for (int j=0; j<x-2; j++) {
                if (!isspace(rowerString[j])) {
                    return false;
                }
            }
            minutes = rowerString[x-1] - '0';
            minutes += 10* (rowerString[x-2]-'0');
        }
        
        // 1's minute (with spaces)
        if (isspace(rowerString[x-2]) ) {
            if (rowerString[x-1]=='0') {
                return false;//break;
            }
            for (int j=0; j<x-2; j++) {
                if (!isspace(rowerString[j])) {
                    return false;
                }
            }
            if (isdigit(rowerString[x-1]) ){
                minutes = rowerString[x-1] - '0';
            }
        }
        
        // 0's minute (with spaces)
        if (isspace(rowerString[x-1])) {
            for (int j=0; j<x; j++) {
                if (!isspace(rowerString[j])) {
                    return false;
                }
            }
            minutes = 0;
        }
        
    }
    
    // checking the 1's minutes without spaces
    if (x-1==0 ){
        if (isdigit(rowerString[x-1]) ){
            if (rowerString[x-1]=='0') {
                return false;//break;
            }
            else
                minutes = rowerString[x-1] - '0';
        }
    }
    // checking the 0's minutes without spaces
    if (x==0) {
        minutes=0;
    }
    
    return minutes;
}


//If the parameter is a well-formed rower string, this function should return the elapsed number of seconds rowing.  If the parameter is not a valid rower string, return -1.
int elapsedSeconds(string rowerString)
{
    if (!isValidRowerString(rowerString)) {
        return -1;
    }
    
    int x=-1;
    int seconds=0;
    
    
    // goes through the string
    for (int i=0; i< rowerString.length(); i++) {
        
        // must locate ':'
        if (rowerString[i]== ':' ) {
            x=i;
        }
    }
    // check the bounds
    if (!(x+3<rowerString.length() )) {
        return false;//break;
    }
    
    // checking the seconds-- if they don't exist, then break
    if (isdigit(rowerString[x+1]) && isdigit(rowerString[x+2]) && isspace(rowerString[x+3])) {
        seconds = 10* (rowerString[x+1]- '0');
        seconds += rowerString[x+2] - '0';
    }
    
    return seconds;
}




int main(){
    bool stop=true;
    while (stop) {
        string rowerString;
        cout<< "Enter a rowerString \n";
        getline(cin, rowerString);
        cout<< endl;
        
        cout<<"boolTime is " << isTimeValid(rowerString)<< endl;
        cout<<"boolStrokesRate is " << isStrokesRateValid(rowerString)<< endl;
        cout<<"boolDistance is " << isDistanceValid(rowerString)<< endl;
        cout<<"boolHeartrate is " << isHeartrateValid(rowerString)<< endl;
       
        cout<<"This string is "<< isValidRowerString(rowerString)<< endl;
        
        cout<< "Distance: "<< totalDistance(rowerString)<< endl;
        cout<< "Heartrate: "<< heartRate(rowerString)<< endl;
        cout<< "StrokeRate: "<< strokesPerMinute(rowerString)<< endl;
        cout<< "Minutes: "<< elapsedMinutes(rowerString)<< endl;
        cout<< "Seconds: "<< elapsedSeconds(rowerString)<< endl;
        
        if (rowerString=="stop") {
            stop=false;
        }
    }
    
    return 0;
}

