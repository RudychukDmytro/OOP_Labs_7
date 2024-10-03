#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <string>
#include <vector>

class FootballPlayer
{
public:
    FootballPlayer(const std::string &name, int goals, int yellowCards);

    void displayStats() const;

    // Префіксні та постфіксні оператори '++' і '--'
    FootballPlayer &operator++();   // Префіксне збільшення
    FootballPlayer operator++(int); // Постфіксне збільшення
    FootballPlayer &operator--();   // Префіксне зменшення
    FootballPlayer operator--(int); // Постфіксне зменшення

private:
    std::string name;
    int goals;
    int yellowCards;
};

class Team
{
public:
    Team(const std::string &name);
    void addPlayer(const FootballPlayer &player);
    void displayTeamStats() const;

private:
    std::string name;
    std::vector<FootballPlayer> players; // Використовуємо STL vector для зберігання гравців
};

class Judge
{
public:
    Judge(const std::string &name);
    std::string getName() const;

private:
    std::string name;
};

// Абстрактний клас Tournament
class Tournament
{
public:
    virtual void scheduleMatch(const std::string &location, const std::string &date) = 0; // чисто віртуальна функція
    virtual void displaySchedule() const = 0;
    virtual ~Tournament() {}
};

class FootballTournament : public Tournament
{
public:
    FootballTournament();
    void addTeam(const Team &team);
    void addJudge(const Judge &judge);
    void scheduleMatch(const std::string &location, const std::string &date) override;
    void displaySchedule() const override;

private:
    std::vector<Team> teams;   // Використовуємо STL vector для зберігання команд
    std::vector<Judge> judges; // Використовуємо STL vector для зберігання суддів
    std::string matchLocation;
    std::string matchDate;
};

#endif
