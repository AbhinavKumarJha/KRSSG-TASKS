#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
using namespace cv;
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
Mat img=imread("krssgtask2.png",0);
    vector<int> v_nn; 
	
	vector< pair <int,int> > vect_n(img.rows*img.cols);
	vector< pair <int,int> > vect_i(img.rows*img.cols);	  
	vector<int> cost(img.rows*img.cols*img.rows);


	void fix_cost(int x,int i,vector< pair <int,int> > vect_i,vector<int> cost,vector< pair <int,int> > vect_n)
{
	int y;
	for(int m=0;m<i;++m)
	{
		if(vect_i[m].first==x)
		{
    		cost[m]=cost[x]+sqrt((vect_n[m].first-vect_n[x].first)*(vect_n[m].first-vect_n[x].first)+(vect_n[m].second-vect_n[x].second)*(vect_n[m].second-vect_n[x].second));
    		y=vect_i[m].second;
    		break;
		}
		if(m==(i-1))
			return;
	}
	cout<<y<<endl;
	fix_cost(y,i,vect_i, cost,vect_n);
}
float dist(int a,int b,int c,int d)
{
	return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
int main(int argc, char *argv[])
{
	srand(time(NULL));
	int x,near_n,a,b,s=10,z,neigh=20;
	int y;
	float cmin;
	
	vect_n[0].first=0;
	vect_n[0].second=0;
	vect_i[0].first=0;
    vect_i[0].second=0;
	for(int i=1;i<1000000;++i)
	{
		v_nn.clear();
		cout<<i<<endl;
		float min=dist(0,0,img.rows,img.cols);
		int f=0;
		x= (rand() % (img.cols));
		y= (rand() % (img.rows));
		for(int j=0;j<i;++j)
		{
			
			if(dist(vect_n[j].first,vect_n[j].second,x,y)<min)
			{
				min=dist(vect_n[j].first,vect_n[j].second,x,y);	
				a=vect_n[j].first;
				b=vect_n[j].second;
				near_n=j;
			}
		}
		if(dist(x,y,a,b)<s)
		{
			vect_n[i].first=x;
			vect_n[i].second=y;
		}
		else
		{
		vect_n[i].first=((s*x)+(dist(x,y,a,b)-s)*a)/dist(x,y,a,b);
		vect_n[i].second=((s*y)+(dist(x,y,a,b)-s)*b)/dist(x,y,a,b);
		x=vect_n[i].first;
		y=vect_n[i].second;
		}
		//cout<<vect_n[i].first<<endl;
		/*for(int j=x;(abs(x-j)+abs(a-j))==abs(a-x);)
		{
			if(img.at<uchar>(j,(int)(y-((y-b)/(x-a))*(x-j)))>127)
					{
						f=1;
						break;
					}
					if(x>a)
						j--;
					else
						j++;
		}*/
		cout<<"fgnhrn"<<endl;
		for(int k=0;k<i;++k)
		{
			if(dist(vect_n[k].first,vect_n[k].second,vect_n[i].first,vect_n[i].second)<20)
			v_nn.push_back(k);			   	 
		}	
		cmin=cost[near_n]+dist(a,b,vect_n[i].first,vect_n[i].second);
		for (int k = 0; k <v_nn.size() ; ++k)
				{
					if((cost[v_nn[k]]+dist(vect_n[v_nn[k]].first,vect_n[v_nn[k]].second,vect_n[i].first,vect_n[i].second))<=cmin)
					{
						cmin=(cost[v_nn[k]]+dist(vect_i[v_nn[k]].first,vect_i[v_nn[k]].first,vect_n[i].first,vect_n[i].second));
						cost[i]=cmin;
						vect_i[i].first=v_nn[k];
				        vect_i[i].second=i;	
				        z=k;
				    }
				}
		
		if(img.at<uchar>(vect_n[i].second,vect_n[i].first)>230)
			f=1;
		cout<<"gnfndhkd"<<endl;
		if(f==0)
		{
			
			
			line(img,Point(vect_n[v_nn[z]].first,vect_n[v_nn[z]].second),Point(vect_n[i].first,vect_n[i].second),Scalar(127),1);
			imshow("image",img);
			waitKey(1);
		}
		else
		{
			vect_n[i].first=0;
			vect_n[i].second=0;
			vect_i[i].first=0;
			vect_i[i].second=0;
			continue;
		}
		
		
		
		if(dist(vect_n[i].first,vect_n[i].second,img.cols-1,img.rows-1)<50)
		{

			int j=i;
			while(j>0)
			{
						//cout<<vect_i[i].first<<endl;
						line(img,Point(vect_n[vect_i[j].first].first,vect_n[vect_i[j].first].second),Point(vect_n[j].first,vect_n[j].second),Scalar(255),1);
						imshow("image",img);
						waitKey(1);
						j=vect_i[j].first;	
			}

			line(img,Point(img.cols-1,img.rows-1),Point(vect_n[i].first,vect_n[i].second),Scalar(255),1);
			imshow("image",img);
			waitKey(1);
			break;
		}


	}






	namedWindow("image",0);
	imshow("image",img);
	waitKey(0);
}