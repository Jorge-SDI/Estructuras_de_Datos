#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Team {
    string Name;
    string Country;
};

struct Match {
    Team Home;
    Team Away;
    int goalsHome;
    int goalsAway;
};

int main() {
    vector<Team> group1;
    vector<Team> group2;
    vector<Match> Ro16;
    vector<Team> Qualified;

    group1.push_back({"Arsenal FC", "England"});
    group1.push_back({"Bayern Munich", "Germany"});
    group1.push_back({"Liverpool", "England"});
    group1.push_back({"Tottenham Hotspur", "England"});
    group1.push_back({"FC Barcelona", "Spain"});
    group1.push_back({"Chelsea FC", "England"});
    group1.push_back({"Sporting Lisboa", "Portugal"});
    group1.push_back({"Manchester City ", "England"});

    group2.push_back({"Real Madrid", "Germany"});
    group2.push_back({"Atletico de Madrid", "Spain"});
    group2.push_back({"Tottenham Hotspur", "England"});
    group2.push_back({"FC Barcelona", "Spain"});
    group2.push_back({"Chelsea FC", "England"});
    group2.push_back({"Sporting Lisboa", "Portugal"});
    group2.push_back({"Manchester City ", "England"});
    group2.push_back({"Bayern Munich", "Germany"});



    return 0;
}