#include<bits/stdc++.h>
#include<vector>
using namespace std;
class Finite_State_machine
{
public:


	int max,min=0,lift_i;
	int d,fmax=min,fmin=max;
	vector<int>lift_inside;
	vector<int>lift_up;
	vector<int>lift_down;
	vector<int>lift_in;

	void read_lift()
	{ int k;
		cout<<"Enter the number of floors in Building : ";
	cin>>max;
	cout<<"Enter the numbers pressed inside lift :(enter 0 to terminate) ";
	for(int i=0;;++i)
	{

		cin>>k;
		if(k==0)
		break;

		lift_inside.push_back(k);

	}
	cout<<"Enter the Present floor : ";
	cin>>lift_i;
	cout<<"Enter the floors in which up is pressed(enter 0 to terminate) : ";
	for(int i=0;;++i)
	{

		cin>>k;
		if(k==0)
		break;

		lift_up.push_back(k);

	}
	cout<<"Enter the floors in which down is pressed(enter 0 to terminate) : ";
	for(int i=0;;++i)
	{

		cin>>k;
		if(k==0)
		break;

		lift_down.push_back(k);

	}
	}
 int  run_lift()
{
	

	for (int i = 0; i < lift_up.size(); ++i)
	{
		d=abs(lift_up[i]-lift_i);
		if(max<d)
			max=d;
	}
	for (int i = 0; i < lift_down.size(); ++i)
	{
		d=abs(lift_up[i]-lift_i);
		if(max<d)
			max=d;
	}
	for (int i = 0; i < lift_inside.size(); ++i)
	{
		d=abs(lift_down[i]-lift_i);
		if(max<d)
			max=d;
	}
	for (int i = 0; i < lift_up.size(); ++i)
	{
		d=abs(lift_up[i]-lift_i);
		if(min>d)
			min=d;
	}
	for (int i = 0; i < lift_down.size(); ++i)
	{
		d=abs(lift_up[i]-lift_i);
		if(min>d)
			min=d;
	}
	for (int i = 0; i < lift_inside.size(); ++i)
	{
		d=abs(lift_down[i]-lift_i);
		if(min>d)
			min=d;
	}
	for (int i = 0; i < lift_up.size(); ++i)
	{
		if((i>min)&&(i<lift_i)&&(i>fmax))
			fmax=i;
	}
	for (int i = 0; i < lift_down.size(); ++i)
	{
		if((i>max)&&(i<lift_i)&&(i>fmin))
			fmin=i;
	}
	cout<<fmin<<endl;
	if((2*max+min+fmax)>(2*min+max+fmin))
	{
		return 0;
	}
	else
	{
		return 1;
	}



	

}

void move_up()
{
vector<int> AB;	

AB.reserve( lift_up.size() + lift_inside.size() ); // preallocate memory
AB.insert( AB.end(), lift_up.begin(), lift_up.end() );
AB.insert( AB.end(), lift_inside.begin(), lift_inside.end() );
sort(AB.begin(),AB.end());
for(int i=0;i<AB.size();++i)
{
	if((AB[i]!=AB[i-1])&&(AB[i]>lift_i))
	{
		cout<<AB[i]<<endl;

	}
	for (int j = 0; j < lift_up.size(); ++j)
	{
		if(lift_up[j]==AB[i])
		{
			lift_up.erase(lift_up.begin()+j);
		}
	}

	for (int j = 0; j < lift_inside.size(); ++j)
	{
		if(lift_inside[j]==AB[i])
		{
			lift_inside.erase(lift_up.begin()+j);
		}
	}


}
int i=(AB.size()-1);
lift_i=AB[i];

}
void move_down()
{
	vector<int> AB;	

AB.reserve( lift_inside.size() + lift_down.size() ); // preallocate memory
AB.insert( AB.end(), lift_inside.begin(), lift_inside.end() );
AB.insert( AB.end(), lift_down.begin(), lift_down.end() );
sort(AB.begin(),AB.end());
for(int i=0;i<AB.size();++i)
{
	if((AB[i]!=AB[i-1])&&(AB[i]>lift_i))
	{
		cout<<AB[i]<<endl;

	}
	for (int j = 0; j < lift_down.size(); ++j)
	{
		if(lift_up[j]==AB[i])
		{
			lift_up.erase(lift_up.begin()+j);
		}
	}

	for (int j = 0; j < lift_inside.size(); ++j)
	{
		if(lift_inside[j]==AB[i])
		{
			lift_inside.erase(lift_up.begin()+j);
		}
	}
}
int i=(AB.size()-1);
lift_i=AB[i];
}


//vector<int> vec path1()
};


int main()
{

	Finite_State_machine lift;
	lift.read_lift();
	if(lift.run_lift()==1)
	{
		lift.move_up();
		lift.move_down();
		lift.move_up();
	}
	else
	{
		lift.move_up();
		lift.move_down();
		lift.move_up();
	}
	
	//run(vector<int> lift_up,vector<int> lift_inside,vector<int> lift_down,max,min);
	//cout<<max<<" "<<min<<endl;

}