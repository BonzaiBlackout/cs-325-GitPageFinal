
//Arianna Cooper's Ranking Code

#include<iostream>
#include<iomanip>
#include <cmath>
#include <string>
using namespace std;
int diceRolls();
void printStat(int statPoints[], int bonus[], int professionalRatings[]);// create tomorrow morning!!
int Fighter(int statCount[]);
int Ranger(int statCount[]);
int Rogue(int statCount[]);
int Mage(int statCount[]);
int Cleric(int statCount[]);
int Bard(int statCount[]);
string determineProfession(int professionRatings[]);
void determineStats();


int main()
{
srand((unsigned)time(NULL));
for (int i = 1; i < 11; i++)
{
cout << "Stat block " << i << ": ";
determineStats();
cout << endl;
}


};


void determineStats()
{
    int statPoints[6];// this array is going to hold the stat points without the bonuses
    int bonus[6];// this array will contain all the bonuses for each stat
    int statPointsBonus[6];// this array contains stats with bonus, will be used for the calculation of profession totals
    int professionRatings[6];
    for(int i = 0; i < 6; i++) // gives stat points all its values
    {
        statPoints[i] = diceRolls();
    }
     
    for (int j = 0; j < 6; j++)// calculates bonus for stats
    {
       bonus[j] = ceil((statPoints[j] - 11)/ 2);
    }

     for(int a = 0; a < 6; a++) // adds stats and bonus together for ratings
    {
        statPointsBonus[a] = statPoints[a] + bonus[a];
    } 

    for(int b = 0; b < 6; b++) // this for loop reads in the ratings total for each profession
    {
        switch(b)
        {
            case 0:
                professionRatings[b] = Fighter(statPointsBonus);
            break;
            case 1:
                professionRatings[b] = Ranger(statPointsBonus);
            break;
            case 2:
                professionRatings[b] = Rogue(statPointsBonus);
            break;
            case 3:
                professionRatings[b] = Mage(statPointsBonus);
            break;
            case 4:
                professionRatings[b] = Cleric(statPointsBonus);
            break;
            case 5:
                professionRatings[b] = Bard(statPointsBonus);
            break;
        }
    }

  printStat(statPoints, bonus, professionRatings);
     
}

string determineProfession(int professionRatings[])
{
    int largest = professionRatings[0];
    for(int i = 0; i < 6; i++)
    {
        if (professionRatings[i] > largest)
        {
            largest = professionRatings[i];
        }
    }
        if (largest == professionRatings[0]) // bool statement checks which value matches the profession
        {
            return "Fighter";
        }
        else if (largest == professionRatings[1])
        {
            return "Ranger";
        }
        else if (largest == professionRatings[2])
        {
            return "Rogue";
        }
        else if (largest == professionRatings[3])
        {
            return "Mage";
        }
        else if (largest == professionRatings[4])
        {
            return "Cleric";
        }
        else
        {
            return "Bard";
        }
}


int diceRolls()// rolls dice 4 times and adds the highest 3 values together
{
    int total = 0;
    int d1 = ((rand() % 6) + 1);
    int d2 =((rand() % 6) + 1);
    int d3 =((rand() % 6) + 1);
    int d4 = ((rand() % 6) + 1);

    if (d1 <= d2 && d1 <= d3 && d1 <= d4)
    {
        total = d2 + d3 + d4; 
    }
     if (d2 <= d1 && d2 <= d3 && d2 <= d4)
    {
        total = d1 + d3 + d4; 
    }
     if (d3 <= d1 && d3 <= d2 && d3 <= d4)
    {
        total = d1 + d2 + d4; 
    }
     if (d4 <= d2 && d4 <= d1 && d4 <= d3)
    {
        total = d1 + d2 + d3; 
    }
    return total;
}


int Fighter(int statCount[]) // total count for fighter, will be called within printfunction
{
    int total = 0;
    int calculateTotal[6];
    for(int i = 0; i < 6; i++)
    {
        switch(i)
        {
            case 0:
                calculateTotal[i] = statCount[i] *10;
            break;
            case 1:
                calculateTotal[i] = statCount[i] *5;
            break;
            case 2:
                calculateTotal[i] = statCount[i] *5;
            break;
            case 3:
                calculateTotal[i] = statCount[i];
            break;
            case 4:
                calculateTotal[i] = statCount[i] *2;
            break;
            case 5:
                calculateTotal[i] = statCount[i] *2;
            break;
        }
    }
    for(int j = 0; j < 6; j++)
    {
        total = total + calculateTotal[j];
    }
    return total;
}


