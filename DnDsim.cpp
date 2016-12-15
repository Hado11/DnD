#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;


class DnD
{
	public:
    int barb[5][1]; 		//declaring barbarian array
    int fight[6][1]; 		//declaring fighter array
    int pally[6][1];		//declaring paladin array
    int fightWeapon;            //fighter weapon select
    int fightStyle;             //fighter fighting style select
    int fightFeat;              //fighter feat select
    int pallyWeapon;            //paladin weapon selec
    int pallyStyle;             //paladin fight style select
    
    void barbarian(int, int , int);                                             //barbarian info
    void fighter(int, int, int, int, int, int, int);                            //fighter info
    void paladin(int, int, int, int, int);                                      //paladin info
    void stats(int);                                                            //final stat loadout for each opponent
    void BarbaianvFighter(int, int, int, int, int, int, int, int&, int&);       //barbvfighter function
    void FightervPaladin(int, int, int, int, int, int, int&, int&);             //fightervpally 
    void BarbarianvPaladin(int, int, int, int, int, int, int, int, int&, int&); //barbvpally
}dnd;


int main()
{
    srand(time(0));
    
    int choice;
    int count;                                                  //choose contestants
    int watch;                                                  //allows the user to observe rolls
    int stats;                                                  //tells 'stats' function which opponents to display
    while (choice != 0)
    {   
        int flatAttack = (rand() % 20 +1); 			//flat roll to hit
	int modAttack = (rand() % 20 +1); 			//roll to hit + modifiers
	int greatAxe = (rand() % 12 +1) + 3; 			//greataxe damage roll
	
        int gs1 = (rand() % 6 + 1);                             //dice 1 for greatsword
        int gs2 = (rand() % 6 + 1);                             //dice 2 for greatsword
        int fgreatSword = (gs1) + (gs2) + 3;                    //fighter greatsword (redundant, but used in code)
        int greatSword = (gs1) + (gs2) + 3; 	                //greatsword damage roll
	int longSword = (rand() % 8 + 1) + 3;                   //longsword damage roll
        int rapier =    (rand() % 8 + 1) + 3;                   //rapier damage roll
        int shortSword = (rand() % 6 + 1) + 3;                  //shortsword damage roll

        int secondWind = (rand() % 10 + 1) + 2;			//fighter second wind roll
        int pallySmite = (rand() % 8 + 1) + (rand() % 8 +1);    //paladin smite damage roll
        
	int barbarian = 0; 					//barbarian wins counter
	int fighter = 0;					//fighter wins counter
	int paladin = 0;	                            	//paladin wins counter
        cout << "<=====Fight Simulation=======>" << endl;
        cout << "1. Barbarian   vs      Fighter" << endl;
        cout << "2. Fighter     vs      Paladin" << endl;
        cout << "3. Paladin     vs    Barbarian" << endl;
        cout << "4.            QUIT" << endl;
        cout << "<============================>" << endl;
        cout << "Enter Selection: ";
        cin >> choice;
        cout << "===================" << endl;

        switch(choice)  
        {
            case 1:
            {
                stats = 1;
                dnd.barbarian(flatAttack, modAttack, greatAxe);
                dnd.fighter(flatAttack, modAttack, fgreatSword, longSword, rapier, shortSword, secondWind);
                dnd.stats(stats);
                
                cout << "<---------------------------------------------------->" << endl;
                cout << "How many times would you like to run this simulations?" << endl;
                cout << "<---------------------------------------------------->" << endl;
                cout << "Enter Amount: ";
                cin >> count;
                cout << "===================" << endl;

                cout << "<===Watch the battle unfold===>" << endl;
                cout << "Would you like to see the rolls?" << endl;
                cout << "1. Yes" << endl;
                cout << "2. No" << endl;
                cout << "<=============================>" << endl;
                cout << "Enter Selection: ";
                cin >> watch;
                cout << "===================" << endl;
                for (int i = 0; i < count; i++)
                {
                    dnd.BarbaianvFighter(watch, flatAttack, modAttack, gs1, gs2, greatAxe, secondWind, barbarian, fighter);
                }
                cout <<"<=====Total Wins=====>" << endl;
	        cout << "Barbarian: " << barbarian << endl;
	        cout << "Fighter: " << fighter << endl;
	        cout <<"<=====Total Wins=====>" << endl;
                break;
            }
            case 2:
            {   
                stats = 2;
                dnd.fighter(flatAttack, modAttack, fgreatSword, longSword, rapier, shortSword, secondWind); 
                dnd.paladin(flatAttack, modAttack, greatSword, longSword, pallySmite);
                dnd.stats(stats);

                cout << "<---------------------------------------------------->" << endl;
                cout << "How many times would you like to run this simulations?" << endl;
                cout << "<---------------------------------------------------->" << endl;
                cout << "Enter Amount: ";
                cin >> count;
                cout << "===================" << endl;
                cout << "<===Watch the battle unfold===>" << endl;
                cout << "Would you like to see the rolls?" << endl;
                cout << "1. Yes" << endl;
                cout << "2. No" << endl;
                cout << "<=============================>" << endl;
                cout << "Enter Selection: ";
                cin >> watch;
                cout << "===================" << endl;
                for (int i = 0; i < count; i++)
                {
                    dnd.FightervPaladin(watch, flatAttack, modAttack, gs1, gs2, secondWind, fighter, paladin);
                }
                cout <<"<=====Total Wins=====>" << endl;
	        cout << "Fighter: " << fighter << endl;
                cout << "Paladin: " << paladin << endl;
	        cout <<"<=====Total Wins=====>" << endl;
                break;
            }
            case 3:
            {
                stats = 3;
                dnd.barbarian(flatAttack, modAttack, greatAxe);
                dnd.paladin(flatAttack, modAttack, greatSword, longSword, pallySmite);
                dnd.stats(stats);

                cout << "<---------------------------------------------------->" << endl;
                cout << "How many times would you like to run this simulations?" << endl;
                cout << "<---------------------------------------------------->" << endl;
                cout << "Enter Amount: ";
                cin >> count;
                cout << "===================" << endl;
                cout << "<===Watch the battle unfold===>" << endl;
                cout << "Would you like to see the rolls?" << endl;
                cout << "1. Yes" << endl;
                cout << "2. No" << endl;
                cout << "<=============================>" << endl;
                cout << "Enter Selection: ";
                cin >> watch;
                cout << "===================" << endl;
                for (int i = 0; i < count; i++)
                {
                    dnd.BarbarianvPaladin(watch, flatAttack, modAttack, gs1, gs2, greatAxe, greatSword, longSword, barbarian, paladin);
                }
                cout <<"<=====Total Wins=====>" << endl;
	        cout << "Barbarian: " << barbarian << endl;
	        cout << "Paladin: " << paladin << endl;
	        cout <<"<=====Total Wins=====>" << endl;
                break;
            }
            case 4:
            {
                choice = 0;
                break;
            }
            default:
            {
                cout << "Please enter a number between 1 and 4." << endl;
            }
        }
    };		
}

void DnD::barbarian(int flatAttack, int modAttack, int greatAxe)
{
    barb[0][0] = 25;            //HP
    barb[1][0] = 15;            //AC
    barb[2][0] = flatAttack;    //flat attack roll
    barb[3][0] = modAttack;     //attack roll with mods
    barb[4][0] = greatAxe +2;   //greataxe damage roll + rage
}

void DnD::fighter(int flatAttack, int modAttack, int fgreatSword, int longSword, int rapier, int shortSword, int secondWind)
{

    cout << "<------FIGHTER WEAPON CHOICE------>" << endl;
    cout << "What type of weapon for Paladin?" <<endl;
    cout << "1. Greatsword" << endl;
    cout << "2. Longsword + shield" << endl;
    cout << "3. Dual Wielding" << endl;
    cout << "<------FIGHTER WEAPON CHOICE------>" << endl;
    cout << "Enter Selection: ";
    cin >> fightWeapon;
    cout << "===================" << endl;

    if (fightWeapon == 1)           //if greatsword
    {
        fight[3][0] = fgreatSword;
        fight[2][0] = flatAttack;
        fight[1][0] = 16;
    }

    else if (fightWeapon == 2 )     //if longsword + shield
    {
    	cout << "<-----------FIGHTER FIGHTING STYLE----------->" << endl;
    	cout << "What type of fighting style for the Fighter?" << endl;
    	cout.width(15); cout << left << "1. Defense";
    	cout.width(30); cout << right << "(+1 AC)" << endl;
    	cout.width(15); cout << left << "2. Dueling";
    	cout.width(30); cout << right <<"(+2 damage)" << endl;
    	cout << "<-----------FIGHTER FIGHTING STYLE----------->" << endl;
    	cout << "Enter Selecting: ";
    	cin >> fightStyle;
    	cout << "===================" << endl;
    }

    else if (fightWeapon == 3)      //if rapier or shortsowrd
    {
        cout << "<-----------FIGHTER FIGHTING STYLE------------->" << endl;
	cout << "What type of fighting style for the Fighter?" << endl;
	cout.width(23); cout << left << "1. Defense"; 
        cout.width(25); cout << right << "(+1 AC)" << endl;
	cout.width(23); cout << left << "2. Two-Weapon Fighting";
	cout.width(25); cout << right << "(dual wield + mod damage)" << endl;
        cout << "<-----------FIGHTER FIGHTING STYLE------------->" << endl;
	cout << "Enter Selecting: ";
	cin >> fightStyle;
        cout << "===================" << endl;  

        cout << "<-------------DUAL WIELDING FEAT------------->" << endl;
        cout.width(22); cout << left << "1. Defensive Duelist";
        cout.width(25); cout << right << "(+2 AC + shortsword d6's)" << endl;
        cout.width(22); cout << left << "2. Dual Wielder";
        cout.width(25); cout << right<< "(+1 AC + rapier d8's)" << endl;
        cout << "<-------------DUAL WIELDING FEAT------------->" << endl;
        cout << "Enter Selection: ";
        cin >> fightFeat;
        cout << "===================" << endl;
    }    
        

        
    if (fightWeapon ==3)
    {
        if(fightFeat == 1)
        {
            fight[1][0] = 16;
            fight[2][0] = modAttack;
            fight[3][0] = shortSword;
        }
        else
        {
            fight[1][0] = 15;
            fight[2][0] = modAttack;
            fight[3][0] = rapier;
        }    
    }
    else if (fightStyle == 1)
    {
     
        fight[1][0] = 19;
        fight[2][0] = modAttack;
        fight[3][0] = longSword;
   }
   else if (fightStyle ==2)
   {
        fight[1][0] = 18;
        fight[2][0] = modAttack;
        fight[3][0] = longSword + 2;
   }
   else if (fightFeat == 1)
   {
        fight[1][0] = 16;
        fight[2][0] = modAttack;
        fight[3][0] = longSword;
   }
   
    fight[0][0] = 22;           //HP
    //fight[1][0]               //AC
    //fight[2][0]               //flat or mod attack roll
    //fight[3][0]               //greatsword longsword rapier shortsword
    fight[4][0] = 1;            //action surge counter
    fight[5][0] = secondWind;   //secondWind 
   
}

