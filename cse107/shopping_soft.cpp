#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include<fstream>
using namespace std;

static int Fsn,Csn,Tsn,Gpn,Spn,Jpn;
int pis;

class product
{
public:
//Formal shirt member.
    float Fs_code,Fsp=0.0,Fsp_rate,Fpf;
    int Fsn=0;

//Casual shirt member.
    float Cs_code,Csp=0.0,Csp_rate,Cpf;
    int Csn=0;

////T shirt member.
    float Ts_code,Tsp=0.0,Tsp_rate,Tpf;
    int Tsn=0;

//Gavading pant member.
    float Gp_code,Gpp=0.0,Gpp_rate,Gpf;
    int Gpn=0;

//Jeans pant member.
    float Jp_code,Jpp=0.0,Jpp_rate,Jpf;
    int Jpn=0;

//Short pant member.
    float Sp_code,Spp,Spp_rate,Spf;
    int Spn=0;

//show Room rent & sellsman charge .
    float s_r=0.0,sel_mc=0.0,others;

// Profit and new price.
    float pf=0.0,percent,F=0,C=0,T=0,G=0,J=0,S=0;
    bool check_percent =0;

    void account_reset()
    {
        Fsp =0;
        Csp=0;
        Tsp=0;
        Gpp=0;
        Jpp=0;
        Spp=0;
        s_r=0;
        sel_mc=0;
        percent=0.0;
    }

    void shirt_profile()
    {

        cout<< "\n\tplease set your product details"<<endl;
        cout<<"\n\tInput your Shirt info "<<endl;

        // Formal shirt info .
        ofstream store_file;
        store_file.open("input.txt",ios::in|ios::out);

        cout<<"\n\tFormal shirt"<<endl<<"Enter price rate : ";
        cin>>Fsp_rate;
        cout<<"\nEnter total Piece : ";
        cin>>Fsn;
        Fsp=Fsp_rate*Fsn;
        store_file<<"\nprice rate of Formal shirt:\t"<<Fsp_rate;
        store_file<<"\ntotal piece of Formal shirt:\t"<<Fsn;


        //  Casual shirt info .

        cout<<"\n\tCasual shirt"<<endl<<"Enter price rate : ";
        cin>>Csp_rate;
        cout<<"\nEnter total Piece : ";
        cin>>Csn;
        Csp=Csp_rate*Csn;

        store_file<<"\nprice rate of casual shirt:\t"<<Csp_rate;
        store_file<<"\ntotal piece of casual shirt:\t"<<Csn;

        // T-shirt info .

        cout<<" \n\tT-shirt "<<endl<<"Enter price rate : ";
        cin>>Tsp_rate;
        cout<<"\nEnter total Piece : ";
        cin>>Tsn;
        Tsp=Tsp_rate*Tsn;

        store_file<<"\nprice rate of T-shirt:\t"<<Tsp_rate;
        store_file<<"\ntotal piece of T-shirt:\t"<<Tsn;


        cout<<"\t\tyour shirt stored successfully"<<endl;

    }
    void pant_profile()
    {
        // Formal shirt info .
        ofstream store_file;
        store_file.open("input.txt",ios::in|ios::out);



        cout<<"\n\tInput your pant info "<<endl;

        // Gavading pant info .

        cout<<" \n\tGavading pant "<<endl<<"Enter price rate : ";
        cin>>Gpp_rate;
        cout<<"\nEnter total Piece : ";
        cin>>Gpn;
        Gpp=Gpp_rate*Gpn;

        store_file<<"\nprice rate of Gavading pant:\t"<<Gpp_rate;
        store_file<<"\ntotal piece of Gavading pant:\t"<<Gpn;


        //   Jeans pant info .

        cout<<" \n\tJeans pant "<<endl<<"Enter price rate : ";
        cin>>Jpp_rate;
        cout<<"\nEnter total Piece : ";
        cin>>Jpn;
        Jpp=Jpp_rate*Jpn;

        store_file<<"\nprice rate of Jeans pant:\t"<<Jpp_rate;
        store_file<<"\ntotal piece of Jeans pant:\t"<<Jpn;

        //   short_pant info .

        cout<<" \n\tShort pant "<<endl<<"Enter price rate : ";
        cin>>Spp_rate;
        cout<<"\nEnter total Piece : ";
        cin>>Spn;
        Spp=Spp_rate*Spn;

        store_file<<"\nprice rate of Short pant:\t"<<Spp_rate;
        store_file<<"\ntotal piece of Short pant:\t"<<Spn;

        cout<<"\t\tyour pant stored successfully"<<endl;



    }
    void total_cost()
    {
        double b_Total;
        b_Total=Fsp+Csp+Tsp+Gpp+Jpp+Spp+s_r+sel_mc;
        cout<<"\n\tYour total cost is : "<<b_Total<<endl;
    }
    void other_cost()
    {
        check_percent=1;
        ofstream store_file;
        store_file.open("input.txt",ios::in|ios::out);
        cout<<"\n\tEnter your showroom rent : ";
        cin>> s_r;
        store_file<<"\nshow room rent:\t"<<s_r;
        cout<<"\n\tEnter your sells man charge : ";
        cin>> sel_mc;
        store_file<<"\nshow sells man charge:\t"<<sel_mc;
        others=(s_r+sel_mc)/2 ;
        cout<<"\n\tYour shop product stored successfully  "<<endl;


        // Profit and new price setup .

        cout<<"\n\n\tPlease Enter How much ('%') profit You want to Earn : ";
        cin>>percent;
        pf=(percent/100);
        store_file<<"\npercent is:\t"<<percent;
        cout<<endl<<"Your other cost setup successfully"<<endl;


        // Set up Shirt Price

        Fs_code=(others/Fsn)+Fsp_rate+(pf*Fsp_rate);
        Cs_code=(others/Csn)+Csp_rate+(pf*Csp_rate);
        Ts_code=(others/Tsn)+Tsp_rate+(pf*Tsp_rate);

        F=Fs_code;
        C=Cs_code;
        T=Ts_code;
        //only profit of Shirt.
        Fpf=pf*Fsp_rate ;
        Cpf=pf*Csp_rate ;
        Tpf=pf*Tsp_rate ;


        // Set up Pant Price

        Gp_code=(others/Gpn)+Gpp_rate+(pf*Gpp_rate);
        Jp_code=(others/Jpn)+Jpp_rate+(pf*Jpp_rate);
        Sp_code=(others/Spn)+Spp_rate+(pf*Spp_rate);

        G=Gp_code;
        J=Jp_code;
        S=Sp_code;
        //only profit of Pant.
        Gpf=pf*Gpp_rate;
        Jpf=pf*Jpp_rate;
        Spf=pf*Spp_rate;


    }


};


