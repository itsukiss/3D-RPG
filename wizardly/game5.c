#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curses.h>
#include <unistd.h>

#define R 0
#define L 1
#define g_y 10
#define g_x 10
#define MAPY 20
#define MAPX 20
#define SCANMAPY 30
#define SCANMAPX 15

void G1();
void G1_2();
void G1_3();
void G1_4(int RL);
void G1_5(int RL);
void G2();
void G3();
void G4();
void G4_1();
void G4_2(int RL);
void BG1();
void BG2();
void BGclear1();
void BGclear2();
void BGclear3();
void BGclear4();
void BGclear5();
void SG();
void SGclear1();
void SG_party();
void SG_sub();
void Top_G();
void syoki_state();
void genzaiti();
void TOP();
void MONSTERHOUSE();
void run();
void setting();
void GAMEN();
void haiti();
void DOOR();
void BATTLE();
void makeENEMY();
void drawENEMY();
void PARTY_STATE();
void battlemes();
void battlestartmes();
void CHOICE(int ptnumber);
void ATTACK();
void PARTY_ATTACK(int number);
void ENEMY_ATTACK(int number);
void EXSIST();
void Battle_ENDmes();
void syoku_state();
void Levelup();
void State_gamen();
void party();
void skillpage();
void statas(int number);
void skillnote(int number);
void syoku_up(int uh,int usp,int up,int ud,int uskl,int uspd,int level);
void JOIN(int enumber);
void JOIN_ST(int enumber);
void SUB();
void leave_party();
int SAVE();
int LOAD();
void saveG();
void saveG2();
void skilltree();
int B_skill(int ptnumber);
void learnSkill(int ptnumber);


int sayu;
int muki_hantei;
char str1[50],str2[20],str3[20],str4[20];
int (*NOWMAP)[MAPX];
int battle = 0;
int ptninzuu;
int nakamanokazu;
int kazu;
int sonzai;
int target[4] = {0};
int getkeikenchi;
int flag;
int fboss = 0;
int bosssen1 = 0;
int lastnumber;


int keikenti[100] ={
	-1,0,5,15,33,68,108,182,320,500,824,1250,
	1820,2480,3100,3840,4700,5700,6920,8640,10500,13060,
	17860,25000,34700,44000,56020,69000,84800,100000,120050,150000,
	194000,240000,290000,350000,422000,488000,552000,630000,699000,777777,
	860000,944000,1020000,1100000,1190000
};

int sykeikenti[21] = {
	-1,0,3,10,20,33,49,69,92,120,150,
	184,219,256,296,340,399,447,498,556,620
};

