#include "tournament.h"
#include <iostream>

FootballPlayer::FootballPlayer(const std::string &name, int goals, int yellowCards)
    : name(name), goals(goals), yellowCards(yellowCards) {}

void FootballPlayer::displayStats() const
{
    std::cout << "Player: " << name << ", Goals: " << goals << ", Yellow Cards: " << yellowCards << std::endl;
}

// Префіксне збільшення '++'
FootballPlayer &FootballPlayer::operator++()
{
    ++goals;
    return *this;
}

// Постфіксне збільшення '++'
FootballPlayer FootballPlayer::operator++(int)
{
    FootballPlayer temp = *this;
    goals++;
    return temp;
}

// Префіксне зменшення '--'
FootballPlayer &FootballPlayer::operator--()
{
    --yellowCards;
    return *this;
}

// Постфіксне зменшення '--'
FootballPlayer FootballPlayer::operator--(int)
{
    FootballPlayer temp = *this;
    yellowCards--;
    return temp;
}

Team::Team(const std::string &name) : name(name) {}

void Team::addPlayer(const FootballPlayer &player)
{
    players.push_back(player); // Додаємо гравця до вектора
}

void Team::displayTeamStats() const
{
    std::cout << "Team: " << name << std::endl;
    for (const auto &player : players)
    {
        player.displayStats();
    }
}

Judge::Judge(const std::string &name) : name(name) {}

std::string Judge::getName() const
{
    return name;
}

FootballTournament::FootballTournament() : matchLocation(""), matchDate("") {}

void FootballTournament::addTeam(const Team &team)
{
    teams.push_back(team); // Додаємо команду до вектора
}

void FootballTournament::addJudge(const Judge &judge)
{
    judges.push_back(judge); // Додаємо суддю до вектора
}

void FootballTournament::scheduleMatch(const std::string &location, const std::string &date)
{
    matchLocation = location;
    matchDate = date;
}

void FootballTournament::displaySchedule() const
{
    std::cout << "Match scheduled at " << matchLocation << " on " << matchDate << std::endl;
}
