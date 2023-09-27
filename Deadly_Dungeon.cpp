//Deadly Dungeon 
	
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <Windows.h>
#include <time.h>
using namespace std;

void start()
	{
		char choose;
		cout<<"Welcome to Deadly Dungeon\n\n";
		cout<<"Choose an option: \n";
		cout<<"	1 - Start\n";
		cout<<"	2 - Exit\n";
		cin>>choose;
		choose=abs(choose);
		
		switch(choose)
			{
				case '1': {cout<<"Let's begin your adventure... ";break;}
				case '2': exit(0);break;
				default: 
					{
						cout<<"Invalid input";
						exit(0);
						break;
					}
			}
	}

void introduction()
	{
		int choose_i;
		bool i;
		i=1;
		cout<<endl<<"\nThe Beggining"<<endl;
		cout<<"\nYou actually don't know how, but you woke up in a strange, dark place. No windows, only fading torch on the wall. There's so quiet. Disturbingly quiet.";
		cout<<"You're looking around and see a yellowed letter. Maybe it's just a silly joke from your friends. \nOr you're just hope so. In this case you decided to took piece of paper and read.";
		
		cout<<"\n\n		Hello";
		cout<<"\n       You're probably wondering what are you doing here. \n       Actually, no one knows that, so you can stop thinking about this nonsense.";
		cout<<"\n		It won't help you anyway. \n		Take this staff and just get out of here if you can. It should be easy. \n		Right?";
	
		cout<<"\n\nYou had no idea what it means, but you need to make the decision: Go or stay here and die. \nWhat you're gonna do?";
		cout<<"\n	1 - Take staff and go ahead";
		cout<<"\n	2 - Be dead\n";
		cin>>choose_i;
		choose_i=abs(choose_i);
	
		while(i==1)
			{
				if(choose_i==1)
				{
					cout<<"\nYou gained a knife and an armor\n";
					i=0;
				}
				else if(choose_i==2)
				{
					cout<<"\n\nYou're dead. <GAME OVER>";
					i=0;
					exit(0);
				}	
				else 
				{
					cout<<"\nInvalid input. Try again: ";	
					cin>>choose_i;
					choose_i=abs(choose_i);
				}
			}
	}

void tutorial()
	{
		cout<<"\n\nWelcome in tutorial";
		cout<<"\nI'm gonna show you basic options and mechanics\nLet's start!";
		
		cout<<"\nIn this game you'll meet creatures which won't enjoy your visit here\nYou need to defend and attack\nYou'll have options to choose, for example:\n     1 - Attack\n        2 - Dodge\n     3 - Drink potion";
		cout<<"\nWhen you're at the fight, your enemies will hurt you, and you need to care about your health. \nTo regenerate your health you can drink a potion, but you have only 3 per fight.";
		
		cout<<"\nWhen your health is 0, you're dead and game is over";
		cout<<"\nNow let's begin truly!";
	}