int map1[MAPY][MAPX]={
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,1,1,1,0,1,0,1,1,1,1,1,0,0,0,0,0,1},
	{1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,1,1,1,1,1,0,1,0,0,0,1,1,1,1,0,0,0,0,1},
	{1,0,0,0,0,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1},
	{1,0,1,1,0,1,0,0,0,1,0,1,0,1,0,0,0,0,0,1},
	{1,0,1,1,0,1,0,1,1,1,0,1,1,1,0,0,1,1,0,1},
	{1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,1,0,1},
	{1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,0,1},
	{1,0,1,0,0,0,1,0,0,0,0,0,0,1,0,1,1,1,0,1},
	{1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,1,1,0,1},
	{1,0,0,0,1,0,0,0,1,0,1,1,0,0,0,0,0,1,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int map2[MAPY][MAPX]={
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int map3[MAPY][MAPX]={
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int map4[MAPY][MAPX]={
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,0,1,0,1,0,0,0,0,0,0,0,1,0,1,1,1,0,1},
	{1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};



struct MAP{
	int (*floor)[MAPX];
	int downstair[2][2];
	int upstair[2][2];
	int tobira[2][2];
	int boss[2];
} ma[11];

struct KAIDAN{
	int kaidan;
	int dtou;
	int utod;
}ka;

struct ME{
	int muki;//0:north,1:east,2:south,3:west
	int me_x;
	int me_y;
	int me_kaisou;
	int join_monster_num[101];
} *me;

struct SKILL{
	char sk_name[9];
	int use;
	int sk_power;
	int consume_sp;
	int effect_state;
	int all;
	int eorp;
};

struct SYOKU{
	int syokugyo;
	char s_name[8];
	int s_level;
	struct SKILL skill[9];
} sy[111];

struct STATE_SYOKU{
	int s_uhp;
	int s_usp;
	int s_upower;
	int s_udefence;
	int s_uskill;
	int s_uspeed;
} ss[9];


struct PARTY{
	struct SYOKU syoku[111];
	char pt_name[8];
	int pt_level;
	int pt_hp;
	int pt_nowhp;
	int pt_sp;
	int pt_nowsp;
	int pt_power;
	int pt_defence;
	int pt_skill;
	int pt_speed;
	int pt_joutai;
	int pt_ulevel;
	int pt_keiken;
	int pt_exsist;
	int pt_synumber;
	int encount_num[111];
	int useskill;
	int pluspower;
	int plusdefence;
	int plusskill;
	int plusspeed;
	int effect_turn;
}pa[12];


struct ENEMY{
	int en_number;
	char *en_name;
	int en_level;
	int en_hp;
	int en_nowhp;
	int en_sp;
	int en_nowsp;
	int en_x;
	int en_y;
	int en_power;
	int en_defence;
	int en_skill;
	int en_speed;
	char en_form[7][20];
	int en_form_len;
	int en_exsist;
	int en_uhp;
	int en_usp;
	int en_upower;
	int en_udefence;
	int en_uskill;
	int en_uspeed;
	int getkeiken;
	int ukeiken;
	int en_join;
}en[4];

struct BOSS{
	int bs_number;
	char *bs_name;
	int bs_level;
	int bs_hp;
	int bs_x;
	int bs_y;
	int bs_power;
	int bs_defence;
	int bs_skill;
	int bs_speed;
	char bs_form[6][20];
	int bs_form_len;
	int bs_exsist;
	int bs_uhp;
	int en_upower;
	int bs_udefence;
	int bs_uskill;
	int bs_uspeed;
	int getkeiken;
}bs[4];

struct SAVEDATA{
	struct PARTY spa[12];
	struct ME sme[1];
	struct KAIDAN ska;
	int savenakama;
	
} DATA;

int main(){
	initscr();
	setting();
	syoku_state();
	skilltree();
	syoki_state();
	TOP();

	endwin();
	return 0;
}

void setting(){
	noecho();
	cbreak();
	curs_set(0);
	keypad(stdscr,TRUE);
	timeout(0);
}

void G1(){
	mvaddstr(g_y,g_x,   "############################################");
	mvaddstr(g_y+1,g_x, "#                                          #");
	mvaddstr(g_y+2,g_x, "#                                          #");
	mvaddstr(g_y+3,g_x, "#                                          #");
	mvaddstr(g_y+4,g_x, "#                                          #");
	mvaddstr(g_y+5,g_x, "#                                          #");
	mvaddstr(g_y+6,g_x, "#                                          #");
	mvaddstr(g_y+7,g_x, "#                                          #");
	mvaddstr(g_y+8,g_x, "#                                          #");
	mvaddstr(g_y+9,g_x, "#                                          #");
	mvaddstr(g_y+10,g_x,"#                                          #");
	mvaddstr(g_y+11,g_x,"#                                          #");
	mvaddstr(g_y+12,g_x,"#                                          #");
	mvaddstr(g_y+13,g_x,"#                                          #");
	mvaddstr(g_y+14,g_x,"#                                          #");
	mvaddstr(g_y+15,g_x,"#                                          #");
	mvaddstr(g_y+16,g_x,"#                                          #");
	mvaddstr(g_y+17,g_x,"############################################");
}

void G1_2(){
	mvaddstr(g_y+1,g_x+41, "##");
	mvaddstr(g_y+2,g_x+39, "##");
	mvaddstr(g_y+3,g_x+37, "##");
	mvaddstr(g_y+4,g_x+35, "##");
	mvaddstr(g_y+13,g_x+35,"##");
	mvaddstr(g_y+14,g_x+37,"##");
	mvaddstr(g_y+15,g_x+39,"##");
	mvaddstr(g_y+16,g_x+41,"##");
}

void G1_3(){
	mvaddstr(g_y+1,g_x+1, "##");
	mvaddstr(g_y+2,g_x+3, "##");
	mvaddstr(g_y+3,g_x+5, "##");
	mvaddstr(g_y+4,g_x+7, "##");
	mvaddstr(g_y+13,g_x+7,"##");
	mvaddstr(g_y+14,g_x+5,"##");
	mvaddstr(g_y+15,g_x+3,"##");
	mvaddstr(g_y+16,g_x+1,"##");
}

void G1_4(int RL){
	int i;
	if(RL == L){
		i = 9;
	}else if(RL == R){
		i = 36;
	}
	mvaddstr(g_y+5,g_x+i,"#");
	mvaddstr(g_y+6,g_x+i+1,"#");
	mvaddstr(g_y+7,g_x+i+2,"#");
	mvaddstr(g_y+8,g_x+i+3,"#");
	mvaddstr(g_y+9,g_x+i+3,"#");
	mvaddstr(g_y+10,g_x+i+2,"#");
	mvaddstr(g_y+11,g_x+i+1,"#");
	mvaddstr(g_y+12,g_x+i,"#");
}

void G1_5(int RL){
	int i;
	if(RL == L){
		i = 7;
	}else if(RL == R){
		i = 34;
	}
	mvaddstr(g_y+5,g_x+i,"#");
	mvaddstr(g_y+6,g_x+i-1,"#");
	mvaddstr(g_y+7,g_x+i-2,"#");
	mvaddstr(g_y+8,g_x+i-3,"#");
	mvaddstr(g_y+9,g_x+i-3,"#");
	mvaddstr(g_y+10,g_x+i-2,"#");
	mvaddstr(g_y+11,g_x+i-1,"#");
	mvaddstr(g_y+12,g_x+i,"#");
}
void G2(){
	mvaddstr(g_y+4,g_x+35, "#");
	mvaddstr(g_y+5,g_x+35, "#");
	mvaddstr(g_y+6,g_x+35, "#");
	mvaddstr(g_y+7,g_x+35, "#");
	mvaddstr(g_y+8,g_x+35, "#");
	mvaddstr(g_y+9,g_x+35, "#");
	mvaddstr(g_y+10,g_x+35,"#");
	mvaddstr(g_y+11,g_x+35,"#");
	mvaddstr(g_y+12,g_x+35,"#");
	mvaddstr(g_y+13,g_x+35,"#");
}

void G3(){
	mvaddstr(g_y+4,g_x+8, "#");
	mvaddstr(g_y+5,g_x+8, "#");
	mvaddstr(g_y+6,g_x+8, "#");
	mvaddstr(g_y+7,g_x+8, "#");
	mvaddstr(g_y+8,g_x+8, "#");
	mvaddstr(g_y+9,g_x+8, "#");
	mvaddstr(g_y+10,g_x+8,"#");
	mvaddstr(g_y+11,g_x+8,"#");
	mvaddstr(g_y+12,g_x+8,"#");
	mvaddstr(g_y+13,g_x+8,"#");
}

void G4(){
	mvaddstr(g_y+4,g_x+8, "############################");
	mvaddstr(g_y+13,g_x+8,"############################");
}

void G4_1(){
	mvaddstr(g_y+4,g_x, "############################################");
	mvaddstr(g_y+13,g_x,"############################################");
}

void G4_2(int RL){
	int i;
	if(RL == L){
		i = 0;
	}else if(RL == R){
		i = 35;
	}
	mvaddstr(g_y+4,g_x+i, "########");
	mvaddstr(g_y+13,g_x+i,"########");
}

void BG1(){
	mvaddstr(g_y,g_x,   "############################################");
	mvaddstr(g_y+1,g_x, "#                                          #");
	mvaddstr(g_y+2,g_x, "#                                          #");
	mvaddstr(g_y+3,g_x, "#                                          #");
	mvaddstr(g_y+4,g_x, "############################################");
	mvaddstr(g_y+5,g_x, "#                                          #");
	mvaddstr(g_y+6,g_x, "#                                          #");
	mvaddstr(g_y+7,g_x, "#                                          #");
	mvaddstr(g_y+8,g_x, "#                                          #");
	mvaddstr(g_y+9,g_x, "#                                          #");
	mvaddstr(g_y+10,g_x,"#                                          #");
	mvaddstr(g_y+11,g_x,"#                                          #");
	mvaddstr(g_y+12,g_x,"############################################");
	mvaddstr(g_y+13,g_x,"#                                          #");
	mvaddstr(g_y+14,g_x,"#                                          #");
	mvaddstr(g_y+15,g_x,"#                                          #");
	mvaddstr(g_y+16,g_x,"#                                          #");
	mvaddstr(g_y+17,g_x,"############################################");
}
void BG2(){
	mvaddstr(g_y,g_x,   "############################################");
	mvaddstr(g_y+1,g_x, "#                                          #");
	mvaddstr(g_y+2,g_x, "#                                          #");
	mvaddstr(g_y+3,g_x, "#                                          #");
	mvaddstr(g_y+4,g_x, "############################################");
	mvaddstr(g_y+5,g_x, "#                                          #");
	mvaddstr(g_y+6,g_x, "#                                          #");
	mvaddstr(g_y+7,g_x, "#                                          #");
	mvaddstr(g_y+8,g_x, "#                                          #");
	mvaddstr(g_y+9,g_x, "#                                          #");
	mvaddstr(g_y+10,g_x,"#                                          #");
	mvaddstr(g_y+11,g_x,"#                                          #");
	mvaddstr(g_y+12,g_x,"############################################");
	mvaddstr(g_y+13,g_x,"#              #                           #");
	mvaddstr(g_y+14,g_x,"#              #                           #");
	mvaddstr(g_y+15,g_x,"#              #                           #");
	mvaddstr(g_y+16,g_x,"#              #                           #");
	mvaddstr(g_y+17,g_x,"############################################");
}

void BGclear1(){
	mvaddstr(g_y+5,g_x, "#                                          #");
	mvaddstr(g_y+6,g_x, "#                                          #");
	mvaddstr(g_y+7,g_x, "#                                          #");
	mvaddstr(g_y+8,g_x, "#                                          #");
	mvaddstr(g_y+9,g_x, "#                                          #");
	mvaddstr(g_y+10,g_x,"#                                          #");
	mvaddstr(g_y+11,g_x,"#                                          #");
}

void BGclear2(){
	mvaddstr(g_y+13,g_x,"#                                          #");
	mvaddstr(g_y+14,g_x,"#                                          #");
	mvaddstr(g_y+15,g_x,"#                                          #");
	mvaddstr(g_y+16,g_x,"#                                          #");
}

void BGclear3(){
	mvaddstr(g_y+13,g_x,"#              #                           #");
	mvaddstr(g_y+14,g_x,"#              #                           #");
	mvaddstr(g_y+15,g_x,"#              #                           #");
	mvaddstr(g_y+16,g_x,"#              #                           #");
}

void BGclear4(){
	mvaddstr(g_y+1,g_x, "#                                          #");
	mvaddstr(g_y+2,g_x, "#                                          #");
	mvaddstr(g_y+3,g_x, "#                                          #");
}

void BGclear5(){
	mvaddstr(g_y+13,g_x+16,"                           ");
	mvaddstr(g_y+14,g_x+16,"                           ");
	mvaddstr(g_y+15,g_x+16,"                           ");
	mvaddstr(g_y+16,g_x+16,"                           ");
}


void SG(){
	mvaddstr(g_y,g_x,   "############################################");
	mvaddstr(g_y+1,g_x, "#                                          #");
	mvaddstr(g_y+2,g_x, "#                                          #");
	mvaddstr(g_y+3,g_x, "#                                          #");
	mvaddstr(g_y+4,g_x, "############################################");
	mvaddstr(g_y+5,g_x, "#              #                           #");
	mvaddstr(g_y+6,g_x, "#              #                           #");
	mvaddstr(g_y+7,g_x, "#              #                           #");
	mvaddstr(g_y+8,g_x, "#              #                           #");
	mvaddstr(g_y+9,g_x, "#              #                           #");
	mvaddstr(g_y+10,g_x,"#              #                           #");
	mvaddstr(g_y+11,g_x,"#              #                           #");
	mvaddstr(g_y+12,g_x,"#              #                           #");
	mvaddstr(g_y+13,g_x,"#              #                           #");
	mvaddstr(g_y+14,g_x,"#              #                           #");
	mvaddstr(g_y+15,g_x,"#              #############################");
	mvaddstr(g_y+16,g_x,"#              #                           #");
	mvaddstr(g_y+17,g_x,"############################################");
}

void SGclear1(){
	mvaddstr(g_y+5,g_x+16, "                           ");
	mvaddstr(g_y+6,g_x+16, "                           ");
	mvaddstr(g_y+7,g_x+16, "                           ");
	mvaddstr(g_y+8,g_x+16, "                           ");
	mvaddstr(g_y+9,g_x+16, "                           ");
	mvaddstr(g_y+10,g_x+16,"                           ");
	mvaddstr(g_y+11,g_x+16,"                           ");
	mvaddstr(g_y+12,g_x+16,"                           ");
	mvaddstr(g_y+13,g_x+16,"                           ");
	mvaddstr(g_y+14,g_x+16,"                           ");
}

void SG_party(){
	mvaddstr(g_y+5,g_x+16, "                           ");
	mvaddstr(g_y+6,g_x+16, "###########################");
	mvaddstr(g_y+7,g_x+16, "                           ");
	mvaddstr(g_y+8,g_x+16, "                           ");
	mvaddstr(g_y+9,g_x+16, "                           ");
	mvaddstr(g_y+10,g_x+16,"                           ");
	mvaddstr(g_y+11,g_x+16,"                           ");
	mvaddstr(g_y+12,g_x+16,"                           ");
	mvaddstr(g_y+13,g_x+16,"                           ");
	mvaddstr(g_y+14,g_x+16,"                           ");
}

void SG_sub(){
	mvaddstr(g_y+5,g_x+16, "          #                ");
	mvaddstr(g_y+6,g_x+16, "          #                ");
	mvaddstr(g_y+7,g_x+16, "          #                ");
	mvaddstr(g_y+8,g_x+16, "          #                ");
	mvaddstr(g_y+9,g_x+16, "          #                ");
	mvaddstr(g_y+10,g_x+16,"###########                ");
	mvaddstr(g_y+11,g_x+16,"          #                ");
	mvaddstr(g_y+12,g_x+16,"          #                ");
	mvaddstr(g_y+13,g_x+16,"          #                ");
	mvaddstr(g_y+14,g_x+16,"          #                ");
}

void saveG(){
	mvaddstr(g_y+7,g_x+12, "#####################");
	mvaddstr(g_y+8,g_x+12, "#                   #");
	mvaddstr(g_y+9,g_x+12, "#####################");
}

void saveG2(){
	mvaddstr(g_y+7,g_x+16, "############");
	mvaddstr(g_y+8,g_x+16, "#          #");
	mvaddstr(g_y+9,g_x+16, "#          #");
	mvaddstr(g_y+10,g_x+16,"#          #");
	mvaddstr(g_y+11,g_x+16,"############");
}

void DOOR(){
	mvaddstr(g_y+5,g_x+16, " __________");
	mvaddstr(g_y+6,g_x+16, "|          |");
	mvaddstr(g_y+7,g_x+16, "|          |");
	mvaddstr(g_y+8,g_x+16, "|          |");
	mvaddstr(g_y+9,g_x+16, "| O        |");
	mvaddstr(g_y+10,g_x+16,"|          |");
	mvaddstr(g_y+11,g_x+16,"|          |");
	mvaddstr(g_y+12,g_x+16,"|          |");
}

void Top_G(){
	mvaddstr(g_y,g_x,   "############################################");
	mvaddstr(g_y+1,g_x, "#                #                         #");
	mvaddstr(g_y+2,g_x, "#                #                         #");
	mvaddstr(g_y+3,g_x, "#                #                         #");
	mvaddstr(g_y+4,g_x, "#                #                         #");
	mvaddstr(g_y+5,g_x, "#                #                         #");
	mvaddstr(g_y+6,g_x, "#                #                         #");
	mvaddstr(g_y+7,g_x, "#                #                         #");
	mvaddstr(g_y+8,g_x, "#                #                         #");
	mvaddstr(g_y+9,g_x, "#                #                         #");
	mvaddstr(g_y+10,g_x,"#                #                         #");
	mvaddstr(g_y+11,g_x,"#                #                         #");
	mvaddstr(g_y+12,g_x,"#                #                         #");
	mvaddstr(g_y+13,g_x,"#                #                         #");
	mvaddstr(g_y+14,g_x,"#                #                         #");
	mvaddstr(g_y+15,g_x,"#                #                         #");
	mvaddstr(g_y+16,g_x,"#                #                         #");
	mvaddstr(g_y+17,g_x,"############################################");
}

void SCANMAP(){
	int i,j;
	char ch;

	NOWMAP = ma[me->me_kaisou].floor;
	for(i = 0; i < MAPY; i++){
		for(j = 0; j < MAPX; j++){
			if(*(NOWMAP[i]+j) == 1){
				ch = '#';
			}else if(*(NOWMAP[i]+j) == 0){
				ch = ' ';
			}
			mvaddch(SCANMAPY+i,SCANMAPX+(j*2),ch);
		}
	}
	/* mvaddstr(30,15,"# # # # # # # # # #"); */
	/* mvaddstr(31,15,"#                 #"); */
	/* mvaddstr(32,15,"#   #             #"); */
	/* mvaddstr(33,15,"#   # #       #   #"); */
	/* mvaddstr(34,15,"#   # #       # # #"); */
	/* mvaddstr(35,15,"#                 #"); */
	/* mvaddstr(36,15,"#   # # # # # #   #"); */
	/* mvaddstr(37,15,"#           # #   #"); */
	/* mvaddstr(38,15,"#           # #   #"); */
	/* mvaddstr(39,15,"# # # # # # # # # #"); */
}

void haiti(){
	ma[1].floor = map1;
	ma[1].downstair[0][0] = 18;
	ma[1].downstair[0][1] = 18;
	ma[2].floor = map2;
	ma[2].upstair[0][0] = 18;
	ma[2].upstair[0][1] = 18;
	ma[2].downstair[0][0] = 1;
	ma[2].downstair[0][1] = 1;
	ma[2].downstair[1][0] = 1;
	ma[2].downstair[1][1] = 18;
	ma[2].tobira[0][0] = 3;
	ma[2].tobira[0][1] = 4;
	ma[3].floor = map3;
	ma[3].upstair[0][0] = 1;
	ma[3].upstair[0][1] = 1;
	ma[3].upstair[1][0] = 1;
	ma[3].upstair[1][1] = 18;
	ma[3].downstair[0][0] = 18;
	ma[3].downstair[0][1] = 18;
	ma[3].boss[0] = 5;
	ma[3].boss[1] = 4;
	ma[4].floor = map4;
	ma[4].upstair[0][0] = 18;
	ma[4].upstair[0][1] = 18;

}

void syoki_state(){

	int i;
	me = (struct ME *)malloc(sizeof(struct ME));

	for(i = 0; i < 101; i++) me->join_monster_num[i] = 0;
	for(i = 0; i < 12; i++) strcpy(pa[i].pt_name,"noname");
	for(i = 0; i < 111; i++){
		pa[1].encount_num[i] = 0;
		pa[2].encount_num[i] = 0;
		pa[3].encount_num[i] = 0;
	}


	nakamanokazu = 3;
	ptninzuu = 3;
	sonzai = 3;
	strcpy(pa[1].pt_name,"itsuki");
	pa[1].pt_synumber = 1;
	pa[1].syoku[pa[1].pt_synumber] = sy[pa[1].pt_synumber];
	pa[1].pt_level = 1;
	pa[1].pt_hp = 5;
	pa[1].pt_nowhp = pa[1].pt_hp;
	pa[1].pt_sp = 5;
	pa[1].pt_nowsp = pa[1].pt_sp;
	pa[1].pt_power = 5;
	pa[1].pt_defence = 5;
	pa[1].pt_skill = 3;
	pa[1].pt_speed = 5;
	pa[1].pt_keiken = 1;
	pa[1].pt_exsist = 1;
	strcpy(pa[2].pt_name,"gilty");
	pa[2].pt_synumber = 2;
	pa[2].syoku[pa[2].pt_synumber] = sy[pa[2].pt_synumber];
	pa[2].pt_level = 1;
	pa[2].pt_hp = 6;
	pa[2].pt_nowhp = pa[2].pt_hp;
	pa[2].pt_sp = 5;
	pa[2].pt_nowsp = pa[2].pt_sp;
	pa[2].pt_power = 4;
	pa[2].pt_defence = 3;
	pa[2].pt_skill = 4;
	pa[2].pt_speed = 7;
	pa[2].pt_keiken = 1;
	pa[2].pt_exsist = 1;
	strcpy(pa[3].pt_name,"gordon");
	pa[3].pt_synumber = 3;
	pa[3].syoku[pa[3].pt_synumber] = sy[pa[3].pt_synumber];
	pa[3].pt_level = 1;
	pa[3].pt_hp = 10;
	pa[3].pt_nowhp = pa[3].pt_hp;
	pa[3].pt_sp = 3;
	pa[3].pt_nowsp = pa[3].pt_sp;
	pa[3].pt_power = 7;
	pa[3].pt_defence = 7;
	pa[3].pt_skill = 2;
	pa[3].pt_speed = 2;
	pa[3].pt_keiken = 1;
	pa[3].pt_exsist = 1;
	

}

void syoku_state(){

	sy[1].syokugyo = 1;
	strcpy(sy[1].s_name,"wizard");
	sy[1].s_level = 1;
	sy[2].syokugyo = 2;
	strcpy(sy[2].s_name,"shief");
	sy[2].s_level = 1;
	sy[3].syokugyo = 3;
	strcpy(sy[3].s_name,"fighter");
	sy[3].s_level = 1;
	sy[10].syokugyo = 10;
	strcpy(sy[10].s_name,"monster");
	sy[10].s_level = 1;
	sy[11].syokugyo = 11;
	strcpy(sy[11].s_name,"ADEAMON");
	sy[11].s_level = 1;
	sy[12].syokugyo = 12;
	strcpy(sy[12].s_name,"slyme");
	sy[12].s_level = 1;
	sy[13].syokugyo = 13;
	strcpy(sy[13].s_name,"m-human");
	sy[13].s_level = 1;
	sy[109].syokugyo = 109;
	strcpy(sy[109].s_name,"EXPfeve");
	sy[109].s_level = 1;
	sy[110].syokugyo = 110;
	strcpy(sy[110].s_name,"G-DORA");
	sy[110].s_level = 1;

}

void skilltree(){

	strcpy(sy[1].skill[1].sk_name,"recover");
	sy[1].skill[1].sk_power = 30;
	sy[1].skill[1].consume_sp = 3;
	sy[1].skill[1].use = 1;
	sy[1].skill[1].effect_state = 0;
	sy[1].skill[1].all = 0;
	sy[1].skill[1].eorp = 1;
	strcpy(sy[1].skill[2].sk_name,"fire");
	sy[1].skill[2].sk_power = 20;
	sy[1].skill[2].consume_sp = 5;
	sy[1].skill[2].use = 0;
	sy[1].skill[2].all = 0;
	sy[1].skill[2].eorp = 0;
	strcpy(sy[1].skill[3].sk_name,"megafire");
	sy[1].skill[3].sk_power = 50;
	sy[1].skill[3].consume_sp = 10;
	sy[1].skill[3].use = 0;
	sy[1].skill[3].all = 1;
	sy[1].skill[3].eorp = 0;
	strcpy(sy[2].skill[1].sk_name,"upattack");
	sy[2].skill[1].sk_power = 10;
	sy[2].skill[1].consume_sp = 2;
	sy[2].skill[1].use = 1;
	sy[2].skill[1].all = 0;
	sy[2].skill[1].eorp = 0;
	strcpy(sy[2].skill[2].sk_name,"Sdance");
	sy[2].skill[2].sk_power = 8;
	sy[2].skill[2].consume_sp = 3;
	sy[2].skill[2].use = 0;
	sy[2].skill[2].effect_state = 4;
	sy[2].skill[2].all = 1;
	sy[2].skill[2].eorp = 1;
	strcpy(sy[2].skill[3].sk_name,"superfly");
	sy[2].skill[3].sk_power = 60;
	sy[2].skill[3].consume_sp = 12;
	sy[2].skill[3].use = 0;
	sy[2].skill[3].all = 0;
	sy[2].skill[3].eorp = 0;
	strcpy(sy[2].skill[4].sk_name,"monstole");
	sy[2].skill[4].sk_power = 3;
	sy[2].skill[4].consume_sp = 10;
	sy[2].skill[4].use = 0;
	sy[2].skill[4].effect_state = 5;
	sy[2].skill[4].all = 0;
	sy[2].skill[4].eorp = 0;
	strcpy(sy[3].skill[1].sk_name,"stone");
	sy[3].skill[1].sk_power = 5;
	sy[3].skill[1].consume_sp = 2;
	sy[3].skill[1].use = 1;
	sy[3].skill[1].effect_state = 2;
	sy[3].skill[1].all = 0;
	sy[3].skill[1].eorp = 1;
	strcpy(sy[3].skill[2].sk_name,"scheme");
	sy[3].skill[2].sk_power = 0;
	sy[3].skill[2].consume_sp = 3;
	sy[3].skill[2].use = 0;
	sy[3].skill[2].all = 0;
	sy[3].skill[2].eorp = 0;
	strcpy(sy[3].skill[3].sk_name,"strongT");
	sy[3].skill[3].sk_power = 100;
	sy[3].skill[3].consume_sp = 10;
	sy[3].skill[3].use = 0;
	sy[3].skill[3].all = 0;
	sy[3].skill[3].eorp = 0;
	strcpy(sy[11].skill[1].sk_name,"Dark");
	sy[11].skill[1].sk_power = 6;
	sy[11].skill[1].consume_sp = 3;
	sy[11].skill[1].use = 1;
	sy[11].skill[1].all = 1;
	sy[11].skill[1].eorp = 0;
	strcpy(sy[11].skill[2].sk_name,"demonS");
	sy[11].skill[2].sk_power = 20;
	sy[11].skill[2].consume_sp = 6;
	sy[11].skill[2].use = 0;
	sy[11].skill[2].all = 0;
	sy[11].skill[2].eorp = 0;
	strcpy(sy[11].skill[3].sk_name,"Skiller");
	sy[11].skill[3].sk_power = 20;
	sy[11].skill[3].consume_sp = 6;
	sy[11].skill[3].use = 0;
	sy[11].skill[3].effect_state = 3;
	sy[11].skill[3].all = 0;
	sy[11].skill[3].eorp = 1;
	strcpy(sy[11].skill[4].sk_name,"inDark");
	sy[11].skill[4].sk_power = 100;
	sy[11].skill[4].consume_sp = 15;
	sy[11].skill[4].use = 0;
	sy[11].skill[4].all = 0;
	sy[11].skill[4].eorp = 0;
	strcpy(sy[11].skill[5].sk_name,"KILLALL");
	sy[11].skill[5].sk_power = 360;
	sy[11].skill[5].consume_sp = 40;
	sy[11].skill[5].use = 0;
	sy[11].skill[5].all = 1;
	sy[11].skill[5].eorp = 0;
	sy[12].skill[1] = sy[1].skill[1];
	strcpy(sy[12].skill[2].sk_name,"slash");
	sy[12].skill[2].sk_power = 40;
	sy[12].skill[2].consume_sp = 5;
	sy[12].skill[2].use = 0;
	sy[12].skill[2].all = 0;
	sy[12].skill[2].eorp = 0;
	strcpy(sy[12].skill[3].sk_name,"Point");
	sy[12].skill[3].sk_power = 99;
	sy[12].skill[3].consume_sp = 12;
	sy[12].skill[3].use = 0;
	sy[12].skill[3].all = 0;
	sy[12].skill[3].eorp = 0;
	strcpy(sy[12].skill[4].sk_name,"M-Recover");
	sy[12].skill[4].sk_power = 100;
	sy[12].skill[4].consume_sp = 15;
	sy[12].skill[4].use = 0;
	sy[12].skill[4].effect_state = 0;
	sy[12].skill[4].all = 1;
	sy[12].skill[4].eorp = 1;
	/* strcpy(sy[12].skill[5].sk_name,""); */
	/* sy[12].skill[5].sk_power = ; */
	/* sy[12].skill[5].consume_sp = ; */
	/* sy[12].skill[5].use = 0; */
	/* sy[12].skill[5].all = 0; */
	/* sy[12].skill[5].eorp = 0; */
	sy[13].skill[1] = sy[2].skill[2];
	strcpy(sy[13].skill[2].sk_name,"demonS");
	sy[13].skill[2].sk_power = 20;
	sy[13].skill[2].consume_sp = 6;
	sy[13].skill[2].use = 0;
	sy[13].skill[2].all = 0;
	sy[13].skill[2].eorp = 0;
	strcpy(sy[13].skill[3].sk_name,"Skiller");
	sy[13].skill[3].sk_power = 20;
	sy[13].skill[3].consume_sp = 6;
	sy[13].skill[3].use = 0;
	sy[13].skill[3].effect_state = 3;
	sy[13].skill[3].all = 0;
	sy[13].skill[3].eorp = 1;
	strcpy(sy[13].skill[4].sk_name,"inDark");
	sy[13].skill[4].sk_power = 100;
	sy[13].skill[4].consume_sp = 15;
	sy[13].skill[4].use = 0;
	sy[13].skill[4].all = 0;
	sy[13].skill[4].eorp = 0;
	strcpy(sy[13].skill[5].sk_name,"KILLALL");
	sy[13].skill[5].sk_power = 360;
	sy[13].skill[5].consume_sp = 40;
	sy[13].skill[5].use = 0;
	sy[13].skill[5].all = 1;
	sy[13].skill[5].eorp = 0;

	strcpy(sy[110].skill[1].sk_name,"G.Breath");
	sy[110].skill[1].sk_power = 40;
	sy[110].skill[1].consume_sp = 6;
	sy[110].skill[1].use = 1;
	sy[110].skill[1].all = 1;
	sy[110].skill[1].eorp = 0;
	strcpy(sy[110].skill[2].sk_name,"metro");
	sy[110].skill[2].sk_power = 110;
	sy[110].skill[2].consume_sp = 12;
	sy[110].skill[2].use = 0;
	sy[110].skill[2].all = 0;
	sy[110].skill[2].eorp = 0;
	strcpy(sy[110].skill[3].sk_name,"Wing up");
	sy[110].skill[3].sk_power = 30;
	sy[110].skill[3].consume_sp = 6;
	sy[110].skill[3].use = 0;
	sy[110].skill[3].effect_state = 4;
	sy[110].skill[3].all = 0;
	sy[110].skill[3].eorp = 1;
	strcpy(sy[110].skill[4].sk_name,"KingofG");
	sy[110].skill[4].sk_power = 200;
	sy[110].skill[4].consume_sp = 20;
	sy[110].skill[4].use = 0;
	sy[110].skill[4].all = 1;
	sy[110].skill[4].eorp = 0;



}

void syoku_up(int uh,int usp,int up,int ud,int uskl,int uspd,int level){

	int i;
	int temp;

	if(level <= 10){
	ss[1].s_uhp = uh%3+2;
	ss[1].s_usp = usp%4+10;
	ss[1].s_upower = up%4+1;
	ss[1].s_udefence = ud%4+1;
	ss[1].s_uskill = uskl%4+6;
	ss[1].s_uspeed = uspd%5;

	ss[2].s_uhp = uh%5+2;
	ss[2].s_usp = usp%8+1;
	ss[2].s_upower = up%6+1;
	ss[2].s_udefence = ud%3;
	ss[2].s_uskill = uskl%4+1;
	ss[2].s_uspeed = uspd%3+7;

	ss[3].s_uhp = uh%2+8;
	ss[3].s_usp = usp%6+1;
	ss[3].s_upower = up%3+8;
	ss[3].s_udefence = ud%3+8;
	ss[3].s_uskill = uskl%2;
	ss[3].s_uspeed = uspd%2;

	ss[11].s_uhp = uh%8+1;
	ss[11].s_usp = usp%10+2;
	ss[11].s_upower = up%7+1;
	ss[11].s_udefence = ud%3+1;
	ss[11].s_uskill = uskl%4+1;
	ss[11].s_uspeed = uspd%4+1;

	ss[12].s_uhp = uh%11+1;
	ss[12].s_usp = usp%5+1;
	ss[12].s_upower = up%6+1;
	ss[12].s_udefence = ud%5+1;
	ss[12].s_uskill = uskl%3+1;
	ss[12].s_uspeed = uspd%3;

	ss[13].s_uhp = uh%7+2;
	ss[13].s_usp = usp%10+2;
	ss[13].s_upower = up%5+1;
	ss[13].s_udefence = ud%5;
	ss[13].s_uskill = uskl%7+1;
	ss[13].s_uspeed = uspd%8+2;

	ss[109].s_uhp = uh%1+2;
	ss[109].s_usp = usp%2+12;
	ss[109].s_upower = up%3+1;
	ss[109].s_udefence = ud%5+20;
	ss[109].s_uskill = uskl%5+14;
	ss[109].s_uspeed = uspd%5+20;

	ss[110].s_uhp = uh%2+5;
	ss[110].s_usp = usp%3+6;
	ss[110].s_upower = up%2+6;
	ss[110].s_udefence = ud%2+6;
	ss[110].s_uskill = uskl%3+7;
	ss[110].s_uspeed = uspd%2+3;

	}else if(level > 10 && level <= 20){
	ss[1].s_uhp = uh%5;
	ss[1].s_usp = usp%4+14;
	ss[1].s_upower = up%4+2;
	ss[1].s_udefence = ud%4+1;
	ss[1].s_uskill = uskl%5+8;
	ss[1].s_uspeed = uspd%5+2;

	ss[2].s_uhp = uh%5;
	ss[2].s_usp = usp%3+4;
	ss[2].s_upower = up%5+2;
	ss[2].s_udefence = ud%4+1;
	ss[2].s_uskill = uskl%4+5;
	ss[2].s_uspeed = uspd%4+9;

	ss[3].s_uhp = uh%6+1;
	ss[3].s_usp = usp%3+1;
	ss[3].s_upower = up%6+2;
	ss[3].s_udefence = ud%6+2;
	ss[3].s_uskill = uskl%2+1;
	ss[3].s_uspeed = uspd%2+1;

	ss[11].s_uhp = uh%4;
	ss[11].s_usp = usp%8;
	ss[11].s_upower = up%3;
	ss[11].s_udefence = ud%4;
	ss[11].s_uskill = uskl%5;
	ss[11].s_uspeed = uspd%4;

	ss[12].s_uhp = uh%5;
	ss[12].s_usp = usp%10;
	ss[12].s_upower = up%6;
	ss[12].s_udefence = ud%5+1;
	ss[12].s_uskill = uskl%4+1;
	ss[12].s_uspeed = uspd%4;

	ss[13].s_uhp = uh%10+1;
	ss[13].s_usp = usp%7+1;
	ss[13].s_upower = up%7+1;
	ss[13].s_udefence = ud%7;
	ss[13].s_uskill = uskl%7+1;
	ss[13].s_uspeed = uspd%6+1;

	ss[109].s_uhp = uh%4;
	ss[109].s_usp = usp%2+14;
	ss[109].s_upower = up%4+1;
	ss[109].s_udefence = ud%4+18;
	ss[109].s_uskill = uskl%4+18;
	ss[109].s_uspeed = uspd%4+22;

	ss[110].s_uhp = uh%9+10;
	ss[110].s_usp = usp%5+10;
	ss[110].s_upower = up%3+14;
	ss[110].s_udefence = ud%5+12;
	ss[110].s_uskill = uskl%5+4;
	ss[110].s_uspeed = uspd%4+2;

	}else{
	ss[1].s_uhp = uh%4;
	ss[1].s_usp = usp%3+6;
	ss[1].s_upower = up%4;
	ss[1].s_udefence = ud%4;
	ss[1].s_uskill = uskl%3+8;
	ss[1].s_uspeed = uspd%5;

	ss[2].s_uhp = uh%5;
	ss[2].s_usp = usp%4+1;
	ss[2].s_upower = up%4;
	ss[2].s_udefence = ud%3;
	ss[2].s_uskill = uskl%4+1;
	ss[2].s_uspeed = uspd%3+10;

	ss[3].s_uhp = uh%3+1;
	ss[3].s_usp = usp%2+1;
	ss[3].s_upower = up%5+1;
	ss[3].s_udefence = ud%4+1;
	ss[3].s_uskill = uskl%3+1;
	ss[3].s_uspeed = uspd%2+1;

	ss[11].s_uhp = uh%3;
	ss[11].s_usp = usp%5+1;
	ss[11].s_upower = up%3;
	ss[11].s_udefence = ud%3;
	ss[11].s_uskill = uskl%3;
	ss[11].s_uspeed = uspd%3;

	ss[12].s_uhp = uh%3+1;
	ss[12].s_usp = usp%4+1;
	ss[12].s_upower = up%3;
	ss[12].s_udefence = ud%5;
	ss[12].s_uskill = uskl%4;
	ss[12].s_uspeed = uspd%6;

	ss[13].s_uhp = uh%4+1;
	ss[13].s_usp = usp%5+1;
	ss[13].s_upower = up%4+1;
	ss[13].s_udefence = ud%6;
	ss[13].s_uskill = uskl%7+1;
	ss[13].s_uspeed = uspd%4+1;

	ss[109].s_uhp = uh%3+1;
	ss[109].s_usp = usp%3+10;
	ss[109].s_upower = up%2+6;
	ss[109].s_udefence = ud%3+10;
	ss[109].s_uskill = uskl%3+10;
	ss[109].s_uspeed = uspd%3+10;

	ss[110].s_uhp = uh%2+12;
	ss[110].s_usp = usp%5+8;
	ss[110].s_upower = up%5+11;
	ss[110].s_udefence = ud%4+11;
	ss[110].s_uskill = uskl%4+5;
	ss[110].s_uspeed = uspd%5+3;

	}

}

int SAVE(){
	int i;
	int exit = 0;
	char ch;
	char datastr[20],str[20];
	int cursolx = g_x+18;
	int cursoly = g_y+8;

	saveG2();
	mvaddstr(g_y+8,g_y+20,"save1");
	mvaddstr(g_y+9,g_y+20,"save2");
	mvaddstr(g_y+10,g_y+20,"save3");

	while((ch = getch()) != ' '){
		switch(ch){
			case 'j':
				mvaddch(cursoly,cursolx,' ');
				if(cursoly < g_y+10) cursoly++;
				break;
			case 'f':
				mvaddch(cursoly,cursolx,' ');
				if(cursoly > g_y+8) cursoly--;
				break;
		}
		if(ch == 'q'){
			exit = 1;
			break;
		}
		mvaddch(cursoly,cursolx,'>');
	}

	if(exit != 1){
		switch(cursoly){
			case g_y+8:
				strcpy(datastr,"savedata1.dat");
				break;
			case g_y+9:
				strcpy(datastr,"savedata2.dat");
				break;
			case g_y+10:
				strcpy(datastr,"savedata3.dat");
				break;
		}
	

	for(i = 0; i < 12; i++) DATA.spa[i] = pa[i];
	DATA.sme[0] = *me;
	DATA.ska = ka;
	DATA.savenakama = nakamanokazu;


	FILE *fp = fopen( datastr, "wb" );//バイナリファイルを開く
	if( fp == NULL ){//エラーが起きたらNULLを返す
		return 0;
	}
	fwrite( &DATA, sizeof(DATA), 1, fp ); // SaveData_t構造体の中身を出力
	fclose( fp );//ファイルを閉じる
	
	saveG();
	mvaddstr(g_y+8,g_y+15,"save complete!");
	while((ch = getch()) != ' ') ;
	}
	TOP();
	return 0;
}

int LOAD(){
	int i;
	int exit = 0;
	char ch;
	char datastr[20],str[20];
	int cursolx = g_x+18;
	int cursoly = g_x+8;

	me = (struct ME *)malloc(sizeof(struct ME));

	saveG2();
	mvaddstr(g_y+8,g_y+20,"load1");
	mvaddstr(g_y+9,g_y+20,"load2");
	mvaddstr(g_y+10,g_y+20,"load3");

	while((ch = getch()) != ' '){
		switch(ch){
			case 'j':
				mvaddch(cursoly,cursolx,' ');
				if(cursoly < g_y+10) cursoly++;
				break;
			case 'f':
				mvaddch(cursoly,cursolx,' ');
				if(cursoly > g_y+8) cursoly--;
				break;
		}
		if(ch == 'q'){
			exit = 1;
			break;
		}
		mvaddch(cursoly,cursolx,'>');
	}

	if(exit != 1){
		switch(cursoly){
			case g_y+8:
				strcpy(datastr,"savedata1.dat");
				break;
			case g_y+9:
				strcpy(datastr,"savedata2.dat");
				break;
			case g_y+10:
				strcpy(datastr,"savedata3.dat");
				break;
		}

	FILE *fp = fopen( datastr, "rb" );
	if( fp == NULL ){
		return 0;
	}
	fread( &DATA, sizeof(DATA), 1, fp );

	for(i = 0; i < 12; i++) pa[i] = DATA.spa[i];
	*me = DATA.sme[0];
	ka = DATA.ska;
	nakamanokazu = DATA.savenakama;
	fclose( fp );

	saveG();
	mvaddstr(g_y+8,g_y+15,"load complete!");
	while((ch = getch()) != ' ') ;
	}
	TOP();
	return 0;
}

void genzaiti(){
	switch(me->muki){
		case 0:
			mvaddch(SCANMAPY+me->me_y,SCANMAPX+(me->me_x*2),'A');
			break;
		case 1:
			mvaddch(SCANMAPY+me->me_y,SCANMAPX+(me->me_x*2),'>');
			break;
		case 2:
			mvaddch(SCANMAPY+me->me_y,SCANMAPX+(me->me_x*2),'V');
			break;
		case 3:
			mvaddch(SCANMAPY+me->me_y,SCANMAPX+(me->me_x*2),'<');
			break;
	}	
}

void TOP(){

	int exit = 0;
	int cursoly,cursolx;
	char str[20];
	char ch;

	Top_G();
	flag = 0;
	cursoly = g_y+2;
	cursolx = g_x+3;
	mvaddch(cursoly,cursolx,'>');
	mvaddstr(g_y+2,g_x+4,"KINGDAM");
	mvaddstr(g_y+3,g_x+4,"PUB");
	mvaddstr(g_y+4,g_x+4,"SHOP");
	mvaddstr(g_y+5,g_x+4,"INSTITUTION");
	mvaddstr(g_y+6,g_x+4,"MONSTERHOUSE");
	mvaddstr(g_y+7,g_x+4,"DUNGEON");
	mvaddstr(g_y+8,g_x+4,"SAVE");
	mvaddstr(g_y+9,g_x+4,"LOAD");
	mvaddstr(g_y+10,g_x+4,"EXIT");

	while((ch = getch()) != ' '){
		switch(ch){
			case 'j':
				mvaddch(cursoly,cursolx,' ');
				if(cursoly < g_y+10) cursoly++;
				mvaddch(cursoly,cursolx,'>');
				break;
			case 'f':
				mvaddch(cursoly,cursolx,' ');
				if(cursoly > g_y+2) cursoly--;
				mvaddch(cursoly,cursolx,'>');
				break;
		}
		if(ch == 'q'){
			exit = 1;
			break;
		}
	}

	if(exit != 1){
		switch(cursoly){
			case g_y+2:
				break;
			case g_y+3:
				break;
			case g_y+4:
				break;
			case g_y+5:
				break;
			case g_y+6:
				MONSTERHOUSE();
				break;
			case g_y+7:
				run();
				break;
			case g_y+8:
				SAVE();
				break;
			case g_y+9:
				LOAD();
				break;
			case g_y+10:
				break;
		}
	}
}

void MONSTERHOUSE(){
	char ch;
	int cursolx,cursoly;
	int exit = 0;

	cursoly = g_y+6;
	cursolx = g_x+3;
	SG();
	PARTY_STATE();
	mvaddch(cursoly,cursolx,'>');
	mvaddstr(g_y+6,g_x+4,"Party");
	mvaddstr(g_y+7,g_x+4,"Monster");
	mvaddstr(g_y+8,g_x+4,"Rebirth");
	mvaddstr(g_y+9,g_x+4,"Leave");
	mvaddstr(g_y+10,g_x+4,"Exit");

	while((ch = getch()) != ' '){
		switch(ch){
			case 'j':
				mvaddch(cursoly,cursolx,' ');
				if(cursoly < g_y+10) cursoly++;
				mvaddch(cursoly,cursolx,'>');
				break;
			case 'f':
				mvaddch(cursoly,cursolx,' ');
				if(cursoly > g_y+6) cursoly--;
				mvaddch(cursoly,cursolx,'>');
				break;
		}
		if(ch == 'q'){
			exit = 1;
			break;
		}
	}

	if(exit != 1){
		switch(cursoly){
			case g_y+6:
				party();
				break;
			case g_y+7:
				SUB();
				break;
			case g_y+8:
				break;
			case g_y+9:
				leave_party();
				break;
			case g_y+10:
				break;
		}
	}
}

void run(){
	char ch;
	int randam1;
	int i;
	int knumber;
	
	me = (struct ME *)malloc(sizeof(struct ME));
	haiti();
	me->muki = 1;
	me->me_y = 1;
	me->me_x = 1;
	me->me_kaisou = 1;
	ka.kaidan = me->me_kaisou;
	ka.dtou = 0;
	ka.utod = 0;

	srand((unsigned)time(NULL));
	/* mvaddch(30+me->me_y,15+(me->me_x*2),'A'); */
	
	while((ch = getch()) != 'q'){
		
	NOWMAP = ma[me->me_kaisou].floor;
	/* SCANMAP(); */
	/* genzaiti(); */
		switch(ch){
			case 'j':
				mvaddch(30+me->me_y,15+(me->me_x*2),' ');
				me->muki++;
				if(me->muki > 3) me->muki = 0;
				break;
			case 'b':
				mvaddch(30+me->me_y,15+(me->me_x*2),' ');
				me->muki++;
				if(me->muki > 3) me->muki = 0;
				me->muki++;
				if(me->muki > 3) me->muki = 0;
				break;
			case 'f':
				mvaddch(30+me->me_y,15+(me->me_x*2),' ');
				me->muki--;
				if(me->muki < 0) me->muki = 3;
				break;
			case ' ':
				randam1 = rand()%30;
				switch(me->muki){
					case 0:
						mvaddch(30+me->me_y,15+(me->me_x*2),' ');
						if(*(NOWMAP[me->me_y-1]+me->me_x) != 1){
							me->me_y--;
							if(randam1 < 3) battle = 1;
						}
						/* mvaddch(30+me->me_y,15+(me->me_x*2),'A'); */
						break;
					case 1:
						mvaddch(30+me->me_y,15+(me->me_x*2),' ');
						if(*(NOWMAP[me->me_y]+me->me_x+1) != 1){
							me->me_x++;
							if(randam1 < 3) battle = 1;
						}
						/* mvaddch(30+me->me_y,15+(me->me_x*2),'>'); */
						break;
					case 2:
						mvaddch(30+me->me_y,15+(me->me_x*2),' ');
						if(*(NOWMAP[me->me_y+1]+me->me_x) != 1){
							me->me_y++;
							if(randam1 < 3) battle = 1;
						}
						/* mvaddch(30+me->me_y,15+(me->me_x*2),'V'); */
						break;
					case 3:
						mvaddch(30+me->me_y,15+(me->me_x*2),' ');
						if(*(NOWMAP[me->me_y]+me->me_x-1) != 1){
							me->me_x--;
							if(randam1 < 3) battle = 1;
						}
						/* mvaddch(30+me->me_y,15+(me->me_x*2),'<'); */
						break;
				}
				break;
			case 'd':
				sprintf(str1,"sayu = %2d",sayu);
				sprintf(str2,"muki_hantei = %3d",muki_hantei);
				sprintf(str3,"me->muki = %d",me->muki);
				sprintf(str4,"randam1 = %2d",randam1);
				mvaddstr(5,15,str1);
				mvaddstr(6,15,str2);
				mvaddstr(7,15,str3);
				mvaddstr(8,15,str4);
				break;
			case 's':
				State_gamen();
				break;
			case 'm':
				SCANMAP();
				genzaiti();
				break;
		}

		GAMEN();
		for(i = 0; i < 2; i++){
		if(me->me_y == ma[me->me_kaisou].downstair[i][0] && me->me_x == ma[me->me_kaisou].downstair[i][1] && ka.kaidan == me->me_kaisou){
			me->me_kaisou++;
			NOWMAP = ma[me->me_kaisou].floor;
			erase();
			GAMEN();
			/* SCANMAP(); */
			NOWMAP = ma[me->me_kaisou].floor;
			ka.kaidan = 0;
			ka.dtou = 1;
			ka.utod = 0;
			knumber = i;
			break;
		}
		if(me->me_y == ma[me->me_kaisou].upstair[i][0] && me->me_x == ma[me->me_kaisou].upstair[i][1] && ka.kaidan == me->me_kaisou){
			me->me_kaisou--;
			NOWMAP = ma[me->me_kaisou].floor;
			erase();
			GAMEN();
			/* SCANMAP(); */
			NOWMAP = ma[me->me_kaisou].floor;
			ka.kaidan = 0;
			ka.dtou = 0;
			ka.utod = 1;
			knumber = i;
			break;
		}
		}

		if((me->me_y != ma[me->me_kaisou].upstair[knumber][0] || me->me_x != ma[me->me_kaisou].upstair[knumber][1]) && ka.kaidan == 0 && ka.dtou == 1){
			ka.kaidan = me->me_kaisou;
		}else if((me->me_y != ma[me->me_kaisou].downstair[knumber][0] || me->me_x != ma[me->me_kaisou].downstair[knumber][1]) && ka.kaidan == 0 && ka.utod == 1){
			ka.kaidan = me->me_kaisou;
		}


		if(me->muki == 3 && me->me_y == ma[2].tobira[0][0] && me->me_x == ma[2].tobira[0][1]+1 && me->me_kaisou == 2){
			DOOR();
		}
		if(me->me_kaisou == 3 && me->me_y == ma[3].boss[0] && me->me_x == ma[3].boss[1]){
			fboss = 1;
			if(bosssen1 == 0) BATTLE();
			bosssen1 = 1;
		}
		if(battle == 1){
			fboss = 0;
			BATTLE();
			battle = 0;
		}


	}
}

void GAMEN(){
	switch(me->muki){
		case 0:
			sayu = (*(NOWMAP[me->me_y]+(me->me_x-1))*10)+(*(NOWMAP[me->me_y]+(me->me_x+1)));
			muki_hantei = (*(NOWMAP[me->me_y-1]+(me->me_x-1))*100)+(*(NOWMAP[me->me_y-1]+(me->me_x))*10)+(*(NOWMAP[me->me_y-1]+(me->me_x+1)));
			break;
		case 1:
			sayu = (*(NOWMAP[me->me_y-1]+(me->me_x))*10)+(*(NOWMAP[me->me_y+1]+(me->me_x)));
			muki_hantei = (*(NOWMAP[me->me_y-1]+(me->me_x+1))*100)+(*(NOWMAP[me->me_y]+(me->me_x+1))*10)+(*(NOWMAP[me->me_y+1]+(me->me_x+1)));
			break;
		case 2:
			sayu = (*(NOWMAP[me->me_y]+(me->me_x+1))*10)+(*(NOWMAP[me->me_y]+(me->me_x-1)));
			muki_hantei = (*(NOWMAP[me->me_y+1]+(me->me_x+1))*100)+(*(NOWMAP[me->me_y+1]+(me->me_x))*10)+(*(NOWMAP[me->me_y+1]+(me->me_x-1)));
			break;
		case 3:
			sayu = (*(NOWMAP[me->me_y+1]+(me->me_x))*10)+(*(NOWMAP[me->me_y-1]+(me->me_x)));
			muki_hantei = (*(NOWMAP[me->me_y+1]+(me->me_x-1))*100)+(*(NOWMAP[me->me_y]+(me->me_x-1))*10)+(*(NOWMAP[me->me_y-1]+(me->me_x-1)));
			break;
	}
	switch(muki_hantei){
		case 0://000
			G1();
			switch(sayu){
				case 0:
					break;
				case 1:
					G1_2();
					G2();
					break;
				case 10:
					G1_3();
					G3();
					break;
				case 11:
					G1_2();
					G1_3();
					G2();
					G3();
					break;
			}
			break;
		case 1://001
			G1();
			G1_5(R);
			switch(sayu){
				case 0:
					G2();
					G4_2(R);
					break;
				case 1:
					G1_2();
					break;
				case 10:
					G1_3();
					G2();
					G3();
					G4_2(R);
					break;
				case 11:
					G1_2();
					G1_3();
					G3();
					break;
			}
			break;
		case 10://010
			G1();
			G2();
			G3();
			G4();
			switch(sayu){
				case 0:
					G1_4(R);
					G1_5(L);
					break;
				case 1:
					G1_2();
					G1_5(L);
					break;
				case 10:
					G1_3();
					G1_4(R);
					break;
				case 11:
					G1_2();
					G1_3();
					break;
			}
			break;
		case 11://011
			G1();
			G4();
			switch(sayu){
				case 0:
					G1_5(L);
					G3();
					G4_2(R);
					break;
				case 1:
					G1_2();
					G1_5(L);
					G2();
					G3();
					break;
				case 10:
					G1_3();
					G3();
					G4_2(R);
					break;
				case 11:
					G1_2();
					G1_3();
					G2();
					G3();
					break;
			}
			break;
		case 100:
			G1();
			G1_4(L);
			switch(sayu){
				case 0:
					G3();
					G4_2(L);
					break;
				case 1:
					G1_2();
					G2();
					G3();
					G4_2(L);
					break;
				case 10:
					G1_3();
					break;
				case 11:
					G1_2();
					G1_3();
					G2();
					break;
			}
			break;
		case 101:
			G1();
			G1_4(L);
			G1_5(R);
			switch(sayu){
				case 0:
					G2();
					G3();
					G4_2(L);
					G4_2(R);
					break;
				case 1:
					G1_2();
					G3();
					G4_2(L);
					break;
				case 10:
					G1_3();
					G2();
					G4_2(R);
					break;
				case 11:
					G1_2();
					G1_3();
					break;
			}
			break;
		case 110:
			G1();
			G4();
			switch(sayu){
				case 0:
					G1_4(R);
					G2();
					G4_2(L);
					break;
				case 1:
					G1_2();
					G2();
					G4_2(L);
					break;
				case 10:
					G1_3();
					G1_4(R);
					G2();
					G3();
					break;
				case 11:
					G1_2();
					G1_3();
					G2();
					G3();
					break;
			}
			break;
		case 111:
			G1();
			G4();
			switch(sayu){
				case 0:
					G4_2(L);
					G4_2(R);
					break;
				case 1:
					G1_2();
					G2();
					G4_2(L);
					break;
				case 10:
					G1_3();
					G3();
					G4_2(R);
					break;
				case 11:
					G1_2();
					G1_3();
					G2();
					G3();
					break;
			}
			break;
	}
}

void BATTLE(){
	int eexsist,pexsist,i;
	int cnt = 0;
	int cancel;
	int s = 0;
	int pkazu;
	int sentou = 0;
	char ch;
	int temp = 0,temp2 = 0;
	int state = 1;
	char s1[30],s2[30],s3[30],s4[30],s5[30],s6[30],s7[30];
	char str1[20];
	int join = 0;
	int turnsuu = 0;


	for(i = 1; i <= ptninzuu; i++){
		pa[i].pluspower = 0;
		pa[i].plusdefence = 0;
		pa[i].plusskill = 0;
		pa[i].plusspeed = 0;
	}

	srand((unsigned)time(NULL));
	BG1();
	makeENEMY();
	drawENEMY();
	battlestartmes();
	BGclear1();
	BGclear2();
	BG2();
	lastnumber = 0;

	while((ch = getch()) != 'y'){
		BGclear1();
		BGclear3();
		drawENEMY();
		battlemes();
		PARTY_STATE();
		if(cnt == 0){
			if(pa[1].pt_exsist == 1){
				sprintf(str1,"%s's turn.",pa[1].pt_name);
				mvaddstr(g_y+14,g_x+19,str1);
				state = 1;
			}else if(pa[2].pt_exsist == 1){
				sprintf(str1,"%s's turn.",pa[2].pt_name);
				mvaddstr(g_y+14,g_x+19,str1);
				state = 2;
			}else if(pa[3].pt_exsist == 1){
				sprintf(str1,"%s's turn.",pa[3].pt_name);
				mvaddstr(g_y+14,g_x+19,str1);
			}
		}else if(cnt == 1){
			if(state == 1){
				if(pa[2].pt_exsist == 1){
					sprintf(str1,"%s's turn.",pa[2].pt_name);
					mvaddstr(g_y+14,g_x+19,str1);
				}else if(pa[3].pt_exsist == 1){
					sprintf(str1,"%s's turn.",pa[3].pt_name);
					mvaddstr(g_y+14,g_x+19,str1);
				}
			}else if(state == 2){
				if(pa[3].pt_exsist == 1){
					sprintf(str1,"%s's turn.",pa[3].pt_name);
					mvaddstr(g_y+14,g_x+19,str1);
				}
			}
		}else if(cnt == 2){
			if(pa[3].pt_exsist == 1){
				sprintf(str1,"%s's turn.",pa[3].pt_name);
				mvaddstr(g_y+14,g_x+19,str1);
			}
		}

		if(s == 0) pkazu = sonzai;
		if(ch == 'a'){
			for(i = 1; i <= kazu ; i++){
				sprintf(s1,"%d.level  :%3d",i,en[i].en_level);
				sprintf(s2,"%d.hp     :%3d/%3d",i,en[i].en_nowhp,en[i].en_hp);
				sprintf(s6,"%d.sp     :%3d/%3d",i,en[i].en_nowsp,en[i].en_sp);
				sprintf(s3,"%d.power  :%3d",i,en[i].en_power);
				sprintf(s4,"%d.defence:%3d",i,en[i].en_defence);
				sprintf(s7,"%d,skill  :%3d",i,en[i].en_skill);
				sprintf(s5,"%d.speed  :%3d",i,en[i].en_speed);
				mvaddstr(30+(7*(i-1)),65,s1);
				mvaddstr(31+(7*(i-1)),65,s2);
				mvaddstr(32+(7*(i-1)),65,s6);
				mvaddstr(33+(7*(i-1)),65,s3);
				mvaddstr(34+(7*(i-1)),65,s4);
				mvaddstr(35+(7*(i-1)),65,s7);
				mvaddstr(36+(7*(i-1)),65,s5);
			}
		}
		if(ch == 'z'){
			if(pkazu > 0){
				if(cnt == 0){
					if(pa[1].pt_exsist == 1){
						CHOICE(1);
					}else if(pa[2].pt_exsist == 1){
						CHOICE(2);
					}else if(pa[3].pt_exsist == 1){
						CHOICE(3);
					}
				}else if(cnt == 1){
					if(pa[2].pt_exsist == 1){
						CHOICE(2);
					}else if(pa[3].pt_exsist == 1){
						CHOICE(3);
					}
				}else if(cnt == 2){
					if(pa[3].pt_exsist == 1){
						CHOICE(3);
					}
				}
				cnt++;
				pkazu--;
				s = 1;
			}
			if(pkazu == 0){
				ATTACK();
				s = 0;
				cnt = 0;
				turnsuu++;
			}
		}
		if(ch == 'x'){
			cancel = 0;
			if(pkazu > 0){
				if(cnt == 0){
					if(pa[1].pt_exsist == 1){
						cancel = B_skill(1);
					}else if(pa[2].pt_exsist == 1){
						cancel = B_skill(2);
					}else if(pa[3].pt_exsist == 1){
						cancel = B_skill(3);
					}
				}else if(cnt == 1){
					if(pa[2].pt_exsist == 1){
						cancel = B_skill(2);
					}else if(pa[3].pt_exsist == 1){
						cancel = B_skill(3);
					}
				}else if(cnt == 2){
					if(pa[3].pt_exsist == 1){
						cancel = B_skill(3);
					}
				}
				if(cancel != 1){
					cnt++;
					pkazu--;
				}
				s = 1;
			}
			if(pkazu == 0){
				ATTACK();
				s = 0;
				cnt = 0;
				turnsuu++;
			}

		}
		for(i = 1; i <= kazu ; i++){
			temp += en[i].en_exsist;
		}
		for(i = 1; i <= ptninzuu ; i++){
			temp2 += pa[i].pt_exsist;
		}
		eexsist = temp;
		pexsist = temp2;
		if(eexsist == 0){
			if(getkeikenchi != 0){
				join = rand()%100+1;
				if(join <= en[lastnumber].en_join){
					JOIN(lastnumber);
				}else{
					for(i = 1; i <= ptninzuu; i++) pa[i].encount_num[pa[i].pt_synumber]++;
					Battle_ENDmes();
				}
			}
			for(i = 1; i <= ptninzuu; i++){
				pa[i].pt_power -= pa[i].pluspower;
				pa[i].pt_defence -= pa[i].plusdefence;
				pa[i].pt_skill -= pa[i].plusskill;
				pa[i].pt_speed -= pa[i].plusspeed;
			}
			break;
		}
		if(pexsist == 0) break;
		temp = 0;
		temp2 = 0;
	}
}

void makeENEMY(){
	int i,j;
	int syurui,level;
	int rare;

	getkeikenchi = 0;
	srand((unsigned)time(NULL));
	kazu = (rand()%3)+1;

	if(fboss == 1) kazu = 1;

	for(i = 1; i <= kazu ; i++){
		if(fboss == 0){

			rare = (rand()%20)+1;
			switch(me->me_kaisou){
				case 1:
					level = (rand()%3)+1;
					syurui = (rand()%2)+1;
					break;
				case 2:
					level = (rand()%3)+2;
					syurui = (rand()%3)+1;
					break;
				case 3:
					if(rare < 20){
						level = (rand()%3)+4;
						syurui = (rand()%2)+2;
					}else if(rare == 20){
						level = (rand()%3)+1;
						syurui = 99;
					}
					break;
				case 4:
					level = (rand()%3)+10;
					syurui = 99;
					break;
			}
		}else if(fboss == 1){
			switch(me->me_kaisou){
				case 3:
					level = (rand()%4)+10;
					syurui = 100;
					break;
			}
		}

		en[i].en_number = syurui;
		en[i].en_level = level;

		en[i].en_y = g_y+5;
		switch(kazu){
			case 1:
				en[i].en_x = g_x+21;
				break;
			case 2:
				switch(i){
					case 1:
						en[i].en_x = g_x+13;
						break;
					case 2:
						en[i].en_x = g_x+30;
						break;
				}
				break;
			case 3:
				switch(i){
					case 1:
						en[i].en_x = g_x+9;
						break;
					case 2:
						en[i].en_x = g_x+21;
						break;
					case 3:
						en[i].en_x = g_x+33;
						break;
				}

		}

		for(j = 0; j < 7; j++){
			sprintf(en[i].en_form[j]," ");
		}
		switch(en[i].en_number){
			case 1:
				en[i].en_name = (char *)malloc(sizeof("A DEAMON"));
				sprintf(en[i].en_name,"A DEAMON");
				sprintf(en[i].en_form[2],"AAA");
				sprintf(en[i].en_form[3],"AAA");
				sprintf(en[i].en_form[4],"AAA");
				en[i].en_form_len = 3;
				en[i].en_hp = 3;
				en[i].en_sp = 6;
				en[i].en_power = 3;
				en[i].en_defence = 2;
				en[i].en_skill = 5;
				en[i].en_speed = 2;
				en[i].getkeiken = 3;
				en[i].en_join = 30 - me->join_monster_num[i];
				break;
			case 2:
				en[i].en_name = (char *)malloc(sizeof("slyme"));
				sprintf(en[i].en_name,"slyme");
				sprintf(en[i].en_form[3],"  A");
				sprintf(en[i].en_form[4],"(0 0)");
				en[i].en_form_len = 5;
				en[i].en_hp = 3;
				en[i].en_sp = 5;
				en[i].en_power = 2;
				en[i].en_defence = 4;
				en[i].en_skill = 4;
				en[i].en_speed = 1;
				en[i].getkeiken = 5;
				en[i].en_join = 20 - me->join_monster_num[i];
				break;
			case 3:
				en[i].en_name = (char *)malloc(sizeof("microhuman"));
				sprintf(en[i].en_name,"microhuman");
				sprintf(en[i].en_form[2]," O");
				sprintf(en[i].en_form[3],"(|)");
				sprintf(en[i].en_form[4]," A");
				en[i].en_form_len = 3;
				en[i].en_hp = 8;
				en[i].en_sp = 7;
				en[i].en_power = 5;
				en[i].en_defence = 5;
				en[i].en_skill = 6;
				en[i].en_speed = 5;
				en[i].getkeiken = 16;
				en[i].en_join = 5 - me->join_monster_num[i];
				break;
			/* case 4: */
				/* en[i].en_name = (char *)malloc(sizeof("stonedoll")); */
				/* sprintf(en[i].en_name,"microhuman"); */
				/* sprintf(en[i].en_form[2]," /=\\"); */
				/* sprintf(en[i].en_form[3],"|▿ ▿|"); */
				/* sprintf(en[i] */
			case 99:
				en[i].en_name = (char *)malloc(sizeof("expfever"));
				sprintf(en[i].en_name,"expfever");
				sprintf(en[i].en_form[1]," ***");
				sprintf(en[i].en_form[2],"|EXP|");
				sprintf(en[i].en_form[3],"L___J");
				sprintf(en[i].en_form[4],"  |");
				sprintf(en[i].en_form[5]," ===");
				en[i].en_form_len = 5;
				en[i].en_hp = 4;
				en[i].en_sp = 100;
				en[i].en_power = 1;
				en[i].en_defence = 200;
				en[i].en_skill = 100;
				en[i].en_speed = 100;
				en[i].getkeiken = 10000;
				en[i].en_join = 3 - me->join_monster_num[i];
				break;
			case 100:
				en[i].en_name = (char *)malloc(sizeof("G-DRAGON"));
				sprintf(en[i].en_name,"G-DRAGON");
				sprintf(en[i].en_form[1]," H  H     /====");
				sprintf(en[i].en_form[2],"/ %%  L   /====");
				sprintf(en[i].en_form[3],"L  A/-  / ===");
				sprintf(en[i].en_form[4],"     V-- }");
				sprintf(en[i].en_form[5],"      L-/");
				sprintf(en[i].en_form[6],"      J/");
				en[i].en_form_len = 15;
				en[i].en_hp = 50;
				en[i].en_sp = 30;
				en[i].en_power = 20;
				en[i].en_defence = 18;
				en[i].en_skill = 20;
				en[i].en_speed = 22;
				en[i].getkeiken = 150;
				en[i].en_join = 0 - me->join_monster_num[i];;
				break;
		}
		for(j = 0; j < en[i].en_level; j++){
			switch(en[i].en_number){
				case 1:
					en[i].en_uhp = rand()%2+1;
					en[i].en_usp = rand()%4+1;
					en[i].en_upower = rand()%4;
					en[i].en_udefence = rand()%2;
					en[i].en_uskill = rand()%4+1;
					en[i].en_uspeed = rand()%2;
					en[i].ukeiken = 1;
					break;
				case 2:
					en[i].en_uhp = rand()%2+1;
					en[i].en_usp = rand()%5+1;
					en[i].en_upower = rand()%3;
					en[i].en_udefence = rand()%4;
					en[i].en_uskill = rand()%3+1;
					en[i].en_uspeed = rand()%2;
					en[i].ukeiken = 1;
					break;
				case 3:
					en[i].en_uhp = rand()%4;
					en[i].en_usp = rand()%6+1;
					en[i].en_upower = rand()%4;
					en[i].en_udefence = rand()%4;
					en[i].en_uskill = rand()&7+1;
					en[i].en_uspeed = rand()%4;
					en[i].ukeiken = 4;
					break;
				case 99:
					en[i].en_uhp = rand()%2;
					en[i].en_usp = rand()%10;
					en[i].en_upower = rand()%2;
					en[i].en_udefence = rand()%14;
					en[i].en_uspeed = rand()%14;
					en[i].ukeiken = 1000;
					break;
				case 100:
					en[i].en_uhp = rand()%10+1;
					en[i].en_usp = rand()%10+1;
					en[i].en_upower = rand()%10+1;
					en[i].en_udefence = rand()%10+1;
					en[i].en_uskill = rand()%8+1;
					en[i].en_uspeed = rand()%6+1;
					en[i].ukeiken = 60;
					break;
			}

			en[i].en_hp += en[i].en_uhp;
			en[i].en_sp += en[i].en_usp;
			en[i].en_power += en[i].en_upower;
			en[i].en_defence += en[i].en_udefence;
			en[i].en_skill += en[i].en_uskill;
			en[i].en_speed += en[i].en_uspeed;
			en[i].getkeiken += en[i].ukeiken;
		}
		en[i].en_nowhp = en[i].en_hp;
		en[i].en_nowsp = en[i].en_sp;

		en[i].en_exsist = 1;
		getkeikenchi += en[i].getkeiken;
		if(en[i].en_join < 0) en[i].en_join = 0;
	}
}


void drawENEMY(){
	int i,j;
	int cnt = 0;

	for(i = 1; i <= kazu; i++){
		if(en[i].en_nowhp <= 0) en[i].en_exsist = 0;
		if(en[i].en_exsist == 1){
			cnt++;
			for(j = 0; j < 7; j++){
				mvaddstr(en[i].en_y+j,en[i].en_x-(en[i].en_form_len/2),en[i].en_form[j]);
			}
		}
	}
	if(cnt == 1){
		for(i = 1; i <= kazu; i++){
			if(en[i].en_exsist == 1) lastnumber = i;
		}
	}
}


void battlemes(){
	mvaddstr(g_y+13,g_x+3,"z:attack");
	mvaddstr(g_y+14,g_x+3,"x:skill");
	mvaddstr(g_y+15,g_x+3,"c:defence");
}

void PARTY_STATE(){
	char str1[10],str2[8],str3[8],str4[8];
	int len;
	int i;

	for(i = 1; i <= ptninzuu; i++){
	sprintf(str1,":%s",pa[i].pt_name);
	strcpy(str2,pa[i].syoku[pa[i].pt_synumber].s_name);
	str2[2] = '\0';
	if(pa[i].pt_nowhp < 0){
		sprintf(str3,"HP:  0");
	}else{
		sprintf(str3,"HP:%3d",pa[i].pt_nowhp);
	}
	if(pa[i].pt_nowsp < 0){
		sprintf(str4,"SP:  0");
	}else{
		sprintf(str4,"SP:%3d",pa[i].pt_nowsp);
	}
	if(i == 1){
		len = 5;
	}else if(i == 2){
		len = 19;
	}else if(i == 3){
		len = 33;
	}
	mvaddstr(g_y+1,g_x+len,str2);
	mvaddstr(g_y+1,g_x+len+strlen(str2),str1);
	mvaddstr(g_y+2,g_x+len,str3);
	mvaddstr(g_y+3,g_x+len,str4);
	}
}

void battlestartmes(){
	char ch;
	int i;
	while((ch = getch()) != 'n'){
		for(i = 1; i <= kazu; i++){
			mvaddstr(g_y+12+i,g_x+4,en[i].en_name);
			mvaddstr(g_y+12+i,g_x+4+strlen(en[i].en_name)," is encounterd !");
		}
		mvaddstr(g_y+16,g_x+15,"Press 'n' key to go Next");
	}
}


void CHOICE(int ptnumber){
	char ch;
	int i,j,k;
	int i1=0,i2=0,i3=0;
	int cnt = 0;
	int y = g_y+13;
	int x = g_x+17;
	int randam_p,randam_e1,randam_e2;
	int temp;
	char str1[5],str2[5],str3[5],str4[5],str5[5],str6[5],str7[5],str8[5],str9[5],chara[5];
	srand((unsigned)time(NULL));
	randam_p = rand()%4;
	randam_e1 = rand()%4;
	randam_e2 = rand()%4;
	BGclear3();
	battlemes();

	if(pa[ptnumber].useskill == 0 || pa[ptnumber].syoku[pa[ptnumber].pt_synumber].skill[pa[ptnumber].useskill].eorp == 0){
	for(i = 1; i <= kazu; i++){
		if(en[i].en_exsist == 1){
			switch(i){
				case 1:
					i1 = 1;
					break;
				case 2:
					i2 = 1;
					break;
				case 3:
					i3 = 1;
					break;
			}
			mvaddstr(g_y+12+i,g_x+19,en[i].en_name);
		}
	}
	}else if(pa[ptnumber].syoku[pa[ptnumber].pt_synumber].skill[pa[ptnumber].useskill].eorp == 1){
	for(i = 1; i <= ptninzuu; i++){
		if(pa[i].pt_exsist == 1){
			switch(i){
				case 1:
					i1 = 1;
					break;
				case 2:
					i2 = 1;
					break;
				case 3:
					i3 = 1;
					break;
			}
			mvaddstr(g_y+12+i,g_x+19,pa[i].pt_name);
		}
	}
	}


	if(i1 == 1){
		y = g_y+13;
	}else if(i2 == 1){
		y = g_y+14;
	}else if(i3 == 1){
		y = g_y+15;
	}

	while((ch = getch()) != ' '){
		switch(ch){
			case 'j':
				mvaddch(y,x,' ');
				switch((i1*100)+(i2*10)+(i3)){
					case 100:
						break;
					case 110:
						if(y < g_y+14) y++;
						break;
					case 111:
						if(y < g_y+15) y++;
						break;
					case 101:
						if(y < g_y+15) y += 2;
						break;
					case 10://010
						break;
					case 11://011
						if(y < g_y+15) y++;
						break;
					case 1:
						break;
				}
				break;
			case 'f':
				mvaddch(y,x,' ');
				switch((i1*100)+(i2*10)+(i3)){
					case 100:
						break;
					case 110:
						if(y > g_y+13) y--;
						break;
					case 111:
						if(y > g_y+13) y--;
						break;
					case 101:
						if(y > g_y+13) y -= 2;
						break;
					case 10://010
						break;
					case 11://011
						if(y > g_y+14) y--;
						break;
					case 1:
						break;
				}
				break;
		}
		mvaddch(y,x,'>');
	}

	switch(y){
		case g_y+13:
			target[ptnumber] = 1;
			break;
		case g_y+14:
			target[ptnumber] = 2;
			break;
		case g_y+15:
			target[ptnumber] = 3;
			break;
	}

	BGclear3();
}

void ATTACK(){
	int i,j;
	int cnt = 0;
	int randam_e1,randam_e2;
	int spd[7] = {0};
	char cspd[7][3];
	int temp;
	char temp2[3];
	char str1[5],str2[5],str3[5],str4[5],str5[5],str6[5],str7[5],str8[5],str9[5],chara[5];
	srand((unsigned)time(NULL));
	randam_e1 = rand()%4;
	randam_e2 = rand()%4;

	for(i=0;i<7;i++){
		for(j=0;j<3;j++){
			cspd[i][j] = '\0';
		}
	}
	sprintf(str1,"e1:%d",randam_e1);
	sprintf(str2,"e2:%d",randam_e2);
	mvaddstr(6,60,str1);
	mvaddstr(7,60,str2);

	for(i = 1; i <= kazu; i++){
		if(en[i].en_exsist == 1){
			cnt++;
			spd[cnt] = en[i].en_speed;
			sprintf(chara,"e%d",i);
			strcpy(cspd[cnt], chara);
		}
	}
	for(i = 1; i <= ptninzuu; i++){
		if(pa[i].pt_exsist == 1){
			cnt++;
			spd[cnt] = pa[i].pt_speed;
			sprintf(chara,"p%d",i);
			strcpy(cspd[cnt], chara);
		}
	}

	cnt = 0;

	for(j = 1; j <= kazu+ptninzuu; j++){
		for(i = 1; i <= kazu+ptninzuu; i++){
			if(i == (kazu+ptninzuu)){
			}else{
				if(spd[i]+randam_e1 > spd[i+1]+randam_e2){
				}else{
					temp = spd[i];
					strcpy(temp2,cspd[i]);
					spd[i] = spd[i+1];
					strcpy(cspd[i],cspd[i+1]);
					spd[i+1] = temp;
					strcpy(cspd[i+1],temp2);
				}
			}
		}
	}
	cnt = 0;

	sprintf(str1,"%d",spd[1]);
	sprintf(str2,"%d",spd[2]);
	sprintf(str3,"%d",spd[3]);
	sprintf(str4,"%d",spd[4]);
	sprintf(str5,"%d",spd[5]);
	sprintf(str6,"%d",spd[6]);


	mvaddstr(8,64,str1);
	mvaddstr(9,64,str2);
	mvaddstr(10,64,str3);
	mvaddstr(11,64,str4);
	mvaddstr(12,64,str5);
	mvaddstr(13,64,str6);

	mvaddstr(8,60,cspd[1]);
	mvaddstr(9,60,cspd[2]);
	mvaddstr(10,60,cspd[3]);
	mvaddstr(11,60,cspd[4]);
	mvaddstr(12,60,cspd[5]);
	mvaddstr(13,60,cspd[6]);


	for(i = 1; i <= kazu+ptninzuu; i++){
		if(strcmp(cspd[i],"p1") == 0){
			if(pa[1].pt_exsist == 1) PARTY_ATTACK(1);
		}else if(strcmp(cspd[i],"p2") == 0){
			if(pa[2].pt_exsist == 1) PARTY_ATTACK(2);
		}else if(strcmp(cspd[i],"p3") == 0){
			if(pa[3].pt_exsist == 1) PARTY_ATTACK(3);
		}else if(strcmp(cspd[i],"e1") == 0){
			if(en[1].en_exsist == 1) ENEMY_ATTACK(1);
		}else if(strcmp(cspd[i],"e2") == 0){
			if(en[2].en_exsist == 1) ENEMY_ATTACK(2);
		}else if(strcmp(cspd[i],"e3") == 0){
			if(en[3].en_exsist == 1) ENEMY_ATTACK(3);
		}
	}

	for(i = 1; i <= kazu; i++){
		spd[i] = 0;
	}

	for(i = 1; i <= ptninzuu; i++){
		pa[i].useskill = 0;
	}
	BG2();
	mvaddstr(8,60,"        ");
	mvaddstr(9,60,"        ");
	mvaddstr(10,60,"        ");
	mvaddstr(11,60,"        ");
	mvaddstr(12,60,"        ");
	mvaddstr(13,60,"        ");

}


void PARTY_ATTACK(int number){
	int damege;
	int end = 0;
	int gosa;
	int critical;
	char str[5],str1[30],str2[30];
	char ch;
	int metal;

	srand((unsigned)time(NULL));
	gosa = rand()%10;
	critical = rand()%30;

	if(pa[number].syoku[pa[number].pt_synumber].skill[pa[number].useskill].all == 0){ 


		if(en[target[number]].en_nowhp <= 0 && pa[number].syoku[pa[number].pt_synumber].skill[pa[number].useskill].eorp == 0){

			BGclear2();
			while((ch = getch()) != ' '){
				mvaddstr(g_y+14,g_x+4,pa[number].pt_name);
				mvaddstr(g_y+14,g_x+4+strlen(pa[number].pt_name)," attacked.");
			}

			BGclear2();
			while((ch = getch()) != ' '){
				mvaddstr(g_y+14,g_x+4,en[target[number]].en_name);
				mvaddstr(g_y+14,g_x+4+strlen(en[target[number]].en_name)," was already died.");
			}
			end = 1;

		}else if(pa[target[number]].pt_nowhp <= 0 && pa[number].syoku[pa[number].pt_synumber].skill[pa[number].useskill].eorp == 1){

			BGclear2();
			sprintf(str,"%d",damege);
			sprintf(str1," use skill:%s",pa[number].syoku[pa[number].pt_synumber].skill[pa[number].useskill].sk_name);
			while((ch = getch()) != ' '){
				mvaddstr(g_y+14,g_x+4,pa[number].pt_name);
				mvaddstr(g_y+14,g_x+4+strlen(pa[number].pt_name),str1);
			}
			BGclear2();
			while((ch = getch()) != ' '){
				mvaddstr(g_y+14,g_x+4,pa[target[number]].pt_name);
				mvaddstr(g_y+14,g_x+4+strlen(pa[target[number]].pt_name)," was already died.");
			}
			end = 1;

		}
	}
	if(end != 1){
		if(pa[number].useskill == 0){
			if(en[target[number]].en_exsist == 0){
				BGclear2();
				while((ch = getch()) != ' '){
					mvaddstr(g_y+14,g_x+4,en[target[number]].en_name);
					mvaddstr(g_y+14,g_x+4+strlen(en[target[number]].en_name)," was already escaped");
				}
			}else{
				damege = pa[number].pt_power - en[target[number]].en_defence + gosa;
				if(damege < 0) damege = 0;
				if(critical == 0){
					damege = pa[number].pt_power * 2.5;
				}else{
					if(en[target[number]].en_number == 99){
						if(pa[number].pt_power - en[target[number]].en_defence > 100){
							damege = pa[number].pt_power - en[target[number]].en_defence;
						}else{
							metal = rand()%3;
							if(metal == 0) damege = 1;
						}
					}
				}

				BGclear2();
				sprintf(str,"%d",damege);
				while((ch = getch()) != ' '){
					mvaddstr(g_y+14,g_x+4,pa[number].pt_name);
					mvaddstr(g_y+14,g_x+4+strlen(pa[number].pt_name)," attacked.");
				}

				if(critical == 0){
					BGclear2();
					while((ch = getch()) != ' '){
						mvaddstr(g_y+14,g_x+4,"Critical Hit!");
					}
				}

				BGclear2();
				while((ch = getch()) != ' '){
					mvaddstr(g_y+14,g_x+4,en[target[number]].en_name);
					mvaddstr(g_y+14,g_x+4+strlen(en[target[number]].en_name)," was dameged:");
					mvaddstr(g_y+14,g_x+18+strlen(en[target[number]].en_name),str);
				}
				en[target[number]].en_nowhp -= damege;
			}

		}else{


			BGclear2();
			sprintf(str1," use skill:%s",pa[number].syoku[pa[number].pt_synumber].skill[pa[number].useskill].sk_name);
			while((ch = getch()) != ' '){
				mvaddstr(g_y+14,g_x+4,pa[number].pt_name);
				mvaddstr(g_y+14,g_x+4+strlen(pa[number].pt_name),str1);
			}
			BGclear2();

			if(pa[number].syoku[pa[number].pt_synumber].skill[pa[number].useskill].eorp == 0){
				if(pa[number].syoku[pa[number].pt_synumber].skill[pa[number].useskill].all == 1){
					for(target[number] = 1; target[number] <= kazu; target[number]++){

						if(en[target[number]].en_exsist == 0){
							BGclear2();
							while((ch = getch()) != ' '){
								mvaddstr(g_y+14,g_x+4,en[target[number]].en_name);
								mvaddstr(g_y+14,g_x+4+strlen(en[target[number]].en_name)," was already escaped");
							}
						}else{
							damege = pa[number].syoku[pa[number].pt_synumber].skill[pa[number].useskill].sk_power+(pa[number].pt_skill/2)-en[target[number]].en_defence-gosa;
							if(damege < 0) damege = 0;
							if(en[target[number]].en_number == 99) damege = 0;
							sprintf(str,"%d",damege);
							sprintf(str2,"was dameged:%d",damege);

							switch(pa[number].syoku[pa[number].pt_synumber].skill[pa[number].useskill].effect_state){
								case 0:
								case 1:
								case 2:
								case 3:
								case 4:
									en[target[number]].en_nowhp -= damege;
									break;
								case 5:
									damege = pa[number].syoku[pa[number].pt_synumber].skill[pa[number].useskill].sk_power+pa[number].pt_level-en[target[number]].en_level;
									if(en[target[number]].en_join > 50){
										sprintf(str2," is Max enjoyment");
									}else{
										sprintf(str2," was gratefull:+%d%%",damege);
										en[target[number]].en_join += damege;
									}
									break;
							}

							while((ch = getch()) != ' '){
								mvaddstr(g_y+14,g_x+4,en[target[number]].en_name);
								mvaddstr(g_y+14,g_x+4+strlen(en[target[number]].en_name),str2);
							}
						}
						BGclear1();
						BGclear2();
						BGclear4();
						drawENEMY();
						PARTY_STATE();

					}
				}else if(pa[number].syoku[pa[number].pt_synumber].skill[pa[number].useskill].all == 0){
					if(en[target[number]].en_exsist == 0){
						BGclear2();
						while((ch = getch()) != ' '){
							mvaddstr(g_y+14,g_x+4,en[target[number]].en_name);
							mvaddstr(g_y+14,g_x+4+strlen(en[target[number]].en_name)," was already escaped");
						}
					}else{
						damege = pa[number].syoku[pa[number].pt_synumber].skill[pa[number].useskill].sk_power+(pa[number].pt_skill/2)-en[target[number]].en_defence-gosa;
						if(damege < 0) damege = 0;
						if(en[target[number]].en_number == 99) damege = 0;
						sprintf(str,"%d",damege);
						sprintf(str2,"was dameged:%d",damege);

						switch(pa[number].syoku[pa[number].pt_synumber].skill[pa[number].useskill].effect_state){
							case 0:
							case 1:
							case 2:
							case 3:
							case 4:
								en[target[number]].en_nowhp -= damege;
								break;
							case 5:
								damege = pa[number].syoku[pa[number].pt_synumber].skill[pa[number].useskill].sk_power+pa[number].pt_level-en[target[number]].en_level;
								if(en[target[number]].en_join > 50){
									sprintf(str2," is Max enjoyment");
								}else{
									sprintf(str2," was gratefull:+%d%%",damege);
									en[target[number]].en_join += damege;
								}
								break;
						}

						while((ch = getch()) != ' '){
							mvaddstr(g_y+14,g_x+4,en[target[number]].en_name);
							mvaddstr(g_y+14,g_x+4+strlen(en[target[number]].en_name),str2);
						}
					}
				}

			}else if(pa[number].syoku[pa[number].pt_synumber].skill[pa[number].useskill].eorp == 1){
				if(pa[number].syoku[pa[number].pt_synumber].skill[pa[number].useskill].all == 1){
					for(target[number] = 1; target[number] <= ptninzuu; target[number]++){

						damege = pa[number].syoku[pa[number].pt_synumber].skill[pa[number].useskill].sk_power;
						if(damege < 0) damege = 0;
						sprintf(str,"%d",damege);

						while((ch = getch()) != ' '){
							mvaddstr(g_y+14,g_x+4,pa[target[number]].pt_name);
							mvaddstr(g_y+14,g_x+4+strlen(pa[target[number]].pt_name)," was affected:");
							mvaddstr(g_y+14,g_x+18+strlen(pa[target[number]].pt_name),str);
						}

						switch(pa[number].syoku[pa[number].pt_synumber].skill[pa[number].useskill].effect_state){
							case 0:
								pa[target[number]].pt_nowhp += damege;
								if(pa[target[number]].pt_nowhp > pa[target[number]].pt_hp) pa[target[number]].pt_nowhp = pa[target[number]].pt_hp;
								break;
							case 1:
								pa[target[number]].pt_power += damege;
								pa[target[number]].pluspower += damege;
								break;
							case 2:
								pa[target[number]].pt_defence += damege;
								pa[target[number]].plusdefence += damege;
								break;
							case 3:
								pa[target[number]].pt_skill += damege;
								pa[target[number]].plusskill += damege;
								break;
							case 4:
								pa[target[number]].pt_speed += damege;
								pa[target[number]].plusspeed += damege;
								break;
						}
						BGclear1();
						BGclear2();
						BGclear4();
						drawENEMY();
						PARTY_STATE();
					}
				}else if(pa[number].syoku[pa[number].pt_synumber].skill[pa[number].useskill].all == 0){
					damege = pa[number].syoku[pa[number].pt_synumber].skill[pa[number].useskill].sk_power;
					if(damege < 0) damege = 0;
					sprintf(str,"%d",damege);

					while((ch = getch()) != ' '){
						mvaddstr(g_y+14,g_x+4,pa[target[number]].pt_name);
						mvaddstr(g_y+14,g_x+4+strlen(pa[target[number]].pt_name)," was affected:");
						mvaddstr(g_y+14,g_x+18+strlen(pa[target[number]].pt_name),str);
					}

					switch(pa[number].syoku[pa[number].pt_synumber].skill[pa[number].useskill].effect_state){
						case 0:
							pa[target[number]].pt_nowhp += damege;
							if(pa[target[number]].pt_nowhp > pa[target[number]].pt_hp) pa[target[number]].pt_nowhp = pa[target[number]].pt_hp;
							break;
						case 1:
							pa[target[number]].pt_power += damege;
							pa[target[number]].pluspower += damege;
							break;
						case 2:
							pa[target[number]].pt_defence += damege;
							pa[target[number]].plusdefence += damege;
							break;
						case 3:
							pa[target[number]].pt_skill += damege;
							pa[target[number]].plusskill += damege;
							break;
						case 4:
							pa[target[number]].pt_speed += damege;
							pa[target[number]].plusspeed += damege;
							break;
					}
				}
			}
		}
	}
	BGclear1();
	BGclear4();
	drawENEMY();
	PARTY_STATE();
}

void ENEMY_ATTACK(int number){
	int damege;
	int gosa,i;
	int temp = 0;
	int etarget;
	int escape = 0;
	char str[5];
	char s[20];
	char ch;
	int randam;

	srand((unsigned)time(NULL));
	randam = rand()%3+1;

	if(en[number].en_number == 99){
		if(randam == 3) escape = 1;
	}

	srand((unsigned)time(NULL));
	gosa = rand()%3;
	
	if(escape == 0){
	do{
		etarget = rand()%ptninzuu+1;
		for(i = 1; i <= ptninzuu; i++){
			temp += pa[i].pt_exsist;
		}
		if(temp == 0) break;
	}while(pa[etarget].pt_exsist == 0);

	
	damege = en[number].en_power - pa[etarget].pt_defence + gosa;
	if(damege < 0) damege = 0;

	BGclear2();
	sprintf(str,"%d",damege);
	while((ch = getch()) != ' '){
		mvaddstr(g_y+14,g_x+4,en[number].en_name);
		mvaddstr(g_y+14,g_x+4+strlen(en[number].en_name)," attacked.");
	}

	BGclear2();
	while((ch = getch()) != ' '){
		mvaddstr(g_y+14,g_x+4,pa[etarget].pt_name);
		mvaddstr(g_y+14,g_x+4+strlen(pa[etarget].pt_name)," was dameged:");
		mvaddstr(g_y+14,g_x+18+strlen(pa[etarget].pt_name),str);
	}
	pa[etarget].pt_nowhp -= damege;
	}else if(escape == 1){
		BGclear2();
		sprintf(s,"%s escaped!",en[number].en_name);
		while((ch = getch()) != ' '){
			mvaddstr(g_y+14,g_x+4,s);
		}
		en[number].en_exsist = 0;
		getkeikenchi -= en[number].getkeiken;
	}
	EXSIST();
	BGclear4();
	PARTY_STATE();

}

void EXSIST(){
	int i;
	int cnt = 0;
	for(i = 1; i <= ptninzuu; i++){
		if(pa[i].pt_nowhp <= 0) pa[i].pt_exsist = 0;
		if(pa[i].pt_exsist == 1) cnt++;
	}
	sonzai = cnt;
}

void Battle_ENDmes(){
	int i;
	char ch;
	char str[50];

	sprintf(str,"PARTY gets experience point: %d",getkeikenchi);
	BGclear2();
	while((ch = getch()) != ' '){
		mvaddstr(g_y+14,g_x+4,"ENEMY died.");
		mvaddstr(g_y+15,g_x+4,str);
	}
	for(i = 1; i <= ptninzuu; i++){
		if(pa[i].pt_exsist == 1){
			pa[i].pt_keiken += getkeikenchi;
		}
	}
	Levelup();
}

void Levelup(){
	int i,j,k;
	int before,after;
	char str[50],str1[50],sh[20],ssp[20],sp[20],sd[20],sskl[20],sspd[20];
	char ch;
	int uh,usp,up,ud,uskl,uspd;
	int stateh,statesp,statep,stated,stateskl,statespd;
	srand((unsigned)time(NULL));

	for(i = 1; i <= ptninzuu; i++){
		for(j = 1; j <= 99; j++){
			if(pa[i].pt_exsist == 1){
				if(pa[i].pt_keiken >= keikenti[j] && pa[i].pt_keiken < keikenti[j+1]){
					if((before = pa[i].pt_level) != j){
						after = j;
						for(k = 1; k <= after-before; k++){
							pa[i].pt_level++;
							BGclear2();
							sprintf(str,"%s is level up!",pa[i].pt_name);
							sprintf(str1,"%s's level is %d.",pa[i].pt_name,pa[i].pt_level);
							while((ch = getch()) != ' '){
								mvaddstr(g_y+14,g_x+4,str);
								mvaddstr(g_y+15,g_x+4,str1);	
							}
							uh = rand();
							usp = rand();
							up = rand();
							ud = rand();
							uskl = rand();
							uspd = rand();

							syoku_up(uh,usp,up,ud,uskl,uspd,pa[i].pt_level);
							
							stateh = ss[pa[i].pt_synumber].s_uhp;
							statesp = ss[pa[i].pt_synumber].s_usp;
							statep = ss[pa[i].pt_synumber].s_upower;
							stated = ss[pa[i].pt_synumber].s_udefence;
							stateskl = ss[pa[i].pt_synumber].s_uskill;
							statespd = ss[pa[i].pt_synumber].s_uspeed;

							pa[i].pt_hp += stateh;
							pa[i].pt_nowhp = pa[i].pt_hp;
							pa[i].pt_sp += statesp;
							pa[i].pt_nowsp = pa[i].pt_sp;
							pa[i].pt_power += statep;
							pa[i].pt_defence += stated;
							pa[i].pt_skill += stateskl;
							pa[i].pt_speed += statespd;

							sprintf(sh,"HP:+%d",stateh);
							sprintf(ssp,"SP:+%d",statesp);
							sprintf(sp,"POWER:+%d",statep);
							sprintf(sd,"DEFENCE:+%d",stated);
							sprintf(sskl,"SKILL:+%d",stateskl);
							sprintf(sspd,"SPEED:+%d",statespd);

							BGclear2();
							while((ch = getch()) != ' '){
								mvaddstr(g_y+13,g_x+4,sh);
								mvaddstr(g_y+14,g_x+4,ssp);
								mvaddstr(g_y+15,g_x+4,sp);
								mvaddstr(g_y+16,g_x+4,sd);
							}
							BGclear2();
							while((ch = getch()) != ' '){	
								mvaddstr(g_y+13,g_x+4,sskl);
								mvaddstr(g_y+14,g_x+4,sspd);
							}
						}
					}
				}
			}
		}
		for(j = 1; j <= 20; j++){
			if(pa[i].pt_exsist == 1){
				if(pa[i].encount_num[pa[i].pt_synumber] >= sykeikenti[j] && pa[i].encount_num[pa[i].pt_synumber] < sykeikenti[j+1]){
					if(pa[i].syoku[pa[i].pt_synumber].s_level != j){
						pa[i].syoku[pa[i].pt_synumber].s_level++;
						BGclear2();
						sprintf(str,"%s is syoku level up!",pa[i].pt_name);
						sprintf(str1,"%s's syoku level is %d.",pa[i].pt_name,pa[i].syoku[pa[i].pt_synumber].s_level);
						while((ch = getch()) != ' '){
								mvaddstr(g_y+14,g_x+4,str);
								mvaddstr(g_y+15,g_x+4,str1);
							}
						learnSkill(i);
					}
				}
			}
		}
	
	}
}

void State_gamen(){

	int exit = 0;
	int cursoly,cursolx;
	char str[20];
	char ch;

	sprintf(str,"FLOOR:B%dF",me->me_kaisou);
	flag = 0;
	cursoly = g_y+6;
	cursolx = g_x+3;
	SG();
	PARTY_STATE();
	mvaddch(cursoly,cursolx,'>');
	mvaddstr(g_y+6,g_x+4,"party");
	mvaddstr(g_y+7,g_x+4,"sub");
	mvaddstr(g_y+8,g_x+4,"skill");
	mvaddstr(g_y+9,g_x+4,"leave");
	mvaddstr(g_y+10,g_x+4,"exit");
	mvaddstr(g_y+16,g_x+18,str);

	while((ch = getch()) != ' '){
		switch(ch){
			case 'j':
				mvaddch(cursoly,cursolx,' ');
				if(cursoly < g_y+10) cursoly++;
				mvaddch(cursoly,cursolx,'>');
				break;
			case 'f':
				mvaddch(cursoly,cursolx,' ');
				if(cursoly > g_y+6) cursoly--;
				mvaddch(cursoly,cursolx,'>');
				break;
		}
		if(ch == 'q'){
			exit = 1;
			break;
		}
	}

	if(exit != 1){
		switch(cursoly){
			case g_y+6:
				party();
				break;
			case g_y+7:
				SUB();
				break;
			case g_y+8:
				skillpage();
				break;
			case g_y+9:
				leave_party();
				break;
			case g_y+10:
				break;
		}
	}
}

void party(){
	int i;
	int exit = 0;
	int cursoly,cursolx;
	char ch;
	char str1[20];

	
	cursoly = g_y+5;
	switch(flag){
		case 0:
		case 1:
			cursolx = g_x+17;
			break;
		case 2:
			cursolx = g_x+25;
			break;
		case 3:
			cursolx = g_x+33;
			break;
	}


	for(i = 1; i <= ptninzuu; i++){
		sprintf(str1,"%s",pa[i].pt_name);
		mvaddstr(g_y+5,g_x+18+(8*(i-1)),str1);
	}
	mvaddch(cursoly,cursolx,'>');

	while((ch = getch()) != ' '){
		switch(ch){
			case 'j':
				mvaddch(cursoly,cursolx,' ');
				switch(ptninzuu){
					case 1:
						break;
					case 2:
						if(cursolx < g_x+25) cursolx += 8;
						break;
					case 3:
						if(cursolx < g_x+33) cursolx += 8;
						break;
				}
				mvaddch(cursoly,cursolx,'>');
				break;
			case 'f':
				mvaddch(cursoly,cursolx,' ');
				if(cursolx > g_x+17) cursolx -= 8;
				mvaddch(cursoly,cursolx,'>');
				break;
		}
		if(ch == 'q'){
			exit = 1;
			break;
		}
	}

	if(exit == 1){
		State_gamen();
	}else{
		switch(cursolx){
			case g_x+17:
				flag = 1;
				statas(1);
				break;
			case g_x+25:
				flag = 2;
				statas(2);
				break;
			case g_x+33:
				flag = 3;
				statas(3);
				break;
		}
	}
}

void skillpage(){
	int i;
	int exit = 0;
	int cursoly,cursolx;
	char ch;
	char str1[20];

	
	cursoly = g_y+5;
	switch(flag){
		case 0:
		case 1:
			cursolx = g_x+17;
			break;
		case 2:
			cursolx = g_x+25;
			break;
		case 3:
			cursolx = g_x+33;
			break;
	}


	for(i = 1; i <= ptninzuu; i++){
		sprintf(str1,"%s",pa[i].pt_name);
		mvaddstr(g_y+5,g_x+18+(8*(i-1)),str1);
	}
	mvaddch(cursoly,cursolx,'>');

	while((ch = getch()) != ' '){
		switch(ch){
			case 'j':
				mvaddch(cursoly,cursolx,' ');
				switch(ptninzuu){
					case 1:
						break;
					case 2:
						if(cursolx < g_x+25) cursolx += 8;
						break;
					case 3:
						if(cursolx < g_x+33) cursolx += 8;
						break;
				}
				mvaddch(cursoly,cursolx,'>');
				break;
			case 'f':
				mvaddch(cursoly,cursolx,' ');
				if(cursolx > g_x+17) cursolx -= 8;
				mvaddch(cursoly,cursolx,'>');
				break;
		}
		if(ch == 'q'){
			exit = 1;
			break;
		}
	}

	if(exit == 1){
		State_gamen();
	}else{
		switch(cursolx){
			case g_x+17:
				flag = 1;
				skillnote(1);
				break;
			case g_x+25:
				flag = 2;
				skillnote(2);
				break;
			case g_x+33:
				flag = 3;
				skillnote(3);
				break;
		}
	}
}


void statas(int number){

	char str[20],str1[20],str2[20],str3[20],str4[20],str5[20],str6[20],str7[20];

	SGclear1();
	sprintf(str,"LEVEL:%d",pa[number].pt_level);
	sprintf(str1,"HP:  %d",pa[number].pt_hp);
	sprintf(str2,"SP:  %d",pa[number].pt_sp);
	sprintf(str3,"POW: %d",pa[number].pt_power);
	sprintf(str4,"DEF: %d",pa[number].pt_defence);
	sprintf(str5,"SKL: %d",pa[number].pt_skill);
	sprintf(str6,"SPD: %d",pa[number].pt_speed);
	sprintf(str7,"EXP: %d",pa[number].pt_keiken);

	mvaddstr(g_y+7,g_x+18,str);
	mvaddstr(g_y+8,g_x+18,str1);
	mvaddstr(g_y+9,g_x+18,str2);
	mvaddstr(g_y+10,g_x+18,str3);
	mvaddstr(g_y+11,g_x+18,str4);
	mvaddstr(g_y+12,g_x+18,str5);
	mvaddstr(g_y+13,g_x+18,str6);
	mvaddstr(g_y+14,g_x+18,str7);

	party();
}

void skillnote(int number){

	int i;
	char str[20],str1[20],str2[20],str3[20],str4[20],str5[20],str6[20],str7[20];

	SGclear1();
	for(i = 1; i < 9; i++){
		if(pa[number].syoku[pa[number].pt_synumber].skill[i].use == 1){
			mvaddstr(g_y+6+i,g_x+18,pa[number].syoku[pa[number].pt_synumber].skill[i].sk_name);
		}
	}
	skillpage();
}
void JOIN(int enumber){
	int i;
	int not = 0;
	int cursoly = g_y+15;
	int cursolx = g_x+9;
	char str[50];
	char ch;

	BGclear1();
	for(i = 0; i < 7; i++){
		mvaddstr(g_y+5+i,g_x+21-(en[enumber].en_form_len/2),en[enumber].en_form[i]);
	}

	BGclear2();
	sprintf(str,"%s want to join us....",en[enumber].en_name);
	while((ch = getch()) != ' '){
		mvaddstr(g_y+14,g_x+4,str);
	}
	if(nakamanokazu >= 9 ){
		BGclear2();
		sprintf(str,"But party is size over!");
		while((ch = getch()) != ' '){
			mvaddstr(g_y+14,g_x+4,str);
		}
		not = 1;
	}else{
		BGclear2();
		sprintf(str,"Do you want them to join us ?");
		while((ch = getch()) != ' '){
			mvaddstr(g_y+14,g_x+4,str);
		}

		mvaddstr(g_y+15,g_x+10,"yes.");
		mvaddstr(g_y+15,g_x+20,"no.");
		mvaddch(cursoly,cursolx,'>');

		while((ch = getch()) != ' '){
			switch(ch){
				case 'j':
					mvaddch(cursoly,cursolx,' ');
					if(cursolx < g_x+19) cursolx += 10;
					mvaddch(cursoly,cursolx,'>');
					break;
				case 'f':
					mvaddch(cursoly,cursolx,' ');
					if(cursolx > g_x+9) cursolx -= 10;
					mvaddch(cursoly,cursolx,'>');
					break;
			}
		}

		switch(cursolx){
			case g_x+9:
				JOIN_ST(enumber);
				break;
			case g_x+19:
				not = 1;
				break;
		}
	}

	if(not == 1){
		BGclear2();
		sprintf(str,"%s leave us.",en[enumber].en_name);
		while((ch = getch()) != ' '){
			mvaddstr(g_y+14,g_x+4,str);
		}
	}
}

void JOIN_ST(int enumber){
	char ch;
	int i;
	char str[30];
	int new;

	me->join_monster_num[en[enumber].en_number] += 10;
	nakamanokazu++;
	for(i = 1; i < 12; i++){
		if(strcmp(pa[i].pt_name,"noname") == 0){
			new = i;
			break;
		}
	}
	strcpy(pa[new].pt_name,en[enumber].en_name);
	pa[new].pt_name[7] = '\0';
	pa[new].pt_synumber = 10 + en[enumber].en_number;
	pa[new].syoku[pa[new].pt_synumber] = sy[pa[new].pt_synumber];
	pa[new].pt_level = en[enumber].en_level;
	pa[new].pt_hp = en[enumber].en_hp;
	pa[new].pt_nowhp = pa[new].pt_hp;
	pa[new].pt_sp = en[enumber].en_sp;
	pa[new].pt_nowsp = pa[new].pt_sp;
	pa[new].pt_power = en[enumber].en_power;
	pa[new].pt_defence = en[enumber].en_defence;
	pa[new].pt_skill = en[enumber].en_skill;
	pa[new].pt_speed = en[enumber].en_speed;
	pa[new].pt_keiken = keikenti[pa[new].pt_level];
	pa[new].pt_exsist = 1;

	BGclear2();
	sprintf(str,"%s joined party!",pa[new].pt_name);
	while((ch = getch()) != ' '){
		mvaddstr(g_y+14,g_y+4,str);
	}

}

void SUB(){
	int i;
	int exit = 0;
	int cursoly = g_y+6;
	int cursolx = g_x+17;
	int cursoly2 = g_y+6;
	int cursolx2 = g_x+28;
	int p,s;
	char ch;
	struct PARTY temp[1];

	SG_sub();

	for(i = 1; i <= 3; i++){
		if(strcmp(pa[i].pt_name,"noname") != 0){
			mvaddstr(g_y+5+i,g_x+18,pa[i].pt_name);
		}
	}
	for(i = 4; i <= 11; i++){
		if(strcmp(pa[i].pt_name,"noname") != 0){
			mvaddstr(g_y+5+(i-3),g_x+29,pa[i].pt_name);
		}
	}

	mvaddch(cursoly,cursolx,'>');
	while((ch = getch()) != ' '){
		switch(ch){
			case 'j':
				mvaddch(cursoly,cursolx,' ');
				if(cursoly < g_y+8) cursoly++;
				mvaddch(cursoly,cursolx,'>');
				break;
			case 'f':
				mvaddch(cursoly,cursolx,' ');
				if(cursoly > g_y+6) cursoly--;
				mvaddch(cursoly,cursolx,'>');
				break;
		}
		if(ch == 'q'){
			exit = 1;
			break;
		}
	}
	if(exit == 1){
		State_gamen();
	}else{
		mvaddch(cursoly2,cursolx2,'>');
		while((ch = getch()) != ' '){
			switch(ch){
				case 'j':
					mvaddch(cursoly2,cursolx2,' ');
					if(cursoly2 < g_y+13) cursoly2++;
					mvaddch(cursoly2,cursolx2,'>');
					break;
				case 'f':
					mvaddch(cursoly2,cursolx2,' ');
					if(cursoly2 > g_y+6) cursoly2--;
					mvaddch(cursoly2,cursolx2,'>');
					break;
			}
			if(ch == 'q'){
				exit = 1;
				break;
			}
		}
		if(exit == 1){
			SUB();
		}else{
			switch(cursoly){
				case g_y+6:
					p = 1;
					break;
				case g_y+7:
					p = 2;
					break;
				case g_y+8:
					p = 3;
					break;
			}

			switch(cursoly2){
				case g_y+6:
					s = 4;
					break;
				case g_y+7:
					s = 5;
					break;
				case g_y+8:
					s = 6;
					break;
				case g_y+9:
					s = 7;
					break;
				case g_y+10:
					s = 8;
					break;
				case g_y+11:
					s = 9;
					break;
				case g_y+12:
					s = 10;
					break;
				case g_y+13:
					s = 11;
					break;
			}

			if(ptninzuu == 1 && strcmp(pa[s].pt_name,"noname") == 0){
			}else{
				temp[0] = pa[p];
				pa[p] = pa[s];
				pa[s] = temp[0];

				if(strcmp(pa[p].pt_name,"noname") == 0){
					if(strcmp(pa[s].pt_name,"noname") == 0){
					}else if(strcmp(pa[s].pt_name,"noname") != 0){
						ptninzuu--;
					}
				}else if(strcmp(pa[p].pt_name,"noname") != 0){
					if(strcmp(pa[s].pt_name,"noname") == 0){
						ptninzuu++;
					}else if(strcmp(pa[s].pt_name,"noname") != 0){
					}
				}
			}

			switch(ptninzuu){
				case 1:
					if(strcmp(pa[1].pt_name,"noname") == 0){
						temp[0] = pa[2];
						pa[2] = pa[1];
						pa[1] = temp[0];
					}
					break;
				case 2:
					if(strcmp(pa[1].pt_name,"noname") == 0){
						temp[0] = pa[2];
						pa[2] = pa[1];
						pa[1] = temp[0];
						temp[0] = pa[3];
						pa[3] = pa[2];
						pa[2] = temp[0];
					}else if(strcmp(pa[2].pt_name,"noname") == 0){
						temp[0] = pa[3];
						pa[3] = pa[2];
						pa[2] = temp[0];
					}
					break;
			}

			SUB();
		}
	}

}

void leave_party(){

	int i;
	int s;
	int exit=0;
	int cursolx = g_x+20;
	int cursoly = g_y+6;
	int cursolx2 = g_x+18;
	int cursoly2 = g_x+9;
	char ch;

	SGclear1();

	for(i = 4; i <= 11; i++){
		if(strcmp(pa[i].pt_name,"noname") != 0){
			mvaddstr(g_y+5+(i-3),g_x+22,pa[i].pt_name);
		}
	}

			while((ch = getch()) != ' '){
			switch(ch){
				case 'j':
					mvaddch(cursoly,cursolx,' ');
					if(cursoly < g_y+13) cursoly++;
					break;
				case 'f':
					mvaddch(cursoly,cursolx,' ');
					if(cursoly > g_y+6) cursoly--;
					break;
			}
			if(ch == 'q'){
				exit = 1;
				break;
			}
					mvaddch(cursoly,cursolx,'>');
			}
			if(exit == 1){
				State_gamen();
			}else{
			switch(cursoly){
				case g_y+6:
					s = 4;
					break;
				case g_y+7:
					s = 5;
					break;
				case g_y+8:
					s = 6;
					break;
				case g_y+9:
					s = 7;
					break;
				case g_y+10:
					s = 8;
					break;
				case g_y+11:
					s = 9;
					break;
				case g_y+12:
					s = 10;
					break;
				case g_y+13:
					s = 11;
					break;
			}

			saveG2();
			mvaddstr(g_y+8,g_x+17,"leave him?");
			mvaddstr(g_y+9,g_x+20,"Yes");
			mvaddstr(g_y+10,g_x+20,"No");
			
			while((ch = getch()) != ' '){
			switch(ch){
				case 'j':
					mvaddch(cursoly2,cursolx2,' ');
					if(cursoly2 < g_y+10) cursoly2++;
					break;
				case 'f':
					mvaddch(cursoly2,cursolx2,' ');
					if(cursoly2 > g_y+9) cursoly2--;
					break;
			}
					mvaddch(cursoly2,cursolx2,'>');
			}

			switch(cursoly2){
				case g_y+9:
					pa[s] = pa[0];
					nakamanokazu--;
					State_gamen();
					break;
				case g_y+10:
					leave_party();
					break;
			}
			}

}


int B_skill(int ptnumber){
	int i;
	int cnt=0;
	char ch;
	int exit;
	int cursoly = g_y+13;
	int cursolx = g_x+17;

	BGclear5();
	for(i = 1; i <= 4; i++){
		if(pa[ptnumber].syoku[pa[ptnumber].pt_synumber].skill[i].use == 1){
			mvaddstr(g_y+12+i,g_x+19,pa[ptnumber].syoku[pa[ptnumber].pt_synumber].skill[i].sk_name);
			cnt++;
		}
	}

	mvaddch(cursoly,cursolx,'>');

	while((ch = getch()) != ' '){
		switch(ch){
			case 'j':
				mvaddch(cursoly,cursolx,' ');
				if(cursoly < g_y+12+cnt) cursoly++;
				break;
			case 'f':
				mvaddch(cursoly,cursolx,' ');
				if(cursoly > g_y+13) cursoly--;
				break;
			case 'g':
				mvaddch(cursoly,cursolx,' ');
				if(cursolx < g_x+29){
					switch(cursoly){
						case g_y+13:
							if(cnt > 4) cursolx += 12;
							break;
						case g_y+14:
							if(cnt > 5) cursolx += 12;
							break;
						case g_y+15:
							if(cnt > 6) cursolx += 12;
							break;
						case g_y+16:
							if(cnt > 7) cursolx += 12;
							break;
					}
					break;
					case 'h':
					mvaddch(cursoly,cursolx,' ');
					if(cursolx > g_x+17) cursolx -= 12;
					break;
				}
		}
		mvaddch(cursoly,cursolx,'>');
		if(ch == 'q'){
			exit = 1;
			break;
		}
	}

	if(exit != 1){
		switch(cursolx){
			case g_x+17:
				switch(cursoly){
					case g_y+13:
						pa[ptnumber].useskill = 1;
						break;
					case g_y+14:
						pa[ptnumber].useskill = 2;
						break;
					case g_y+15:
						pa[ptnumber].useskill = 3;
						break;
					case g_y+16:
						pa[ptnumber].useskill = 4;
						break;
				}
				break;
			case  g_x+29:
				switch(cursoly){
					case g_y+13:
						pa[ptnumber].useskill = 5;
						break;
					case g_y+14:
						pa[ptnumber].useskill = 6;
						break;
					case g_y+15:
						pa[ptnumber].useskill = 7;
						break;
					case g_y+16:
						pa[ptnumber].useskill = 8;
						break;
				}
				break;
		}

		if(pa[ptnumber].pt_nowsp - pa[ptnumber].syoku[pa[ptnumber].pt_synumber].skill[pa[ptnumber].useskill].consume_sp >= 0){
			pa[ptnumber].pt_nowsp -= pa[ptnumber].syoku[pa[ptnumber].pt_synumber].skill[pa[ptnumber].useskill].consume_sp;

			if(pa[ptnumber].syoku[pa[ptnumber].pt_synumber].skill[pa[ptnumber].useskill].all == 0) CHOICE(ptnumber);
			return 0;
		}
	}
	if(exit != 1){
		BGclear5();
		mvaddstr(g_y+14,g_y+19,"SP is not enough.");
		while((ch = getch()) != ' ');
	}
	return 1;
}

void learnSkill(int ptnumber){
	int learn = 0;
	char ch;
	char str[50];
	if(pa[ptnumber].syoku[pa[ptnumber].pt_synumber].skill[pa[ptnumber].syoku[pa[ptnumber].pt_synumber].s_level].use == 0){
		pa[ptnumber].syoku[pa[ptnumber].pt_synumber].skill[pa[ptnumber].syoku[pa[ptnumber].pt_synumber].s_level].use = 1;
		learn = 1;
	}

	if(learn == 1){
		BGclear2();
		sprintf(str,"%s learned skill:%s",pa[ptnumber].pt_name,pa[ptnumber].syoku[pa[ptnumber].pt_synumber].skill[pa[ptnumber].syoku[pa[ptnumber].pt_synumber].s_level].sk_name);
		while((ch = getch()) != ' '){
			mvaddstr(g_y+14,g_x+4,str);
		}
	}
}
