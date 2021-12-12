#pragma once
#include <iostream>
#include <conio.h>
#include <cstring>
#include <time.h>
#include <fstream>
#include <string>
#include <limits>


using namespace std;

//////////////////////////////////////////////////////////////////////STUFF TO ADD
/*

MAKE LEVELLING SYSTEM
MAKE ENTITY SPAWNER AND HORDE MECHANICS
MAKE NPCS
melee combat add it eventually but bro I need a break from combat lol
make z levels
redo skills, maybe get rid of the combat related ones
all skills out of 100 I think
get some dismemberment
make enemies not idiots
make function for trains

*/
///////////////////////////////////////////////////////////////////////STUFF ADDED
/*



*/



/////////////////////////////////////////////////////////////////////FUNCTION DECS
int init();
int initEnemy(
	string name1, 
	int strength1, 
	int dexterity1, 
	int intelligence1, 
	int mainHand1, 
	int wpn1, 
	int x1, 
	int y1, 
	int num1
);//this will create enemies
int initFirearm(
	int reliability1, //out of 1000
	int accurracy1, //out of 100 
	string fName1, //full name of weapon
	int damage1, //hp taken off with a hit
	int reloadTime1, //turns reloading takes
	string nName1, //nickname
	int range1, //how many tiles away it can shoot
	int owned1, //0 is not owned, 1 is owned
	string ammoType1, //"9mm", stuff like that
	int ammo1 = 0, //exact number of mag if it has one
	int shootTime1 = 1 //how many turns to set up gun, 1 means instant
	); //makes guns
int initMag(
	int magSize1, 
	string ammoType1, 
	int owned1 = 0, 
	int amount1 = 1, 
	int bulletsLeft1 = 0
); //makes mags speedily
int initBullet(
	int amount1, 
	string ammoType1, 
	int owned1 = 0
);


int display(); //displays the world
int header(); //this will show everything you need during combat

int inv(); //inventory
int filterInv(string itype1);//inventory with a filter
int invChose(); //this will take what you chose and go through the options

int invHeader(); //displays item stats
int update(); //for inv, updates names

void moveC(int i);
int dsplyE();


int fire(); //shoots closest enemy
int endist(); //calcs enemy distances
int vis(); //combat visuals

/*int combat(int type); //combat screen
//sub-functions
int attack(); //player's attack
int enemyAttack(); //enemy's attack
int useWeapon(); //different options like reload, eject round
int combatMove(); //move closer or farther from combatant
int search(); //this will check with all objects on the ground near mc
//later make this also find items near the mc loc on main map
*/

int check(string skill, int score, int bdypt); //runs check with skill and required score to pass

int menu(); //opens menu, has options and stuff
//sub-menus
void setDisplaySize();
void teleport();
void createCharacter();
void viewCharacter();
void saveGame();
void loadGame();

int sel(string top, int chnum, string exitable, string ch1 = "", string ch2 = "", string ch3 = "", string ch4 = "", string ch5 = "", string ch6 = "", string ch7 = "", string ch8 = "", string ch9 = "", string ch10 = "");
//makes a menu you can select different things in, just leave the strings your not gonna use empty
//last char YES means you can exit from menu

int sym(int i, int o); //prints ascii
int tx(string i); //prints text centered
int txt(string i, int o); //prints centered text with more options
int r(int lower, int upper); //prints a number in a range

int loc(int q, int w); //checks where you are globally
int col(const char* i); //checks collision for mc
int coli(const char* i, int num1); //checks collision for other entities
int tp(int i, int o); // teleports player same spot regardless of display size


int bd(int type, int coordx, int coordy); //builds a pixel of material with collision
int bld(int coord1, int coord2, int coord3, int coord4, int type, string face = "up"); //loads pixels into global coordinate system
int dsplybd(); //displays static pixels


int kp(const char* key); //checks keypress 

int save();
int load();
int itemLogger(); //logs all loaded items into a txt file
fstream& gotoLine(fstream& file, unsigned int num);

///////////////////////////////////////////////////////////////////////GLOBAL VARS




/// WORLD
int xh;
int yh; //where you spawn, changed in init

int x;
int y; //location of whole screen(these drift when changing resolution, not sure if it's a big deal or not)
int xg;
int yg; //global coords, each tile is a different coord

int counter = 0; //this will be used to assign array values for xe and ye


const int xborder = 300;
const int yborder = 300; //size of map
int c[xborder + 1][yborder + 1]; //global collision map
int b[xborder + 1][yborder + 1]; //global building map
int i[xborder + 1][yborder + 1]; //global item map



int xloc;
int yloc; // local cords for current x y position

int xmax;
int ymax; //display size, must be even numbers
int xmaxo;
int ymaxo; //stores previous size to correct drift in setDisplaySize();
int drange; //range for enemies and things to update


/// GLOBAL LAYERS
int debug = 0; //sets collision debugging among other things
int details = 0; //shows extra stats for player


int ans; //stores player input

//COMBAT
int goToCombat = 0; //signals start of combat one turn prior
int combatRange; //0: CLOSE, 1: MED, 2: FAR
int enemyNum; //takes type from combat
int gunNum; //currently equipped weapon
int inCombat = 0; //simply tells if your in combat or not
int yourTurn; //shows whos turn it is
int dismembermentChance = 3; //max num for r() when calculating if bodypart is injured
int gndItm[10]; //this will hold random items on the ground during a fight
int firing = 0; //when 1, bullet tracer appears
//int av = 0; //determines which enemy is getting his shit kicked in
int invats = 0; //if in vats, you are selecting a specific target
int selen = 0; //which enemy is selected in vats
int reloadNum = 0; //how many turns of reload left

int ennum = 0; //this is the enemy being shot
int hit = 0; //this will be to confirm your gun hit something
int here[6] = { 0,0 }; //where messages will be displayed
int ejected = 0; //just ejected a round
int reloaded = 0; //just reloaded
int killed = 0; //just killed

int inCover[] = { 0,0 }; //[0] is mc, [1] is enemy
int hidden[] = { 0,0 }; //^^

//INIT
int cn = 1;
int c2 = 1; //for initFirearm
int invNum = 0;
int invObject[21];//for update() updates inv()

//INVENTORY
int inInventory = 0; //says if you are in inventory or not, currently used to show invHeader();
int inFilterInv = 0; //says your in filterinv
int item; //item number
int citem; //item to combine something with for reloading and loading  bullets and stuff
int escaped = 0; //in sel() tells filterInv when enough is enough
int filterNorm = 0; //for filterinv to act normal or be used for special things
int typeMax = 3; //types of items for filtering


int chpicked = 0; //returned from sel, says what choice was picked
int locs = 1;


//////////////////////////////////////////////////////////////////////ITEM VARS
//names
string fName[100] = { "" };//full name
string nName[100] = { "" };//short name

string iType[100] = { "" }; //type of item (firearm, melee weapon, misc, ammo)

int amount[100]; //number of this item you have
int attached[100]; //0 for not attached, num is what it is attached to

