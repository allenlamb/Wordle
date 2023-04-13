//
// Created by Allen Lam on 3/23/22.
//

#ifndef SFML_TEST_SNAPSHOTINTERFACE_H
#define SFML_TEST_SNAPSHOTINTERFACE_H
#include "Snapshot.h"
struct SnapshotInterface {
    // return a snapshot of the object's current state
    virtual Snapshot getSnapshot() =0;
    //apply a snapshot to the object
    //This will revert the object back to the state that has been recorded
    // in the snapshot
    virtual void applySnapshot(const Snapshot& snapshot) = 0;
};


#endif //SFML_TEST_SNAPSHOTINTERFACE_H
