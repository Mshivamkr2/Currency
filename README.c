#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include<queue>
#include<map>
using std::vector;
using std::priority_queue;
using std::min;
using std::map;
long int m1[1000000];

void unions(int i,int j,int n)
{
    int a= m1[i];
    int b= m1[j];
    int x= min(a,b);

    for(int k=0;k<n;k++)
    {
        if(m1[k]==a || m1[k]==b)
            m1[k]=x;
    }
}
double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  int i,j,index1,index2;

  int cor1;
  int cor2;
  priority_queue <double, vector < double >, std::greater<double> > q1;
 map<double,vector<int> > ma;
 map<double,vector<int> > mb;
  for(i=0;i<x.size();i++)
  {

      for(j=0;j<x.size();j++)
      {
          if(i!=j)
          {
          double pt=sqrt(((x[i]-x[j])*(x[i]-x[j]))+((y[i]-y[j])*(y[i]-y[j])));
          q1.push(pt);
          ma[pt].push_back(i);
          mb[pt].push_back(j);

          }

      }
  }
   int n=x.size();
   int edges=0;
   int k=n+1;
  while(edges!=n-1)
  {
      double pi= q1.top();
      q1.pop();
      int c1= ma[pi].back();
      ma[pi].pop_back();
      int c2 = mb[pi].back();
      mb[pi].pop_back();

      if(m1[c1]!=m1[c2])
      {
      unions(m1[c1],m1[c2],n);
      result+=pi;
      edges++;

      }

      else if(m1[c1]==m1[c2])
      {
          continue;
      }

  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
    m1[i]=i;
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
