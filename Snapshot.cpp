//
// Created by Allen Lam on 3/23/22.
//

#include "Snapshot.h"

std::string Snapshot::getInfo() const {
    return info;
}

void Snapshot::setInfo(const std::string& snapInfo) {
    info = snapInfo;
}

Snapshot::Snapshot() {

}
