#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
int main()
{
    long long n=0;
    long long pos=0;
    string PlanText="";
    string key;
    string CipherText;
    int Y=0,k=0,start=0,a=0,b=0,c=0,d=0;
    string letters[]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    cin>>key;
    cin>>PlanText;
    int  found=0;
    int PlanText_Length=PlanText.length();

    string PlayFairMatrix[5][5];
    for(int i=0;i<PlanText.length();i++)
    {
       if((PlanText.find("J",found))!=std::string::npos){
            found=PlanText.find("J",found);
     PlanText.replace(found,1,"I");
    found++;
       }
    }
    found=0;
     for(int i=0;i<key.length();i++)
    {
       if((key.find("J",found))!=std::string::npos){
           found=key.find("J",found);
     key.replace(found,1,"I");
    found++;
       }
    }
    for(int i=0;i<key.length();i++)
    {
        for(int j=0;j<key.length();j++){
        if(key[i]==key[j]&&(i!=j))
        {
          //  cout<<key[i]<<"  "<<i<<"  "<<j<<endl;
            if(j>i)
            key.erase(j,1);
            else if(j<i)
                key.erase(i,1);
        }

        }
    }

  //  cout<<"key= "<<key<<endl;
   // cout<<PlanText<<endl;
      /* if(key.find(letter[8])!=std::string::npos)
        flagi=1;
if(key.find(letter[9])!=std::string::npos)
        flagj=1;*/
    for (int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
        if(Y<key.length())
            {
         PlayFairMatrix[i][j]=key[Y];
         Y++;
           }
        else
        {
            start=0;
            while(start==0)
            {//cout<<letters[k]<<endl;
            if((key.find(letters[k],0))==std::string::npos&&letters[k]!="J")
               {
                 PlayFairMatrix[i][j]=letters[k];
                 start=1;
              //   if(k==8)
               //     k++;
               }
            k++;

            }
        }
    }
    }
string f="";
for(int i=0;i<PlanText.length();i=i+2)
{
   // cout<<"i= "<<i<<endl;
   if( PlanText[i]==PlanText[i+1])
   {
       f=PlanText[i];
    if(f!="X"){
   PlanText.insert(i+1,"X");
   //cout<<"PlanText= "<<PlanText<<endl;

   }
   else{
    PlanText.insert(i+1,"Q");
    //cout<<"PlanText= "<<PlanText<<endl;

   }
   }
}
    if(PlanText.length()%2!=0)
        if(PlanText[PlanText.length()-1]!='X')
        PlanText=PlanText+"X";
        else
          PlanText=PlanText+"Q";

  /*  for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        cout<<PlayFairMatrix[i][j]<<"   ";
    cout<<endl;
    }*/
int ij[2][2]={0};
string letter="";
for(int L=0;L<PlanText.length();L=L+2){
    for(int k=0;k<2;k++){
        for(int i=0;i<5;i++)
            {
            for(int j=0;j<5;j++)
                {letter=letter+PlanText[L+k];
                if(letter==PlayFairMatrix[i][j])
                    {
                      ij[k][0]=i;
                      ij[k][1]=j;
                    }

                    letter="";
                }

            }
    }
   // cout<<ij[0][0]<<"  "<<ij[0][1]<<endl<<ij[1][0]<<"  "<<ij[1][1]<<endl;
  // a= ij[0][0],b=ij[0][1],c=ij[1][0],d=ij[1][1]<<endl;
    if(ij[0][0]==ij[1][0]){
   // cout<<PlayFairMatrix[ij[0][0]][ij[0][1]]<<"   "<<cout<<PlayFairMatrix[ij[1][0]][ij[1][1]]<<endl;
     CipherText= CipherText+PlayFairMatrix[ij[0][0]][(ij[0][1]+1)%5];
     CipherText= CipherText+PlayFairMatrix[ij[1][0]][(ij[1][1]+1)%5];
  //  cout<<PlayFairMatrix[ij[0][0]][(ij[0][1]+1)%5]<<"   "<<cout<<PlayFairMatrix[ij[1][0]][(ij[1][1]+1)%5]<<endl;
     }
     else if(ij[0][1]==ij[1][1]){
  // cout<<PlayFairMatrix[ij[0][0]][ij[0][0]]<<"   "<<cout<<PlayFairMatrix[ij[1][0]][ij[1][1]]<<endl;
     CipherText= CipherText+PlayFairMatrix[(ij[0][0]+1)%5][ij[0][1]];
     CipherText= CipherText+PlayFairMatrix[(ij[1][0]+1)%5][ij[1][1]];
  //   cout<<PlayFairMatrix[(ij[0][0]+1)%5][ij[0][1]]<<"   "<<PlayFairMatrix[(ij[1][0]+1)%5][ij[1][1]]<<endl;
     }
     else
     {
    // cout<<PlayFairMatrix[ij[0][0]][ij[0][0]]<<"   "<<cout<<PlayFairMatrix[ij[1][0]][ij[1][1]]<<endl;
       CipherText= CipherText+PlayFairMatrix[ij[0][0]][ij[1][1]];
       CipherText= CipherText+PlayFairMatrix[ij[1][0]][ij[0][1]];
   // cout<<PlayFairMatrix[ij[0][0]][ij[1][1]]<<"   "<<PlayFairMatrix[ij[1][0]][ij[0][1]]<<endl;
     }
}
cout<<CipherText<<endl;
    return 0;
}
