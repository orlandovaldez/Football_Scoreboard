//Orlando Valdez
//Dr_T
//4-13-2020
//Football Scoreboard
#include <iostream>
#include <unistd.h>
#include <iomanip>
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
    int getDown() const { return down;}
    int getToGo() const { return toGo;}
    bool getPoss() const { return poss;}
    Team getHometeam() const { return Hometeam; }
    Team getVisitors() const { return Visitors; }

    void showScoreboard()
    {
      string color,colorRed = "";
      string reset = "\x1b[0m";

        system("clear"); //clears the screen after loop refresh
        color = "\x1b[32;1m";
        colorRed = "\x1b[31;15m";

        cout << color << "つ ◕_◕ ༽つ Football Scoreboard つ ◕_◕ ༽つ " << reset << endl;
        cout << setw(24) << "||10:37||" << endl;
        for( int i = 0; i < 40; i++) {cout << "$";}
        cout << endl;
        cout << setw(9)<< "HomeTeam" << setw(29) <<"Visitors" << endl;
        cout << setw(10) <<  Hometeam.getTeamName() << setw(29) << Visitors.getTeamName()  << endl;

        cout << setw(6) << Hometeam.getTeamScore() << setw(30) << Visitors.getTeamScore() << endl;
        if(poss == true)
        {
        cout << setw(22)  << colorRed << "O<"<< reset << " POSS" << endl;
        }
        else
        {
        cout << setw(22) <<  "POSS" << colorRed << " >O" << reset << endl;

        }
        cout << setw(25) << "Quarter: " << quarter << endl;
        cout << "\n" << endl;

        cout << setw(10) << getDown() << " < Down" << setw(16) << "To Go > " << getToGo() << "\n" << endl;

        for( int i = 0; i < 40; i++) {cout << "$";}
        cout << endl;

    };

};

void scorebaordEdit()
{
  Scoreboard s;
  Team HometeamBoard;//object for Team that becomes Scoreboard member
  Team VisitorsBoard;//object for Team that becomes Scoreboard member
  char choice = '\0';
  int newTeamScore = 0;
  int newQuarter = 0;
  int newDown;
  int newToGo;
  bool newPoss;
  string newTeamName = "";
  string newCoachName = "";
  string newHomeCity = "";
  string MenuColor = "";
  string MenuReset = "";

  s.setHometeam(HometeamBoard);
  s.setVisitors(VisitorsBoard);

  do 
  {
    s.showScoreboard();
    MenuColor = "\x1b[31;15m";
    MenuReset = "\x1b[0m";
    cout << MenuColor;//Change Menu color to red
    cout << "\nMenu:" << endl;
    cout << "A. Update Hometeam Name" << endl;
    cout << "B. Update Visitors Name" << endl;
    cout << "C. Update Hometeam Score" << endl;
    cout << "D. Update Visitors Score" << endl;
    cout << "E. Update Quarter " << endl;
    cout << "F. Update Downs " << endl;
    cout << "G. Update To Go " << endl;
    //cout << "H. Update Hometeam Coach" << endl;
    //cout << "I. Update Visitors Coach" << endl;
    //cout << "J. Update Hometeam HomeCity" << endl;
    //cout << "K. Update Visitors HomeCity" << endl;
    cout << "L. Update Possesion" << endl;

    cout << "X. To Exit Scoreboard\n" << endl;
    cout << "Enter Choice Here....> ";
    cout << MenuReset;// reset menu color to white for legibility in choice selection

    cin >> choice;

    if(choice == 'A' || choice == 'a')
    {
      cout << "\nHometeam Name Update \n";
      cout << "What Is The New Team Name? ";
      cin >> newTeamName;
      HometeamBoard.setTeamName(newTeamName);
      cout << "Updating Team Name for Hometeam to " << HometeamBoard.getTeamName() << endl;
      sleep(1); 

    }
    else if(choice == 'B' || choice == 'b')
    {
      cout << "\nVisitors Name Update \n";
      cout << "What Is The New Team Name?...> ";
      cin >> newTeamName;
      VisitorsBoard.setTeamName(newTeamName);
      cout << "Updating Team  Name for Visitors to  " << VisitorsBoard.getTeamName() << endl;
      sleep(1);
    }
    else if(choice == 'C' || choice == 'c')
    {
      cout << "\nHometeam Score Update \n" ;
      cout << "What is the new score?...> ";
      cin >> newTeamScore;
      HometeamBoard.setTeamScore(newTeamScore);
      cout << "\nUpdating New Hometown Score To ..." << HometeamBoard.getTeamScore() << endl;
      sleep(1);
    }
    else if(choice == 'D' || choice == 'd')
    {
      cout << "\nVisitor Score Update \n" ;
      cout << "What Is The New Score?...> ";
      cin >> newTeamScore;
      VisitorsBoard.setTeamScore(newTeamScore);
      cout << "\nUpdating New Visitor Score To ..." << VisitorsBoard.getTeamScore() << endl;
      sleep(1);
    }    
    else if(choice == 'E' || choice == 'e')
    {
      cout << "\nQuarter Update \n";
      cout << "What Is The Updated Quarter? ...>";
      cin >> newQuarter;
      s.setQuarter(newQuarter);
      cout << "\nUpdating Quarter To ..." << s.getQuarter() << endl;
      sleep(1);
    }
    else if(choice == 'F' || choice == 'f')
    {
      cout << "\nDown Update \n";
      cout << "What is the new Down? ...>";
      cin >> newDown;
      s.setDown(newDown);
      cout << "\nUpdating Down To ..." << s.getDown() << endl;
      sleep(1);
    }
    else if(choice == 'G' || choice == 'g')
    {
      cout << "\nTo Go Update \n";
      cout << "What Is The New To Go? ...>";
      cin >> newToGo;
      s.setToGo(newToGo);
      cout << "\nUpdating  To Go To ..." << s.getToGo() << endl;
      sleep(1);
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
    else if(choice == 'L' || choice == 'l')
    {
      cout << "\nPossession Update\n";
      cout << "Who Has Possesion?( 1 For Hometeam, 0 For Visitors)...>";
      cin >> newPoss;
      s.setPoss(newPoss);
      cout << "\nUpdating Possesssion To ... " << s.getPoss() << endl;
      sleep(2);
    }
  s.setHometeam(HometeamBoard);
  s.setVisitors(VisitorsBoard);               
  }while(choice != 'x' && choice != 'X');
  {
    cout << "\nAnd That's Game Over.... See Ya Later Champ" << endl;
    cout << "\nGO Cowboys! " << endl;
  }


}

int main() 
{
  scorebaordEdit();

return 0;
}