////GUN SPECIFIC
int reloadTime[100]; //number of turns to reload if you have another loaded mag
int magNum[100]; //this assigns a mag currently in the gun
int shootTime[100]; //shots per turn if shooting carefully
int reliability[100]; //this number out of 1000 chance of not jamming when you fire per shot
int accurracy[100]; //this number is score required to pass dexterity check
int damage[100]; //damage per shot
int optimalRange[100]; //0close 1med 2far
string ammoType[100]; //9mm, 20mm etc
int ammo[100]; //ID for mag that is in the gun
int jammed[100]; //1 is jammed 0 is not jammed
int bulletInChamber[100]; //1 has bullet in chamber
int owned[100]; //this is if you have the weapon
int range[100]; //this is how many blocks away you can shoot

////MAG SPECIFIC
int magSize[100]; //max number of bullets in mag
int bulletsLeft[100]; //bullets in mag

////CHAR SPECIFIC
int enemyOrder[100]; //this will be the order of enemies to update
//it skips enemies that aren't on the screen
int charNum = 0; //number of enemies on screen
int moveUpdate = 1; //if 0 no enemies move


///////////////////////////////////////////////////////////////////////////STRUCTS

struct player
{
	//names
	string fName; //first name
	string lName; //last name
	string nName; //nickname
	//health
	int hp;
	int maxhp;
	int bd[10]; //2 is healthy, 1 is injured 0 is gone 
	// [0] head
	// [1] torso
	// [2] left arm
	// [3] right arm
	// [4] left leg
	// [5] right leg
	//skills
	int lvl;
	int strength;
	int dexterity;
	int intelligence;
	int wisdom;
	int charisma;
	int mHand; //dominant hand for skill checks, 2 is left hand 3 is right hand
	int mLeg; //dominant leg i know this sounds dumb but its for running away and stuff
	//location
	int x;
	int y;
};
struct enemy
{
	//names
	string name[100]; //npc name
	//health
	int hp[100];
	int maxhp[100];
	int bd[100][10]; //2 is healthy, 1 is injured 0 is gone 
	// [0] head
	// [1] torso
	// [2] left arm
	// [3] right arm
	// [4] left leg
	// [5] right leg
	//skills
	int lvl[100];
	int strength[100];
	int dexterity[100];
	int intelligence[100];
	int wisdom[100];
	int charisma[100];
	int mHand[100];
	//possessions
	int wpn[100];
	//location
	int x[100];
	int y[100];
	int di[100]; //distance from player
	int av[100]; //0 if off screen, 1 if on screen, 2 if in range
	int pr[100]; //this is priority as in how close to player
};

//player sf{ "sebastian", "fournier", "sebbie", 20, 20, 10, 10, 10, 10, 10 };
player mc; //player
enemy ph; //enemies

//baretta




