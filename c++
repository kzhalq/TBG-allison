#include<Windows.h>
#include<iostream>
using namespace std;

//global variables
int health = 100;
string inventory[10] = { "sword", "shield", "potion", " ", " ", " "," "," ", " "};//creates an inventory of 10 items
int gold = 200;

//functions
void shop();
void AnimalNpc();
void BattleSystem();



int main() {//starting point of program

	int room = 1;
	char input = 'a';
	
	cout << "Seem's like you're cat has ran inside of the abandoned castle. You call out their name... " << endl;
	cout << "............It seems like you have no choice but to look inside, Good luck!" << endl;
	cout << "   _        " << endl;
	cout << "   \ `*-.       " << endl;
	cout << "    )  _ `-.     " << endl;
	cout << "   .  : `.  .     " << endl;
	cout << "   : _   '   \    " << endl;
	cout << "   ; *` _.    `*-._   " << endl;
	cout << "   `-.-'           `-.     " << endl;
	cout << "     ;         `       `.     " << endl;
	cout << "     :.         .        \  " << endl;
	cout << "     . \  .     :   .-'   .  " << endl;
	cout << "     '  `+.;    ;  '      :   " << endl;
	cout << "     :  '  |      ;       ;-.  " << endl;
	cout << "     ; '   :  :` -:     _.`* ;   " << endl;
	cout << " .*'  /  .*'  ;  .*`- +'  `*' " << endl;
	cout << "  `*-*   `*-*    `*-*'        " << endl;

	
	while (health > 0) {//game loop
		//print the inventory every turn:
		cout << "This is your inventory" << endl;
		for (int i = 0; i < 5; i++)//puts space in the inventory
			inventory[1] = " ";
		cout << endl;
		
		switch (room) {
		case 1:
			cout << "you are at the entrance, you can go (E)ast to head into the entrance for the hall" << endl;
			cin >> input;
			if (input == 'E')
				room = 2;
			
			break;
		case 2:
			cout << "you are in the hall, you can go (W)est to return to the entrance or (S)outh to countinue trough the hall" << endl;
			cin >> input;
			if (input == 'W')
				room = 1;
			if (input == 'S')
				room = 3;

			break;
		case 3:
			system("color F2");
			cout << "you are in the kitchen, you can go (N)orth to retun to the hall or (E)ast to countinue" << endl;
			cin >> input;
			if (input == 'N')
				room = 2;
			if (input == 'E')
				room = 4;

			break;
		case 4:
			cout << "you are in dining room, you can go (W)est to retun to the kitchen or (E)ast to countinue" << endl;
			cin >> input;
			if (input == 'W')
				room = 3;
			if (input == 'E')
				room = 5;

			break;
		case 5:
			AnimalNpc();//calls function
			cout << "you are on the stairs that lead to the dungeon you can go (N)orth or (W)est to go back to the dining room" << endl;
			cin >> input;
			if (input == 'N')
				room = 6;
			if (input == 'W')
				room = 4;

			break;
		case 6:
			cout << "Go (E)ast to reach the dungeon or (S)outh to go back uptairs" << endl;
			cin >> input;
			if (input == 'E')
				room = 7;
			if (input == 'S')
				room = 5;

			break;
		case 7:
			cout << "You reached the dungeon (W)est to enter a mysterious room or (E)ast to go back up" << endl;
			cin >> input;
			if (input == 'W')
				room = 6;
			if (input == 'E')
				room = 8;

			break;
		case 8:
			cout << "You enter the room (W)estv to go back or (S)outh to countinue" << endl;
			cout << " There's a (s)hop in the courner." << endl;
			cin >> input;
			if (input == 'W')
				room = 7;
			if (input == 'S')
				room = 9;
			if (input == 's')
				shop();//calls function

			break;
		case 9:
			BattleSystem();//calls function
			cout << "You are almost at the exit (N)orth to return or (E)ast to go trough the last door" << endl;
			cin >> input;
			if (input == 'N')
				room = 8;
			if (input == 'E') {
				if (inventory[5] == "key") {
					room = 10;
					cout << "The key unlocks the door" << endl;
					inventory[5] = " ";
				}
				else {
					cout << "The door requires a key to open. Try the shop" << endl;
				}
			}
			break;
		case 10:
			cout << "You are at the exit, you should use the (2)sock to attract you'r cat" << endl;
			cin >> input;
			if (input == '2') {
				if (inventory[4] == "sock") {
					cout << " You exit the abonded castle with you'r cat, you decide to go back home after an exhausting adventure" << endl;
					inventory[4] = " ";
				}
				else {
					cout << " you need the stinky souck from the shop" << endl;
					room = 8;
				}
			}
			break;
		}//end switch
	}//end of game loop
}//end of main

