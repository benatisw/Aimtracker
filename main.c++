#include <stdlib.h>
#include <iostream>
#include <string>
#include <ctype.h>
#include <fstream>
#include <ctime>

using namespace std;

bool checkIfInteger(string myScore)
{
    for (int s = 0; s < myScore.length(); s++)
    if (isdigit(myScore[s]) == false)
    return false;
    return true;
}
bool checkIfFloat(string myScore)
{
    bool flag = false;
    for (int x = 0; x < myScore.length(); x++)
    {
        if (isalpha(myScore[x]))
        return false;
        else if(ispunct(myScore[x]) && myScore[x] == '.' || myScore[x] == ',')
   {
       if (isdigit(myScore[x-1]) && isdigit(myScore[x+1]) && flag == false){
       flag = true;
       
       }
       else if (isdigit(myScore[x-1]) && isdigit(myScore[x+1]) && flag == true)
       return false;
       else
       return false;

        
       
       
       
       
   }
   
    }
    return true;
     
   

}

int main()
{
   time_t currentime = time(0);
   tm*date = localtime(&currentime);
   int year = 1900 + date ->tm_year;
   int month = 1 + date ->tm_mon;
   int day = date ->tm_mday;   
   ofstream myScores;
   bool exitToSelection = false;
   bool exitAll = false;
   myScores.open("myScores.csv"); 
   cout<<("Please select your level: \n");
   cout<<("1. Beginner \n");
   cout<<("2. Advanced Beginner \n");
   cout<<("3. Sub-Intermediate \n");
   int s1 = 0;
   int s2 = 0;
   int s3 = 0;
   float avg = 0;
   int m = 0;
   int c = 0;
   string myScore;
   float totScore=0;
   cin>>(s1);

    while (s1<1 || s1>3)
    {
    cout<<("You haven't selected any level, please try again\n");
    cin>>(s1);
    }
switch (s1)
{
case 1:
    cout<<("You've selected Beginner difficulty\n");
    cout<<("Now please select which scenario would you like to practice\n");
    cout<<("1. Tracking dominated Routine\n");
    cout<<("2. Click-timing dominated Routine\n");
    cout<<("3. Complete routine\n");
    cin>>(s2);
    while(s2<1 || s2>3)
    {
        cout<<("You've selected a wrong scenario, please try again: \n");
        cout<<("Select the scenario: ");
        cin>>(s2);
    }
        cout<<("You've selected the 'Tracking dominated routine' scenario\n");
        while(exitAll == false)
        {
    switch (s2)
    {
        
        case 1:
            
            cout<<("Now please pick which exercise you're trying to practice: \n");
            cout<<("1. Close Long Strafes\n");
            cout<<("2. FuglaaXYLongStrafe \n");
            cout<<("3. Vertical Long Strafes\n");
            cout<<("4. 1wall6targets \n");
            cout<<("5. Tile Frenzy - Strafing - 01\n");
            cout<<("6. *LG Pin Practice 360 \n");
            cin>>(s3);
            exitToSelection = false;
                while(s3<1 || s3>6)
            {
                cout<<("You've selected a wrong exercise, please try again: \n");
                cout<<("Select the exercise: ");
                cin>>(s3);
            }
            switch(s3)
            {
                case 1:
                    cout<<("You've selected 1. Close Long Strafes\n");
                    cout<<("Here is your weekly average xxx \n");
                    while(exitToSelection == false){
                    cout<<("\nInsert the score you obtained in the exercise: ");    
                    cin>>(myScore);
                    if(myScore == "exit" || myScore == "EXIT" || myScore == "Exit"){
                        exitAll = true;
                        break;
                    }
                    
                    if(ispunct(myScore[0]))
                        cout<<"\nWrong input!";  

                    else if (checkIfInteger(myScore) || checkIfFloat(myScore))
                    {
                        totScore =  stof(myScore) + totScore;
                        myScore.clear();
                        c++;

                    }                    
                    else if(myScore == "new" || myScore == "New" || myScore == "NEW")
                    {
                        avg = totScore/float(c);
                        cout<<"\nYour total score for this exercise is: "<<totScore;
                        totScore = 0;
                        cout<<"\nToday's total attempts for this exercise were: "<<c;
                        c = 0;
                        cout<<"\nAnd your average score on this exercise was: "<<avg<<endl;
                        myScores<<day<<"/"<<month<<"/"<<year<<" Here's your average score for this date: "<<avg<<endl;
                        avg = 0;
                        exitToSelection = true;
                        
                        
                      

                    }                     
                                   
                    }
                    break;

                default :
                cout<<("\nSomething went wrong, please restart the program.");   
                break; 
            
            }
            break;
    
        default :
        cout<<("\nSomething went wrong please restart the program.");
        cout<<s2;
        break;
    }
    //break;
        }    
        break;
    
    
    
    

        


    
        
case 2:
    cout<<("You've selected Advanced Beginner difficulty\n");
    break;
case 3:
    cout<<("You've selected the Sub-Intermediate difficulty");
    break;
default:
    cout<<("Something happened, please restart the program \n");
    break;

}




}





