#include <stdio.h>
#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

double t[20]={0,0,1.84,1.32,1.20,1.14,1.11,1.09,1.08};//t分布因子page-8 
int dataQuantity=0;
double datas[20]={0};
double dataAver=0;
double s=0;//标准偏差 
double deltaXa=0;//A类不确定度 
double deltaXb=0;//B类不确定度 
double deltaX=0;//不确定度 

/*
声明：本程序为交差而写，由计算产生的误差在所难免，概不负责 
*/

void getAver();
void getS();
void getDeltaXa();

int main()
{
	
	char choice=0;
	double division=0.01;
	
	while(1)
	{
		cout<<"----------------开始新一轮不确定度计算...------------------"<<endl;
		cout<<"请输入数据量:"<<endl;
		cin>>dataQuantity;
		
		if(dataQuantity<2)//防捣蛋 
		{
			cout<<"?";
			continue;
		}
		else if(dataQuantity>8)
		{
			cout<<"t分布因子未填充，请亲手查阅并输入：";
			cin>>t[dataQuantity] ;
		}
		
		cout<<"请输入数据(空格隔开)(记得换算为国际单位):"<<endl;
		for(int i=0;i<dataQuantity;)
		{
			cin>>datas[i++];
		}
		cout<<endl<<endl;
		cout<<"----------------开始计算...------------------"<<endl<<endl;
		cout<<"t分布因子获得："<<t[dataQuantity]<<endl<<endl; 
		getAver();
		cout<<"平均值aver获得："<<dataAver<<endl<<endl;
		getS();
		cout<<"标准偏差s获得："<<s<<endl<<endl;
		
		/*cout<<"按1修改标准偏差;按其他键继续"<<s<<endl;
		getchar();
		choice=getch('1');
		if(choice==1)
		{
			cou<<"s=？";这块留作私人定制内容了。。 
			cin>>s;
		}
		choice=0;  */ 
		
		
		getDeltaXa();
		cout<<"A类不确定度delta_X_a获得："<<deltaXa<<endl<<endl;
		cout<<"A类不确定度计算完成..."<<endl<<endl;
		cout<<"按'1'计算B类不确定度 ; 按'2'输入B类不确定度 ; 按其他键开始下一轮计算  "; 
		cout<<"(提示：机算B类不确定度默认选定置信系数为根号三)"<<endl<<endl; 
		getchar();
		 choice=getch();
		 if(choice=='1')
		 {
		 	choice=0;
		 	cout<<"输入仪器最小分度确定B类不确定度:"<<endl;
		 	cin>>division;
		 	deltaXb=division/sqrt(3);
			  cout<<"B类不确定度delta_X获得："<<deltaXb<<endl<<endl; 
			deltaX=sqrt(deltaXa*deltaXa+deltaXb*deltaXb);
			cout<<"不确定度获得："<<deltaX<<endl<<endl;
		 }
		 else if(choice=='2')
		 {
		 	choice=0;
		 	cout<<"输入B类不确定度:"<<endl;
		 	cin>>deltaXb;
		 	cout<<"B类不确定度delta_X_b获得："<<deltaXb<<endl<<endl; 
		 	deltaX=sqrt(deltaXa*deltaXa+deltaXb*deltaXb);
			cout<<"最终不确定度delta_X获得："<<deltaX<<endl<<endl;
		 }
		cout<<"----------------不确定度计算完成...------------------"<<endl<<endl<<endl;
	}
	
} 
void getAver()
{
		dataAver=0;
	for(int i=0;i<dataQuantity;i++)
		{
			dataAver+=datas[i];
		}
	dataAver/=dataQuantity;
}
void getS()
{
	s=0;
	double temp=0;
	for(int i=0;i<dataQuantity;i++)
		{
			temp=datas[i]-dataAver;
			temp=temp*temp;
			s+=temp;
		}
	
	s/=(dataQuantity-1);
		
	s=sqrt(s);
		
	
} 
void getDeltaXa()
{
	deltaXa=0;
	deltaXa=s*t[dataQuantity]/sqrt(dataQuantity);
}
