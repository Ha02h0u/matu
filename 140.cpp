#include <iostream>
using namespace std;
class Clock{
public:
      Clock(int h,int m, int s);
	  void SetAlarm(int h,int m,int s);
	  void run();
	  void ShowTime(){
		  cout<<"Now:"<<hour<<":"<<minute<<":"<<second<<endl;
	  }
private:
	int hour;   //ʱ
	int minute;  //��
	int second;  //��

	int Ahour;   //ʱ�����ӣ�
	int Aminute;  //�֣����ӣ�
	int Asecond;   //�루���ӣ�
};

void ck(int &x,const int mx){
        if(x>=mx)x=0;
        if(x<=0)x=0;
};
Clock::Clock(int h,int m, int s)
{
    ck(h,24),ck(m,60),ck(s,60);
    hour=h;
    minute=m;
    second=s;
    Asecond=-1;
}
void Clock::SetAlarm(int h,int m, int s){
    if(h>=24)h=0;
    if(m>=60)m=0;
    if(s>=60)s=0;
    Ahour=h,Aminute=m,Asecond=s;
}

void Clock::run(){
    second++;
    if(second==60){
        second=0;
        minute++;
        if(minute==60){
            minute=0;
            hour++;
            if(hour==24)hour=0;
        }
    }
    if(second==Asecond&&minute==Aminute&&hour==Ahour){
        cout<<"Plink!plink!plink!.."<<endl;
    }
}
int main(){
    Clock c(25,61,-1);
    c.ShowTime();
}
