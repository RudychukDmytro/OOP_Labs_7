#include "tournament.h"
#include <iostream>

int main()
{
    FootballPlayer player1("John Doe", 5, 2);
    FootballPlayer player2("Jane Smith", 7, 3);

    Team team1("The Eagles");
    team1.addPlayer(player1);
    team1.addPlayer(player2);

    Judge judge1("Referee Mike");

    FootballTournament tournament;
    tournament.addTeam(team1);
    tournament.addJudge(judge1);
    tournament.scheduleMatch("Stadium A", "2024-10-10");

    tournament.displaySchedule();
    team1.displayTeamStats();

    // Використання префіксного та постфіксного оператора '++'
    std::cout << "\nIncrementing goals for John Doe..." << std::endl;
    ++player1;
    player1++;
    player1.displayStats();

    // Використання префіксного та постфіксного оператора '--'
    std::cout << "\nDecreasing yellow cards for Jane Smith..." << std::endl;
    --player2;
    player2--;
    player2.displayStats();

    return 0;
}