class keepsell :public product
{

public:
    static double total,profit;
    void recit()
    {
        double p,sell;
        int pis;
        cout<<"\t\nproduct key for Formal shirt  '10' "<<endl;
        cout<<"\t\nproduct key for Casual shirt  '11' "<<endl;
        cout<<"\t\nproduct key for T-shirt shirt '12' "<<endl;
        cout<<"\t\nproduct key for Gavading pant '20' "<<endl;
        cout<<"\t\nproduct key for Gens pant     '21' "<<endl;
        cout<<"\t\nproduct key for Short pant    '22' "<<endl;
        cout<<"\n\n\tEnter item key & Press 0 to print recit .";
        while(p!=0)
        {
            cout<<" \nEnter product key :";
            cin>>p;
            if(p==10)       //Formal shirt info.

            {
                cout<<"\nEnter total piece : ";

                cin>>pis;

                if(pis<=Fsn && check_percent)
                {


                    sell=pis*F;
                    cout<<"\nFormal shirt : \t"<<pis<<" -piece- "<< " Price :"<<sell<<endl;
                    Fsn-=pis;
                    total+=sell;
                    profit+=(Fpf*pis);
                    pis=0;
                    Fsn=Fsn-pis;
                }
                else if(!check_percent)
                {
                    cout<<"Please Fill Up percentage of profit how do you want!!!"<<endl;
                }

                else
                {
                    cout<<" 'SORRY' This Item aren't available in the store as You want";
                    cout<<"Total Formal Shirt has : "<<Fsn<<"\n\tThank You"<<endl;
                }
            }


            else if(p==11)  //Casual shirt info.
            {
                cout<<"\nEnter total piece : ";

                cin>>pis;
                if(pis<=Csn && check_percent)
                {

                    sell=pis*C;
                    cout<<"\nCasual shirt : \t"<<pis<<" -piece- "<< " Price :"<<sell<<endl;
                    Csn-=pis;
                    total+=sell;
                    profit+=(Cpf*pis);
                    pis=0;
                    Csn=Csn-pis;
                }
                else if(!check_percent)
                {
                    cout<<"Please Fill Up percentage of profit how do you want!!!"<<endl;
                }

                else
                {
                    cout<<" 'SORRY' This Item aren't available in the store as You want";
                    cout<<"Total Casual Shirt has : "<<Csn<<"\n\tThank You"<<endl;
                }
            }


            else if(p==12)  // T shirt info.
            {
                cout<<"\nEnter total piece : ";

                cin>>pis;
                if(pis<=Tsn && check_percent)
                {

                    sell=pis*T;
                    cout<<"\nT shirt : \t"<<pis<<" -piece- "<< " Price :"<<sell<<endl;
                    Tsn-=pis;
                    total+=sell;
                    profit+=(Tpf*pis);
                    pis=0;
                    Tsn=Tsn-pis;
                }
                else if(!check_percent)
                {
                    cout<<"Please Fill Up percentage of profit how do you want!!!"<<endl;
                }

                else
                {
                    cout<<" 'SORRY' This Item aren't available in the store as You want";
                    cout<<"Total T Shirt has : "<<Tsn<<"\n\tThank You"<<endl;
                }
            }


            else if(p==20)  //Gavading pant info.
            {
                cout<<"\nEnter total piece : ";

                cin>>pis;
                if(pis<=Gpn && check_percent)
                {

                    sell=pis*G;
                    cout<<"\nGavading pant : \t"<<pis<<" -piece- "<< " Price :"<<sell<<endl;
                    Gpn-=pis;
                    total+=sell;
                    profit+=(Gpf*pis);
                    pis=0;
                    Gpn=Gpn-pis;
                }
                else if(!check_percent)
                {
                    cout<<"Please Fill Up percentage of profit how do you want!!!"<<endl;
                }

                else
                {
                    cout<<" 'SORRY' This Item aren't available in the store as You want";
                    cout<<"Total Gavading pant has : "<<Gpn<<"\n\tThank You"<<endl;
                }
            }


            else if(p==21) //Jeans pant info.
            {
                cout<<"\nEnter total piece : ";

                cin>>pis;
                if(pis<=Jpn && check_percent)
                {

                    sell=pis*J;
                    cout<<"\njeans pant : \t"<<pis<<" -piece- "<< " Price :"<<sell<<endl;
                    Jpn-=pis;
                    total+=sell;
                    profit+=(Jpf*pis);
                    pis=0;
                    Jpn=Jpn-pis;
                }
                else if(!check_percent)
                {
                    cout<<"Please Fill Up percentage of profit how do you want!!!"<<endl;
                }

                else
                {
                    cout<<" 'SORRY' This Item aren't available in the store as You want";
                    cout<<"Total Jeans pant has : "<<Jpn<<"\n\tThank You"<<endl;
                }
            }


            else if(p==22)  //Short pant info.
            {
                cout<<"\nEnter total piece : ";

                cin>>pis;
                if(pis<=Spn && check_percent)
                {
                    sell=pis*S;
                    cout<<"\nShort pant : \t"<<pis<<" -piece- "<< " Price :"<<sell<<endl;
                    Spn-=pis;
                    total+=sell;
                    profit+=(Spf*pis);
                    pis=0;
                    Spn=Spn-pis;
                }
                else if(!check_percent)
                {
                    cout<<"Please Fill Up percentage of profit how do you want!!!"<<endl;
                }
                else
                {
                    cout<<" 'SORRY' This Item aren't available in the store as You want";
                    cout<<"Total short pant has : "<<Spn<<"\n\tThank You"<<endl;
                }
            }


            else if(p==0 && check_percent)  //Recit show.
            {
                static float v,vat,Vtotal;
                v=total;
                vat=(v*0.05);
                cout<<"\n\t   Your Total Cost = "<<total;
                cout<<"\n\t               VAT = "<<vat;
                cout<<"\n\t----------------------------";
                Vtotal=v+vat;
                cout<<"\n\tTotal including VAT= "<<Vtotal<<"Taka\n";
                cout<<"\n\t ****** Thank You To Stay with Us ****** ";
                cout<<"\n\t    ***        See You Again.     ***\n ";

            }
            else if(!check_percent)
            {
                cout<<"Please Fill Up percentage of profit how do you want!!!"<<endl;
            }

            else cout<<"Invalid input\t please try again"<<endl;
        }
    }

