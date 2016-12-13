#include<iostream>
#include<string>
#include<random>
#include<ctime>

using namespace std;

int getHumans();
int getSkeletons();
void printResults(int humans, int skeletons ,int starthumans ,int startSkeletons);
void simulateBattle(int &humans, int &skeletons );


int main()
{
	// Number of Both
	int humans;
	int starthumans;
	int skeletons;
	int startSkeletons;
	

	///////////////////////////////////////////////////
	cout<< "*** Skeletons vs Humans *** \n"<<endl;
	
	humans = getHumans();
	skeletons = getSkeletons();
	cout<<endl;

	starthumans = humans;
	startSkeletons = skeletons;
	cout<< "+++++++++++++++++++\n"<<endl;
	cout<< "Beginning Combat! \n"<<endl;
	cout<< "<Combat Noises> \n" <<endl;

	cout<<"********************\n"<<endl;
	

	simulateBattle(humans , skeletons);
	
	printResults(humans , skeletons , starthumans , startSkeletons);
	
	system("PAUSE");
	return 0;


}

int getHumans()
{   // get humans from the user
	int humans;
	cout<< "Input the number of humans: " ;
	cin >> humans;
	return humans;
}

int getSkeletons()
{   // get skeletons from the user 
	int skeletons;
	cout<< "Input the number of skeletons: ";
	cin>> skeletons;
	return skeletons;
}

void printResults(int humans , int skeletons, int starthumans , int startSkeletons)
{
	cout<< "Combat ended! \n" <<endl;
	if (humans > 0 )
	{
		cout << "\nHumans Won! \n"; 
		cout << "\nThere are " << humans << " Humans left!";
	} else
	{
		cout<< "\nSkeletons Won! \n"; 
		cout << "\nThere are " << skeletons << " Skeletons left!";
	}
	//Kill Counter
	cout<<"\n"<< starthumans - humans << " humans and " << startSkeletons - skeletons << " skeletons lost their lives. \n"<<endl;
}

void simulateBattle(int &humans, int &skeletons )
{
	// Human Properties
	float humanAttack= 0.6f;
	float humanHealth = 250.0f;
	float humanDamage = 200.0f;
	float currentHumanHealth = humanHealth;
	// Sketon Properties
	float skeletonAttack = 0.4f;
	float skeletonHealth = 50.0f;
	float skeletonDamage = 40.0f;
	float currentSkeltonHealth= skeletonHealth;

	// First Turn parameter setter
	char turn = 'S';

	// Generate Random Number for attack
	static default_random_engine randomeGenerator(time(NULL));
	uniform_real_distribution<float> attack(0.0f,1.0f);
    float attackResult;
	
	
	while ( (humans > 0)  && (skeletons > 0))
	{
				 
		attackResult = attack(randomeGenerator);
		
		if (turn == 'S')
		{
			// Get our attack result
		
			// Check if our attack was successful
			if (attackResult <= skeletonAttack)
			{
				currentHumanHealth -= skeletonDamage;
				if (currentHumanHealth < 0)
				{
					humans--;
					currentHumanHealth = humanHealth;
				}
			}
			turn = 'H';
		}else
		{
			if (attackResult <= humanAttack)
			{
				currentSkeltonHealth -= humanDamage;
				if (currentSkeltonHealth < 0)
				{
					skeletons-- ;
					currentSkeltonHealth = skeletonHealth;
				}
			}
			turn = 'S';
		}
	}
}