int Ranger(int statCount[]) // total count for ranger, will be called within printfunction
{
    int total = 0;
    int calculateTotal[6];
    for(int i = 0; i < 6; i++)
    {
        switch(i)
        {
            case 0:
                calculateTotal[i] = statCount[i] *5;
            break;
            case 1:
                calculateTotal[i] = statCount[i] *10;
            break;
            case 2:
                calculateTotal[i] = statCount[i] *2;
            break;
            case 3:
                calculateTotal[i] = statCount[i] *2;
            break;
            case 4:
                calculateTotal[i] = statCount[i] *5;
            break;
            case 5:
                calculateTotal[i] = statCount[i];
            break;
        }
    }
    for(int j = 0; j < 6; j++)
    {
        total = total + calculateTotal[j];
    }
    return total;
}

int Rogue(int statCount[]) // total count for rogue, will be called within printfunction
{
    int total = 0;
    int calculateTotal[6];
    for(int i = 0; i < 6; i++)
    {
        switch(i)
        {
            case 0:
                calculateTotal[i] = statCount[i] *5;
            break;
            case 1:
                calculateTotal[i] = statCount[i] *2;
            break;
            case 2:
                calculateTotal[i] = statCount[i] *10;
            break;
            case 3:
                calculateTotal[i] = statCount[i]*5;
            break;
            case 4:
                calculateTotal[i] = statCount[i];
            break;
            case 5:
                calculateTotal[i] = statCount[i] *2;
            break;
        }
    }
    for(int j = 0; j < 6; j++)
    {
        total = total + calculateTotal[j];
    }
    return total;
}

int Mage(int statCount[]) // total count for Mage, will be called within printfunction
{
    int total = 0;
    int calculateTotal[6];
    for(int i = 0; i < 6; i++)
    {
        switch(i)
        {
            case 0:
                calculateTotal[i] = statCount[i] *2;
            break;
            case 1:
                calculateTotal[i] = statCount[i];
            break;
            case 2:
                calculateTotal[i] = statCount[i] *2;
            break;
            case 3:
                calculateTotal[i] = statCount[i]*10;
            break;
            case 4:
                calculateTotal[i] = statCount[i]*5;
            break;
            case 5:
                calculateTotal[i] = statCount[i] *5;
            break;
        }
    }
    for(int j = 0; j < 6; j++)
    {
        total = total + calculateTotal[j];
    }
    return total;
}

int Cleric(int statCount[]) // total count for cleric, will be called within printfunction
{
    int total = 0;
    int calculateTotal[6];
    for(int i = 0; i < 6; i++)
    {
        switch(i)
        {
            case 0:
                calculateTotal[i] = statCount[i] *2;
            break;
            case 1:
                calculateTotal[i] = statCount[i] *5;
            break;
            case 2:
                calculateTotal[i] = statCount[i];
            break;
            case 3:
                calculateTotal[i] = statCount[i] *2;
            break;
            case 4:
                calculateTotal[i] = statCount[i]*10;
            break;
            case 5:
                calculateTotal[i] = statCount[i] *5;
            break;
        }
    }
    for(int j = 0; j < 6; j++)
    {
        total = total + calculateTotal[j];
    }
    return total;
}

int Bard(int statCount[]) // total count for Bard, will be called within printfunction
{
    int total = 0;
    int calculateTotal[6];
    for(int i = 0; i < 6; i++)
    {
        switch(i)
        {
            case 0:
                calculateTotal[i] = statCount[i];
            break;
            case 1:
                calculateTotal[i] = statCount[i] *2;
            break;
            case 2:
                calculateTotal[i] = statCount[i] *5;
            break;
            case 3:
                calculateTotal[i] = statCount[i] *5;
            break;
            case 4:
                calculateTotal[i] = statCount[i]*2;
            break;
            case 5:
                calculateTotal[i] = statCount[i] *10;
            break;
        }
    }
    for(int j = 0; j < 6; j++)
    {
        total = total + calculateTotal[j];
    }
    return total;
}




void printStat (int statPoints[], int bonus[], int professionalRating[]) // prints a full fledged list of stats and ratings
{
    string statCategory[6] = {"Str","Con","Dex","Int","Wis","Cha"};

    for(int i = 0; i < 6; i++)
    {
        if (bonus[i] >= 0)
        {
            cout << statCategory[i] << "=" << statPoints[i] << "(+" << bonus[i] << ") "; 
        }
        else
        {
            cout << statCategory[i] << "=" << statPoints[i] << "(" << bonus[i] << ") "; 
        }
    }

    cout << endl << "Ratings:" << endl;
    
    for (int j = 0; j < 6; j++)
        {
            if (j == 0)
            {
                cout << "Fighter: "  << professionalRating[0];;
            }
            if (j == 1)
            {
                cout << "Ranger : " << professionalRating[1];
            
            }
            if(j == 2)
            {
                cout << "Rogue  : " << professionalRating[2];
            }
            if (j == 3)
            {
                cout << "Mage   : "<< professionalRating[3];
            }
            if (j == 4)
            { 
                cout << "Cleric : " << professionalRating[4];
            }
            if(j == 5)
            {
                cout << "Bard   : " << professionalRating[5];
            }
        
        cout << endl;
        }
        cout << "Best Option: " << determineProfession(professionalRating);
        cout << endl;
    }
    