    void check_profit()
    {

        cout<<"\n\tYour current Profit is Now : "<<profit;

        cout<<"\n\n";
    }

    void check_balance()
    {
        cout<<"\n\t***You Have remain This products in the store *** "<<endl;
        cout<<"\n\t\t Formal shirt has  : "<<Fsn;
        cout<<"\n\t\t Casual shirt has  : "<<Csn;
        cout<<"\n\t\t      T shirt has  : "<<Tsn;
        cout<<"\n\t\t Gavading pant has : "<<Gpn;
        cout<<"\n\t\t   Jeans pant has  : "<<Jpn;
        cout<<"\n\t\t   Short pant has  : "<<Spn;
        cout<<"\n\n";
    }

};

double keepsell:: total;
double keepsell:: profit;



int main()
{
    keepsell ks;


    int y=0;
    char a,x;
    ifstream file_read;
    file_read.open("input.txt",ios::in|ios::out);
    bool flag=0;
    while(1)
    {
        cout<<"\n\n\t\t******Welcome to our software****** "<<endl;
        cout<<"-----------------------------------------------------------------------------------"<<endl;
        cout<<"\n\tPress 1 for create product profile .";
        cout<<"\n\tPress 2 for sell product .";
        cout<<"\n\tPress 3 for check profit .";
        cout<<"\n\tPress 4 for check stored balance .";
        cout<<"\n\tPress 5 for profile settings.";
        cout<<"\n\tPress 0 to exit .";

        cout<<"\n-----------------------------------------------------------------------------------"<<endl;

        cout<<"Please Enter Your choice : " ;
        cin>>x;


        if(x=='1')
        {
            if(!file_read.eof())
            {
                system("CLS");

                // file_read.seekg(0,beg);
                //while(file_read((int *)&ks,sizeof ks))
    level1:
                while(1)
                {
                    cout<<endl<<endl;
                    cout<<"-----------------------------------------------------------------------------------"<<endl;
                    cout<<"\tPress 1 to setup shirt profile"<<endl;
                    cout<<"\tPress 2 to setup pant profile"<<endl;
                    cout<<"\tPress 3 to setup other cost(rent,labor and profit percentage) profile"<<endl;
                    cout<<"\tPress 4 to check total cost"<<endl;
                    cout<<"\tPress 0 back to main menu"<<endl;
                    cout<<"\n-----------------------------------------------------------------------------------"<<endl;
                    cout<<"\n\tPlease Enter your choose : ";
                    cin>>a;

                    if(a=='1')
                    {
                        system("CLS");
                        ks.shirt_profile();
                        system ("PAUSE");
                        system("CLS");

                    }
                    else if(a=='2')
                    {
                        system("CLS");
                        ks.pant_profile();
                        system ("PAUSE");
                        system("CLS");


                    }
                    else if(a=='3')
                    {
                        if(!flag)
                        {
                            flag=1;
                            system("CLS");
                            ks.other_cost();
                            system ("PAUSE");
                            system("CLS");
                        }
                        else
                        {
                            system("CLS");
                            cout<<"\t\nYou have stored data"<<endl;
                            system ("PAUSE");
                            system("CLS");
                        }

                    }
                    else if(a=='4')
                    {
                        system("CLS");
                        ks.total_cost();
                        system ("PAUSE");
                        system("CLS");

                    }
                    else if(a== '0')
                    {
                        break;
                    }

                }
                file_read.clear();
                cout<<"congrats Your profile complete successfully .";
                system ("PAUSE");
                system("CLS");
                y+=1;
            }
            else
            {
                system("CLS");
                cout<<"\n\tYour profile already completed\n";
                cout<<"\n\tPlease choose another option\n\tThank You \n";
                system ("PAUSE");
                system("CLS");
            }
        }

        else if(x=='2')
        {
            if(y>0)
            {
                system("CLS");
                ks.recit();
                system ("PAUSE");
                system("CLS");

            }
            else
            {
                system("CLS");
                cout<<"\n\tPlease complete Your product profile First ";
                cout<<"\n\t\t Thank You\n";
                system ("PAUSE");
                system("CLS");

            }
        }
        else if(x=='3')
        {
            if(y>0)
            {
                if(flag==1)
                {
                    system("CLS");
                    ks.check_profit();

                    system ("PAUSE");
                    system("CLS");
                }
                else
                {
                    system("CLS");
                    cout<<"\n\n\t\tPlease fill up the other profile(house rent and labor cost)"<<endl;
                    system ("PAUSE");
                    system("CLS");
                }

            }
            else
            {
                cout<<"Please complete Your product profile First ";
                cout<<"\n\t Thank You\n";
                system ("PAUSE");
                system("CLS");

            }
        }
        else if(x=='4')
        {
            if(y>0)
            {
                system("CLS");
                ks.check_balance();

                system ("PAUSE");
                system("CLS");
            }
            else
            {
                system("CLS");
                cout<<"\t\nPlease complete Your product profile First ";
                cout<<"\n\t Thank You\n";
                system ("PAUSE");
                system("CLS");

            }
        }


        else if(x=='5')
        {
            int c;
            cout<<"\n\tDo You want to reset your profile ? ";
            cout<<"\n\t 1.Yes\n\t 2.No .";
            cout<<"\nPlease Enter Your choice :" ;
            cin>>c;
            if(c==1)
            {
                ks.account_reset();
                system("CLS");
                goto level1;
                system ("PAUSE");
                system("CLS");
            }

            else if(c==2)
            {
                system ("PAUSE");
                system("CLS");
            }

            else
            {
                cout<<"\n\t\tWrong keyword \nPlease try again\n";
                system ("PAUSE");
                system("CLS");
            }
        }

        else if(x=='0')
        {
            system("CLS");
            exit(0);
             system ("PAUSE");
            system("CLS");
            cout<<"\n\t\tYour programme shuting Down ... ";
        }
        else
        {
            system("CLS");
            cout<<"\n\tInvalid keyword Inputed.\n\tPlease try again. "<<endl;
            system ("PAUSE");
            system("CLS");
        }
    }

    return 0;

}