void DnD::paladin(int flatAttack, int modAttack, int greatSword, int longSword, int pallySmite)
{
    //reroll so fighter and pally dont start off with the same roll
    flatAttack = (rand() % 20 + 1);
    modAttack = (rand() % 20 + 1) + 5;
    longSword = (rand() % 8 + 1) + 3;
    

    cout << "<------PALADIN WEAPON CHOICE------>" << endl;
    cout << "What type of weapon for Paladin?" <<endl;
    cout << "1. Greatsword" << endl;
    cout << "2. Longsword + shield" << endl;
    cout << "<------PALADIN WEAPON CHOICE------>" << endl;
    cout << "Enter Selection: ";
    cin >> pallyWeapon;
    cout << "===================" << endl;
    
    if (pallyWeapon == 1)               //if greatsword
    {
        pally[3][0] = greatSword;
        pally[2][0] = flatAttack;
        pally[1][0] = 16;
    }

    else if (pallyWeapon == 2) 	//if longsword + shield   
    {
	cout << "<-----------PALADIN FIGHTING STYLE----------->" << endl;
	cout << "What type of fighting style for the Paladin?" << endl;
	cout.width(15);cout << left << "1. Defense";
        cout.width(30);cout << right<< "(+1 AC)" << endl;
	cout.width(15);cout << left << "2. Dueling";
        cout.width(30);cout << right << "(+2 damage)" << endl; 
	cout << "<-----------PALADIN FIGHTING STYLE----------->" << endl;
	cout << "Enter Selecting: ";
	cin >> pallyStyle;
	cout << "===================" << endl;
        if (pallyStyle == 1)           //if defense style
        {
            pally[1][0] = 19;
            pally[2][0] = modAttack;
            pally[3][0] = longSword;
        }
        else if (pallyStyle ==2)        //if duelist style
        {
            pally[1][0] = 18;
            pally[2][0] = modAttack;
            pally[3][0] = longSword + 2;
        }
        
    }


    pally[0][0] = 22;           //HP
    //pally[1][0]               //AC
    //pally[2][0]               //flat or mod attack roll
    //pally[3][0]               //greatsword or longsword
    pally[4][0] = pallySmite;   //smite counter
    pally[5][0] = 10;           //lay on hands
   
}

void DnD::stats(int stats)
{
    if (stats == 1)                 //pulls barbarian & fighter loadout stats to display
    {
        int barbAC = barb[1][0];
	int barbHP = barb[0][0];
        int fightAC = fight[1][0];
        int fightHP = fight[0][0];

        string displayWeapon;
        string displayStyle;
        string displayFeat;

        int x;
        int y;
        int z;

        if (fightWeapon == 1)
        {
            displayWeapon = "Greatsword";
            displayStyle = "GWF";
            x = 18;
            y = 25;
            if (barbAC < 17)
            {
                displayFeat = "GWM";
                z= 25;
            }
            else
            {
                displayFeat = "N/A";
                z = 25;
            }
        }
        else if (fightWeapon == 2)
        {
            displayWeapon = "Longsword";
            x = 19;
            if (fightStyle == 1)
            {
                displayStyle = "Defense";
                displayFeat = "N/A";
                y = 21;
                z = 25;
            }
            else if (fightStyle == 2)
            {
                displayStyle = "Dueling";
                displayFeat = "N/A";
                y = 21;
                z = 25;
            }
        }


   
        if(fightWeapon == 3 && fightFeat == 1)
        {
            displayWeapon = "Shortsword";
            displayFeat = "Defensive Duelist";
            x = 18;
            z = 11;
        
            if (fightStyle == 1)
            {
                displayStyle = "Defense";
                y = 21;
        
            }
            else if (fightStyle == 2)
            {
                displayStyle = "TWF";
                y = 25;
            }
        }
        else if (fightWeapon == 3 && fightFeat == 2)
        {
            displayWeapon = "Rapier";
            displayFeat = "Dual Wielder";
            x = 22; 
            z = 16;

            if (fightStyle == 1)
            {
                displayStyle = "Defense";
                y = 21;
            }
            else if (fightStyle == 2)
            {
                displayStyle = "TWF";
                y = 25;
            }
        }
    
  
        cout << "<===========================BARBARIAN=======================>" << endl;
        cout.width(10); cout << left << "|";
        cout.width(10); cout << internal << "BARBARIAN"; 
        cout.width(12); cout << internal << "|";
        cout.width(18); cout << internal << "FIGHTER"; 
        cout.width(11); cout << right << "|" << endl;
        cout.width(5); cout << left << "|HP: " << barbHP;   
        cout.width(25); cout << internal << "|";
        cout.width(26); cout << right << "HP: " << fightHP << "|" << endl;
        cout.width(5); cout << left << "|AC: " << barbAC;
        cout.width(25); cout << internal << "|";
        cout.width(26); cout << right << " AC: " << fightAC << "|" << endl  ;
        cout.width(15); cout << left << "|Fighting Style: N/A";
        cout.width(12); cout << internal << "|";
        cout.width(y); cout << right << "Fighting Style: " << displayStyle << "|" << endl;
        cout.width(15); cout << left << "|Feat: GWM";   
        cout.width(17); cout << internal << "|";
        cout.width(z); cout << right << "Feat: " << displayFeat << "|" << endl;
        cout.width(30); cout << left << "|Barbarian Weapon: Greataxe";
        cout.width(2); cout << internal << "|";
        cout.width(x); cout << right << " Fighter Weapon: " << displayWeapon << "|" << endl;
        cout << "<============================FIGHTER========================>" << endl;
  
    }

    else if (stats == 2)            //pulls fighter & paladin loadout stats to display
    {
        int fightAC = fight[1][0];
        int fightHP = fight[0][0];
        int pallyAC = pally[1][0];
	int pallyHP = pally[0][0];
        string displayWeapon;
        string displayStyle;
        string displayFeat;

        int lStyle;
        int lFeat;
        int lWeapon;
        int x;
        int y;
        int z;

        if (fightWeapon == 1)
        {
            displayWeapon = "Greatsword";
            displayStyle = "GWF";
            x = 5;
            lWeapon = 13;
            lStyle = 12;
            y = 15;
            z= 5;
            lFeat = 22;

        
            if (pallyAC < 17)
            {
                displayFeat = "GWM";
            }
            else
            {
                displayFeat = "N/A";
            }
        
        }
        else if (fightWeapon == 2)
        {
            displayWeapon = "Longsword";
            x = 5;
            lWeapon = 14;

            if (fightStyle == 1)
            {
                displayStyle = "Defense";
                displayFeat = "N/A";
                y = 15;
                z = 5;
                lStyle = 8;
                lFeat = 22;
            }
            else if (fightStyle == 2)
            {
                displayStyle = "Dueling";
                displayFeat = "N/A";
                y = 15;
                z = 5;
                lStyle = 8;
                lFeat = 22;
            }
        }
 


        if(fightWeapon == 3 && fightFeat == 1)
        {
            displayWeapon = "Shortsword";
            displayFeat = "Defensive Duelist";
            x = 5;
            y = 20;
            z = 5;
            lWeapon = 13;
            lFeat = 8;
            if (fightStyle == 1)
            {
                displayStyle = "Defense";
                y = 15;
                lStyle = 8;
            }
            else
            {
                displayStyle = "TWF";
                y= 5;
                lStyle = 12;
            }
        
        }
        else if (fightWeapon == 3 && fightFeat == 2)
        {
            displayWeapon = "Rapier";
            displayFeat = "Dual Wielder";
            x = 5; 
            y = 15;
            z = 5;
            lWeapon= 17;
            lFeat = 13;
            if (fightStyle == 1)
            {
                displayStyle = "Defense";
                lStyle = 8;
            }
            else
            {
                displayStyle = "TWF";
                y = 5;
                lStyle = 12;
            }
        }   


        string displayWeaponP;
        string displayStyleP;
        string displayFeatP;
    
        int a;
        int b;
    
        if (pallyWeapon == 1)
        {
            displayWeaponP = "Greatsword";
            displayStyleP = "GWF";
            a = 18;
            b = 25;
        }
        else if (pallyWeapon == 2)
        {
            displayWeaponP = "Longsword";
            a = 19;
            if (pallyStyle == 1)
            {
                displayStyleP = "Defense";
                b = 21;
            }
            else if (pallyStyle == 2)
            {
                displayStyleP = "Dueling";
                b = 21;
            }

        }
       if (fightAC < 17 && pallyWeapon == 1)
        {
            displayFeatP = "GWM";
        }
        else
        {
            displayFeatP = "N/A";
        }
    
        cout << "<============================FIGHTER========================>" << endl;
        cout.width(10); cout << left << "|";
        cout.width(10); cout << internal << "FIGHTER"; 
        cout.width(12); cout << internal << "|";
        cout.width(18); cout << internal << "PALADIN"; 
        cout.width(11); cout << right << "|" << endl;
        cout.width(5); cout << left << "|HP: " << fightHP;   
        cout.width(25); cout << internal << "|";
        cout.width(26); cout << right << "HP: " << pallyHP << "|" << endl;
        cout.width(5); cout << left << "|AC: " << fightAC;
        cout.width(25); cout << internal << "|";
        cout.width(26); cout << right << " AC: " << pallyAC << "|" << endl  ;
        cout.width(y); cout << left << "|Fighting Style: " << displayStyle;
        cout.width(lStyle); cout << internal << "|";
        cout.width(b); cout << right << "Fighting Style: " << displayStyleP << "|" << endl;
        cout.width(z); cout << left << "|Feat: " << displayFeat;   
        cout.width(lFeat); cout << internal << "|";
        cout.width(25); cout << right << "Feat: " << displayFeatP << "|" << endl;
        cout.width(x); cout << left << "|Weapon: " << displayWeapon;
        cout.width(lWeapon); cout << internal << "|";
        cout.width(a); cout << right << "  Weapon: " << displayWeaponP << "|" << endl;
        cout << "<============================PALADIN========================>" << endl;   
    }
    else if (stats == 3)            //pulls barbarian & paladin loadout stats to display
    {
        int barbAC = barb[1][0];
	int barbHP = barb[0][0];
	int pallyAC = pally[1][0];
	int pallyHP = pally[0][0];
        string displayWeapon;
        string displayStyle;
        string displayFeat;
    

        int x;
        int y;
    
        if (pallyWeapon == 1)
        {
            displayWeapon = "Greatsword";
            displayStyle = "GWF";
            x = 18;
            y = 25;
        }
        else if (pallyWeapon == 2 && pallyStyle == 1)
        {
            displayWeapon = "Longsword";
            displayStyle = "Defense";
            x = 19;
            y = 21;
        }
        else if (pallyWeapon == 2 && pallyStyle == 2)
        {
            displayWeapon = "Longsword";
            displayStyle = "Dueling";
            x = 19;
            y = 21;
        }

        if (pallyWeapon == 1)
        {
            displayFeat = "GWM";
        }
        else
        {
            displayFeat = "N/A";
        }
 
        cout << "<===========================BARBARIAN=======================>" << endl;
        cout.width(10); cout << left << "|";
        cout.width(10); cout << internal << "BARBARIAN"; 
        cout.width(12); cout << internal << "|";
        cout.width(18); cout << internal << "PALADIN"; 
        cout.width(11); cout << right << "|" << endl;
        cout.width(5); cout << left << "|HP: " << barbHP;   
        cout.width(25); cout << internal << "|";
        cout.width(26); cout << right << "HP: " << pallyHP << "|" << endl;
        cout.width(5); cout << left << "|AC: " << barbAC;
        cout.width(25); cout << internal << "|";
        cout.width(26); cout << right << " AC: " << pallyAC << "|" << endl  ;
        cout.width(15); cout << left << "|Fighting Style: N/A";
        cout.width(12); cout << internal << "|";
        cout.width(y); cout << right << "Fighting Style: " << displayStyle << "|" << endl;
        cout.width(20); cout << left << "|Feat: GWM";   
        cout.width(12); cout << internal << "|";
        cout.width(25); cout << right << "Feat: " << displayFeat << "|" << endl;
        cout.width(30); cout << left << "|Weapon: Greataxe";
        cout.width(2); cout << internal << "|";
        cout.width(x); cout << right << "  Weapon: " << displayWeapon << "|" << endl;
        cout << "<=============================PALADIN=======================>" << endl;
    }
}