/////////////////////////////////////////////////////////////////////////FUNCTIONS
int init()
{
	xmax = 60;
	ymax = 24; //display resolution

	//loading visuals
	sym(219, xmax * 2);
	sym(10, ymax / 2);
	tx("LOADING");
	sym(10, (ymax / 2) - 2);
	sym(219, xmax * 2);


	for (int u = 0; u < 100; u++) {
		attached[u] = 0;
	}
	//resets all attachments
	////////////////////////STATICS
	
	//random grass generation
	int weee = 1;
	for (int xq = 0; xq <= xborder; xq++) {
		for (int yq = 0; yq <= yborder; yq++) {
			weee = r(1, 30);
			if (weee == 1) {
				bd(176, xq, yq);
			}
		}
	}

	//world border
	bld(100, 100, xborder, yborder, 2);

	


	//buildings
	bld(226, 211, 230, 230, 2);

	//item on ground test
	i[225][210] = 4;

	///////////////////PLACEHOLDER MC
	mc.fName = "JOE";
	mc.lName = "SMITH";
	mc.nName = "JOE";
	mc.hp = 20;
	mc.maxhp = 20;
	mc.bd[0] = 2;	
	mc.bd[1] = 2;
	mc.bd[2] = 2;
	mc.bd[3] = 2;
	mc.bd[4] = 2;
	mc.bd[5] = 2;
	mc.mHand = 3;
	mc.mLeg = 4;
	mc.lvl = 1;
	mc.strength = 10;
	mc.dexterity = 10;
	mc.intelligence = 10;
	mc.wisdom = 10;
	mc.charisma = 10;
	/////////////////////////ENTITIES
	initEnemy("RANGER", 10, 5, 10, 3, 2, 225, 225, 15);
	/*initEnemy("RANGER", 10, 5, 10, 3, 2, 225, 224, 1);
	initEnemy("RANGER", 10, 5, 10, 3, 2, 225, 223, 1);
	initEnemy("RANGER", 10, 5, 10, 3, 2, 226, 223, 1);
	initEnemy("RANGER", 10, 5, 10, 3, 2, 227, 223, 1);
	initEnemy("RANGER", 10, 5, 10, 3, 2, 227, 224, 1);
	initEnemy("RANGER", 10, 5, 10, 3, 2, 227, 225, 1);
	initEnemy("RANGER", 10, 5, 10, 3, 2, 226, 225, 1);
	initEnemy("RANGER", 10, 5, 10, 3, 2, 226, 226, 1);
	initEnemy("RANGER", 10, 5, 10, 3, 2, 226, 227, 1);
	initEnemy("RANGER", 10, 5, 10, 3, 2, 226, 228, 1);*/ //square of enemies used for rangefinding
	////////////////////////MC WEAPONS
	initFirearm(950, 80, "BARETTA M9", 20, 5, "M9", 5, 1, "9mm", 2); //2
	//initFirearm("GLOCK 9", "GLOCK", 95, 9, 6, 0, "9mm", 0, 0, 1, 1, 1);
	//////////////////////ENEMY WEAPONS
	//initFirearm("GLOCK 9 FULL AUTO", "GLOCK", 97, 10, 3, 0, "9mm", 0, 1, 0, 1, 4);

	///////////////////MISC OWNED ITEMS
	initMag(20, "9mm", 1, 2); //3
	initMag(30, "9mm");
	initBullet(100, "9mm", 1); //5
	
	///////////////////INITIALIZER MISC
	gunNum = 1; //starting weapon
	xh = 225;
	yh = 210; //home spawn change this to change spawn
	itemLogger(); //logs items into txt file
	
	drange = xmax + ymax + 100;
	display();
	return 0;
}
int display()
{
	tp(xh, yh);
	
	
	int flag = 1;
	while (flag) {
		if (killed) {
			int toimp;
			system("CLS");
			for (int tomp = ymax + 5; tomp >= 1; tomp--) {
				for (int timp = 0; timp < xmax; timp++) {
					toimp = r(0, 2);
					sym(32, toimp);
					sym(219, (2 - toimp));
				}
				sym(10, 1);
			}
			killed = 0;
		}
		system("CLS");
		if (invats) {
			txt("VATS", 205);
		}
		else {
			txt("WORLD", 205);
		}
		
		sym(10, 1);
		if (!invats) {
			for (int w = 0; w <= cn; w++) { 
				//updates enemies
				if (ph.hp[w] > 0) {
					moveC(w);
				}
			}
			//reloads
			if (reloadNum) reloadNum--;
		}
		else {
			endist();
		}
		if (firing) {
			//coords for character "BANG"
			int xcord1 = (mc.x - 2);
			int xcord2 = (mc.x + 2);
			int ycord1 = (mc.y - 2);
			int ycord2 = (mc.y + 2);
			here[0] = r(xcord1, xcord2);
			here[1] = r(ycord1, ycord2);

			//coords for enemy "HIT" or "MISS"
			int xcord3 = (ph.x[ennum] - 2);
			int xcord4 = (ph.x[ennum] + 2);
			int ycord3 = (ph.y[ennum] - 2);
			int ycord4 = (ph.y[ennum] + 2);
			here[2] = r(xcord3, xcord4);
			here[3] = r(ycord3, ycord4);
		}
		else if (ejected) {
			int xcord1 = (mc.x - 2);
			int xcord2 = (mc.x + 2);
			int ycord1 = (mc.y - 2);
			int ycord2 = (mc.y + 2);
			here[0] = r(xcord1, xcord2);
			here[1] = r(ycord1, ycord2);
		}
		else if (reloaded) {
			int xcord1 = (mc.x - 2);
			int xcord2 = (mc.x + 2);
			int ycord1 = (mc.y - 2);
			int ycord2 = (mc.y + 2);
			here[0] = r(xcord1, xcord2);
			here[1] = r(ycord1, ycord2);
		}
		for (yloc = ymax; yloc >= 1; yloc--) {
			yg = yloc + y;
			for (xloc = 1; xloc <= xmax; xloc++) {
				xg = xloc + x;


				/// MAIN PART FOR WORLD DISPLAY ///

				if (xloc == xmax / 2 && yloc == ymax / 2) {
					mc.x = xg;
					mc.y = yg;
				}
				if (vis()) { //displays visual effects
				}
				else if (xloc == xmax / 2 && yloc == ymax / 2) { //mc display
					sym(178, 2);
				}
				//else if (vis()) { //display for combat visuals
				//}  don't know why there's two vis inits here but if visuals stop working add this back ig
				else if (dsplyE()) { //displays entities
				}
				else{
					dsplybd(); //displays static pixels
				}
				
				///////////////////////////////////////////////////////

				

			}
			sym(10, 1);
		}
		sym(205, xmax * 2);
		sym(10, 1);
		header();
		if (debug) {
			cout << mc.x << "," << mc.y << " ";
			//cout << xg << "," << yg << " ";
			//if (col("up")) cout << "collide up,";
			//if (col("down")) cout << "collide down,";
			//if (col("left")) cout << "collide left,";
			//if (col("right")) cout << "collide right,";
			//cout << "resolution: " << xmax << "*" << ymax << " ";
			cout << "last input:" << ans;
			//if (firing) cout << " firing";
			//if (hit) cout << " hit";
			//cout << " " + range[gunNum];
			//cout << " " + charNum;
			cout << " selen:" << selen;
		}
		for (int s = 1; s <= 5; s++) {
			int d = ph.x[s] - mc.x;
			int f = ph.y[s] - mc.y;
			d = abs(d);
			f = abs(f);
			if (d <= 1 && f <= 1 && ph.hp[s] > 0) {
				goToCombat = s;
			}
		}
		if (goToCombat) {
			tx("ENTERING COMBAT");
			sym(10, 1);
			goToCombat = 0;
		}
		ennum = 0; //stop auto shooting dead targets
		fflush(stdin);
		ans = _getch();
		if (invats) {
			if (kp("quit")) {
				flag = 0;
			}
			if (kp("debug")) {
				debug = !debug;
			}
			if (kp("details")) {
				details = !details;
			}
			if (kp("escape") || kp("vats")) {
				invats = 0;
				selen = 0;
			}
			else if (kp("down") || kp("left")) {
				if (selen > 1) {
					selen--;
				}
				else {
					selen = cn;
				}
				int flag3 = 1;
				while (ph.av[selen] != 2 && flag3) {
					if (selen > 1) {
						selen--;
					}
					else {
						selen = 0;
						flag3 = 0;
					}
				}
			}
			else if (kp("up") || kp("right")) {
				if (selen <= cn) {
					selen++;
				}
				else {
					selen = 1;
				}
				int flag3 = 1;
				while (ph.av[selen] != 2 && flag3) {
					if (selen <= cn) {
						selen++;
					}
					else {
						selen = 0;
						flag3 = 0;
					}
				}
			}
			else if (kp("shoot") && !reloadNum && !jammed[gunNum]) {
				fire();
			}
		}
		else {
			if (kp("quit")) {
				flag = 0;
			}
			if (kp("debug")) {
				debug = !debug;
			}
			if (kp("details")) {
				details = !details;
			}
			if (kp("escape")) {
				menu();
			}
			if (kp("up") && !col("up")) {
				y++;
			}
			else if (kp("down") && !col("down")) {
				y--;
			}
			else if (kp("left") && !col("left")) {
				x--;
			}
			else if (kp("right") && !col("right")) {
				x++;
			}
			else if ((kp("vats") && bulletInChamber[gunNum])) {
				invats = 1;
				selen = 0;
			}
			else if (kp("shoot") && bulletInChamber[gunNum] && !jammed[gunNum] && !reloadNum) {
				fire();
			}
			else if (kp("reload") && gunNum) {
				update();
				int flag4 = 1;
				int temp = 0;
				while (flag4 && temp <= 100) {
					if (iType[invObject[temp]] == "AMMO MAG") {
						if (ammoType[invObject[temp]] == ammoType[gunNum]) {
							if (bulletsLeft[invObject[temp]] > 0) {
								attached[ammo[gunNum]] = 0;
								ammo[gunNum] = invObject[temp];
								attached[invObject[temp]] = gunNum;
								reloadNum += reloadTime[gunNum];
								reloaded = 1;
							}
						}
					}
					temp++;
				}
			}
			else if (kp("eject") && !reloadNum) {
				if (bulletsLeft[ammo[gunNum]]) {
					bulletsLeft[ammo[gunNum]]--;
					bulletInChamber[gunNum] = 1;
				}
				else {
					bulletInChamber[gunNum] = 0;
				}
				jammed[gunNum] = 0;
				ejected = 1;
			}
			else if (kp("secondary")) {
				inv();
			}
			else if (kp("interact")) {
				if (i[mc.x][mc.y]) {
					owned[i[mc.x][mc.y]] = 1;
					i[mc.x][mc.y] = 0;
				}
			}
		}
	}
	return 0;
}
int header()
{
	//prompt for ground item
	if (i[mc.x][mc.y]) {
		string itemString = fName[i[mc.x][mc.y]] + " (F)";
		tx(itemString);
	}

	//player health
	if (mc.hp < mc.maxhp) {
		float num = (float)mc.hp / mc.maxhp;
		int relativeHealth = (float)num * xmax * 2;
		sym(176, (xmax - relativeHealth / 2));
		sym(178, relativeHealth);
		sym(176, (xmax * 2 - relativeHealth) - (xmax - relativeHealth / 2));
		sym(10, 1);
	}
	
	//enemy health
	//float num1 = (float)ph.hp[enemyNum] / ph.maxhp[enemyNum];
	//int relativeHealth1 = (float)num1 * xmax * 2;
	//sym(176, (xmax - relativeHealth1 / 2));
	//sym(178, relativeHealth1);
	//sym(176, (xmax * 2 - relativeHealth1) - (xmax - relativeHealth1 / 2));
	//sym(10, 1);

	string ab1; //bullet in chamber or no
	string ab2; //combat range
	
	if (jammed[gunNum]) {
		ab1 = "JAMMED";
	}
	else if (bulletInChamber[gunNum] == 1) {
		ab1 = "BULLET IN CHAMBER";
	}
	else {
		ab1 = "EMPTY CHAMBER";
	}
	/*
	switch (combatRange) {
	case 0:
		ab2 = "CLOSE";
		break;
	case 1:
		ab2 = "MED";
		break;
	case 2:
		ab2 = "FAR";
		break;
	}
	*/
	string testicle;
	string balls = mc.nName + " LVL " + to_string(mc.lvl) + " =VS= " + ph.name[enemyNum] + " LVL " + to_string(ph.lvl[enemyNum]);
	string penis = "HEAD:" + to_string(ph.bd[enemyNum][0]) + " TORSO:" + to_string(ph.bd[enemyNum][1]) + " LEFT ARM:" + to_string(ph.bd[enemyNum][2]) + " RIGHT ARM:" + to_string(ph.bd[enemyNum][3]) + " LEFT LEG:" + to_string(ph.bd[enemyNum][4]) + " RIGHT LEG:" + to_string(ph.bd[enemyNum][5]);
	//string ballHair = "RANGE: " + ab2;
	if (!reloadNum) {
		testicle = "WEAPON: " + nName[gunNum] + " " + to_string(bulletsLeft[ammo[gunNum]]) + "/" + to_string(magSize[ammo[gunNum]]) + " " + ab1;
	}
	else {
		testicle = "WEAPON: " + nName[gunNum] + " RELOADING(" + to_string(reloadNum) + ")";
	}
	//tx(balls
	if (details) tx(penis);
	tx(testicle);
	//tx(ballHair);
	//sym(196, xmax * 2);
	//sym(10, 1);
	return 0;
}
int invHeader()
{
	int n;
	if (inFilterInv && !filterNorm) {
		n = citem;
	}
	else {
		n = item;
	}
	if (iType[n] != "") {
		tx(fName[n]);
		string owo = "TYPE: " + iType[n];
		tx(owo);
		if (iType[n] == "FIREARM") {
			owo = "SHOTS PER TURN:" + to_string(shootTime[n]) + " RELIABILITY:" + to_string(reliability[n]) + "%" + " DEXTERITY SCORE:" + to_string(accurracy[n]) + " DAMAGE:" + to_string(damage[n]);
			tx(owo);
			owo = "RANGE:" + to_string(optimalRange[n]) + " AMMO:" + ammoType[n] + " MAG:" + to_string(bulletsLeft[ammo[n]]) + "/" + to_string(magSize[ammo[n]]) + " RELOAD TIME:" + to_string(reloadTime[n]);
			tx(owo);
			owo = "";
			if (gunNum == n) {
				owo = "EQUIPPED";
				tx(owo);
			}
			if (jammed[n]) {
				owo = "WEAPON IS JAMMED";
				tx(owo);
			}
			if (!ammo[n]) {
				owo = "NO MAG";
				tx(owo);
			}
			else if (!bulletsLeft[ammo[n]]){
				owo = "EMPTY MAG";
				tx(owo);
			}
			if (!bulletInChamber[n]) {
				owo = "CHAMBER IS EMPTY";
				tx(owo);
			}
		}
		else if (iType[n] == "AMMO MAG") {
			//owo = "BULLETS:" + to_string(bulletsLeft[n]) + "/" + to_string(magSize[n]) + " BULLET TYPE:" + ammoType[n];
			//tx(owo);
		}
		else if (iType[n] == "BULLET") {
			owo = "AMOUNT: " + to_string(amount[n]);
			tx(owo);
		}
		sym(196, xmax * 2);
		sym(10, 1);
	}
	return 0;
}
int update()
{
	invNum = 0;
	for (int m = 1; m <= 20; m++) {
		invObject[m] = 0;
	}
	for (int k = 1; k <= 11; k++) {
		if (owned[k] && !attached[k]) {
			invNum++;
			invObject[invNum] = k;
			if (iType[k] == "AMMO MAG") {
				fName[k] = ammoType[k] + " MAG " + to_string(bulletsLeft[k]) + "/" + to_string(magSize[k]);
			}
			else if (iType[k] == "FIREARM") {
					fName[ammo[k]] = ammoType[ammo[k]] + " MAG " + to_string(bulletsLeft[ammo[k]]) + "/" + to_string(magSize[ammo[k]]);
			}
		}
	}
	return 0;
}


