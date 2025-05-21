#include <gtest/gtest.h>
#include "stud.h"

TEST(StudTest, DefaultConstructor) {
    stud s;
    EXPECT_EQ(s.getVardas(), "");
    EXPECT_EQ(s.getPavarde(), "");
    EXPECT_EQ(s.getGalutinisVid(), 0);
    EXPECT_EQ(s.getGalutinisMed(), 0);
}

TEST(StudTest, Setters) {
    stud s;
    s.setvard("Jonas");
    s.setpava("Jonaitis");
    s.setEgzaminas(9.5);
    s.setVid(8.0);
    s.setMed(8.5);
    EXPECT_EQ(s.getVardas(), "Jonas");
    EXPECT_EQ(s.getPavarde(), "Jonaitis");
    EXPECT_EQ(s.getEgz(), 9.5);
    EXPECT_EQ(s.getGalutinisVid(), 8.0);
    EXPECT_EQ(s.getGalutinisMed(), 8.5);
}

TEST(StudTest, RuleOfFive) {
    // Set up original object
    stud original;
    original.setvard("Jonas");
    original.setpava("Jonaitis");
    original.setEgzaminas(9.5);
    original.setVid(8.0);
    original.setMed(8.5);

    // Copy constructor
    stud copyConstructed(original);
    EXPECT_EQ(copyConstructed.getVardas(), "Jonas");
    EXPECT_EQ(copyConstructed.getPavarde(), "Jonaitis");
    EXPECT_EQ(copyConstructed.getEgz(), 9.5);
    EXPECT_EQ(copyConstructed.getGalutinisVid(), 8.0);
    EXPECT_EQ(copyConstructed.getGalutinisMed(), 8.5);

    // Copy assignment
    stud copyAssigned;
    copyAssigned = original;
    EXPECT_EQ(copyAssigned.getVardas(), "Jonas");
    EXPECT_EQ(copyAssigned.getPavarde(), "Jonaitis");
    EXPECT_EQ(copyAssigned.getEgz(), 9.5);
    EXPECT_EQ(copyAssigned.getGalutinisVid(), 8.0);
    EXPECT_EQ(copyAssigned.getGalutinisMed(), 8.5);

    // Move constructor
    stud toMove;
    toMove.setvard("Moved");
    stud moveConstructed(std::move(toMove));
    EXPECT_EQ(moveConstructed.getVardas(), "Moved");

    // Move assignment
    stud toMoveAssign;
    toMoveAssign.setvard("MoveAssign");
    stud moveAssigned;
    moveAssigned = std::move(toMoveAssign);
    EXPECT_EQ(moveAssigned.getVardas(), "MoveAssign");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}