void DnD::BarbaianvFighter(int watch, int flatAttack, int modAttack, int gs1, int gs2, int greatAxe, int secondWind, int& barbarian, int& fighter)
{
    //reassinged variables for ease of typing
    //a few addintional stat calculations
    int gs3 = gs1;
    int gs4 = gs2;

    int gs5 = gs1;
    int gs6 = gs2;
    int barbAC = barb[1][0];
    int barbHP = barb[0][0];	
    int barbAttack;
    int barbDamage;

    int fightAC = fight[1][0];
    int fightHP = fight[0][0];
    int fightAttack = fight[2][0];
    int fightDamage = fight[3][0];
    int actionSurge = fight[4][0];
    secondWind = fight[5][0];
    int secondWindCounter = 1;
    int bonusAction = 1;
    int fightFirst = 1;

    if(fightWeapon == 1)
    {
        if (barbAC > 16)
        {
            fightAttack = modAttack;
        }
        else
        {
            fightAttack = flatAttack;
            fightDamage = fight[3][0] + 13;
        }
    }

    if (fightAC > 16)
    {
        barbAttack = (rand() % 20 + 1) + 5;
	    barbDamage = greatAxe + 2;
    }
    else
    {
        barbAttack = (rand() % 20 + 1);
        barbDamage = greatAxe + 12;
    }

    
    int fightInitiative;
    int barbInitiative = (rand() % 20 + 1) + 2;

    if (fightWeapon == 3)
    {
        fightInitiative = (rand() % 20 + 1) + 3;
    }
    else
    {
        fightInitiative = (rand() % 20 + 1) + 1;
    }


    if ( watch == 1)
    {
        cout << "Fighter initiative roll: " << fightInitiative << endl;
        cout << "Barbarian initiative roll:" << barbInitiative << endl;
    }

    if (barbInitiative > fightInitiative && fightWeapon != 3)                   //if barb withs initiative and fight isnt dex based
    {
        do
        {
            if (fightAC < 17)                                                   //CRIT MOD START
            {                                                                   //BARB CRIT START
                if (barbAttack == 20)                                           //GWM mod
                {
                    barbDamage = (barbDamage * 2) - 15;
                }
                else
                {
                    barbDamage = barbDamage;
                }
            }
            else
            {
                if (barbAttack == 25)                                           //normal mod
                {
                    barbDamage = (barbDamage * 2) - 5;
                }
                else                                                            //no crit
                {
                    barbDamage = barbDamage;
                }
            }                                                                   //BARB crit end

            if (fightWeapon == 1 && barbAC < 17)                                //FIGHT crit start
            {
                if (fightAttack == 20)                                          //GWM mod
                {
                    fightDamage = (fightDamage * 2) - 13;
                }
                else                                                            //no crit
                {
                    fightDamage = fightDamage;
                }
            }
            else
            {
                if (fightAttack == 25)                            
                {
                    if (fightStyle == 2)                                        //dueling style
                    {
                        fightDamage = (fightDamage * 2) - 5;
                    }
                    else                                                        //normal mod
                    {
                        fightDamage = (fightDamage * 2) -3;
                    }
                }
                else                                                            //no crit
                {
                    fightDamage = fightDamage;
                }                                                               //FIGHT crit end
            }                                                                   //crit mod ending

            if ( watch == 1)                                                    
            {
                cout << "Barbarian attack roll: " << barbAttack << endl;
            }
            if (barbAttack >= fightAC)                                          //BARB ATTACK START
            {
                fightHP = fightHP - barbDamage;                                 //barb damage to fighter

                if ( watch == 1)
                {
                    cout << "Barbarian damage roll: " << barbDamage << endl;
                    cout << "Fighter HP: " << fightHP << endl;
                }
            }                                                                   //BARB ATTACK END
            if (fightHP <= 0)                                                   //display if barb wins
            {    
                if (watch == 1)
                {
                    cout << "---------------" << endl;
                    cout << "|Barbarian Wins|" << endl;
                    cout << "---------------" << endl;
                    barbarian++;
                    break;
                }
                else
                {
                    barbarian++;
                    break;
                }
            }
                                                                                //FIGHTER TURN START
            if (fightAC < 17)                                                   //GWM check for second wind use
            {                                                                   //SECONDWIND START
                if (fightHP <= 15 && secondWindCounter != 0)                
                {
                    fightHP = fightHP + secondWind;
                    secondWindCounter = 0;
                    bonusAction--;

                    if (fightHP < 22)
                    {
                        fightHP == 22;
                    }
                    
                    if ( watch == 1)
                    {
                        cout << "Fighter used second wind!" << endl;
                        cout << "Fighter HP: " << fightHP << endl;
                    }
                }
            }

            else if (fightHP <= 12 && secondWindCounter !=0)                    //second wind check for non GWM attack
            {           
                fightHP = fightHP + secondWind;
                secondWindCounter = 0;
                bonusAction--;

                if (fightHP < 22)
                {
                    fightHP == 22;
                }

                if ( watch == 1)
                    {
                        cout << "Fighter used second wind!" << endl;
                        cout << "Fighter HP: " << fightHP << endl;
                    }
            }                                                                   //SECONDWIND END

            if (watch ==1)
            {
                cout << "Fighter attack roll:" << fightAttack << endl;
            }
                                                                                //FIGHTER ATTACK START
            if (fightAttack >= barbAC)                                          //MAIN ATTACK START
            {   
                if (fightWeapon == 1)                                           //greatsword equip check
                {
                    if (gs3 <= 2)                                               //greatsword dice rerolls for 1's & 2's
                    {
                        gs3 = (rand() % 6 + 1);                             
                    }
                    if (gs4 <= 2)
                    {
                       gs4 =(rand() % 6 +1);
                    }
                    if (barbAC < 17)
                    {
                        fightDamage = (gs3 + gs4) + 13;
                    }
                    else
                    {
                        fightDamage = (gs3 + gs4) + 3;
                    }
                    if (watch ==1)
                    {
                        cout << "rerolling 1's and 2's" << endl;                //reroll end
                    }
                    
                            
                }
                barbHP = barbHP - (fightDamage/2);                              //fighter damage to barb
                                                                                //MAIN ATTACK END
                if (watch == 1)
                {
                    cout << "Fighter damage: " << fightDamage << endl;
                    cout << "Barbarian HP: " << barbHP << endl;
                }                                         
            }
                                                                                //BONUS ATTACK START
            if (bonusAction == 1 && fightWeapon == 3)                           //offhand weapon check
            {   
                fightAttack = (rand() % 20 + 1) + 5;
                if (watch == 1)
                {
                    cout << "Fighter bonus attack roll: " << fightAttack << endl;
                }
                
                if (fightAttack >= barbAC)
                {   
                    if (fightWeapon == 3 && fightStyle == 1)                    //fighting style check (defense)
                    {
                        if (fightFeat == 1)
                        {
                            fightDamage == (rand() % 6 + 1);
                        }
                        else
                        {
                            fightDamage == (rand() % 8 + 1);
                        }
                    }
                    else if (fightWeapon == 3 && fightStyle == 2)               //fighting style check (TWF)
                    {
                        if (fightFeat == 1)
                        {                                                                  
                            fightDamage = (rand() % 6 + 1) + 3;
                        }
                        else
                        {
                            fightDamage = (rand() % 8 + 1) + 3;              
                        }
                    }
        
                    bonusAction--;
                    barbHP = barbHP - (fightDamage/2);                          //fighter damage to barb   
                                                                                //BONUS ATTACK END
                    if (watch == 1)
                    {
                        cout << "Fighter damage: " << fightDamage << endl;
                        cout << "Barbarian HP: " << barbHP << endl;
                    }
                }
            } 

            if (actionSurge == 1)                                               //ACTION SURGE START
            {
                actionSurge--;                                                  //action surge counter ( 1 use)
                if (watch == 1)
                {
                    cout << "Fighter used action surge!" << endl;
                }
                                                                                //reroll dice
                gs3 = (rand() % 6 + 1);
                gs4 = (rand() % 6 + 1);
                if (barbAC < 17)                                      
                {
                    fightAttack = (rand() % 20 + 1);
                    fightDamage = (gs3 + gs4) + 13;
                }
                else                                                               
                {
                    fightAttack = (rand() % 20 + 1) + 5;                        //mod attack reroll
            
                    if (fightWeapon == 1)                                       //greatsword damage assigned
                    {
                        fightDamage = (gs3 + gs4) +3;
                    }
                    if (fightWeapon == 2 || fightFeat == 2)                     //longsword & rapier reroll
                    {
                       fightDamage = (rand() % 8 + 1) +3;
                    }
                    else                                                        //shortsword reroll
                    {
                        fightDamage = (rand() % 6 + 1) + 3;
                    }
                }
                if (watch == 1)
                {
                    cout << "Fighter attack roll: " << fightAttack << endl;
                } 

                if (fightAttack >= barbAC)                                      //roll to hit
                {
                    if (fightWeapon == 1)                                       //greatsword equip check
                    {
                        if (gs3 <= 2)                                           //greatsword dice rerolls (1 & 2)
                        {
                            gs3 = (rand() % 6 + 1);                            
                        }
                        if (gs4 <= 2)
                        {
                           gs4 =(rand() % 6 +1);
                        }
                        if (barbAC >= 17)
                        {
                            fightDamage = (gs3 + gs4) + 3;
                        }
                        else
                        {
                            fightDamage = (gs3 + gs4) + 13;
                        }
                        if (watch ==1)
                        {
                            cout << "rerolling 1's and 2's" << endl;            //reroll end
                        }
                    }
                    barbHP = barbHP - (fightDamage/2);                          //fighter damage to barb           
                                                                                //ACTION SURGE END
                    if (watch == 1)
                    {
                        cout << "Fighter damage: " << fightDamage << endl;
                        cout << "Barbarian HP: " << barbHP << endl;
                    }                                         
                }
            }

            if (barbHP <= 0)                                                    //display if fighter wins
            {
                if (watch == 1)
                {
                    cout << "--------------" << endl;
                    cout << "|Fighter Wins|" << endl;
                    cout << "--------------" << endl;
                    fighter++;
                    break;
                }
                else
                {
                    fighter++;
                    break;
                }
            }
            gs3 = (rand() % 6 + 1);                                             //rerolls
            gs4 = (rand() % 6 + 1);

            if (fightAC < 17)                                                   //BARB REROLLS
            {
                barbAttack = (rand() % 20 + 1);
                barbDamage = (rand() % 12 + 1) + 15;
            }
            else if (fightAC > 16)
            {
                barbAttack = (rand() % 20 + 1) + 5;
                barbDamage = (rand() % 12 + 1) + 5;
            }

            bonusAction = 1;                                                    //FIGHTER REROLLS
            if (barbAC < 17 && fightWeapon == 1)                                //GWM attack reroll       
            {
                fightAttack = (rand() % 20 + 1);
                fightDamage = (gs3 + gs4) + 13;
            }
            else                                                                //mod attack roll
            {
                fightAttack = (rand() % 20 + 1) + 5;                            //mod attack reroll
                
                if (fightWeapon == 1)
                {
                    fightDamage = (gs3 + gs4) +3;
                }
                else if (fightWeapon == 2 || fightFeat == 2)                    //longsword & rapier reroll
                {   
                    fightDamage = (rand() % 8 + 1) +3;
                    if (fightWeapon == 2 && fightStyle == 2)
                    {
                        fightDamage = (rand() % 8 + 1) +5;
                    }
                }
                else                                                            //shortsword reroll
                {
                    fightDamage = (rand() % 6 + 1) + 3;
                }
            }

        
        } while (barbHP > 0 || fightHP > 0);
    }
    
    else                                                                        //fighter wins initiative
    {
        do
        {
            if (fightAC < 17)                                                   //BARB CRIT MOD START
            {
                if (barbAttack == 20)
                {
                    barbDamage = (barbDamage * 2) - 15;
                }
                else
                {
                    barbDamage = barbDamage;
                }
            }
            else
            {
                if (barbAttack == 25)
                {
                    barbDamage = (barbDamage * 2) - 5;
                }
                else
                {
                    barbDamage = barbDamage;
                }           
            }                                                                   //BARB CRIT MOD END

            if (fightWeapon == 1 && barbAC < 17)                                //FIGHT CRIT MOD START
            {
                if (fightAttack == 20)
                {
                    fightDamage = (fightDamage * 2) - 13;
                }
                else
                {
                    fightDamage = fightDamage;
                }
            }
            else
            {
                if (fightAttack == 25)
                {
                    if (fightStyle == 2)                                        //dueling style
                    {
                        fightDamage = (fightDamage * 2) - 5;
                    }
                    else
                    {
                        fightDamage = (fightDamage * 2) -3;
                    }
                }
                else
                {
                    fightDamage = fightDamage;
                }           
            }                                                                   //FIGHT CRIT MOD END
                                                                                //SECOND WIND START
            if (fightAC < 17)                                                   //GWM check for second wind
            {
                if (fightHP <= 15 && secondWindCounter != 0)
                {
                    fightHP = fightHP + secondWind;
                    secondWindCounter = 0;
                    bonusAction--;

                    if (fightHP < 22)
                    {
                        fightHP == 22;
                    }
                    
                    if ( watch == 1)
                    {
                        cout << "Fighter used second wind!" << endl;
                        cout << "Fighter HP: " << fightHP << endl;
                    }
                }
            }
            else if (fightHP <= 12 && secondWindCounter !=0)                    //second wind non GWM check 
            {           
                fightHP = fightHP + secondWind;
                secondWindCounter = 0;
                bonusAction--;

                if (fightHP < 22)
                {
                    fightHP == 22;
                }

                if ( watch == 1)
                    {
                        cout << "Fighter used second wind!" << endl;
                        cout << "Fighter HP: " << fightHP << endl;
                    }
            }                                                                   //SECOND WIND END

            if (watch ==1)
            {
                cout << "Fighter attack roll:" << fightAttack << endl;
            }

            if (fightAttack >= barbAC)                                          //FIGHT ATTACK START
            {                                                                   //MAIN ATTACK START
                if (fightWeapon == 1)                                           //greatsword equip check
                {                                                       
                    if (gs3 <= 2)                                               //GWF rerolls
                    {
                        gs3 = (rand() % 6 + 1);                             
                    }
                    if (gs4 <= 2)
                    {
                       gs4 =(rand() % 6 +1);
                    }
                    if (barbAC < 17)
                    {
                        fightDamage = (gs3 + gs4) + 13;
                    }
                    else
                    {
                        fightDamage = (gs3 + gs4) + 3;
                    }
                    if (watch ==1)
                    {
                        cout << "rerolling 1's and 2's" << endl;                //rerolls end
                    }
                    
                            
                }
                if (fightFirst == 1)                                            //rage check
                {
                    barbHP = barbHP - fightDamage;                              //full damage    
                }
                else
                {
                    barbHP = barbHP - (fightDamage/2);                          //half damage
                }                                                               //MAIN ATTACK END
                
                if (watch == 1)
                {
                    cout << "Fighter damage: " << fightDamage << endl;
                    cout << "Barbarian HP: " << barbHP << endl;
                }                                           
            }

            if (bonusAction == 1 && fightWeapon == 3)                           //BONUS ATTACK START
            {                                                                   //offhand weapon check
                fightAttack = (rand() % 20 + 1) + 5;
                if (watch == 1)
                {
                    cout << "Fighter bonus attack roll: " << fightAttack << endl;
                }
                
                if (fightAttack >= barbAC)
                {   
                    if (fightWeapon == 3 && fightStyle == 1)                    //fighting style check (defense)
                    {
                        if (fightFeat == 1)
                        {
                            fightDamage == (rand() % 6 + 1);
                        }
                        else
                        {
                            fightDamage == (rand() % 8 + 1);
                        }
                    }
                    else if (fightWeapon == 3 && fightStyle == 2)               //fighting style check (TWF)
                    {
                        if (fightFeat == 1)
                        {                                                                  
                            fightDamage = (rand() % 6 + 1) + 3;
                        }
                        else
                        {
                            fightDamage = (rand() % 8 + 1) + 3;              
                        }
                    }
        
                    bonusAction--;
                    if(fightFirst ==1)                                          //rage check
                    {
                        barbHP = barbHP - fightDamage;                          //full damage
                    }                                                   
                    else
                    {
                        barbHP = barbHP - (fightDamage/2);                      //half damage
                    }                                                           //BONUS ATTACK END
                    if (watch == 1)
                    {
                        cout << "Fighter damage: " << fightDamage << endl;
                        cout << "Barbarian HP: " << barbHP << endl;
                    }
                }
            }

            if (actionSurge == 1)                                               //ACTION SURGE START
            {                                                           
                actionSurge--;                                                  //action surge counter ( 1 use)
                if (watch == 1)
                {
                    cout << "Fighter used action surge!" << endl;
                }
                
                gs3 = (rand() % 6 + 1);                                         //rerolls
                gs4 = (rand() % 6 + 1);
                if (barbAC < 17)                                        
                {
                    fightAttack = (rand() % 20 + 1);
                    fightDamage = (gs3 + gs4) + 13;
                }
                else                                                            //mod attack roll
                {
                    fightAttack = (rand() % 20 + 1) + 5;                        //mod attack reroll
            
                    if (fightWeapon == 1)
                    {
                        fightDamage = (gs3 + gs4) +3;
                    }
                    if (fightWeapon == 2 || fightFeat == 2)                     //longsword & reroll
                    {
                       fightDamage = (rand() % 8 + 1) +3;
                    }
                    else                                                        //shortsword reroll
                    {
                        fightDamage = (rand() % 6 + 1) + 3;
                    }                                                   
                }
                if (watch == 1)
                {
                    cout << "Fighter attack roll: " << fightAttack << endl;
                } 
                if (fightAttack >= barbAC)                                      //roll to hit
                {
                    if (fightWeapon == 1)                                       //greatsword equip check
                    {
                        if (gs3 <= 2)                                           //GWF rerolls
                        {
                            gs3 = (rand() % 6 + 1);                       
                        }
                        if (gs4 <= 2)
                        {
                           gs4 =(rand() % 6 +1);
                        }
                        if (barbAC >= 17)
                        {
                            fightDamage = (gs3 + gs4) + 3;
                        }
                        else
                        {
                            fightDamage = (gs3 + gs4) + 13;
                        }
                        if (watch ==1)
                        {
                            cout << "rerolling 1's and 2's" << endl;            //reroll end
                        }
                    }
                    if (fightFirst == 1)                                        //rage check
                    {
                        barbHP = barbHP - fightDamage;                          //full damage
                    }
                    else
                    {
                        barbHP = barbHP - (fightDamage/2);                      //half damage
                    }
                    if (watch == 1)
                    {                                                           //ACTION SURGE END
                        cout << "Fighter damage: " << fightDamage << endl;
                        cout << "Barbarian HP: " << barbHP << endl;
                    }                                                           //FIGHT TURN END
                }
            }

            if (barbHP <= 0)                                                    //display if fighter win
            {
                if (watch == 1)
                {
                    cout << "--------------" << endl;
                    cout << "|Fighter Wins|" << endl;
                    cout << "--------------" << endl;
                    fighter++;
                    break;
                }
                else
                {
                    fighter++;
                    break;
                }
            }

            if ( watch == 1)
            {
                cout << "Barbarian attack roll: " << barbAttack << endl;
            }                                                           
                                                                                //BARB ATTACK START
            fightFirst = 0;
            if (barbAttack >= fightAC)                                          //roll to hit 
            {
                fightHP = fightHP - barbDamage;                                 //barb damage to fight
                
                if ( watch == 1)
                {
                    cout << "Barbarian damage roll: " << barbDamage << endl;
                    cout << "Fighter HP: " << fightHP << endl;
                }                                                               //BARB ATTACK END
            }
            
            if (watch == 1)                                                     //display if barb win
            {    
                if (fightHP <= 0)
                {
                    cout << "---------------" << endl;
                    cout << "|Barbarian Wins|" << endl;
                    cout << "---------------" << endl;
                    barbarian++;
                    break;
                }
            }

            gs3 = (rand() % 6 + 1);                                             //dice rerolls
            gs4 = (rand() % 6 + 1);

            if (fightAC < 17)                                                   //BARB REROLLS
            {
                barbAttack = (rand() % 20 + 1);
                barbDamage = (rand() % 12 + 1) + 15;
            }
            else if (fightAC > 16)
            {
                barbAttack = (rand() % 20 + 1) + 5;
                barbDamage = (rand() % 12 + 1) + 5;
            }

             bonusAction = 1;                                                   //FIGHTER REROLLS
            if (barbAC < 17 && fightWeapon == 1)                                //gwm attack roll
            {
                fightAttack = (rand() % 20 + 1);
                fightDamage = (gs3 + gs4) + 13;
            }
            else                                                                //mod attack roll
            {
                fightAttack = (rand() % 20 + 1) + 5;                            //mod attack reroll
                
                if (fightWeapon == 1)
                {
                    fightDamage = (gs3 + gs4) +3;
                }
                else if (fightWeapon == 2 || fightFeat == 2)                    //longsword & rapier reroll
                {   
                    fightDamage = (rand() % 8 + 1) +3;
                    if (fightWeapon == 2 && fightStyle == 2)
                    {
                        fightDamage = (rand() % 8 + 1) +5;
                    }
                }
                else                                                            //shortsword reroll
                {
                    fightDamage = (rand() % 6 + 1) + 3;
                }
            }


        } while (barbHP > 0 || fightHP > 0);
    } 
}

