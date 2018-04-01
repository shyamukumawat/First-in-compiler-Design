
////////////////////////NOTE I am using '!'   as   epsilon ///////////////////////////////////////////// 


#include<bits/stdc++.h>
using namespace std;
vector<string>first[100];
vector<string >v[100];
int nop;
string findFirst(char x,int ii)
{  string s,ss,prd,xx="\0";
   s.insert(s.end(),x);
   int i,j,k;
   for(i=0;i<nop;i++)
   {  if(v[i][0]==s&&i!=ii)
      {
      ss="\0";
      prd=v[i][1];

         for(j=0;j<prd.size();j++)
         {  if(j==0||(j-1>0&&prd[j-1]=='/'))
             {    if(prd[j]=='!')
                   {ss.insert(ss.end(),prd[j]);ss.insert(ss.end(),' ');}
                  else if(prd[j]<65||prd[j]>90)
                  {ss.insert(ss.end(),prd[j]);ss.insert(ss.end(),' ');}
                  else
                  { xx=findFirst(prd[j],i);
                    ss=ss+xx;
                  }


             }

         }
      }
   }
   return ss;
}
main()
{
    cout<<"Enter no of productions :";
    cin>>nop;
    string prd;
    int i,j,k;
    for(i=0;i<nop;i++)
    {  cout<<"Enter left symbol :";
       cin>>prd;
       v[i].push_back(prd);
       cout<<"Enter production :";
       cin>>prd;
       v[i].push_back(prd);
    }
    cout<<"Productions are :";
    for(i=0;i<nop;i++)
    {  cout<<v[i][0]<<"->"<<v[i][1]<<endl;
    }
      string ff;
    for(i=0;i<nop;i++)
    { first[i].push_back(v[i][0]);
      prd=v[i][1];

      ff="\0";
      for(j=0;j<prd.size();j++)
      {  if(j==0||(j-1>0&&prd[j-1]=='/'))
         { if(prd[j]=='!')
           {  ff="\0";
           ff.insert(ff.end(),prd[j]);
           ff.insert(ff.end(),' ');
           first[i].push_back(ff);
           }
           else if(prd[j]<65||prd[j]>90)
           {ff.insert(ff.end(),prd[j]);ff.insert(ff.end(),' ');first[i].push_back(ff);}
           else
           {
           int flag=1,ddd=0;
              while(flag==1)
              {  ff="\0";

                 ff=findFirst(prd[j],i);
                    cout<<ddd<<endl;
                 flag=0;
                 for(k=0;k<ff.size();k++)
                 { if(ff[k]=='!')
                     {   if(j+1<prd.size()&&prd[j+1]!='/')
                           {  j++;
                              if(prd[j]<65||prd[j]>90)
                               {ff.insert(ff.end(),prd[j]);ff.insert(ff.end(),' '); break;}
                               else
                               flag=1;
                           }
                     }
                 }
                 first[i].push_back(ff);
              }


           }
         }

      }
    }
cout<<"First :";
for(i=0;i<nop;i++)
  {  cout<<first[i][0]<<"= {";
  for(j=1;j<first[i].size();j++)
     cout<<first[i][j];
     cout<<"}"<<endl;
  }
}