int inv()
{
	inInventory = 1;
	update();
	while (sel("INVENTORY", invNum, "YES", fName[invObject[1]], fName[invObject[2]], fName[invObject[3]], fName[invObject[4]], fName[invObject[5]], fName[invObject[6]], fName[invObject[7]], fName[invObject[8]], fName[invObject[9]], fName[invObject[10]])) {
		if (chpicked) {
			invChose();
		}
	}
	if (filterNorm) {
		update();
		escaped = 0;
		inInventory = 0;
		filterInv("FIREARM");
	}
	inInventory = 0;
	return 0;
}
int filterInv(string iType1)
{
	update();
	inFilterInv = 1;
	int invNum = 0;
	int invObject[21];
	for (int m = 1; m <= 20; m++) {
		invObject[m] = 0;
	}
	if (filterNorm) {
		for (int k = 1; k <= 20; k++) {
			if (owned[k] && iType[k] == iType1) {
				invNum++;
				invObject[invNum] = k;
			}
		}
	}
	else {
		for (int k = 1; k <= 20; k++) {
			if (owned[k] && iType[k] == iType1 && ammoType[k] == ammoType[citem]) {
				invNum++;
				invObject[invNum] = k;
			}
		}
	}
	while (!escaped) {
		sel(iType1, invNum, "YES", fName[invObject[1]], fName[invObject[2]], fName[invObject[3]], fName[invObject[4]], fName[invObject[5]], fName[invObject[6]], fName[invObject[7]], fName[invObject[8]], fName[invObject[9]], fName[invObject[10]]);
		if (chpicked) {
			item = invObject[chpicked];
			if (filterNorm) {
				invChose();
			}
			else {
				if (iType[item] == "FIREARM") {
					ans = _getch();
				}
				else if (iType[item] == "AMMO MAG") { //for reload
					attached[ammo[gunNum]] = 0;
					ammo[citem] = item;
					attached[item] = gunNum;
					reloadNum += reloadTime[gunNum];
					escaped = 1;
				}
				else if (iType[item] == "BULLET") {
					if (bulletsLeft[citem] < magSize[citem]) {
						bulletsLeft[citem]++;
						amount[item]--;
						reloadNum++;
					}
				}
			}
			update();
		}
	}
	if (filterNorm) {
		update();
		escaped = 0;
		switch (filterNorm) {
		case 1:
			filterInv("FIREARM");
			break;
		case 2:
			filterInv("AMMO MAG");
			break;
		case 3:
			filterInv("BULLET");
			break;
		}
		//filterNorm = 0;
	}
	inFilterInv = 0;
	filterNorm = 0;
	return 0;
}
int invChose()
{
	item = invObject[chpicked];
	citem = item;
	if (iType[item] == "FIREARM") {
		while (chpicked) {
			sel("FIREARM", 4, "YES", "RELOAD", "EJECT ROUND", "EJECT MAG", "EQUIP"); //add eject mag as an option
			if (chpicked == 1) {
				filterNorm = 0;
				filterInv("AMMO MAG");
				update();
				chpicked = 0;
			}
			else if (chpicked == 2) {
				if (bulletsLeft[ammo[item]]) {
					bulletsLeft[ammo[item]]--;
					bulletInChamber[item] = 1;
				}
				else {
					bulletInChamber[item] = 0;
				}
				jammed[item] = 0;
			}
			else if (chpicked == 3) {
				ammo[gunNum] = 0;
			}
			else if (chpicked == 4) {
				if (gunNum == item) {
					gunNum = 0;
				}
				else {
					gunNum = item;
				}
			}
		}
	}
	else if (iType[item] == "AMMO MAG") {
		while (chpicked) {
			sel("MAG", 1, "YES", "ADD BULLETS"); //add remove bullets as an option 
			citem = item;
			if (chpicked == 1) {
				filterNorm = 0;
				filterInv("BULLET");
				update();
			}
		}
	}
	else if (iType[item] == "BULLET") {
		sel("BULLET", 1, "YES", "BACK");
	}
	item = 0;
	return 0;
}





