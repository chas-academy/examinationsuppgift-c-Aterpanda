#include <stdio.h> //hämtar funktioner för in- och utmatning

int main() { //Startar programet

    char name[5][10];
    int score;
    int student, test;
    float average[5];
    int sum;
//Skapar lite variablar som ska användas i programmet

    for(student = 0; student < 5; student++) //Skapar en loop som körs 5 gånger, en för varje student
    {
        scanf("%s", name[student]); //Läser in namnet på studenten och sparar det i en array

        sum = 0; //Nollställer summan av poängen för varje student

        for(test = 0; test < 13; test++) //Skapar en loop som körs 13 gånger, en för varje test
        {
            scanf("%d", &score); //Läser in poängen för varje test och sparar det i en variabel
            sum += score; //Adderar poängen till summan
        }
        average[student] = sum / 13.0; //Beräknar genomsnittet av poängen

        if(name[student][0] >= 'a' && name[student][0] <= 'z') //Kollar om den första bokstaven i namnet är en liten bokstav
        {
            name[student][0] -= 32; //Om det är en liten bokstav så görs den till en stor bokstav genom att subtrahera 32 från dess ASCII-värde
        }
    }
    
    for(student = 0; student < 5; student++) //Skapar en loop som körs 5 gånger, en för varje student 
    {
        for(test = student + 1; test < 5; test++) //Skapar en loop som körs 4 gånger, en för varje student efter den nuvarande studenten
        {
            if(average[test] > average[student]) //Kollar om genomsnittet av poängen för den nuvarande studenten är mindre än genomsnittet av poängen för den andra studenten
            { // a => c sedan b => a sedan c => b 
                float tempAverage = average[student]; //Om det är sant så sparars värdet så det inte skrivs över när de byter plats.
                average[student] = average[test]; //Och byter plats på genomsnittet av poängen för den nuvarande studenten med genomsnittet av poängen för den andra studenten
                average[test] = tempAverage; //Sparar även genomsnittet av poängen för den andra studenten i en temp variabel så jag kan bya på dem sen

                char tempName[10]; //Och namnen på de två studenterna byts också plats
                for(int k = 0; k < 10; k++) //Skapar en loop som körs 10 gånger, en för varje tecken i namnet
                {
                    tempName[k] = name[student][k]; //Sparar namnet på den nuvarande studenten i en temporär variabel
                    name[student][k] = name[test][k]; //Byter plats på namnet på den nuvarande studenten med namnet på den andra studenten
                    name[test][k] = tempName[k]; //Byter plats på namnet på den andra studenten med namnet på den nuvarande studenten
                }
            }
        } 
    }

    printf("%s\n", name[0]); //Skriver ut namnet på studenten, varje namn på en ny rad
    printf("%s\n", name[4]); //Skriver ut namnet på studenten med sämst genomsnittspoäng.
    printf("%s\n", name[3]); //Skriver ut namnet på studenten, med näst sämst genomsnittspoäng.

          
    
    return 0;
    //Har satt upp så koden kan spotta ut summan/medelvärdet av poängen för varje student men det var kvar att inte skriva ut det.
}
