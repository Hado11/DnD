#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class DnD
{
	public:
	
	void fight(int, int, int, int, int, int&, int&);
}dnd;

int main()
{
	srand(time(0));
	int randomb = (rand() % 20 +1); 				//barbarian roll to hit
	int randomf = (rand() % 20 +1); 				//fighter roll to hit
	int secondWind = (rand() % 10 + 1) + 2; 			//fighter second wind roll
	int bHit = (rand() % 12 +1) +5; 				//barbarian damage roll
	int fHit = (rand() % 6 + 1) + (rand() % 6 +1) +3; 		//fighter damage roll

	int barbarian = 0; 						//barbarian wins counter
	int fighter = 0; 						//fighter wins counter

	for( int i = 0; i <1000000; i ++) // loop to run the simulation as many times a specified 	
	{
		dnd.fight(bHit, randomb, fHit, randomf, secondWind, barbarian, fighter);
	}

	//prints total wins
	cout <<"<=====Total Wins=====>" << endl;
	cout << "Barbarian: " << barbarian << endl;
	cout << "Fighter: " << fighter << endl;
	cout <<"<=====Total Wins=====>" << endl;
	return 0;	
		
}

void DnD::fight(int bHit, int randomb, int fHit, int randomf, int secondWind, int& barbarian, int& fighter)
{
	int barb[5][1]; 						//declaring barbarian array
	barb[1][0] = 25; 						//hp
	barb[2][0] = bHit; 						//attack
	barb[3][0] = 15; 						//ac
	barb[4][0] = randomb; 					//d20 roll + mod
	
	int fight[5][1]; 						//declaring fighter array
	fight[1][0] = 22;						//hp
	fight[2][0] = fHit; 					//attack
	fight[3][0] = 16; 						//ac
	fight[4][0] = randomf; 					//d20 roll + mod


	int initiativeb = (rand() % 20 +1) + 2; 			//barbarian initiative roll
	int initiativef = (rand() % 20 +1) + 1; 			//fighter initiative roll

//	cout << "Barbarian Intiative roll: " << initiativeb << endl;
//	cout << "Fighter Initiative roll: " << initiativef << endl;

	int i = 1;											//secondWind counter
	int a = 1;											//actionsurge counter

	int fFirst =1;//fighter first(used if fighter wins initiative. attacks barb before raging)

	if (initiativeb >= initiativef) 					//if barb wins initiative
	{
		do
		{
			//if statements for crits to double damage. if not a crit, normal damage
			if (randomb != 20)
			{
				barb[2][0] = randomb;
			}
			if (randomb == 20)
			{
				barb[2][0] = (barb[2][0] *2) - 15;
			}
			if (randomf != 20)
			{
				fight[2][0] = randomf;
			}
			if (randomf == 20)
			{
				fight[2][0] = (fight[2][0] *2) - 13;
			}

//			cout << "Barbarian attack roll: " << randomb << endl;

			if(randomb >= fight[3][0]) 					//if the barb hits the fighter
			{
				fight[1][0] = fight[1][0] - barb[2][0]; //fighter hp = current hp - barb attack
//				cout <<"Fighter HP: " << fight[1][0] << endl;
				if (i == 1) // counter so secondWind cant be used more than once
				{
					fight[1][0] = fight[1][0] + secondWind; //fighter hp = current + second wind
//					cout << "Second wind used, Fighter HP: " << fight[1][0] << endl;
					i--;
				}	 
			}
			if (fight[1][0] <=0) 						//fighter hp <= 0
			{
//				cout << "Barbarian Wins" << endl;
				barbarian++;
				break;
			}
			
//			cout << "Fighter attack roll: " << randomf << endl;

			if (randomf >= barb[3][0]) 				//if the figher hits the barb
			{
				barb[1][0] = barb[1][0] - (fight[2][0]/2); //barb loses health
//				cout << "Barbarian HP: " << barb[1][0] << endl;
			}
			if(a==1)								//action surge
			{
				a--; 								//action surge used
//				cout << " Action surge used" << endl;
				randomf = (rand() % 20 +1); 		//fighter attack roll
//				cout << "Fighter attack roll: " << randomf << endl;
				if (randomf >= barb[3][0])
				{
					barb[1][0] = barb[1][0] - (fight[2][0]/2); //barb loses health
//					cout << "Barbarian HP: " << barb[1][0] << endl;
					
				}
			}
				
		
			if (barb[1][0] <= 0) 						//barb hp <= 0
			{
//				cout << "Fighter Wins" << endl;
				fighter++;
				break;
			}
			
			randomb = (rand() % 20 +1); 				//reroll attack dice
			randomf = (rand() % 20 +1); 				//reroll attack dice
		} while((barb[1][0] >=1) || (fight[1][0] >=1));
	}

	else if (initiativef > initiativeb)
	{
		do
		{
			if (randomb != 20)
			{
				barb[2][0] = randomb;
			}
			if (randomb == 20)
			{
				barb[2][0] = (barb[2][0] *2) - 15;
			}
			if (randomf != 20)
			{
				fight[2][0] = randomf;
			}
			if (randomf == 20)
			{
				fight[2][0] = (fight[2][0] *2) - 13;
			}
			
			if (fFirst ==1) //used if fighter wins. barb takes full damage
			{
				fFirst++;
//				cout << "Fighter attack roll: " << randomf << endl;
				if(randomf >= barb[3][0]) 				{
					barb[1][0] = barb[1][0] - (fight[2][0]); 
//					cout << "Barbarian HP: " << barb[1][0] << endl;
				}
				if (a == 1) 
				{
					a--;
//					cout << " Action surge used" << endl;
					randomf = (rand() % 20 +1);
//					cout << "Fighter attack roll: " << randomf << endl;
					if (randomf >= barb[3][0])
					{
						barb[1][0] = barb[1][0] - (fight[2][0]); 
//						cout << "Barbarian HP: " << barb[1][0] << endl;
						
					}
				}	 
			}
			
			else
			{
//				cout << "Fighter attack roll: " << randomf << endl;
				if(randomf >= barb[3][0]) 
				{
					barb[1][0] = barb[1][0] - (fight[2][0]/2); 
//					cout << "Barbarian HP: " << barb[1][0] << endl;
				}
				if (a == 1) 
				{
					a--;
//					cout << " Action surge used" << endl;
					randomf = (rand() % 20 +1);
//					cout << "Fighter attack roll: " << randomf << endl;
					if (randomf >= barb[3][0])
					{
						barb[1][0] = barb[1][0] - (fight[2][0]/2); 
//						cout << "Barbarian HP: " << barb[1][0] << endl;
					}
				}	 
			
			}
			if (barb[1][0] <=0)
			{
//				cout << "Fighter Wins" << endl;
				fighter++;
				break;
			}

//			cout << "Barbarian attack roll: " << randomb << endl;
			if (randomb >= fight[3][0]) 
			{
				fight[1][0] = fight[1][0] - (barb[2][0]); 
//				cout << "Fighter HP: " << fight[1][0] << endl;
				if(i == 1)
				{
					fight[1][0] = fight[1][0] + secondWind; 
//					cout << "Second Wind used, Fighter HP: " << fight[1][0] << endl;
					i--;
				}
			}
			
	
		
			if (fight[1][0] <= 0)
			{
//				cout << "Barbarian Wins" << endl;
				barbarian++;
				break;
			}
			
			randomb = (rand() % 20 +1);
			randomf = (rand() % 20 +1);
		}while((barb[1][0] >=1) || (fight[1][0] >=1));
			
	}

} 
