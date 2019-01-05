#include <cstring>
#include <iostream>
using namespace std;
//required libraries imported
class Address//address class
{
	public:
	string houseNumber;
	string city;
	long pinCode;//data members
	public:
	Address()//constructor
	{
		houseNumber="";
		city="";
		pinCode=0l;
	}
	void setup()//input method
	{
		cout<<"Enter the house number\n";
		cin>>houseNumber;
		cout<<"Enter the city name\n";
		cin>>city;
		cout<<"Enter the pin code\n";
		cin>>pinCode;
	}
	void display()//display method
	{
		cout<<"House Address: "<<houseNumber<<" "<<city<<", Pin Code: "<<pinCode<<endl;
	}
};//end of class Address
class Room//class Room
{
	public:
	float length;
	float breadth;
	float height;
	string purpose;//data memebers
	public:
	Room()//constructor
	{
		length=0.0f;
		breadth=0.0f;
		height=0.0f;
		purpose="";
	}
	void setup()//input method
	{
		cout<<"Enter the length of the room\n";
		cin>>length;
		cout<<"Enter the breadth of the room\n";
		cin>>breadth;
		cout<<"Enter the height of the room\n";
		cin>>height;
		cout<<"Enter the purpose of the room\n";
		cin>>purpose;
	}
	void display()//display method
	{
		cout<<purpose<<endl;
		cout<<"The dimension of the "<<purpose<<" is "<<length<<" by "<<breadth<<" by "<<height<<endl;
	}
	float area()//method to calculate the area of each room
	{
		return (float)(length*breadth);
	}
};//end of class Room
class House//class House
{
	public:
	string houseName;
	Address houseAddress;
	Room houseRooms[10];
	int noOfRooms;//data members
	public:
	House()//constructor
	{
		houseName="";	
		noOfRooms=0;	
	}
	void setup()//input method
	{
		cout<<"Enter the name of the house.\n";
		cin>>houseName;
		houseAddress.setup();//method of class Address called for input of address
		cout<<"Enter the number of rooms in the house\n";
		cin>>noOfRooms;//number of room inputted
		for(int i=0;i<noOfRooms;i++)
		{
			cout<<"Enter the details of the "<<(i+1)<<"th room\n";
			houseRooms[i].setup();//method of class room called for input of details of each room
		}
	}
	void display()//method display
	{
		cout<<"House name: "<<houseName<<endl;
		houseAddress.display();//address displ;ayed by a call to the function of class Address
		cout<<"Number of rooms:"<<noOfRooms<<endl;
		cout<<"Room details:\n";
		float totalArea=0.0f;
		int noOfBedrooms=0;
		int noOfKitchens=0;
		int noOfBathrooms=0;
		int noOfDiningrooms=0;
		int noOfDrawingrooms=0;
		for(int i=0;i<noOfRooms;i++)
		{
			houseRooms[i].display();//details of each room displayed by a call to the respective functions of the class
			totalArea+=houseRooms[i].area();//total area computed
			if(houseRooms[i].purpose.compare("Bedroom")==0)
			noOfBedrooms++;
			else if(houseRooms[i].purpose.compare("Kitchen")==0)
			noOfKitchens++;
			else if(houseRooms[i].purpose.compare("Bathroom")==0)
			noOfBathrooms++;
			else if(houseRooms[i].purpose.compare("Diningroom")==0)
			noOfDiningrooms++;
			else if(houseRooms[i].purpose.compare("Drawingroom")==0)
			noOfDrawingrooms++;
		}
		cout<<"Total area of the house is "<<totalArea<<endl;//total area displayed
		cout<<"It has "<<noOfBedrooms<<" bedrooms, "<<noOfKitchens<<" kitchens, "<<noOfBathrooms<<" bathrooms, "<<noOfDiningrooms<<" dining rooms and "<<noOfDrawingrooms<<" dining rooms\n";//individual types of rooms displayed
	}
	House copyHouse(string n,House home)//method to copy a house to another house
	{
		home.houseName=n;//new name assigned
		home.houseAddress=this->houseAddress;//address copied
		home.noOfRooms=this->noOfRooms;//number of rooms copied
		for(int i=0;i<noOfRooms;i++)
		home.houseRooms[i]=this->houseRooms[i];//details of each room copied
		return home;//new house created is returned
	}
};//end of class House
int main()//main method to test the class House
{
	House house1;
	House house2;
	House house3;//three house objects
	cout<<"Enter the details of the first house\n";
	house1.setup();
	cout<<"Enter the details of the second house\n";
	house2.setup();
	cout<<"Enter the details of the third house\n";
	house3.setup();//their details inputted
	house1.display();
	house2.display();
	house3.display();//details displayed
	string name="";
	cout<<"Enter the name of the copied house\n";
	cin>>name;//new name for the copied house inputted
	house2=house1.copyHouse(name,house2);//house copied
	house1.display();//original house displayed
	house2.display();//copied house displayed
	return 0;
}
