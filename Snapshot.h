//
// Created by Allen Lam on 3/23/22.
//

#ifndef SFML_TEST_SNAPSHOT_H
#define SFML_TEST_SNAPSHOT_H
#include <string>

class Snapshot {
private:
    std::string info;
public:
    Snapshot();
    std::string getInfo() const;
    void setInfo(const std::string& snapInfo);
};


#endif //SFML_TEST_SNAPSHOT_H