void DnD::FightervPaladin(int watch, int flatAttack, int modAttack, int gs1, int gs2, int secondWind, int& fighter, int& paladin)
{   
    //reassinged variables for ease of typing
    //a few additional stat calculations
    int fightAttack;
    int fightDamage;
    int gs3 = gs1;
    int gs4 = gs2;

    gs1 = (rand() % 6 + 1);
    gs2 = (rand() % 6 + 1);
    int gs5 = gs1;
    int gs6 = gs2;
    int fightAC = fight[1][0];
    int fightHP = fight[0][0];
    fightAttack = fight[2][0];
    fightDamage = fight[3][0];
    int actionSurge = fight[4][0];
    secondWind = fight[5][0];
    int secondWindCounter = 1;
    int bonusAction = 1;
        
    int pallyAC = pally[1][0];
    int pallyHP = pally[0][0];
    int pallyAttack = pally[2][0];
    int pallyDamage = pally[3][0];
    int smite = pally[4][0];
    int smiteCounter = 2;
    int Loh = pally[5][0];
    int LohCounter = 2;
    int action = 1;

    if(fightWeapon == 1)
    {
        if (pallyAC > 16)
        {
            fightAttack = modAttack;
            fight[2][0] = modAttack;
        }
        else
        {
            fightAttack = flatAttack;
            fightDamage = fight[3][0] + 13;
        }
    }
    
    if (pallyWeapon == 1)
    {
        if (fightAC > 16)
        {
            pallyAttack = modAttack;
            pallyAttack = modAttack;
        }
        else
        {
            pallyAttack = flatAttack;
        }
    }

  int fightInitiative;

    if (fightWeapon == 3)   
    {
        fightInitiative = (rand() % 20 + 1) + 3;
    }
    else
    {
        fightInitiative = (rand() % 20 + 1) + 1;
    }
  
    int pallyInitiative = (rand() % 20 +1) + 1;                                 

    if (fightWeapon != 3)                                                       //reroll initiative on tie (if not dex fight)
    {
        while (fightInitiative == pallyInitiative)
        {
            fightInitiative = (rand() % 20 + 1) + 1;
            pallyInitiative = (rand() % 20 +1) + 1;
        }
    }
    
   
    if ( watch == 1)
    {
        cout << "Fighter initiative roll: " << fightInitiative << endl;
        cout << "Paladin initiative roll:" << pallyInitiative << endl;
    }

    if (fightInitiative >= pallyInitiative)                                     //if fight wins initiative       
    {
        do
        {
                                                                                //CRIT MOD START
            if (fightWeapon == 1 && pallyAC < 17)                               //FIGHT CRIT START
            {
                if (fightAttack == 20)
                {
                    fightDamage = (fightDamage * 2) - 13;
                }
                else
                {
                    fightDamage = fightDamage;
                }
            }
            else
            {
                if (fightAttack == 25)
                {
                    if (fightStyle == 2)                                        //dueling style
                    {
                        fightDamage = (fightDamage * 2) - 5;
                    }
                    else
                    {
                        fightDamage = (fightDamage * 2) -3;
                    }
                }
                else
                {
                    fightDamage = fightDamage;
                }
            }                                                                   //FIGHT CRIT END

                                                                                //PALLY CRIT START
            if (pallyWeapon == 1 && fightAC < 17)                  
            {
                if (pallyAttack ==20)
                {
                    pallyDamage = (pallyDamage  * 2) - 13;
                    smite = smite * 2;
                }
                else
                {
                    pallyDamage = pallyDamage;
                    smite = smite;
                }
            }
            else
            {
                if (pallyAttack == 25)
                {
                    if (pallyStyle == 2)                                        //dueling style
                    {
                        pallyDamage = (pallyDamage * 2) - 5;    
                    }
                    else
                    {
                        pallyDamage = (pallyDamage * 2) - 3;                    //denfensive style crit
                    }    
                    smite = smite * 2;
                }
                else
                {
                    pallyDamage = pallyDamage;                                  //non crit
                    smite = smite;                                              //PALLY CRIT END
                }                                                               //CRIT MOD END
            }                                                                   //FIGHT TURN START
                                                                                //SECOND WIND START
            if (pallyWeapon == 1 && fightAC < 17)                               //GWM check for second wind
            {
                if (fightHP <= 15 && secondWindCounter != 0)
                {
                    fightHP = fightHP + secondWind;
                    secondWindCounter = 0;
                    bonusAction--;

                    if (fightHP < 22)
                    {
                        fightHP == 22;
                    }
                    
                    if ( watch == 1)
                    {
                        cout << "Fighter used second wind!" << endl;
                        cout << "Fighter HP: " << fightHP << endl;
                    }
                }
            }
            else if (fightHP <= 12 && secondWindCounter !=0)                    //non GWM second wind check
            {           
                fightHP = fightHP + secondWind;
                secondWindCounter = 0;
                bonusAction--;

                if (fightHP < 22)
                {
                    fightHP == 22;
                }

                if ( watch == 1)
                    {
                        cout << "Fighter used second wind!" << endl;
                        cout << "Fighter HP: " << fightHP << endl;
                    }
            }                                                                   //SECOND WIND END

            if (watch ==1)
            {
                cout << "Fighter attack roll:" << fightAttack << endl;          
            }                                                                   //MAIN ATTACK START
            if (fightAttack >= pallyAC)                                        
            {   
                if (fightWeapon == 1)                                           //greatsword equip check
                {
                    if (gs3 <= 2)                                               //GWF rerolls
                    {
                        gs3 = (rand() % 6 + 1);                         
                    }
                    if (gs4 <= 2)
                    {
                       gs4 =(rand() % 6 +1);
                    }
                    if (pallyAC < 17)
                    {
                        fightDamage = (gs3 + gs4) + 13;
                    }
                    else
                    {
                        fightDamage = (gs3 + gs4) + 3;
                    }
                    if (watch ==1)
                    {
                        cout << "rerolling 1's and 2's" << endl;                //rerolls end
                    }
                    
                            
                }
                pallyHP = pallyHP - fightDamage;                                //pally loses hp
                                                                                //MAIN ATTACK END
                if (watch == 1)
                {
                    cout << "Fighter damage: " << fightDamage << endl;
                    cout << "Paladin HP: " << pallyHP << endl;
                }                                         
            }
                                                                                //BONUS ATTACK START
            if (bonusAction == 1 && fightWeapon == 3)                           //offhand weapon check
            {   
                fightAttack = (rand() % 20 + 1) + 5;
                if (watch == 1)
                {
                    cout << "Fighter bonus attack roll: " << fightAttack << endl;
                }
                
                if (fightAttack >= pallyAC)
                {   
                    if (fightWeapon == 3 && fightStyle == 1)                    //fighting style check (defense)
                    {
                        if (fightFeat == 1)
                        {
                            fightDamage == (rand() % 6 + 1);
                        }
                        else
                        {
                            fightDamage == (rand() % 8 + 1);
                        }
                    }
                    else if (fightWeapon == 3 && fightStyle == 2)               //fighting style check (TWF)
                    {
                        if (fightFeat == 1)
                        {                                                                  
                            fightDamage = (rand() % 6 + 1) + 3;
                        }
                        else
                        {
                            fightDamage = (rand() % 8 + 1) + 3;              
                        }
                    }
        
                    bonusAction--;
                    pallyHP = pallyHP - fightDamage;                            //pally loses hp
                                                                                //BONUS ATTACK END
                    if (watch == 1)                                         
                    {
                        cout << "Fighter damage: " << fightDamage << endl;
                        cout << "Paladin HP: " << pallyHP << endl;
                    }
                }
            } 

            

            if (actionSurge == 1)                                               //ACTION SURGE START
            {
                actionSurge--;                                                  //action surge counter
                if (watch == 1)
                {
                    cout << "Fighter used action surge!" << endl;
                }
                
                gs3 = (rand() % 6 + 1);                                         //reroll dice
                gs4 = (rand() % 6 + 1);
                if (pallyAC < 17)                                      
                {
                    fightAttack = (rand() % 20 + 1);
                    fightDamage = (gs3 + gs4) + 13;
                }
                else                                                            //mod attack roll
                {
                    fightAttack = (rand() % 20 + 1) + 5;                        //mod attack reroll
            
                    if (fightWeapon == 1)
                    {
                        fightDamage = (gs3 + gs4) +3;
                    }
                    if (fightWeapon == 2 || fightFeat == 2)                     //longsword reroll
                    {
                       fightDamage = (rand() % 8 + 1) +3;
                    }
                    else                                                        //shortsword reroll
                    {
                        fightDamage = (rand() % 6 + 1) + 3;
                    }
                }
                if (watch == 1)
                {
                    cout << "Fighter attack roll: " << fightAttack << endl;
                } 
                if (fightAttack >= pallyAC)                                     //if fighter hits
                {
                    if (fightWeapon == 1)                                       //greatsword equip check
                    {
                        if (gs3 <= 2)                                           //GWF rerolls
                        {
                            gs3 = (rand() % 6 + 1);                             
                        }
                        if (gs4 <= 2)
                        {
                           gs4 =(rand() % 6 +1);
                        }
                        if (pallyAC >= 17)
                        {
                            fightDamage = (gs3 + gs4) + 3;
                        }
                        else
                        {
                            fightDamage = (gs3 + gs4) + 13;
                        }
                        if (watch ==1)
                        {
                            cout << "rerolling 1's and 2's" << endl;
                        }
                    }
                    pallyHP = pallyHP - fightDamage;                            //pally loses hp
                                                                                //ACTION SURGE END
                    if (watch == 1)
                    {
                        cout << "Fighter damage: " << fightDamage << endl;
                        cout << "Paladin HP: " << pallyHP << endl;
                    }                                                           //FIGHT TURN END
                }
            }
            
            if (pallyHP <= 0)                                                   //display if fight win
            {
                if (watch == 1)
                {
                    cout << "--------------" << endl;
                    cout << "|Fighter Wins|" << endl;
                    cout << "--------------" << endl;
                    fighter++;
                    break;
                }
                else
                {
                    fighter++;
                    break;
                }
            }

                                                                                //PALLY TURN START
            if (fightWeapon == 1 && pallyAC < 17)                               //LOH START
            {                                                                   //GWM check for lay on hands
                if (pallyHP <= 15 && Loh !=0)   
                {
                        pallyHP = pallyHP + Loh;
                        Loh = 0;
                        action = 0;
                        LohCounter = 0;
                        if (LohCounter <= 0)
                        {
                            Loh = 0;
                        }

                        if (watch == 1)
                        {
                            cout << "The Paladin used lay on hands!" << endl;
                            cout << "Paladin HP: " << pallyHP << endl;
                        }
                }
            }
            
            else  if (pallyHP <= 12 && Loh != 0)                                //non GWM check
            {
                pallyHP = pallyHP + 5;
                Loh = 5;
                action = 0;
                LohCounter--;
                if (LohCounter <= 0)
                {
                    Loh = 0;
                }

                if (watch == 1)
                {
                    cout << "The Paladin used lay on hands!" << endl;
                    cout << "Paladin HP: " << pallyHP << endl;
                }                                                               //LOH END
           }
                                                                                //PALLY ATTACK START
            if (action == 1)                                                    //action counter for loh
            {
                if (watch == 1)
                {
                    cout << "Paladin attack roll: " << pallyAttack << endl;
                }

                if (pallyAttack >= fightAC)                                     //roll to hit
                {
                    if (pallyWeapon == 1)                                       //GS equip check
                    {
                        if (pallyAC < 17)                                       //GWM check                                    
                        {                                                       //GWF rerolls
                            if (gs5 <= 2)   
                            {
                                gs5 = (rand() % 6 + 1);                            
                            }
                            if (gs6 <= 2)
                            {
                                gs6 = (rand() % 6 + 1);                         //reroll end
                            }    
                            pallyDamage = (gs5 + gs6) + 13;                     //new damage
                            
                            if ( watch == 1)
                            {
                                cout << "Rerolling 1's and 2's" << endl;
                            }
                            
                        }
                        else                                                    
                        {
                            if (gs5 <= 2)                                       //GWF reroll
                            {
                                gs5 = (rand() % 6 + 1);                             
                            }
                            if (gs6 <= 2)
                            {
                                gs6 = (rand() % 6 + 1);
                            }                                                   //reroll end
                            pallyDamage = (gs5 + gs6) +3;                       //new damage
                                
                            if ( watch == 1)
                            {
                                cout << "Rerolling 1's and 2's" << endl;
                            }
                        }
                        
                    }
                    if (smiteCounter >=1)                                       //smite counter
                    {
                        fightHP = fightHP - (pallyDamage + smite);              //fighter loses hp (smite damage)
                    }
                    else
                    {
                        fightHP = fightHP - pallyDamage;                        //fighter loses hp no smite
                    }                                                           //PALLY ATTACK END

                    if (watch == 1)
                    {
                        if (smiteCounter >= 1)
                        {
                             cout << "Paladin damage: " << pallyDamage << " Smite damage: " << smite << endl;
                        }
                        else
                        {
                            cout << "Paladin damage: " << pallyDamage << endl;
                        }
                        cout << "Fighter HP: " << fightHP << endl;
                    }
                    smiteCounter--;                     

                }
            }                                                                   //PALLY TURN END

            if (fightHP <= 0)                                                   //display if pally win
            {
                if (watch == 1)
                {
                    cout << "--------------" << endl;
                    cout << "|Paladin Wins|" << endl;
                    cout << "--------------" << endl;
                    paladin++;
                    break;   
                }
                else
                {
                    paladin++;
                    break;
                }
            }

            gs3 = (rand() % 6 + 1);                                             //rerolls
            gs4 = (rand() % 6 + 1);
            gs5 = (rand() % 6 + 1);
            gs6 = (rand() % 6 + 1);

            bonusAction = 1;                                                    //FIGHTER REROLLS
            if (pallyAC < 17 && fightWeapon == 1)                               //gwm attack roll
            {
                fightAttack = (rand() % 20 + 1);
                fightDamage = (gs3 + gs4) + 13;
            }
            else                                                                //mod attack roll
            {
                fightAttack = (rand() % 20 + 1) + 5;                            //mod attack reroll
                
                if (fightWeapon == 1)
                {
                    fightDamage = (gs3 + gs4) +3;
                }
                else if (fightWeapon == 2 || fightFeat == 2)                    //longsword & rapier reroll
                {   
                    fightDamage = (rand() % 8 + 1) +3;
                    if (fightWeapon == 2 && fightStyle == 2)
                    {
                        fightDamage = (rand() % 8 + 1) +5;
                    }
                }
                else                                                            //shortsword reroll
                {
                    fightDamage = (rand() % 6 + 1) + 3;
                }
            }

            action = 1;                                                         //PALLY REROLLS
            smite = (rand() % 8 + 1) + (rand() % 8 +1);
            if (fightAC < 17 && pallyWeapon == 1)                               //gwm attack roll
            {
                pallyAttack = (rand() % 20 + 1);
                pallyDamage = (gs5 + gs6) + 13;
            }
            else
            {
                pallyAttack = (rand() % 20 + 1) + 5;                            //mod attack reroll
                
                if (pallyWeapon == 1)
                {
                    pallyDamage = (gs3 + gs4) +3;
                }
                if (pallyWeapon == 2)                                           //longsword reroll
                {
                    pallyDamage = (rand() % 8 + 1) +3;
                    if (pallyStyle == 2)
                    {
                        pallyDamage = (rand() % 8 + 1) + 5;
                    }
                }
            }

        } while (fightHP > 0 || pallyHP > 0);
    }
    else if (pallyInitiative > fightInitiative)
    {
        do
        {
            if (pallyAC < 17)                                                   //FIGHT CRIT MOD START
            {
                if (fightAttack == 20)
                {
                    fightDamage = (fightDamage * 2) - 13;
                }
                else
                {
                    fightDamage = fightDamage;
                }
            }
            else
            {
                if (fightAttack == 25)
                {
                    if (fightStyle == 2)                                        //dueling style
                    {
                        fightDamage = (fightDamage * 2) - 5;
                    }
                    else
                    {
                        fightDamage = (fightDamage * 2) -3;
                    }
                }
                else
                {
                    fightDamage = fightDamage;
                }
            }                                                                   //FIGHT CRIT MOD END

                                                                                //PALLY CRIT MOD START
            if (fightAC < 17)                  
            {
                if (pallyAttack == 20)
                {
                    pallyDamage = (pallyDamage  * 2) - 13;
                    smite = smite * 2;
                }
                else
                {
                    pallyDamage = pallyDamage;
                    smite = smite;
                }
            }
            else
            {
                if (pallyAttack == 25)
                {
                    if (pallyStyle == 2)                                        //dueling style
                    {
                        pallyDamage = (pallyDamage * 2) - 5;    
                    }
                    else
                    {
                        pallyDamage = (pallyDamage * 2) - 3;
                    }    
                    smite = smite * 2;
                }
                else
                {
                    pallyDamage = pallyDamage;
                    smite = smite;
                }                                                               //PALLY CRIT MOD END
            }
                                                                                //PALLY TURN START
                                                                                //LOH START
            if (pallyAC > 16)                                                   //GWM check for loh
            {
                if (pallyHP <= 11 && Loh !=0)   
                {
                        pallyHP = pallyHP + 5;
                        Loh = 5;
                        action = 0;
                        LohCounter--;
                        if (LohCounter <= 0)
                        {
                            Loh = 0;
                        }

                        if (watch == 1)
                        {
                            cout << "The Paladin used lay on hands!" << endl;
                            cout << "Paladin HP: " << pallyHP << endl;
                        }
                }
            }
            else  if (pallyHP <= 15 && Loh != 0)                                //non GWM check
            {
                pallyHP = pallyHP + Loh;
                Loh = 0;
                action = 0;
                LohCounter = 0;

                if (watch == 1)
                {
                    cout << "The Paladin used lay on hands!" << endl;
                    cout << "Paladin HP: " << pallyHP << endl;
                }
           }                                                                    //LOH END
          
            if (watch == 1)
            {
                cout << "Paladin attack roll: " << pallyAttack << endl;
            }                                                                   //PALLY ATTACK START
            if (action == 1)                                                    //action counter for loh
            {
                if (pallyAttack >= fightAC)                                     //roll to hit
                {
                    if (pallyWeapon == 1)
                    {
                        if (fightAC < 17 && pallyWeapon == 1)                   //GWM check
                        {
                            if (gs5 <= 2)                                       //GWF rerolls
                            {
                                gs5 = (rand() % 6 + 1);                             
                            }
                            if (gs6 <= 2)
                            {
                                gs6 = (rand() % 6 + 1);
                            }                                                   //reroll end
                            pallyDamage = (gs5 + gs6) + 13;                     //new damage
                            
                            if ( watch == 1)
                            {
                               cout << "Rerolling 1's and 2's" << endl;
                            }                    
                        }
                        else                                                    
                        {
                            if (gs5 <= 2)                                       //GWF reroll
                            {
                                gs5 = (rand() % 6 + 1);                             
                            }
                            if (gs6 <= 2)
                            {
                                gs6 = (rand() % 6 + 1);
                            }                                                   //reroll end
                            pallyDamage = (gs5 + gs6) +3;                       //new damage
                                
                            if ( watch == 1)
                            {
                                cout << "Rerolling 1's and 2's" << endl;
                            }
                            
                        }
                    }
                    if (smiteCounter >=1)                                       //smite counter
                    {
                        fightHP = fightHP - (pallyDamage + smite);              //fighter loses hp (smite damage)
                    }
                    else
                    {
                        fightHP = fightHP - pallyDamage;                        //fighter loses hp no smite
                    }                                                           //PALLY ATTACK END

                    if (watch == 1)
                    {
                        if (smiteCounter >= 1)
                        {
                             cout << "Paladin damage: " << pallyDamage << " Smite damage: " << smite << endl;;  
                        }
                        else
                        {
                            cout << "Paladin damage: " << pallyDamage << endl;
                        }
                        cout << "Fighter HP: " << fightHP << endl;
                    }
                    smiteCounter--;                                             //PALLY TURN END
                }    
            }
            if (fightHP <= 0)                                                  //display if pally win
            {
                if (watch == 1)
                {
                    cout << "--------------" << endl;
                    cout << "|Paladin Wins|" << endl;
                    cout << "--------------" << endl;
                    paladin++;
                    break;   
                }
                else
                {
                    paladin++;
                    break;
                }
            }
                                                                                //FIGHT TURN START
                                                                                //SECOND WIND START
            if (fightAC < 17)                                                   //GWM check for second wind
            {
                if (fightHP <= 15 && secondWindCounter != 0)
                {
                    fightHP = fightHP + secondWind;
                    secondWindCounter = 0;
                    bonusAction--;

                    if (fightHP < 22)
                    {
                        fightHP == 22;
                    }
                    
                    if ( watch == 1)
                    {
                        cout << "Fighter used second wind!" << endl;
                        cout << "Fighter HP: " << fightHP << endl;
                    }
                }
            }
            else if (fightHP <= 12 && secondWindCounter !=0)                    //non GWM check
            {           
                fightHP = fightHP + secondWind;
                secondWindCounter = 0;
                bonusAction--;

                if (fightHP < 22)
                {
                    fightHP == 22;
                }

                if ( watch == 1)
                    {
                        cout << "Fighter used second wind!" << endl;
                        cout << "Fighter HP: " << fightHP << endl;
                    }
            }                                                                   //SECOND WIND END

            if (watch ==1)
            {
                cout << "Fighter attack roll:" << fightAttack << endl;          
            }                                                                   //MAIN ATTACK START
            if (fightAttack >= pallyAC)                                         //roll to hit
            {
                if (fightWeapon == 1)                                           //GS equip check
                {
                    if (gs3 <= 2)                                               //GWF rerolls
                    {
                        gs3 = (rand() % 6 + 1);                         
                    }
                    if (gs4 <= 2)
                    {
                       gs4 =(rand() % 6 +1);
                    }
                    if (pallyAC >= 17)
                    {
                        fightDamage = (gs3 + gs4) + 3;
                    }
                    else
                    {
                        fightDamage = (gs3 + gs4) + 13;
                    }
                    if (watch ==1)
                    {
                        cout << "rerolling 1's and 2's" << endl;                //rerolls end
                    }      
                }
                pallyHP = pallyHP - fightDamage;                                //pally loses hp
                                                                                //MAIN ATTACK END
                if (watch == 1)
                {
                    cout << "Fighter damage: " << fightDamage << endl;
                    cout << "Paladin HP: " << pallyHP << endl;
                }                                         
            }
                                                                                //BONUS ATTACK START
            if (bonusAction == 1 && fightWeapon == 3)                           //offhand weapon check
            {
                fightAttack = (rand() % 20 + 1) + 5;   
                if (watch == 1)
                {
                    cout << "Fighter bonus attack roll: " << fightAttack << endl;
                }
               
                if (fightAttack >= pallyAC)
                {    
                    if (fightWeapon == 3 && fightStyle == 1)                    //fighting style check (defense)
                    {
                        if (fightFeat == 1)
                        {
                            fightDamage == (rand() % 6 + 1);
                        }
                        else
                        {
                            fightDamage == (rand() % 8 + 1);
                        }
                    }
                    else if (fightWeapon == 3 && fightStyle == 2)               //fighting style check (TWF)
                    {
                        if (fightFeat == 1)
                        {                                                                  
                            fightDamage = (rand() % 6 + 1) + 3;
                        }
                        else
                        {
                            fightDamage = (rand() % 8 + 1) + 3;             
                        }
                    }
                    
                    bonusAction--;
                    pallyHP = pallyHP - fightDamage;                            //pally loses hp
                    if (watch == 1)                                             //BONUS ATTACK END
                    {
                        cout << "Fighter damage: " << fightDamage << endl;
                        cout << "Paladin HP: " << pallyHP << endl;
                    }
                }
            } 

            

            if (actionSurge == 1)                                               //ACTION SURGE START
            {
                actionSurge--;                                                  //action surge counter
                if (watch == 1)
                {
                    cout << "Fighter used action surge!" << endl;
                }
                gs3 = (rand() % 6 + 1);                                         //reroll dice
                gs4 = (rand() % 6 + 1);
                if (pallyAC < 17)                                               //gwm attack roll
                {
                    fightAttack = (rand() % 20 + 1);
                    fightDamage = (gs3 + gs4) + 13;
                }
                else                                                             //mod attack roll
                {
                    fightAttack = (rand() % 20 + 1) + 5;                         //mod attack reroll
                
                    if (fightWeapon == 1)
                    {
                        fightDamage = (gs3 + gs4) +3;
                    }
                    if (fightWeapon == 2 || fightFeat == 2)                     //longsword reroll
                    {
                        fightDamage = (rand() % 8 + 1) +3;
                        if (fightWeapon == 2 && fightStyle == 2)
                        {
                            fightDamage = (rand() % 8 + 1) + 5;
                        }
                    }
                    else                                                        //shortsword reroll
                    {
                        fightDamage = (rand() % 6 + 1) + 3;
                    }
                }
                if (watch == 1)
                {
                    cout << "Fighter attack roll: " << fightAttack << endl;
                }
                if (fightAttack >= pallyAC)                                     //roll to hit
                {
                    if (fightWeapon == 1)                                       //greatsword equip check
                    {
                        if (gs3 <= 2)                                           //GWF rerolls
                        {
                            gs3 = (rand() % 6 + 1);                         
                        }
                        if (gs4 <= 2)
                        {
                           gs4 =(rand() % 6 +1);
                        }
                        if (pallyAC >= 17)
                        {
                            fightDamage = (gs3 + gs4) + 3;
                        }
                        else
                        {
                            fightDamage = (gs3 + gs4) + 13;
                        }
                        if (watch ==1)
                        {
                            cout << "rerolling 1's and 2's" << endl;            //reroll end
                        }    
                    }
                    pallyHP = pallyHP - fightDamage;                            //pally loses hp
                                                                                //ACTION SURGE END
                    if (watch == 1)
                    {
                        cout << "Fighter damage: " << fightDamage << endl;
                        cout << "Paladin HP: " << pallyHP << endl;
                    }                                         
                }                                                               
            }
            
            if (pallyHP <= 0)                                                   //display if fight win
            {
                if (watch == 1)
                {
                    cout << "--------------" << endl;
                    cout << "|Fighter Wins|" << endl;
                    cout << "--------------" << endl;
                    fighter++;
                    break;
                }
                else
                {
                   fighter++;
                   break;
                }
            }
            

            gs3 = (rand() % 6 + 1);
            gs4 = (rand() % 6 + 1);
            gs5 = (rand() % 6 + 1);
            gs6 = (rand() % 6 + 1);

            bonusAction = 1;                                                    //FIGHTER REROLLS
            if (pallyAC < 17 && fightWeapon == 1)                               //gwm attack roll
            {
                fightAttack = (rand() % 20 + 1);
                fightDamage = (gs3 + gs4) + 13;
            }
            else                                                               //mod attack roll
            {
                fightAttack = (rand() % 20 + 1) + 5;                           //mod attack reroll
                
                if (fightWeapon == 1)
                {
                    fightDamage = (gs3 + gs4) +3;
                }
                else if (fightWeapon == 2 || fightFeat == 2)                    //longsword reroll
                {
                    fightDamage = (rand() % 8 + 1) +3;
                    if (fightWeapon == 2 && fightStyle == 2)
                    {
                        fightDamage = (rand() % 8 + 1) + 5;
                    }
                }
                else                                                            //shortsword reroll
                {
                    fightDamage = (rand() % 6 + 1) + 3;
                }
            }

            action = 1;                                                         //PALLY REROLLS
            smite = (rand() % 8 + 1) + (rand() % 8 +1);
            if (fightAC < 17 && pallyWeapon == 1)                               //gwm attack roll
            {
                pallyAttack = (rand() % 20 + 1);
                pallyDamage = (gs5 + gs6) + 13;
            }
            else
            {
                pallyAttack = (rand() % 20 + 1) + 5;                            //mod attack reroll
                
                if (pallyWeapon == 1)
                {
                    pallyDamage = (gs3 + gs4) +3;
                }
                if (pallyWeapon == 2)                                           //longsword reroll
                {
                    pallyDamage = (rand() % 8 + 1) +3;
                    if (pallyStyle == 2)
                    {
                        pallyDamage = (rand() % 8 + 1) + 5;
                    }
                }
            }
           
        } while (fightHP > 0 || pallyHP > 0);
    }
}
           