void fight()
	{
		int health, i, j, k, monster_health[4], damage, choice, chance, dodge, monster, quantity, potions;
		
		for(i=1;i<11;++i)
		{
			cout<<"\n\n\n		Room "<<i;
			health=300;
			potions=0;
			dodge=0;
			monster=0+rand()%(19);
			monster=abs(monster);
			monster=round(monster);
			
				switch(monster)
				{
					case 0 ... 10:
						{
							quantity=1+rand()%(3);
							
							for(j=0;j<quantity;j++) monster_health[j]=60+rand()%(20);
							
							cout<<"\nAfter entering the room, "<<quantity<<" ";                
							
							switch(monster)
							{
								case 0:cout<<"jellies attacked you!";		break;
								case 1:cout<<"skelletons attacked you!";	break;
								case 2:cout<<"zombies attacked you!";		break;
								case 3:cout<<"ghosts attacked you!";		break;
								case 4:cout<<"ghouls attacked you!";		break;
								case 5:cout<<"rats attacked you!";			break;
								case 6:cout<<"scorpions attacked you!";		break;
								case 7:cout<<"phantoms attacked you!";		break;
								case 8:cout<<"medium spiders attacked you!";break;
								case 9:cout<<"large spiders attacked you!";	break;
								case 10:cout<<"goblins attacked you!";		break;
							}
							
							for(j=0; j<quantity; j++)
							{
								cout<<"\n\nYour health: "<<health;
								for(k=0;k<quantity;k++)	cout<<endl<<k+1<<". monster health: "<<monster_health[k];
							
								while(monster_health[j]>0)	
								{
									cout<<"\n\n\nWhat do you gonna do now?";
									cout<<"\n		1 - Attack\n		2 - Dodge\n		3 - Drink potion";
									cout<<"\n		(If you'll choose other option you'll automatically dodge)";
									cin>>choice;
							
									switch(choice)
										{
											case 1:
												{
													chance=0+rand()%10;
													chance=ceil(chance);
												
													if(chance<3) cout<<"\nMonster dodged your attack! \n";
													else
														{
															damage=5+rand()%(2);
															damage=pow(2,damage);
															monster_health[j]=monster_health[j] - damage;
															cout<<"You attacked a monster for "<<damage<<" health points!\n";
															if(monster_health[j]<=0)	cout<<"\n\nYou defeat a monster!";	
														}
													break;		
												}
										
											case 3: 
												{
													if(potions<3)
													{
														if(health<200)	health=health+100;
														else health=300;
														cout<<"\nAfter drunk potion you got 25 health points\n";
														potions=potions+1;
													}	
													else 
													{
														cout<<"\nYou drunk all of your potions! (Dodge automatically)";
														chance=0+rand()%8;
														if(chance>5)	
														{
															cout<<"\nYou dodged successfuly!"; 
															dodge=1;
														}
														
														else cout<<"\nYour dodge failed!";
													}
													break;
												}
												
											default:
												{
													chance=0+rand()%8;
													chance=ceil(chance);
													if(chance>5)	
													{
														cout<<"\nYou dodged successfuly!"; 
														dodge=1;
													}
													else cout<<"\nYour dodge failed!";
													break;
												}	//klamerka default
										} //klamerka switch
									
									if(dodge==0)
										{
											for(k=0;k<quantity;k++)
											{
												if(monster_health[k]>0)
												{
													damage=3+rand()%(2);
													damage=floor(damage);
													damage=pow(2,damage);
													health=health-damage;
													cout<<"\nMonster attacked you for "<<damage<<" health points! (your health: "<<health<<")";
													
													if(health<=0)
													{
														cout<<"\n\nYou're dead. <GAME OVER>";
														exit(0);
													}
												}
											}	
										}
									
								} //klamerka do while
					
							} //klamerka do for z walka z potworami z pokoju
		
							break;
						} //klamerka do case 0 ... 10
						
					case 11 ... 19:
						{
							monster_health[0]=200+rand()%(70);
							cout<<"\nAfter entering the room, ";   
							
							switch(monster)
							{
								case 11:cout<<"werewolf attacked you!";		break;
								case 12:cout<<"demon attacked you!";		break;
								case 13:cout<<"Fallen Angel attacked you!";	break;
								case 14:cout<<"mummy attacked you!";		break;
								case 15:cout<<"cyklop attacked you!";		break;
								case 16:cout<<"vampire attacked you!";		break;
								case 17:cout<<"stone troll attacked you!";	break;
								case 18:cout<<"earth troll attacked you!";	break;
								case 19:cout<<"troll attacked you!";		break;
							}	
							
							cout<<"\n\nYour health: "<<health;
							cout<<endl<<"Monster health: "<<monster_health[0];
							
							while(monster_health[0]>0)	
								{
									cout<<"\n\n\nWhat do you gonna do now?";
									cout<<"\n		1 - Attack\n		2 - Dodge\n		3 - Drink potion";
									cout<<"\n		(If you'll choose bad option you automatically dodge)";
									cin>>choice;
							
									switch(choice)
										{
											case 1:
												{
													chance=0+rand()%10;
												
													if(chance<3) cout<<"\nMonster dodge your attack! \n";
													else
														{
															damage=5+rand()%(3);
															damage=pow(2,damage);
															monster_health[0]=monster_health[0] - damage;
															cout<<"You attacked a monster for "<<damage<<" health points!\n";
															if(monster_health[0]<=0)	cout<<"\n\nYou defeat a monster!";	
														}
													break;		
												}
										
											case 3: 
												{
													if(potions<3)
													{
														if(health<200)	health=health+100;
														else health=300;
														cout<<"\nAfter drunk potion you got 100 health points\n";
														potions=potions+1;
													}	
													else 
													{
														cout<<"\nYou drunk all of your potions! (Dodge automatically)";
														chance=0+rand()%8;
														if(chance>5)	
														{
															cout<<"/nYou dodged successfuly!"; 
															dodge=1;
														}
													}
													break;
												}
												
											default:
												{
													chance=0+rand()%8;
													if(chance>5)	
													{
														cout<<"/nYou dodged successfuly!"; 
														dodge=1;
													}
													break;
												}	//klamerka default
										} //klamerka switch
									
									if(dodge==0)
										{
											{
												if(monster_health[0]>0)
												{
													damage=1000+rand()%(3000);
													damage=sqrt(damage);
													damage=floor(damage);
													health=health-damage;
													cout<<"\nMonster attacked you for "<<damage<<" health points! (your health: "<<health<<")";
													
													if(health<=0)
													{
														cout<<"\n\nYou're dead. <GAME OVER>";
														exit(0);
													}
												}
											}	
										}
									
								} //klamerka do while
					
							break;
						}//klamerka do case 11 ... 19	
				} //klamerka do switch(monster)
		}//klamerka do for z wszystkimi pokojami
	}//klamerka do void fight()

