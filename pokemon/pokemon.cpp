#include<iostream>
#include <windows.h>
#include<conio.h>
#include<string>
#include<fstream> 
#include<map>
#include<ctime>
using namespace std;
void gotoxy(int xpos, int ypos)
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}
 
void setColor(int bc=0, int fc=7)
{	
  HANDLE hConsole;
  int color;
  color = (bc%16)*16+(fc%16);
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,color);
}
class Move
{
    public:
        string move_name;
        string attribute;
        int damage;
        double accuracy;
        int maxuse;
    public:
        Move(string mname="000",string at="0",float d=0,float ac=0.0,int mu=0):move_name(mname),attribute(at),damage(d),accuracy(ac),maxuse(mu){}
        string get_move_name(){return move_name;}
        string get_attribute(){return attribute;}
        int get_damage(){return damage;}
        double get_accuracy(){return accuracy;}
        int get_maxuse(){return maxuse;}
};
class pokemon:public Move 
{
	public: 
	    string pokemon_name;
		int speed;
		string attribute1;
		string attribute2;
		int attack;
		int defend;
	    int HP;
	    Move move1;
        Move move2;
        Move move3;
	public:
		pokemon(int sp=0,string at1="0",string at2="0",float atk=0,float def=0,float blood=0):speed(sp),attribute1(at1),attribute2(at2),attack(atk),defend(def),HP(blood){}
            int set_blood(int a)
			{
				HP=a;
				return HP;
			}
			float search_map1(pokemon p,Move m)//招式對敵 
			{
				float table[15][15]={0};           
				ifstream fin;	
				fin.open("attribute_table.txt");
				for(int i=0;i<15;i++)
				{
					for(int j=0;j<15;j++)
					{
						fin>>table[i][j];
					}
				}
				fin.close();
				map <string,int> attribute_map;
				map<string,int>::iterator iter1;
				map<string,int>::iterator iter2;
   	 			map<string,int>::reverse_iterator iter_r; 
   	 			attribute_map.insert(pair<string,int>("Normal",0));
   	 			attribute_map.insert(pair<string,int>("Fighting",1));
   	 			attribute_map.insert(pair<string,int>("Flying",2));
   	 			attribute_map.insert(pair<string,int>("Poison",3));
   	 			attribute_map.insert(pair<string,int>("Ground",4));
   	 			attribute_map.insert(pair<string,int>("Rock",5));
   	 			attribute_map.insert(pair<string,int>("Bug",6));
   	 			attribute_map.insert(pair<string,int>("Ghost",7));
   	 			attribute_map.insert(pair<string,int>("Fire",8));
   	 			attribute_map.insert(pair<string,int>("Water",9));
   	 			attribute_map.insert(pair<string,int>("Grass",10));
   	 			attribute_map.insert(pair<string,int>("Electric",11));
   	 			attribute_map.insert(pair<string,int>("Psychic",12));
   	 			attribute_map.insert(pair<string,int>("Ice",13));
   	 			attribute_map.insert(pair<string,int>("Dragon",14));
   	 			for(iter1 = attribute_map.begin(); iter1 != attribute_map.end(); iter1++)
   	 			{
					for(iter2 = attribute_map.begin(); iter2 != attribute_map.end(); iter2++)
					{
						if(move1.attribute==(*iter1).first&&p.attribute1==(*iter2).first)
						{
							//cout<<(*iter1).second<<endl;
							//cout<<(*iter2).second<<endl;
							return table[(*iter1).second][(*iter2).second];
						}
					}
    		    }
			}
				float search_map2(pokemon p,Move m)//招式對敵 
			{
				float table[15][15]={0};           
				ifstream fin;	
				fin.open("attribute_table.txt");
				for(int i=0;i<15;i++)
				{
					for(int j=0;j<15;j++)
					{
						fin>>table[i][j];
					}
				}
				fin.close();
				map <string,int> attribute_map;
				map<string,int>::iterator iter1;
				map<string,int>::iterator iter2;
   	 			map<string,int>::reverse_iterator iter_r; 
   	 			attribute_map.insert(pair<string,int>("Normal",0));
   	 			attribute_map.insert(pair<string,int>("Fighting",1));
   	 			attribute_map.insert(pair<string,int>("Flying",2));
   	 			attribute_map.insert(pair<string,int>("Poison",3));
   	 			attribute_map.insert(pair<string,int>("Ground",4));
   	 			attribute_map.insert(pair<string,int>("Rock",5));
   	 			attribute_map.insert(pair<string,int>("Bug",6));
   	 			attribute_map.insert(pair<string,int>("Ghost",7));
   	 			attribute_map.insert(pair<string,int>("Fire",8));
   	 			attribute_map.insert(pair<string,int>("Water",9));
   	 			attribute_map.insert(pair<string,int>("Grass",10));
   	 			attribute_map.insert(pair<string,int>("Electric",11));
   	 			attribute_map.insert(pair<string,int>("Psychic",12));
   	 			attribute_map.insert(pair<string,int>("Ice",13));
   	 			attribute_map.insert(pair<string,int>("Dragon",14));
   	 			for(iter1 = attribute_map.begin(); iter1 != attribute_map.end(); iter1++)
   	 			{
					for(iter2 = attribute_map.begin(); iter2 != attribute_map.end(); iter2++)
					{
						if(move2.attribute==(*iter1).first&&p.attribute1==(*iter2).first)
						{
							//cout<<(*iter1).second<<endl;
							//cout<<(*iter2).second<<endl;
							return table[(*iter1).second][(*iter2).second];
						}
					}
    		    }
			}
				float search_map3(pokemon p,Move m)//招式對敵 
			{
				float table[15][15]={0};           
				ifstream fin;	
				fin.open("attribute_table.txt");
				for(int i=0;i<15;i++)
				{
					for(int j=0;j<15;j++)
					{
						fin>>table[i][j];
					}
				}
				fin.close();
				map <string,int> attribute_map;
				map<string,int>::iterator iter1;
				map<string,int>::iterator iter2;
   	 			map<string,int>::reverse_iterator iter_r; 
   	 			attribute_map.insert(pair<string,int>("Normal",0));
   	 			attribute_map.insert(pair<string,int>("Fighting",1));
   	 			attribute_map.insert(pair<string,int>("Flying",2));
   	 			attribute_map.insert(pair<string,int>("Poison",3));
   	 			attribute_map.insert(pair<string,int>("Ground",4));
   	 			attribute_map.insert(pair<string,int>("Rock",5));
   	 			attribute_map.insert(pair<string,int>("Bug",6));
   	 			attribute_map.insert(pair<string,int>("Ghost",7));
   	 			attribute_map.insert(pair<string,int>("Fire",8));
   	 			attribute_map.insert(pair<string,int>("Water",9));
   	 			attribute_map.insert(pair<string,int>("Grass",10));
   	 			attribute_map.insert(pair<string,int>("Electric",11));
   	 			attribute_map.insert(pair<string,int>("Psychic",12));
   	 			attribute_map.insert(pair<string,int>("Ice",13));
   	 			attribute_map.insert(pair<string,int>("Dragon",14));
   	 			for(iter1 = attribute_map.begin(); iter1 != attribute_map.end(); iter1++)
   	 			{
					for(iter2 = attribute_map.begin(); iter2 != attribute_map.end(); iter2++)
					{
						if(move3.attribute==(*iter1).first&&p.attribute1==(*iter2).first)
						{
							return table[(*iter1).second][(*iter2).second];
						}
					}
    		    }
			}
			float search_map4(pokemon p,Move m)
			{
				float plus=0; 
				if(p.attribute1==move1.attribute)
			    {
				 	plus=1.5;
				}
				else
				{
					plus=1;
				}
				return plus;
			}
			float search_map5(pokemon p,Move m)
			{
				float plus=0; 
				if(p.attribute1==move2.attribute)
			    {
				 	plus=1.5;
				}
				else
				{
					plus=1;
				}
				return plus;
			}
			float search_map6(pokemon p,Move m)
			{
				float plus=0; 
				if(p.attribute1==move3.attribute)
			    {
				 	plus=1.5;
				}
				else
				{
					plus=1;
				}
				return plus;
			}
		 
};
class pikachu : public pokemon
{

public:
    pikachu(int sp = 90, string at1 = "Electric", string at2 = "0", float atk = 55, float def = 40, float blood = 35):pokemon(sp, at1, at2, atk, def, blood)
        //move1(Move("電光一閃", 80, 100, 10)),
        //move2(Move("電球", 65, 90, 15)),
        //move3(Move("十萬伏特", 95, 100, 15))
		{
			pokemon_name="pikachu";
			move1=Move("電光一閃","Normal", 100, 100, 10);
		  	move2=Move("電球    ","Electric", 65, 90, 15);
            move3=Move("十萬伏特","Electric", 95, 100, 15);
		}
};
class venusauer:public pokemon
{
	public:
		venusauer(int sp=80,string at1="Grass",string at2="0",float atk=82,float def=83,float blood=80):pokemon(sp,at1,at2,atk,def,blood)
		{
			pokemon_name="venusauer";
			move1=Move("日光束  ","Grass", 120, 100, 10);
		  	move2=Move("飛葉快刀","Grass",55, 95, 25);
            move3=Move("汙泥波 ","Poison", 95, 75, 15);
		} 
	 
};
class blastoise:public pokemon
{
	public:
		blastoise(int sp=75,string at1="Water",string at2="0",float atk=83,float def=100,float blood=79):pokemon(sp,at1,at2,atk,def,blood)
		{
			pokemon_name="blastoise";
			move1=Move("水炮  ","Water", 120, 80, 5);
		  	move2=Move("火箭頭槌","Normal",100, 100, 15);
            move3=Move("衝浪  ","Water", 95, 100, 15);
		} 
};
class  charizard:public pokemon
{
	public:
		charizard(int sp=100,string at1="Fire",string at2="Flying",float atk=84,float def=78,float blood=78):pokemon(sp,at1,at2,atk,def,blood)
		{
			pokemon_name="charizard";
			move1=Move("噴射火焰","Fire", 95, 100, 5);
		  	move2=Move("大字爆炎","Fire",120, 85, 5);
            move3=Move("龍之怒 ","Dragon", 50, 100, 15);
		} 
		 	
};
class  gengar:public pokemon
{
	public:
		gengar(int sp=110,string at1="Ghost",string at2="Poison",float atk=65,float def=60,float blood=60):pokemon(sp,at1,at2,atk,def,blood)
		{
			pokemon_name="gengar";
			move1=Move("暗影球 ","Ghost", 80, 60, 20);
		  	move2=Move("精神強念","Psychic",90, 100, 10);
            move3=Move("汙泥波","Poison", 95, 100, 10);
		} 
};
class  gyarados:public pokemon
{
	public:
		gyarados(int sp=81,string at1="Water",string at2="Flying",float atk=125,float def=79,float blood=95):pokemon(sp,at1,at2,atk,def,blood)
		{
			pokemon_name="gyarados";
			move1=Move("龍之怒 ","Dragon", 50, 100, 10);
		  	move2=Move("水砲  ","Water",120, 80, 5);
            move3=Move("破壞光線","Normal",150 , 90, 5);
		} 
};
class  alakazam:public pokemon
{
	public:
		alakazam(int sp=120,string at1="Psychic",string at2="0",float atk=50,float def=45,float blood=55):pokemon(sp,at1,at2,atk,def,blood)
		{
			pokemon_name="alakazam";
			move1=Move("精神強念","Psychic", 90, 100, 10);
		  	move2=Move("愛心印章","Psychic", 60, 20, 20);
            move3=Move("念力","Psychic", 50, 20 , 20);
		} 
	 	
};
class  scyther:public pokemon
{
	public:
		scyther(int sp=105,string at1="Bug",string at2="Flying",float atk=110,float def=80,float blood=70):pokemon(sp,at1,at2,atk,def,blood)
		{
			pokemon_name="scyther";
			move1=Move("蟲鳴 ","Bug", 90, 20, 30);
		  	move2=Move("捨身衝撞","Normal", 100, 100, 15);
            move3=Move("近身戰","Fighting", 120, 100, 35);
		} 
};
class  lapras:public pokemon
{
	public:
		lapras(int sp=60,string at1="Water",string at2="Ice",float atk=85,float def=80,float blood=130):pokemon(sp,at1,at2,atk,def,blood)
		{
			pokemon_name="lapras";
			move1=Move("水炮  ","Water", 120, 80, 5);
		  	move2=Move("冰凍光束","Ice", 95, 100, 10);
            move3=Move("暴風雪 ","Ice", 120, 90, 5);
		} 
};
class  dragonfat:public pokemon
{
	public:dragonfat(int sp=80,string at1="Dragon",string at2="Flying",float atk=134,float def=95,float blood=91):pokemon(sp,at1,at2,atk,def,blood)
		{
			pokemon_name="dragonfat";
			move1=Move("破壞光線","Normal", 150, 90, 5);
		  	move2=Move("龍之怒 ","Dragon", 50, 100, 10);
            move3=Move("大字爆炎","Fire", 120, 85, 5);
		} 
	 
};
class player:public pokemon 
{
	public: 
		string name;
		pokemon *pet[3];
	public:
		player(string n1="0"):name(n1){}
		void set_n1()
		{
			cin>>name;
		}
		void show()
		{
			cout<<name;
		}
		void choose_pokemon()
		{
			int count=0;
			cout<<"你選擇的三隻寶可夢是:";
			int n[3]={0};
			for(int i=0;i<3;i++)
			{
				cin>>n[i];
			}
			while(true)
			{ 
			     
				switch(n[count])
				{
					case 1:
						cout<<"皮卡丘  ";
						pet[count]=new pikachu(121,"Electric","0",86,81,121);
						break;
					case 2:
						cout<<"妙蛙花  ";
						pet[count]=new venusauer(111,"Grass","0",131,131,166);
						break;
					case 3:
						cout<<"水箭龜  ";
						pet[count]=new blastoise(109,"Water","0",116,136,165);
						break;
					case 4:
						cout<<"噴火龍  ";
						pet[count]=new charizard(131,"Fire","Flying",140,116,164);
						break;
					case 5:
						cout<<"耿鬼  ";
						pet[count]=new gengar(141,"Ghost","Poison",161,106,146);
						break;
					case 6:
						cout<<"暴鯉龍  ";
						pet[count]=new gyarados(112,"Water","Fly",156,131,181);
						break;
					case 7:
						cout<<"胡地  ";
						pet[count]=new alakazam(151,"Psychic","0",166,126,141);
						break;
					case 8:
						cout<<"飛天螳螂  ";
						pet[count]=new scyther(136,"Bug","Fly",141,111,156);
						break;
					case 9:
						cout<<"乘龍  ";
						pet[count]=new lapras(91,"Water","Ice",116,126,216);
						break;	
					case 10:
						cout<<"快龍  ";
						pet[count]=new dragonfat(111,"Dragon","Fly",165,131,177);
						break;		
				} 
				count=count+1;
				if(count>2)
				{
					break;
				}
		    }
		}
};
class pokemon_list
{
	public:
		void show()
		{
			cout<<"1.皮卡丘  "<<"\t";//  電球 電光一閃    十萬伏特   打雷 
			cout<<"2.妙蛙花  "<<"\t";// 日光束   寄身種子  催眠粉     飛葉快刀 
			cout<<"3.水箭龜  "<<"\t";//水炮    火箭頭槌  衝浪   破壞光線 
			cout<<"4.噴火龍  "<<"\t";//噴射火焰 大字爆炎 飛翔   龍之怒 
			cout<<"5.耿鬼    "<<"\t"<<endl; //催眠術 食夢 精神強念  奇異之光 
			cout<<"6.暴鯉龍  "<<"\t";// 龍之怒  水砲  衝浪  破壞光線 
			cout<<"7.胡地    "<<"\t";//精神強念  自我再生 反射壁 三重攻擊 
			cout<<"8.飛天螳螂"<<"\t";//劍舞 電光一閃  翅膀攻擊 60   
			cout<<"9.乘龍    "<<"\t";
			cout<<"10.快龍   "<<"\t"<<endl; 
		}
};
int main()
{ 
	 //輸入術性克制表 
	player p1,p2;
	pokemon_list list1;
	char c;
	cout<<"請輸入訓練家名稱"<<endl;
    p1.set_n1();
    system("cls");
    list1.show();
	cout<<"請"; 
	p1.show();  
	cout<<"選擇三隻寶可夢";
	p1.choose_pokemon();
	 
	c=getch();
	system("cls");
	
	
    cout<<"請輸入訓練家名稱"<<endl;
    p2.set_n1();
    system("cls");
    list1.show();
	cout<<"請"; 
	p2.show();  
	cout<<"選擇三隻寶可夢";
	p2.choose_pokemon();
	c=getch();
	system("cls");
    int number1=0;
    int number2=0;
    int HP1=1;
	int HP2=1;
	int a=1;
	int b=1;
   	while(true)
	{
		//system("cls");
		cout<<(*p1.pet[number1]).pokemon_name<<"\t\t\t\t";
		cout<<(*p2.pet[number2]).pokemon_name<<endl;
		cout<<"HP:"<<(*p1.pet[number1]).HP<<"\t\t\t\t";
		cout<<"HP:"<<(*p2.pet[number2]).HP<<endl;
		cout<<"招式:"<<"\t\t\t\t"; 
		cout<<"招式:"<<endl;
		cout<< "q."<< (*p1.pet[number1]).move1.move_name <<" " << (*p1.pet[number1]).move1.attribute <<" \t\t" ;//<<(*p1.pet[number1]).move1.maxuse << "\t";
		cout<<"1." << (*p2.pet[number2]).move1.move_name <<" " << (*p2.pet[number2]).move1.attribute << " \t"<< endl; //<<(*p2.pet[number2]).move1.maxuse << endl;
		cout<< "w." << (*p1.pet[number1]).move2.move_name <<" " << (*p1.pet[number1]).move2.attribute << " \t\t"; //<<(*p1.pet[number1]).move2.maxuse << "\t";
		cout<<"2." << (*p2.pet[number2]).move2.move_name <<" " << (*p2.pet[number2]).move2.attribute << " \t" << endl;//<<(*p2.pet[number2]).move2.maxuse << endl;
		cout<< "e." << (*p1.pet[number1]).move3.move_name <<" " << (*p1.pet[number1]).move3.attribute << " \t\t" ;//<<(*p1.pet[number1]).move3.maxuse << "\t";
		cout<<"3." << (*p2.pet[number2]).move3.move_name <<" " << (*p2.pet[number2]).move3.attribute << " \t"<< endl; //<<(*p2.pet[number2]).move3.maxuse << endl;
		cout<<"所選寶可夢:"<<"\t\t\t"<<"所選寶可夢:"<<endl;
		cout<< "r." << (*p1.pet[0]).pokemon_name<<"\t\t\t";
		cout<< "4." << (*p2.pet[0]).pokemon_name<<endl;
		cout<< "t." << (*p1.pet[1]).pokemon_name<<"\t\t\t";
		cout<< "5." << (*p2.pet[1]).pokemon_name<<endl;
		cout<< "y." << (*p1.pet[2]).pokemon_name<<"\t\t\t";
		cout<< "6." << (*p2.pet[2]).pokemon_name<<endl;
		if(((*p1.pet[0]).HP<=0)&&((*p1.pet[1]).HP<=0)&&((*p1.pet[2]).HP<=0))
		{
			cout<<"恭喜訓練家";
			p2.show();
			cout<<"獲勝!!";
			break; 
		}
		if(((*p2.pet[0]).HP<=0)&&((*p2.pet[1]).HP<=0)&&((*p2.pet[2]).HP<=0))
		{
			cout<<"恭喜訓練家";
			p1.show();
			cout<<"獲勝!!";
			break;
		}
		srand(time(0)); 
		char c;
		int count=0;
		int speed_compare[2]={0};
		int moves[2]={0};
		float damage_plus1;
		float damage_plus2;
		int flag1=0;
		int flag2=0;
		int prepare1;
		int prepare2;
		while(true)
		{
				while(true)
				{
					if(kbhit())
					{
						c=getch();
						if(c=='q'||c=='w'||c=='e'||c=='r'||c=='t'||c=='y')
						{
							if(c=='q'&&(*p1.pet[number1]).HP>0)
							{
								moves[0]=(*p1.pet[number1]).move1.damage;
								speed_compare[0]=(*p1.pet[number1]).speed;
								damage_plus1=(*p1.pet[number1]).search_map1((*p2.pet[number2]),(*p1.pet[number1]).move1)*(*p1.pet[number1]).search_map4((*p1.pet[number1]),(*p1.pet[number1]).move1);
								count+=1; 
								prepare1=1;
							}
							if(c=='w'&&(*p1.pet[number1]).HP>0)
							{
							 	moves[0]=(*p1.pet[number1]).move2.damage;
								speed_compare[0]=(*p1.pet[number1]).speed;
								damage_plus1=(*p1.pet[number1]).search_map2((*p2.pet[number2]),(*p1.pet[number1]).move2)*(*p1.pet[number1]).search_map5((*p1.pet[number1]),(*p1.pet[number1]).move2);
								count+=1; 
								prepare1=2;
							}
							if(c=='e'&&(*p1.pet[number1]).HP>0)
							{
							 	moves[0]=(*p1.pet[number1]).move3.damage;
								speed_compare[0]=(*p1.pet[number1]).speed;
								damage_plus1=(*p1.pet[number1]).search_map3((*p2.pet[number2]),(*p1.pet[number1]).move3)*(*p1.pet[number1]).search_map6((*p1.pet[number1]),(*p1.pet[number1]).move3);
								count+=1; 
								prepare1=3;
							}
							if(c=='r'&&(*p1.pet[0]).HP>0)
							{
								if(number1!=0)
								{
									count+=1;
									number1=0;
									flag1+=1;
								}
								 
							}
							if(c=='t'&&(*p1.pet[1]).HP>0)
							{
							 	if(number1!=1)
								{
									count+=1;
									number1=1;
									flag1+=1;
								}
							}	
							if(c=='y'&&(*p1.pet[2]).HP>0)
							{
							 	if(number1!=2)
								{
									count+=1;
									number1=2;
									flag1+=1;
								}
							}		
							
						}
						if(c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6')
						{
							if(c=='1'&&(*p2.pet[number2]).HP>0)
							{
							 	moves[1]=(*p2.pet[number2]).move1.damage;
							 	speed_compare[1]=(*p2.pet[number2]).speed;
							 	damage_plus2=(*p2.pet[number2]).search_map1((*p1.pet[number1]),(*p2.pet[number2]).move1)*(*p2.pet[number2]).search_map4((*p2.pet[number2]),(*p2.pet[number2]).move1);
							 	count+=1;
							 	prepare2=1;
							}
							if(c=='2'&&(*p2.pet[number2]).HP>0)
							{
							 	moves[1]=(*p2.pet[number2]).move2.damage;
							 	speed_compare[1]=(*p2.pet[number2]).speed;
							 	damage_plus2=(*p2.pet[number2]).search_map2((*p1.pet[number1]),(*p2.pet[number2]).move2)*(*p2.pet[number2]).search_map5((*p2.pet[number2]),(*p2.pet[number2]).move2);
							 	count+=1;
							 	prepare2=2;
							}
							if(c=='3'&&(*p2.pet[number2]).HP>0)
							{
							 	moves[1]=(*p2.pet[number2]).move3.damage;
							 	speed_compare[1]=(*p2.pet[number2]).speed;
							 	damage_plus2=(*p2.pet[number2]).search_map3((*p1.pet[number1]),(*p2.pet[number2]).move3)*(*p2.pet[number2]).search_map6((*p2.pet[number2]),(*p2.pet[number2]).move3);
							 	count+=1;
							 	prepare2=3;
							}
							if(c=='4'&&(*p2.pet[0]).HP>0)
							{
							 	if(number2!=0)
								{
									count+=1;
									number2=0;
									flag2+=1;
								}
						    }
						    if(c=='5'&&(*p2.pet[1]).HP>0)
							{
							 	if(number2!=1)
								{
									count+=1;
									number2=1;
									flag2+=1;
								}
						    }
						    if(c=='6'&&(*p2.pet[2]).HP>0)
							{
							 	if(number2!=2)
								{
									count+=1;
									number2=2;
									flag2+=1;
								}
						    }
					    }
					    if(count==2&&flag2==1&&HP2>0)//殘血換角   p2換 
					    {
					    	if(prepare1==1)
					    	{
					    		damage_plus1=(*p1.pet[number1]).search_map1((*p2.pet[number2]),(*p1.pet[number1]).move1)*(*p1.pet[number1]).search_map4((*p1.pet[number1]),(*p1.pet[number1]).move1);
					    		damage_plus2=0;
							}
							if(prepare1==2)
							{
								damage_plus1=(*p1.pet[number1]).search_map2((*p2.pet[number2]),(*p1.pet[number1]).move2)*(*p1.pet[number1]).search_map5((*p1.pet[number1]),(*p1.pet[number1]).move2);
								damage_plus2=0;
							}
							if(prepare1==3)
							{
								damage_plus1=(*p1.pet[number1]).search_map3((*p2.pet[number2]),(*p1.pet[number1]).move3)*(*p1.pet[number1]).search_map6((*p1.pet[number1]),(*p1.pet[number1]).move3);
								damage_plus2=0;
							}
						}
						else if(count==2&&flag2==1&&HP2<=0)
						{
							damage_plus1=0;
							damage_plus2=0;
							HP2=1;
						}
						if(count==2&&flag1==1&&HP1>0)   //1換 
						{
							if(prepare2==1)
							{
								damage_plus2=(*p2.pet[number2]).search_map1((*p1.pet[number1]),(*p2.pet[number2]).move1)*(*p2.pet[number2]).search_map4((*p2.pet[number2]),(*p2.pet[number2]).move1);
								damage_plus1=0;
							}
							if(prepare2==2)
							{
								damage_plus2=(*p2.pet[number2]).search_map2((*p1.pet[number1]),(*p2.pet[number2]).move2)*(*p2.pet[number2]).search_map5((*p2.pet[number2]),(*p2.pet[number2]).move2);
								damage_plus1=0;
							}  
							if(prepare2==3)
							{
									damage_plus2=(*p2.pet[number2]).search_map3((*p1.pet[number1]),(*p2.pet[number2]).move3)*(*p2.pet[number2]).search_map6((*p2.pet[number2]),(*p2.pet[number2]).move3);
									damage_plus1=0;
							}
						}
			            else if(count==2&&flag1==1&&HP1<=0)
			            {
			            	damage_plus1=0;
							damage_plus2=0;
							HP1=1;
						}
						if(flag1==1&&flag2==1)
						{
							damage_plus1=0;
							damage_plus2=0;
						}
					    if(count==2)
					    {
					    	break;
						}
				    }
				} 
			                   //55,40,35
				if(count==2&&( (flag1==0&&flag2==0) || (flag1==1&&flag2==0)||(flag1==0&&flag2==1) ) )
		        {		
					 		a=(*p2.pet[number2]).HP-(((0.4*(double)(*p1.pet[number1]).attack/(double)(*p2.pet[number2]).defend*(moves[0]))+2)*damage_plus1);
						 	b=(*p1.pet[number1]).HP-(((0.4*(double)(*p2.pet[number2]).attack/(double)(*p1.pet[number1]).defend*(moves[1]))+2)*damage_plus2);
					 	cout<<a<<endl;
					 	cout<<b<<endl;
					//cout<<damage_plus1<<endl;
					if((*p1.pet[number1]).speed>(*p2.pet[number2]).speed)
					{
					    (*p2.pet[number2]).set_blood(a);
					    HP2=(*p2.pet[number2]).set_blood(a);
					    if((*p2.pet[number2]).HP>0)
					    {
					    	(*p1.pet[number1]).set_blood(b);
					    	HP1=(*p1.pet[number1]).set_blood(b);
						}
					}
					else if((*p1.pet[number1]).speed<(*p2.pet[number2]).speed)
					{
						(*p1.pet[number1]).set_blood(b);
						HP1=(*p1.pet[number1]).set_blood(b);
						if((*p1.pet[number1]).HP>0)
					    {
					    	(*p2.pet[number2]).set_blood(a);
					    	HP2=(*p2.pet[number2]).set_blood(a);
						}
					}
					else if((*p1.pet[number1]).speed==(*p2.pet[number2]).speed)
					{
						if(rand()%2==0)
						{
							(*p2.pet[number2]).set_blood(a);
							HP2=(*p2.pet[number2]).set_blood(a);
					    	if((*p2.pet[number2]).HP>0)
					    	{
					    		(*p1.pet[number1]).set_blood(b);
					    	    HP1=(*p1.pet[number1]).set_blood(b);
							}
						}
						else
						{
							(*p1.pet[number1]).set_blood(b);
							HP1=(*p1.pet[number1]).set_blood(b);
							if((*p1.pet[number1]).HP>0)
					    	{
					    		(*p2.pet[number2]).set_blood(a);
					    		HP2=(*p2.pet[number2]).set_blood(a);
							}
						}
					}	
				  break;	 
				}
			break;
		}
    }
    return 0;
}
