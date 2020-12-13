#pragma once

#include "Monom.h"

class TPolinom :public TList<TMonomData>
{
public:
  TPolinom();
  TPolinom(TPolinom& _v);
  ~TPolinom();

  TPolinom& operator =(TPolinom& _v);
  TPolinom& operator +=(TMonom& _v);

  TPolinom operator *(TPolinom& _v);
  TPolinom operator +(TPolinom& _v);
  TPolinom operator -(TPolinom& _v);

  friend ostream& operator <<(ostream& ostr, const TPolinom& P);
  friend istream& operator >>(istream& istr, TPolinom& P);

  // ��� ������� 
  // ��� ������� 1 � 3 ����������� � �������� ���� ������ TMonom 
  
  void WriteToFile(string name);
  friend ofstream& operator <<(ofstream& ofstr, const TPolinom& P);
};