int fire() //shoots the thing
{
	endist();
	firing = 1;
	if (bulletsLeft[ammo[gunNum]]) {
		bulletsLeft[ammo[gunNum]] -= 1;
	}
	else {
		bulletInChamber[gunNum] = 0;
	}
	if (invats) {
		ennum = selen;
	}
	else {
		int flag2 = 1;
		int q = 0;
		while (flag2) //shoots whoever is closest
		{
			//might not work if it takes all the uninitialized ranges
			for (int t = 1; t <= cn; t++) {
				//checks all enemies if they are the specific distance
				if (ph.hp[t] > 0 && flag2) {
					if (ph.di[t] == q) {
						ennum = t;
						flag2 = 0;
					}
				}
			}
			if (q > range[gunNum]) {
				ennum = 0;
				hit = 0;
				flag2 = 0;
			}
			else {
				q++;
			}
		}
	}
	if (r(1, 1000) <= reliability[gunNum]) {
		if (r(1, 100) <= accurracy[gunNum]) {
			ph.hp[ennum] -= damage[gunNum];
			if (ph.hp[ennum] <= 0 && ennum) killed = 1;
			hit = 1;
		}
		else {
			hit = 0;
		}
	}
	else {
		jammed[gunNum] = 1;
	}
	
	selen = 0;
	return 0;
}
int endist() 
{
	for (int h = 0; h <= cn; h++) {
		if (ph.hp[h] > 0) {
			//getting distance from player
			int xdist = abs(ph.x[h] - mc.x);
			int ydist = abs(ph.y[h] - mc.y);
			if (xdist > ydist) {
				ph.di[h] = xdist;
			}
			else {
				ph.di[h] = ydist;
			}
			//determining if the enemy is either on display, 
			//in range or not visible
			if (xdist > xmax || ydist > ymax) {
				ph.av[h] = 0;
			}
			else if (ph.di[h] <= range[gunNum]) {
				ph.av[h] = 2;
			}
			else {
				ph.av[h] = 1;
			}
		}
		else {
			ph.av[h] = 0;
		}
	}
	return 0;
}
int vis() //combat visuals
{
	int vc = 0;
	if (xloc == xmax && yloc == 1) {
		firing = 0;
	}
	vc = 0;
	if (firing) {
		if (xg == here[0] && yg == here[1]) {
			if (!jammed[gunNum]) {
				cout << "BA";
			}
			else {
				cout << "CL";
			}
			vc = 1;
		}
		else if (xg == (here[0] + 1) && yg == here[1]) {
			if (!jammed[gunNum]) {
				cout << "NG";
			}
			else {
				cout << "IC";
			}
			vc = 1;
		}
		else if (xg == (here[0] + 2) && yg == here[1] && jammed[gunNum]) {
			cout << "K ";
			vc = 1;
		}
		else if (xg == here[2] && yg == here[3]) {
			if (hit && !jammed[gunNum]) {
				cout << "HI";
			}
			else {
				cout << "MI";
			}
			vc = 1;
		}
		else if (xg == (here[2] + 1) && yg == here[3]) {
			if (hit && !jammed[gunNum]) {
				cout << "T ";
			}
			else {
				cout << "SS";
			}
			vc = 1;
		}
		else if (abs(mc.x - xg) <= 1 && abs(mc.y - yg) <= 1 && r(0, 2) == 0 && !jammed[gunNum]) {
			sym(219, 2);
			vc = 1;
		}
		else if (abs(mc.x - xg) <= 2 && abs(mc.y - yg) <= 2 && r(0, 2) == 0 && !jammed[gunNum]) {
			sym(178, 2);
			vc = 1;
		}
		else if (abs(ph.x[ennum] - xg) <= 1 && abs(ph.y[ennum] - yg) <= 1 && r(0, 3) == 0 && !jammed[gunNum]) {
			sym(178, 2);
			vc = 1;
		}
		else if (abs(ph.x[ennum] - xg) <= 2 && abs(ph.y[ennum] - yg) <= 2 && r(0, 3) == 0 && !jammed[gunNum]) {
			sym(177, 2);
			vc = 1;
		}
	}
	else if (ejected) {
		if (xg == here[0] && yg == here[1]) {
			cout << "EJ";
			vc = 1;
		}
		else if (xg == here[0] + 1 && yg == here[1]) {
			cout << "EC";
			vc = 1;
		}
		else if (xg == here[0] + 2 && yg == here[1]) {
			cout << "T ";
			vc = 1;
			ejected = 0;
		}
	}
	else if (reloaded) {
		if (xg == here[0] && yg == here[1]) {
			cout << "RE";
			vc = 1;
		}
		else if (xg == here[0] + 1 && yg == here[1]) {
			cout << "LO";
			vc = 1;
		}
		else if (xg == here[0] + 2 && yg == here[1]) {
			cout << "AD";
			vc = 1;
			reloaded = 0;
		}
	}
	if (vc) {
		return 1;
	}
	else {
		return 0;
	}
}


