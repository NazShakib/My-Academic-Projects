#include<bits/stdc++.h>
using namespace std;
int countn;
//////////////start page/display//////////

void start_page()
{
    cout<<endl;
    cout<<"......................................................."<<endl;
    cout<<right<<setw(40)<<"EWU Blood Bank & Pharmacy"<<endl;
    cout<<right<<setw(36)<<"Aftab Nagar,Dhaka"<<endl;
    cout<<"......................................................."<<endl<<endl;
}
void start_page2()
{
    cout<<endl<<"    1 . Blood Bank"<<endl<<"    2 . Pharmacy"<<endl<<"    3 . Exit"<<endl;
}
//////////////////////////Start Page for Blood Bank////////////////////
void star_page1()
{
    cout<<endl;
    cout<<"......................................................."<<endl;
    cout<<right<<setw(30)<<"Blood Bank"<<endl;
    cout<<"......................................................."<<endl<<endl;
    cout<<"   1 . Add Donor Information"<<endl;
    cout<<"   2 . Delete Information from Blood Bank"<<endl;
    cout<<"   3 . All Donors List"<<endl;
    cout<<"   4 . Search Blood Group"<<endl;
    cout<<endl<<" Press 0 to back to main menu "<<endl;
}
//////////////////////////Start Page for Pharmacy////////////////////
void pharmacy_start_page()
{
    cout<<endl;
    cout<<"......................................................."<<endl;
    cout<<right<<setw(30)<<"Pharmacy"<<endl;
    cout<<"......................................................."<<endl<<endl;
    cout<<"   1 . Search Medicine"<<endl
        <<"   2 . All Medicines"<<endl
        <<"   3 . Add Medicine"<<endl
        <<"   4 . Delete Medicine"<<endl
        <<"   5 . Update Price"<<endl
        <<"   6 . Sell Medicine"<<endl<<endl
        <<"   Press 0 to back to main menu"<<endl;
}
///////////////////Pharmacy/////////////////////

struct node
{
    string s;
    int price;
    int piece;
    node *next;
    node *prev;
};
node *head,*temp;
void insert(string s,int price,int piece)
{
    node *n=new node;
    n->s=s;
    n->price=price;
    n->piece=piece;
    n->next=NULL;
    n->prev=NULL;
    if(head==NULL)
    {
        head=n;
        temp=n;
    }
    else
    {
        if(s<=head->s)
        {
            temp=n;
            n->next=head;
            head->prev=n;
            head=n;

        }
        else if(s>=temp->s)
        {
            node *temp1;
            while(s>temp->s && temp->next!=NULL)
            {
                temp=temp->next;
            }
            if(temp->next==NULL && s>temp->s)
            {
                temp->next=n;
                n->prev=temp;
                temp=temp->next;
            }
            else
            {
                temp1=temp->prev;
                temp1->next=n;
                n->prev=temp1;
                n->next=temp;
                temp->prev=n;
                temp=n;
            }
        }
        else
        {
            node *temp2;
            while(s<temp->s)
            {
                temp=temp->prev;
            }
            temp2=temp->next;
            temp->next=n;
            n->prev=temp;
            n->next=temp2;
            temp2->prev=n;
            temp=n;
        }
    }
}
void display()
{
    node *t=head;
    if(head==NULL)
    {
        cout<<endl<<"List is Empty"<<endl<<endl;
        return;
    }
    int c=1;
    cout<<endl<<" Medicine list : "<<endl;
    while(t)
    {
        cout<<endl<<c<<" . Name : "<<t->s<<endl<<"   Price per piece : "<<t->price<<" /="<<endl<<"   Pieces : "<<t->piece<<endl;
        t=t->next;
        c++;
    }
    cout<<endl;
}
void search_medicine(string name)
{
    node *t=head;

    while(t)
    {
        if(t->s==name)
        {
            cout<<endl<<"Yes Availabe"<<endl;
            cout<<endl<<"Name : "<<t->s<<endl<<"Price per piece : "<<t->price<<" /= "<<endl<<"Pieces : "<<t->piece<<endl<<endl;
            return;
        }
        else
        {
            t=t->next;
        }
    }
    cout<<endl<<"Not Available"<<endl;
    cout<<endl;
}
int search_medicine_1(string name)
{
    node *t=head;
    while(t)
    {
        if(t->s==name)
        {
            return 1;
        }
        else
        {
            t=t->next;
        }
    }
    return 0;
}
void delete_medicine(string name)
{
    if(head->s==name)
    {
        node *temp=head;
        head=head->next;
        free(temp);
    }
    else
    {
        node *temp=head;
        while(temp->s!=name)
        {
            temp=temp->next;
        }
        node *temp1,*temp2;
        temp1=temp->prev;
        if(temp->next==NULL)
        {
            free(temp);
            temp1->next=NULL;
        }
        else
        {
            temp2=temp->next;
            temp1->next=temp2;
            temp2->prev=temp1;
            free(temp);
        }
    }
}
void update_price(string name,int price)
{
    if(head==NULL)
    {
        cout<<"Haven't any Medicine name in the List"<<endl;
        return;
    }
    node *temp=head;
    while(temp->s!=name)
    {
        temp=temp->next;
    }
    temp->price=price;
}
void update_piece(string name,int piece)
{
    node *temp=head;
    while(temp->s!=name)
    {
        temp=temp->next;
    }
    temp->piece=temp->piece-piece;
}
void update_piece1(string name,int piece)
{
    node *temp=head;
    while(temp->s!=name)
    {
        temp=temp->next;
    }
    temp->piece=temp->piece+piece;
}
int check_quantity(string name,int q)
{
    node *temp=head;
    while(temp->s!=name)
    {
        temp=temp->next;
    }
    if(temp->piece>=q)
    {
        return temp->price;
    }
    return 0;
}
struct node_sell
{
    string name;
    int sell_price;
    int sell_quantity;

};