//function definition
void BattleSystem() {
	cout << "Battle commencing!" << endl;
	int MonsterHealth = 50;
	char input;

	while (health >= 0 && MonsterHealth > 0) {
		
		if (inventory[1] == "shield") {
			cout << "you partially block with your shield, the monster bites you for 5hp" << endl;
			health -= 5;
		}
		else {
			cout << "the mosnter bites you for 10 hp" << endl;
			health -= 10;
			Beep(800, 200);
		}
		
		if (inventory[0] == "sword") {
			cout << "you hit the monster with you sword for 30hp" << endl;
			MonsterHealth -= 30;
		}
		else {
			cout << "you punch the monster for 3 damage" << endl;
			MonsterHealth -= 3;
		}

		cout << "Your Health:" << health << ".Monster Health" << MonsterHealth << endl;
		system("pause");

		if (health > 0 && MonsterHealth > 0)
			cout << "you can (f)ight, (r)un, or use (p)otion" << endl;
		cin >> input;
		if (input == 'r') {
			int num = rand() % 100;
			if (num < 40) {
				cout << "you can escape the battle!" << endl;
				break;
			}
			else
				cout << "chance to run failed :(" << endl;
		}
		if (input == 'p') {
			if (inventory[2] == "potion") {
				cout << "glug glug" << endl;
				health += 35;
				inventory[2] = " ";
			}
			else
				cout << "sorry,you don't have any more potions." << endl;

		}
		if (input == 'f') cout << "the battle countinues..." << endl;
	}
}
//function definition
void shop() {
	int input = 'a';
	while (input != 0)
	{
		cout << "-----------------------------------------------" << endl;
		cout << "welcome to the shop!" << endl;
		cout << "iteams for sale:" << endl;
		cout << "1) cupcake: $5" << endl;
		cout << "2) dirty sock: $10" << endl;
		cout << "3) key: $50" << endl;


		cout << "your inventory:" << endl;
		for (int i = 0; i < 10; i++)
			cout << inventory[i] << " ";
		cout << endl << endl;

		cout << "what would you like to purchase?" << endl;
		cin >> input;


		if (input == 1) {
			if (gold >= 5) {
				cout << "you bought the cupcake!" << endl;
				inventory[3] = "cupcake";//this puts cupcake in the third slot
				gold -= 5;
			}
			else
				cout << "you don't have enough gold!" << endl;
		}


		if (input == 2) {
			if (gold >= 5) {
				cout << "you bought the dirty sock!" << endl;
				inventory[4] = "sock!";//this puts a sock in the fourth slot
				gold -= 10;
			}
			else
				cout << "you don't have enough gold!" << endl;
		}


		if (input == 3) {
			if (gold >= 50) {
				cout << "you bought the key!" << endl;
				inventory[5] = "key";//this puts a key in the fifth slot
				gold -= 50;
			}
			else
				cout << "You dont have enough!" << endl;
		}

		else if (input == 0)
			cout << "Thanks for buying! Goodbye!" << endl;
		else {
			cout << "That's not an option, dummy" << endl;
		}
	}
}

//function definition
void AnimalNpc() {
	int num = rand() % 100;
	if (num < 20)
		cout << "The cat meows" << endl;
	else if (num < 40)
		cout << "The cat purs" << endl;
	else
		cout << "The cat runs away!" << endl;
}