void DnD::BarbarianvPaladin(int watch, int flatAttack, int modAttack, int gs1, int gs2, int greatAxe, int greatSword, int longSword, int& barbarian, int& paladin)
{
    //reassinged variable for ease of typing
    //a few additional stat calculatons
    int gs5 = gs1;
    int gs6 = gs2;
    int barbAC = barb[1][0];
    int barbHP = barb[0][0];	
    int barbAttack;
    int barbDamage;

    int pallyAC = pally[1][0];
    int pallyHP = pally[0][0];
    int pallyAttack = pally[2][0];
    int pallyDamage = pally[3][0];
    int smite = pally[4][0];
    int smiteCounter = 2;
    int Loh = pally[5][0];
    int LohCounter = 2;
    int action = 1;
    int pallyFirst = 1;

    if (pallyAC > 16)
    {
        barbAttack = (rand() % 20 + 1) + 5;
	    barbDamage = greatAxe + 2;
    }
    else
    {
        barbAttack = (rand() % 20 + 1);
        barbDamage = greatAxe + 12;
    }

    int barbInitiative = (rand() % 20 + 1) + 2;
    int pallyInitiative = (rand() % 20 +1) + 1;

    

    if ( watch == 1)
    {
        cout << "Barbarian initiative roll: " << barbInitiative << endl;
        cout << "Paladin initiative roll:" << pallyInitiative << endl;
    }
   
    if (barbInitiative >= pallyInitiative)                                      //barbarian wins initiative
    {
        do
        {
            
            if (pallyAC < 17)                                                   //BARB CRIT MOD START
            {
                if (barbAttack == 20)
                {
                    barbDamage = (barbDamage * 2) - 15;
                }
                else
                {
                    barbDamage = barbDamage;
                }
            }
            else
            {
                if (barbAttack == 25)
                {
                    barbDamage = (barbDamage * 2) - 5;
                }
                else
                {
                    barbDamage = barbDamage;
                }
            }                                                                   //BARB CRIT MOD END
            
                                                                                //PALLY CRIT MOD START
            if (barbAC < 17 && pallyWeapon == 1)                  
            {
                if (pallyAttack ==20)
                {
                    pallyDamage = (pallyDamage  * 2) - 13;
                    smite = smite * 2;
                }
                else
                {
                    pallyDamage = pallyDamage;
                    smite = smite;
                }
            }
            else
            {
                if (pallyAttack == 25)
                {
                    if (pallyStyle == 2)                                        //dueling style
                    {
                        pallyDamage = (pallyDamage * 2) - 5;  
                    }
                    else
                    {
                        pallyDamage = (pallyDamage * 2) - 3;
                    }    
                    smite = smite * 2;
                }
                else
                {
                    pallyDamage = pallyDamage;
                    smite = smite;
                }                                                               //PALLY CRT MOD END
            }

            if ( watch == 1)
            {
                cout << "Barbarian attack roll: " << barbAttack << endl;
            }                                                                   //BARB ATTACK START
            if (barbAttack >= pallyAC)                                          //roll to hit
            {
                pallyHP = pallyHP - barbDamage;                                 //pally loses HP
                
                if ( watch == 1)
                {
                    cout << "Barbarian damage roll: " << barbDamage << endl;
                    cout << "Paladin HP: " << pallyHP << endl;
                }
            }                                                                   //BARB ATTACK ENDS

            
            if (pallyHP <= 0)                                                   //display if barb wins
            {    
                if (watch == 1)
                {
                    cout << "---------------" << endl;
                    cout << "|Barbarian Wins|" << endl;
                    cout << "---------------" << endl;
                    barbarian++;
                    break;
                }
                else
                {
                    barbarian++;
                    break;
                }
            }                                                                   //PALLY TURN START
                                                                                //LOH START
            if (pallyAC > 16)                                                   //GWM check for loh
            {
                
                if (pallyHP <= 11 && Loh != 0)
                {
                    action --;
                    pallyHP = pallyHP + 5;
                    Loh = 5;
                    LohCounter--;
                    if (LohCounter <= 0)
                    {
                        Loh = 0;
                    }
                    if ( watch == 1)
                    {
                        cout << "The Paladin used lay on hands!" << endl;
                        cout << "Paladin HP: " << pallyHP << endl;
                        
                    }
                }
            }
            
            else if (pallyHP <=15 && Loh != 0)                                  //non GWM check 
            {
                action--;
                pallyHP = pallyHP + Loh;
                Loh = 0;
                LohCounter = 0;
                if ( watch == 1)
                {
                    cout << "The Paladin used lay on hands!" << endl;
                    cout << "Paladin HP: " << pallyHP << endl;
                }  
            }                                                                   //LOH END

            if (action == 1)
            {
                 if ( watch == 1)
                {
                    cout << "Paladin attack roll: " << pallyAttack << endl;
                }
                                                                                //PALLY ATTACK START
                if (pallyAttack >= barbAC)                                      // roll to hit
                {
                    if (pallyWeapon == 1)                                       //greatsword check
                    {
                        if (gs5 <= 2)                                           //GWF rerolls
                        {
                            gs5 = (rand() % 6 + 1);
                        }
                        if (gs6 <= 2)
                        {
                            gs6 = (rand() % 6 + 1);
                        }                                                        //reroll end
                        pallyDamage = (gs5 + gs6) + 13;                          //new damage     
                        if ( watch == 1)
                        {
                            cout << "Rerolling 1's and 2's:" << endl;
                        }
                        
                    }
                    if (smiteCounter >= 1)                                     //checks smite uses
                    {
                        barbHP = barbHP - ((pallyDamage/2) + smite);           //barb loses HP smite used                   
                    }
                    else
                    {
                        barbHP = barbHP - (pallyDamage/2);                     //barb loses HP no smite
                    }                                                          //PALLY ATTACK END

                    if ( watch == 1)
                    {   
                        if (smiteCounter >= 1)
                        {
                            cout << "Paladin weapon damage: " << pallyDamage << " Smite damage: " << smite <<  endl;    
                        }
                        else if (smiteCounter <= 0)
                        {
                            cout << "Paladin weapon damage: " << pallyDamage << endl;
                        }
                        cout << "Barbarian HP: " << barbHP << endl; 
                    }
                    smiteCounter --;                                            //PALLY TURN END
                }
            }
            if (barbHP <= 0)                                                    //display if pally wins
            {    
                if (watch == 1)
                {
                    cout << "--------------" << endl;
                    cout << "|Paladin Wins|" << endl;
                    cout << "--------------" << endl;
                    paladin++;
                    break;
                }
                else
                {
                    paladin++;
                    break;
                }
            }

            gs5 = (rand() % 6 + 1);
            gs6 = (rand() % 6 + 1);

                                                                                //REROLLS
            if (pallyAC < 17)                                                   //BARB REROLLS
            {
                barbAttack = (rand() % 20 + 1);
                barbDamage = (rand() % 12 + 1) + 15;
            }
            else if (pallyAC > 16)
            {
                barbAttack = (rand() % 20 + 1) + 5;
                barbDamage = (rand() % 12 + 1) + 5;
            }
            
                                                                                //PALADIN REROLLS
            action = 1;
            smite = (rand() % 8 + 1) + (rand() % 8 + 1);
            if (barbAC < 17 && pallyWeapon == 1)
            {
                pallyAttack = (rand() % 20 + 1);
                pallyDamage = (gs5 + gs6) + 13;
            }
            else
            {
                pallyAttack = (rand() % 20 + 1) + 5;
                 
                if (pallyWeapon == 2)
                {
                    if (pallyStyle == 1)
                    {
                        pallyDamage = (rand() % 8 + 1) +3;
                    }
                    else
                    {
                        pallyDamage = (rand() % 8 + 1) +5;
                    }
                }
            }   
            
        } while (barbHP > 0 || pallyHP > 0);
    }

                                                                                //paladin wins the initiative
    else
    {
        do
        {
            if (pallyAC < 17)                                                   //BARB CRIT MOD START 
            {
                if (barbAttack == 20)
                {
                    barbDamage = (barbDamage * 2) - 15;
                }
                else
                {
                    barbDamage = barbDamage;
                }
            }
            else
            {
                if (barbAttack == 25)
                {
                    barbDamage = (barbDamage * 2) - 5;
                }
                else
                {
                    barbDamage = barbDamage;
                }
            }                                                                   //BARB CRIT MOD END
            
                                                                                //PALLY CRIT MOD START
            if (barbAC < 17 && pallyWeapon == 1)                  
            {
                if (pallyAttack ==20)
                {
                    pallyDamage = (pallyDamage  * 2) -13;
                    smite = smite * 2;
                }
                else
                {
                    pallyDamage = pallyDamage;
                    smite = smite;
                }
            }
            else
            {
                if (pallyAttack == 25)
                {
                    if (pallyStyle == 2)
                    {
                        pallyDamage = (pallyDamage * 2) - 5;
                    }
                    else
                    {
                        pallyDamage = (pallyDamage * 2) - 3;
                    
                    }
                    smite = smite * 2;
                }
                else
                {
                    pallyDamage = pallyDamage;
                    smite = smite;
                }
            }                                                                   //PALLY CRIT MOD END

            if (pallyAC > 16)
            {
                
                if (pallyHP <= 11 && Loh != 0)
                {
                    action --;
                    pallyHP = pallyHP + 5;
                    Loh = 5;
                    LohCounter--;
                    if (LohCounter <= 0)
                    {
                        Loh = 0;
                    }

                    if ( watch == 1)
                    {
                        cout << "The Paladin used lay on hands!" << endl;
                        cout << "Paladin HP: " << pallyHP << endl;
                        
                    }
                }
            }
            
            else if (pallyHP <=15 && Loh != 0) 
            {
                action--;
                pallyHP = pallyHP + Loh;
                Loh = 0;
                LohCounter = 0;

                if ( watch == 1)
                {
                    cout << "The Paladin used lay on hands!" << endl;
                    cout << "Paladin HP: " << pallyHP << endl;
                }  
            }                                                                   //LOH END
                                                                                //PALLY ATTACK START

            if (action == 1)                                                    //action counter for loh
            {
                if ( watch == 1)
                {
                cout << "Paladin attack roll: " << pallyAttack << endl;
                }
                if (pallyAttack >= barbAC)                                      //roll to hit
                {
                    if (pallyWeapon == 1)                                       //GS check
                    {
                        if (gs5 <= 2)                                           //GWF rerolls
                        {
                            gs5 = (rand() % 6 + 1);
                        }
                        if (gs6 <= 2)
                        {
                            gs6 = (rand() % 6 + 1);                             //reroll end
                        }
                        pallyDamage = (gs5 + gs6) + 13;                         //new damage 
                        if ( watch == 1)
                        {
                            cout << "Rerolling 1's and 2's:" << endl;
                        }
                            
                    }
                    if (smiteCounter >= 1)                                      //checks smite uses
                    {
                                                                                       
                        if (pallyFirst == 1)                                    //rage check
                        {
                            barbHP = barbHP - ((pallyDamage) + smite);          //full damage
                        }
                        else
                        {
                            barbHP = barbHP - ((pallyDamage/2) + smite);        //half damage
                        }
                    }
                    else
                    {    
                        if (pallyFirst == 1)                                    //no smite
                        {
                            barbHP = barbHP - (pallyDamage);                    //full damage
                        }
                        else
                        {
                            barbHP = barbHP - (pallyDamage/2);                  //half damage
                        }                                                       //PALLY ATTACK ENDS
                    } 
                    if ( watch == 1)
                    {   
                        if (smiteCounter >= 1)
                        {
                            cout << "Paladin weapon damage: " << pallyDamage << " Smite damage: " << smite <<  endl;    
                        }
                        else if (smiteCounter <= 0)
                        {
                            cout << "Paladin weapon damage: " << pallyDamage << endl;
                        }
                        cout << "Barbarian HP: " << barbHP << endl; 
                    }
                    smiteCounter --;                                            //PALLY TURN ENDS
                }
            }
            
            
            if (watch == 1)                                                     //display if pally wins
            {    
                if (barbHP <= 0)
                {
                    cout << "--------------" << endl;
                    cout << "|Paladin Wins|" << endl;
                    cout << "--------------" << endl;
                    paladin++;
                    break;
                }
            }

            if (watch == 1)                                                     //BARB ATTACK START
            {
                cout << "Barbarian attack roll: " << barbAttack << endl;
            }
            pallyFirst = 0;
            if (barbAttack >= pallyAC)                                          //roll to hit
            {
                pallyHP = pallyHP - barbDamage;                                 //pally loses HP
                
                if ( watch == 1)
                {
                    cout << "Barbarian damage roll: " << barbDamage << endl;
                    cout << "Paladin HP: " << pallyHP << endl;
                }
            }                                                                   //BARB ATTACK END

            
            if (pallyHP <= 0)                                                   //display if barb wins
            {    
                if (watch == 1)
                {
                    cout << "---------------" << endl;
                    cout << "|Barbarian Wins|" << endl;
                    cout << "---------------" << endl;
                    barbarian++;
                    break;
                }
                else
                {
                    barbarian++;
                    break;
                }
            }
            

            gs5 = (rand() % 6 + 1);                                             //REROLLS
            gs6 = (rand() % 6 + 1);


            if (pallyAC > 16)                                                   //BARB REROLLS
            {
                barbAttack = (rand() % 20 + 1) + 5;
                barbDamage = (rand() % 12 + 1) + 5;
            }
            else if (pallyAC < 17)
            {
                barbAttack = (rand() % 20 + 1);
                barbDamage = (rand() % 12 + 1) + 15;
            }

            
            action = 1;                                                         //PALLY REROLLS
            smite = (rand() % 8 + 1) + (rand() % 8 + 1);
            if (barbAC < 17 && pallyWeapon == 1)
            {
                pallyAttack = (rand() % 20 + 1);
                pallyDamage = (gs5 + gs6) + 13;
            }
            else
            {
                pallyAttack = (rand() % 20 + 1) + 5;
                        
                if (pallyWeapon == 2)
                {
                    if (pallyStyle == 1)
                    {
                        pallyDamage = (rand() % 8 + 1) +3;
                    }
                    else
                    {
                        pallyDamage = (rand() % 8 + 1) +5;
                    }
                }
            }
        } while (barbHP > 0 || pallyHP > 0);
    }
}
