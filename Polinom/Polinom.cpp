#include <math.h>

#include "Polinom.h"

TPolinom::TPolinom() :TList<TMonomData>()
{
}

TPolinom::TPolinom(TPolinom& _v) : TList<TMonomData>(_v)
{
}

TPolinom::~TPolinom()
{
}

TPolinom& TPolinom::operator=(TPolinom& _v)
{
  return *this;
}

TPolinom& TPolinom::operator+=(TMonom& _v)
{
  if (this->root == 0)
  {
    this->root = _v.Clone();
    this->end = this->root;
  }
  else
  {
    TMonom* temp = static_cast<TMonom*>(this->root);
    while (temp != 0)
      if (*temp == _v)
      {
        temp->SetK(temp->GetK() + _v.GetK());
        return *this;
      }
      else
      {
        TMonom* _v2 = _v.Clone();
        if (*temp < _v)
        {
          _v2->SetPrev(temp->GetPrev());
          _v2->SetNext(temp);

          if (temp->GetPrev() != 0)
            temp->GetPrev()->SetNext(_v2);
          else
            this->root = _v2;

          temp->SetPrev(_v2);
          return *this;
        }
        else if (temp->GetNext() == 0)
        {
          _v2->SetPrev(temp);
          temp->SetNext(_v2);
          this->end = _v2;
          return *this;
        }
        else
          temp = static_cast<TMonom*>(temp->GetNext());
      }
  }
  return *this;
}

TPolinom TPolinom::operator*(TPolinom& _v)
{
  TPolinom res;
  TMonom* tmp1 = static_cast<TMonom*>(this->root);
  if (this->root == 0 && _v.root == 0)
    throw - 1;
  while (tmp1 != 0)
  {
    TMonom* tmp2 = static_cast<TMonom*>(_v.root);
    while (tmp2 != 0)
    {
      TMonom tmp3 = *tmp2 * *tmp1;
      res += tmp3;
      tmp2 = static_cast<TMonom*>(tmp2->GetNext());
    }
    tmp1 = static_cast<TMonom*>(tmp1->GetNext());
  }
  return res;
}

TPolinom TPolinom::operator+(TPolinom& _v)
{
  return TPolinom();
}

TPolinom TPolinom::operator-(TPolinom& _v)
{
  return TPolinom();
}

ostream& operator<<(ostream& ostr, const TPolinom& P)
{
  return ostr;
}

istream& operator>>(istream& istr, TPolinom& P)
{
  return istr;
}

//доп задания 

void TPolinom::WriteToFile(string name)
{
  ofstream fout(name.c_str());
  fout << *this;
  fout.close();
}

ofstream& operator<<(ofstream& ofstr, const TPolinom& P)
{
  return ofstr;
}