/////////////////////Blood Bank/////////////////////////

struct BloodNode
{
    string name;
    string phone;
    string bloodGroup;
    struct BloodNode *next;
    struct BloodNode *prev;
};
struct BloodNode *headBlood,*tempBlood;
void AddInformation(string n,string p,string b)
{
    struct BloodNode *blood=new BloodNode;
    blood->name=n;
    blood->phone=p;
    blood->bloodGroup=b;
    blood->next=NULL;
    blood->prev=NULL;
    if(headBlood==NULL)
    {
        headBlood=blood;
        tempBlood=blood;
    }
    else
    {
        if(n<=headBlood->name)
        {
            tempBlood=blood;
            blood->next=headBlood;
            headBlood->prev=blood;
            headBlood=blood;

        }
        else if(n>=tempBlood->name)
        {
            BloodNode *temp1;
            while(n>tempBlood->name && tempBlood->next!=NULL)
            {
                tempBlood=tempBlood->next;
            }
            if(tempBlood->next==NULL && n>tempBlood->name)
            {
                tempBlood->next=blood;
                blood->prev=tempBlood;
                tempBlood=tempBlood->next;
            }
            else
            {
                temp1=tempBlood->prev;
                temp1->next=blood;
                blood->prev=temp1;
                blood->next=tempBlood;
                tempBlood->prev=blood;
                tempBlood=blood;
            }
        }
        else
        {
            BloodNode *temp2;
            while(n<tempBlood->name)
            {
                tempBlood=tempBlood->prev;
            }
            temp2=tempBlood->next;
            tempBlood->next=blood;
            blood->prev=tempBlood;
            blood->next=temp2;
            temp2->prev=blood;
            tempBlood=blood;
        }
    }
}
void delete_Information(string name)
{
    if(headBlood->name==name)
    {
        BloodNode *temp=headBlood;
        headBlood=headBlood->next;
        free(temp);
    }
    else
    {
        BloodNode *temp=headBlood;
        while(temp->name!=name)
        {
            temp=temp->next;
        }
        BloodNode *temp1,*temp2;
        temp1=temp->prev;
        if(temp->next==NULL)
        {
            free(temp);
            temp1->next=NULL;
        }
        else
        {
            temp2=temp->next;
            temp1->next=temp2;
            temp2->prev=temp1;
            free(temp);
        }
    }
}
void search_Blood(string name)
{
    int counter=0;
    BloodNode *temp1=headBlood;
    if(headBlood==NULL)
    {
        cout<<endl<<"List is empty"<<endl;
        return ;
    }
    cout<<endl<<name<<" Doners are : "<<endl;
    while(temp1!=NULL)
    {
        if(temp1->bloodGroup==name)
        {
            cout<<endl<<"Name : "<<temp1->name<<endl<<"Phone : "<<temp1->phone<<endl;
        }
        else
        {
            counter++;
        }
        temp1=temp1->next;
    }
    if(counter!=0)
    {
        cout<<endl<<"Not Available"<<endl;
    }
}
string search_Delete(string name)
{
    int counter=0;
    BloodNode *temp1=headBlood;
    if(headBlood==NULL)
    {
        return 0;
    }
    while(temp1!=NULL)
    {
        if(temp1->bloodGroup==name)
        {
            return temp1->name;
        }
        else
        {
            counter++;
        }
        temp1=temp1->next;
    }
    if(counter!=0)
    {
        return 0;
    }
    return temp1->name;
}
int search_donner_name(string name)
{
    BloodNode *t=headBlood;
    while(t)
    {
        if(t->name==name)
        {
            return 1;
        }
        t=t->next;
    }
    return 0;
}
void display1()
{
    BloodNode *temp1=headBlood;
    if(temp1==NULL)
    {
        cout<<endl<<"List is empty"<<endl;
        return;
    }
    cout<<endl<<"All donors are : "<<endl;
    int s=1;
    while(temp1)
    {
        cout<<endl<<s<<" . Name : "<<temp1->name<<endl<<"    Phone Number : "<<temp1->phone<<endl<<"    Blood Group : ";
        cout<<temp1->bloodGroup<<endl;
        temp1=temp1->next;
        s++;
    }

}
string string_converter(string name)
{
    if(name=="ab+" || name=="Ab+")
    {
        name="AB+";
        return name;
    }
    else if(name=="ab-" || name=="Ab-")
    {
        name="AB-";
        return name;
    }
    if(name[0]>96)
    {
        name[0]=name[0]-32;
    }
    for(int i=1;i<name.length()-1;i++)
    {
        if(name[i]==' ')
        {
            if(name[i+1]>96)
            {
                name[i+1]=name[i+1]-32;
            }
        }
    }
    return name;
}
int main()
{
    vector<node_sell> v;
    head=NULL;
    headBlood=NULL;
    char c;
    string name;
    int price,piece,t;
    string name1,group,phone;
    string receiver,receiverPhone,receiverGroup;
    int quantity;
    char m;

    while(1)
    {
        // system("CLS");
        start_page();
        start_page2();
        cout<<endl<<"Enter Choice : ";
        cin>>c;
        getchar();
        if(c=='1')
        {
            system("CLS");
            while(1)
            {
                star_page1();
                cout<<endl<<"Enter Choice : ";
                cin>>m;
                getchar();
                if( m=='1')
                {
                    system("CLS");
                    cout<<endl<<"Enter Donor Name : ";
                    getline(cin,name1);
                    name1=string_converter(name1);
                    cout<<endl<<"Enter Phone Number : ";
                    getline(cin,phone);
                    cout<<endl<<"Enter Blood Group : ";
                    cin>>group;
                    group=string_converter(group);
                    if(group!="O+" && group!="O-" && group!="A-" && group!="A+" && group!="B+" && group!="B-" && group!="AB+" && group!="AB-")
                    {
                        cout<<endl<<"Invalid blood group"<<endl<<endl;
                    }
                    else
                    {
                         AddInformation(name1,phone,group);
                        cout<<endl<<"Information Added Successfully"<<endl<<endl;
                    }

                    system("PAUSE");
                    system("CLS");
                }
                else if(m=='2')
                {
                    system("CLS");
                    if(headBlood==NULL)
                    {
                        cout<<endl<<"List is empty"<<endl<<endl;
                    }
                    else
                    {
                        cout<<"Enter name to Delete Information : ";
                        cin>>name;
                        name=string_converter(name);
                        if(search_donner_name(name))
                        {
                            delete_Information(name);
                            cout<<endl<<"Deleted"<<endl<<endl;
                        }
                        else
                        {
                            cout<<endl<<"Not stored"<<endl;
                        }
                    }
                    system("PAUSE");
                    system("CLS");
                }
                else if(m=='3')
                {
                    system("CLS");
                    display1();
                    cout<<endl;
                    system("PAUSE");
                    system("CLS");
                }
                else if(m=='4')
                {
                    system("CLS");
                    if(headBlood==NULL)
                    {
                        cout<<endl<<"List is empty"<<endl<<endl;
                    }
                    else
                    {
                        cout<<"Enter Blood Group : ";
                        cin>>group;
                        group=string_converter(group);
                        if(group!="O+" && group!="O-" && group!="A-" && group!="A+" && group!="B+" && group!="B-" && group!="AB+" && group!="AB-")
                        {
                            cout<<endl<<"Invalid blood group"<<endl<<endl;
                        }
                        else
                        {
                            search_Blood(group);
                            cout<<endl<<endl;
                        }
                    }
                    system("PAUSE");
                    system("CLS");
                }
                else if(m=='0')
                {
                    break;
                }
                else
                {
                    system("CLS");
                }

            }
            system("CLS");
        }
        else if(c=='2')
        {
            system("CLS");
            while(1)
            {
                pharmacy_start_page();
                cout<<endl<<"Enter Choice : ";
                cin>>c;
                getchar();
                if(c=='1')
                {
                    system("CLS");
                    if(head==NULL)
                    {
                        cout<<endl<<"List Is Empty"<<endl<<endl;
                    }
                    else
                    {
                        cout<<endl<<"Eneter Name : ";
                        getline(cin,name);
                        name=string_converter(name);
                        search_medicine(name);

                    }
                    system("PAUSE");
                    system("CLS");
                }
                else if(c=='2')
                {
                    system("CLS");
                    display();
                    system("PAUSE");
                    system("CLS");
                }
                else if(c=='3')
                {
                    system("CLS");
                    while(1)
                    {
                        cout<<endl<<"  1. Add new medicine"<<endl<<endl<<"  2. Add old medicine"<<endl<<endl;
                        cout<<"Enter choice : ";
                        cin>>c;
                        if(c=='1')
                        {
                            system("CLS");
                            getchar();
                            cout<<endl<<"Enter Name : ";
                            getline(cin,name);
                            name=string_converter(name);
                            if(search_medicine_1(name))
                            {
                                system("CLS");
                                cout<<endl<<"Already Added"<<endl<<endl;
                                break;
                            }
                            else
                            {
                                cout<<endl<<"Enter Price Per Piece: ";
                                cin>>price;
                                cout<<endl<<"Enter Pieces : ";
                                cin>>piece;
                                insert(name,price,piece);

                                cout<<endl<<"Added Successfully"<<endl<<endl;
                                break;
                            }
                        }
                        else if(c=='2')
                        {
                            system("CLS");
                            if(head==NULL)
                            {
                                cout<<endl<<"List Is Empty"<<endl<<endl;
                                break;
                            }
                            else
                            {
                                getchar();
                                cout<<endl<<"Enter Name : ";
                                getline(cin,name);
                                name=string_converter(name);
                                if(search_medicine_1(name))
                                {
                                    cout<<"Enter Pieces : ";
                                    cin>>piece;
                                    update_piece1(name,piece);
                                    cout<<endl<<"Added Successfully"<<endl<<endl;
                                    break;
                                }
                                else
                                {
                                    system("CLS");
                                    cout<<endl<<"Not stored"<<endl<<endl;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            system("CLS");
                        }
                    }

                    system("PAUSE");
                    system("CLS");
                }
                else if(c=='4')
                {
                    system("CLS");
                    if(head==NULL)
                    {
                        cout<<endl<<"List Is Empty"<<endl<<endl;
                    }
                    else
                    {
                        cout<<endl<<"Enter Name :";
                        getline(cin,name);
                        name=string_converter(name);
                        if(search_medicine_1(name))
                        {
                            delete_medicine(name);
                            cout<<endl<<"Deleted Successfully"<<endl<<endl;
                        }
                        else
                        {
                            cout<<endl<<"Not stored"<<endl<<endl;
                        }
                    }

                    system("PAUSE");
                    system("CLS");
                }
                else if(c=='5')
                {
                    system("CLS");
                    if(head==NULL)
                    {
                        cout<<endl<<"List Is Empty"<<endl<<endl;
                    }
                    else
                    {
                        cout<<endl<<"Enter Name :";
                        getline(cin,name);
                        name=string_converter(name);
                        if(search_medicine_1(name))
                        {
                            cout<<endl<<"Enter new price per piece: ";
                            cin>>price;
                            update_price(name,price);
                            cout<<endl<<"Updated successfully"<<endl<<endl;
                        }
                        else
                        {
                            cout<<endl<<"Not stored"<<endl;
                        }
                    }

                    system("PAUSE");
                    system("CLS");
                }
                else if(c=='6')
                {
                    system("CLS");
                    t=0;
                     while(1)
                     {
                         if(head==NULL)
                         {
                             cout<<endl<<"There is no medicine to sell"<<endl<<endl;
                             break;
                         }
                         cout<<endl<<"Enter Name : ";
                         getline(cin,name);
                         name=string_converter(name);
                         if(search_medicine_1(name))
                         {
                             cout<<endl<<"Enter quantity : ";
                             cin>>piece;
                             getchar();
                             if(check_quantity(name,piece))
                             {
                                 t++;
                                 node_sell z;
                                 z.sell_price=check_quantity(name,piece);
                                 z.sell_quantity=piece;
                                 z.name=name;
                                 v.push_back(z);
                                 update_piece(name,piece);
                                 l3:system("CLS");
                                 cout<<endl<<"Sell More ? (y/n) :";
                                 cin>>c;
                                 getchar();
                                 if(c=='y' || c=='Y')
                                 {
                                     continue;
                                 }
                                 else if(c=='n' || c=='N')
                                 {
                                     break;
                                 }
                                 else
                                 {
                                     goto l3;
                                 }
                             }
                             else
                             {
                                 l2:system("CLS");
                                 cout<<endl<<"Insufficient storage"<<endl<<endl;
                                 cout<<"Sell More ? (y/n) :";
                                 cin>>c;
                                 getchar();

                                 if(c=='y' || c=='Y')
                                 {
                                     continue;
                                 }
                                 else if(c=='n' || c=='N')
                                 {
                                     cout<<endl;
                                     break;
                                 }
                                 else
                                 {
                                     goto l2;
                                 }
                            }
                         }
                         else
                         {
                             l1: system("CLS");
                             cout<<endl<<"Not stored"<<endl;
                             cout<<endl<<"Sell More ? (y/n) : ";
                                 cin>>c;
                                 getchar();
                                 if(c=='y' || c=='Y')
                                 {
                                     continue;
                                 }
                                 else if(c=='n' || c=='N')
                                 {
                                     cout<<endl;
                                     break;
                                 }
                                 else
                                 {

                                     goto l1;
                                 }
                         }
                     }
                     if(t!=0)
                     {
                         while(1)
                         {
                             system("CLS");
                             cout<<endl<<"Enter P for printing memo : ";
                             cin>>c;
                             int total=0;
                             if(c=='p' || c=='P')
                             {

                                     cout<<endl<<endl;
                                     cout<<right<<setw(45)<<"East  West  Pharmacy"<<endl;
                                     cout<<right<<setw(43)<<"Aftab Nagar,Dhaka"<<endl;
                                     cout<<"\t......................................................"<<endl;
                                     cout<<right<<setw(15)<<"Name"<<setw(23)<<"Quantity"<<setw(20)<<"Price"<<endl;
                                     cout<<"\t......................................................"<<endl;

                                     for(int i=0;i<v.size();i++)
                                     {
                                         cout<<"         "<<i+1<<"."<<left<<setw(15)<<v[i].name<<right<<setw(9)<<v[i].sell_quantity<<right<<setw(21)<<v[i].sell_price*v[i].sell_quantity<<"/="<<endl;
                                         total=total+v[i].sell_price*v[i].sell_quantity;
                                     }
                                     cout<<"\t......................................................"<<endl;
                                     cout<<"         "<<"total price: "<<right<<setw(34)<<total<<"/=";

                                 cout<<endl<<endl;
                                 break;
                             }
                             else
                             {
                                 continue;
                             }
                             v.clear();
                        }

                     }
                    system("PAUSE");
                    system("CLS");
                }
                else if(c=='0')
                {
                    break;
                }
                else
                {
                    cout<<"Wrong Input"<<endl;
                    system("CLS");
                }
            }
            system("CLS");

        }
        else if(c=='3')
        {
            system("CLS");
            cout<<endl<<"|| Thank You ||"<<endl;
            cout<<endl<<"Program is shutting down......"<<endl;
            exit(1);
        }
        else
        {
            system("CLS");
            continue;
        }
    }
    return 0;
}