void moveC(int i)
{
	int o = r(1, 4);
	switch (o) {
		case 1:
			if (!coli("up", i)) ph.y[i]++;
			break;
		case 2:
			if (!coli("down", i)) ph.y[i]--;
			break;
		case 3:
			if (!coli("left", i)) ph.x[i]--;
			break;
		case 4:
			if (!coli("right", i)) ph.x[i]++;
			break;
	}
	
}
int dsplyE() 
{
	int u = 0;
	int i = 0;
	for (int p = 0; p <= cn; p++) { 
		if (ph.x[p] == xg && ph.y[p] == yg) {
			
			if (p == selen) {
				u = 3;
			}
			else if (ph.hp[p] > 0) {
				u = 1;
			}
			else {
				u = 2;
			}
			i = p;
		}
	}
	if (!debug) {
		if (u == 3) {
			if (ph.di[i] < 10) cout << "0";
			cout << ph.di[i];
			return 1;
		}
		else if (u == 1) {
			cout << "!!";
			return 1;
		}
		else if (u == 2) {
			cout << "@@";
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		if (u == 3) {
			cout << "!!";
			return 1;
		}
		else if (u == 1) {
			cout << "0" << ph.av[i];
			return 1;
		}
		else if (u == 2) {
			cout << "@@";
			return 1;
		}

		else {
			return 0;
		}
	}
	
}



int check(string skill, int score, int bdypt)
{
	int passed;
	int mod;
	int x;
	string answer;
	if (!bdypt) {
		passed = 0;
		answer = "FAILED " + skill + " CHECK, MISSING BODY PART";
		tx(answer);
		return 0;
	}
	else {
		if (skill == "STRENGTH") {
			x = r(1, 20);
			mod = (mc.strength - 10) / 2;
			if (x + mod >= score) {
				passed = 1;
			}
			else {
				passed = 0;
			}
		}
		if (skill == "DEXTERITY") {
			x = r(1, 20);
			mod = (mc.dexterity - 10) / 2;
			if (x + mod >= score) {
				passed = 1;
			}
			else {
				passed = 0;
			}
		}
		if (skill == "INTELLIGENCE") {
			x = r(1, 20);
			mod = (mc.intelligence - 10) / 2;
			if (x + mod >= score) {
				passed = 1;
			}
			else {
				passed = 0;
			}
		}
		if (skill == "WISDOM") {
			x = r(1, 20);
			mod = (mc.wisdom - 10) / 2;
			if (x + mod >= score) {
				passed = 1;
			}
			else {
				passed = 0;
			}
		}
		if (skill == "CHARISMA") {
			x = r(1, 20);
			mod = (mc.charisma - 10) / 2;
			if (x + mod >= score) {
				passed = 1;
			}
			else {
				passed = 0;
			}
		}
		if (passed) {
			answer = "PASSED " + skill + " CHECK OF " + to_string(score) + ", SCORED " + to_string(x + mod);
			tx(answer);
			return 1;
		}
		else {
			answer = "FAILED " + skill + " CHECK OF " + to_string(score) + ", SCORED " + to_string(x + mod);
			tx(answer);
			return 0;
		}
	}
}

int sel(string top, int chnum, string exitable, string ch1, string ch2, string ch3, string ch4, string ch5, string ch6, string ch7, string ch8, string ch9, string ch10)
{
	int goingIntoInv = 0;
	int flag = 1;
	int select[12];
	chpicked = 0;
	escaped = 0;
	while (flag) {
		for (int i = 1; i <= 10; i++) {
			select[i] = 32;
		}
		select[locs] = 196;
		if (inInventory) {
			system("CLS");
			txt(top, 205);
			invHeader();
		}
		else if (inCombat) {
			system("CLS");
			txt(top, 205);
			header();
		} 
		else {
			system("CLS");
			txt(top, 205);
		}
		for (int o = 1; o <= chnum; o++) {
			if (o == 1) {
				txt(ch1, select[o]);
			}
			else if (o == 2) {
				txt(ch2, select[o]);
			}
			else if (o == 3) {
				txt(ch3, select[o]);
			}
			else if (o == 4) {
				txt(ch4, select[o]);
			}
			else if (o == 5) {
				txt(ch5, select[o]);
			}
			else if (o == 6) {
				txt(ch6, select[o]);
			}
			else if (o == 7) {
				txt(ch7, select[o]);
			}
			else if (o == 8) {
				txt(ch8, select[o]);
			}
			else if (o == 9) {
				txt(ch9, select[o]);
			}
			else if (o == 10) {
				txt(ch10, select[o]);
			}
		}
		if (debug) {
			cout << "itemtype:" << iType[item];
		}
		fflush(stdin);
		ans = _getch();
		if (kp("escape") || kp("quit") || (kp("secondary") && inInventory)) {
			if (exitable == "YES") {
				filterNorm = 0;
				escaped = 1;
				flag = 0;
			}
		}
		else if (kp("up")) {
			if (locs > 1) {
				locs--;
			}
			else {
				locs = chnum;
			}
		}
		else if (kp("down")) {
			if (locs < chnum) {
				locs++;
			}
			else {
				locs = 1;
			}
		}
		else if (kp("left") && (inFilterInv)) {
			if (filterNorm > 1) {
				filterNorm--;
			}
			else {
				goingIntoInv = 1;
			}
			escaped = 1;
			flag = 0;
		}
		else if (kp("right") && (inInventory || inFilterInv)) {
			if (filterNorm < typeMax) {
				filterNorm++;
				escaped = 1;
				flag = 0;
			}
		}
		else if (kp("select")) {
			flag = 0;
		}
		else if (kp("debug")) {
			debug = !debug;
		}
		else if (kp("details")) {
			details = !details;
		}
	}
	if (escaped) {
		chpicked = 0;
		locs = 1;
		if (goingIntoInv) {
			inv();
		}
		return 0;
	}
	else {
		chpicked = locs;
		return locs;
	}
}

int menu()
{
	int loc = 1;
	int flag = 1;
	int select[11];
	while (sel("MENU", 10, "YES", "INVENTORY", "SET DISPLAY SIZE", "TP HOME", "TELEPORT", "CREATE CHARACTER", "VIEW CHARACTER", "SAVE", "LOAD", "PLACEHOLDER", "QUIT")) {
		
		if (chpicked == 1) {
			inv();
		}
		else if (chpicked == 2) {
			setDisplaySize();
		}
		else if (chpicked == 3) {
			tp(xh, xh);
		}
		else if (chpicked == 4) {
			teleport();
		}
		else if (chpicked == 5) {
			createCharacter();
		}
		else if (chpicked == 6) {
			viewCharacter();
		}
		else if (chpicked == 7) {
			saveGame();
		}
		else if (chpicked == 8) {
			loadGame();
		}
		
		else if (chpicked == 10) {
			exit(0);
		}
	}
	return 0;
}
void setDisplaySize() 
{
	xmaxo = xmax;
	ymaxo = ymax;
	system("CLS");
	txt("CHOOSE EVEN NUMBER FOR X",205);
	sym(10, 1);
	cout << "CURRENT: " << xmax << "*" << ymax;
	sym(10, 1);
	cin >> xmax;
	system("CLS");
	txt("CHOOSE EVEN NUMBER FOR Y", 205);
	sym(10, 1);
	cout << "CURRENT: " << xmax << "*" << ymax;
	sym(10, 1);
	cin >> ymax;
	x -= ((xmax - xmaxo) / 2);
	y -= ((ymax - ymaxo) / 2);
	drange = xmax + ymax + 100;
}
void teleport() 
{
	int temp1;
	int temp2;
	system("CLS");
	txt("TELEPORT", 205);
	sym(10, 1);
	cout << "CURRENT: " << mc.x << "," << mc.y;
	sym(10, 1);
	tx("TYPE X VALUE");
	sym(10, 1);
	cin >> temp1;
	tx("TYPE Y VALUE");
	sym(10, 1);
	cin >> temp2;
	tp(temp1, temp2);
}
void createCharacter()
{
	system("CLS");
	txt("CREATE CHARACTER", 205);
	cout << "FIRST NAME: ";
	cin >> mc.fName;
	cout << "LAST NAME: ";
	cin >> mc.lName;
	cout << "NICKNAME: ";
	cin >> mc.nName;
	int loc = 1;
	int flag = 1;
	string toppart = mc.fName + " '" + mc.nName + "' " + mc.lName;
	sel(toppart, 2, "NO", "PICK SKILLS", "RANDOM SKILLS");
	if (chpicked == 1) {
		flag = 0;
		system("CLS");
		cout << mc.fName << " '" << mc.nName << "' " << mc.lName;
		sym(10, 2);
		cout << "FOR OPTIMAL PLAYING EXPERIENCE KEEP LEVELS UNDER 20";
		sym(10, 1);
		cout << "STRENGTH: ";
		cin >> mc.strength;
		cout << "DEXTERITY: ";
		cin >> mc.dexterity;
		cout << "INTELLIGENCE: ";
		cin >> mc.intelligence;
		cout << "WISDOM: ";
		cin >> mc.wisdom;
		cout << "CHARISMA: ";
		cin >> mc.charisma;
		mc.lvl = 1;
		mc.maxhp = (mc.lvl + mc.strength);
		mc.hp = mc.maxhp;
		ans = _getch();
	}
	else if (chpicked == 2) {
		flag = 0;
		for (int i = 1; i <= 20; i++) {
			system("CLS");
			cout << mc.fName << " '" << mc.nName << "' " << mc.lName;
			sym(10, 2);
			mc.strength = rand() % 100;
			cout << "STRENGTH: " << mc.strength;
		}
		for (int i = 1; i <= 20; i++) {
			system("CLS");
			cout << mc.fName << " '" << mc.nName << "' " << mc.lName;
			sym(10, 2);
			mc.dexterity = rand() % 100;
			cout << "STRENGTH: " << mc.strength;
			sym(10, 1);
			cout << "DEXTERITY: " << mc.dexterity;
		}
		for (int i = 1; i <= 20; i++) {
			system("CLS");
			cout << mc.fName << " '" << mc.nName << "' " << mc.lName;
			sym(10, 2);
			mc.intelligence = rand() % 100;
			cout << "STRENGTH: " << mc.strength;
			sym(10, 1);
			cout << "DEXTERITY: " << mc.dexterity;
			sym(10, 1);
			cout << "INTELLIGENCE: " << mc.intelligence;
		}
		for (int i = 1; i <= 20; i++) {
			system("CLS");
			cout << mc.fName << " '" << mc.nName << "' " << mc.lName;
			sym(10, 2);
			mc.wisdom = rand() % 100;
			cout << "STRENGTH: " << mc.strength;
			sym(10, 1);
			cout << "DEXTERITY: " << mc.dexterity;
			sym(10, 1);
			cout << "INTELLIGENCE: " << mc.intelligence;
			sym(10, 1);
			cout << "WISDOM: " << mc.wisdom;
		}
		for (int i = 1; i <= 20; i++) {
			system("CLS");
			cout << mc.fName << " '" << mc.nName << "' " << mc.lName;
			sym(10, 2);
			mc.charisma = rand() % 100;
			cout << "STRENGTH: " << mc.strength;
			sym(10, 1);
			cout << "DEXTERITY: " << mc.dexterity;
			sym(10, 1);
			cout << "INTELLIGENCE: " << mc.intelligence;
			sym(10, 1);
			cout << "WISDOM: " << mc.wisdom;
			sym(10, 1);
			cout << "CHARISMA: " << mc.charisma;
		}
	}
	mc.lvl = 1;
	mc.maxhp = (mc.lvl + mc.strength);
	mc.hp = mc.maxhp;
	sym(10, 1);
	ans = _getch();
}
void viewCharacter() 
{
	system("CLS");
	txt("CHARACTER", 205);
	sym(10, 1);
	cout << mc.fName << " '" << mc.nName << "' "  << mc.lName;
	sym(10, 1);
	cout << "LVL: " << mc.lvl << " HP: " << mc.hp << "/" << mc.maxhp;
	sym(10, 2);
	cout << "STRENGTH: " << mc.strength;
	sym(10, 1);
	cout << "DEXTERITY: " << mc.dexterity;
	sym(10, 1);
	cout << "INTELLIGENCE: " << mc.intelligence;
	sym(10, 1);
	cout << "WISDOM: " << mc.wisdom;
	sym(10, 1);
	cout << "CHARISMA: " << mc.charisma;
	sym(10, 1);
	ans = _getch();
}
void saveGame()
{
	system("CLS");
	txt("SAVING", 205);
	sym(10, 2);
	save();
	tx("SAVED");
	sym(10, 1);
	ans = _getch();
}
void loadGame()
{
	system("CLS");
	txt("LOADING", 205);
	sym(10, 2);
	load();
	tx("LOADED");
	sym(10, 1);
	ans = _getch();
}



int kp(const char* key)
{
	if (key == "up") {
		if (ans == 119) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (key == "down") {
		if (ans == 115) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (key == "left") {
		if (ans == 97) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (key == "right") {
		if (ans == 100) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (key == "quit") {
		if (ans == 113) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (key == "escape") {
		if (ans == 27 || ans == 8) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (key == "select") {
		if (ans == 13) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (key == "debug") {
		if (ans == 33) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (key == "details") {
		if (ans == 64) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (key == "quit") {
		if (ans == 113) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (key == "shoot") {
		if (ans == 32) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (key == "secondary") {
		if (ans == 101) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (key == "vats") {
		if (ans == 118) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (key == "reload") {
		if (ans == 114) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (key == "eject") {
		if (ans == 82) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (key == "interact") {
		if (ans == 102) {
			return 1;
		}
		else {
			return 0;
		}
	}
}
int sym(int i, int o) 
{
	for (int tempv = 1; tempv <= o; tempv++) {
		cout << char(i);
	}
	return(0);
}
int loc(int q, int w) 
{
	if (q == xg && w == yg) {
		return 1;
	}
	else {
		return 0;
	}
}
int col(const char* i) 
{
	if (i == "up") {
		if (c[mc.x][mc.y + 1] == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (i == "down") {
		if (c[mc.x][mc.y - 1] == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (i == "left") {
		if (c[mc.x - 1][mc.y] == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (i == "right") {
		if (c[mc.x + 1][mc.y] == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}
int coli(const char* i, int num1)
{
	if (i == "up") {
		if (c[ph.x[num1]][ph.y[num1] + 1] == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (i == "down") {
		if (c[ph.x[num1]][ph.y[num1] - 1] == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (i == "left") {
		if (c[ph.x[num1] - 1][ph.y[num1]] == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (i == "right") {
		if (c[ph.x[num1] + 1][ph.y[num1]] == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}


int tp(int i, int o)
{
	x = i - (xmax / 2);
	y = o - (ymax / 2);
	return 0;
}


int bd(int type, int coordx, int coordy)
{
	if (type == 219) {
		c[coordx][coordy] = 1;
		b[coordx][coordy] = type;
	}
	else {
		c[coordx][coordy] = 0;
		b[coordx][coordy] = type;
	}
	return 0;
}
int bld(int coord1, int coord2, int coord3, int coord4, int type, string face)
{
	if (type == 1) {
		for (int xo = coord1; xo <= coord3; xo++) {
			for (int xe = coord2; xe <= coord4; xe++) {
				bd(219, xo, xe);
			}
		}
	}
	else if (type == 2) {
		for (int temp = coord1; temp <= coord3; temp++) {
			//x axis top, bottom
			bd(219, temp, coord2);
			bd(219, temp, coord4);
		}
		for (int temp2 = coord2; temp2 <= coord4; temp2++) {
			//y axis left, right
			bd(219, coord1, temp2);
			bd(219, coord3, temp2);
		}
	}
	else {
		return 1;
	}
	return 0;

	/*
	if (type == 1) {
		if (coord1 <= xg && xg <= coord3 && coord2 <= yg && yg <= coord4) {
			bd(219);
			return 1;
		}
		else {
			return 0;
		}

	}
	else if (type == 2) {
		if ((coord1 <= xg && xg <= coord3 && (coord2 == yg || coord4 == yg)) || (coord2 <= yg && yg <= coord4 && (coord1 == xg || coord3 == xg))) {
			bd(219);
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (type == 3) {
		if (face == "up" && (xg == (coord3 - coord1) / 2 + coord1) && yg == coord2) {
			bd(176);
			return 1;
		}
		else if (face == "down" && (xg == (coord3 - coord1) / 2 + coord1) && yg == coord4) {
			bd(176);
			return 1;
		}
		else if (face == "left" && (yg == (coord4 - coord2) / 2 + coord2) && xg == coord1) {
			bd(176);
			return 1;
		}
		else if (face == "right" && (yg == (coord4 - coord2) / 2 + coord2) && xg == coord3) {
			bd(176);
			return 1;
		}
		else if ((coord1 <= xg && xg <= coord3 && (coord2 == yg || coord4 == yg)) || (coord2 <= yg && yg <= coord4 && (coord1 == xg || coord3 == xg))) {
			bd(219);
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
	*/
}
int dsplybd()
{
	int wootemp = b[xg][yg];
	if (wootemp) {
		sym(wootemp, 2);
	}
	else if (i[xg][yg]) {
		sym(105, 2);
	}
	else {
		sym(32, 2);
	}
	return 0;
}


int tx(string i) 
{
	int p = (xmax - (i.length()) / 2);
	sym(32, p);
	cout << i;
	sym(32, xmax * 2 - p - i.length());
	sym(10, 1);
	return 0;
}
int txt(string i, int o)
{
	int p = (xmax - (i.length()) / 2);
	sym(o, p);
	cout << i;
	sym(o, xmax * 2 - p - i.length());
	sym(10, 1);
	return 0;
}

int r(int lower, int upper)
{
	int num = (rand() % (upper - lower + 1)) + lower;
	return num;
}

int save()
{
	ofstream file("saveData.txt");
	file << mc.x << endl << mc.y << endl;
	file << mc.fName << endl << mc.lName << endl << mc.nName << endl;
	file << mc.hp << endl << mc.maxhp << endl;
	file << mc.lvl << endl << mc.strength << endl << mc.dexterity << endl << mc.intelligence << endl << mc.wisdom << endl << mc.charisma << endl;
	file << gunNum << endl;

	file.close();
	return 0;
}
int load()
{
	int temp1 = 0;
	int temp2 = 0;
	int a;
	string b;
	string line;
	fstream file("saveData.txt");

	gotoLine(file, 1);
	file >> a;
	temp1 = a;
	gotoLine(file, 2);
	file >> a;
	temp2 = a;

	gotoLine(file, 3);
	file >> b;
	mc.fName = b;
	gotoLine(file, 4);
	file >> b;
	mc.lName = b;
	gotoLine(file, 5);
	file >> b;
	mc.nName = b;

	gotoLine(file, 6);
	file >> a;
	mc.hp = a;
	gotoLine(file, 7);
	file >> a;
	mc.maxhp = a;

	gotoLine(file, 8);
	file >> a;
	mc.lvl = a;

	gotoLine(file, 9);
	file >> a;
	mc.strength = a;
	gotoLine(file, 10);
	file >> a;
	mc.dexterity = a;
	gotoLine(file, 11);
	file >> a;
	mc.intelligence = a;
	gotoLine(file, 12);
	file >> a;
	mc.wisdom = a;
	gotoLine(file, 13);
	file >> a;
	mc.charisma = a;

	gotoLine(file, 14);
	file >> a;
	gunNum = a;


	file.close();
	tp(temp1, temp2);
	return 0;
}
int itemLogger() //logs all loaded items into a txt file
{
	ofstream file("item.txt");
	
	for (int pop = 0; pop <= c2; pop++) {
		file << pop << " = " << fName[pop] << endl;
	}

	file.close();
	return 0;
	return 0;
}

fstream& gotoLine(fstream& file, unsigned int num) {
	file.seekg(ios::beg);
	for (int i = 0; i < num - 1; ++i) {
		file.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return file;
}

int initEnemy(string name1, int strength1, int dexterity1, int intelligence1, int mainHand1, int wpn1, int x1, int y1, int num1)//this will create chars and items
{
	for (int num3 = 1; num3 <= num1; num3++) {
		ph.name[cn] = name1;
		ph.bd[cn][0] = 2; //head
		ph.bd[cn][1] = 2; //torso
		ph.bd[cn][2] = 2; //left arm
		ph.bd[cn][3] = 2; //right arm
		ph.bd[cn][4] = 2; //left leg
		ph.bd[cn][5] = 2; //right leg

		ph.strength[cn] = strength1;
		ph.dexterity[cn] = dexterity1;
		ph.intelligence[cn] = intelligence1;
		ph.lvl[cn] = (strength1 + dexterity1 + intelligence1) / 3;
		ph.maxhp[cn] = strength1 + ph.lvl[cn];
		ph.hp[cn] = ph.maxhp[cn];

		ph.wpn[cn] = wpn1;
		ph.mHand[cn] = mainHand1;

		ph.x[cn] = x1;
		ph.y[cn] = y1;

		cn++;
	}
	return 0;
}
int initFirearm(
	int reliability1, //out of 1000
	int accurracy1, //out of 100 
	string fName1, //full name of weapon
	int damage1, //hp taken off with a hit
	int reloadTime1, //turns reloading takes
	string nName1, //nickname
	int range1, //how many tiles away it can shoot
	int owned1, //0 is not owned, 1 is owned
	string ammoType1, //"9mm", stuff like that
	int ammo1, //exact number of mag if it has one
	int shootTime1 //how many turns to set up gun, 1 means instant
	)
{
	fName[c2] = fName1;
	nName[c2] = nName1;
	iType[c2] = "FIREARM";
	amount[c2] = 1;
	reloadTime[c2] = reloadTime1;
	shootTime[c2] = shootTime1;
	reliability[c2] = reliability1;
	accurracy[c2] = accurracy1;
	damage[c2] = damage1;
	ammoType[c2] = ammoType1;
	ammo[c2] = ammo1;
	if (ammo1) attached[ammo1] = c2;
	range[c2] = range1;
	bulletInChamber[c2] = 0;
	owned[c2] = owned1;
	c2++;
	return 0;
}
int initMag(int magSize1, string ammoType1, int owned1, int amount1, int bulletsLeft1)
{
	for (int i = 1; i <= amount1; i++) {
		nName[c2] = "MAG";
		iType[c2] = "AMMO MAG";
		magSize[c2] = magSize1;
		ammoType[c2] = ammoType1;
		owned[c2] = owned1;
		if (bulletsLeft1) {
			bulletsLeft[c2] = bulletsLeft1;
		}
		else {
			bulletsLeft[c2] = magSize1;
		}
		fName[c2] = ammoType[c2] + " MAG " + to_string(bulletsLeft[c2]) + "/" + to_string(magSize[c2]);
		c2++;
	}
	return 0;
}
int initBullet(int amount1, string ammoType1, int owned1) {
	nName[c2] = "BULLETS";
	iType[c2] = "BULLET";
	ammoType[c2] = ammoType1;
	owned[c2] = owned1;
	amount[c2] = amount1;
	fName[c2] = ammoType[c2] + " BULLETS";
	c2++;
	return 0;
}