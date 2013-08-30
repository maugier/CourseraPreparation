class Person {
};


class Room {
	public:
		void add_person(Person person)
		{
			// do stuff
		}

	private:
		Person* people_in_room;
};


template <class T, int N>
class Bag<T, N> {
};


class Hey{
	
};

int main()
{	
	int i = 0; 
	float j = 1; 
	double k = 2; 
	
	int* ptrInt (int*) malloc (sizeof(int) * 10); 
	
	
	Hey* h = new Hey(); 
	
	Person* p = new Person();
	Bag<Person, 42> bagofpersons;

	return 0;
}
