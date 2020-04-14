//Orlando Valdez
//Dr_T
//4-13-2020
//Football Scoreboard
#include <iostream>
#include <unistd.h>
using namespace std;

class Team 
{
  private:
    int score;
    string teamName;
    string coachName;
    string HomeCity;

  public:
    Team()
    {
      teamName = "Team Name";
      score = 0;
      coachName = "Coach Name";
      HomeCity = "HomeCity";
      
    }
    void setTeamScore(int s)     { score = s; }
    void setTeamName (string tN) { teamName = tN; }
    void setCoachName(string cN) { coachName = cN; }
    void setHomeCity (string hC) { HomeCity = hC; }

    double getTeamScore() const { return score; }
    string getTeamName()  const { return teamName; }
    string getCoachName() const { return coachName; }
    string getHomeCity()  const { return HomeCity; }




};

class Scoreboard
{
  private:
    int quarter;
    int down;
    int toGo;
    bool poss;//Possesion if the home team has possession of ball true/false
    Team Hometeam;
    Team Visitors;

    

  public:
    Scoreboard()
    {
      quarter = 1;
      poss = true;//HomeTeam will have the ball
      down = 0;
      toGo = 0;
    }
    void setQuarter(int q)   { quarter = q; }
    void setDown   (int d)   { down = d; }
    void setToGo   (int tG)  { toGo = tG; }
    void setPoss   (bool pos){ poss = pos; }
    void setHometeam (Team hT) { Hometeam = hT; }
    void setVisitors (Team vT) { Visitors = vT; }
 
    int getQuarter() const { return quarter;}
    int getDown () const { return down;}
    int getToGo() const { return toGo;}
    bool getPoss () const { return poss;}
    Team getHometeam() const { return Hometeam; }
    Team getVisitors() const { return Visitors; }

    void showScoreboard()
    {
      string color = "";
      string reset = "\x1b[0m";

        //system("clear"); //clears the screen after loop refresh
        color = "\x1b[32;1m";\
        cout << color << " \t\t\tFootball Scoreboard\n " << reset;
        for( int i = 0; i < 40; i++) {cout << "$";}
        cout << endl;

        cout << Hometeam.getTeamName() << "\t\t\t\t\t" << Visitors.getTeamName()  << endl;
        cout << Hometeam.getTeamScore() << "\t\t\t" << Visitors.getTeamScore() << endl;
        cout << "Quarter: " << quarter << endl;

    };

};

void scorebaordEdit()
{
  Scoreboard s;
  Team Hometeam;//object for Team that becomes Scoreboard member
  Team Visitors;//object for Team that becomes Scoreboard member
  char choice = '\0';
  int newTeamScore = 0;
  string newTeamName = "";
  string newCoachName = "";
  string newHomeCity = "";

  s.setHometeam(Hometeam);
  s.setVisitors(Visitors);

  do 
  {
    s.showScoreboard();

    cout << "\nMenu:" << endl;
    cout << "A. Update Team 1 Name" << endl;
    cout << "B. Update Team 2 Name" << endl;
    cin >> choice;

    if(choice == 'A' || choice == 'a')
    {
      cout << "Team 1 Score Update \n";
      cout << "What is the new team name? ";
      cin >> newTeamName;
      Hometeam.setTeamName(newTeamName);
      cout << "Updating Team Name for Hometeam to " << Hometeam.getTeamName() << endl;
      sleep(2); 

    }
    else if(choice == 'B' || choice == 'b')
    {
      cout << "Teanm 2 Score Update \n";
      cout << "What is the new team name? ";
      cin >> newTeamName;
      Visitors.setTeamName(newTeamName);
      cout << "Updating Team  Name for Visitors to  " << Visitors.getTeamName() << endl;
      sleep(2);


    }
    else if(choice == 'C' || choice == 'c')
    {
      cout << "Hometeam Score Update \n" ;
      cout << "What is the new score? ";
      cin >> newTeamScore;
      Hometeam.setTeamScore(newTeamScore);
      cout << "\nUpdating New Hometown Score To ..." << Hometeam.getTeamScore() << endl;
      sleep(2);
    }
    else if(choice == 'D' || choice == 'd')
    {

    }    
    else if(choice == 'E' || choice == 'e')
    {

    }
    else if(choice == 'F' || choice == 'f')
    {

    }
    else if(choice == 'G' || choice == 'g')
    {

    }
    else if(choice == 'H' || choice == 'h')
    {

    }
    else if(choice == 'I' || choice == 'i')
    {

    }
    else if(choice == 'J' || choice == 'j')
    {

    }
    else if(choice == 'K' || choice == 'k')
    {

    }                                    
  }while(choice != 'x' && choice != 'X');

}

int main() 
{
  scorebaordEdit();

return 0;
}