void boss()
	{
		Sleep(1000);
		cout<<"\n\n\n\n\n\n			Something changed...";
		cout<<"\n			After defeat the last enemies suddenly darkness came...";
		cout<<"\n			After a while you saw a strange dark creature\n			It spoke after a while...";
		cout<<"\n\n			 - Welcome in my Dungeon, arrival";
		cout<<"\n			   Maybe you're thinking about why are you here...";
		cout<<"\n			   Now, when you're almost dead, does it matter?";
		cout<<"\n			   Who could beat the Grim Reaper?";
		cout<<"\n			   It's time for your last combat!";
		
		Sleep(500);
		cout<<"\n\nThen Grim Reaper has knocked you down with his scythe...";
		cout<<"\n			 - Your time has passed...";
		Sleep(700);
		cout<<"\n			   Wait, nothing happened?!";
		Sleep(600);
		cout<<"\n			   .";
		Sleep(600);
		cout<<".";
		Sleep(600);
		cout<<".";
		Sleep(1000);
		
		cout<<"\n\n\n\nSuddenly you heard beeping";
		cout<<"\nYou tried to open your eyes and the white blinded you...";
		cout<<"\nHospital white.";
		cout<<"\n\n			 - Patient woke up!";
		cout<<"\nSomeone came over to your bed. It's a doctor.";
		cout<<"\n\n			 - You were in a coma for 3 days.";
		cout<<"\n			   You may be a little dazed for a few  hours.";
		cout<<"\n			   Rest and  don't tire yourself out.";
		cout<<"\n\n			 - Why am i here?";
		cout<<"\n\n			 - You overdosed on energy drinks and spent too much time in front of the computer.";
		cout<<"\n			   You complitely ruined your organism.";
		cout<<"\n			   After you'll leave the hospital, I advise you to limit your time in front of the computer and spend more time outdoors.";
		cout<<"\n			   You also should care more about your nutrition.";
		cout<<"\n			   Now rest and we'll do some medical examinations later.";
	}
	
int main()
{
	srand(time(0));
	string choose_t;
	start();
	introduction();
	
	cout<<"\nDo you want to see a tutorial? Type Y if yes: ";
	cin>>choose_t;
	if(choose_t=="Y" || choose_t=="y") 
		tutorial();
	fight();
	boss();
	
	
	cout<<"\n\n\n\n\n\n					END";
	
}

