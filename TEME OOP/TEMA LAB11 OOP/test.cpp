#include "pch.h"

TEST(TestCaseName, TestName) {


    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

TEST(TestSortare, TestElementeSortate)
{
    int a[5] = { 3, 8 ,0, 1 };
    unsigned int n = 4;
    unsigned int nrelem = 4;
    Sortare <int>(a, n);
    for (unsigned int i = 0; i < nrelem - 1; i++)
    {
        ASSERT_LE(a[i], a[i + 1]);
    }
}

TEST(TestSortare2, TestNrElemente)
{
    int a[5] = { 3, 8 ,0, 1 };
    unsigned int n = 4;
    unsigned int nrelem = 4;
    Sortare <int>(a, n);
    ASSERT_EQ(n, nrelem);
}

TEST(TestSortare3, TestSortarePrimulElement)
{
    int a[5] = { 3, 8 ,0, 1 };
    int b[5] = { 0, 1, 3, 8 };
    unsigned int n = 4;
    unsigned int nrelem = 4;
    Sortare <int>(a, n);
    ASSERT_EQ(a[1], b[1]);
}

TEST(TestSortare4, TestSortareUltimulElement)
{
    int a[5] = { 3, 8 ,0, 1 };
    int b[5] = { 0, 1, 3, 8 };
    unsigned int n = 4;
    unsigned int nrelem = 4;
    Sortare <int>(a, n);
    ASSERT_EQ(a[3], b[3]);
}

TEST(TestSortare5, TestSortareAceleasiElemente)
{
    int a[5] = { 3, 8 ,0, 1 };
    int b[5] = { 3, 8 ,0, 1 };
    unsigned int n = 4;
    unsigned int nrelem = 4;
    int fra[10], frb[10];
    Sortare <int>(a, n);
    int i;
    for (i = 0; i <= 9; i++)
        fra[i] = frb[i] = 0;
    for (i = 0; i < n; i++)
    {
        fra[a[i]]++;
        frb[b[i]]++;
    }
    for (i = 0; i <= 9; i++)
        ASSERT_EQ(fra[i], frb[i]);
}