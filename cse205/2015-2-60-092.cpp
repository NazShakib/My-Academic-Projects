#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<ctime>

using namespace std;
 int data_store1[1000],data_store2[10000],data_store3[100000],data_cheak1[2000],data_cheak2[20000],data_cheak3[200000];

 void funcation1()
{
    cout<<"------For 1000 Random number data set-----"<<endl;
    int count1=0,ran_value;
    for(int i=1;count1!=1000;i++)
    {
        ran_value =rand()%1000;
        if(data_cheak1[ran_value]!=1)
        {
            count1++;
            data_store1[count1]=ran_value;
            data_cheak1[ran_value]=1;
        }
    }
    sort (data_store1,data_store1+count1);
    int stable_value = 1+rand()%1000,c=0;
    clock_t start1,start2,stop1,stop2;
    double difference1,difference2;
    start1 = clock();
    for(int i=1;i<=1000;i++)
     {
        if(data_store1[i]==stable_value)
        {
            cout<<"\nLinear searching value is = "<<stable_value<<"  and position is= "<<i<<"th"<<endl;
            c++;
            break;
        }
      }
        if(c==0)
        {
            cout<<" random value  is not found  by linear search"<<endl;
        }
      stop1 = clock()-start1;
      difference1 =((std:: clock()-start1) / (double)CLOCKS_PER_SEC)*1000000000;
      cout<<"for linear search need to "<<start1<<" click and "<<difference1<<"  nanosecond "<<endl;
        int i,j,middle_number;
         i=1;
        j=count1;
        int count2=0;
        start2=clock();
        do
          {
             count2++;
            if(count2>=(count1/2))
            {
                  cout<<"Random value is not found by binary search"<<endl;
                  break;
          }

            middle_number=(i+j)/2;
            if(data_store1[middle_number]==stable_value)
            {
                cout<<"Binary searching value is = "<<stable_value<<"  and position is="<<middle_number<<"th"<<endl;
                break;
            }
            else if(data_store1[middle_number]>stable_value)
            {
                j= middle_number-1;
            }
            else if(data_store1[middle_number]<stable_value)
            {
                i =middle_number+1;
            }
        }
     while(data_store1[middle_number]!= stable_value);
     stop2 =clock()-start2;
     difference2 = ((std::clock()- start2) / (double)CLOCKS_PER_SEC)*1000000000;
     cout<<"for Binary search need to "<<stop2<<" click and "<<difference2 <<"  nanosecond "<<endl;
}

 void funcation2()
 {
         cout<<endl<<endl<<"\n------For 10000 Random number data set-----"<<endl<<endl;
    int count1=0,ran_value;
    for(int i=1;count1!=10000;i++)
    {
        ran_value =rand()%10000;
        if(data_cheak2[ran_value]!=1)
        {
            count1++;
            data_store2[count1]=ran_value;
            data_cheak2[ran_value]=1;
        }
    }
    sort (data_store2,data_store2+count1);
    int stable_value = 1+rand()%10000,c=0;
    clock_t start1,start2,stop1,stop2;
    double difference1,difference2;
    start1=clock();
    for(int i=1;i<=10000;i++)
     {
        if(data_store2[i]==stable_value)
        {
            cout<<"\nLinear searching value is = "<<stable_value<<"  and position is= "<<i<<"th"<<endl;
            c++;
            break;
        }
      }
        if(c==0)
        {
            cout<<" random value  is not found  by linear search"<<endl;
        }
        stop1= clock()-start1;
        difference1=(( std::clock() - start1) / (double)CLOCKS_PER_SEC)*1000000000;
        cout<<"for Linear search need to "<<stop1<<" click and "<<difference1 << " nanosecond "<<endl;
        int i,j,middle_number;
        i=1;
        j=count1;
        int count2=0;
        start2=clock();
        middle_number=(i+j)/2;
        do
          {
             count2++;
            if(count2>=(count1/2))
            {
                  cout<<"Random value is not found by binary search"<<endl;
                  break;
          }
            middle_number=(i+j)/2;
            if(data_store2[middle_number]==stable_value)
            {
                cout<<"Binary searching value is = "<<stable_value<<"  and position is="<<middle_number<<"th"<<endl;
                break;
            }
            else if(data_store2[middle_number] > stable_value)
            {
                j= middle_number-1;
            }
            else if(data_store2[middle_number] < stable_value)
            {
                i =middle_number+1;
            }
        }
        while(data_store2[middle_number]!= stable_value);
        stop2= clock()-start2;
        difference2=((std::clock()- start2) / (double)CLOCKS_PER_SEC)*1000000000;
        cout<<"for Binary search need to "<<stop2<<" click and "<<difference2 << " nanosecond "<<endl;
 }

 void funcation3()
 {
         cout<<endl<<endl<<"\n------For 100000 Random number data set-----\n"<<endl<<endl;
    int count1=0,ran_value, temp=1;
    for(int i=1;count1!=100000;i++)
    {
        ran_value = temp+ rand()%100000;
        if(data_cheak3[ran_value]==0)
        {
            count1++;
            data_store3[count1]=ran_value;
            data_cheak3[ran_value]=1;
        }
        ++temp;
    }
    sort (data_store3, data_store3+count1);
    int stable_value = rand()%100000,c=0;
    clock_t start1,start2,stop1,stop2;
    double difference1,difference2;
    start1=clock();
    for(int i=1;i<=100000;i++)
     {
        if(data_store3[i]==stable_value)
        {
            cout<<"\nLinear searching value is = "<<stable_value<<" and position is= "<<i<<"th"<<endl;
            c++;
            break;
        }
      }
        if(c==0)
        {
            cout<<" Random value  is not found  by linear search"<<endl;
        }
        stop1=clock()-start1;
        difference1=(( std::clock()- start1)/(double)CLOCKS_PER_SEC)*1000000000;
        cout<<"for Linear search need to "<<stop1<<" click and "<<difference1 << " nanosecond "<<endl;
        int i,j,middle_number;
         i=1;
        j=count1;
        int count2=0;
        start2=clock();
        do
          {
             count2++;
            if(count2>=(count1/2))
            {
                  cout<<" Random value is not found by binary search"<<endl;
                  break;
            }

               middle_number=(i+j)/2;

            if(data_store3[middle_number]==stable_value)
            {
                cout<<"Binary searching value is = "<<stable_value<<" and position is="<<middle_number<<"th"<<endl;
                break;
            }
            else if(data_store3[middle_number]>stable_value)
            {
                j= middle_number-1;
            }
            else if(data_store3[middle_number]<stable_value)
            {
                i =middle_number+1;
            }
        }
        while(data_store3[middle_number]!= stable_value);

        stop2=clock()-start2;

        difference2=(( std:: clock()-start2)/ (double)CLOCKS_PER_SEC)*1000000000;

        cout<<"for Binary search need to "<<stop2<<" click and "<<difference2 << " nanosecond "<<endl;

 }

 int main()
 {
     funcation1();
     funcation2();
     funcation3();
 }
