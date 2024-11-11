#include<iostream>
using namespace std;

struct Vector
{
  int *niz;
  int log_vel;
  int fiz_vel;

  void vector_new(int n)
  {
    niz = new int[n];
    log_vel = 0;
    fiz_vel = n;
  }

  void vector_delete()
  {
    delete[] niz;
    log_vel = 0;
    fiz_vel = 0;
  }

  void vector_push_back(int value)
  {
    if(log_vel == fiz_vel)
    {
      fiz_vel* = 2;
      int new_niz* = new int[fiz_vel]
      for(int i = 0; i < log_vel; i++)
      {
        new_niz[i] = niz[i];
      }
      delete[] niz;
      niz = new_niz;
    }
    niz[log_vel++] = value;
  }

  void vetor_pop_back()
  {
    if(log_vel > 0)
    {
      log_vel--;
    }
  }

  int vector_front() const
  {
    if(log_vel > 0)
    {
      return niz[0];
    }
    cout<<"Vektor je prazan."<<endl; 
    return -1; 
  }

  int vector_back() const
  {
    if(log_vel > 0)
    {
      return niz[log_vel-1];
    }
    cout<<"Vektor je prazan."<<endl; 
    return -1; 
  }

  int vector_size()
  {
    return log_vel;
  }
};

int main()
{
  Vector v;

  v.vector_new(2);
  v.vector_push_back(10);
  v.vector_push_back(11);
  v.vector_push_back(20);

  cout<<"Prvi element je:"<<v.vector_front()<<endl;
  cout<<"Zadnji element je;"<<v.vector_back()<<endl;
  cout<<"Veličina je;"<<v.vector_size()<<endl;

  v.vetor_pop_back();
  cout<<"Novi zadnji element je;"<<v.vetor_pop_back()<<endl;
  v.vector_delete();
  return 0;
}