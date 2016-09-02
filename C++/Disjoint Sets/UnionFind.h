#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

template<typename Etype>
class DisjSets{

public:
	explicit DisjSets(int numElements);
	~DisjSets();
	
	int sizeofarray;

	//Etype find(Etype x) const;
	int find(int x);
	void unionSets(int index1, int index2);
	//ostream& printContents();
	int rootFind(int ind);
	Etype* s;
	friend ostream& operator <<(ostream &out, DisjSets<Etype>& rhs){
		for(int i=0; i < rhs.sizeofarray; i++)
		{
			out<<"#: "<<i<<endl;
			out<<rhs.s[i]<<endl;
		}
		return out;
	}

private:
	
};

/*
Construct the disjoint sets object
numElements is the initial number of disjoint sets
*/
template<typename Etype>
DisjSets<Etype>::DisjSets(int numElements){
		sizeofarray=numElements;
		s=new Etype[numElements];
}
/**/
template<typename Etype>
DisjSets<Etype>::~DisjSets()
{
	delete s;
}

template<typename Etype>
int DisjSets<Etype>::rootFind(int ind){
	if(s[ind].ID() == -1 || ind == s[ind].ID()) return ind;
	else return rootFind(s[ind].ID());
	return ind;
}

/*
Union two disjoint sets
For simplicity, we assume root1 and root2 are distinct and represent set names
root1 is the root of set 1, root2 is the root of set 2
*/

template<typename Etype>
void DisjSets<Etype>::unionSets(int index1, int index2){
	
	index1 = rootFind(index1);
	index2 = rootFind(index2);

	if(s[index1] < s[index2]){
		s[index1].ParentID = index2;
		//s[index1].increment();
	}
	else{
		if(s[index1] == s[index2] && s[index1].ParentID != index2)
			s[index1].increment();
		s[index2].ParentID = index1;
	}
}

//template<typename Etype>
//void DisjSets<Etype>::unionSets(int index1, int index2){ 
//
//	index1 = rootFind(index1);
//	index2 = rootFind(index2);
//
//	//if(s[index1].ID() != -1) index1 = s[index1].ID(); //finds root ID, maintains rank
//	//if(s[index2].ID() != -1) index2 = s[index2].ID(); 
//	
//	if(s[index2] < s[index1]){ //index2 is bigger in rank
//		s[index2].setPair(index1);
//		s[index1].increment();
//	}
//	else if(s[index1] < s[index2]){ //index1 is bigger in rank
//		s[index1].setPair(index2);
//		s[index2].increment();
//	}
//	else{
//		int ind1 = s[index1].ID(); //if ranks are equal
//
//		if(ind1 != index2)
//			s[index1].increment();
//
//		//if(s[index1] == s[index2])
//			s[index2].setPair(index1);
//		
//	}
//}

/*
Perform a find with path compression
Error checks omitted again for simplicity
Return the set containing x
*/
template<typename Etype>
int DisjSets<Etype>::find(int x){//fix this
	if(s[x].ParentID == -1) return x; 
	else if(x == s[x].ParentID) return x;
	else
		return s[x].ParentID = find(s[x].ParentID); //path compression //not overloaded correctly
	return x;
}


/*
Perform a find
Error checks omitted again for simplicity
Return the set containing x
*/
/*
template <typename Etype>
Etype DisjSets<Etype>::find(Etype x) const{
	if(s[x] < 0) return x;
	else return find(s[x]);
}
/**/