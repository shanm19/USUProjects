#include<iostream>
#include<fstream>
using namespace std;

template<typename Etype>
class Pair{
public:
	Etype ParentID;
	int Rank;

	Pair(Etype p=-1, int s=0){
		ParentID = p;
		Rank = s;
	}
	Pair(int newParentID)
	{
		ParentID=newParentID;
		Rank=0;
	}
	
	int ID(){return ParentID;}
	int R(){return Rank;}

	void setPair(int p){ParentID = p;}

	void increment(){Rank++;}
	//void decrement(){Rank--;}
	/*
	void print()
	{
		cout<<"Parent: "<<ParentID<<endl;
		cout<<"Rank: "<<Rank<<endl;
	}*/
	friend ostream& operator <<(ostream &out, Pair<Etype>& rhs)
	{
		out<<"Parent: "<<rhs.ParentID<<endl;
		out<<"Rank: "<<rhs.Rank<<endl;
		//rhs.print();
		return out;
	}
	bool operator <(Pair<Etype>& rhs)
	{
		if(Rank<rhs.Rank) return true;
		return false;
	}
	bool operator ==(Pair<Etype>& rhs)
	{
		if(Rank==rhs.Rank) return true;
		return false;
	}
	void operator =(int& rhs)
	{
		ParentID = rhs;
		//Size = rhs.Size;
	}
	
};