#include<iostream>
#include<math.h>
/* Lineini uravneniq, izpolzvashti Gausova eliminaciq C++*/
using namespace std;
int main()
{
    int i,j,k,n;
    
    cout<<"Vavedete: ";        
    cin>>n;
    
    /* ako nito edno ot uravneniqta e n, togava razmerat na urelichenata matrica shte bade n * n + 1. Taka che tuk deklarirame 2d masiv mat s razmer n+n+1 */
    float mat[n][n+1];
    
    float res[n];
   
    cout<<"\nVavedete elementnite na razshirenata matrica: \n";
    for(i=0;i<n;i++)
    {
      for(j=0;j<n+1;j++)
    {
      cin>>mat[i][j]; 
    }    
    }
  
    for(i=0;i<n;i++) 
    {                   
        for(j=i+1;j<n;j++)
        {
            if(abs(mat[i][i]) < abs(mat[j][i]))
            {
                for(k=0;k<n+1;k++)
                {
                    /* razmenqme mat[i][k] i mat[j][k] */
        mat[i][k]=mat[i][k]+mat[j][k];
                    mat[j][k]=mat[i][k]-mat[j][k];
                    mat[i][k]=mat[i][k]-mat[j][k];
                }
            }
      }
    }
   
     /* Deistvieto na Gausova eliminaciq */
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            float f=mat[j][i]/mat[i][i];
            for(k=0;k<n+1;k++)
            {
              mat[j][k]=mat[j][k]-f*mat[i][k];
      		}
        }
    }
 
    for(i=n-1;i>=0;i--)          
    {                     
        res[i]=mat[i][n];
                    
        for(j=i+1;j<n;j++)
        {
          if(i!=j)
          {
              res[i]=res[i]-mat[i][j]*res[j];
    }          
  }
  res[i]=res[i]/mat[i][i];  
    }
    
    cout<<"\nStoinostite na neizvestnite gorni uravneniq=>\n";
    for(i=0;i<n;i++)
    {
      cout<<res[i]<<"\n";
    }
      
    return 0;
}

/* Vavejdane: 2
Vavejdane na elementite na rashirenata matrica:
3 -1 7
2 3 1 

Stoinostite na neizvestnite za gornite uravneniq=> 2 -1

 */
