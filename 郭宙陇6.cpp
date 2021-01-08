#include<iostream>
#include <math.h>
using namespace std;


class vehicle
{
protected:
	int wheels;
	int weight;
public:
	vehicle(int wh, int we)
	{
		wheels = wh;
		weight = we;
	}
	void disp() //io口
	{
		cout << "汽车" << endl << "wheels=" << wheels << endl << "weight=" << weight << endl;
	}
};

class car :private vehicle
{
	int passenger_load;
public:
	car(int wh, int we, int pa) :vehicle(wh, we)
	{
		passenger_load = pa;
	}
	void disp()
	{
		cout << "小车" << endl << "wheels=" << wheels << endl << "weight=" << weight << endl;
		cout << "passenger_load=" << passenger_load << endl;
	}
};

class truck :private vehicle
{
	int passenger_load;
	int payload;
public:
	truck(int wh, int we, int pa, int pay) :vehicle(wh, we)
	{
		passenger_load = pa;
		payload = pay;
	}
	void disp()
	{
		cout << "卡车" << endl;
		cout << "wheels=" << wheels << endl << "weight=" << weight << endl;
		cout << "passenger_load=" << passenger_load << endl << "payload=" << payload << endl;
	}


};




void main()
{
	int a, b;
	cin >> a >> b;
	vehicle v(a, b);
	v.disp();
	//
	int x, d, e;
	cin >> x >> d >> e;
	car c(x, d, e);
	c.disp();
	//
	cin >> a >> b >> d >> e;
	truck t(a, b, d, e);
	t.disp();
}
