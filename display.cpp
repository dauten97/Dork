
 
#include "dork.h"

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds


void display_init()
{
	initscr();			/* Start curses */
	raw();
	echo();
}

void display_close()
{
	endwin();			/* End curses   */
	exit(0);			/* Make clean exit */
}	

void intro_display()
{
	    std::ifstream Art("art.txt");
	    std::ifstream Intro("intro.txt");
	    Art.open("art.txt");
	    Intro.open("intro.txt");
	    displaytext(Art);
	    displaytext_delay(Intro);
	    Art.close();
	    Intro.close();	
}
void displaytext (std::ifstream& File)
{
    std::string Lines = "";
    if (File.is_open()) 
    {
		while (File.good())
		{
			std::string TempLine;                  
			std::getline (File , TempLine);
			TempLine += "\n";                     
			Lines += TempLine;
			
		}	
		char myArray[Lines.size()+1];
		strcpy(myArray, Lines.c_str());
		printw(myArray);
		refresh();
	}
    else
    {
	cout<< "ERROR File does not exist." << endl;
    }
}

void displaytext_delay(std::ifstream& File)
{
    std::string Lines = ""; 
    int j=0;
    sleep_for(seconds(3));
    if (File.is_open())  
    {
		while (File.good ())
		{
			std::string TempLines; 
			std::getline (File , TempLines);
			TempLines += "\n";
			char myArray[TempLines.size()+1];
			strcpy(myArray, TempLines.c_str());
				for (int i=0; i<TempLines.size();i++)
				{
				mvaddch(j,(40+i),myArray[i]);
				refresh();
				sleep_for(milliseconds(50));
				}
			j=j+1;
			refresh();
			sleep_until(system_clock::now() + seconds(1));
		}
		printw("###################$$$$$$$$$$$$$$$$###################\n");
		printw("                   WELCOME TO DORK\n");
		printw("###################$$$$$$$$$$$$$$$$###################\n");
    }
    else                           //Return error
    {
	cout<< "ERROR File does not exist." << endl;
    }
}

void clearDisplay(int num){
	if(num==0)
	clear();
	else{
	clear();
	std::ifstream banner ("banner.txt"); 
	displaytext(banner);}
	refresh();
}
