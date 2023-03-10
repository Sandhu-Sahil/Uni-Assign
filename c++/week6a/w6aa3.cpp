#include<iostream.h>

class House;

class Room
{
  public:

    Room()
    {
    };

    static void createRoom_v(Room* (&room), House* hse, char* name)
    {
      room = new Room(hse, name); 
    }
    
    Room(House* hse, char* myName)
    {
      cout<<"Room::ctor\n";
      myHse_p = hse;
      
      if(NULL != myHse_p)
      {
        name_p = new char(sizeof(strlen(myName)));
        name_p = myName;
      }
      else
      {
        cout<<"Oops House itself is not Created Yet ...\n";
      }
    };

    ~Room()
    {
      cout<<"Room:dtor\n";
      myHse_p = NULL;
      delete (name_p);
    };

    void disp()
    {
      cout<< name_p;
      cout<<"\n";
    }
    
    static void initList_v(Room *(& roomsList_p)[3])
    {
      roomsList_p[3] = new Room[3];
    }

  private:
    House * myHse_p;
    char * name_p;
};

class House
{
  public:

    House(char *myName)
    {
      cout<<"House::ctor\n";
      name_p = new char(sizeof(strlen(myName)));;
      name_p = myName;

      Room::initList_v(roomsList_p);

      Room* myRoom;
      Room::createRoom_v(myRoom, this, "Kitchen");
      roomsList_p[0] = myRoom;
      
      Room::createRoom_v(myRoom, this, "BedRoom");
      roomsList_p[1] = myRoom;

      Room::createRoom_v(myRoom, this, "Drwaing Room");
      roomsList_p[2] = myRoom;
    }
    
    ~House()
    {
      cout<<"House:dtor\n";
      unsigned int i;
      
      cout<<"Delete all the Rooms ...\n";
      for(i=0; i<3; ++i)
      {
        if(roomsList_p[i] != NULL)
        {
          delete (roomsList_p[i]);
        }
          
      }
      delete [] roomsList_p;
      delete (name_p);
    }

    void disp()
    {
      cout<<"\n\nName of the House :"<<name_p;
      
      if(roomsList_p != NULL)
      {
        unsigned int i;
        cout<<"\n\nRooms details...\n";
        for(i=0; i<3; ++i)
        {
          if(NULL != roomsList_p[i])
          {
            roomsList_p[i]->disp();
          }
        }
        cout<<"\n\n";
      }
    }

  private:
    char* name_p;
    Room* roomsList_p[3];
};

int main()
{
  
  cout<<"\nExample of Composition Relationship\n";
  cout<<"-----------------------------------------\n\n";
  House hse("Vishranti Nilaya");

  cout<<"\n\nHouse details...\n";
  hse.disp();

  cout<<"Here House itself creates the Rooms and Deletes as well, before it gets deletd...\n";

  return(0);
}