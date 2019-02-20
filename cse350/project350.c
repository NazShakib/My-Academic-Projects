/*
    Sohely Towhid          2015-2-60-101
    Nabil Al Raian         2015-2-60-081
    Nazmus Sakib Patwary   2015-2-60-092
*/

#include <stdio.h>
#include<conio.h>
#include <stdbool.h>
#include<string.h>


char Reminder[500];
char finalData[500];

char* findFCS(char *frame,char divisor[])
{
    int i,j,divisorLength,frameLength;
    char temp[500],quot[100],remind[500],divisors[500],extra[500];
   // length of divisor and frame
    divisorLength=strlen(divisor);
    frameLength=strlen(frame);

   //copy divisor and frame another character array

    strcpy(divisors,divisor);
    strcpy(extra,frame);

    //putting '0' after length of frame value

    for (i=0; i<divisorLength-1; i++){
        extra[frameLength+i]='0';
    }

    //copy from frame which is equal to divisor length

    for (i=0; i<divisorLength; i++){
        temp[i]=extra[i];
    }


    for (i=0; i<frameLength; i++)
    {
        quot[i]=temp[0];
        if(quot[i]=='0')
        {

            for (j=0; j<divisorLength; j++){
                divisor[j]='0';
            }

        }
        else
        {
            for (j=0; j<divisorLength; j++){
                divisor[j]=divisors[j];
            }

        }
    //this is the XOR part which is generate FCS value
        for (j=divisorLength-1; j>0; j--)
        {
            if(temp[j]==divisor[j]){
                remind[j-1]='0';
            }

            else{
                remind[j-1]='1';
            }

        }

        //after generate the FCS we just added with the frame
        remind[divisorLength-1]=extra[i+divisorLength];
        strcpy(temp,remind);
    }

    strcpy(remind,temp);
    //here is FCS,store in Reminder
    for (i=0; i<divisorLength-1; i++){
        Reminder[i]=remind[i];
    }

    for (i=0; i<frameLength; i++){
        finalData[i]=frame[i];
    }
    //finalData store the final frame with FCS
    for (j=0; i<frameLength+divisorLength-1; i++,j++){
        finalData[i]=remind[j];
    }

    return finalData;
}


bool checkData(char* frame,char divisor[])
{
    int yesNo,randomIndex,i,j;
    char changeFrame[1000];
    strcpy(changeFrame,findFCS(frame,divisor));// here changeFrame have the Transmitter latest data

    yesNo=rand()%2; //randomly choose decision, set error or exit it normally

    randomIndex=rand()%40; // randomly generated index number
    if(!yesNo)
    {
        if(changeFrame[randomIndex]=='1')
        {
            changeFrame[randomIndex]='0';
        }

        else{
            changeFrame[randomIndex]='1';
        }

    }
    //Receiver also sent frame to check ,have there any error
    strcpy(changeFrame,findFCS(changeFrame,divisor));


    printf("\t\t\t\t\t\tReminder : %s",Reminder);
    for(i=0; Reminder[i]; i++)
    {
        if(Reminder[i]=='1')
        {
            return true;
        }
    }
    return false;
}


int main()
{
    int frameSize;
    char Frame[500][500];
    int i,j,start,last,check,switchBit,flag=0;


    printf("\n\t\t\t\tStop and Wait Data Control Flow");

    printf("\n\nTotal Transmitted Frame Number : ");
    scanf("%d",&frameSize);



    for(i=0; i<frameSize; i++)
    {
        for(j=0; j<40; j++)
        {
            Frame[i][j]=((rand()%2)+48);   //Randomly Generate 40 bit for per frame

        }
    }

    printf("\n\t\t\t\t\tSending Data using (Frame[0] To Frame[%d])\n",frameSize-1);
    printf("\n\t\t\t\t[SENDER]>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>[RECEIVER]\n");
    for(i=0; i<frameSize; )
    {

        start=i;
        last=(frameSize-1);


        printf("\n");

        for(j=start; j<=last; j++)
        {
            check=0;
            char divisor[]="11000000000000101";
            printf("\n\nPress Any key to continue...");
            getch();
            system("cls");
            printf("\n\t\t\tCurrent frame[%d] out of %d : %s\n\n",j,frameSize,Frame[j]);
            printf("\n\t\t\t\t\t\tDivisor : %s\n\n",divisor);

            if(!checkData(Frame[j],divisor))
            {
                if((j+1)%2 != 0)
                {
                    switchBit=1;
                    printf("\n\n\t\t\t There is no Error in Data and The Frame[0] is Successfully Received by Receiver\n",switchBit);
                    printf("\n\t\t\t\t\t   Acknowledgment (ACK-%d) sent\n",switchBit);
                    printf("\t\t\t\t[SENDER]<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<[RECEIVER]\n");
                     if(j==last)
                     {
                         flag=1;
                     }

                }
                else
                {
                    switchBit=0;
                    printf("\n\n\t\t\t There is no Error in Data and The Frame[1] is Successfully Received by Receiver\n");
                    printf("\n\t\t\t\t\t   Acknowledgment (ACK-%d) sent\n",switchBit);
                    printf("\t\t\t\t[SENDER]<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<[RECEIVER]\n");
                     if(j==last)
                     {
                         flag=1;
                     }
                }

            }
            else
            {
                if((j+1)%2 != 0)
                {
                    switchBit=0;
                    printf("\n\n\t\t\t\t\t Error Found on Frame[%d]\n",switchBit);
                    printf("\n\t\t\t\t\tHave to Re-Send Frame[%d]\n",switchBit);
                    printf("\n\t\t\t\t\tNegative Acknowledgment (NAK- %d) sent\n",switchBit);
                    printf("\t\t\t\t[SENDER]<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<[RECEIVER]\n");
                }
                else
                {
                    switchBit=1;
                    printf("\n\n\t\t\t\t\t Error Found on Frame[%d]\n",switchBit);
                    printf("\n\t\t\t\t\tHave to Re-Send Frame[%d]\n",switchBit);
                    printf("\n\t\t\t\t\tNegative Acknowledgment (NAK- %d) sent\n",switchBit);
                    printf("\t\t\t\t[SENDER]<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<[RECEIVER]\n");

                }

                i=j;
                check=1;

            }
            if(check==1)
            {
                break;
            }
        }
        if(flag==1)
        {
            break;
        }

    }
    int counter =0;
    for(j=0; j<frameSize; j++)
      {
          if(counter ==0)
          {
              printf("\n\n\t\t\t\tFrame : %d",j);
          }
          else
          {
            printf(" ,%d",j);
          }
          counter++;
      }
      printf(" are received successfully\n");

    printf("\n\n\t\t----------------------- All frames are transmitted Successfully--------------------\n\n\n\n");

    return 0;

}
