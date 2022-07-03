#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    
    
    
    int row,column,i,j,k,t=0;
    while(t==0){
        cout<<"請輸入矩陣列數";
        cin>>row;
        //row=int(row);
        if(row==0)cout<<"\n"<<"請輸入不為零的數"<<"\n";
        else t=1;
    }
    
    
    while(t==1){
        cout<<"請輸入矩陣行數";
        cin>>column;
        
        if(column==0)cout<<"\n"<<"請輸入不為零的數"<<"\n";
        else t=2;
    }
    
    
    int arr1[row][column]={};//原輸入矩陣
    int arr2[row][column]={};//高斯消去法用矩陣
    int arr3[row][column]={};//交換用
    
    //輸入矩陣
    for(i=0;i<row;i++){
        cout<<"請輸入第"<<i+1<<"列(橫的)的數字，並以空格分開";
        for(j=0;j<column;j++){
            cin>>arr1[i][j];
            arr2[i][j]=arr1[i][j];
            arr3[i][j]=arr1[i][j];
        }
    }
    cout<<"2";
    //高斯消去法
    row--;column--;
    int w=-1,times=0;
    
    for(i=0;i<column;i++){
        i=w+1;
        
        //找到一個pivot position
        for(j=i;j<column;j++){
            
            //判斷整行是否為零
            int sum=0;
            for(k=0;k<row;k++)sum+=arr2[j+times][k];
            if(sum==0)continue;
            
            int pivot=arr2[j][0];
            //如果pivot position值為零，找跟它同行比它下面且不為零的一行
            int p=0;
            if(pivot==0)for(k=0;k<row;k++)if(arr2[j][k]!=0){w=k;p=1;break;}
            if(p==1)for(k=0;k<column;k++){arr2[k][0]=arr3[k][w];arr2[k][w]=arr3[k][0];}
            
            //將本行其他列數字消成零
            for(k=0;k<row;k++){
                if(arr2[k][j]!=0){
                    int differ=arr2[k][j]/pivot*-1;
                    for(int g=0;g<column;g++){arr2[k][g]+=differ;}
                }
            }
            
            w=j;times++;break;
            
        }
        
    }
    
    row++;column++;
    
    for(i=0;i<row;i++){
        cout<<"\n";
        for(j=0;j<column;j++)cout<<setw(7)<<arr2[i][j];
    }
    
    
    
}

