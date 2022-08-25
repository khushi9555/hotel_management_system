#include <bits/stdc++.h>
using namespace std;
int room_count = 0;
bool visited[100 + 1] = {false};
class customer
{
    public:
    string first_name;
    string last_name;
    int M_number;
    string from_date;
    string to_date;
    int booking_id;
};
class Room
{
public:
    char ac;   // AC or non AC
    char size; // 2 bed or single
    int roomnumber;
    int statue = 0; // booked or not
    int rent;
    void searchRoom(int);
    void deleteRoom(int);
    class customer c;
};
class HotelMgnt
{
public:
    int count;
    class Room room[100];
    void addRoom();
    void BookRoom();
    bool checkAvailableRoom(int); // check whether the data of room is available or not
    void CheckCustomerDetail();
    void CheckTotalGuestDetail();
    bool StatusOfRoom(int);
};
bool HotelMgnt ::checkAvailableRoom(int rno)
{

    if (visited[rno + 1] == true)
    {
        return true;
    }
    return false;
}
void HotelMgnt ::CheckCustomerDetail()
{
    int rno;
    cout << "Enter the room number of customer : ";
    cin >> rno;
    if (room[rno - 1].statue == 0)
    {
        cout << "Customer not found !" << endl;
    }
    else
    {   cout<<endl;
        cout << "*********CUSTOMER DETAIL **************" << endl;
        cout << "Customer 's name : " << room[rno - 1].c.first_name <<" "<<room[rno - 1].c.last_name<< endl;
        cout << "customer 's mobile number : " << room[rno - 1].c.M_number << endl;
        cout << "customer's booking id : " << room[rno - 1].c.booking_id << endl;
        cout << "Start time : " << room[rno - 1].c.from_date << endl;
        cout << "End time : " << room[rno - 1].c.to_date << endl;
    }
}
bool HotelMgnt ::StatusOfRoom(int rno)
{
    if (visited[rno + 1] == false)
    {
        cout << "Room data is not Available " << endl;
        return false;
    }
    else
    {
        if (room[rno ].statue == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
void HotelMgnt ::CheckTotalGuestDetail()
{
    if (room_count == 0)
    {
        cout << "No Guest found in the hotel " << endl;
    }
    else
    {   
        
        for (int i = 0; i < room_count; i++)
        {
            if (room[i].statue == 1)
            {
                cout << "ROOM NUMBER : " << room[i].roomnumber << endl;
                cout << "Customer 's name : " << room[i].c.first_name <<" "<<room[i].c.last_name<< endl;
                cout << "customer 's mobile number : " << room[i].c.M_number << endl;
                cout << "customer's booking id : " << room[i].c.booking_id << endl;
                cout << "Start time : " << room[i].c.from_date << endl;
                cout << "End time : " << room[i].c.to_date << endl;
            }
            
            cout << endl;
        }
    }
}
void HotelMgnt ::addRoom()
{
    cout << "Enter how many room you want to add : ";
    cin >> count;
    cout << "enter the detail of each room : " << endl;
    for (int j = 0; j < count; j++)
    {
        cout << "***************************************************" << endl;
        int i = room_count;
        visited[i + 1] = true;
        cout << "Enter the room number : ";
        cin >> room[i].roomnumber;
        cout << "Type AC or Non AC (A/N) : ";
        cin >> room[i].ac;
        cout << "Type size (B/S) : ";
        cin >> room[i].size;
        cout << "Rent : ";
        cin >> room[i].rent;
        room_count++;
    }
}
void HotelMgnt ::BookRoom()
{
    int rno;
    cout << endl
         << "Enter the room number that you want to book : ";
    cin >> rno;
    if (checkAvailableRoom(rno - 1) == false)
    {
        char c;
        cout << "Room data is not available " << endl
             << "you can add room details " << endl;
        cout << "Want to add Room(Y/N) : ";
        cin >> c;
        if (c == 'Y')
        {
            addRoom();
            BookRoom();
        }
    }
    else
    {
        if (StatusOfRoom(rno - 1) == false)
        {
            cout<<"                CUSTOMER INFORMATION                       "<<endl;
            cout<<"FIRST NAME  : ";
            cin>>room[rno - 1].c.first_name;
            cout<<"LAST NAME : ";
            cin>>room[rno - 1].c.last_name;
            cout << " START DATE (DD/MM/YYYY) : ";
            cin>>room[rno - 1].c.from_date;
            cout << "END DATE (DD/MM/YYYY) : ";
            cin>>room[rno -1].c.to_date;
            cout << "MOBILE NUMBER  : ";
            cin >> room[rno -1].c.M_number;
            cout << "BOOKING ID  : ";
            cin >> room[rno -1].c.booking_id;
            room[rno -1].statue = 1;
        }
        else
        {
            cout << "Room is already booked !";
        }
    }
}

int main()
{
    cout << "#################### WELCOME TO SOFTWARE #########################" << endl;
    cout << "                      HOTEL MANAGEMENT                             " << endl;
    class HotelMgnt hm;
    // roomnumber = room[roomnumber - 1]
    // visited [rno + 1]
    int opt;
    do
    {
        cout << "____________________________________________________________________________________" << endl;
        cout << "1.ADD ROOM " << endl;
        cout << "2.BOOK ROOM " << endl;
        cout << "3.CHECK  AVAILABLE ROOM " << endl;
        cout << "4.CHECK CUSTOMER DETAIL " << endl;
        cout << "5.CHECK TOTAL GUEST DETAIL " << endl;
        cout << "6.CHECK STATUS OF ROOM " << endl;
        cout << "7.EXIT" << endl;
        cout<<"_________________________________________________________________________________________"<<endl;
        cout << "Enter your choice : ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            hm.addRoom();
            break;
        case 2:
            hm.BookRoom();
            break;
        case 6:
            int rno;
            cout << "enter the room number to check its status  : ";
            cin >> rno;
            if (hm.StatusOfRoom(rno -1) == true)
            {
                cout << "Room is booked " << endl;
            }
            else
            {
                cout << "Room is not booked " << endl;
            }
            break;
        case 4:
            hm.CheckCustomerDetail();
            break;
        case 5:
            hm.CheckTotalGuestDetail();
            break;
        case 3:
            int rno2;
            cout << "enter the room number to check whether it is available or not :  ";
            cin >> rno2;
            if (hm.checkAvailableRoom(rno2 - 1) == true)
            {
                cout << "Room data is  available " << endl;
                ;
            }
            else
            {
                cout << "Room data is not available " << endl;
            }
            break;
        case 7:
            cout << "###################### THANKYOU FOR USING THE SOFTWARE ################################## ";
            exit(0);
            break;
        default:
            cout<<"Enter the correct option !"<<endl;
            break;
        }


    } while (true);
    return 0;
}