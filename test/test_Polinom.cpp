#include "Polinom.h"
#include <fstream>
#include <../gtest/gtest.h>

TEST(TPolinom, can_create_polinom)
{
  ASSERT_NO_THROW(TPolinom());
}

TEST(TPolinom, can_multiply)
{
  TPolinom P, P1, P2;
  TMonom a(new double[3]{ 1,1,1 }, 3, -1);
  TMonom b(new double[3]{ 2,2,2 }, 3, 1);
  P1 += a;
  P1 += b;
  TMonom c(new double[3]{ 3,2,1 }, 3, 1);
  TMonom d(new double[3]{ 1,2,3 }, 3, -1);
  P2 += c;
  P2 += d;
  P = P1 * P2;
  string res = P.GetPolinom();
  string expP = "1543-1432-13451234";
  EXPECT_EQ(expP, res);
}

TEST(TPolinom, can_plus)
{
  TPolinom P, P1, P2;
  TMonom a(new double[3]{ 1,1,1 }, 3, -1);
  TMonom b(new double[3]{ 2,2,2 }, 3, 1);
  P1 += a;
  P1 += b;
  TMonom c(new double[3]{ 3,2,1 }, 3, 1);
  TMonom d(new double[3]{ 1,2,3 }, 3, -1);
  P2 += c;
  P2 += d;
  P = P1 + P2;
  string res = P.GetPolinom();
  string expP = "13211222-1123-1111";
  EXPECT_EQ(expP, res);
}

TEST(TPolinom, can_sub)
{

  TPolinom P, P1, P2;
  TMonom a(new double[3]{ 1,1,1 }, 3, -1);
  TMonom b(new double[3]{ 2,2,2 }, 3, 1);
  P1 += a;
  P1 += b;
  TMonom c(new double[3]{ 3,2,1 }, 3, 1);
  TMonom d(new double[3]{ 1,2,3 }, 3, -1);
  P2 += c;
  P2 += d;
  P = P1 - P2;
  string res = P.GetPolinom();
  string expP = "-132112221123-1111";
  EXPECT_EQ(expP, res);
}

//доп задания

TEST(TPolinom, can_write_polinom_to_file)
{
  const int size = 4;
  TPolinom P;
  TMonom a(new double[3]{ 3,2,1 }, 3, 1);
  TMonom b(new double[3]{ 2,1,2 }, 3, -2);
  TMonom c(new double[3]{ 1,2,3 }, 3, 1);
  P += a;
  P += b;
  P += c;
  P.WriteToFile("output.txt");
  string expP = "1321-22121123";
  string Polinom = "";
  ifstream fin("output.txt");
  fin >> Polinom;
  fin.close();
  EXPECT_EQ(expP, Polinom);
}


