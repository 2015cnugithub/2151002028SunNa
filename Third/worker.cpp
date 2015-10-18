#include <iostream>
#include <string>
using namespace std;

class Worker{
protected:
	string name;
	int age;
	string sex;
	double pay_per_hour;
public:
	void workernew(string namenew, int agenew, string sexnew, double pay)
    {
		name = namenew;
		age = agenew;
		sex = sexnew;
		pay_per_hour = pay;
	}
	 virtual void Comput_pay(double hours){
	}
	friend ostream& operator<<(ostream& out, Worker& worker){
		return out << "name:" << worker.name <<endl<< " age:" << worker.age <<endl<<
			" sex:" << worker.sex <<endl<<  " pay per hour:" << worker.pay_per_hour << endl;
	}
	void Name(){
		cout << name << endl;
	}
};

class HourlyWorker : public Worker{
public:
	void Comput_pay(double hours){
		double pay;
		if (hours <= 40) pay = pay_per_hour*hours;
		else pay = pay_per_hour * 40 + 1.5*pay_per_hour*(hours - 40);
		cout << "The salary is " << pay << endl;
	}
};

class SalariedWorker : public Worker{
public:
	void Comput_pay(double hours){
		double pay;
		if (hours < 35) pay = pay_per_hour*hours + 0.5*pay_per_hour*(35 - hours);
		else pay = pay_per_hour * 40;
		cout << "The salary is " << pay << endl;
	}
};

    int main(){
	Worker* workers[5];
	string name;
	int age;
	string sex;
	double pay;
	for (int i = 0; i < 5; i++){
		cout << "输入姓名，年龄，性别以及小时工资额:";
		cin >> name >> age >> sex >> pay;
		if (pay == 10 || pay == 20 || pay == 40) workers[i] = new HourlyWorker;
		else if(pay==30||pay==50) workers[i] = new SalariedWorker;
		else {
			cout << "Error!";
			return 0;
		}
		workers[i]->workernew(name, age, sex, pay);
	}
	cout << "Name" << endl;
	for (int i = 0; i < 5; i++){
		cout << i + 1 << " ";
		workers[i]->Name();
	}
	cout << "选择一个名字（以其对应序号表示）:";
	int number;
	cin >> number;
	cout << *workers[number-1];
	cout << "每周工作小时数:";
	double h;
	cin >> h;
	workers[number]->Comput_pay(h);
	system("pause");
}

 
