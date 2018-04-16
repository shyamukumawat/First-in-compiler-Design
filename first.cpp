
//|||||||||||||||||||||||||||||NOTE I am using '!'   as   epsilon |||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||---------------CDRSHYAMU----------|||||||||||||||||||||||||||||||||||
#include<bits/stdc++.h>
using namespace std;
char fir[100][10];
char fol[100][10];
char prod[100][10];
int n;
int static  nn=0;
string first(char x,int p)
{  string s="\0";
   int flag=0;
   char c;
    int i,j;
    for(i=0;i<n;i++)
    {  if(prod[i][0]==x)
       {  for(j=1;j<strlen(prod[i]);j++)
           {  if(j==1||prod[i][j-1]=='/')
               {  if(prod[i][j]=='!')
                   flag=1;
                   else if(prod[i][j]<65||prod[i][j]>90)
                   c=prod[i][j],s.insert(s.end(),c);
                   else
                     s+=first(prod[i][j],i);

               }
           }
           if(flag==1)
           { for(j=1;j<strlen(prod[p]);j++)
             { if(prod[p][j]==x)
                {
                s+=first(prod[p][j+1],p);
                   break;
                }
             }
           }
           return s;
    }

  }
}
int main()
{  cout<<"Enter NUmber of productions(use ! for epsilon) :";
   cin>>n;
   int i,j,k,l;
   string s;
   char x[10],c,d;
   for(i=0;i<n;i++)
   {  cout<<"Enter left symbol of production :";
      cin>>prod[i][0];
      cout<<"Enter corresponding production :";
      scanf("%s",x);
      strcat(prod[i],x);

   }
   cout<<"Productions: "<<endl;
   for(i=0;i<n;i++)
   {  cout<<prod[i][0]<<"->";
      for(j=1;j<strlen(prod[i]);j++)
       cout<<prod[i][j];
       cout<<endl;
   }
   for(i=0;i<n;i++)
   {   fir[i][0]=prod[i][0];
   for(j=1;j<strlen(prod[i]);j++)
      {   if(j==1||prod[i][j-1]=='/')
          {  if(prod[i][j]=='!')
                 c=prod[i][j],fir[i][strlen(fir[i])]=c;
             else if(prod[i][j]<65||prod[i][j]>90)
                 c=prod[i][j],fir[i][strlen(fir[i])]=c;
             else{
                  s=first(prod[i][j],i);
                  l=strlen(fir[i]);
                  for(k=0;k<s.size();k++)
                   {  fir[i][l+k]=s[k];
                   }
                 }
          }

      }
   }
   cout<<"First :"<<endl;
   for(i=0;i<n;i++)
   {  cout<<fir[i][0]<<"->";
     for(j=1;j<strlen(fir[i]);j++)
       cout<<fir[i][j];
       cout<<endl;
   }
}
